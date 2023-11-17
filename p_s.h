// Defines leds for various parts:

#define DATA_PIN_HEAD       4
#define DATA_PIN_TORSO      5
#define DATA_PIN_BODY       6
#define DATA_PIN_S_UMBRELLA 7
#define DATA_PIN_P_UMBRELLA 8
#define DATA_PIN_PENGUINS   9

// Body
#define BODY_START   0
#define BODY_END     5
#define BODY_COLOR   CRGB::White

// Torso
#define TORSO_START   0
#define TORSO_END    18

#define L_HAND_START  0
#define L_HAND_END    5
#define L_HAND_COLOR  CRGB::Green

#define L_ARM_START   6
#define L_ARM_END     10
#define L_ARM_COLOR   CRGB::White

#define T_MAIN_START  11
#define T_MAIN_END    12
#define T_MAIN_COLOR  CRGB::White

#define R_ARM_START   13
#define R_ARM_END     14
#define R_ARM_COLOR   CRGB::White

#define R_HAND_START  15
#define R_HAND_END    16
#define R_HAND_COLOR  CRGB::Green

#define T_SCARF_START 17
#define T_SCARF_END   18
#define T_SCARF_COLOR CRGB::Yellow

// Head
#define HEAD_START   0
#define HEAD_END    17

// Hat + Face are subsets of Head
#define HAT_START    0
#define HAT_END      4
#define HAT_COLOR    CRGB::Red

#define FACE_START   5
#define FACE_END     9
#define FACE_COLOR   CRGB::White

#define MOUTH_START 10
#define MOUTH_END   13
#define MOUTH_COLOR  CRGB::White

#define EYES_START  14
#define EYES_END    15
#define EYES_COLOR  CRGB::White

#define NOSE_START  16
#define NOSE_END    17
#define NOSE_COLOR  CRGB::Orange

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

#define P_1_BODY_START    0
#define P_1_BODY_END      1
#define P_1_BODY_COLOR    CRGB::White

#define P_1_HEAD_START    2
#define P_1_HEAD_END      3
#define P_1_HEAD_COLOR    CRGB::Blue

#define P_1_MUFFS_START   4
#define P_1_MUFFS_END     5
#define P_1_MUFFS_COLOR    CRGB::Red

#define P_1_L_ARM_START   6
#define P_1_L_ARM_END     7
#define P_1_L_ARM_COLOR   CRGB::Blue
