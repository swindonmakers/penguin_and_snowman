// Penguin and Snowman Selfie Point Illumination

#include <FastLED.h>
#include "p_s.h"

#define BRIGHTNESS 96

#define LED_TYPE WS2811
#define COLOR_ORDER RGB

CRGB body[BODY_END - BODY_START];
CRGB head[HEAD_END - HEAD_START + 1];
CRGB torso[TORSO_END - TORSO_START];
CRGB s_umbrella[S_UMBRELLA_END - S_UMBRELLA_START];
CRGB p_umbrella[P_UMBRELLA_END - P_UMBRELLA_START];
CRGB penguins[PENGUINS_END - PENGUINS_START];

uint8_t global_hue = 0;

void setup() {
    delay(3000);
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
  
  // // Snowman Head
  color_item(head, HAT_START, HAT_START+HAT_CNT, HAT_COLOR);
  color_item(head, FACE_START, FACE_START+FACE_CNT, FACE_COLOR);
  color_item(head, MOUTH_START, MOUTH_START+MOUTH_CNT, MOUTH_COLOR);
  color_item(head, EYES_START, EYES_START+EYES_CNT, EYES_COLOR);
  color_item(head, NOSE_START, NOSE_START+NOSE_CNT, NOSE_COLOR);

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
  color_item(penguins, P_1_BODY_START, P_1_BODY_END, P_1_BODY_COLOR);

  p_umbrella_rainbow_wipe(global_hue);
  s_umbrella_rainbow_wipe(global_hue+80);
  global_hue--;
  delay(100);

  FastLED.show();
}

void color_item(CRGB section[], int start_led, int end_led, int color) {
   for( int i = start_led; i < end_led; i++) {
       section[i] = color;
   }    
}

//Penguin umbrella colour wipe
void p_umbrella_rainbow_wipe(uint8_t hue){
  uint8_t spread = 120; //amount of hue across the umbrella
  uint8_t spread_mid = spread/2; //halfway point
  CHSV hsv;
  hsv.hue = hue;
  hsv.val = 255;
  hsv.sat = 240;
  //go thought section by section in order as they are wired up
  //left center rib
  for (uint8_t i = 0; i <P_UMBRELLA_HANDLE_CNT ; i++ ){
    hsv.hue = hue + spread_mid; //last 2 digits map position from left to right of the rib
    p_umbrella[i + P_UMBRELLA_HANDLE_START] = hsv;
  }


  //left center rib
  for (uint8_t i = 0; i < P_UMBRELLA_L_RIB_CENTRE_CNT; i++ ){
    hsv.hue = hue + map(i, 0, P_UMBRELLA_L_RIB_CENTRE_CNT,spread*0.33, spread_mid); //last 2 digits map position from left to right of the rib
    p_umbrella[i + P_UMBRELLA_L_RIB_CENTRE_START] = hsv;
  }

  //right mid rib
  for (uint8_t i = 0; i < P_UMBRELLA_R_RIB_MID_CNT; i++ ){
    hsv.hue = hue + map(i, 0, P_UMBRELLA_R_RIB_MID_CNT,spread_mid, spread*0.8); //last 2 digits map position from left to right of the rib
    p_umbrella[i+ P_UMBRELLA_R_RIB_MID_START] = hsv;
  }
  
  //right center rib
  for (uint8_t i = 0; i < P_UMBRELLA_R_RIB_CENTRE_CNT; i++ ){
    hsv.hue = hue + map(i, 0, P_UMBRELLA_R_RIB_CENTRE_CNT,spread*.67, spread_mid); //last 2 digits map position from left to right of the rib
    p_umbrella[i+ P_UMBRELLA_R_RIB_CENTRE_START] = hsv;
  }

  //left mid rib
  for (uint8_t i = 0; i < P_UMBRELLA_L_RIB_MID_CNT; i++ ){
    hsv.hue = hue + map(i, 0, P_UMBRELLA_L_RIB_MID_CNT,spread_mid, spread*0.2); //last 2 digits map position from left to right of the rib
    p_umbrella[i+ P_UMBRELLA_L_RIB_MID_START] = hsv;
  }  

  //left outer rib
  for (uint8_t i = 0; i < P_UMBRELLA_L_RIB_OUTER_CNT; i++ ){
    hsv.hue = hue + map(i, 0, P_UMBRELLA_L_RIB_OUTER_CNT,0, spread_mid); //last 2 digits map position from left to right of the rib
    p_umbrella[i+ P_UMBRELLA_L_RIB_OUTER_START] = hsv;
  }    
  //right outer rib
  for (uint8_t i = 0; i < P_UMBRELLA_R_RIB_OUTER_CNT; i++ ){
    hsv.hue = hue + map(i, 0, P_UMBRELLA_R_RIB_OUTER_CNT,spread_mid, spread); //last 2 digits map position from left to right of the rib
    p_umbrella[i+ P_UMBRELLA_R_RIB_OUTER_START] = hsv;
  }    
  
  //right outer rib
  for (uint8_t i = 0; i < P_UMBRELLA_BTM_CANOPY_CNT; i++ ){
    hsv.hue = hue + map(i, 0, P_UMBRELLA_BTM_CANOPY_CNT,spread, 0); //last 2 digits map position from left to right of the rib
    p_umbrella[i+ P_UMBRELLA_BTM_CANOPY_START] = hsv;
  } 
}

//Snowman umbrella colour wipe
void s_umbrella_rainbow_wipe(uint8_t hue){
  uint8_t spread = 160; //amount of hue across the umbrella
  uint8_t spread_mid = spread/2; //halfway point
  CHSV hsv;
  hsv.hue = hue;
  hsv.val = 255;
  hsv.sat = 240;
  //go thought section by section in order as they are wired up
  //left center rib
  for (uint8_t i = 0; i <S_UMBRELLA_HANDLE_CNT ; i++ ){
    hsv.hue = hue + spread_mid; //last 2 digits map position from left to right of the rib
    s_umbrella[i + S_UMBRELLA_HANDLE_START] = hsv;
  }


  //left center rib
  for (uint8_t i = 0; i < S_UMBRELLA_L_RIB_CENTRE_CNT; i++ ){
    hsv.hue = hue + map(i, 0, S_UMBRELLA_L_RIB_CENTRE_CNT,spread*0.33, spread_mid); //last 2 digits map position from left to right of the rib
    s_umbrella[i + S_UMBRELLA_L_RIB_CENTRE_START] = hsv;
  }

  //right mid rib
  for (uint8_t i = 0; i < S_UMBRELLA_R_RIB_MID_CNT; i++ ){
    hsv.hue = hue + map(i, 0, S_UMBRELLA_R_RIB_MID_CNT,spread_mid, spread*0.8); //last 2 digits map position from left to right of the rib
    s_umbrella[i+ S_UMBRELLA_R_RIB_MID_START] = hsv;
  }
  
  //right center rib
  for (uint8_t i = 0; i < S_UMBRELLA_R_RIB_CENTRE_CNT; i++ ){
    hsv.hue = hue + map(i, 0, S_UMBRELLA_R_RIB_CENTRE_CNT,spread*.67, spread_mid); //last 2 digits map position from left to right of the rib
    s_umbrella[i+ S_UMBRELLA_R_RIB_CENTRE_START] = hsv;
  }

  //left mid rib
  for (uint8_t i = 0; i < S_UMBRELLA_L_RIB_MID_CNT; i++ ){
    hsv.hue = hue + map(i, 0, S_UMBRELLA_L_RIB_MID_CNT,spread_mid, spread*0.2); //last 2 digits map position from left to right of the rib
    s_umbrella[i+ S_UMBRELLA_L_RIB_MID_START] = hsv;
  }  

  //left outer rib
  for (uint8_t i = 0; i < S_UMBRELLA_L_RIB_OUTER_CNT; i++ ){
    hsv.hue = hue + map(i, 0, S_UMBRELLA_L_RIB_OUTER_CNT,0, spread_mid); //last 2 digits map position from left to right of the rib
    s_umbrella[i+ S_UMBRELLA_L_RIB_OUTER_START] = hsv;
  }    
  //right outer rib
  for (uint8_t i = 0; i < S_UMBRELLA_R_RIB_OUTER_CNT; i++ ){
    hsv.hue = hue + map(i, 0, S_UMBRELLA_R_RIB_OUTER_CNT,spread_mid, spread); //last 2 digits map position from left to right of the rib
    s_umbrella[i+ S_UMBRELLA_R_RIB_OUTER_START] = hsv;
  }    
  
  //right outer rib
  for (uint8_t i = 0; i < S_UMBRELLA_BTM_CANOPY_CNT; i++ ){
    hsv.hue = hue + map(i, 0, S_UMBRELLA_BTM_CANOPY_CNT,spread, 0); //last 2 digits map position from left to right of the rib
    s_umbrella[i+ S_UMBRELLA_BTM_CANOPY_START] = hsv;
  } 
}
