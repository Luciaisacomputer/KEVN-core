# KEVN-core
The core code for the IOT device itself

## How to setup the feather

1. Install the [Arduino IDE](https://www.arduino.cc/en/Main/Software)

1. Next take `keven.ino` from the `arduino-sketches` directory and copy it into a new Arduino Sketch

1. Flash the sketch onto your device over a serial port.

## Setup of local App

1. Run `npm install`

1. Run this command `node app.js --serialport="/dev/cu.usbmodem1411"`

Note: Your serial port might vary depending on your device. For a Macbook Pro it could be `/dev/cu.usbmodem1411` or `/dev/cu.usbmodem1421`.
