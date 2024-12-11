// Defines leds for various parts:
// L and R means stage left and stage right ie:your left not the models 
#define DATA_PIN_DISPLAY    3 //3
#define DATA_PIN_HEAD       4 //4
#define DATA_PIN_TORSO      5 //5 
#define DATA_PIN_BODY       6 //6
#define DATA_PIN_S_UMBRELLA 7 //7
#define DATA_PIN_P_UMBRELLA 8 //8
#define DATA_PIN_PENGUINS   9 //9
#define DATA_PIN_OWL        23 //TODO
#define DATA_PIN_SQUIRREL   20//TODO
#define DATA_PIN_FOX        21//TODO
#define DATA_PIN_TREE       22//TODO  
#define DATA_PIN_TREELIGHT  19


#define DISPLAY_CNT 26
#define DISPLAY_COLOR CRGB::White

#define TREELIGHT_CNT 100

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

#define P_1_FOOT_COLOR     CRGB::OrangeRed
#define P_1_WING_COLOR     CRGB::MediumBlue 
#define P_1_SCARF_COLOR    CRGB::Fuchsia
#define P_1_BROW_COLOR     CRGB::MediumBlue 
#define P_1_EYE_COLOR      CRGB(60, 40, 4) //nerfed CRGB::Goldenrod
#define P_1_BEAK_COLOR     CRGB(24,  150,  0) //CRGB::Chartreuse//RGB is GRB out of order with these so finding a different colour 
#define P_1_HAT_COLOR      CRGB::Red
#define P_1_BODY_COLOR     CRGB::MediumBlue 
#define P_1_BODY_COLOR2    CRGB(60,60, 60) //effectively white 
#define P_1_HAT_POM_COLOR  CRGB(60,60, 60)

#define OFF_LED CRGB(1,1,1) //off by most definitions but not 0 for some cheating in code in otherplaces

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

#define P_2_FOOT_COLOR     CRGB::OrangeRed
#define P_2_WING_COLOR     CRGB::Blue
#define P_2_SCARF_COLOR    CRGB::Green
#define P_2_BROW_COLOR     CRGB::Blue
#define P_2_EYE_COLOR      CRGB(60,60, 0)
#define P_2_BEAK_COLOR     CRGB(24,  150,  0)
#define P_2_HAT_COLOR      CRGB::Red
#define P_2_BODY_COLOR     CRGB::Blue
#define P_2_BODY_COLOR2    CRGB::Gray //effectively white 
#define P_2_EAR_COLOR      CRGB::Red

// snowman
//sections of Snowman
//bottom section of Snowman

#define S_B_BODY_CNT     43
#define S_B_BADGE_CNT    24

#define S_B_BODY_START   0
#define S_B_BADGE_START  S_B_BODY_START + S_B_BODY_CNT
#define S_B_BODY_END     S_B_BADGE_START + S_B_BADGE_CNT

#define S_B_BODY_COLOR   CRGB(90,255,150)
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

#define S_R_OUTTER_ARM_START  S_B_BODY_END
#define S_R_HAND_START        S_B_BODY_END + S_R_OUTTER_ARM_CNT
#define S_R_INNER_ARM_START   S_R_HAND_START       + S_R_HAND_CNT
#define S_M_BODY_START        S_R_INNER_ARM_START  + S_R_INNER_ARM_CNT
#define S_T_SCARF_START       S_M_BODY_START       + S_M_BODY_CNT
#define S_B_SCARF_START       S_T_SCARF_START      + S_T_SCARF_CNT
#define S_L_SCARF_START       S_B_SCARF_START      + S_B_SCARF_CNT
#define S_R_SCARF_START       S_L_SCARF_START      + S_L_SCARF_CNT
#define S_L_T_ARM_START       S_R_SCARF_START      + S_R_SCARF_CNT
#define S_L_HAND_START        S_L_T_ARM_START      + S_L_T_ARM_CNT
#define S_L_B_ARM_START       S_L_HAND_START       + S_L_HAND_CNT

#define S_TORSO_START         S_B_BODY_END
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

#define S_HEAD_START     S_TORSO_END
#define S_HAT_RIM_START  S_HEAD_START     + S_FACE_CNT
#define S_HAT_START      S_HAT_RIM_START  + S_HAT_RIM_CNT
#define S_MOUTH_START    S_HAT_START      + S_HAT_CNT
#define S_NOSE_START     S_MOUTH_START    + S_MOUTH_CNT
#define S_L_EYE_START    S_NOSE_START     + S_NOSE_CNT
#define S_R_EYE_START    S_L_EYE_START    + S_L_EYE_CNT
#define S_HEAD_END       S_R_EYE_START    + S_R_EYE_CNT
#define SNOWMAN_END      S_HEAD_END

#define S_FACE_COLOR     CRGB::Gray
#define S_HAT_COLOR      CRGB::Red
#define S_MOUTH_COLOR    CRGB::Chartreuse
#define S_EYES_COLOR     CRGB::Red
#define S_NOSE_COLOR     CRGB::Yellow

// Squirrel
#define SQ_L_TAIL_CNT       8
#define SQ_M_TAIL_CNT       10
#define SQ_U_TAIL_CNT       12
#define SQ_M_BODY_CNT       14
#define SQ_LOWER_HEAD_CNT   8
#define SQ_R_OUT_EYE_CNT    3
#define SQ_NOSE_CNT         9
#define SQ_TOOTH_CNT        2
#define SQ_R_EYE_CNT        7
#define SQ_L_EYE_CNT        7
#define SQ_L_OUT_EYE_CNT    3
#define SQ_L_EAR_CNT        4
#define SQ_UPPER_HEAD_CNT   6
#define SQ_R_EAR_CNT        4
#define SQ_U_BODY_CNT       2
#define SQ_ARM_CNT          9
#define SQ_F_BODY_CNT       3
#define SQ_FOOT_CNT         5

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

#define SQ_BODY_COLOR    CRGB(100, 80, 0)
#define SQ_HEAD_COLOR    CRGB::DarkGoldenrod
#define SQ_TOOTH_COLOR   CRGB::IndianRed
#define SQ_EYE_COLOR     CRGB(0, 0, 60)

#define ANIMATION_ORIGINAL   1 //default colours, rainbow umbrellas
#define ANIMATION_SPREADON   2 //slowly light up all the leds in a spreading out pattern
#define ANIMATION_SPREADOFF  3 //slowly light up all the leds in a spreading out pattern
#define ANIMATION_LIGHTCHASE 4 //default colours, white led runs around the place
#define ANIMATION_FADEOUT    5 //leds on,  gradually get darker until off
#define ANIMATION_FADEIN     6 //leds off, gradulaly get brighter until on
#define ANIMATION_SPOTSON    7 //leds off, random ones get turned on until all on
#define ANIMATION_SPOTSOFF   8 //leds on,  random ones get turned off until all off
#define ANIMATION_NONE       9 //all default nothing else (gap between animations) //maybe just original?

#define ANIMATION_STATE_NEW 0
#define ANIMATION_STATE_RUNNING 1
#define ANIMATION_STATE_DONE 2

#define LIGHTCHASE_RANGE 5 //number of options
#define LIGHTCHASE_SQ 0
#define LIGHTCHASE_OWL 1
#define LIGHTCHASE_FOX 2
#define LIGHTCHASE_PENGUINS 3
#define LIGHTCHASE_SNOWMAN 4

// Owl
#define O_M_BODY_CNT      13
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
#define O_L_WING_CNT      33

#define O_START            0
#define O_R_FACE_WING_ST   O_START            + O_M_BODY_CNT + O_R_WING_IN_CNT + O_R_WING_OUT_CNT
#define O_R_EAR_ST         O_R_FACE_WING_ST   + O_R_FACE_CNT
#define O_HEAD_TOP_ST      O_R_EAR_ST         + O_R_EAR_CNT
#define O_L_EAR_ST         O_HEAD_TOP_ST      + O_HEAD_TOP_CNT
#define O_OUTER_EYE_ST     O_L_EAR_ST         + O_L_EAR_CNT
#define O_L_FACE_ST        O_OUTER_EYE_ST     + O_L_FACE_CNT 
#define O_BEAK_ST          O_L_FACE_ST        + O_L_OUT_EYE_CNT + O_R_OUT_EYE_CNT
#define O_R_IN_EYE_ST      O_BEAK_ST          + O_BEAK_CNT
#define O_EYES_ST          O_R_IN_EYE_ST      + O_R_IN_EYE_CNT
#define O_L_IN_EYE_ST      O_EYES_ST          + O_R_EYE_CNT + O_L_EYE_CNT
#define O_L_WING_ST        O_L_IN_EYE_ST      + O_L_IN_EYE_CNT
#define O_END              O_L_WING_ST        + O_L_WING_CNT

#define O_BODY_COLOR       CRGB::Blue
#define O_EAR_COLOR        CRGB::Gray
#define O_OUT_EYE_COLOR    CRGB(0,50,50)
#define O_EYE_COLOR        CRGB(40,40,40)
#define O_BEAK_COLOR       CRGB::DarkBlue

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
#define F_MID_LEG_ST     F_REAR_LEG_ST    + F_REAR_LEG_CNT
#define F_MID_BODY_ST    F_MID_LEG_ST     + F_MID_LEG_CNT
#define F_LEFT_MASK_ST   F_MID_BODY_ST      + F_MID_BODY_CNT
#define F_RIGHT_MASK_ST  F_LEFT_MASK_ST     + F_LEFT_MASK_CNT
#define F_LOWER_FACE_ST  F_RIGHT_MASK_ST    + F_RIGHT_MASK_CNT
#define F_L_HEAD_ST      F_LOWER_FACE_ST   + F_LOWER_FACE_CNT
#define F_R_HEAD_ST      F_L_HEAD_ST   + F_L_HEAD_CNT
#define F_R_EYE_ST       F_R_HEAD_ST       + F_R_HEAD_CNT
#define F_L_EYE_ST       F_R_EYE_ST       + F_R_EYE_CNT
#define F_L_EAR_ST       F_L_EYE_ST        + F_L_EYE_CNT
#define F_TOP_HEAD_ST    F_L_EAR_ST        + F_L_EAR_CNT
#define F_R_EAR_ST       F_TOP_HEAD_ST        + F_TOP_HEAD_CNT
#define F_R_BODY_ST      F_R_EAR_ST     + F_R_EAR_CNT
#define F_FR_LEG_ST      F_R_BODY_ST        + F_R_BODY_CNT
#define F_L_BODY_ST      F_FR_LEG_ST       + F_FR_LEG_CNT
#define F_END            F_L_BODY_ST       + F_L_BODY_CNT

#define F_BODY_COLOR     CRGB(255,38,0)//OrangeRed
#define F_TAIL_COLOR     CRGB(60,60,60)
#define F_MASK_COLOR     CRGB(60,60,60)
#define F_EYES_COLOR     CRGB(0,0,80)
#define F_NOSE_COLOR     CRGB::DarkOrange

#define T_TR_BTM_CNT       52
#define T_L_L_BRANCH_CNT   43
#define T_R_L_BRANCH_CNT   44
#define T_TR_MID_CNT       32
#define T_R_U_BRANCH_CNT   24
#define T_L_U_BRANCH_CNT   28
#define T_TR_TOP_CNT       36

#define T_START             0
#define T_END               T_TR_BTM_CNT + T_L_L_BRANCH_CNT + T_R_L_BRANCH_CNT + T_TR_MID_CNT + T_R_U_BRANCH_CNT + T_L_U_BRANCH_CNT + T_TR_TOP_CNT

#define T_COLOR         CRGB(0,30,0)//CRGB::Sienna//CRGB(90,20,0)//CRGB::Brown

//penguins leds neighbour node system (i.e each led has a neighbour so we can have light patterns travel around and look cool)
const uint8_t penguins_nodes[PENGUINS_END][4] = {
  {1,85,255,255}, //0
  {0,2,255,255},  //1
  {1,3,255,255},  //2
  {2,4,255,255},  //3
  {3,86,255,255}, //4
  {6,88,255,255}, //5
  {5,7,255,255},  //6
  {6,8,255,255}, //7
  {7,9,255,255}, //8
  {8,89,255,255}, //9
  {93,11,255,255}, //10
  {10,12,255,255}, //11
  {11,13,255,255}, //12
  {12,14,255,255}, //13
  {13,15,255,255}, //14
  {14,95,255,255}, //15
  {95,96,17,255}, //16
  {16,18,255,255}, //17
  {17,19,26,27}, //18
  {18,20,33,255}, //19
  {19,36,79,255}, //20
  {22,37,78,79}, //21
  {21,37,23,255}, //22
  {22,26,24,55}, //23
  {23,25,255,255}, //24
  {24,96,255,255}, //25
  {23,18,27,255}, //26
  {18,26,28,255}, //27
  {27,29,255,255}, //28
  {28,30,255,255}, //29
  {31,29,255,255}, //30
  {32,30,255,255}, //31
  {31,35,255,255}, //32
  {19,34,255,255}, //33
  {33,35,255,255}, //34
  {32,34,36,255}, //35
  {35,37,255,255}, //36
  {36,21,22,255}, //37
  {39,78,255,255}, //38
  {63,38,40,255}, //39
  {39,41,255,255}, //40
  {43,42,40,255}, //41
  {41,97,96,255}, //42
  {41,44,255,255}, //43
  {43,45,255,255}, //44
  {44,46,255,255}, //45
  {45,47,255,255}, //46
  {46,48,255,255}, //47
  {47,49,255,255}, //48
  {48,50,255,255}, //49
  {49,51,255,255}, //50
  {50,52,255,255}, //51
  {51,53,255,255}, //52
  {52,54,255,255}, //53
  {53,55,255,255}, //54
  {54,56,255,255}, //55
  {55,57,255,255}, //56
  {56,58,255,255}, //57
  {57,59,255,255}, //58
  {58,60,255,255}, //59
  {59,61,255,255}, //60
  {60,62,255,255}, //61
  {61,63,255,255}, //62
  {62,39,255,255}, //63
  {81,65,255,255}, //64
  {64,66,255,255}, //65
  {65,67,255,255}, //66
  {66,68,255,255}, //67
  {79,67,255,255}, //68
  {76,70,77,111}, //69
  {69,71,255,255}, //70
  {70,72,255,255}, //71
  {71,98,255,255}, //72
  {99,74,98,255}, //73
  {73,75,255,255}, //74
  {74,76,255,255}, //75
  {75,111,69,255}, //76
  {69,78,76,255}, //77
  {38,77,21,79}, //78
  {68,78,20,80}, //79
  {79,81,255,255}, //80
  {64,80,82,255}, //81
  {81,83,255,255}, //82
  {82,84,255,255}, //83
  {83,85,255,255}, //84
  {0,84,86,255}, //85
  {4,85,87,255}, //86
  {86,88,255,255}, //87
  {87,5,89,255}, //88
  {9,88,90,255}, //89
  {89,91,255,255}, //90
  {90,92,255,255}, //91
  {91,93,255,255}, //92
  {10,92,94,255}, //93
  {93,95,255,255}, //94
  {15,16,94,96}, //95
  {95,25,97,43}, //96
  {42,96,98,255}, //97
  {72,99,97,255}, //98
  {73,98,100,255}, //99
  {99,101,255,255}, //100
  {100,102,117,255}, //101
  {101,103,159,255}, //102
  {102,104,112,255}, //103
  {103,105,113,255}, //104
  {104,106,255,255}, //105
  {107,108,105,255}, //106
  {106,108,255,255}, //107
  {107,109,105,255}, //108
  {108,110,255,255}, //109
  {109,111,255,255}, //110
  {110,76,77,69}, //111
  {158,159,113,103}, //112
  {112,114,104,255}, //113
  {113,115,255,255}, //114
  {114,116,255,255}, //115
  {115,157,158,255}, //116
  {160,118,101,255}, //117
  {117,119,255,255}, //118
  {118,120,255,255}, //119
  {119,161,162,255}, //120
  {122,164,165,255}, //121
  {121,123,255,255}, //122
  {122,124,255,255}, //123
  {123,125,255,255}, //124
  {124,126,255,255}, //125
  {125,167,255,255}, //126
  {128,167,255,255}, //127
  {127,129,255,255}, //128
  {128,130,136,255}, //129
  {129,131,141,146}, //130
  {130,152,146,175}, //131
  {175,133,255,255}, //132
  {132,134,255,255}, //133
  {133,135,255,255}, //134
  {134,168,255,255}, //135
  {129,137,255,255}, //136
  {136,138,255,255}, //137
  {137,139,255,255}, //138
  {138,140,255,255}, //139
  {139,143,144,255}, //140
  {130,142,255,255}, //141
  {141,143,255,255}, //142
  {140,142,144,255}, //143
  {140,143,145,255}, //144
  {144,146,255,255}, //145
  {145,130,131,255}, //146
  {148,154,155,255}, //147
  {147,149,255,255}, //148
  {148,150,255,255}, //149
  {149,151,255,255}, //150
  {150,152,255,255}, //151
  {153,131,175,255}, //152
  {152,131,154,175}, //153
  {153,155,147,255}, //154
  {154,147,156,255}, //155
  {155,157,255,255}, //156
  {156,158,116,255}, //157
  {157,159,112,255}, //158
  {158,160,102,255}, //159
  {159,117,161,255}, //160
  {160,162,120,255}, //161
  {161,120,163,255}, //162
  {162,164,255,255}, //163
  {163,165,121,255}, //164
  {164,166,255,255}, //165
  {165,167,255,255}, //166
  {126,127,166,168}, //167
  {135,167,186,169}, //168
  {170,192,168,255}, //169
  {187,171,169,255}, //170
  {172,170,255,255}, //171
  {171,176,173,255}, //172
  {172,174,181,255}, //173
  {182,175,180,255}, //174
  {174,132,153,152}, //175
  {172,177,181,255}, //176
  {176,178,255,255}, //177
  {177,179,180,255}, //178
  {178,180,174,255}, //179
  {174,179,181,255}, //180
  {180,176,173,255}, //181
  {174,183,255,255}, //182
  {182,213,184,255}, //183
  {183,185,255,255}, //184
  {184,186,193,255}, //185
  {185,168,169,191}, //186
  {170,192,188,255}, //187
  {187,189,255,255}, //188
  {188,190,255,255}, //189
  {189,191,168,255}, //190
  {190,192,169,255}, //191
  {187,169,191,255}, //192
  {185,194,255,255}, //193
  {193,195,255,255}, //194
  {194,196,255,255}, //195
  {195,197,255,255}, //196
  {196,198,255,255}, //197
  {197,199,255,255}, //198
  {198,200,255,255}, //199
  {199,201,255,255}, //200
  {200,202,255,255}, //201
  {201,203,255,255}, //202
  {202,204,255,255}, //203
  {203,205,255,255}, //204
  {204,206,255,255}, //205
  {205,207,255,255}, //206
  {206,208,255,255}, //207
  {207,209,255,255}, //208
  {208,210,255,255}, //209
  {209,211,255,255}, //210
  {210,212,255,255}, //211
  {211,213,255,255}, //212
  {212,183,255,255} //213
  // {213,183,255,255} //214
};

const uint8_t penguin_umbrella_nodes[P_UMBRELLA_END][4] = {
  {1,255,255,255}, //0
  {0,2,255,255}, //1
  {1,3,255,255}, //2
  {2,4,255,255}, //3
  {3,5,255,255}, //4
  {4,6,255,255}, //5
  {5,7,255,255}, //6
  {6,8,255,255}, //7
  {7,78,255,255}, //8
  {10,81,255,255}, //9
  {9,11,255,255}, //10
  {10,12,255,255}, //11
  {11,13,255,255}, //12
  {12,14,255,255}, //13
  {13,15,255,255}, //14
  {14,16,255,255}, //15
  {15,17,34,55}, //16
  {16,18,255,255}, //17
  {17,19,255,255}, //18
  {18,20,255,255}, //19  
  {19,21,255,255}, //20
  {20,22,255,255}, //21  
  {21,23,255,255}, //22
  {22,24,255,255}, //23
  {23,25,255,255}, //24
  {24,26,255,255}, //25
  {25,72,255,255}, //26
  {75,28,255,255}, //27
  {27,29,255,255}, //28
  {28,30,255,255}, //29
  {29,31,255,255}, //30
  {30,32,255,255}, //31  
  {31,33,255,255}, //32
  {32,34,255,255}, //33
  {33,35,16,55}, //34
  {34,36,255,255}, //35
  {35,37,255,255}, //36
  {36,38,255,255}, //37
  {37,39,255,255}, //38
  {38,40,255,255}, //39
  {39,41,255,255}, //40
  {40,42,255,255}, //41  
  {41,43,255,255}, //42
  {42,84,255,255}, //43
  {87,45,255,255}, //44
  {44,46,255,255}, //45
  {45,47,255,255}, //46
  {46,48,255,255}, //47
  {47,49,255,255}, //48
  {48,50,255,255}, //49
  {49,51,255,255}, //50
  {50,52,255,255}, //51  
  {51,53,255,255}, //52
  {52,54,255,255}, //53
  {53,55,255,255}, //54
  {54,56,16,34}, //55
  {55,57,255,255}, //56
  {56,58,255,255}, //57
  {57,59,255,255}, //58
  {58,60,255,255}, //59
  {59,61,255,255}, //60
  {60,62,255,255}, //61  
  {61,63,255,255}, //62
  {62,64,255,255}, //63
  {63,65,255,255}, //64
  {64,66,255,255}, //65
  {65,67,255,255}, //66
  {66,68,255,255}, //67
  {67,69,255,255}, //68
  {68,70,255,255}, //69
  {69,71,255,255}, //70
  {70,72,255,255}, //71  
  {26,71,73,255}, //72
  {72,74,255,255}, //73
  {73,75,255,255}, //74
  {27,74,76,255}, //75
  {75,77,255,255}, //76
  {76,78,255,255}, //77
  {8,77,79,255}, //78
  {78,80,255,255}, //79
  {79,81,255,255}, //80
  {9,80,82,255}, //81  
  {81,83,255,255}, //82
  {82,84,255,255}, //83
  {43,83,85,255}, //84
  {84,86,255,255}, //85
  {85,87,255,255}, //86
  {44,86,255,255} //87
};

const uint8_t squirrel_nodes[SQ_END][4] = {
  {1,255,255,255}, //0
  {0,18,2,255}, //1
  {1,3,255,255}, //2
  {2,4,255,255}, //3
  {3,5,255,255}, //4
  {4,6,255,255}, //5
  {5,7,255,255}, //6
  {6,37,255,255}, //7
  {38,9,255,255}, //8
  {8,10,255,255}, //9
  {9,11,255,255}, //10
  {10,12,255,255}, //11
  {11,13,255,255}, //12
  {12,14,255,255}, //13
  {13,15,255,255}, //14
  {14,16,255,255}, //15
  {15,17,255,255}, //16
  {16,18,255,255}, //17
  {17,19,1,255}, //18
  {18,20,255,255}, //19
  {19,21,255,255}, //20
  {20,22,255,255}, //21
  {21,23,255,255}, //22
  {22,24,255,255}, //23
  {23,25,255,255}, //24
  {24,26,255,255}, //25
  {25,27,255,255}, //26
  {26,28,255,255}, //27
  {27,29,255,255}, //28
  {28,40,255,255}, //29
  {31,255,255,255}, //30
  {30,32,255,255}, //31
  {31,33,255,255}, //32
  {32,34,110,255}, //33
  {33,35,115,255}, //34
  {34,36,255,255}, //35
  {35,37,111,255}, //36
  {36,38,7,255}, //37
  {37,39,8,255}, //38
  {38,40,255,255}, //39
  {39,41,29,255}, //40
  {40,42,255,255}, //41
  {41,43,255,255}, //42
  {42,47,99,255}, //43
  {82,87,45,74}, //44
  {44,46,255,255}, //45
  {45,47,255,255}, //46
  {46,48,43,99}, //47
  {47,49,99,255}, //48
  {48,50,255,255}, //49
  {49,51,255,255}, //50
  {50,52,92,255}, //51
  {51,53,255,255}, //52
  {52,67,54,255}, //53
  {53,57,255,255}, //54
  {72,63,255,255}, //55
  {58,63,60,62}, //56
  {54,62,61,80}, //57
  {56,61,255,255}, //58
  {60,79,255,255}, //59
  {59,56,65,255}, //60
  {58,57,255,255}, //61
  {57,56,255,255}, //62
  {55,56,64,255}, //63
  {63,65,255,255}, //64
  {64,60,255,255}, //65
  {53,67,255,255}, //66
  {66,68,255,255}, //67
  {67,69,255,255}, //68
  {68,70,255,255}, //69
  {69,71,255,255}, //70
  {70,72,255,255}, //71
  {71,55,255,255}, //72
  {73,59,255,255}, //73
  {73,75,255,255}, //74
  {74,76,255,255}, //75
  {75,77,255,255}, //76
  {76,78,255,255}, //77
  {77,79,255,255}, //78
  {78,82,255,255}, //79
  {57,81,255,255}, //80
  {80,82,82,255}, //81
  {81,44,255,255}, //82
  {88,84,255,255}, //83
  {83,85,255,255}, //84
  {84,86,255,255}, //85
  {85,87,255,255}, //86
  {44,88,86,255}, //87
  {83,87,255,255}, //88
  {88,90,255,255}, //89
  {89,91,255,255}, //90
  {90,92,93,255}, //91
  {51,91,96,255}, //92
  {91,94,255,255}, //93
  {93,95,255,255}, //94
  {94,96,255,255}, //95
  {95,92,255,255}, //96
  {48,98,255,255}, //97
  {97,101,255,255}, //98
  {43,47,100,255}, //99
  {99,101,255,255}, //100
  {100,102,98,255}, //101
  {101,103,255,255}, //102
  {102,104,255,255}, //103
  {103,105,255,255}, //104
  {104,106,108,255}, //105
  {105,107,255,255}, //106
  {106,255,255,255}, //107
  {105,109,255,255}, //108
  {108,110,255,255}, //109
  {109,33,255,255}, //110
  {36,112,255,255}, //111
  {111,113,255,255}, //112
  {112,114,255,255}, //113
  {113,115,255,255}, //114
  {34,114,255,255} //115
};

const uint8_t snowman_umbrella_nodes[S_UMBRELLA_END][4] = {
  {1,255,255,255}, //0
  {0,2,255,255}, //1
  {1,3,255,255}, //2
  {2,4,255,255}, //3
  {3,5,255,255}, //4
  {4,6,255,255}, //5
  {5,7,255,255}, //6
  {6,8,255,255}, //7
  {7,9,255,255}, //8
  {8,123,255,255}, //9
  {127,11,255,255}, //10
  {10,12,255,255}, //11
  {11,13,255,255}, //12
  {12,14,255,255}, //13
  {13,15,255,255}, //14
  {14,16,255,255}, //15
  {15,17,255,255}, //16
  {16,18,255,255}, //17
  {17,19,255,255}, //18
  {18,20,255,255}, //19
  {19,21,255,255}, //20
  {20,22,255,255}, //21
  {87,23,21,50}, //22
  {22,24,255,255}, //23
  {23,25,255,255}, //24
  {24,26,255,255}, //25
  {25,27,255,255}, //26
  {26,28,255,255}, //27
  {27,29,255,255}, //28
  {28,30,255,255}, //29
  {29,31,255,255}, //30
  {30,32,255,255}, //31
  {31,33,255,255}, //32
  {32,34,255,255}, //33
  {33,35,255,255}, //34
  {34,36,255,255}, //35
  {35,37,255,255}, //36
  {36,38,255,255}, //37
  {37,111,255,255}, //38
  {118,40,255,255}, //39
  {39,41,255,255}, //40
  {40,42,255,255}, //41
  {41,43,255,255}, //42
  {42,44,255,255}, //43
  {43,45,255,255}, //44
  {44,46,255,255}, //45
  {45,47,255,255}, //46
  {46,48,255,255}, //47
  {47,49,255,255}, //48
  {48,50,255,255}, //49
  {49,51,22,87}, //50
  {50,52,255,255}, //51
  {51,53,255,255}, //52
  {52,54,255,255}, //53
  {53,55,255,255}, //54
  {54,56,255,255}, //55
  {55,57,255,255}, //56
  {56,58,255,255}, //57
  {57,59,255,255}, //58
  {58,60,255,255}, //59
  {59,61,255,255}, //60
  {60,62,255,255}, //61
  {61,63,255,255}, //62
  {62,64,255,255}, //63
  {63,65,255,255}, //64
  {64,66,255,255}, //65
  {65,67,255,255}, //66
  {66,134,255,255}, //67
  {139,69,255,255}, //68
  {68,70,255,255}, //69
  {69,71,255,255}, //70
  {70,72,255,255}, //71
  {71,73,255,255}, //72
  {72,74,255,255}, //73
  {73,75,255,255}, //74
  {74,76,255,255}, //75
  {75,77,255,255}, //76
  {76,78,255,255}, //77
  {77,79,255,255}, //78
  {78,80,255,255}, //79
  {79,81,255,255}, //80
  {80,82,255,255}, //81
  {81,83,255,255}, //82
  {82,84,255,255}, //83
  {83,85,255,255}, //84
  {84,86,255,255}, //85
  {85,87,22,50}, //86
  {86,88,50,255}, //87
  {87,89,255,255}, //88
  {88,90,255,255}, //89
  {89,91,255,255}, //90
  {90,92,255,255}, //91
  {91,93,255,255}, //92
  {92,94,255,255}, //93
  {93,95,255,255}, //94
  {94,96,255,255}, //95
  {95,97,255,255}, //96
  {96,98,255,255}, //97
  {97,99,255,255}, //98
  {98,100,255,255}, //99
  {99,101,255,255}, //100
  {100,102,255,255}, //101
  {101,103,255,255}, //102
  {102,104,255,255}, //103
  {103,105,255,255}, //104
  {104,106,255,255}, //105
  {105,107,255,255}, //106
  {106,108,255,255}, //107
  {107,109,255,255}, //108
  {108,110,255,255}, //109
  {109,111,255,255}, //110
  {110,112,38,255}, //111
  {111,113,255,255}, //112
  {112,114,255,255}, //113
  {113,115,255,255}, //114
  {114,116,255,255}, //115
  {115,117,255,255}, //116
  {116,118,39,255}, //117
  {117,119,255,255}, //118
  {118,120,255,255}, //119
  {119,121,255,255}, //120
  {120,122,255,255}, //121
  {121,123,255,255}, //122
  {122,124,9,255}, //123
  {123,125,255,255}, //124
  {124,126,255,255}, //125
  {125,127,255,255}, //126
  {126,128,10,255}, //127
  {127,129,255,255}, //128
  {128,130,255,255}, //129
  {129,131,255,255}, //130
  {130,132,255,255}, //131
  {131,133,255,255}, //132
  {132,134,255,255}, //133
  {133,135,67,255}, //134
  {134,136,255,255}, //135
  {135,137,255,255}, //136
  {136,138,255,255}, //137
  {137,139,255,255}, //138
  {138,68,255,255} //139
};

const uint8_t fox_nodes[F_END][4] = {
  {29,1,255,255}, //0
  {0,2,255,255}, //1
  {1,3,255,255}, //2
  {2,4,255,255}, //3
  {3,5,255,255}, //4
  {4,6,255,255}, //5
  {5,7,255,255}, //6
  {6,8,255,255}, //7
  {7,9,255,255}, //8
  {8,10,255,255}, //9
  {9,11,255,255}, //10
  {10,12,255,255}, //11
  {11,13,255,255}, //12
  {12,14,255,255}, //13
  {13,15,255,255}, //14
  {14,20,255,255}, //15
  {158,17,255,255}, //16
  {16,18,255,255}, //17
  {17,19,255,255}, //18
  {18,29,255,255}, //19
  {15,19,21,255}, //20
  {20,22,255,255}, //21
  {21,23,255,255}, //22
  {22,24,255,255}, //23
  {23,25,255,255}, //24
  {24,26,255,255}, //25
  {25,27,255,255}, //26
  {26,28,255,255}, //27
  {27,29,255,255}, //28
  {0,28,30,255}, //29
  {29,31,255,255}, //30
  {30,32,255,255}, //31
  {31,33,255,255}, //32
  {32,34,255,255}, //33
  {33,35,255,255}, //34
  {34,36,255,255}, //35
  {35,37,255,255}, //36
  {36,38,159,255}, //37
  {37,39,255,255}, //38
  {38,40,255,255}, //39
  {39,41,57,255}, //40
  {40,42,255,255}, //41
  {41,43,255,255}, //42
  {42,44,255,255}, //43
  {43,45,255,255}, //44
  {44,46,54,255}, //45
  {45,47,255,255}, //46
  {46,48,255,255}, //47
  {47,49,255,255}, //48
  {48,50,255,255}, //49
  {49,51,255,255}, //50
  {50,52,255,255}, //51
  {51,53,255,255}, //52
  {52,255,255,255}, //53
  {45,55,255,255}, //54
  {54,56,255,255}, //55
  {55,57,255,255}, //56
  {56,58,41,255}, //57
  {57,59,255,255}, //58
  {58,60,137,255}, //59
  {59,61,255,255}, //60
  {60,62,255,255}, //61
  {61,63,255,255}, //62
  {62,64,255,255}, //63
  {63,65,133,134}, //64
  {64,66,255,255}, //65
  {65,67,255,255}, //66
  {66,68,255,255}, //67
  {67,69,255,255}, //68
  {68,70,147,255}, //69
  {69,71,89,90}, //70
  {70,72,89,90}, //71
  {71,73,255,255}, //72
  {72,74,105,255}, //73
  {73,75,255,255}, //74
  {74,86,255,255}, //75
  {85,77,255,255}, //76
  {76,78,255,255}, //77
  {77,79,255,255}, //78
  {78,80,98,255}, //79
  {79,81,255,255}, //80
  {80,97,255,255}, //81
  {97,83,255,255}, //82
  {82,84,104,255}, //83
  {83,85,255,255}, //84
  {84,86,76,255}, //85
  {75,85,87,255}, //86
  {86,88,255,255}, //87
  {111,87,89,255}, //88
  {88,70,71,90}, //89
  {91,71,89,70}, //90
  {112,90,92,255}, //91
  {91,93,255,255}, //92
  {92,117,255,255}, //93
  {95,120,255,255}, //94
  {94,96,255,255}, //95
  {95,97,125,255}, //96
  {96,81,82,126}, //97
  {79,99,255,255}, //98
  {98,100,255,255}, //99
  {99,101,255,255}, //100
  {100,102,255,255}, //101
  {101,103,255,255}, //102
  {102,104,255,255}, //103
  {103,83,255,255}, //104
  {73,106,255,255}, //105
  {105,107,255,255}, //106
  {106,108,255,255}, //107
  {107,109,255,255}, //108
  {108,110,255,255}, //109
  {109,111,255,255}, //110
  {110,88,255,255}, //111
  {91,113,255,255}, //112
  {112,114,255,255}, //113
  {113,115,255,255}, //114
  {114,116,255,255}, //115
  {115,117,255,255}, //116
  {116,93,118,255}, //117
  {117,119,255,255}, //118
  {118,120,255,255}, //119
  {119,121,94,255}, //120
  {120,122,255,255}, //121
  {121,123,255,255}, //122
  {122,124,255,255}, //123
  {123,125,255,255}, //124
  {124,97,255,255}, //125
  {97,127,255,255}, //126
  {126,128,255,255}, //127
  {127,129,255,255}, //128
  {128,130,255,255}, //129
  {129,131,146,255}, //130
  {130,132,255,255}, //131
  {131,133,255,255}, //132
  {132,64,134,255}, //133
  {133,64,135,255}, //134
  {134,136,255,255}, //135
  {135,137,255,255}, //136
  {59,136,138,255}, //137
  {137,139,255,255}, //138
  {138,140,255,255}, //139
  {139,141,255,255}, //140
  {140,142,255,255}, //141
  {141,143,255,255}, //142
  {142,144,255,255}, //143
  {143,145,255,255}, //144
  {144,146,255,255}, //145
  {145,130,255,255}, //146
  {69,148,255,255}, //147
  {147,149,255,255}, //148
  {148,150,255,255}, //149
  {149,151,255,255}, //150
  {150,152,255,255}, //151
  {151,153,255,255}, //152
  {152,154,255,255}, //153
  {153,155,255,255}, //154
  {154,156,255,255}, //155
  {155,157,255,255}, //156
  {156,158,255,255}, //157
  {157,159,16,255}, //158
  {158,36,37,255}  //159
};


const uint16_t snowman_nodes[SNOWMAN_END][4] = {
  {1,114,1023,1023}, //0
  {0,2,1023,1023}, //1
  {1,3,1023,1023}, //2
  {2,4,1023,1023}, //3
  {3,5,1023,1023}, //4
  {4,6,1023,1023}, //5
  {5,7,1023,1023}, //6
  {6,8,1023,1023}, //7
  {7,9,1023,1023}, //8
  {8,10,1023,1023}, //9
  {9,11,1023,1023}, //10
  {10,12,1023,1023}, //11
  {11,13,1023,1023}, //12
  {12,14,1023,1023}, //13
  {13,15,1023,1023}, //14
  {14,16,1023,1023}, //15
  {15,17,1023,1023}, //16
  {16,18,1023,1023}, //17
  {17,19,1023,1023}, //18
  {18,20,1023,1023}, //19
  {19,21,1023,1023}, //20
  {20,22,1023,1023}, //21
  {21,23,1023,1023}, //22
  {22,24,1023,1023}, //23
  {23,25,1023,1023}, //24
  {24,26,1023,1023}, //25
  {25,27,1023,1023}, //26
  {26,28,1023,1023}, //27
  {27,29,1023,1023}, //28
  {28,30,1023,1023}, //29
  {29,31,1023,1023}, //30
  {30,32,1023,1023}, //31
  {31,33,1023,1023}, //32
  {32,34,1023,1023}, //33
  {33,35,1023,1023}, //34
  {34,36,1023,1023}, //35
  {35,37,1023,1023}, //36
  {36,38,1023,1023}, //37
  {37,39,1023,1023}, //38
  {38,40,1023,1023}, //39
  {39,41,1023,1023}, //40
  {40,42,1023,1023}, //41
  {41,85,1023,1023}, //42
  {44,1023,1023,1023}, //43
  {43,45,1023,1023}, //44
  {44,46,1023,1023}, //45
  {45,47,1023,1023}, //46
  {46,48,1023,1023}, //47
  {47,49,1023,1023}, //48
  {48,50,1023,1023}, //49
  {49,51,1023,1023}, //50
  {50,52,1023,1023}, //51
  {51,53,1023,1023}, //52
  {52,54,1023,1023}, //53
  {53,55,1023,1023}, //54
  {54,56,1023,1023}, //55
  {55,57,1023,1023}, //56
  {56,58,1023,1023}, //57
  {57,59,1023,1023}, //58
  {58,60,1023,1023}, //59
  {59,61,1023,1023}, //60
  {60,62,1023,1023}, //61
  {61,63,1023,1023}, //62
  {62,64,1023,1023}, //63
  {63,65,1023,1023}, //64
  {64,66,1023,1023}, //65
  {65,67,1023,1023}, //66
  {66,1023,1023,1023}, //67
  {133,69,1023,1023}, //0
  {68,70,1023,1023}, //1
  {69,71,43,1023}, //2
  {70,72,1023,1023}, //3
  {71,73,1023,1023}, //4
  {72,74,1023,1023}, //5
  {73,75,1023,1023}, //6
  {74,76,1023,1023}, //7
  {75,77,1023,1023}, //8
  {76,78,1023,1023}, //9
  {77,79,1023,1023}, //10
  {78,80,1023,1023}, //11
  {79,81,1023,1023}, //12
  {80,82,96,1023}, //13
  {81,83,1023,1023}, //14
  {82,84,1023,1023}, //15
  {83,85,1023,1023}, //16
  {84,86,42,1023}, //17
  {85,87,1023,1023}, //18
  {86,88,102,1023}, //19
  {87,89,1023,1023}, //20
  {88,90,1023,1023}, //21
  {89,91,1023,1023}, //22
  {90,92,1023,1023}, //23
  {91,93,1023,1023}, //24
  {92,94,1023,1023}, //25
  {93,95,97,1023}, //26
  {94,96,1023,1023}, //27
  {95,81,1023,1023}, //28
  {94,98,1023,1023}, //29
  {95,99,1023,1023}, //30
  {98,100,1023,1023}, //31
  {99,101,1023,1023}, //32
  {100,67,1023,1023}, //33
  {87,103,1023,1023}, //34
  {102,104,1023,1023}, //35
  {103,105,1023,1023}, //36
  {104,106,1023,1023}, //37
  {105,107,1023,1023}, //38
  {106,108,1023,1023}, //39
  {107,109,1023,1023}, //40
  {108,110,1023,1023}, //41
  {109,111,1023,1023}, //42
  {110,112,1023,1023}, //43
  {111,113,1023,1023}, //44
  {112,114,1023,1023}, //45
  {113,115,1023,1023}, //46
  {114,116,0,1023}, //47
  {115,117,1023,1023}, //48
  {116,118,195,1023}, //49
  {117,119,1023,1023}, //50
  {118,120,1023,1023}, //51
  {119,121,1023,1023}, //52
  {120,122,167,1023}, //53
  {121,123,1023,1023}, //54
  {122,124,1023,1023}, //55
  {123,125,143,1023}, //56
  {124,126,223,1023}, //57
  {125,127,1023,1023}, //58
  {126,128,158,1023}, //59
  {127,129,166,1023}, //60
  {128,130,1023,1023}, //61
  {129,131,1023,1023}, //62
  {130,132,1023,1023}, //63
  {131,133,231,1023}, //64
  {132,134,68,1023}, //65
  {133,135,1023,1023}, //66
  {134,136,1023,1023}, //67
  {135,137,1023,1023}, //68
  {136,138,1023,1023}, //69
  {137,139,1023,1023}, //70
  {138,140,164,1023}, //71
  {139,141,160,157}, //72
  {140,142,1023,1023}, //73
  {141,143,144,1023}, //74
  {142,123,1023,1023}, //75
  {142,145,1023,1023}, //76
  {144,146,1023,1023}, //77
  {145,147,1023,1023}, //78
  {146,148,1023,1023}, //79
  {147,149,1023,1023}, //80
  {148,150,1023,1023}, //81
  {149,151,1023,1023}, //82
  {150,152,1023,1023}, //83
  {151,153,1023,1023}, //84
  {152,154,1023,1023}, //85
  {153,155,1023,1023}, //86
  {154,156,1023,1023}, //87
  {155,157,1023,1023}, //88
  {156,140,1023,1023}, //89
  {127,159,1023,1023}, //90
  {158,160,1023,1023}, //91
  {159,161,140,1023}, //92
  {160,162,1023,1023}, //93
  {161,163,1023,1023}, //94
  {162,164,1023,1023}, //95
  {163,165,1023,1023}, //96
  {164,166,1023,1023}, //97
  {165,167,1023,1023}, //98
  {166,168,1023,1023}, //99
  {167,169,1023,1023}, //100
  {168,170,1023,1023}, //101
  {169,171,1023,1023}, //102
  {170,172,1023,1023}, //103
  {171,173,1023,1023}, //104
  {172,174,1023,1023}, //105
  {173,175,139,1023}, //106
  {174,176,1023,1023}, //107
  {175,128,1023,1023}, //108
  {121,178,1023,1023}, //109
  {177,179,1023,1023}, //110
  {178,180,1023,1023}, //111
  {179,181,1023,1023}, //112
  {180,182,196,1023}, //113
  {181,183,1023,1023}, //114
  {182,184,1023,1023}, //115
  {183,185,1023,1023}, //116
  {184,186,1023,1023}, //117
  {185,187,1023,1023}, //118
  {186,188,1023,1023}, //119
  {187,189,1023,1023}, //120
  {188,190,1023,1023}, //121
  {189,191,1023,1023}, //122
  {190,192,1023,1023}, //123
  {191,193,1023,1023}, //124
  {192,194,195,1023}, //125
  {193,197,1023,1023}, //126
  {194,196,1023,1023}, //127
  {195,196,1023,1023}, //128  
  {193, 198, 1023, 1023}, //129
  {197, 199, 1023, 1023}, //130
  {198, 200, 1023, 1023}, //131
  {199, 201, 1023, 1023}, //132
  {200, 202, 1023, 1023}, //133
  {201, 203, 1023, 1023}, //134
  {202, 204, 1023, 1023}, //135
  {203, 205, 1023, 1023}, //136
  {204, 117, 1023, 1023}, //137
  {234,207,1023,1023}, //0
  {206,208,1023,1023}, //1
  {207,209,313,1023}, //2
  {208,210,1023,1023}, //3
  {209,211,1023,1023}, //4
  {210,212,1023,1023}, //5
  {211,213,1023,1023}, //6
  {212,214,1023,1023}, //7
  {213,215,1023,1023}, //8
  {214,216,1023,1023}, //9
  {215,217,1023,1023}, //10
  {216,218,307,1023}, //11
  {217,219,1023,1023}, //12
  {218,220,257,1023},  //13
  {219,221,1023,1023}, //14
  {220,222,1023,1023}, //15
  {221,223,288,1023}, //16
  {222,224,125,1023}, //17
  {223,225,1023,1023}, //18
  {224,226,1023,1023}, //19
  {225,227,1023,1023}, //20
  {226,228,1023,1023}, //21
  {227,229,1023,1023}, //22
  {228,230,1023,1023}, //23
  {229,231,1023,1023}, //24
  {230,232,132,281},  //25
  {231,233,1023,1023}, //26
  {232,234,1023,1023}, //27
  {233,235,206,1023},  //28
  {234,236,1023,1023}, //29
  {235,237,1023,1023}, //30
  {236,238,1023,1023}, //31
  {237,239,1023,1023}, //32
  {238,240,1023,1023}, //33
  {239,241,1023,1023}, //34
  {240,242,1023,1023}, //35
  {241,243,280,1023},  //36
  {242,244,1023,1023}, //37
  {243,245,1023,1023}, //38
  {244,246,1023,1023}, //39
  {245,247,1023,1023}, //40
  {246,248,1023,1023}, //41
  {247,249,1023,1023}, //42
  {248,250,1023,1023}, //43
  {249,251,1023,1023}, //44
  {250,252,258,1023},  //45
  {251,253,1023,1023}, //46
  {252,254,1023,1023}, //47
  {253,255,1023,1023}, //48
  {254,256,1023,1023}, //49
  {255,257,1023,1023}, //50
  {256,219,1023,1023}, //51
  {251,259,1023,1023}, //52
  {258,260,1023,1023}, //53
  {259,261,1023,1023}, //54
  {260,262,1023,1023}, //55
  {261,263,1023,1023}, //56
  {262,264,1023,1023}, //57
  {263,265,1023,1023}, //58
  {264,266,1023,1023}, //59
  {265,267,1023,1023}, //60
  {266,268,1023,1023}, //61
  {267,269,1023,1023}, //62
  {268,270,1023,1023}, //63
  {269,271,1023,1023}, //64
  {270,272,1023,1023}, //65
  {271,273,1023,1023}, //66
  {272,274,1023,1023}, //67
  {273,275,1023,1023}, //68
  {274,276,1023,1023}, //69
  {275,277,1023,1023}, //70
  {276,278,1023,1023}, //71
  {277,279,1023,1023}, //72
  {278,280,1023,1023}, //73
  {279,241,1023,1023}, //74
  {230,282,1023,1023}, //75
  {281,283,1023,1023}, //76
  {282,284,1023,1023}, //77
  {283,285,1023,1023}, //78
  {284,286,1023,1023}, //79
  {285,287,1023,1023}, //80
  {286,288,1023,1023}, //81
  {287,222,1023,1023}, //82
  {300,299,294,1023}, //83
  {299,298,1023,1023}, //84
  {298,297,1023,1023}, //85 //TODO CHECK THE LEDS FOR THE HEAD
  {297,296,1023,1023}, //86
  {296,295,1023,1023}, //87
  {289,295,1023,1023}, //88
  {294,293,1023,1023}, //89
  {293,292,1023,1023}, //90
  {291,292,308,1023}, //91
  {291,290,301,1023}, //92
  {290,289,1023,1023}, //93
  {289,1023,1023,1023}, //94
  {298,302,1023,1023}, //95
  {301,303,1023,1023}, //96
  {302,304,1023,1023}, //97
  {303,305,1023,1023}, //98
  {304,306,1023,1023}, //99
  {305,307,1023,1023}, //100
  {306,217,1023,1023}, //101
  {297,309,1023,1023}, //102
  {308,310,1023,1023}, //103
  {309,311,1023,1023}, //104
  {310,312,1023,1023}, //105 
  {311,313,1023,1023}, //104
  {312,208,1023,1023} //105 
  // {313,208,1023,1023}  //106
};

// const uint8_t snowman_btm_nodes[S_B_BODY_END+1][4] = {
  // {1,255,255,255}, //0
  // {0,2,255,255}, //1
  // {1,3,255,255}, //2
  // {2,4,255,255}, //3
  // {3,5,255,255}, //4
  // {4,6,255,255}, //5
  // {5,7,255,255}, //6
  // {6,8,255,255}, //7
  // {7,9,255,255}, //8
  // {8,10,255,255}, //9
  // {9,11,255,255}, //10
  // {10,12,255,255}, //11
  // {11,13,255,255}, //12
  // {12,14,255,255}, //13
  // {13,15,255,255}, //14
  // {14,16,255,255}, //15
  // {15,17,255,255}, //16
  // {16,18,255,255}, //17
  // {17,19,255,255}, //18
  // {18,20,255,255}, //19
  // {19,21,255,255}, //20
  // {20,22,255,255}, //21
  // {21,23,255,255}, //22
  // {22,24,255,255}, //23
  // {23,25,255,255}, //24
  // {24,26,255,255}, //25
  // {25,27,255,255}, //26
  // {26,28,255,255}, //27
  // {27,29,255,255}, //28
  // {28,30,255,255}, //29
  // {29,31,255,255}, //30
  // {30,32,255,255}, //31
  // {31,33,255,255}, //32
  // {32,34,255,255}, //33
  // {33,35,255,255}, //34
  // {34,36,255,255}, //35
  // {35,37,255,255}, //36
  // {36,38,255,255}, //37
  // {37,39,255,255}, //38
  // {38,40,255,255}, //39
  // {39,41,255,255}, //40
  // {40,42,255,255}, //41
  // {41,255,255,255}, //42
  // {44,255,255,255}, //43
  // {43,45,255,255}, //44
  // {44,46,255,255}, //45
  // {45,47,255,255}, //46
  // {46,48,255,255}, //47
  // {47,49,255,255}, //48
  // {48,50,255,255}, //49
  // {49,51,255,255}, //50
  // {50,52,255,255}, //51
  // {51,53,255,255}, //52
  // {52,54,255,255}, //53
  // {53,55,255,255}, //54
  // {54,56,255,255}, //55
  // {55,57,255,255}, //56
  // {56,58,255,255}, //57
  // {57,59,255,255}, //58
  // {58,60,255,255}, //59
  // {59,61,255,255}, //60
  // {60,62,255,255}, //61
  // {61,63,255,255}, //62
  // {62,64,255,255}, //63
  // {63,65,255,255}, //64
  // {64,66,255,255}, //65
  // {65,67,255,255}, //66
  // {66,255,255,255} //67
// };

// const uint8_t snowman_mid_nodes[S_TORSO_END+1][4] = {
  // {65,1,255,255}, //0
  // {0,2,255,255}, //1
  // {1,3,255,255}, //2
  // {2,4,255,255}, //3
  // {3,5,255,255}, //4
  // {4,6,255,255}, //5
  // {5,7,255,255}, //6
  // {6,8,255,255}, //7
  // {7,9,255,255}, //8
  // {8,10,255,255}, //9
  // {9,11,255,255}, //10
  // {10,12,255,255}, //11
  // {11,13,255,255}, //12
  // {12,14,28,255}, //13
  // {13,15,255,255}, //14
  // {14,16,255,255}, //15
  // {15,17,255,255}, //16
  // {16,18,255,255}, //17
  // {17,19,255,255}, //18
  // {18,20,34,255}, //19
  // {19,21,255,255}, //20
  // {20,22,255,255}, //21
  // {21,23,255,255}, //22
  // {22,24,255,255}, //23
  // {23,25,255,255}, //24
  // {24,26,255,255}, //25
  // {25,27,29,255}, //26
  // {26,28,255,255}, //27
  // {27,13,255,255}, //28
  // {26,30,255,255}, //29
  // {27,31,255,255}, //30
  // {30,32,255,255}, //31
  // {31,33,255,255}, //32
  // {32,255,255,255}, //33
  // {19,35,255,255}, //34
  // {34,36,255,255}, //35
  // {35,37,255,255}, //36
  // {36,38,255,255}, //37
  // {37,39,255,255}, //38
  // {38,40,255,255}, //39
  // {39,41,255,255}, //40
  // {40,42,255,255}, //41
  // {41,43,255,255}, //42
  // {42,44,255,255}, //43
  // {43,45,255,255}, //44
  // {44,46,255,255}, //45
  // {45,47,255,255}, //46
  // {46,48,255,255,}, //47
  // {47,49,255,255}, //48
  // {48,50,127,255}, //49
  // {49,51,255,255}, //50
  // {50,52,255,255}, //51
  // {51,53,255,255}, //52
  // {52,54,99,255}, //53
  // {53,55,255,255}, //54
  // {54,56,255,255}, //55
  // {55,57,75,255}, //56
  // {56,58,255,255}, //57
  // {57,59,255,255}, //58
  // {58,60,90,255}, //59
  // {59,61,98,255}, //60
  // {60,62,255,255}, //61
  // {61,63,255,255}, //62
  // {62,64,255,255}, //63
  // {63,65,255,255}, //64
  // {64,66,0,255}, //65
  // {65,67,255,255}, //66
  // {66,68,255,255}, //67
  // {67,69,255,255}, //68
  // {68,70,255,255}, //69
  // {69,71,255,255}, //70
  // {70,72,96,255}, //71
  // {71,73,92,89}, //72
  // {72,74,255,255}, //73
  // {73,75,76,255}, //74
  // {74,55,255,255}, //75
  // {74,77,255,255}, //76
  // {76,78,255,255}, //77
  // {77,79,255,255}, //78
  // {78,80,255,255}, //79
  // {79,81,255,255}, //80
  // {80,82,255,255}, //81
  // {81,83,255,255}, //82
  // {82,84,255,255}, //83
  // {83,85,255,255}, //84
  // {84,86,255,255}, //85
  // {85,87,255,255}, //86
  // {86,88,255,255}, //87
  // {87,89,255,255}, //88
  // {88,72,255,255}, //89
  // {59,91,255,255}, //90
  // {90,92,255,255}, //91
  // {91,93,72,255}, //92
  // {92,94,255,255}, //93
  // {93,95,255,255}, //94
  // {94,96,255,255}, //95
  // {95,97,255,255}, //96
  // {96,98,255,255}, //97
  // {97,99,255,255}, //98
  // {98,100,255,255}, //99
  // {99,101,255,255}, //100
  // {100,102,255,255}, //101
  // {101,103,255,255}, //102
  // {102,104,255,255}, //103
  // {103,105,255,255}, //104
  // {104,106,255,255}, //105
  // {105,107,71,255}, //106
  // {106,108,255,255}, //107
  // {107,60,255,255}, //108
  // {53,110,255,255}, //109
  // {109,111,255,255}, //110
  // {110,112,255,255}, //111
  // {111,113,255,255}, //112
  // {112,114,128,255}, //113
  // {113,115,255,255}, //114
  // {114,116,255,255}, //115
  // {115,117,255,255}, //116
  // {116,118,255,255}, //117
  // {117,119,255,255}, //118
  // {118,120,255,255}, //119
  // {119,121,255,255}, //120
  // {120,122,255,255}, //121
  // {121,123,255,255}, //122
  // {122,124,255,255}, //123
  // {123,125,255,255}, //124
  // {124,126,127,255}, //125
  // {125,129,255,255}, //126
  // {126,128,255,255}, //127
  // {127,113,255,255}, //128
  // {125,130,255,255}, //129
  // {129,131,255,255}, //130
  // {130,132,255,255}, //131
  // {131,133,255,255}, //132
  // {132,134,255,255}, //133
  // {133,135,255,255}, //134
  // {134,136,255,255}, //135
  // {135,137,255,255}, //136
  // {136,49,255,255} //137
// };

// const uint8_t snowman_head_nodes[S_HEAD_END+1][4] = {
  // {28,1,255,255}, //0
  // {0,2,255,255}, //1
  // {1,3,255,255}, //2
  // {2,4,255,255}, //3
  // {3,5,255,255}, //4
  // {4,6,255,255}, //5
  // {5,7,255,255}, //6
  // {6,8,255,255}, //7
  // {7,9,255,255}, //8
  // {8,10,255,255}, //9
  // {9,11,255,255}, //10
  // {10,12,255,255}, //11
  // {11,13,255,255}, //12
  // {12,14,51,255}, //13
  // {13,15,255,255}, //14
  // {14,16,255,255}, //15
  // {15,17,255,255}, //16
  // {16,18,255,255}, //17
  // {17,19,255,255}, //18
  // {18,20,255,255}, //19
  // {19,21,255,255}, //20
  // {20,22,255,255}, //21
  // {21,23,255,255}, //22
  // {22,24,255,255}, //23
  // {23,25,255,255}, //24
  // {24,26,75,255}, //25
  // {25,27,255,255}, //26
  // {26,28,255,255}, //27
  // {27,29,0,255}, //28
  // {28,30,255,255}, //29
  // {29,31,255,255}, //30
  // {30,32,255,255}, //31
  // {31,33,255,255}, //32
  // {32,34,255,255}, //33
  // {33,35,255,255}, //34
  // {34,36,255,255}, //35
  // {35,37,74,255}, //36
  // {36,38,255,255}, //37
  // {37,39,255,255}, //38
  // {38,40,255,255}, //39
  // {39,41,255,255}, //40
  // {40,42,255,255}, //41
  // {41,43,255,255}, //42
  // {42,44,255,255}, //43
  // {43,45,255,255}, //44
  // {44,46,52,255}, //45
  // {45,47,255,255}, //46
  // {46,48,255,255}, //47
  // {47,49,255,255}, //48
  // {48,50,255,255}, //49
  // {49,51,255,255}, //50
  // {50,13,255,255}, //51
  // {45,53,255,255}, //52
  // {52,54,255,255}, //53
  // {53,55,255,255}, //54
  // {54,56,255,255}, //55
  // {55,57,255,255}, //56
  // {56,58,255,255}, //57
  // {57,58,255,255}, //58
  // {58,60,255,255}, //59
  // {59,61,255,255}, //60
  // {62,63,255,255}, //61
  // {61,63,255,255}, //62
  // {62,64,255,255}, //63
  // {63,65,255,255}, //64
  // {64,66,255,255}, //65
  // {65,67,255,255}, //66
  // {66,68,255,255}, //67
  // {67,69,255,255}, //68
  // {68,70,255,255}, //69
  // {69,71,255,255}, //70
  // {70,72,255,255}, //71
  // {71,73,255,255}, //72
  // {72,74,255,255}, //73
  // {73,36,255,255}, //74
  // {25,76,255,255}, //75
  // {75,77,255,255}, //76
  // {76,78,255,255}, //77
  // {77,79,255,255}, //78
  // {78,80,255,255}, //79
  // {79,81,255,255}, //80
  // {80,82,255,255}, //81
  // {81,16,255,255}, //82
  // {82,84,255,255}, //83
  // {83,85,255,255}, //84
//   {}, //85 //TODO CHECK THE LEDS
//   {}, //86
//   {}, //87
//   {}, //88
//   {}, //89
//   {}, //90
//   {}, //91
//   {}, //92
//   {}, //93
//   {}, //94
//   {}, //95
//   {}, //96
//   {}, //97
//   {}, //98
//   {}, //99
//   {}, //100
//   {}, //101
//   {}, //102
//   {}, //103
//   {}, //104
//   {}  //105 
// };

const uint8_t owl_nodes[O_END][4] = {
  {118,1,255,255}, //0
  {0,2,255,255}, //1
  {1,3,255,255}, //2
  {2,4,255,255}, //3
  {3,5,255,255}, //4
  {4,6,255,255}, //5
  {5,7,255,255}, //6
  {6,8,255,255}, //7
  {7,9,17,255}, //8
  {8,10,255,255}, //9
  {9,11,255,255}, //10
  {10,12,255,255}, //11
  {11,23,255,255}, //12
  {14,255,255,255}, //13
  {13,21,255,255}, //14
  {19,16,255,255}, //15
  {15,255,255,255}, //16
  {8,18,255,255}, //17
  {17,19,255,255}, //18
  {18,20,15,255}, //19
  {19,21,255,255}, //20
  {20,24,14,255}, //21
  {80,23,255,255}, //22
  {22,24,12,255}, //23
  {23,25,21,255}, //24
  {24,26,255,255}, //25
  {25,27,255,255}, //26
  {26,28,255,255}, //27
  {27,29,255,255}, //28
  {28,31,255,255}, //29
  {38,31,255,255}, //30
  {30,32,29,255}, //31
  {31,33,255,255}, //32
  {32,34,73,255}, //33
  {33,35,255,255}, //34
  {34,36,255,255}, //35
  {35,37,255,255}, //36
  {36,38,39,255}, //37
  {37,30,255,255}, //38
  {37,40,255,255}, //39
  {39,41,255,255}, //40
  {40,42,255,255}, //41
  {41,43,255,255}, //42
  {42,44,255,255}, //43
  {43,46,255,255}, //44
  {51,46,255,255}, //45
  {45,47,44,255}, //46
  {46,48,255,255}, //47
  {47,49,255,255}, //48
  {48,50,68,255}, //49
  {49,51,255,255}, //50
  {50,52,46,255}, //51
  {51,53,255,255}, //52
  {52,54,255,255}, //53
  {53,55,255,255}, //54
  {54,56,255,255}, //55
  {55,57,255,255}, //56
  {56,58,145,255}, //57
  {57,59,113,255}, //58
  {58,61,255,255}, //59
  {82,59,61,255}, //60
  {60,62,255,255}, //61
  {61,63,255,255}, //62
  {62,64,110,255}, //63
  {63,65,255,255}, //64
  {64,66,255,255}, //65
  {65,67,255,255}, //66
  {66,68,255,255}, //67
  {67,69,49,255}, //68
  {68,70,107,255}, //69
  {69,84,255,255}, //70
  {84,72,255,255}, //71
  {71,73,87,255}, //72
  {33,72,74,255}, //73
  {73,75,255,255}, //74
  {74,76,255,255}, //75
  {75,77,255,255}, //76
  {76,78,255,255}, //77
  {77,79,255,255}, //78
  {78,80,255,255}, //79
  {79,81,22,255}, //80
  {86,80,255,255}, //81
  {60,86,83,255}, //82
  {82,84,255,255}, //83
  {70,71,83,85}, //84
  {84,86,255,255}, //85
  {82,85,81,255}, //86
  {72,92,88,255}, //87
  {87,89,93,255}, //88
  {88,90,255,255}, //89
  {89,91,78,255}, //90
  {90,92,99,255}, //91
  {91,87,255,255}, //92
  {88,94,255,255}, //93
  {93,95,255,255}, //94
  {94,96,255,255}, //95
  {95,97,255,255}, //96
  {96,98,255,255}, //97
  {97,99,255,255}, //98
  {98,91,255,255}, //99
  {111,101,255,255}, //100
  {100,102,255,255}, //101
  {101,103,255,255}, //102
  {102,104,255,255}, //103
  {103,105,255,255}, //104
  {104,106,255,255}, //105
  {105,108,255,255}, //106
  {112,69,108,255}, //107
  {107,109,106,255}, //108
  {108,110,255,255}, //109
  {109,111,63,255}, //110
  {110,112,100,255}, //111
  {107,111,255,255}, //112
  {58,114,255,255}, //113
  {113,115,126,255}, //114
  {114,116,125,255}, //115
  {115,117,255,255}, //116
  {116,118,255,255}, //117
  {117,0,119,255}, //118
  {118,123,122,255}, //119
  {121,130,129,255}, //120
  {120,122,255,255}, //121
  {119,121,123,255}, //122
  {122,124,255,255}, //123
  {123,128,255,255}, //124
  {128,115,255,255}, //125
  {114,127,255,255}, //126
  {126,133,132,128}, //127
  {127,125,124,129}, //128
  {128,120,255,255}, //129
  {120,138,255,255}, //130
  {138,139,255,255}, //131
  {139,127,255,255}, //132
  {127,140,255,255}, //133
  {140,141,255,255}, //134
  {141,136,255,255}, //135
  {135,137,255,255}, //136
  {136,138,255,255}, //137
  {137,130,131,255}, //138
  {131,140,255,255}, //139
  {139,133,134,255}, //140
  {135,134,142,255}, //141
  {141,143,255,255}, //142
  {142,144,255,255}, //143
  {143,145,255,255}, //144
  {144,57,255,255} //145
};

const uint16_t tree_nodes[T_END][3] = {
  {156,1,1023}, //0
  {0,2,1023}, //1
  {1,3,1023}, //2
  {2,4,1023}, //3
  {3,5,1023}, //4
  {4,6,1023}, //5
  {5,7,1023}, //6
  {6,8,1023}, //7
  {7,9,1023}, //8
  {8,10,1023}, //9
  {9,11,1023}, //10
  {10,12,1023}, //11
  {11,13,1023}, //12
  {12,14,1023}, //13
  {13,15,1023}, //14
  {14,16,1023}, //15
  {15,17,1023}, //16
  {16,18,1023}, //17
  {17,19,1023}, //18
  {18,20,1023}, //19
  {19,21,1023}, //20
  {20,22,1023}, //21
  {21,23,1023}, //22
  {22,24,1023}, //23
  {23,25,1023}, //24
  {24,26,1023}, //25
  {25,27,1023}, //26
  {26,28,1023}, //27
  {27,29,1023}, //28
  {28,30,1023}, //29
  {29,31,1023}, //30
  {30,32,1023}, //31
  {31,33,1023}, //32
  {32,34,1023}, //33
  {33,35,1023}, //34
  {34,36,1023}, //35
  {35,37,1023}, //36
  {36,38,1023}, //37
  {37,39,1023}, //38
  {38,40,1023}, //39
  {39,41,1023}, //40
  {40,42,1023}, //41
  {41,43,1023}, //42
  {42,44,1023}, //43
  {43,45,1023}, //44
  {44,46,1023}, //45
  {45,47,1023}, //46
  {46,48,1023}, //47
  {47,49,1023}, //48
  {48,50,1023}, //49
  {49,51,1023}, //50
  {50,52,1023}, //51
  {51,155,1023}, //52
  {156,54,1023}, //53
  {53,55,1023}, //54
  {54,56,1023}, //55
  {55,57,1023}, //56
  {56,58,1023}, //57
  {57,59,1023}, //58
  {58,60,1023}, //59
  {59,61,1023}, //60
  {60,62,1023}, //61
  {61,63,1023}, //62
  {62,64,1023}, //63
  {63,65,1023}, //64
  {64,66,1023}, //65
  {65,67,1023}, //66
  {66,68,1023}, //67
  {67,69,1023}, //68
  {68,70,1023}, //69
  {69,71,1023}, //70
  {70,72,1023}, //71
  {71,73,1023}, //72
  {72,74,1023}, //73
  {73,75,1023}, //74
  {74,76,1023}, //75
  {75,77,1023}, //76
  {76,78,1023}, //77
  {77,79,1023}, //78
  {78,80,1023}, //79
  {79,81,1023}, //80
  {80,82,1023}, //81
  {81,83,1023}, //82
  {82,84,1023}, //83
  {83,85,1023}, //84
  {84,86,1023}, //85
  {85,87,1023}, //86
  {86,88,1023}, //87
  {87,89,1023}, //88
  {88,90,1023}, //89
  {89,91,1023}, //90
  {90,92,1023}, //91
  {91,93,1023}, //92
  {92,94,1023}, //93
  {93,95,1023}, //94
  {94,159,1023}, //95
  {153,97,1023}, //96
  {96,98,1023}, //97
  {97,99,1023}, //98
  {98,100,1023}, //99
  {99,101,1023}, //100
  {100,102,1023}, //101
  {101,103,1023}, //102
  {102,104,1023}, //103
  {103,105,1023}, //104
  {104,106,1023}, //105
  {105,107,1023}, //106
  {106,108,1023}, //107
  {107,109,1023}, //108
  {108,110,1023}, //109
  {109,111,1023}, //110
  {110,112,1023}, //111
  {111,113,1023}, //112
  {112,114,1023}, //113
  {113,115,1023}, //114
  {114,116,1023}, //115
  {115,117,1023}, //116
  {116,118,1023}, //117
  {117,119,1023}, //118
  {118,120,1023}, //119
  {119,121,1023}, //120
  {120,122,1023}, //121
  {121,123,1023}, //122
  {122,124,1023}, //123
  {123,125,1023}, //124
  {124,126,1023}, //125
  {125,127,1023}, //126
  {126,128,1023}, //127
  {127,129,1023}, //128
  {128,130,1023}, //129
  {129,131,1023}, //130
  {130,132,1023}, //131
  {131,133,1023}, //132
  {132,134,1023}, //133
  {133,135,1023}, //134
  {134,136,1023}, //135
  {135,137,1023}, //136
  {136,138,1023}, //137
  {137,139,1023}, //138
  {138,148,1023}, //139
  {256,141,1023}, //140
  {140,142,1023}, //141
  {141,143,1023}, //142
  {142,144,1023}, //143
  {143,145,1023}, //144
  {144,146,1023}, //145
  {145,147,1023}, //146
  {146,148,1023}, //147
  {147,149,139}, //148
  {148,150,1023}, //149
  {149,151,1023}, //150
  {150,152,1023}, //151
  {151,153,1023}, //152
  {152,154,96}, //153
  {153,155,1023}, //154
  {154,52,1023}, //155
  {0,157,53}, //156
  {156,158,1023}, //157
  {157,159,1023}, //158
  {95,158,160}, //159
  {159,161,1023}, //160
  {160,162,1023}, //161
  {161,163,1023}, //162
  {162,164,1023}, //163
  {163,165,1023}, //164
  {164,166,1023}, //165
  {165,167,1023}, //166
  {166,168,1023}, //167
  {167,169,1023}, //168
  {168,170,1023}, //169
  {169,171,1023}, //170
  {170,224,1023}, //171
  {255,173,1023}, //172
  {172,174,1023}, //173
  {173,175,1023}, //174
  {174,176,1023}, //175
  {175,177,1023}, //176
  {176,178,1023}, //177
  {177,179,1023}, //178
  {178,180,1023}, //179
  {179,181,1023}, //180
  {180,182,1023}, //181
  {181,183,1023}, //182
  {182,184,1023}, //183
  {183,185,1023}, //184
  {184,186,1023}, //185
  {185,187,1023}, //186
  {186,188,1023}, //187
  {187,189,1023}, //188
  {188,190,1023}, //189
  {189,191,1023}, //190
  {190,192,1023}, //191
  {191,193,1023}, //192
  {192,194,1023}, //193
  {193,195,1023}, //194
  {194,254,1023}, //195
  {227,197,1023}, //196
  {196,198,1023}, //197
  {197,199,1023}, //198
  {198,200,1023}, //199
  {199,201,1023}, //200
  {200,202,1023}, //201
  {201,203,1023}, //202
  {202,204,1023}, //203
  {203,205,1023}, //204
  {204,206,1023}, //205
  {205,207,1023}, //206
  {206,208,1023}, //207
  {207,209,1023}, //208
  {208,210,1023}, //209
  {209,211,1023}, //210
  {210,212,1023}, //211
  {211,213,1023}, //212
  {212,214,1023}, //213
  {213,215,1023}, //214
  {214,216,1023}, //215
  {215,217,1023}, //216
  {216,218,1023}, //217
  {217,219,1023}, //218
  {218,220,1023}, //219
  {219,221,1023}, //220
  {220,222,1023}, //221
  {221,223,1023}, //222
  {222,225,1023}, //223
  {171,225,1023}, //224
  {223,224,226}, //225
  {225,227,1023}, //226
  {226,228,1023}, //227
  {227,229,1023}, //228
  {228,230,1023}, //229
  {229,231,1023}, //230
  {230,232,1023}, //231
  {231,233,1023}, //232
  {232,234,1023}, //233
  {233,235,1023}, //234
  {234,236,1023}, //235
  {235,237,1023}, //236
  {236,238,1023}, //237
  {237,239,1023}, //238
  {238,240,1023}, //239
  {239,241,1023}, //240
  {240,242,1023}, //241
  {241,243,1023}, //242
  {242,244,1023}, //243
  {243,245,1023}, //244
  {244,246,1023}, //245
  {245,247,1023}, //246
  {246,248,1023}, //247
  {247,249,1023}, //248
  {248,250,1023}, //249
  {249,251,1023}, //250
  {250,252,1023}, //251
  {251,253,1023}, //252
  {252,254,1023}, //253
  {253,255,195}, //254
  {172,254,256}, //255
  {255,257,1023},  //256
  {256,258,1023}, //257
  {257,140,1023}  //258
};


/*
  {}, //0
  {}, //1
  {}, //2
  {}, //3
  {}, //4
  {}, //5
  {}, //6
  {}, //7
  {}, //8
  {}, //9
  {}, //10
  {}, //11
  {}, //12
  {}, //13
  {}, //14
  {}, //15
  {}, //16
  {}, //17
  {}, //18
  {}, //19
  {}, //20
  {}, //21
  {}, //22
  {}, //23
  {}, //24
  {}, //25
  {}, //26
  {}, //27
  {}, //28
  {}, //29
  {}, //30
  {}, //31
  {}, //32
  {}, //33
  {}, //34
  {}, //35
  {}, //36
  {}, //37
  {}, //38
  {}, //39
  {}, //40
  {}, //41
  {}, //42
  {}, //43
  {}, //44
  {}, //45
  {}, //46
  {}, //47
  {}, //48
  {}, //49
  {}, //50
  {}, //51
  {}, //52
  {}, //53
  {}, //54
  {}, //55
  {}, //56
  {}, //57
  {}, //58
  {}, //59
  {}, //60
  {}, //61
  {}, //62
  {}, //63
  {}, //64
  {}, //65
  {}, //66
  {}, //67
  {}, //68
  {}, //69
  {}, //70
  {}, //71
  {}, //72
  {}, //73
  {}, //74
  {}, //75
  {}, //76
  {}, //77
  {}, //78
  {}, //79
  {}, //80
  {}, //81
  {}, //82
  {}, //83
  {}, //84
  {}, //85
  {}, //86
  {}, //87
  {}, //88
  {}, //89
  {}, //90
  {}, //91
  {}, //92
  {}, //93
  {}, //94
  {}, //95
  {}, //96
  {}, //97
  {}, //98
  {}, //99
  {}, //100
  {}, //101
  {}, //102
  {}, //103
  {}, //104
  {}, //105
  {}, //106
  {}, //107
  {}, //108
  {}, //109
  {}, //110
  {}, //111
  {}, //112
  {}, //113
  {}, //114
  {}, //115
  {}, //116
  {}, //117
  {}, //118
  {}, //119
  {}, //120
  {}, //121
  {}, //122
  {}, //123
  {}, //124
  {}, //125
  {}, //126
  {}, //127
  {}, //128
  {}, //129
  {}, //130
  {}, //131
  {}, //132
  {}, //133
  {}, //134
  {}, //135
  {}, //136
  {}, //137
  {}, //138
  {}, //139
  {}, //140
  {}, //141
  {}, //142
  {}, //143
  {}, //144
  {}, //145
  {}, //146
  {}, //147
  {}, //148
  {}, //149
  {}, //150
  {}, //151
  {}, //152
  {}, //153
  {}, //154
  {}, //155
  {}, //156
  {}, //157
  {}, //158
  {}, //159
  {}, //160
  {}, //161
  {}, //162
  {}, //163
  {}, //164
  {}, //165
  {}, //166
  {}, //167
  {}, //168
  {}, //169
  {}, //170
  {}, //171
  {}, //172
  {}, //173
  {}, //174
  {}, //175
  {}, //176
  {}, //177
  {}, //178
  {}, //179
  {}, //180
  {}, //181
  {}, //182
  {}, //183
  {}, //184
  {}, //185
  {}, //186
  {}, //187
  {}, //188
  {}, //189
  {}, //190
  {}, //191
  {}, //192
  {}, //193
  {}, //194
  {}, //195
  {}, //196
  {}, //197
  {}, //198
  {}, //199
  {}, //200
  {}, //201
  {}, //202
  {}, //203
  {}, //204
  {}, //205
  {}, //206
  {}, //207
  {}, //208
  {}, //209
  {}, //210
  {}, //211
  {}, //212
  {}, //213
  {}, //214
  {}, //215
  {}, //216
  {}, //217
  {}, //218
  {}, //219
  {}, //220
  {}, //221
  {}, //222
  {}, //223
  {}, //224
  {}, //225
  {}, //226
  {}, //227
  {}, //228
  {}, //229
  {}, //230
  {}, //231
  {}, //232
  {}, //233
  {}, //234
  {}, //235
  {}, //236
  {}, //237
  {}, //238
  {}, //239
  {}, //240
  {}, //241
  {}, //242
  {}, //243
  {}, //244
  {}, //245
  {}, //246
  {}, //247
  {}, //248
  {}, //249
  {}, //250
  {}, //251
  {}, //252
  {}, //253
  {}, //254
  {}, //255
  {}, //256
  {}, //257
  {}, //258
  {}, //259
  */