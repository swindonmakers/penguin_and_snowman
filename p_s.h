// Defines leds for various parts:
// L and R means stage left and stage right ie:your left not the models 
#define DATA_PIN_HEAD       4
#define DATA_PIN_TORSO      5
#define DATA_PIN_BODY       6
#define DATA_PIN_S_UMBRELLA 7
#define DATA_PIN_P_UMBRELLA 8
#define DATA_PIN_PENGUINS   9

// // Body
// #define BODY_START   0
// #define BODY_END     5
// #define BODY_COLOR   CRGB::White

// // Torso
// #define TORSO_START   0
// #define TORSO_END    18

// #define L_HAND_START  0
// #define L_HAND_END    5
// #define L_HAND_COLOR  CRGB::Green

// #define L_ARM_START   6
// #define L_ARM_END     10
// #define L_ARM_COLOR   CRGB::White

// #define T_MAIN_START  11
// #define T_MAIN_END    12
// #define T_MAIN_COLOR  CRGB::White

// #define R_ARM_START   13
// #define R_ARM_END     14
// #define R_ARM_COLOR   CRGB::White

// #define R_HAND_START  15
// #define R_HAND_END    16
// #define R_HAND_COLOR  CRGB::Green

// #define T_SCARF_START 17
// #define T_SCARF_END   18
// #define T_SCARF_COLOR CRGB::Yellow

// // Head
// #define HEAD_START   0
// #define HEAD_END    17

// // Hat + Face are subsets of Head
// #define HAT_START    0
// #define HAT_END      4
// #define HAT_COLOR    CRGB::Red

// #define FACE_START   5
// #define FACE_END     9
// #define FACE_COLOR   CRGB::White

// #define MOUTH_START 10
// #define MOUTH_END   13
// #define MOUTH_COLOR  CRGB::White

// #define EYES_START  14
// #define EYES_END    15
// #define EYES_COLOR  CRGB::White

// #define NOSE_START  16
// #define NOSE_END    17
// #define NOSE_COLOR  CRGB::Orange

// Snowman Umbrella
//sections of Snowman Umbrella
#define S_UMBRELLA_HANDLE_CNT       10    //handle LED Count
#define S_UMBRELLA_L_RIB_OUTER_CNT  20    //left outmost rib LED Count
#define S_UMBRELLA_R_RIB_OUTER_CNT  19    //right outmost rib LED Count
#define S_UMBRELLA_L_RIB_MID_CNT    17    //left middle rib LED Count
#define S_UMBRELLA_R_RIB_MID_CNT    17    //right middle rib LED Count
#define S_UMBRELLA_L_RIB_CENTRE_CNT 12    //left center rib LED Count
#define S_UMBRELLA_R_RIB_CENTRE_CNT 12     //right center rib LED Count
#define S_UMBRELLA_BTM_CANOPY_CNT   33    //btm bit LED Count

#define S_UMBRELLA_HANDLE_START       0                                                               //handle LED Count
#define S_UMBRELLA_L_RIB_CENTRE_START S_UMBRELLA_HANDLE_START       + S_UMBRELLA_HANDLE_CNT           //left center rib LED Start
#define S_UMBRELLA_R_RIB_MID_START    S_UMBRELLA_L_RIB_CENTRE_START + S_UMBRELLA_L_RIB_CENTRE_CNT     //right middle rib LED Start
#define S_UMBRELLA_R_RIB_CENTRE_START S_UMBRELLA_R_RIB_MID_START    + S_UMBRELLA_R_RIB_MID_CNT        //right center rib LED Start
#define S_UMBRELLA_L_RIB_MID_START    S_UMBRELLA_R_RIB_CENTRE_START + S_UMBRELLA_R_RIB_CENTRE_CNT     //left middle rib LED Start
#define S_UMBRELLA_L_RIB_OUTER_START  S_UMBRELLA_L_RIB_MID_START    + S_UMBRELLA_L_RIB_MID_CNT        //left outmost rib LED Start
#define S_UMBRELLA_R_RIB_OUTER_START  S_UMBRELLA_L_RIB_OUTER_START  + S_UMBRELLA_L_RIB_OUTER_CNT      //right outmost rib LED Start
#define S_UMBRELLA_BTM_CANOPY_START   S_UMBRELLA_R_RIB_OUTER_START  + S_UMBRELLA_R_RIB_OUTER_CNT      //btm bit LED Start

#define S_UMBRELLA_START 0
#define S_UMBRELLA_END   S_UMBRELLA_BTM_CANOPY_START + S_UMBRELLA_BTM_CANOPY_CNT
#define S_UMBRELLA_COLOR CRGB::Yellow

// Penguin Umbrella
//sections of Penguin Umbrella
#define P_UMBRELLA_HANDLE_CNT       9     //handle LED Count
#define P_UMBRELLA_L_RIB_OUTER_CNT  12    //left outmost rib LED Count
#define P_UMBRELLA_R_RIB_OUTER_CNT  13    //right outmost rib LED Count
#define P_UMBRELLA_L_RIB_MID_CNT    9     //left middle rib LED Count
#define P_UMBRELLA_R_RIB_MID_CNT    10    //right middle rib LED Count
#define P_UMBRELLA_L_RIB_CENTRE_CNT 8     //left center rib LED Count
#define P_UMBRELLA_R_RIB_CENTRE_CNT 8     //right center rib LED Count
#define P_UMBRELLA_BTM_CANOPY_CNT   19    //btm bit LED Count

#define P_UMBRELLA_HANDLE_START       0                                                               //handle LED Count
#define P_UMBRELLA_L_RIB_CENTRE_START P_UMBRELLA_HANDLE_START       + P_UMBRELLA_HANDLE_CNT           //left center rib LED Start
#define P_UMBRELLA_R_RIB_MID_START    P_UMBRELLA_L_RIB_CENTRE_START + P_UMBRELLA_L_RIB_CENTRE_CNT     //right middle rib LED Start
#define P_UMBRELLA_R_RIB_CENTRE_START P_UMBRELLA_R_RIB_MID_START    + P_UMBRELLA_R_RIB_MID_CNT        //right center rib LED Start
#define P_UMBRELLA_L_RIB_MID_START    P_UMBRELLA_R_RIB_CENTRE_START + P_UMBRELLA_R_RIB_CENTRE_CNT     //left middle rib LED Start
#define P_UMBRELLA_L_RIB_OUTER_START  P_UMBRELLA_L_RIB_MID_START    + P_UMBRELLA_L_RIB_MID_CNT        //left outmost rib LED Start
#define P_UMBRELLA_R_RIB_OUTER_START  P_UMBRELLA_L_RIB_OUTER_START  + P_UMBRELLA_L_RIB_OUTER_CNT      //right outmost rib LED Start
#define P_UMBRELLA_BTM_CANOPY_START   P_UMBRELLA_R_RIB_OUTER_START  + P_UMBRELLA_R_RIB_OUTER_CNT      //btm bit LED Start
  
//umbrella LED order is L_C, R_M, R_C, L_M, L_O, R_O, BTM
#define P_UMBRELLA_START  0
#define P_UMBRELLA_END    P_UMBRELLA_BTM_CANOPY_START + P_UMBRELLA_BTM_CANOPY_CNT
#define P_UMBRELLA_COLOR  CRGB::Red

#define PENGUINS_START    0
#define PENGUINS_END      100

// Penguins
//sections of bottom Penguin
#define P_1_L_FOOT_CNT     5
#define P_1_R_FOOT_CNT     5
#define P_1_R_WING_CNT     6
#define P_1_B_SCARF_CNT    5
#define P_1_T_SCARF_CNT    5
#define P_1_R_SCARF_CNT    7
#define P_1_L_SCARF_CNT    5
#define P_1_BROW_CNT       5
#define P_1_R_EYE_CNT      7
#define P_1_BEAK_CNT       7
#define P_1_L_EYE_CNT      7
#define P_1_L_WING_CNT     5
#define P_1_B_HAT_RIM_CNT  4
#define P_1_T_HAT_RIM_CNT  4
#define P_1_L_BODY_CNT     2
#define P_1_B_BODY_CNT     18
#define P_1_R_BODY_CNT     2
#define P_1_T_HAT_CNT      7
#define P_1_HAT_POM_CNT    3   //pompom
#define P_1_B_HAT_CNT      3




#define P_1_L_FOOT_START  0
#define P_1_R_FOOT_START  P_1_L_FOOT_START      + P_1_L_FOOT_CNT
#define P_1_R_WING_START  P_1_R_FOOT_START      + P_1_R_FOOT_CNT
#define P_1_B_SCARF_START P_1_R_WING_START      + P_1_R_WING_CNT
#define P_1_T_SCARF_START P_1_B_SCARF_START     + P_1_B_SCARF_CNT
#define P_1_R_SCARF_START P_1_T_SCARF_START     + P_1_T_SCARF_CNT
#define P_1_L_SCARF_START P_1_R_SCARF_START     + P_1_R_SCARF_CNT
#define P_1_BROW_START    P_1_L_SCARF_START     + P_1_L_SCARF_CNT
#define P_1_R_EYE_START   P_1_BROW_START        + P_1_BROW_CNT
#define P_1_BEAK_START    P_1_R_EYE_START       + P_1_R_EYE_CNT
#define P_1_L_EYE_START   P_1_BEAK_START        + P_1_BEAK_CNT
#define P_1_L_WING_START  P_1_L_EYE_START       + P_1_L_EYE_CNT
#define P_1_B_RIM_START   P_1_L_WING_START      + P_1_L_WING_CNT
#define P_1_T_RIM_START   P_1_B_RIM_START       + P_1_B_HAT_RIM_CNT
#define P_1_L_BODY_START  P_1_T_RIM_START       + P_1_T_HAT_RIM_CNT    //black bit of body
#define P_1_B_BODY_START  P_1_L_BODY_START      + P_1_L_BODY_CNT       //white bit of body
#define P_1_R_BODY_START  P_1_B_BODY_START      + P_1_B_BODY_CNT       //black bit of body
#define P_1_T_HAT_START   P_1_R_BODY_START      + P_1_R_BODY_CNT    
#define P_1_HAT_POM_START P_1_T_HAT_START       + P_1_T_HAT_CNT
#define P_1_B_HAT_START   P_1_HAT_POM_START     + P_1_HAT_POM_CNT      //pompom
    

//sections of top Penguin's
#define P_2_L_FOOT_CNT     5
#define P_2_R_FOOT_CNT     4
#define P_2_R_WING_CNT     6
#define P_2_B_SCARF_CNT    5
#define P_2_T_SCARF_CNT    4
#define P_2_R_SCARF_CNT    5
#define P_2_L_SCARF_CNT    6
#define P_2_L_WING_CNT     5
#define P_2_B_BODY_CNT     15
#define P_2_T_BODY_CNT     8
#define P_2_L_EAR_CNT      6
#define P_2_BROW_CNT       5
#define P_2_R_EAR_CNT      6
#define P_2_R_EYE_CNT      7
#define P_2_BEAK_CNT       7
#define P_2_L_EYE_CNT      7



#define P_2_L_FOOT_START  P_1_B_HAT_START       +P_1_B_HAT_CNT
#define P_2_R_FOOT_START  P_2_L_FOOT_START      + P_2_L_FOOT_CNT
#define P_2_R_WING_START  P_2_R_FOOT_START      + P_2_R_FOOT_CNT
#define P_2_B_SCARF_START P_2_R_WING_START      + P_2_R_WING_CNT
#define P_2_T_SCARF_START P_2_B_SCARF_START     + P_2_B_SCARF_CNT
#define P_2_R_SCARF_START P_2_T_SCARF_START     + P_2_T_SCARF_CNT
#define P_2_L_SCARF_START P_2_R_SCARF_START     + P_2_R_SCARF_CNT
#define P_2_L_WING_START  P_2_L_SCARF_START     + P_2_L_SCARF_CNT
#define P_2_B_BODY_START  P_2_L_WING_START      + P_2_L_WING_CNT    //white bit of body
#define P_2_T_BODY_START  P_2_B_BODY_START      + P_2_B_BODY_CNT    //black bit of body
#define P_2_L_EAR_START   P_2_T_BODY_START      + P_2_T_BODY_CNT
#define P_2_BROW_START    P_2_L_EAR_START       + P_2_L_EAR_CNT
#define P_2_R_EAR_START   P_2_BROW_START        + P_2_BROW_CNT
#define P_2_R_EYE_START   P_2_R_EAR_START        + P_2_R_EAR_CNT
#define P_2_BEAK_START    P_2_R_EYE_START       + P_2_R_EYE_CNT
#define P_2_L_EYE_START   P_2_BEAK_START        + P_2_BEAK_CNT



// snowman
//sections of Snowman
//bottom section of Snowman

#define S_B_BODY_CNT     43
#define S_B_BADGE_CNT    24

#define S_B_BODY_START   0
#define S_B_BADGE_START  S_B_BODY_START + S_B_BODY_CNT


//middle section of  Snowman
#define S_R_OUTTER_ARM_CNT 13
#define S_R_HAND_CNT       16
#define S_R_INNER_ARM_CNT  5
#define S_M_BODY_CNT       22
#define S_T_SCARF_CNT      9
#define S_B_SCARF_CNT      11
#define S_L_SCARF_CNT      14
#define S_R_SCARF_CNT      19
#define S_L_T_ARM_CNT      4
#define S_L_HAND_CNT       16
#define S_L_B_ARM_CNT      9

#define S_R_OUTTER_ARM_START  0
#define S_R_HAND_START        S_R_OUTTER_ARM_START + S_R_OUTTER_ARM_CNT
#define S_R_INNER_ARM_START   S_R_HAND_START       + S_R_HAND_CNT
#define S_M_BODY_START        S_R_INNER_ARM_START  + S_R_INNER_ARM_CNT
#define S_T_SCARF_START       S_M_BODY_START       + S_M_BODY_CNT
#define S_B_SCARF_START       S_T_SCARF_START      + S_T_SCARF_CNT
#define S_L_SCARF_START       S_B_SCARF_START      + S_B_SCARF_CNT
#define S_R_SCARF_START       S_L_SCARF_START      + S_L_SCARF_CNT
#define S_L_T_ARM_START       S_R_SCARF_START      +S_R_SCARF_CNT
#define S_L_HAND_START        S_L_T_ARM_START      + S_L_T_ARM_CNT
#define S_L_B_ARM_START       S_L_HAND_START       + S_L_HAND_CNT

//top section of  Snowman
#define S_HEAD_CNT 29
#define S_HAT_RIM_CNT 23 
#define S_HAT_CNT 23 
#define S_MOUTH_CNT 8
#define S_NOSE_CNT 12
#define S_L_EYE_CNT 7
#define S_R_EYE_CNT 7



#define S_HEAD_START     0
#define S_HAT_RIM_START  S_HEAD_START     + S_HEAD_CNT
#define S_HAT_START      S_HAT_RIM_START  + S_HAT_RIM_CNT
#define S_MOUTH_START    S_HAT_START      + S_HAT_CNT
#define S_NOSE_START     S_MOUTH_START    + S_MOUTH_CNT
#define S_L_EYE_START    S_NOSE_START     + S_NOSE_CNT
#define S_r_EYE_START    S_L_EYE_START    + S_L_EYE_CNT


// #define P_1_BODY_START    0
// #define P_1_BODY_END      1
// #define P_1_BODY_COLOR    CRGB::White

// #define P_1_HEAD_START    2
// #define P_1_HEAD_END      3
// #define P_1_HEAD_COLOR    CRGB::Blue

// #define P_1_MUFFS_START   4
// #define P_1_MUFFS_END     5
// #define P_1_MUFFS_COLOR    CRGB::Red

// #define P_1_L_ARM_START   6
// #define P_1_L_ARM_END     7
// #define P_1_L_ARM_COLOR   CRGB::Blue
