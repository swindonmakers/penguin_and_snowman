// Penguin and Snowman Selfie Point Illumination

#include <FastLED.h>
#include "p_s.h"

#define BRIGHTNESS 120

#define LED_TYPE WS2811
#define COLOR_ORDER RGB 


CRGB display[DISPLAY_CNT];
CRGB snowman[S_HEAD_END - S_B_BODY_START]; //snowman array now merged into 1
CRGB s_umbrella[S_UMBRELLA_END - S_UMBRELLA_START];
CRGB p_umbrella[P_UMBRELLA_END - P_UMBRELLA_START];
CRGB penguins[PENGUINS_END - PENGUINS_START];
CRGB squirrel[SQ_END - SQ_START];
CRGB owl[O_END - O_START];
CRGB fox[F_END - F_START];
CRGB tree[T_END - T_START];
CRGB treelight[TREELIGHT_CNT];

//default colours
CRGB squirrel_default[SQ_END - SQ_START];
CRGB owl_default[O_END - O_START];
CRGB penguins_default[PENGUINS_END - PENGUINS_START];
CRGB snowman_default[S_HEAD_END - S_B_BODY_START];
CRGB fox_default[F_END - F_START];
CRGB tree_default[T_END - T_START];
CRGB s_umbrella_default[S_UMBRELLA_END - S_UMBRELLA_START];
CRGB p_umbrella_default[P_UMBRELLA_END - P_UMBRELLA_START];

//previous led values (useful for animations)
CRGB squirrel_old[SQ_END - SQ_START];
CRGB owl_old[O_END - O_START];
CRGB penguins_old[PENGUINS_END - PENGUINS_START];
CRGB snowman_old[S_HEAD_END - S_B_BODY_START];
CRGB fox_old[F_END - F_START];
CRGB tree_old[T_END - T_START];
CRGB s_umbrella_old[S_UMBRELLA_END - S_UMBRELLA_START];
CRGB p_umbrella_old[P_UMBRELLA_END - P_UMBRELLA_START];

uint8_t global_hue = 0;
int analogPin = A14;

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
uint8_t fade_counter = 0;

int performance = 0;
int debug_loop = 0;
int stall_timer = 0;


void next_on_sequence(){ //next animation, all lights currently on
        //time to change animation
        animation_select_old = animation_select;
        int number_of_next_states = 11;
        int next_states[number_of_next_states] = {ANIMATION_SPREADOFF,ANIMATION_FADEOUT, ANIMATION_SPOTSOFF,ANIMATION_LIGHTCHASE,ANIMATION_LIGHTCHASE,ANIMATION_LIGHTCHASE,ANIMATION_ORIGINAL,ANIMATION_ORIGINAL,ANIMATION_ORIGINAL,ANIMATION_ORIGINAL,ANIMATION_ORIGINAL};  
        int next_state_loc = random(0,number_of_next_states);
        animation_select = next_states[next_state_loc];
        //if (animation_select == animation_select_old){
          animation_select_old = -1;
        //  animation_state = ANIMATION_FADEOUT;
        //}
        // animation_select = ANIMATION_FADEOUT; //TODO remove after debug
        Serial.println("GOING TO STATE");
        Serial.println(animation_select);
        stall_timer = millis(); //anti stall
}

void next_off_sequence(){
  int number_of_next_states = 3;
  int next_states[number_of_next_states] = {ANIMATION_SPREADON,ANIMATION_FADEIN,ANIMATION_SPOTSON};  
  int next_state_loc = random(0,number_of_next_states);
  animation_select = next_states[next_state_loc];
  stall_timer = millis(); //anti stall
  // animation_select = ANIMATION_FADEIN;
}

bool is_pixel_black(CRGB pix){ //because fastled doesnt have something equivalent as far as i can tell
  
  if (pix.r == 0)
    if (pix.g == 0)
      if (pix.b == 0)
        return true;
  return false;
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
  // color_item(squirrel, SQ_START, SQ_TOOTH_ST, SQ_BODY_COLOR);
  // color_item(squirrel, SQ_TOOTH_ST, SQ_TOOTH_ST + SQ_TOOTH_CNT, SQ_TOOTH_COLOR);
  // color_item(squirrel, SQ_R_EYE_ST, SQ_R_EYE_ST + SQ_R_EYE_CNT + SQ_L_EYE_CNT, SQ_EYE_COLOR);
  // color_item(squirrel, SQ_L_OUT_EYE_ST, SQ_END, SQ_BODY_COLOR);
  memcpy(squirrel, squirrel_default, sizeof(squirrel));
  memcpy(owl, owl_default, sizeof(owl));
  memcpy(penguins,penguins_default, sizeof(penguins));
  memcpy(snowman, snowman_default, sizeof(snowman));
  memcpy(fox, fox_default, sizeof(fox));
  memcpy(tree, tree_default, sizeof(tree));
  memcpy(s_umbrella, s_umbrella_default, sizeof(s_umbrella));
  memcpy(p_umbrella, p_umbrella_default, sizeof(p_umbrella));
  
  color_item(display,0 ,DISPLAY_CNT, DISPLAY_COLOR );
  // for(int i = 0; i < SQ_END; i++){
  //   squirrel[i] = squirrel_default[i];
  // }
  delay(250);
}

void all_pixel_off(){
  for(int i = 0; i < SQ_END; i++){
    squirrel[i] = CRGB::Black;
  }
  for(int i = 0; i < O_END; i++){
    owl[i] = CRGB::Black;
  }
  for(int i = 0; i < PENGUINS_END; i++){
    penguins[i] = CRGB::Black;
  }
  for(int i = 0; i < SNOWMAN_END; i++){
    snowman[i] = CRGB::Black;
  }
  for(int i = 0; i < F_END; i++){
    fox[i] = CRGB::Black;
  }
  for(int i = 0; i < T_END; i++){
    tree[i] = CRGB::Black;
  }
  for(int i = 0; i < TREELIGHT_CNT; i++){
    treelight[i] = CRGB::Black;
  }  
  for(int i = 0; i < S_UMBRELLA_END; i++){
    s_umbrella[i] = CRGB::Black;
  }
  for(int i = 0; i < P_UMBRELLA_END; i++){
    p_umbrella[i] = CRGB::Black;
  }
  
  color_item(display,0 ,DISPLAY_CNT, DISPLAY_COLOR );
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
  // uint8_t pick_size = 1;
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

uint8_t get_penguins_neighbour_led(uint8_t current_pos, uint8_t old_pos){
  uint8_t new_pos = current_pos;
  // uint8_t pick_size = 1;
  if (penguins_nodes[current_pos][1] == 255)//only one answer
    return(penguins_nodes[current_pos][0]);  
  do {
      new_pos = penguins_nodes[current_pos][random(0,4)];
    } while ((new_pos == old_pos) || (new_pos == 255));
  return new_pos;
}

uint16_t get_snowman_neighbour_led(uint16_t current_pos, uint16_t old_pos){
  uint8_t new_pos = current_pos;
  // uint8_t pick_size = 1;
  if (snowman_nodes[current_pos][1] == 1023)//only one answer
    return(snowman_nodes[current_pos][0]);  
  do {
      new_pos = snowman_nodes[current_pos][random(0,4)];
    } while ((new_pos == old_pos) || (new_pos == 1023));
  return new_pos;
}
uint8_t get_fox_neighbour_led(uint8_t current_pos, uint8_t old_pos){
  uint8_t new_pos = current_pos;
  // uint8_t pick_size = 1;
  if (fox_nodes[current_pos][1] == 255)//only one answer
    return(fox_nodes[current_pos][0]);  
  do {
      new_pos = fox_nodes[current_pos][random(0,4)];
    } while ((new_pos == old_pos) || (new_pos == 255));
  return new_pos;
}
uint16_t get_tree_neighbour_led(uint16_t current_pos, uint8_t old_pos){
  uint16_t new_pos = current_pos;
  // uint8_t pick_size = 1;
  if (tree_nodes[current_pos][1] == 1023)//only one answer
    return(tree_nodes[current_pos][0]);  
  do {
      new_pos = tree_nodes[current_pos][random(0,3)];
    } while ((new_pos == old_pos) || (new_pos == 1023));
  return new_pos;
}
void color_beak_1(CRGB section[], int start_led , CRGB color){
  section[start_led+0] = CRGB(1,  1,  1); //effectively black but not 0 to help algorithms out
  section[start_led+1] = color;
  section[start_led+2] = color;
  section[start_led+3] = color;
  section[start_led+4] = color;
  section[start_led+5] = CRGB(1,  1,  1);
  section[start_led+6] = CRGB(1,  1,  1);
}

void color_beak_2(CRGB section[], int start_led , CRGB color){
  section[start_led+0] = CRGB(1,  1,  1);
  section[start_led+1] = color;
  section[start_led+2] = color;
  section[start_led+3] = CRGB(1,  1,  1);
  section[start_led+4] = CRGB(1,  1,  1);
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
    p_umbrella_default[i + P_UMBRELLA_HANDLE_START] = hsv;
  }


  //left center rib
  for (uint8_t i = 0; i < P_UMBRELLA_L_RIB_CENTRE_CNT; i++ ){
    hsv.hue = hue + map(i, 0, P_UMBRELLA_L_RIB_CENTRE_CNT,spread*0.33, spread_mid); //last 2 digits map position from left to right of the rib
    p_umbrella_default[i + P_UMBRELLA_L_RIB_CENTRE_START] = hsv;
  }

  //right mid rib
  for (uint8_t i = 0; i < P_UMBRELLA_R_RIB_MID_CNT; i++ ){
    hsv.hue = hue + map(i, 0, P_UMBRELLA_R_RIB_MID_CNT,spread_mid, spread*0.8); //last 2 digits map position from left to right of the rib
    p_umbrella_default[i+ P_UMBRELLA_R_RIB_MID_START] = hsv;
  }
  
  //right center rib
  for (uint8_t i = 0; i < P_UMBRELLA_R_RIB_CENTRE_CNT; i++ ){
    hsv.hue = hue + map(i, 0, P_UMBRELLA_R_RIB_CENTRE_CNT,spread*.67, spread_mid); //last 2 digits map position from left to right of the rib
    p_umbrella_default[i+ P_UMBRELLA_R_RIB_CENTRE_START] = hsv;
  }

  //left mid rib
  for (uint8_t i = 0; i < P_UMBRELLA_L_RIB_MID_CNT; i++ ){
    hsv.hue = hue + map(i, 0, P_UMBRELLA_L_RIB_MID_CNT,spread_mid, spread*0.2); //last 2 digits map position from left to right of the rib
    p_umbrella_default[i+ P_UMBRELLA_L_RIB_MID_START] = hsv;
  }  

  //left outer rib
  for (uint8_t i = 0; i < P_UMBRELLA_L_RIB_OUTER_CNT; i++ ){
    hsv.hue = hue + map(i, 0, P_UMBRELLA_L_RIB_OUTER_CNT,0, spread_mid); //last 2 digits map position from left to right of the rib
    p_umbrella_default[i+ P_UMBRELLA_L_RIB_OUTER_START] = hsv;
  }    
  //right outer rib
  for (uint8_t i = 0; i < P_UMBRELLA_R_RIB_OUTER_CNT; i++ ){
    hsv.hue = hue + map(i, 0, P_UMBRELLA_R_RIB_OUTER_CNT,spread_mid, spread); //last 2 digits map position from left to right of the rib
    p_umbrella_default[i+ P_UMBRELLA_R_RIB_OUTER_START] = hsv;
  }    
  
  //right outer rib
  for (uint8_t i = 0; i < P_UMBRELLA_BTM_CANOPY_CNT; i++ ){
    hsv.hue = hue + map(i, 0, P_UMBRELLA_BTM_CANOPY_CNT,spread, 0); //last 2 digits map position from left to right of the rib
    p_umbrella_default[i+ P_UMBRELLA_BTM_CANOPY_START] = hsv;
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
    s_umbrella_default[i + S_UMBRELLA_HANDLE_START] = hsv;
  }


  //left center rib
  for (uint8_t i = 0; i < S_UMBRELLA_L_RIB_CENTRE_CNT; i++ ){
    hsv.hue = hue + map(i, 0, S_UMBRELLA_L_RIB_CENTRE_CNT,spread*0.33, spread_mid); //last 2 digits map position from left to right of the rib
    s_umbrella_default[i + S_UMBRELLA_L_RIB_CENTRE_START] = hsv;
  }

  //right mid rib
  for (uint8_t i = 0; i < S_UMBRELLA_R_RIB_MID_CNT; i++ ){
    hsv.hue = hue + map(i, 0, S_UMBRELLA_R_RIB_MID_CNT,spread_mid, spread*0.8); //last 2 digits map position from left to right of the rib
    s_umbrella_default[i+ S_UMBRELLA_R_RIB_MID_START] = hsv;
  }
  
  //right center rib
  for (uint8_t i = 0; i < S_UMBRELLA_R_RIB_CENTRE_CNT; i++ ){
    hsv.hue = hue + map(i, 0, S_UMBRELLA_R_RIB_CENTRE_CNT,spread*.67, spread_mid); //last 2 digits map position from left to right of the rib
    s_umbrella_default[i+ S_UMBRELLA_R_RIB_CENTRE_START] = hsv;
  }

  //left mid rib
  for (uint8_t i = 0; i < S_UMBRELLA_L_RIB_MID_CNT; i++ ){
    hsv.hue = hue + map(i, 0, S_UMBRELLA_L_RIB_MID_CNT,spread_mid, spread*0.2); //last 2 digits map position from left to right of the rib
    s_umbrella_default[i+ S_UMBRELLA_L_RIB_MID_START] = hsv;
  }  

  //left outer rib
  for (uint8_t i = 0; i < S_UMBRELLA_L_RIB_OUTER_CNT; i++ ){
    hsv.hue = hue + map(i, 0, S_UMBRELLA_L_RIB_OUTER_CNT,0, spread_mid); //last 2 digits map position from left to right of the rib
    s_umbrella_default[i+ S_UMBRELLA_L_RIB_OUTER_START] = hsv;
  }    
  //right outer rib
  for (uint8_t i = 0; i < S_UMBRELLA_R_RIB_OUTER_CNT; i++ ){
    hsv.hue = hue + map(i, 0, S_UMBRELLA_R_RIB_OUTER_CNT,spread_mid, spread); //last 2 digits map position from left to right of the rib
    s_umbrella_default[i+ S_UMBRELLA_R_RIB_OUTER_START] = hsv;
  }    
  
  //right outer rib
  for (uint8_t i = 0; i < S_UMBRELLA_BTM_CANOPY_CNT; i++ ){
    hsv.hue = hue + map(i, 0, S_UMBRELLA_BTM_CANOPY_CNT,spread, 0); //last 2 digits map position from left to right of the rib
    s_umbrella_default[i+ S_UMBRELLA_BTM_CANOPY_START] = hsv;
  } 
}

void update_treelights(){
  for(int i=0; i< TREELIGHT_CNT; i++){
    if (i % 3 == 0){
      int tme = (millis() /1000) % 3;
        if (tme == 0) treelight[i] = CRGB::Red;
        if (tme == 1) treelight[i] = CRGB::Green;
        if (tme == 2) treelight[i] = CRGB::Blue;
    }
    if (i % 3 == 1){
      int tme = (millis() /1000) % 3;
        if (tme == 0) treelight[i] = CRGB::Green;
        if (tme == 1) treelight[i] = CRGB::Blue;
        if (tme == 2) treelight[i] = CRGB::Red;
    }    
    if (i % 3 == 2){
      int tme = (millis() /1000) % 3;
        if (tme == 0) treelight[i] = CRGB::Blue;
        if (tme == 1) treelight[i] = CRGB::Red;
        if (tme == 2) treelight[i] = CRGB::Green;
    }
  }
}
void treelightsoff(){
  for(int i = 0; i < TREELIGHT_CNT; i++){
    treelight[i] = CRGB::Black;
  } 
}

void update_umbrellas(){
  p_umbrella_rainbow_wipe(global_hue);
  s_umbrella_rainbow_wipe(global_hue+80);
  memcpy(s_umbrella, s_umbrella_default, sizeof(s_umbrella));
  memcpy(p_umbrella, p_umbrella_default, sizeof(p_umbrella));
  global_hue++;
}

void setup() {
  delay(1000);
  FastLED.addLeds<LED_TYPE, DATA_PIN_DISPLAY,COLOR_ORDER>
  (display, DISPLAY_CNT).setCorrection(TypicalLEDStrip);

  FastLED.addLeds<LED_TYPE, DATA_PIN_S_UMBRELLA,COLOR_ORDER>
  (s_umbrella, S_UMBRELLA_END - S_UMBRELLA_START).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, DATA_PIN_P_UMBRELLA,COLOR_ORDER>
  (p_umbrella, P_UMBRELLA_END - P_UMBRELLA_START).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, DATA_PIN_PENGUINS,COLOR_ORDER>
  (penguins, PENGUINS_END - PENGUINS_START).setCorrection( 0x90FFA0 );
  FastLED.addLeds<LED_TYPE, DATA_PIN_SQUIRREL,COLOR_ORDER>
  (squirrel, SQ_END - SQ_START).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, DATA_PIN_OWL,COLOR_ORDER>
  (owl, O_END - O_START).setCorrection( 0x90FFA0 );

  FastLED.addLeds<LED_TYPE, DATA_PIN_BODY,COLOR_ORDER>
  (snowman, S_B_BODY_START, S_B_BODY_END - S_B_BODY_START ).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, DATA_PIN_HEAD,COLOR_ORDER>
  (snowman, S_HEAD_START, S_HEAD_END - S_HEAD_START).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, DATA_PIN_TORSO,COLOR_ORDER>
  (snowman, S_TORSO_START, S_TORSO_END - S_TORSO_START).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, DATA_PIN_FOX,COLOR_ORDER>
  (fox, F_END - F_START).setCorrection(0x90FFA0);
  FastLED.addLeds<LED_TYPE, DATA_PIN_TREE,COLOR_ORDER>
  (tree, T_END - T_START).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, DATA_PIN_TREELIGHT,COLOR_ORDER>
  (treelight, TREELIGHT_CNT).setCorrection(TypicalLEDStrip);
  // FastLED.setBrightness(BRIGHTNESS);
  // delay(3000);
  Serial.begin(9600);
  Serial.println("booting");

  //setup default colours
    // Squirrel
  color_item(squirrel_default, SQ_START, SQ_TOOTH_ST, SQ_BODY_COLOR);
  color_item(squirrel_default, SQ_TOOTH_ST, SQ_TOOTH_ST + SQ_TOOTH_CNT, SQ_TOOTH_COLOR);
  color_item(squirrel_default, SQ_R_EYE_ST, SQ_R_EYE_ST + SQ_R_EYE_CNT + SQ_L_EYE_CNT, SQ_EYE_COLOR);
  color_item(squirrel_default, SQ_L_OUT_EYE_ST, SQ_END, SQ_BODY_COLOR);

  color_item(owl_default, O_START, O_R_EAR_ST, O_BODY_COLOR);
  color_item(owl_default, O_R_EAR_ST, O_HEAD_TOP_ST, O_EAR_COLOR);
  color_item(owl_default, O_HEAD_TOP_ST, O_L_EAR_ST, O_BODY_COLOR);
  color_item(owl_default, O_L_EAR_ST, O_OUTER_EYE_ST, O_EAR_COLOR);
  color_item(owl_default, O_OUTER_EYE_ST, O_L_FACE_ST, O_BODY_COLOR);
  color_item(owl_default, O_L_FACE_ST, O_BEAK_ST, O_OUT_EYE_COLOR);
  color_item(owl_default, O_BEAK_ST, O_R_IN_EYE_ST, O_BEAK_COLOR);
  color_item(owl_default, O_R_IN_EYE_ST, O_EYES_ST, O_OUT_EYE_COLOR);
  color_item(owl_default, O_EYES_ST, O_L_IN_EYE_ST, O_EYE_COLOR);
  color_item(owl_default, O_L_IN_EYE_ST, O_L_WING_ST, O_OUT_EYE_COLOR);
  color_item(owl_default, O_L_WING_ST, O_END, O_BODY_COLOR);

  // // Penguin 1
  color_item(penguins_default, P_1_L_FOOT_START, P_1_L_FOOT_START + P_1_L_FOOT_CNT + P_1_R_FOOT_CNT, P_1_FOOT_COLOR);
  color_item(penguins_default, P_1_R_WING_START, P_1_R_WING_START + P_1_R_WING_CNT, P_1_WING_COLOR);
  color_item(penguins_default, P_1_B_SCARF_START, P_1_B_SCARF_START + P_1_B_SCARF_CNT + P_1_T_SCARF_CNT + P_1_R_SCARF_CNT + P_1_L_SCARF_CNT, P_1_SCARF_COLOR);
  color_item(penguins_default, P_1_BROW_START, P_1_BROW_START + P_1_BROW_CNT, P_1_BROW_COLOR);
  color_item(penguins_default, P_1_R_EYE_START, P_1_R_EYE_START + P_1_R_EYE_CNT, CRGB(30,  25,  8));
  color_beak_1(penguins_default, P_1_BEAK_START, CRGB(20,  120,  0));
  color_item(penguins_default, P_1_L_EYE_START, P_1_L_EYE_START + P_1_L_EYE_CNT, CRGB(30,  25,  8)); 
  color_item(penguins_default, P_1_L_WING_START, P_1_L_WING_START + P_1_L_WING_CNT, P_1_WING_COLOR);
  color_item(penguins_default, P_1_B_HAT_RIM_START, P_1_B_HAT_RIM_START+  P_1_B_HAT_RIM_CNT + P_1_T_HAT_RIM_CNT, P_1_HAT_COLOR);
  color_item(penguins_default, P_1_L_BODY_START, P_1_L_BODY_START + P_1_L_BODY_CNT , P_1_BODY_COLOR2);
  color_item(penguins_default, P_1_B_BODY_START, P_1_B_BODY_START + P_1_B_BODY_CNT , P_1_BODY_COLOR);
  color_item(penguins_default, P_1_R_BODY_START, P_1_R_BODY_START + P_1_R_BODY_CNT , P_1_BODY_COLOR2);
  color_item(penguins_default, P_1_T_HAT_START, P_1_T_HAT_START + P_1_T_HAT_CNT, P_1_HAT_COLOR);
  color_item(penguins_default, P_1_HAT_POM_START, P_1_HAT_POM_START + P_1_HAT_POM_CNT, P_1_HAT_POM_COLOR);
  color_item(penguins_default, P_1_B_HAT_START, P_1_B_HAT_START + P_1_B_HAT_CNT, P_1_HAT_COLOR);

  // // Penguin 2
  color_item(penguins_default, P_2_L_FOOT_START, P_2_L_FOOT_START + P_2_L_FOOT_CNT + P_2_R_FOOT_CNT, P_2_FOOT_COLOR);
  color_item(penguins_default, P_2_L_WING_START, P_2_L_WING_START + P_2_L_WING_CNT, P_2_WING_COLOR);
  color_item(penguins_default, P_2_R_WING_START, P_2_R_WING_START + P_2_R_WING_CNT, P_2_WING_COLOR);
  color_item(penguins_default, P_2_B_SCARF_START, P_2_B_SCARF_START + P_2_B_SCARF_CNT + P_2_T_SCARF_CNT + P_2_R_SCARF_CNT + P_2_L_SCARF_CNT, P_2_SCARF_COLOR);
  color_item(penguins_default, P_2_B_BODY_START, P_2_B_BODY_START + P_2_B_BODY_CNT , P_2_BODY_COLOR);
  color_item(penguins_default, P_2_T_BODY_START, P_2_T_BODY_START + P_2_T_BODY_CNT , CRGB(80,80,80)); //"white"
  color_item(penguins_default, P_2_L_EAR_START, P_2_L_EAR_START + P_2_L_EAR_CNT, P_2_EAR_COLOR);
  color_item(penguins_default, P_2_R_EAR_START, P_2_R_EAR_START + P_2_R_EAR_CNT, P_2_EAR_COLOR);
  color_item(penguins_default, P_2_BROW_START, P_2_BROW_START + P_2_BROW_CNT, P_2_BROW_COLOR);
  color_item(penguins_default, P_2_R_EYE_START, P_2_R_EYE_START + P_2_R_EYE_CNT, CRGB(30,30,0)); //yellow
  color_item(penguins_default, P_2_L_EYE_START,  P_2_L_EYE_START + P_2_L_EYE_CNT, CRGB(30,30,0)); //yellow
  color_beak_2(penguins_default, P_2_BEAK_START, CRGB(20,  120,  0));

  //snowman
  color_item(snowman_default, S_B_BODY_START, S_B_BODY_START + S_B_BODY_CNT, S_B_BODY_COLOR);
  color_item(snowman_default, S_B_BADGE_START, S_B_BADGE_START + S_B_BADGE_CNT, CRGB(40,  255,  0));
  
  // // // Snowman Head
  color_item(snowman_default, S_HEAD_START, S_HEAD_START + S_FACE_CNT, S_B_BODY_COLOR);
  color_item(snowman_default, S_HAT_RIM_START, S_HAT_RIM_START + S_HAT_RIM_CNT + S_HAT_CNT, S_HAT_COLOR);
  color_item(snowman_default, S_MOUTH_START, S_MOUTH_START + S_FACE_CNT, S_MOUTH_COLOR);
  color_item(snowman_default, S_L_EYE_START, S_L_EYE_START + S_L_EYE_CNT + S_R_EYE_CNT, CRGB(20,0,0));
  color_item(snowman_default, S_NOSE_START, S_NOSE_START + S_NOSE_CNT, S_NOSE_COLOR);

  // // Snowman Torso

  color_item(snowman_default, S_TORSO_START, S_TORSO_START + S_R_OUTTER_ARM_CNT,  S_B_BODY_COLOR);
  color_item(snowman_default, S_R_HAND_START, S_R_HAND_START + S_R_HAND_CNT,  CRGB::Green);
  color_item(snowman_default, S_R_INNER_ARM_START, S_R_INNER_ARM_START + S_R_INNER_ARM_CNT,  S_B_BODY_COLOR);
  color_item(snowman_default, S_M_BODY_START, S_M_BODY_START + S_M_BODY_CNT,  S_B_BODY_COLOR);
  color_item(snowman_default, S_T_SCARF_START, S_T_SCARF_START + S_T_SCARF_CNT + S_B_SCARF_CNT + S_L_SCARF_CNT + S_R_SCARF_CNT, S_SCARF_COLOR);
  color_item(snowman_default, S_L_T_ARM_START, S_L_T_ARM_START + S_L_T_ARM_CNT + S_L_HAND_CNT + S_L_B_ARM_CNT,  S_B_BODY_COLOR);
  color_item(snowman_default, S_L_HAND_START, S_L_HAND_START + S_L_HAND_CNT,  CRGB::Green);
  color_item(snowman_default, S_L_B_ARM_START, S_L_B_ARM_START + S_L_B_ARM_CNT,  S_B_BODY_COLOR);

  //Fox
  color_item(fox_default, F_START, F_START + F_TAIL_TIP_CNT, F_TAIL_COLOR);
  color_item(fox_default, F_TAIL_MAIN_ST, F_TAIL_MAIN_ST + F_TAIL_MAIN_CNT + F_REAR_LEG_CNT + F_MID_LEG_CNT + F_MID_BODY_CNT, F_BODY_COLOR);
  color_item(fox_default, F_LEFT_MASK_ST, F_LEFT_MASK_ST + F_LEFT_MASK_CNT + F_RIGHT_MASK_CNT + F_LOWER_FACE_CNT, F_MASK_COLOR);
  color_item(fox_default, F_L_HEAD_ST, F_L_HEAD_ST + F_L_HEAD_CNT + F_R_HEAD_CNT, F_BODY_COLOR);
  color_item(fox_default, F_R_EYE_ST, F_R_EYE_ST + F_R_EYE_CNT + F_L_EYE_CNT, F_EYES_COLOR);
  color_item(fox_default, F_L_EAR_ST, F_END, F_BODY_COLOR);

  //tree
  color_item(tree_default, T_START, T_END, T_COLOR);
 
  //umbrellas
  update_umbrellas();

  //display
  color_item(display,0 ,DISPLAY_CNT, DISPLAY_COLOR );
  // color_item(display_default,0 ,DISPLAY_CNT, DISPLAY_COLOR );
  // Serial.println("TORSO_START");
  // Serial.println(S_TORSO_START);
  //first animation should be a turn on 
  // animation_select = ANIMATION_SPREADON;
  animation_select = ANIMATION_SPOTSON;
  //all_default_colour();
  //FastLED.show();
  delay(2000);
  stall_timer = millis();

}

void loop() {

  int val;
  val = analogRead(analogPin);
  FastLED.setBrightness(40 + val/4);
  switch(animation_select){
    case ANIMATION_ORIGINAL: 
      if (animation_select != animation_select_old){ //if just started on this animation
        animation_select_old = animation_select;
        all_default_colour(); //set all default colours (shouldnt do this each time as thats exhausting)
        animation_timer = millis(); //setup timer for how long to display this
        animation_segment_time = random(25,35);
        animation_state = ANIMATION_STATE_NEW;
        Serial.println("OG");
      }
      
      update_umbrellas();
      update_treelights();
      delay(100);
      animation_state = ANIMATION_STATE_RUNNING; //animation is running (not sure if useful here)
      if (animation_timer + (animation_segment_time * 1000) < millis()){ //if its been running long enough
        next_on_sequence();
      }

      break;
    case ANIMATION_SPREADON:
      if (animation_select != animation_select_old){//if just started on this animation
        animation_select_old = animation_select;
        all_pixel_off(); //should be all off but just check
        animation_state = ANIMATION_STATE_NEW;
        Serial.println("ANIMATION_STATE_NEW");
        Serial.println("ANIMATION_SPREADON");
        break;
      }
      //if new animation setup where to start lights
      if (animation_state == ANIMATION_STATE_NEW){

        //squirrel
        uint pos_rand = random(0,SQ_END);
        squirrel[pos_rand] = squirrel_default[pos_rand];
        //owl
        pos_rand = random(0,O_END);
        owl[pos_rand] = owl_default[pos_rand];
        //penguins
        pos_rand = random(0,PENGUINS_END);
        penguins[pos_rand] = penguins_default[pos_rand];
        //snowman
        pos_rand = random(0,SNOWMAN_END);
        snowman[pos_rand] = snowman_default[pos_rand];
        //fox
        pos_rand = random(0,F_END);
        fox[pos_rand] = fox_default[pos_rand];
        //tree
        pos_rand = random(0,T_END/2);
        tree[pos_rand] = tree_default[pos_rand];       
        pos_rand = random(T_END/2,T_END); //two in tree as its so big
        tree[pos_rand] = tree_default[pos_rand];

        pos_rand = random(0, S_UMBRELLA_END);
        s_umbrella[pos_rand] = s_umbrella_default[pos_rand];
        pos_rand = random(0, P_UMBRELLA_END);
        p_umbrella[pos_rand] = p_umbrella_default[pos_rand];
        Serial.println("STARTING_LED");

        // Serial.println(pos_rand);
        delay(250);
        animation_state = ANIMATION_STATE_RUNNING;
        Serial.println("ANIMATION_STATE_RUNNING");
        break;
      } 

      memcpy(squirrel_old, squirrel, sizeof(squirrel_old));
      memcpy(owl_old, owl, sizeof(owl_old));
      memcpy(penguins_old, penguins, sizeof(penguins_old));
      memcpy(snowman_old, snowman, sizeof(snowman_old));
      memcpy(fox_old, fox, sizeof(fox));
      memcpy(tree_old, tree, sizeof(tree));
      memcpy(s_umbrella_old, s_umbrella, sizeof(s_umbrella_old));
      memcpy(p_umbrella_old, p_umbrella, sizeof(p_umbrella_old));
      if (animation_state == ANIMATION_STATE_RUNNING){
        animation_state = ANIMATION_STATE_DONE;

        //squirrel
        for(int i = 0; i < SQ_END; i++){
          // Serial.println(i);
          if (!is_pixel_black(squirrel_old[i])){//if light is on then light up neighbours
            // Serial.println("lighting up neighbours");
            for (int j=0; j < 4; j++){
              if (squirrel_nodes[i][j] != 255){
                squirrel[squirrel_nodes[i][j]] = squirrel_default[squirrel_nodes[i][j]];
                // Serial.println(squirrel_nodes[i][j]);
                if (squirrel_old[squirrel_nodes[i][j]] == CRGB::Black){
                  animation_state = ANIMATION_STATE_RUNNING;//still updating display as some leds are still black
                  // if (debug_loop > 100){
                  //   Serial.println("s");
                  //   Serial.println(squirrel_nodes[i][j]);
                  // }
                }
              }//else {break;}//255 means no more nodes so break the loop to save compute
            }
            // Serial.println("done");
          }
        }
        //owl
        for(int i = 0; i < O_END; i++){
          // Serial.println(i);
          if (!is_pixel_black(owl_old[i])){//if light is on then light up neighbours
            // Serial.println("lighting up neighbours");
            for (int j=0; j < 4; j++){
              if (owl_nodes[i][j] != 255){
                owl[owl_nodes[i][j]] = owl_default[owl_nodes[i][j]];
                // Serial.println(squirrel_nodes[i][j]);
                if (owl_old[owl_nodes[i][j]] == CRGB::Black){
                  animation_state = ANIMATION_STATE_RUNNING;//still updating display as some leds are still black
                  // if (debug_loop > 100){
                  //   Serial.println("o");
                  //   Serial.println(owl_nodes[i][j]);}
                }
              }//else {break;}//255 means no more nodes so break the loop to save compute
            }
            // Serial.println("done");
          }
        }
        //penguins
        for(int i = 0; i < PENGUINS_END; i++){
          // Serial.println(i);
          if (!is_pixel_black(penguins_old[i])){//if light is on then light up neighbours
            // Serial.println("lighting up neighbours");
            for (int j=0; j < 4; j++){
              if (penguins_nodes[i][j] != 255){
                penguins[penguins_nodes[i][j]] = penguins_default[penguins_nodes[i][j]];
                // Serial.println(penguins_nodes[i][j]);
                if (penguins_old[penguins_nodes[i][j]] == CRGB::Black){
                  animation_state = ANIMATION_STATE_RUNNING;//still updating display as some leds are still black
                  // if (debug_loop > 100){
                  //   Serial.println("p");
                  //   Serial.println(penguins_nodes[i][j]);}

                }
              }//else {break;}//255 means no more nodes so break the loop to save compute
            }
            // Serial.println("done");
          }
        }
        //snowman
        for(int i = 0; i < SNOWMAN_END; i++){
          // Serial.println(i);
          if (!is_pixel_black(snowman_old[i])){//if light is on then light up neighbours
            // Serial.println("lighting up neighbours");
            for (int j=0; j < 4; j++){
              if (snowman_nodes[i][j] != 1023){
                snowman[snowman_nodes[i][j]] = snowman_default[snowman_nodes[i][j]];
                // Serial.println(penguins_nodes[i][j]);
                if (snowman_old[snowman_nodes[i][j]] == CRGB::Black){
                  animation_state = ANIMATION_STATE_RUNNING;//still updating display as some leds are still black
                  
                  // if (debug_loop > 100){
                  //   Serial.println("s");
                  //   Serial.println(snowman_nodes[i][j]);
                  // }
                }
              }else {break;}//255 means no more nodes so break the loop to save compute
            }
            // Serial.println("done");
          }
        }
        //fox
        for(int i = 0; i < F_END; i++){
          // Serial.println(i);
          if (!is_pixel_black(fox_old[i])){//if light is on then light up neighbours
            // Serial.println("lighting up neighbours");
            for (int j=0; j < 4; j++){
              if (fox_nodes[i][j] != 255){
                fox[fox_nodes[i][j]] = fox_default[fox_nodes[i][j]];
                // Serial.println(penguins_nodes[i][j]);
                if (fox_old[fox_nodes[i][j]] == CRGB::Black){
                  animation_state = ANIMATION_STATE_RUNNING;//still updating display as some leds are still black
                  
                  // if (debug_loop > 100)
                  //   Serial.println(fox_nodes[i][j]);
                }
              }//else {break;}//255 means no more nodes so break the loop to save compute
            }
            // Serial.println("done");
          }
        }    

        //tree
        for(int i = 0; i < T_END; i++){
          // Serial.println(i);
          if (!is_pixel_black(tree_old[i])){//if light is on then light up neighbours
            // Serial.println("lighting up neighbours");
            for (int j=0; j < 3; j++){
              if (tree_nodes[i][j] != 1023){
                tree[tree_nodes[i][j]] = tree_default[tree_nodes[i][j]];
                // Serial.println(penguins_nodes[i][j]);
                if (tree_old[tree_nodes[i][j]] == CRGB::Black){
                  animation_state = ANIMATION_STATE_RUNNING;//still updating display as some leds are still black
                  
                  // if (debug_loop > 100){
                  //   Serial.println("s");
                  //   Serial.println(tree_nodes[i][j]);
                  // }
                }
              }//else {break;}//255 means no more nodes so break the loop to save compute
            }
            // Serial.println("done");
          }
        }
        //p_umbrella
        for(int i = 0; i < P_UMBRELLA_END; i++){
          // Serial.println(i);
          if (!is_pixel_black(p_umbrella_old[i])){//if light is on then light up neighbours
            // Serial.println("lighting up neighbours");
            for (int j=0; j < 4; j++){
              if (penguin_umbrella_nodes[i][j] != 255){
                p_umbrella [penguin_umbrella_nodes[i][j]] = p_umbrella_default[penguin_umbrella_nodes[i][j]];
                // Serial.println(penguin_umbrella_nodes[i][j]);
                if (p_umbrella_old[penguin_umbrella_nodes[i][j]] == CRGB::Black){
                  animation_state = ANIMATION_STATE_RUNNING;//still updating display as some leds are still black
                  // if (debug_loop > 100){
                  //   Serial.println("s");
                  //   Serial.println(penguin_umbrella_nodes[i][j]);
                  // }
                }
              }else {break;}//255 means no more nodes so break the loop to save compute
            }
            // Serial.println("done");
          }
        }
        //p_umbrella
        for(int i = 0; i < S_UMBRELLA_END; i++){
          // Serial.println(i);
          if (!is_pixel_black(s_umbrella_old[i])){//if light is on then light up neighbours
            // Serial.println("lighting up neighbours");
            for (int j=0; j < 4; j++){
              if (snowman_umbrella_nodes[i][j] != 255){
                s_umbrella[snowman_umbrella_nodes[i][j]] = s_umbrella_default[snowman_umbrella_nodes[i][j]];
                // Serial.println(snowman_umbrella_nodes[i][j]);
                if (s_umbrella_old[snowman_umbrella_nodes[i][j]] == CRGB::Black){
                  animation_state = ANIMATION_STATE_RUNNING;//still updating display as some leds are still black
                  // if (debug_loop > 100){
                  //   Serial.println("s");
                  //   Serial.println(snowman_umbrella_nodes[i][j]);
                  // }
                }
              }//else {break;}//255 means no more nodes so break the loop to save compute
            }
            // Serial.println("done");
          }
        }
        // debug_loop++;
        // if (debug_loop > 100){
          
        //   Serial.println("snowmancheck");  
        //   for(int i=0; i<SNOWMAN_END; i++)
        //     if(snowman_old[i] == CRGB::Black)
        //       Serial.println(i);  
        //   Serial.println("owlcheck");  
        //   for(int i=0; i<O_END; i++)
        //     if(owl_old[i] == CRGB::Black)
        //       Serial.println(i);  
        //   Serial.println("pencheck");  
        //   for(int i=0; i<PENGUINS_END; i++)
        //     if(penguins_old[i] == CRGB::Black)
        //       Serial.println(i);  
        //   Serial.println("sqcheck");  
        //   for(int i=0; i<SQ_END; i++)
        //     if(squirrel_old[i] == CRGB::Black)
        //       Serial.println(i);  
        // }
        
        if (animation_state == ANIMATION_STATE_DONE) {//if no more LEDs lit up
          animation_timer = millis(); //setup timer for how long to display this
          animation_segment_time = random(5,15);
          Serial.println("SPREADON complete, now waiting");
          break;
        }
      }

      if (animation_state == ANIMATION_STATE_DONE){
        update_umbrellas();
        update_treelights();
        if (animation_timer + (animation_segment_time * 1000) < millis()){//if waited a good amount of time afterwards
          next_on_sequence();
        }
      }
      delay(250);

      break;
    case ANIMATION_SPREADOFF:
      if (animation_select != animation_select_old){//if just started on this animation
        animation_select_old = animation_select;
        all_default_colour(); //should be all on but just check
        treelightsoff(); //tree lights arent a part of this
        animation_state = ANIMATION_STATE_NEW;
        Serial.println("ANIMATION_STATE_NEW");
        Serial.println("ANIMATION_SPREADOFF");
        break;
      }

      //if new animation setup where to start lights
      if (animation_state == ANIMATION_STATE_NEW){
        debug_loop = 0;
        uint pos_rand = random(0,SQ_END);
        squirrel[pos_rand] = CRGB::Black; //turn off a single LED to start the fade out
        pos_rand = random(0,O_END);
        owl[pos_rand] = CRGB::Black; //turn off a single LED to start the fade out
        pos_rand = random(0,PENGUINS_END);
        penguins[pos_rand] = CRGB::Black; //turn off a single LED to start the fade out
        pos_rand = random(0,SNOWMAN_END);
        snowman[pos_rand] = CRGB::Black; //turn off a single LED to start the fade out
        pos_rand = random(0,F_END);
        fox[pos_rand] = CRGB::Black; //turn off a single LED to start the fade out
        pos_rand = random(0,T_END/2);
        tree[pos_rand] = CRGB::Black; //turn off a single LED to start the fade out        
        pos_rand = random(T_END/2,T_END); //tree twice to as so big to get rid of all of it
        tree[pos_rand] = CRGB::Black; //turn off a single LED to start the fade out
        pos_rand = random(0, S_UMBRELLA_END);
        s_umbrella[pos_rand] = CRGB::Black;
        pos_rand = random(0, P_UMBRELLA_END);
        p_umbrella[pos_rand] = CRGB::Black;
        Serial.println("STARTING_LED");
        Serial.println(pos_rand);
        delay(2500); //have a little bit of black out timing
        animation_state = ANIMATION_STATE_RUNNING;
        Serial.println("ANIMATION_STATE_RUNNING");
        Serial.println(pos_rand);
        break;
      } 


      memcpy(squirrel_old, squirrel, sizeof(squirrel_old));
      memcpy(owl_old, owl, sizeof(owl_old));
      memcpy(penguins_old, penguins, sizeof(penguins_old));
      memcpy(snowman_old, snowman, sizeof(snowman_old));
      memcpy(fox_old, fox, sizeof(fox_old));
      memcpy(tree_old, tree, sizeof(tree));
      memcpy(s_umbrella_old, s_umbrella, sizeof(s_umbrella_old));
      memcpy(p_umbrella_old, p_umbrella, sizeof(p_umbrella_old));
      
      if (animation_state == ANIMATION_STATE_RUNNING){
        animation_state = ANIMATION_STATE_DONE;
        //squirrel
        for(int i = 0; i < SQ_END; i++){
          // Serial.println(i);
          if (squirrel_old[i] == CRGB::Black){//if light is on then light up neighbours
            // Serial.println("lighting up neighbours");
            for (int j=0; j < 4; j++){
              if (squirrel_nodes[i][j] != 255){
                if (!is_pixel_black( squirrel_old[squirrel_nodes[i][j]])){
                  animation_state = ANIMATION_STATE_RUNNING;//still updating display as some leds are still not black
                  squirrel[squirrel_nodes[i][j]] = CRGB::Black;
                }
              }else {break;}//255 means no more nodes so break the loop to save compute
            }
            // Serial.println("done");
          }
        }
        //owl
        for(int i = 0; i < O_END; i++){
          // Serial.println(i);
          if (owl_old[i] == CRGB::Black){//if light is on then light up neighbours
            // Serial.println("lighting up neighbours");
            for (int j=0; j < 4; j++){
              if (owl_nodes[i][j] != 255){
                if (!is_pixel_black( owl_old[owl_nodes[i][j]])){
                  animation_state = ANIMATION_STATE_RUNNING;//still updating display as some leds are still not black
                  owl[owl_nodes[i][j]] = CRGB::Black;
                }
              }else {break;}//255 means no more nodes so break the loop to save compute
            }
            // Serial.println("done");
          }
        }
        //penguins
        for(int i = 0; i < PENGUINS_END; i++){
          // Serial.println(i);
          if (penguins_old[i] == CRGB::Black){//if light is on then light up neighbours
            // Serial.println("lighting up neighbours");
            for (int j=0; j < 4; j++){
              if (penguins_nodes[i][j] != 255){
                if (!is_pixel_black( penguins_old[penguins_nodes[i][j]])){
                  animation_state = ANIMATION_STATE_RUNNING;//still updating display as some leds are still not black
                  penguins[penguins_nodes[i][j]] = CRGB::Black;
                }
              }else {break;}//255 means no more nodes so break the loop to save compute
            }
            // Serial.println("done");
          }
        }
        //snowman
        for(int i = 0; i < SNOWMAN_END; i++){
          // Serial.println(i);
          if (snowman_old[i] == CRGB::Black){//if light is on then light up neighbours
            // Serial.println("lighting up neighbours");
            for (int j=0; j < 4; j++){
              if (snowman_nodes[i][j] != 1023){
                if (!is_pixel_black( snowman_old[snowman_nodes[i][j]])){
                  animation_state = ANIMATION_STATE_RUNNING;//still updating display as some leds are still not black
                  snowman[snowman_nodes[i][j]] = CRGB::Black;
                }
              }else {break;}//255 means no more nodes so break the loop to save compute
            }
            // Serial.println("done");
          }
        }
        //fox
        for(int i = 0; i < F_END; i++){
          // Serial.println(i);
          if (fox_old[i] == CRGB::Black){//if light is on then light up neighbours
            // Serial.println("lighting up neighbours");
            for (int j=0; j < 4; j++){
              if (fox_nodes[i][j] != 255){
                if (!is_pixel_black( fox_old[fox_nodes[i][j]])){
                  animation_state = ANIMATION_STATE_RUNNING;//still updating display as some leds are still not black
                  fox[fox_nodes[i][j]] = CRGB::Black;
                }
              }else {break;}//255 means no more nodes so break the loop to save compute
            }
            // Serial.println("done");
          }
        }
        //tree
        for(int i = 0; i < T_END; i++){
          // Serial.println(i);
          if (tree_old[i] == CRGB::Black){//if light is on then light up neighbours
            // Serial.println("lighting up neighbours");
            for (int j=0; j < 3; j++){
              if (tree_nodes[i][j] != 1023){
                if (!is_pixel_black( tree_old[tree_nodes[i][j]])){
                  animation_state = ANIMATION_STATE_RUNNING;//still updating display as some leds are still not black
                  tree[tree_nodes[i][j]] = CRGB::Black;
                }
              }else {break;}//255 means no more nodes so break the loop to save compute
            }
            // Serial.println("done");
          }
        }
        //p_umbrella
        for(int i = 0; i < P_UMBRELLA_END; i++){
          // Serial.println(i);
          if (p_umbrella_old[i] == CRGB::Black){//if light is on then light up neighbours
            // Serial.println("lighting up neighbours");
            for (int j=0; j < 4; j++){
              if (penguin_umbrella_nodes[i][j] != 255){
                if (!is_pixel_black( p_umbrella_old[penguin_umbrella_nodes[i][j]])){
                  animation_state = ANIMATION_STATE_RUNNING;//still updating display as some leds are still not black
                  p_umbrella[penguin_umbrella_nodes[i][j]] = CRGB::Black;
                }
              }else {break;}//255 means no more nodes so break the loop to save compute
            }
            // Serial.println("done");
          }
        }     
        //s_umbrella
        for(int i = 0; i < S_UMBRELLA_END; i++){
          // Serial.println(i);
          if (s_umbrella_old[i] == CRGB::Black){//if light is on then light up neighbours
            // Serial.println("lighting up neighbours");
            for (int j=0; j < 4; j++){
              if (snowman_umbrella_nodes[i][j] != 255){
                if (!is_pixel_black( s_umbrella_old[snowman_umbrella_nodes[i][j]])){
                  animation_state = ANIMATION_STATE_RUNNING;//still updating display as some leds are still not black
                  s_umbrella[snowman_umbrella_nodes[i][j]] = CRGB::Black;
                }
              }else {break;}//255 means no more nodes so break the loop to save compute
            }
            // Serial.println("done");
          }
        } 
        debug_loop++;
        
        if (animation_state == ANIMATION_STATE_DONE) {//if no more LEDs to turn off
          animation_timer = millis(); //setup timer for how long to display this
          animation_segment_time = random(3,5);
          Serial.println("SPREADOFF complete, now waiting");
          break;
        }
      }

      if (animation_state == ANIMATION_STATE_DONE){
        if (animation_timer + (animation_segment_time * 1000) < millis()){//if waited a good amount of time afterwards
          next_off_sequence();
        }
      }
      delay(250);
      break; //end of ANIMATION_SPREADOFF
    case ANIMATION_LIGHTCHASE:
      
      // Serial.println("LIGHTCHASE");
      if (animation_select != animation_select_old){ //if just started on this animation
        animation_select_old = animation_select;
        all_default_colour(); //set all default colours (shouldnt do this each time as thats exhausting)
        animation_state = ANIMATION_STATE_RUNNING;
        //randomly select an animal/opbject to light trail
        selected_light_chase = random(0,LIGHTCHASE_RANGE); //pick something to do the light chase on
        // selected_light_chase = LIGHTCHASE_FOX; //TODO remove
        Serial.println("ANIMATION_LIGHTCHASE");
        animation_segment_time = random(25,35);
        switch (selected_light_chase){
          case LIGHTCHASE_SQ:
            lightchase_pos = random(0, SQ_END);
            break;
          case LIGHTCHASE_OWL:
            lightchase_pos = random(0, O_END);
            break;         
          case LIGHTCHASE_FOX:             
            lightchase_pos = random(0, F_END);
            break;
          case LIGHTCHASE_PENGUINS:
            lightchase_pos = random(0, PENGUINS_END);
          case LIGHTCHASE_SNOWMAN:
            lightchase_pos = random(0, SNOWMAN_END);
            break;
        }
        lightchase_pos_old = 0;
        break; 
      }
      update_umbrellas();
      update_treelights();
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
            lightchase_pos_new = get_owl_neighbour_led(lightchase_pos, lightchase_pos_old);
            lightchase_pos_old_old = lightchase_pos_old;
            lightchase_pos_old = lightchase_pos;
            lightchase_pos = lightchase_pos_new;
            owl[lightchase_pos] = CRGB::White;
            owl[lightchase_pos_old] = CRGB::Gray;
            owl[lightchase_pos_old_old] = owl_default[lightchase_pos_old_old];//set back to orginal colour            
            break;         
          case LIGHTCHASE_FOX:             
            lightchase_pos_new = get_fox_neighbour_led(lightchase_pos, lightchase_pos_old);
            lightchase_pos_old_old = lightchase_pos_old;
            lightchase_pos_old = lightchase_pos;
            lightchase_pos = lightchase_pos_new;
            fox[lightchase_pos] = CRGB::White;
            fox[lightchase_pos_old] = CRGB::Gray;
            fox[lightchase_pos_old_old] = fox_default[lightchase_pos_old_old];//set back to orginal colour     
            break;
          case LIGHTCHASE_PENGUINS:
            lightchase_pos_new = get_penguins_neighbour_led(lightchase_pos, lightchase_pos_old);
            lightchase_pos_old_old = lightchase_pos_old;
            lightchase_pos_old = lightchase_pos;
            lightchase_pos = lightchase_pos_new;
            penguins[lightchase_pos] = CRGB::White;
            penguins[lightchase_pos_old] = CRGB::Gray;
            penguins[lightchase_pos_old_old] = penguins_default[lightchase_pos_old_old];//set back to orginal colour                
            break;
          case LIGHTCHASE_SNOWMAN:
            lightchase_pos_new = get_snowman_neighbour_led(lightchase_pos, lightchase_pos_old);
            lightchase_pos_old_old = lightchase_pos_old;
            lightchase_pos_old = lightchase_pos;
            lightchase_pos = lightchase_pos_new;
            snowman[lightchase_pos] = CRGB::White;
            snowman[lightchase_pos_old] = CRGB::Gray;
            snowman[lightchase_pos_old_old] = snowman_default[lightchase_pos_old_old];//set back to orginal colour                
            break;            
        }  
      
        if (animation_timer + (animation_segment_time * 1000) < millis()){//if waited a good amount of time afterwards
          next_on_sequence();
        }
              
      }
      delay(20);//due to ther bits of code the actual delay is way longer

      break;
    case ANIMATION_FADEOUT:
      // Serial.println(fade_counter);
      if (animation_select != animation_select_old){//if just started on this animation
        Serial.println("ANIMATION_FADEOUT");
        animation_select_old = animation_select;
        all_default_colour(); //should be all on but just check
        animation_state = ANIMATION_STATE_RUNNING;
        Serial.println("ANIMATION_STATE_RUNNING");
        fade_counter = 0;
        break;
      }
      
      if (animation_state == ANIMATION_STATE_RUNNING){
        all_default_colour();
        update_umbrellas();
        update_treelights();
        for (int i=0; i< SQ_END; i++){
          squirrel[i].fadeLightBy(fade_counter); //scale light on range of 0 to 256
        }
        for (int i=0; i< O_END; i++){
          owl[i].fadeLightBy(fade_counter); //scale light on range of 0 to 256
        }
        for (int i=0; i< PENGUINS_END; i++){
          penguins[i].fadeLightBy(fade_counter); //scale light on range of 0 to 256
        }
        for (int i=0; i< SNOWMAN_END; i++){
          snowman[i].fadeLightBy(fade_counter); //scale light on range of 0 to 256
        }
        for (int i=0; i< F_END; i++){
          fox[i].fadeLightBy(fade_counter); //scale light on range of 0 to 256
        }
        for (int i=0; i< T_END; i++){
          tree[i].fadeLightBy(fade_counter); //scale light on range of 0 to 256
        }
        for (int i=0; i< S_UMBRELLA_END; i++){
          s_umbrella[i].fadeLightBy(fade_counter); //scale light on range of 0 to 256
        }
        for (int i=0; i< P_UMBRELLA_END; i++){
          p_umbrella[i].fadeLightBy(fade_counter); //scale light on range of 0 to 256
        }
        for (int i=0; i< TREELIGHT_CNT; i++){
          treelight[i].fadeLightBy(fade_counter); //scale light on range of 0 to 256
        }        
        fade_counter = fade_counter + 8;
      
        if (fade_counter > 245){// fade finishing
          animation_state = ANIMATION_STATE_DONE;
          all_pixel_off(); //set to default colours
          animation_timer = millis(); //setup timer for how long to display this
          animation_segment_time = random(2,4);
          Serial.println("FADEOUT complete, now waiting");
          break;
        }
      }
      if (animation_state == ANIMATION_STATE_DONE){
        // update_umbrellas();
        // Serial.println("Fadeoutdone");
        if (animation_timer + (animation_segment_time * 1000) < millis()){//if waited a good amount of time afterwards
            next_off_sequence();
        }
      }
      delay(250);   
      break;
    case ANIMATION_FADEIN:
      // Serial.println(fade_counter);
      if (animation_select != animation_select_old){//if just started on this animation
        Serial.println("ANIMATION_FADEIN");
        animation_select_old = animation_select;
        all_pixel_off(); //should be all on but just check
        animation_state = ANIMATION_STATE_RUNNING;
        Serial.println("ANIMATION_STATE_RUNNING");
        fade_counter = 7;
        break;
      }

      if (animation_state == ANIMATION_STATE_RUNNING){
        all_default_colour();
        
        update_umbrellas();
        update_treelights();
        //squirrel
        for (int i=0; i< SQ_END; i++){
          squirrel[i].fadeLightBy(255 - fade_counter); //scale light on range of 0 to 256
        }
        for (int i=0; i< O_END; i++){
          owl[i].fadeLightBy(255 - fade_counter); //scale light on range of 0 to 256
        }
        for (int i=0; i< PENGUINS_END; i++){
          penguins[i].fadeLightBy(255 - fade_counter); //scale light on range of 0 to 256
        }
        for (int i=0; i< SNOWMAN_END; i++){
          snowman[i].fadeLightBy(255 - fade_counter); //scale light on range of 0 to 256
        }
        for (int i=0; i< F_END; i++){
          fox[i].fadeLightBy(255 - fade_counter); //scale light on range of 0 to 256
        }        
        for (int i=0; i< T_END; i++){
          tree[i].fadeLightBy(255 - fade_counter); //scale light on range of 0 to 256
        }
        for (int i=0; i< P_UMBRELLA_END; i++){
          p_umbrella[i].fadeLightBy(255 - fade_counter); //scale light on range of 0 to 256
        }
        for (int i=0; i< S_UMBRELLA_END; i++){
          s_umbrella[i].fadeLightBy(255 - fade_counter); //scale light on range of 0 to 256
        }
        for (int i=0; i< TREELIGHT_CNT; i++){
          treelight[i].fadeLightBy(255 - fade_counter); //scale light on range of 0 to 256
        }
        fade_counter = fade_counter + 8;
        
        // Serial.println("fadecounter");
        // Serial.println(fade_counter);
        if (fade_counter > 250){// fade finishing
          animation_state = ANIMATION_STATE_DONE;
          all_default_colour(); //set to default colours
          update_umbrellas();
          animation_timer = millis(); //setup timer for how long to display this
          animation_segment_time = random(5,15);//TODO set appropriate value
          Serial.println("FADEON complete, now waiting");
          break;
        }
      }
      if (animation_state == ANIMATION_STATE_DONE){
        update_umbrellas();
        // Serial.println("Fadeoutdone");
        if (animation_timer + (animation_segment_time * 1000) < millis()){//if waited a good amount of time afterwards
            next_on_sequence();
        }
      }
      delay(250);
      break;
    case ANIMATION_SPOTSON: 
      //random ones light up one by one until all have
      // Serial.println("ANIMATION_SPOTSON");
      if (animation_select != animation_select_old){//if just started on this animation
        animation_select_old = animation_select;
        all_pixel_off(); //should be all on but just check
        treelightsoff();
        animation_state = ANIMATION_STATE_RUNNING;
        Serial.println("ANIMATION_STATE_RUNNING");
        Serial.println("ANIMATION_SPOTSON");
        break;
      }

      if (animation_state == ANIMATION_STATE_RUNNING){
        //check if all leds are on
        bool all_on = true;
        uint8_t sq_black_pos[SQ_END]; //list of locations that are still black
        uint8_t o_black_pos[O_END]; //list of locations that are still black
        uint8_t p_black_pos[PENGUINS_END];
        uint16_t s_black_pos[SNOWMAN_END];
        uint8_t f_black_pos[F_END];
        uint16_t t_black_pos[T_END];
        uint8_t p_u_black_pos[P_UMBRELLA_END];
        uint8_t s_u_black_pos[S_UMBRELLA_END];

        int index_count = 0;

        //squirrel
        for (int i = 0; i < SQ_END; i++){
          if (squirrel[i] == CRGB::Black){
            sq_black_pos[index_count] = i;
            index_count++;
          }
        }
        if (index_count != 0){//some leds found to be black
          for(int i = 0; i<1; i++){//loop how many lights on per cycle
            int rnd_pos = random(0,index_count);
            squirrel[sq_black_pos[rnd_pos]] = squirrel_default[sq_black_pos[rnd_pos]];
          }
          all_on = false;
        } 

        //owl
        index_count = 0;
        for (int i = 0; i < O_END; i++){
          if (owl[i] == CRGB::Black){
            o_black_pos[index_count] = i;
            index_count++;
          }
        }
        if (index_count != 0){//some leds found to be black
          for(int i = 0; i<1; i++){//loop how many lights on per cycle
            int rnd_pos = random(0,index_count);
            owl[o_black_pos[rnd_pos]] = owl_default[o_black_pos[rnd_pos]];
          }
          all_on = false;
        }         
        //penguins
        index_count = 0;
        for (int i = 0; i < PENGUINS_END; i++){
          if (penguins[i] == CRGB::Black){
            p_black_pos[index_count] = i;
            index_count++;
          }
        }
        if (index_count != 0){//some leds found to be black
          for(int i = 0; i<1; i++){//loop how many lights on per cycle
            int rnd_pos = random(0,index_count);
            penguins[p_black_pos[rnd_pos]] = penguins_default[p_black_pos[rnd_pos]];
          }
          all_on = false;
        }   
        //snowman
        index_count = 0;
        for (int i = 0; i < SNOWMAN_END; i++){
          if (snowman[i] == CRGB::Black){
            s_black_pos[index_count] = i;
            index_count++;
          }
        }
        if (index_count != 0){//some leds found to be black
          for(int i = 0; i<2; i++){//loop how many lights on per cycle
            int rnd_pos = random(0,index_count);
            snowman[s_black_pos[rnd_pos]] = snowman_default[s_black_pos[rnd_pos]];
          }
          all_on = false;
        }   
        //fox
        index_count = 0;
        for (int i = 0; i < F_END; i++){
          if (fox[i] == CRGB::Black){
            f_black_pos[index_count] = i;
            index_count++;
          }
        }
        if (index_count != 0){//some leds found to be black
          for(int i = 0; i<1; i++){//loop how many lights on per cycle
            int rnd_pos = random(0,index_count);
            fox[f_black_pos[rnd_pos]] = fox_default[f_black_pos[rnd_pos]];
          }
          all_on = false;
        }   
        //tree  
        index_count = 0;
        for (int i = 0; i < T_END; i++){
          if (tree[i] == CRGB::Black){
            t_black_pos[index_count] = i;
            index_count++;
          }
        }
        if (index_count != 0){//some leds found to be black
          for(int i = 0; i<2; i++){//loop how many lights on per cycle
            int rnd_pos = random(0,index_count);
            tree[t_black_pos[rnd_pos]] = tree_default[t_black_pos[rnd_pos]];
          }
          all_on = false;
        }  
        //p_umbrella
        index_count = 0;
        for (int i = 0; i < P_UMBRELLA_END; i++){
          if (p_umbrella[i] == CRGB::Black){
            p_u_black_pos[index_count] = i;
            index_count++;
          }
        }
        if (index_count != 0){//some leds found to be black
          for(int i = 0; i<1; i++){//loop how many lights on per cycle
            int rnd_pos = random(0,index_count);
            p_umbrella[p_u_black_pos[rnd_pos]] = p_umbrella_default[p_u_black_pos[rnd_pos]];
          }
          all_on = false;
        }    
        //s_umbrella
        index_count = 0;
        for (int i = 0; i < S_UMBRELLA_END; i++){
          if (s_umbrella[i] == CRGB::Black){
            s_u_black_pos[index_count] = i;
            index_count++;
          }
        }
        if (index_count != 0){//some leds found to be black
          for(int i = 0; i<1; i++){//loop how many lights on per cycle
            int rnd_pos = random(0,index_count);
            s_umbrella[s_u_black_pos[rnd_pos]] = s_umbrella_default[s_u_black_pos[rnd_pos]];
          }
          all_on = false;
        }  

        if (all_on){// leds all on on every segment
          animation_state = ANIMATION_STATE_DONE;
          all_default_colour(); //set to default colours
          animation_timer = millis(); //setup timer for how long to display this
          animation_segment_time = random(5,15);
          Serial.println("SPOTSON complete, now waiting");
          break;
        }
      } //animation running

      if (animation_state == ANIMATION_STATE_DONE){
        update_umbrellas();
        update_treelights();
        
        if (animation_timer + (animation_segment_time * 1000) < millis()){//if waited a good amount of time afterwards
            next_on_sequence();
        }
      }
      delay(50); //dont want a long delay otherwise will take ages to colour in all 260 leds in longest chain
        //should scale this with how many are turned on per cycle
      break;
    case ANIMATION_SPOTSOFF:
      Serial.println("ANIMATION_SPOTSOFF");
      if (animation_select != animation_select_old){//if just started on this animation
        animation_select_old = animation_select;
        all_default_colour(); //should be all on but just check
        treelightsoff();
        animation_state = ANIMATION_STATE_RUNNING;
        Serial.println("ANIMATION_SPOTSOFF");
        fade_counter = 0;
        break;
      }

      if (animation_state == ANIMATION_STATE_RUNNING){
        //check if all leds are on
        bool all_off = true;
        uint8_t sq_black_pos[SQ_END]; //list of locations that are still black
        uint8_t o_black_pos[O_END];
        uint8_t p_black_pos[PENGUINS_END];
        uint16_t s_black_pos[SNOWMAN_END];
        uint8_t f_black_pos[F_END];
        uint16_t t_black_pos[SNOWMAN_END];
        uint8_t p_u_black_pos[P_UMBRELLA_END];
        uint8_t s_u_black_pos[S_UMBRELLA_END];

        int index_count = 0;
        //squirrel
        for (int i = 0; i < SQ_END; i++){
          if (!is_pixel_black(squirrel[i])){
            sq_black_pos[index_count] = i;
            index_count++;
          }
        }

        if (index_count != 0){//some leds found to be black
          for(int i = 0; i<1; i++){//loop how many lights on per cycle
            int rnd_pos = random(0,index_count);
            squirrel[sq_black_pos[rnd_pos]] = CRGB::Black;
          }
          all_off = false;
        } 
        //owl
        index_count = 0;
        for (int i = 0; i < O_END; i++){
          if (!is_pixel_black(owl[i])){
            o_black_pos[index_count] = i;
            index_count++;
          }
        }

        if (index_count != 0){//some leds found to be black
          for(int i = 0; i<1; i++){//loop how many lights on per cycle
            int rnd_pos = random(0,index_count);
            owl[o_black_pos[rnd_pos]] = CRGB::Black;
          }
          all_off = false;
        } 
        //penguins
        index_count = 0;
        for (int i = 0; i < PENGUINS_END; i++){
          if (!is_pixel_black(penguins[i])){
            p_black_pos[index_count] = i;
            index_count++;
          }
        }

        if (index_count != 0){//some leds found to be black
          for(int i = 0; i<1; i++){//loop how many lights on per cycle
            int rnd_pos = random(0,index_count);
            penguins[p_black_pos[rnd_pos]] = CRGB::Black;
          }
          all_off = false;
        } 
        //snowman
        index_count = 0;
        for (int i = 0; i < SNOWMAN_END; i++){
          if (!is_pixel_black(snowman[i])){
            s_black_pos[index_count] = i;
            index_count++;
          }
        }

        if (index_count != 0){//some leds found to be black
          for(int i = 0; i<2; i++){//loop how many lights on per cycle
            int rnd_pos = random(0,index_count);
            snowman[s_black_pos[rnd_pos]] = CRGB::Black;
          }
          all_off = false;
        } 
        //fox
        index_count = 0;
        for (int i = 0; i < F_END; i++){
          if (!is_pixel_black(fox[i])){
            f_black_pos[index_count] = i;
            index_count++;
          }
        }

        if (index_count != 0){//some leds found to be black
          for(int i = 0; i<1; i++){//loop how many lights on per cycle
            int rnd_pos = random(0,index_count);
            fox[f_black_pos[rnd_pos]] = CRGB::Black;
          }
          all_off = false;
        } 
        //tree
        index_count = 0;
        for (int i = 0; i < T_END; i++){
          if (!is_pixel_black(tree[i])){
            t_black_pos[index_count] = i;
            index_count++;
          }
        }

        if (index_count != 0){//some leds found to be black
          for(int i = 0; i<2; i++){//loop how many lights on per cycle
            int rnd_pos = random(0,index_count);
            tree[t_black_pos[rnd_pos]] = CRGB::Black;
          }
          all_off = false;
        } 

        //s_umbrella
        index_count = 0;
        for (int i = 0; i < S_UMBRELLA_END; i++){
          if (!is_pixel_black(s_umbrella[i])){
            s_u_black_pos[index_count] = i;
            index_count++;
          }
        }

        if (index_count != 0){//some leds found to be black
          for(int i = 0; i<1; i++){//loop how many lights on per cycle
            int rnd_pos = random(0,index_count);
            s_umbrella[s_u_black_pos[rnd_pos]] = CRGB::Black;
          }
          all_off = false;
        } 
        //p_umbrella
        index_count = 0;
        for (int i = 0; i < P_UMBRELLA_END; i++){
          if (!is_pixel_black(p_umbrella[i])){
            p_u_black_pos[index_count] = i;
            index_count++;
          }
        }

        if (index_count != 0){//some leds found to be black
          for(int i = 0; i<1; i++){//loop how many lights on per cycle
            int rnd_pos = random(0,index_count);
            p_umbrella[p_u_black_pos[rnd_pos]] = CRGB::Black;
          }
          all_off = false;
        } 

        if (all_off){// leds all on on every segment
          animation_state = ANIMATION_STATE_DONE;
          all_pixel_off(); //set to default colours
          animation_timer = millis(); //setup timer for how long to display this
          animation_segment_time = random(2,4);//TODO set appropriate value
          Serial.println("SPOTSOFF complete, now waiting");
          break;
        }
      } //animation running

      if (animation_state == ANIMATION_STATE_DONE){
        // Serial.println("time check");
        if (animation_timer + (animation_segment_time * 1000) < millis()){//if waited a good amount of time afterwards
            next_off_sequence();
        }
      }
      delay(50); //dont want a long delay otherwise will take ages to colour in all 260 leds in longest chain
        //should scale this with how many are turned on per cycle
      break;
    case ANIMATION_NONE: //not used
      all_default_colour();
      break;
  }
  FastLED.show();
  if (stall_timer + (60 * 1000) < millis()){//wait a minute, if no scene change then force scene change, something broke
    Serial.println("TIMEOUTHIT");
    next_on_sequence();
  }
}

