# KEVN-core

This is the code for KEVN, our IoT device for monitoring stress. It is currently a very limited-prototype that uses an FSR (force sensitive resistor) to detect the applied pressure. Eventually we envision this as using conductive rubber/fabric on the outside, and a flexible resistor on the inside. This will allow us to have multiple variables to log potential stress levels. 

## How to setup the feather

1. Install the [Arduino IDE](https://www.arduino.cc/en/Main/Software)

1. Next take `keven.ino` from the `arduino-sketches` directory and copy it into a new Arduino Sketch

1. Flash the sketch onto your device over a serial port.

## Setup of local App

1. Run `npm install`

1. Run this command `node app.js --serialport="/dev/cu.usbmodem1411"`

Note: Your serial port might vary depending on your device. For a Macbook Pro it could be `/dev/cu.usbmodem1411` or `/dev/cu.usbmodem1421`.
