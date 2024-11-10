// Defines leds for various parts:
// L and R means stage left and stage right ie:your left not the models 
#define DATA_PIN_DISPLAY    3
#define DATA_PIN_HEAD       4
#define DATA_PIN_TORSO      5
#define DATA_PIN_BODY       6
#define DATA_PIN_S_UMBRELLA 7
#define DATA_PIN_P_UMBRELLA 8
#define DATA_PIN_PENGUINS   9
#define DATA_PIN_FOX        10
#define DATA_PIN_SQUIRREL   11
#define DATA_PIN_OWL        12
#define DATA_PIN_TREE       13


#define DISPLAY_CNT 26
#define DISPLAY_COLOR CRGB::White

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
#define P_1_B_HAT_RIM_START   P_1_L_WING_START      + P_1_L_WING_CNT
#define P_1_T_HAT_RIM_START   P_1_B_HAT_RIM_START       + P_1_B_HAT_RIM_CNT
#define P_1_L_BODY_START  P_1_T_HAT_RIM_START       + P_1_T_HAT_RIM_CNT    //black bit of body
#define P_1_B_BODY_START  P_1_L_BODY_START      + P_1_L_BODY_CNT       //white bit of body
#define P_1_R_BODY_START  P_1_B_BODY_START      + P_1_B_BODY_CNT       //black bit of body
#define P_1_T_HAT_START   P_1_R_BODY_START      + P_1_R_BODY_CNT    
#define P_1_HAT_POM_START P_1_T_HAT_START       + P_1_T_HAT_CNT
#define P_1_B_HAT_START   P_1_HAT_POM_START     + P_1_HAT_POM_CNT      //pompom

#define P_1_FOOT_COLOR     CRGB::Gold
#define P_1_WING_COLOR     CRGB::MediumBlue 
#define P_1_SCARF_COLOR    CRGB::Fuchsia
#define P_1_BROW_COLOR     CRGB::MediumBlue 
#define P_1_EYE_COLOR      CRGB::Goldenrod
// #define P_1_BEAK_COLOR     CRGB(40,  255,  255) //CRGB::Chartreuse//RGB is GRB out of order with these so finding a different colour 
#define P_1_HAT_COLOR      CRGB::Red
#define P_1_BODY_COLOR     CRGB::MediumBlue 
#define P_1_BODY_COLOR2    CRGB::PaleGreen //effectively white 
#define P_1_HAT_POM_COLOR  CRGB::PaleGreen

//sections of top Penguin's
#define P_2_L_FOOT_CNT     5
#define P_2_R_FOOT_CNT     4
#define P_2_R_WING_CNT     6
#define P_2_B_SCARF_CNT    5
#define P_2_T_SCARF_CNT    4
#define P_2_R_SCARF_CNT    5
#define P_2_L_SCARF_CNT    6
#define P_2_L_WING_CNT     6
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

#define PENGUINS_START    P_1_L_FOOT_START
#define PENGUINS_END      P_2_L_EYE_START + P_2_L_EYE_CNT

#define P_2_FOOT_COLOR     CRGB::Gold
#define P_2_WING_COLOR     CRGB::Blue
#define P_2_SCARF_COLOR    CRGB::Green
#define P_2_BROW_COLOR     CRGB::Blue
#define P_2_EYE_COLOR      CRGB::Yellow
#define P_2_BEAK_COLOR     CRGB::Orange
#define P_2_HAT_COLOR      CRGB::Red
#define P_2_BODY_COLOR     CRGB::Blue
#define P_2_BODY_COLOR2    CRGB::PaleGreen //effectively white 
#define P_2_EAR_COLOR      CRGB::Red

// snowman
//sections of Snowman
//bottom section of Snowman

#define S_B_BODY_CNT     43
#define S_B_BADGE_CNT    24

#define S_B_BODY_START   0
#define S_B_BADGE_START  S_B_BODY_START + S_B_BODY_CNT
#define S_B_BODY_END     S_B_BADGE_START + S_B_BADGE_CNT

#define S_B_BODY_COLOR   CRGB::White
#define S_B_BADGE_COLOR   CRGB::Orange

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
#define S_R_HAND_START        S_TORSO_START + S_R_OUTTER_ARM_CNT
#define S_R_INNER_ARM_START   S_R_HAND_START       + S_R_HAND_CNT
#define S_M_BODY_START        S_R_INNER_ARM_START  + S_R_INNER_ARM_CNT
#define S_T_SCARF_START       S_M_BODY_START       + S_M_BODY_CNT
#define S_B_SCARF_START       S_T_SCARF_START      + S_T_SCARF_CNT
#define S_L_SCARF_START       S_B_SCARF_START      + S_B_SCARF_CNT
#define S_R_SCARF_START       S_L_SCARF_START      + S_L_SCARF_CNT
#define S_L_T_ARM_START       S_R_SCARF_START      +S_R_SCARF_CNT
#define S_L_HAND_START        S_L_T_ARM_START      + S_L_T_ARM_CNT
#define S_L_B_ARM_START       S_L_HAND_START       + S_L_HAND_CNT

#define S_TORSO_START         S_R_OUTTER_ARM_START
#define S_TORSO_END           S_L_B_ARM_START      + S_L_B_ARM_CNT

#define S_SCARF_COLOR         CRGB::Pink

//top section of  Snowman
#define S_FACE_CNT 29
#define S_HAT_RIM_CNT 23 
#define S_HAT_CNT 23 
#define S_MOUTH_CNT 8
#define S_NOSE_CNT 12
#define S_L_EYE_CNT 7
#define S_R_EYE_CNT 7

#define S_HEAD_START     0
#define S_HAT_RIM_START  S_HEAD_START     + S_FACE_CNT
#define S_HAT_START      S_HAT_RIM_START  + S_HAT_RIM_CNT
#define S_MOUTH_START    S_HAT_START      + S_HAT_CNT
#define S_NOSE_START     S_MOUTH_START    + S_MOUTH_CNT
#define S_L_EYE_START    S_NOSE_START     + S_NOSE_CNT
#define S_R_EYE_START    S_L_EYE_START    + S_L_EYE_CNT
#define S_HEAD_END       S_R_EYE_START    + S_R_EYE_CNT

#define S_FACE_COLOR     CRGB::White
#define S_HAT_COLOR      CRGB::Red
#define S_MOUTH_COLOR    CRGB::Chartreuse
#define S_EYES_COLOR     CRGB::Red
#define S_NOSE_COLOR     CRGB::Yellow

// Fox
#define F_TAIL_TIP_CNT  16
#define F_TAIL_MAIN_CNT 21
#define F_REAR_LEG_CNT  17
#define F_MID_LEG_CNT   10
// Junction with body/front leg
#define F_MID_BODY_CNT   7
#define F_LEFT_MASK_CNT  5
#define F_RIGHT_MASK_CNT 6
#define F_LOWER_FACE_CNT 8
#define F_L_HEAD_CNT     4
#define F_R_HEAD_CNT     4
#define F_R_EYE_CNT      7
#define F_L_EYE_CNT      7
#define F_L_EAR_CNT      6
#define F_TOP_HEAD_CNT   2
#define F_R_EAR_CNT      6
#define F_R_BODY_CNT     8
#define F_FR_LEG_CNT    13
#define F_L_BODY_CNT    13

#define F_START          0
#define F_TAIL_MAIN_ST   F_START           + F_TAIL_TIP_CNT
#define F_REAR_LEG_ST    F_TAIL_MAIN_ST    + F_TAIL_MAIN_CNT
#define F_MID_LEG_ST     F_TAIL_MAIN_ST    + F_REAR_LEG_CNT
#define F_MID_BODY_ST    F_REAR_LEG_ST     + F_MID_LEG_CNT
#define F_LEFT_MASK_ST   F_MID_LEG_ST      + F_MID_BODY_CNT
#define F_RIGHT_MASK_ST  F_MID_BODY_ST     + F_LEFT_MASK_CNT
#define F_LOWER_FACE_ST  F_LEFT_MASK_ST    + F_RIGHT_MASK_CNT
#define F_L_HEAD_ST      F_RIGHT_MASK_ST   + F_LOWER_FACE_CNT
#define F_R_HEAD_ST      F_LOWER_MASK_ST   + F_L_HEAD_CNT
#define F_R_EYE_ST       F_L_HEAD_ST       + F_R_HEAD_CNT
#define F_L_EYE_ST       F_R_HEAD_ST       + F_R_EYE_CNT
#define F_L_EAR_ST       F_R_EYE_ST        + F_L_EYE_CNT
#define F_TOP_HEAD_ST    F_L_EYE_ST        + F_L_EAR_CNT
#define F_R_EAR_ST       F_L_EAR_ST        + F_TOP_HEAD_CNT
#define F_R_BODY_ST      F_TOP_HEAD_ST     + F_R_EAR_CNT
#define F_FR_LEG_ST      F_R_EAR_ST        + F_R_BODY_CNT
#define F_L_BODY_ST      F_R_BODY_ST       + F_FR_LEG_CNT
#define F_END            F_FR_LEG_ST       + F_L_BODY_CNT

#define F_BODY_COLOR     CRGB::DarkRed
#define F_TAIL_COLOR     CRGB::White
#define F_MASK_COLOR     CRGB::White
#define F_EYES_COLOR     CRGB::Red
#define F_NOSE_COLOR     CRGB::DarkOrange

// Squirrel
#define SQ_L_TAIL_CNT    8
#define SQ_M_TAIL_CNT   10
#define SQ_U_TAIL_CNT   12
#define SQ_M_BODY_CNT   14
#define SQ_LOWER_HEAD_CNT 8
#define SQ_R_OUT_EYE_CNT 3
#define SQ_NOSE_CNT     10
#define SQ_TOOTH_CNT     3
#define SQ_R_EYE_CNT     7
#define SQ_L_EYE_CNT     7
#define SQ_L_OUT_EYE_CNT 3
#define SQ_L_EAR_CNT     3
#define SQ_UPPER_HEAD_CNT 6
#define SQ_R_EAR_CNT     4
#define SQ_U_BODY_CNT    2
#define SQ_ARM_CNT       9
#define SQ_F_BODY_CNT    3
#define SQ_FOOT_CNT      5

#define SQ_START   0
#define SQ_L_TAIL_ST     SQ_START
#define SQ_M_TAIL_ST     SQ_L_TAIL_ST      + SQ_L_TAIL_CNT
#define SQ_U_TAIL_ST     SQ_M_TAIL_ST      + SQ_M_TAIL_CNT
#define SQ_M_BODY_ST     SQ_U_TAIL_ST      + SQ_U_TAIL_CNT
#define SQ_LOWER_HEAD_ST SQ_M_BODY_ST      + SQ_M_BODY_CNT
#define SQ_R_OUT_EYE_ST  SQ_LOWER_HEAD_ST  + SQ_LOWER_HEAD_CNT
#define SQ_NOSE_ST       SQ_R_OUT_EYE_ST   + SQ_R_OUT_EYE_CNT
#define SQ_TOOTH_ST      SQ_NOSE_ST        + SQ_NOSE_CNT
#define SQ_R_EYE_ST      SQ_TOOTH_ST       + SQ_TOOTH_CNT
#define SQ_L_EYE_ST      SQ_R_EYE_ST       + SQ_R_EYE_CNT
#define SQ_L_OUT_EYE_ST  SQ_L_EYE_ST       + SQ_L_EYE_CNT
#define SQ_L_EAR_ST      SQ_L_OUT_EYE_ST   + SQ_L_OUT_EYE_CNT
#define SQ_UPPER_HEAD_ST SQ_L_EAR_ST       + SQ_L_EAR_CNT
#define SQ_R_EAR_ST      SQ_UPPER_HEAD_ST  + SQ_UPPER_HEAD_CNT
#define SQ_U_BODY_ST     SQ_R_EAR_ST       + SQ_R_EAR_CNT
#define SQ_ARM_ST        SQ_U_BODY_ST      + SQ_U_BODY_CNT
#define SQ_F_BODY_ST     SQ_ARM_ST         + SQ_ARM_CNT
#define SQ_FOOT_ST       SQ_F_BODY_ST      + SQ_F_BODY_CNT
#define SQ_END           SQ_FOOT_ST        + SQ_FOOT_CNT

#define SQ_BODY_COLOR    CRGB::Goldenrod
#define SQ_HEAD_COLOR    CRGB::DarkGoldenrod
#define SQ_TOOTH_COLOR   CRGB::IndianRed
#define SQ_EYE_COLOR     CRGB::Blue

// Owl
#define O_M_BODY_CNT      12
#define O_R_WING_IN_CNT    4
#define O_R_WING_OUT_CNT   5
#define O_R_FACE_CNT       8
#define O_R_EAR_CNT        9
#define O_HEAD_TOP_CNT     6
#define O_L_EAR_CNT        7
#define O_L_FACE_CNT       8
#define O_L_OUT_EYE_CNT   11
#define O_R_OUT_EYE_CNT   11
#define O_BEAK_CNT         5
#define O_R_IN_EYE_CNT     6
#define O_R_EYE_CNT        7
#define O_L_EYE_CNT        7
#define O_L_IN_EYE_CNT     6
#define O_L_WING_CNT      36

#define O_START            0
#define O_R_FACE_WING_ST   O_START            + O_M_BODY_CNT + O_R_WING_IN_CNT + O_R_WING_OUT_CNT
#define O_R_EAR_ST         O_R_FACE_WING_ST   + O_R_FACE_CNT
#define O_HEAD_TOP_ST      O_R_EAR_ST         + O_R_FACE_CNT
#define O_L_EAR_ST         O_HEAD_TOP_ST      + O_HEAD_TOP_CNT
#define O_OUTER_EYE_ST     O_L_EAR_ST         + O_L_EAR_CNT
#define O_BEAK_ST          O_OUTER_EYE_ST     + O_L_OUT_EYE_CNT + O_R_OUT_EYE_CNT
#define O_R_IN_EYE_ST      O_BEAK_ST          + O_BEAK_CNT
#define O_EYES_ST          O_R_IN_EYE_ST      + O_R_IN_EYE_CNT
#define O_L_IN_EYE_ST      O_EYES_ST          + O_R_EYE_CNT + O_L_EYE_CNT
#define O_L_WING_ST        O_L_IN_EYE_ST      + O_L_IN_EYE_CNT
#define O_END              O_L_WING_ST        + O_L_WING_CNT

#define O_BODY_COLOR       CRGB::Blue
#define O_EAR_COLOR        CRGB::White
#define O_OUT_EYE_COLOR    CRGB::Cyan
#define O_EYE_COLOR        CRGB::White
#define O_BEAK_COLOR       CRGB::DarkBlue

// Tree
#define T_TR_BTM_CNT       52
#define T_L_L_BRANCH_CNT   43
#define T_R_L_BRANCH_CNT   44
#define T_TR_MID_CNT       32
#define T_R_U_BRANCH_CNT   24
#define T_L_U_BRANCH_CNT   28
#define T_TR_TOP_CNT       33

#define T_START             0
#define T_END               T_TR_BTM_CNT + T_L_L_BRANCH_CNT + T_R_L_BRANCH_CNT + T_TR_MID_CNT + T_R_U_BRANCH_CNT + T_L_U_BRANCH_CNT + T_TR_TOP_CNT
