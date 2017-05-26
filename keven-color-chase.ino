#include <Adafruit_NeoPixel.h>

#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6
#define NUMPIXELS 12

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRBW + NEO_KHZ800);

int waitTime = 50; // delay for half a second

// the setup function runs once when you press reset or power the board
void setup() {
  strip.begin();
  strip.show();
}

// the loop function runs over and over again forever
void loop() {
   for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    strip.setPixelColor(i, strip.Color(0,150,0)); // Moderately bright green color.
  
    strip.show(); // This sends the updated pixel color to the hardware.
    
    delay(waitTime); // Delay for a period of time (in milliseconds).
  }

   for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    strip.setPixelColor(i, strip.Color(0,0,150)); // Moderately bright green color.
  
    strip.show(); // This sends the updated pixel color to the hardware.
    
    delay(waitTime); // Delay for a period of time (in milliseconds).
  }
}
