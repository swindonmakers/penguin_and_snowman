// Penguin and Snowman Selfie Point Illumination

#include <FastLED.h>
#include "p_s.h"

#define BRIGHTNESS 120

#define LED_TYPE WS2811
#define COLOR_ORDER RGB

CRGB body[S_B_BODY_END - S_B_BODY_START];
CRGB display[DISPLAY_CNT];
CRGB head[S_HEAD_END - S_HEAD_START];
CRGB torso[S_TORSO_END - S_TORSO_START];
CRGB s_umbrella[S_UMBRELLA_END - S_UMBRELLA_START];
CRGB p_umbrella[P_UMBRELLA_END - P_UMBRELLA_START];
CRGB penguins[PENGUINS_END - PENGUINS_START];
CRGB squirrel[SQ_END - SQ_START];
CRGB owl[OWL_END - OWL_START];

//default colours
CRGB squirrel_default[SQ_END - SQ_START];

//previous led values (useful for animations)
CRGB squirrel_old[SQ_END - SQ_START];

uint8_t global_hue = 0;
// int analogPin = A1;

uint8_t lightchase_pos = 0;
uint8_t lightchase_pos_old = 0;
uint8_t lightchase_pos_old_old = 0;
uint8_t lightchase_pos_new = 0;
int animation_timer = 0;
int animation_select = 0;
int animation_select_old = -1;
int animation_state = ANIMATION_STATE_NEW;
int animation_segment_time = 0; //number of seconds it stays here
int selected_light_chase = 0; //object that will have the light chase on it
int fade_counter = 0;

int performance = 0;


void next_on_sequence(){ //next animation, all lights currently on
        //time to change animation
        animation_select_old = animation_select;
        int number_of_next_states = 5;
        int next_states[number_of_next_states] = {ANIMATION_SPREADOFF,ANIMATION_LIGHTCHASE,ANIMATION_LIGHTCHASE,ANIMATION_FADEOUT,ANIMATION_ORIGINAL};  
        int next_state_loc = random(0,number_of_next_states);
        animation_select = next_states[next_state_loc];
        if (animation_select == animation_select_old){
          animation_select = -1;
          animation_state = ANIMATION_STATE_DONE;
        }
        animation_select = ANIMATION_LIGHTCHASE; //TODO remove
        Serial.println("GOING TO STATE");
        Serial.println(animation_select);
}

void next_off_sequence(){

}


void all_default_colour(){
  // // // Display colour
  // color_item(display, 0, DISPLAY_CNT, DISPLAY_COLOR);
  // color_item(body, S_B_BODY_START, S_B_BODY_START + S_B_BODY_CNT, CRGB(100,255,100));
  // color_item(body, S_B_BADGE_START, S_B_BADGE_START + S_B_BADGE_CNT, CRGB(40,  255,  0));
  
  // // // Snowman Head
  // color_item(head, S_HEAD_START, S_HEAD_START + S_FACE_CNT, CRGB(100,255,100));
  // color_item(head, S_HAT_RIM_START, S_HAT_RIM_START + S_HAT_RIM_CNT + S_HAT_CNT, S_HAT_COLOR);
  // color_item(head, S_MOUTH_START, S_MOUTH_START + S_FACE_CNT, S_MOUTH_COLOR);
  // color_item(head, S_L_EYE_START, S_L_EYE_START + S_L_EYE_CNT + S_R_EYE_CNT, CRGB(70,0,0));
  // color_item(head, S_NOSE_START, S_NOSE_START + S_NOSE_CNT, S_NOSE_COLOR);

  // // Snowman Torso

  // color_item(torso, S_R_OUTTER_ARM_START, S_R_OUTTER_ARM_CNT,  CRGB(100,255,100));
  // color_item(torso, S_R_HAND_START, S_R_HAND_START + S_R_HAND_CNT,  CRGB::Green);
  // color_item(torso, S_R_INNER_ARM_START, S_R_INNER_ARM_START + S_R_INNER_ARM_CNT,  CRGB(100,255,100));
  // color_item(torso, S_M_BODY_START, S_M_BODY_START + S_M_BODY_CNT,  CRGB(100,255,100));
  // color_item(torso, S_T_SCARF_START, S_T_SCARF_START + S_T_SCARF_CNT + S_B_SCARF_CNT + S_L_SCARF_CNT + S_R_SCARF_CNT, S_SCARF_COLOR);
  // color_item(torso, S_L_T_ARM_START, S_L_T_ARM_START + S_L_T_ARM_CNT + S_L_HAND_CNT + S_L_B_ARM_CNT,  CRGB(100,255,100));
  // color_item(torso, S_L_HAND_START, S_L_HAND_START + S_L_HAND_CNT,  CRGB::Green);
  // color_item(torso, S_L_B_ARM_START, S_L_B_ARM_START + S_L_B_ARM_CNT,  CRGB(100,255,100));

  // // Snowman Umbrella
  // color_item(s_umbrella, S_UMBRELLA_START, S_UMBRELLA_END, S_UMBRELLA_COLOR);

  // // Penguin Umbrella
  // color_item(p_umbrella, P_UMBRELLA_START, P_UMBRELLA_END, P_UMBRELLA_COLOR);

  // // Penguin 1
  // color_item(penguins, P_1_L_FOOT_START, P_1_L_FOOT_START + P_1_L_FOOT_CNT + P_1_R_FOOT_CNT, P_1_FOOT_COLOR);
  // color_item(penguins, P_1_R_WING_START, P_1_R_WING_START + P_1_R_WING_CNT, P_1_WING_COLOR);
  // color_item(penguins, P_1_B_SCARF_START, P_1_B_SCARF_START + P_1_B_SCARF_CNT + P_1_T_SCARF_CNT + P_1_R_SCARF_CNT + P_1_L_SCARF_CNT, P_1_SCARF_COLOR);
  // color_item(penguins, P_1_BROW_START, P_1_BROW_START + P_1_BROW_CNT, P_1_BROW_COLOR);
  // color_item(penguins, P_1_R_EYE_START, P_1_R_EYE_START + P_1_R_EYE_CNT, CRGB(109,  82,  16));
  // color_beak_1(penguins, P_1_BEAK_START, CRGB(40,  255,  0));
  // color_item(penguins, P_1_L_EYE_START, P_1_L_EYE_START + P_1_L_EYE_CNT, CRGB(109,  82,  16)); 
  // color_item(penguins, P_1_L_WING_START, P_1_L_WING_START + P_1_L_WING_CNT, P_1_WING_COLOR);
  // color_item(penguins, P_1_B_HAT_RIM_START, P_1_B_HAT_RIM_START+  P_1_B_HAT_RIM_CNT + P_1_T_HAT_RIM_CNT, P_1_HAT_COLOR);
  // color_item(penguins, P_1_L_BODY_START, P_1_L_BODY_START + P_1_L_BODY_CNT , P_1_BODY_COLOR2);
  // color_item(penguins, P_1_B_BODY_START, P_1_B_BODY_START + P_1_B_BODY_CNT , P_1_BODY_COLOR);
  // color_item(penguins, P_1_R_BODY_START, P_1_R_BODY_START + P_1_R_BODY_CNT , P_1_BODY_COLOR2);
  // color_item(penguins, P_1_T_HAT_START, P_1_T_HAT_START + P_1_T_HAT_CNT, P_1_HAT_COLOR);
  // color_item(penguins, P_1_HAT_POM_START, P_1_HAT_POM_START + P_1_HAT_POM_CNT, P_1_HAT_POM_COLOR);
  // color_item(penguins, P_1_B_HAT_START, P_1_B_HAT_START + P_1_B_HAT_CNT, P_1_HAT_COLOR);

  // // Penguin 2
  // color_item(penguins, P_2_L_FOOT_START, P_2_L_FOOT_START + P_2_L_FOOT_CNT + P_2_R_FOOT_CNT, P_2_FOOT_COLOR);
  // color_item(penguins, P_2_L_WING_START, P_2_L_WING_START + P_2_L_WING_CNT, P_2_WING_COLOR);
  // color_item(penguins, P_2_R_WING_START, P_2_R_WING_START + P_2_R_WING_CNT, P_2_WING_COLOR);
  // color_item(penguins, P_2_B_SCARF_START, P_2_B_SCARF_START + P_2_B_SCARF_CNT + P_2_T_SCARF_CNT + P_2_R_SCARF_CNT + P_2_L_SCARF_CNT, P_2_SCARF_COLOR);
  // color_item(penguins, P_2_B_BODY_START, P_2_B_BODY_START + P_2_B_BODY_CNT , P_2_BODY_COLOR);
  // color_item(penguins, P_2_T_BODY_START, P_2_T_BODY_START + P_2_T_BODY_CNT , CRGB(80,255,80)); //"white"
  // color_item(penguins, P_2_L_EAR_START, P_2_L_EAR_START + P_2_L_EAR_CNT, P_2_EAR_COLOR);
  // color_item(penguins, P_2_R_EAR_START, P_2_R_EAR_START + P_2_R_EAR_CNT, P_2_EAR_COLOR);
  // color_item(penguins, P_2_BROW_START, P_2_BROW_START + P_2_BROW_CNT, P_2_BROW_COLOR);
  // color_item(penguins, P_2_R_EYE_START, P_2_R_EYE_START + P_2_R_EYE_CNT, CRGB(120,120,0)); //yellow
  // color_item(penguins, P_2_L_EYE_START,  P_2_L_EYE_START + P_2_L_EYE_CNT, CRGB(120,120,0)); //yellow
  // color_beak_2(penguins, P_2_BEAK_START, CRGB(40,  255,  0));


  //squirrel
  color_item(squirrel, SQ_START, SQ_TOOTH_ST, SQ_BODY_COLOR);
  color_item(squirrel, SQ_TOOTH_ST, SQ_TOOTH_ST + SQ_TOOTH_CNT, SQ_TOOTH_COLOR);
  color_item(squirrel, SQ_R_EYE_ST, SQ_R_EYE_ST + SQ_R_EYE_CNT + SQ_L_EYE_CNT, SQ_EYE_COLOR);
  color_item(squirrel, SQ_L_OUT_EYE_ST, SQ_END, SQ_BODY_COLOR);
}

void all_off(){
  //squirrel
  color_item(squirrel, SQ_START, SQ_TOOTH_ST, CRGB::Black);
  color_item(squirrel, SQ_TOOTH_ST, SQ_TOOTH_ST + SQ_TOOTH_CNT, CRGB::Black);
  color_item(squirrel, SQ_R_EYE_ST, SQ_R_EYE_ST + SQ_R_EYE_CNT + SQ_L_EYE_CNT, CRGB::Black);
  color_item(squirrel, SQ_L_OUT_EYE_ST, SQ_END, CRGB::Black);  
}

uint8_t get_squirrel_neighbour_led(uint8_t current_pos, uint8_t old_pos){
  uint8_t new_pos = current_pos;
  if (squirrel_nodes[current_pos][1] == 255)//only one answer
    return(squirrel_nodes[current_pos][0]);
  // Serial.println(squirrel_nodes[current_pos][0]);
  // Serial.println(squirrel_nodes[current_pos][1]);
  // Serial.println(squirrel_nodes[current_pos][2]);
  // Serial.println(squirrel_nodes[current_pos][3]);
  // if (squirrel_nodes[current_pos][0] != 255)
  //   squirrel[squirrel_nodes[current_pos][0]] = CRGB::Red;  
  // if (squirrel_nodes[current_pos][1] != 255)
  //   squirrel[squirrel_nodes[current_pos][1]] = CRGB::Green;
  // if (squirrel_nodes[current_pos][2] != 255)
  //   squirrel[squirrel_nodes[current_pos][2]] = CRGB::Blue;
  // if (squirrel_nodes[current_pos][3] != 255)
  //   squirrel[squirrel_nodes[current_pos][3]] = CRGB::Purple;

  do {
      new_pos = squirrel_nodes[current_pos][random(0,4)];
    } while ((new_pos == old_pos) || (new_pos == 255));
  return new_pos;
}

uint8_t get_owl_neighbour_led(uint8_t current_pos, uint8_t old_pos){
  uint8_t new_pos = current_pos;
  uint8_t pick_size = 1;
  if (owl_nodes[current_pos][1] == 255)//only one answer
    return(owl_nodes[current_pos][0]);  
  // Serial.println(owl_nodes[current_pos][0]);
  // Serial.println(owl_nodes[current_pos][1]);
  // Serial.println(owl_nodes[current_pos][2]);
  // Serial.println(owl_nodes[current_pos][3]);
  // if (owl_nodes[current_pos][0] != 255)
  //   owl[owl_nodes[current_pos][0]] = CRGB::Red;  
  // if (owl_nodes[current_pos][1] != 255)
  //   owl[owl_nodes[current_pos][1]] = CRGB::Green;
  // if (owl_nodes[current_pos][2] != 255)
  //   owl[owl_nodes[current_pos][2]] = CRGB::Blue;
  // if (owl_nodes[current_pos][3] != 255)
  //   owl[owl_nodes[current_pos][3]] = CRGB::Purple;

  do {
      new_pos = owl_nodes[current_pos][random(0,4)];
    } while ((new_pos == old_pos) || (new_pos == 255));
  return new_pos;
}

void color_beak_1(CRGB section[], int start_led , CRGB color){
  //section[start_led+0] = color;
  section[start_led+1] = color;
  section[start_led+2] = color;
  section[start_led+3] = color;
  section[start_led+4] = color;
}

void color_beak_2(CRGB section[], int start_led , CRGB color){
  //section[start_led+0] = color;
  section[start_led+1] = color;
  section[start_led+2] = color;
  section[start_led+5] = color;
  section[start_led+6] = color;
}

void color_item(CRGB section[], int start_led, int end_led, CRGB color) {
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

void setup() {
  delay(1000);
  // FastLED.addLeds<LED_TYPE, DATA_PIN_DISPLAY,COLOR_ORDER>
  // (display, DISPLAY_CNT).setCorrection(TypicalLEDStrip);
  // FastLED.addLeds<LED_TYPE, DATA_PIN_BODY,COLOR_ORDER>
  // (body, S_B_BODY_END - S_B_BODY_START).setCorrection(TypicalLEDStrip);
  // FastLED.addLeds<LED_TYPE, DATA_PIN_HEAD,COLOR_ORDER>
  // (head, S_HEAD_END - S_HEAD_START).setCorrection(TypicalLEDStrip);
  // FastLED.addLeds<LED_TYPE, DATA_PIN_TORSO,COLOR_ORDER>
  // (torso, S_TORSO_END - S_TORSO_START).setCorrection(TypicalLEDStrip);
  // FastLED.addLeds<LED_TYPE, DATA_PIN_S_UMBRELLA,COLOR_ORDER>
  // (s_umbrella, S_UMBRELLA_END - S_UMBRELLA_START).setCorrection(TypicalLEDStrip);
  // FastLED.addLeds<LED_TYPE, DATA_PIN_P_UMBRELLA,COLOR_ORDER>
  // (p_umbrella, P_UMBRELLA_END - P_UMBRELLA_START).setCorrection(TypicalLEDStrip);
  // FastLED.addLeds<LED_TYPE, DATA_PIN_PENGUINS,COLOR_ORDER>
  // (penguins, PENGUINS_END - PENGUINS_START).setCorrection( 0x90FFA0 );
  FastLED.addLeds<LED_TYPE, DATA_PIN_PENGUINS,COLOR_ORDER>
  (squirrel, SQ_END - SQ_START).setCorrection( 0x90FFA0 );
  // FastLED.addLeds<LED_TYPE, DATA_PIN_PENGUINS,COLOR_ORDER>
  // (owl, OWL_END - OWL_START).setCorrection( 0x90FFA0 );


  FastLED.setBrightness(BRIGHTNESS);
  // delay(3000);
  Serial.begin(9600);
  Serial.println("booting");

  //setup default colours
    // Squirrel
  color_item(squirrel_default, SQ_START, SQ_TOOTH_ST, SQ_BODY_COLOR);
  color_item(squirrel_default, SQ_TOOTH_ST, SQ_TOOTH_ST + SQ_TOOTH_CNT, SQ_TOOTH_COLOR);
  color_item(squirrel_default, SQ_R_EYE_ST, SQ_R_EYE_ST + SQ_R_EYE_CNT + SQ_L_EYE_CNT, SQ_EYE_COLOR);
  color_item(squirrel_default, SQ_L_OUT_EYE_ST, SQ_END, SQ_BODY_COLOR);

  //first animation should be a turn on 
  // animation_select = ANIMATION_SPREADON;
  animation_select = ANIMATION_SPOTSON;
  delay(2000);

}

void loop() {
  switch(animation_select){
    case ANIMATION_ORIGINAL: 
      if (animation_select != animation_select_old){ //if just started on this animation
        animation_select_old = animation_select;
        all_default_colour(); //set all default colours (shouldnt do this each time as thats exhausting)
        animation_timer = millis(); //setup timer for how long to display this
        animation_segment_time = random(25,35);
        animation_state = ANIMATION_STATE_NEW;
      }
      animation_state = ANIMATION_STATE_RUNNING; //animation is running (not sure if useful here)
      if (animation_timer + (animation_segment_time * 1000) < millis()){ //if its been running long enough
        next_on_sequence();
      }
      //TODO rainbow sequence

      break;
    case ANIMATION_SPREADON:
      Serial.println("ANIMATION_SPREADON");
      if (animation_select != animation_select_old){//if just started on this animation
        animation_select_old = animation_select;
        all_off(); //should be all off but just check
        animation_state = ANIMATION_STATE_NEW;
        Serial.println("ANIMATION_STATE_NEW");
        break;
      }
      //if new animation setup where to start lights
      if (animation_state == ANIMATION_STATE_NEW){
        uint pos_rand = random(0,SQ_END);
        squirrel[pos_rand] = squirrel_default[pos_rand];
        
        Serial.println("STARTING_LED");
        Serial.println(pos_rand);
        delay(5000);
        animation_state = ANIMATION_STATE_RUNNING;
        Serial.println("ANIMATION_STATE_RUNNING");
        Serial.println(pos_rand);
        break;
      } //TODO this for all other parts

      memcpy(squirrel_old, squirrel, sizeof(squirrel_old));
      if (animation_state == ANIMATION_STATE_RUNNING){
        animation_state = ANIMATION_STATE_DONE;
        for(int i = 0; i < SQ_END; i++){
          // Serial.println(i);
          if (squirrel_old[i] != CRGB::Black){//if light is on then light up neighbours
            // Serial.println("lighting up neighbours");
            for (int j=0; j < 4; j++){
              if (squirrel_nodes[i][j] != 255){
                squirrel[squirrel_nodes[i][j]] = squirrel_default[squirrel_nodes[i][j]];
                // Serial.println(squirrel_nodes[i][j]);
                if (squirrel_old[squirrel_nodes[i][j]] == CRGB::Black){
                  animation_state = ANIMATION_STATE_RUNNING;//still updating display as some leds are still black
                }
              }else {break;}//255 means no more nodes so break the loop to save compute
            }
            // Serial.println("done");
          }
        }// TODO this for all other parts

        if (animation_state == ANIMATION_STATE_DONE) {//if no more LEDs lit up
          animation_timer = millis(); //setup timer for how long to display this
          animation_segment_time = random(5,15);
          Serial.println("SPREADON complete, now waiting");
          break;
        }
      }

      if (animation_state == ANIMATION_STATE_DONE){
        if (animation_timer + (animation_segment_time * 1000) < millis()){//if waited a good amount of time afterwards
          next_on_sequence();
        }
      }
      delay(300);

      break;
    case ANIMATION_SPREADOFF:
      Serial.println("ANIMATION_SPREADOFF");
      if (animation_select != animation_select_old){//if just started on this animation
        animation_select_old = animation_select;
        all_default_colour(); //should be all on but just check
        animation_state = ANIMATION_STATE_NEW;
        Serial.println("ANIMATION_STATE_NEW");
        break;
      }

      //if new animation setup where to start lights
      if (animation_state == ANIMATION_STATE_NEW){
        uint pos_rand = random(0,SQ_END);
        squirrel[pos_rand] = CRGB::Black; //turn off a single LED to start the fade out
        
        Serial.println("STARTING_LED");
        Serial.println(pos_rand);
        delay(2500); //have a little bit of black out timing
        animation_state = ANIMATION_STATE_RUNNING;
        Serial.println("ANIMATION_STATE_RUNNING");
        Serial.println(pos_rand);
        break;
      } //TODO this for all other parts


      memcpy(squirrel_old, squirrel, sizeof(squirrel_old));
      if (animation_state == ANIMATION_STATE_RUNNING){
        animation_state = ANIMATION_STATE_DONE;
        for(int i = 0; i < SQ_END; i++){
          // Serial.println(i);
          if (squirrel_old[i] == CRGB::Black){//if light is on then light up neighbours
            // Serial.println("lighting up neighbours");
            for (int j=0; j < 4; j++){
              if (squirrel_nodes[i][j] != 255){
                squirrel[squirrel_nodes[i][j]] = CRGB::Black;
                // Serial.println(squirrel_nodes[i][j]);
                if (squirrel_old[squirrel_nodes[i][j]] != CRGB::Black){
                  animation_state = ANIMATION_STATE_RUNNING;//still updating display as some leds are still not black
                }
              }else {break;}//255 means no more nodes so break the loop to save compute
            }
            // Serial.println("done");
          }
        }// TODO this for all other parts

        if (animation_state == ANIMATION_STATE_DONE) {//if no more LEDs to turn off
          animation_timer = millis(); //setup timer for how long to display this
          animation_segment_time = random(5,15);
          Serial.println("SPREADOFF complete, now waiting");
          break;
        }
        if (animation_state == ANIMATION_STATE_DONE){
          if (animation_timer + (animation_segment_time * 1000) < millis()){//if waited a good amount of time afterwards
            next_on_sequence();
          }
        }
      }
      delay(300);
      break; //end of ANIMATION_SPREADOFF
    case ANIMATION_LIGHTCHASE:
      
      // Serial.println("LIGHTCHASE");
      if (animation_select != animation_select_old){ //if just started on this animation
        animation_select_old = animation_select;
        all_default_colour(); //set all default colours (shouldnt do this each time as thats exhausting)
        animation_state = ANIMATION_STATE_RUNNING;
        //randomly select an animal/opbject to light trail
        selected_light_chase = random(0,LIGHTCHASE_RANGE); //pick something to do the light chase on
        selected_light_chase = LIGHTCHASE_SQ; //TODO remove
        switch (selected_light_chase){
          case LIGHTCHASE_SQ:
            lightchase_pos = random(0, SQ_END);
            break;
          case LIGHTCHASE_OWL:
            lightchase_pos = random(0, OWL_END);
            break;         
          case LIGHTCHASE_FOX:             
            lightchase_pos = random(0, FOX_END);
            break;
          case LIGHTCHASE_PENGUINS:
            lightchase_pos = random(0, PENGUINS_END);
            break;
        }
        lightchase_pos_old = 0;
        break; 
      }
      if (animation_state == ANIMATION_STATE_RUNNING){
        switch (selected_light_chase){
          case LIGHTCHASE_SQ:
            lightchase_pos_new = get_squirrel_neighbour_led(lightchase_pos, lightchase_pos_old);
            lightchase_pos_old_old = lightchase_pos_old;
            lightchase_pos_old = lightchase_pos;
            lightchase_pos = lightchase_pos_new;
            squirrel[lightchase_pos] = CRGB::White;
            squirrel[lightchase_pos_old] = CRGB::Gray;
            squirrel[lightchase_pos_old_old] = squirrel_default[lightchase_pos_old_old];//set back to orginal colour
            break;
          case LIGHTCHASE_OWL:
            //TODO
            break;         
          case LIGHTCHASE_FOX:             
            //TODO
            break;
          case LIGHTCHASE_PENGUINS:
            //TODO
            break;
        }        
      }
      delay(120);

      break;
    case ANIMATION_FADEOUT:
      //TODO once i know fadeoff works
      break;
    case ANIMATION_FADEIN:
      // Serial.println(fade_counter);
      if (animation_select != animation_select_old){//if just started on this animation
        Serial.println("ANIMATION_FADEIN");
        animation_select_old = animation_select;
        all_off(); //should be all on but just check
        animation_state = ANIMATION_STATE_RUNNING;
        Serial.println("ANIMATION_STATE_RUNNING");
        fade_counter = 0;
        break;
      }
      
      if (animation_state == ANIMATION_STATE_RUNNING){
        memcpy(squirrel, squirrel_default, sizeof(squirrel));
        for (int i=0; i< SQ_END; i++){
          squirrel[i].fadeLightBy(255 - fade_counter); //scale light on range of 0 to 256
        }
        fade_counter = fade_counter + 8;
        
        // Serial.println("fadecounter");
        // Serial.println(fade_counter);
        if (fade_counter > 250){// fade finishing
          animation_state = ANIMATION_STATE_DONE;
          all_default_colour(); //set to default colours
          animation_timer = millis(); //setup timer for how long to display this
          animation_segment_time = random(5,15);//TODO set appropriate value
          Serial.println("FADEON complete, now waiting");
          break;
        }
      }
      if (animation_state == ANIMATION_STATE_DONE){
        
        // Serial.println("Fadeoutdone");
        if (animation_timer + (animation_segment_time * 1000) < millis()){//if waited a good amount of time afterwards
            next_on_sequence();
        }
      }
      delay(250);
      break;
    case ANIMATION_SPOTSON: //random ones light up one by one until all have
      Serial.println("ANIMATION_SPOTSON");
      if (animation_select != animation_select_old){//if just started on this animation
        animation_select_old = animation_select;
        all_off(); //should be all on but just check
        animation_state = ANIMATION_STATE_RUNNING;
        Serial.println("ANIMATION_STATE_RUNNING");
        fade_counter = 0;
        break;
      }

      if (animation_state = ANIMATION_STATE_RUNNING){
        //check if all leds are on
        bool all_on = true;
        uint8_t black_pos[SQ_END]; //list of locations that are still black
        int index_count = 0;
        for (int i = 0; i < SQ_END; i++){
          if (squirrel[i] == CRGB::Black){
            black_pos[index_count] = i;
            index_count++;
          }
        }
        Serial.println("Index Count");
        Serial.println(index_count);

        if (index_count != 0){//some leds found to be black
          for(int i = 0; i<1; i++){//loop how many lights on per cycle
            int rnd_pos = random(0,index_count);
            squirrel[black_pos[rnd_pos]] = squirrel_default[black_pos[rnd_pos]];
          }
          all_on = false;
        } 

        if (all_on){// leds all on on every segment
          animation_state = ANIMATION_STATE_DONE;
          all_default_colour(); //set to default colours
          animation_timer = millis(); //setup timer for how long to display this
          animation_segment_time = random(5,15);//TODO set appropriate value
          Serial.println("SPOTSON complete, now waiting");
          break;
        }
      } //animation running

      if (animation_state == ANIMATION_STATE_DONE){
        if (animation_timer + (animation_segment_time * 1000) < millis()){//if waited a good amount of time afterwards
            next_on_sequence();
        }
      }
      delay(25); //dont want a long delay otherwise will take ages to colour in all 260 leds in longest chain
        //should scale this with how many are turned on per cycle
      break;
    case ANIMATION_SPOTSOFF:
      //TODO once i know spotsoff works
      break;
    case ANIMATION_NONE:
      break;
  }


  // // Snowman Body
  // int val;
  // val = analogRead(analogPin);
  // FastLED.setBrightness(60 + val/8);
  // // Serial.println(val);
  // // Serial.println(80 + val/12);
  


  // p_umbrella_rainbow_wipe(global_hue);
  // s_umbrella_rainbow_wipe(global_hue+80);
  // global_hue--;

  //// FastLED.show();
  // Serial.println("waiting for next input");
  // while (!Serial.available()){delay(100);}
  // penguin_light_pos = Serial.parseInt();
  // if (penguin_light_pos == 0) return;
  // Serial.flush();
  // Serial.println(penguin_light_pos);
  // Serial.println("connects to:");
  // uint8_t penguin_new_light_pos = get_squirrel_neighbour_led(penguin_light_pos, penguin_light_old_pos);
  // penguin_light_old_pos = penguin_light_pos;
  // penguin_light_pos = penguin_new_light_pos;
  // color_item(squirrel, SQ_START, SQ_TOOTH_ST, SQ_BODY_COLOR);
  // color_item(squirrel, SQ_TOOTH_ST, SQ_TOOTH_ST + SQ_TOOTH_CNT, SQ_TOOTH_COLOR);
  // color_item(squirrel, SQ_R_EYE_ST, SQ_R_EYE_ST + SQ_R_EYE_CNT + SQ_L_EYE_CNT, SQ_EYE_COLOR);
  // color_item(squirrel, SQ_L_OUT_EYE_ST, SQ_END, SQ_BODY_COLOR);
  // squirrel[penguin_light_pos] = CRGB::White;
  // squirrel[penguin_light_old_pos] = CRGB::Gray;
  FastLED.show();

}

