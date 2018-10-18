#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define PIN 6

// 1 is forward, -1 is reverse
int direction = 1;

int col = 0;

int i = 0;

uint8_t c;

Adafruit_NeoPixel matrix = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  matrix.begin();
  matrix.show(); // Initialize all pixels to 'off'
}

void do_intro(int elapsed_time) {
  int cycle = elapsed_time % 120;
  col = map(cycle, 0, 119, 0, 8);
  col *= direction;
  int prior_col = col - direction;
  matrix.setPixelColor(0 + prior_col, 0, 0, 0);
  matrix.setPixelColor(8 + prior_col, 0, 0, 0);
  matrix.setPixelColor(16 + prior_col, 0, 0, 0);
  matrix.setPixelColor(24 + prior_col, 0, 0, 0);
  matrix.setPixelColor(32 + prior_col, 0, 0, 0);
  
  matrix.setPixelColor(0 + col, 10, 0, 10);
  matrix.setPixelColor(8 + col, 10, 0, 10);
  matrix.setPixelColor(16 + col, 10, 0, 10);
  matrix.setPixelColor(24 + col, 10, 0, 10);
  matrix.setPixelColor(32 + col, 10, 0, 10);

  matrix.show();

  if (cycle == 0) {
    direction *= -1;
  }
}

void show_increment() {
  while (Serial.available() > 0) {
    c = Serial.read();
    if (c == 'a') {
      matrix.setPixelColor(0 + i, 10, 0, 10);
      matrix.setPixelColor(8 + i, 10, 0, 10);
      matrix.setPixelColor(16 + i, 10, 0, 10);
      matrix.setPixelColor(24 + i, 10, 0, 10);
      matrix.setPixelColor(32 + i, 10, 0, 10);
      matrix.show();
      i += 1;
    }
  }
}

void loop() {
  int elapsed = millis();
  if (elapsed < 600) {
    do_intro(elapsed);
    return;
  }
  else {
    show_increment();
  }
}



