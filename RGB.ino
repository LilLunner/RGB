#include <Adafruit_NeoPixel.h>

#define PIN 2
#define NUMPIXELS 32

int speedRead = A0;
int red = A1;
int green = A2;
int blue = A3;

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
    pixels.begin();
    pinMode(speedRead, INPUT);
    pinMode(red, INPUT);
    pinMode(green, INPUT);
    pinMode(blue, INPUT);
}

void dj() {
    pixels.clear();

    for(int i=0; i<NUMPIXELS; i++) {
        pixels.setPixelColor(i, pixels.Color(analogRead(red)/5,analogRead(green)/5,analogRead(blue)/5));
        pixels.show();
        delay(analogRead(speedRead)/10);
    }
}

void loop() {
   dj(); 
}