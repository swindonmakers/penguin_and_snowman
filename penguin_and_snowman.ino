// Penguin and Snowman Selfie Point Illumination

#include <FastLED.h>
#include "p_s.h"

#define BRIGHTNESS 96

#define LED_TYPE WS2812
#define COLOR_ORDER GRB

CRGB body[BODY_END - BODY_START];
CRGB head[HEAD_END - HEAD_START];

void setup() {
    FastLED.addLeds<LED_TYPE, DATA_PIN_BODY,COLOR_ORDER>
    (body, BODY_END - BODY_START).setCorrection(TypicalLEDStrip);
    FastLED.addLeds<LED_TYPE, DATA_PIN_HEAD,COLOR_ORDER>
    (head, HEAD_END - HEAD_START).setCorrection(TypicalLEDStrip);

    FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
   // Snowman Head
   color_item(head, HAT_START, HAT_END, HAT_COLOR);
   color_item(head, FACE_START, FACE_END, FACE_COLOR);
   color_item(head, MOUTH_START, MOUTH_END, MOUTH_COLOR);
   
   FastLED.show();
}

void color_item(CRGB section[], int start_led, int end_led, int color) {
   for( int i = start_led; i <= end_led; i++) {
       section[i] = color;
   }    
}
