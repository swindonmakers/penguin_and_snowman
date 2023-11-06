// Penguin and Snowman Selfie Point Illumination

#include <FastLED.h>
#include "p_s.h"

#define BRIGHTNESS 96

#define LED_TYPE WS2811
#define COLOR_ORDER GRB

CRGB body[BODY_END - BODY_START];
CRGB head[HEAD_END - HEAD_START];
CRGB torso[TORSO_END - TORSO_START];
CRGB s_umbrella[S_UMBRELLA_END - S_UMBRELLA_START];
CRGB p_umbrella[P_UMBRELLA_END - P_UMBRELLA_START];
CRGB penguins[PENGUINS_END - PENGUINS_START];

void setup() {
    FastLED.addLeds<LED_TYPE, DATA_PIN_BODY,COLOR_ORDER>
    (body, BODY_END - BODY_START).setCorrection(TypicalLEDStrip);
    FastLED.addLeds<LED_TYPE, DATA_PIN_HEAD,COLOR_ORDER>
    (head, HEAD_END - HEAD_START).setCorrection(TypicalLEDStrip);
    FastLED.addLeds<LED_TYPE, DATA_PIN_TORSO,COLOR_ORDER>
    (torso, TORSO_END - TORSO_START).setCorrection(TypicalLEDStrip);
    FastLED.addLeds<LED_TYPE, DATA_PIN_S_UMBRELLA,COLOR_ORDER>
    (s_umbrella, S_UMBRELLA_END - S_UMBRELLA_START).setCorrection(TypicalLEDStrip);
    FastLED.addLeds<LED_TYPE, DATA_PIN_P_UMBRELLA,COLOR_ORDER>
    (p_umbrella, P_UMBRELLA_END - P_UMBRELLA_START).setCorrection(TypicalLEDStrip);
    FastLED.addLeds<LED_TYPE, DATA_PIN_PENGUINS,COLOR_ORDER>
    (penguins, PENGUINS_END - PENGUINS_START).setCorrection(TypicalLEDStrip);

    FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  // Snowman Body
  color_item(body, BODY_START, BODY_END, BODY_COLOR);
  
  // Snowman Head
  color_item(head, HAT_START, HAT_END, HAT_COLOR);
  color_item(head, FACE_START, FACE_END, FACE_COLOR);
  color_item(head, MOUTH_START, MOUTH_END, MOUTH_COLOR);
  color_item(head, EYES_START, EYES_END, EYES_COLOR);
  color_item(head, NOSE_START, NOSE_END, NOSE_COLOR);

  // Snowman Torso
  color_item(torso, L_HAND_START, L_HAND_END, L_HAND_COLOR);
  color_item(torso, L_ARM_START,  L_ARM_END,  L_ARM_COLOR);
  color_item(torso, T_MAIN_START, T_MAIN_END, T_MAIN_COLOR);
  color_item(torso, R_HAND_START, R_HAND_END, R_HAND_COLOR);
  color_item(torso, R_ARM_START,  R_ARM_END,  R_ARM_COLOR);
  color_item(torso, T_SCARF_START, T_SCARF_END, T_SCARF_COLOR);

  // Snowman Umbrella
  color_item(s_umbrella, S_UMBRELLA_START, S_UMBRELLA_END, S_UMBRELLA_COLOR);

  // Penguin Umbrella
  color_item(p_umbrella, P_UMBRELLA_START, P_UMBRELLA_END, P_UMBRELLA_COLOR);

  // Penguin 1 body
  color_item(penguins, P_1_BODY_START, 

  FastLED.show();
}

void color_item(CRGB section[], int start_led, int end_led, int color) {
   for( int i = start_led; i <= end_led; i++) {
       section[i] = color;
   }    
}
