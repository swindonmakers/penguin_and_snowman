// Penguin and Snowman Selfie Point Illumination

#include <FastLED.h>

// Defines leds for various parts:

#define DATA_PIN_HEAD 4
#define DATA_PIN_BODY 5
#define DATA_PIN_UMBRELLA 6

#define BODY_START   0
#define BODY_END     5
// Head
#define HEAD_START   0
#define HEAD_END    13
// Hat + Face are subsets of Head
#define HAT_START    0
#define HAT_END      4
#define FACE_START   5
#define FACE_END     9
#define MOUTH_START 10
#define MOUTH_END   13

// Might need more than one of these?
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
   for( int i = HAT_START; i = HAT_END; i++) {
       head[i] = CRGB::Blue;
   }
   for( int i = FACE_START; i = FACE_END; i++) {
       head[i] = CRGB::White;
   }
   for( int i = MOUTH_START; i = MOUTH_END; i++) {
       head[i] = CRGB::Red;
   }
   FastLED.show();
}
