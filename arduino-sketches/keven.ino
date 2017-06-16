#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_NeoPixel.h>

#if not defined (_VARIANT_ARDUINO_DUE_X_) && not defined(ARDUINO_ARCH_SAMD)
  #include <SoftwareSerial.h>
#endif

#include <Adafruit_BLE.h>
#include <Adafruit_BluefruitLE_SPI.h>
#include <Adafruit_BluefruitLE_UART.h>
#include "BluefruitConfig.h"
#include "ColorWheelConfig.h"

#ifdef __AVR__
  #include <avr/power.h>
#endif

#define FACTORYRESET_ENABLE         0
#define MINIMUM_FIRMWARE_VERSION    "0.6.6"

void Ring1Complete();

// Define some NeoPatterns for the two rings and the stick
//  as well as some completion routines
NeoPatterns Ring1(12, 6, NEO_GRBW + NEO_KHZ800, &Ring1Complete);

int fsrPin = 0;     // the FSR and 10K pulldown are connected to a0
int fsrReading;     // the analog reading from the FSR resistor divider

SoftwareSerial bluefruitSS = SoftwareSerial(BLUEFRUIT_SWUART_TXD_PIN, BLUEFRUIT_SWUART_RXD_PIN);

Adafruit_BluefruitLE_UART ble(bluefruitSS, BLUEFRUIT_UART_MODE_PIN,
                      BLUEFRUIT_UART_CTS_PIN, BLUEFRUIT_UART_RTS_PIN);

 // A small helper
void error(const __FlashStringHelper*err) 
{
  Serial.println(err);
  while (1);
}

// Initialize everything and prepare to start
void setup()
{


  Serial.begin(9600);
  ble.begin();
  ble.factoryReset();
  ble.sendCommandCheckOK(F( "AT+GAPDEVNAME=KEVN" ));
  ble.setMode(BLUEFRUIT_MODE_DATA);
  // Initialize all the pixelStrips
  Ring1.begin();

    
  // Kick off a pattern
  //Ring1.RainbowCycle(3);
  Ring1.TheaterChase(Ring1.Color(0,255,0, 15), Ring1.Color(0,0,225, 0), 100);
}

// Main loop
void loop()
{
  // Update the rings.
  Ring1.Update();   
  readFSR();
}

//------------------------------------------------------------
//Completion Routines - get called on completion of a pattern
//------------------------------------------------------------

// Ring1 Completion Callback
void Ring1Complete()
{
    Ring1.Reverse();
}

void readFSR(void) 
{
  fsrReading = analogRead(fsrPin);  
  Serial.println(fsrReading);     // the raw analog reading
  ble.println(fsrReading); // bluetooth reading over software serial
  delay(1000);
}
