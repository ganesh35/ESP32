# Testing MQTT Functionality

MQTT (Message Queuing Telemetry Transport) broker receives all messages from the clients (Publishers) and then routes the messages to the appropriate destination clients (Subscribers).

An MQTT client is any device (from a micro controller up to a fully-fledged server) that runs an MQTT library and connects to an MQTT broker over a network.

- [Tools and Materials](#tools-and-materials)
- [How-to](#how-to)
- [The Breadboard](#the-breadboard)
- [Code](#code)
- [Conclusion](#conclusion)

## Tools and Materials
Required Software tools for this project are:
- MQTT Broker
	We can utilize existing community servers for testing purpose rather than installing a new one.
	- Protocol: mqtt://
	- Host: mqtt.eclipse.org
	- Port: 1883

- MQTT Clients
	- MQTT Explorer for Windows 
		Site: http://mqtt-explorer.com/
		Downlod Link: https://github.com/thomasnordquist/MQTT-Explorer/releases/download/0.0.0-0.4.0-beta1/MQTT-Explorer-Setup-0.4.0-beta1.exe
	- MQTT Dashboard for Android
		Site: https://play.google.com/store/apps/details?id=com.app.vetru.mqttdashboard

## How-to
### Step #1: Install
![Install MQTT Explorer](./assets/01_insall_mqtt_explorer.png?raw=true)

[![Download and Install MQTT Explorer for windows](https://img.youtube.com/vi/hxiqCPJElR4/0.jpg)](https://youtu.be/hxiqCPJElR4)

### Step #2: Configure
	- Open MQTT Explorer
	- Select mqtt.eclipse.org from the left connections menu
	- Click on Connect button
	![Install MQTT Explorer](./assets/02_mqtt_connection2eclipse.png?raw=true)
	For this test we will use mqtt.eclipse.org broker, so we need not to enter any configuration details here.

