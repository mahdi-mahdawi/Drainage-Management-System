# Drainage-Management-System (Using IoT)

<h3>Tagline: Step on blockage the only way to flow</h3>
<h2>1.INTRODUCTION</h2>
<p>&nbsp;&nbsp;&nbsp;&nbsp;The drainage system is an important component of cities. It is considered to be city’s lifeline. Mostly,the management on drainage is manual by workers, therefore it is not efficient to have a clean working system. Moreover, in such big cities, it is difficult for the government's personnel to locate the exact area which a blockage occures until it is notified by the local people. Therefore, it is important to develop a system which can handle drainage overflow which is the result of blockages, without human interfere. This project describes various functions used for maintaining and monitoring of underground drainage system. It provides a system which is able to monitor the water level, water flow, atmospheric temperature, and toxic gasses. If drainage system gets blocked and water overflows it can be identified by the sensors of system. Then sensors send information via the transmitter which is located in that particular area to the corresponding managing station.</p>

<h3>1.1Problem Statement</h3>
	<p>&nbsp;&nbsp;&nbsp;&nbsp; One of the biggest problem we are facing today is drainage system is not advanced enough to prevent any sort of water blockage or at least alert about the same to the water monitor bodies. So whenever there is blockage of water it is difficult to figure out the exact location of the blockage. Also, early alerts of the blockage are not received. Hence detection and repairing of the blockage become time consuming.  It becomes very inconvenient and expensive to  to handle the situation when pipes are blocked completely.  Due to such failure of drainage line, not only people face a lot of problems but the cost invloved to solve this problem would be way more expensive than preventing cost. </p> 
 
<h4>Objectives</h4>
<p> The solution we are looking for this problem is a Drainage Management System which is an IOT system.  Has the ability to not only alert the Management station . To detect the exact location of the blockage before the damges taking place. this project has the following features. </p> 
<ol>
  <li>	Detect the location of blockage </li>
  <li>	The system governing the flow of sewage from the pipes.  </li>
  <li>	Use of flow sensors to detect the variations in the flow. </li>
  <li>	Get the prior alerts of blockages and locate them using IOT. Trace location using GPS and send SMS through GSM.</li></ol>

<h4>1.2Block Diagram</h4>
<img src="photos/Block diagram.png" alt="Block Diagram" height="40%" width="70%" align="center">

<h2>2.System Analysis</h2>
<h3>2.2	Functional Requirement:</h3>
<p>&nbsp;&nbsp;&nbsp;&nbsp; When the water level rises in the drain the water overflows to the road. The drainage consists of water flow sensor which detects the flow of the water. If there is stop in the flow of water then there is a rise water level. The flow stops due to reasons like blockage in the drain. The water level sensor detects the rise in water, if the water level exceeds to more than the given threshold value then it can be a dangerous situation. When there is rise in water, with the help Of GPS and GSM a message is sent to the government body who are responsible for the cleanliness. So that they could clear up the drainage. We have used here temperature sensor to detect the temperature and also gas sensor. Gas sensor is used because it can also detect the harmful gas. In a city like Bangalore, in most areas gas pipe runs parallel to the drainage. So there are chances of leakage in the gas pip. Therefore, the gas sensor detects the flow of gas to ensure the safety of the personnel.  </p>

<h3>2.3	Requirement Specification:</h3>
<h4>2.3.1 Software Requirement</h4>
<h5>2.3.1.1 Arduino IDE: </h5>
<p>&nbsp;&nbsp;&nbsp;&nbsp; The Arduino Integrated Development Environment - or Arduino Software (IDE) it contains a text editor for writing code, a message area, a text console, a toolbar with buttons for common functions and a series of menus. It connects to the Arduino and Genuino hardware to upload programs and communicate with them.</p>

<h4>2.3.2 Hardware Requirement</h4>
		  
<ol>
   <li>Arduino Uno  </li>
   <li>Bread Board </li>
   <li>Jumper wire </li>
   <li>Water Flow sensor</li>
   <li>Water level sensor</li>
   <li>Temperature Sensor</li>
   <li>Gas sensor</li>
   <li>GPS</li>
   <li>GSM</li>
</ol>

<h2>CONCLUSION </h2>
<p>&nbsp;&nbsp;&nbsp;&nbsp; Underground monitoring is challenging problem. This project proposes different methods for monitoring and managing underground drainage system. It explains various applications like underground drainage and manhole identification in real time. Various parameters like temperature, toxic gases, flow and level of water are being monitored and updated on the internet using the Internet of Things. This enables the person in-charge to take the necessary actions regarding the same. In this way the unnecessary trips on the manholes are saved and can only be conducted as and when required. Also, real time update on the internet helps in maintaining the regularity in drainage check thus avoiding the hazards. </p>
