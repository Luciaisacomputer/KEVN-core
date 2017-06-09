# KEVN-core
This is the code for KEVN, our IoT device for monitoring stress. It is currently a very limited-prototype that uses an FSR (force sensitive resistor) to detect the applied pressure. Eventually we envision this as using conductive rubber/fabric on the outside, and a flexible resistor on the inside. This will allow us to have multiple variables to log potential stress levels. 

## How to setup ardunio

Install the [Arduino IDE](https://www.arduino.cc/en/Main/Software)

Pull in this code in the editor and run it!


## Setup of local App

1. Run `npm install`

1. Run this command `node app.js --serialport="/dev/cu.usbmodem1411"`
