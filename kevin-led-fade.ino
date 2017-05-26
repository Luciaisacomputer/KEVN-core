#include <Adafruit_NeoPixel.h>

#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6
#define NUMPIXELS 12

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRBW + NEO_KHZ800);

int waitTime = 25; // delay for half a second

// the setup function runs once when you press reset or power the board
void setup() {
  strip.begin();
  strip.show();
}

// the loop function runs over and over again forever
void loop() {
  fadeInAndOut(0, 255, 0, waitTime); // Green
  fadeInAndOut(0, 0, 255, waitTime); // Blue
}


void fadeInAndOut(uint8_t red, uint8_t green, uint8_t blue, uint8_t wait) {

  for(uint8_t b=0; b <255; b++) {
     for(uint8_t i=0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 0, green*b/255, blue*b/255, 0);
     }
     strip.show();
     delay(wait);
  };

  for(uint8_t b=255; b > 0; b--) {
     for(uint8_t i=0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 0, green*b/255, blue*b/255, 0);
     }
     strip.show();
     delay(wait);
  };
};
