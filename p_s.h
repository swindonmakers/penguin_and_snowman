// Defines leds for various parts:

#define DATA_PIN_HEAD       5
#define DATA_PIN_TORSO      18
#define DATA_PIN_BODY       19
#define DATA_PIN_S_UMBRELLA 21
#define DATA_PIN_P_UMBRELLA 22
#define DATA_PIN_PENGUINS   23


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

// Hat + Face are subsets of Head
#define FACE_START   HEAD_START
#define FACE_CNT     27
#define FACE_COLOR   CRGB::White

#define HAT_START    FACE_START+FACE_CNT
#define HAT_CNT      47
#define HAT_COLOR    CRGB::Red

#define MOUTH_START HAT_START+HAT_CNT
#define MOUTH_CNT    8
#define MOUTH_COLOR  CRGB::Yellow

#define NOSE_START  MOUTH_START+MOUTH_CNT
#define NOSE_CNT    11
#define NOSE_COLOR  CRGB::Orange

#define EYES_START  NOSE_START+NOSE_CNT
#define EYES_CNT    12
#define EYES_COLOR  CRGB::White

#define HEAD_END    HEAD_START+FACE_CNT+HAT_CNT+MOUTH_CNT+NOSE_CNT+EYES_CNT

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
