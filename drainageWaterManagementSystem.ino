/*******************************************************************************

DESIGNER : Mahdi

DATE :1/2/2019

WORK : GAS, WATER LEVEL,TEMPERATURE, WATER FLOW SENSORS

*******************************************************************************/

//water_level variables
// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM-Pulse Width Modulation (analog out)
int red_led=12;
/****************************************************************************/
//Gas variables
int green_led=11;

int buzz=13;

int gas_value;

int gas_avalue;

int sensorThres=200;
/****************************************************************************/
//temperature variables
int val;
int tempPin = A2;
/****************************************************************************/
//water_flow variables
byte statusLed    = 13;

byte sensorInterrupt = 0;  // 0 = digital pin 2
byte sensorPin       = 2;

// The hall-effect flow sensor outputs approximately 4.5 pulses per second per
// litre/minute of flow.
float calibrationFactor = 4.5;

volatile byte pulseCount;  

float flowRate;
unsigned int flowMilliLitres;
unsigned long totalMilliLitres;

unsigned long oldTime;
/****************************************************************************/

void setup()
{
  setupWaterLevel();
  setupGas();
  setupTemprature();
  setupWaterFlow();
}

void loop()
{
  readWaterLevel();
  readGas();
  readTemprature();
  readWaterFlow();
  

  delay(5000);
}
void setupWaterLevel() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}
void readWaterLevel() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);

  // print the results to the Serial Monitor:
  Serial.println("\n\n*****************************************************************************");
  Serial.println("The report values of Water Level are:");
  Serial.print("\t Sensor Value = ");
  Serial.print(sensorValue);
  Serial.print("\t Water Level = ");
  Serial.print(outputValue);
  Serial.println("\n____________________________________________________________________________");

if(outputValue>80)
{
  Serial.print(" The water level is in dangerous condition!");
 
  }
  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
 
}




void setupGas()

{

pinMode(red_led,OUTPUT);

pinMode(buzz,OUTPUT);

pinMode(green_led,OUTPUT);

pinMode(A5,INPUT);

Serial.begin(9600);

}

void readGas()

{

gas_avalue=analogRead(A5);

if (gas_avalue > sensorThres)

{

digitalWrite(red_led, HIGH);

digitalWrite(green_led, LOW);

digitalWrite( buzz, HIGH);
Serial.println("The report values from Gas sensor");
Serial.println("\t DANGER!!!! The concentration of CO2 is more than standard ");

Serial.println("\tConcentration is: ");
Serial.print("\t");
Serial.print( gas_avalue);
Serial.print(" ppm");
}

else

{

digitalWrite(red_led, LOW);

digitalWrite(green_led, HIGH);

digitalWrite( buzz, LOW);
Serial.println("The report values from Gas sensor");
Serial.println("\t NO LEAKAGE, The concentration of CO2 is in normal standard ");

Serial.print("\tConcentration is: ");
Serial.print("\t");
Serial.print(gas_avalue);
Serial.print(" ppm");
}
}

void setupTemprature()
{
Serial.begin(9600);
}

void readTemprature()
{
val = analogRead(tempPin);
float mv = ( val/1024.0)*5000; 
float cel = mv/10;
float farh = (cel*9)/5 + 32;
Serial.println("\n____________________________________________________________________________");
Serial.println("\nThe report values from Temperature sensor");

Serial.print("\tTEMPERATURE = ");
Serial.print(cel);
Serial.print(" °C");
Serial.print("\tTEMPRATURE = ");
Serial.print(farh);
Serial.print(" °F");

}

void setupWaterFlow()
{
    // Initialize a serial connection for reporting values to the host
  Serial.begin(9600);
   
  // Set up the status LED line as an output
  pinMode(statusLed, OUTPUT);
  digitalWrite(statusLed, HIGH);  // We have an active-low LED attached
  
  pinMode(sensorPin, INPUT);
  digitalWrite(sensorPin, HIGH);

  pulseCount        = 0;
  flowRate          = 0.0;
  flowMilliLitres   = 0;
  totalMilliLitres  = 0;
  oldTime           = 0;

  // The Hall-effect sensor is connected to pin 2 which uses interrupt 0.
  // Configured to trigger on a FALLING state change (transition from HIGH
  // state to LOW state)
  attachInterrupt(sensorInterrupt, pulseCounter, FALLING);
  
 }

void readWaterFlow()
{
  if((millis() - oldTime) > 1000)    // Only process counters once per second
  { 
    // Disable the interrupt while calculating flow rate and sending the value to
    // the host
    detachInterrupt(sensorInterrupt);
        
    // Because this loop may not complete in exactly 1 second intervals we calculate
    // the number of milliseconds that have passed since the last execution and use
    // that to scale the output. We also apply the calibrationFactor to scale the output
    // based on the number of pulses per second per units of measure (litres/minute in
    // this case) coming from the sensor.
    flowRate = ((1000.0 / (millis() - oldTime)) * pulseCount) / calibrationFactor;
    
    // Note the time this processing pass was executed. Note that because we've
    // disabled interrupts the millis() function won't actually be incrementing right
    // at this point, but it will still return the value it was set to just before
    // interrupts went away.
    oldTime = millis();
    
    // Divide the flow rate in litres/minute by 60 to determine how many litres have
    // passed through the sensor in this 1 second interval, then multiply by 1000 to
    // convert to millilitres.
    flowMilliLitres = (flowRate / 60) * 1000;
    
    // Add the millilitres passed in this second to the cumulative total
    totalMilliLitres += flowMilliLitres;
      
    unsigned int frac;
    
    // Print the flow rate for this second in litres / minute
    Serial.println("\n____________________________________________________________________________");
    Serial.println("\nThe report values from Water Flow sensor");
    Serial.print("\t");
    Serial.print("Flow rate: ");
    Serial.print(int(flowRate));  // Print the integer part of the variable
    Serial.print("L/min");
    Serial.print("\t");       // Print tab space

    // Print the cumulative total of litres flowed since starting
    Serial.print("Output Liquid Quantity: ");        
    Serial.print(totalMilliLitres);
    Serial.println("mL"); 
    Serial.print("\t");       // Print tab space
    Serial.print(totalMilliLitres/1000);
    Serial.print("L");
    

    // Reset the pulse counter so we can start incrementing again
    pulseCount = 0;
    
    // Enable the interrupt again now that we've finished sending output
    attachInterrupt(sensorInterrupt, pulseCounter, FALLING);
  }
  }

void pulseCounter()
{
  // Increment the pulse counter
  pulseCount++;
}
