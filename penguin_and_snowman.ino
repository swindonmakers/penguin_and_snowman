// Penguin and Snowman Selfie Point Illumination

#include <FastLED.h>
#include "p_s.h"

#define BRIGHTNESS 96

#define LED_TYPE WS2811
#define COLOR_ORDER RGB

CRGB body[S_B_BODY_END - S_B_BODY_START];
CRGB head[S_HEAD_END - S_HEAD_START];
CRGB torso[S_TORSO_END - S_TORSO_START];
CRGB s_umbrella[S_UMBRELLA_END - S_UMBRELLA_START];
CRGB p_umbrella[P_UMBRELLA_END - P_UMBRELLA_START];
CRGB penguins[PENGUINS_END - PENGUINS_START];

uint8_t global_hue = 0;

void setup() {
    delay(3000);
    FastLED.addLeds<LED_TYPE, DATA_PIN_BODY,COLOR_ORDER>
    (body, S_B_BODY_END - S_B_BODY_START).setCorrection(TypicalLEDStrip);
    FastLED.addLeds<LED_TYPE, DATA_PIN_HEAD,COLOR_ORDER>
    (head, S_HEAD_END - S_HEAD_START).setCorrection(TypicalLEDStrip);
    FastLED.addLeds<LED_TYPE, DATA_PIN_TORSO,COLOR_ORDER>
    (torso, S_TORSO_END - S_TORSO_START).setCorrection(TypicalLEDStrip);
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
  color_item(body, S_B_BODY_START, S_B_BODY_START + S_B_BODY_CNT, S_B_BODY_COLOR);
  color_item(body, S_B_BADGE_START, S_B_BADGE_START + S_B_BADGE_CNT, S_B_BADGE_COLOR);
  
  // // Snowman Head
  color_item(head, S_HEAD_START, S_HEAD_START + S_FACE_CNT, S_FACE_COLOR);
  color_item(head, S_HAT_RIM_START, S_HAT_RIM_CNT + S_HAT_CNT, S_HAT_COLOR);
  color_item(head, S_MOUTH_START, S_MOUTH_START + S_FACE_CNT, S_MOUTH_COLOR);
  color_item(head, S_L_EYE_START, S_L_EYE_CNT + S_R_EYE_CNT, S_EYES_COLOR);
  color_item(head, S_NOSE_START, S_NOSE_START + S_NOSE_CNT, S_NOSE_COLOR);

  // Snowman Torso
  color_item(torso, S_R_OUTTER_ARM_START, S_R_OUTTER_ARM_CNT + S_R_HAND_CNT + S_R_INNER_ARM_CNT + S_M_BODY_CNT, S_B_BODY_COLOR);
  color_item(torso, S_T_SCARF_START, S_T_SCARF_CNT + S_B_SCARF_CNT + S_L_SCARF_CNT + S_R_SCARF_CNT, S_SCARF_COLOR);
  color_item(torso, S_L_T_ARM_START, S_L_T_ARM_CNT + S_L_HAND_CNT + S_L_B_ARM_CNT, S_B_BODY_COLOR);

  // Snowman Umbrella
  color_item(s_umbrella, S_UMBRELLA_START, S_UMBRELLA_END, S_UMBRELLA_COLOR);

  // Penguin Umbrella
  color_item(p_umbrella, P_UMBRELLA_START, P_UMBRELLA_END, P_UMBRELLA_COLOR);

  // Penguin 1
  color_item(penguins, P_1_L_FOOT_START, P_1_L_FOOT_CNT + P_1_R_FOOT_CNT, P_1_FOOT_COLOR);
  color_item(penguins, P_1_L_WING_START, P_1_L_WING_CNT, P_1_WING_COLOR);
  color_item(penguins, P_1_R_WING_START, P_1_R_WING_CNT, P_1_WING_COLOR);
  color_item(penguins, P_1_B_SCARF_START, P_1_B_SCARF_CNT + P_1_T_SCARF_CNT + P_1_R_SCARF_CNT + P_1_L_SCARF_CNT, P_1_SCARF_COLOR);
  color_item(penguins, P_1_BROW_START, P_1_BROW_CNT, P_1_BROW_COLOR);
  color_item(penguins, P_1_R_EYE_START, P_1_R_EYE_CNT, P_1_EYE_COLOR);
  color_item(penguins, P_1_L_EYE_START, P_1_L_EYE_CNT, P_1_EYE_COLOR);
  color_item(penguins, P_1_BEAK_START, P_1_BEAK_CNT, P_1_BEAK_COLOR);
  color_item(penguins, P_1_B_HAT_RIM_START, P_1_B_HAT_RIM_CNT + P_1_T_HAT_RIM_CNT, P_1_HAT_COLOR);
  color_item(penguins, P_1_L_BODY_START, P_1_L_BODY_CNT + P_1_B_BODY_CNT + P_1_B_BODY_CNT, P_1_BODY_COLOR);
  color_item(penguins, P_1_T_HAT_START, P_1_T_HAT_CNT, P_1_HAT_COLOR);
  color_item(penguins, P_1_HAT_POM_START, P_1_HAT_POM_CNT, P_1_HAT_POM_COLOR);

  // Penguin 2
  color_item(penguins, P_2_L_FOOT_START, P_2_L_FOOT_CNT + P_2_R_FOOT_CNT, P_2_FOOT_COLOR);
  color_item(penguins, P_2_L_WING_START, P_2_L_WING_CNT, P_2_WING_COLOR);
  color_item(penguins, P_2_R_WING_START, P_2_R_WING_CNT, P_2_WING_COLOR);
  color_item(penguins, P_2_B_SCARF_START, P_2_B_SCARF_CNT + P_2_T_SCARF_CNT + P_2_R_SCARF_CNT + P_2_L_SCARF_CNT, P_2_SCARF_COLOR);
  color_item(penguins, P_2_B_BODY_START, P_2_B_BODY_CNT + P_2_T_BODY_CNT, P_2_BODY_COLOR);
  color_item(penguins, P_2_L_EAR_START, P_2_L_EAR_CNT, P_2_EAR_COLOR);
  color_item(penguins, P_2_R_EAR_START, P_2_R_EAR_CNT, P_2_EAR_COLOR);
  color_item(penguins, P_2_BROW_START, P_2_BROW_CNT, P_2_BROW_COLOR);
  color_item(penguins, P_2_R_EYE_START, P_2_R_EYE_CNT, P_2_EYE_COLOR);
  color_item(penguins, P_2_L_EYE_START, P_2_L_EYE_CNT, P_2_EYE_COLOR);
  color_item(penguins, P_2_BEAK_START, P_2_BEAK_CNT, P_2_BEAK_COLOR);

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
