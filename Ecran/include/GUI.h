//  Le code es un peut compliquer c'etais le code auto generated par GUISlice Builder , je l'ai modifié pour que ce soit plus simple
//  J'ai essayer de tous mettre les declarations dans le header mais j'ai pas pu faire fonctionner et j'ai manqué de temps
//  Et avec plus de temps j'aurais separer le code en plusieurs classes.
//  Cela vas etre corrige pour le HOMEGARDEN 6000

//<File !Start!>
// FILE: [arduino_GSLC.h]
// Created by GUIslice Builder version: [0.17.b11]
//
// GUIslice Builder Generated GUI Framework File
//
// For the latest guides, updates and support view:
// https://github.com/ImpulseAdventure/GUIslice
//
//<File !End!>

#ifndef _GUISLICE_GEN_H
#define _GUISLICE_GEN_H

// ------------------------------------------------
// Headers to include
// ------------------------------------------------
#include "GUIslice.h"
#include "GUIslice_drv.h"

// Include any extended elements
//<Includes !Start!>
// Include extended elements
#include "elem/XKeyPad_Alpha.h"
#include "elem/XListbox.h"
#include "elem/XRingGauge.h"
#include "elem/XSlider.h"

// Ensure optional features are enabled in the configuration
//<Includes !End!>

// ------------------------------------------------
// Headers and Defines for fonts
// Note that font files are located within the Adafruit-GFX library folder:
// ------------------------------------------------
//<Fonts !Start!>
#if !defined(DRV_DISP_TFT_ESPI)
#error Project tab->Target Platform should be arduino
#endif
#include <TFT_eSPI.h>
#include <PubSubClient.h>
#include <esp_now.h>
#include <Arduino.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <WiFi.h>
#include <config.h>
#include "WifiFonction.h"

//<Fonts !End!>

// ------------------------------------------------
// Defines for resources
// ------------------------------------------------
//<Resources !Start!>
//<Resources !End!>

// ------------------------------------------------
// Enumerations for pages, elements, fonts, images
// ------------------------------------------------
//<Enum !Start!>
enum
{
  E_PG_MAIN,
  E_PG2,
  E_PG3,
  E_POP_KEYPAD_ALPHA
};
enum
{
  E_DRAW_LINE1,
  E_DRAW_LINE2,
  E_DRAW_LINE3,
  E_ELEM_BOX2,
  E_ELEM_BOX3,
  E_ELEM_BOX4,
  E_ELEM_BOX5,
  E_ELEM_BTN1,
  E_ELEM_BTN2,
  E_ELEM_LISTBOX1,
  E_ELEM_RINGGAUGE5,
  E_ELEM_RINGGAUGE6,
  E_ELEM_RINGGAUGE7,
  E_ELEM_TEXT1,
  E_ELEM_TEXT10,
  E_ELEM_TEXT11,
  E_ELEM_TEXT12,
  E_ELEM_TEXT13,
  E_ELEM_TEXT14,
  E_ELEM_TEXT15,
  E_ELEM_TEXT16,
  E_ELEM_TEXT17,
  E_ELEM_TEXT19,
  E_ELEM_TEXT2,
  E_ELEM_TEXT20,
  E_ELEM_TEXT21,
  E_ELEM_TEXT22,
  E_ELEM_TEXT24,
  E_ELEM_TEXT25,
  E_ELEM_TEXT26,
  E_ELEM_TEXT4,
  E_ELEM_TEXT8,
  E_ELEM_TEXT9,
  E_ELEM_TEXTINPUT1,
  E_ELEM_TEXTINPUT2,
  E_ELEM_TEXTINPUT3,
  E_LISTSCROLL1,
  E_ELEM_KEYPAD_ALPHA
};
// Must use separate enum for fonts with MAX_FONT at end to use gslc_FontSet.
enum
{
  E_BUILTIN10X16,
  E_BUILTIN15X24,
  E_BUILTIN20X32,
  E_BUILTIN25X40,
  E_BUILTIN5X8,
  MAX_FONT
};
//<Enum !End!>

// ------------------------------------------------
// Instantiate the GUI
// ------------------------------------------------

// ------------------------------------------------
// Define the maximum number of elements and pages
// ------------------------------------------------
//<ElementDefines !Start!>
#define MAX_PAGE 4

#define MAX_ELEM_PG_MAIN 3                    // # Elems total on page
#define MAX_ELEM_PG_MAIN_RAM MAX_ELEM_PG_MAIN // # Elems in RAM

#define MAX_ELEM_PG2 8                // # Elems total on page
#define MAX_ELEM_PG2_RAM MAX_ELEM_PG2 // # Elems in RAM

#define MAX_ELEM_PG3 27               // # Elems total on page
#define MAX_ELEM_PG3_RAM MAX_ELEM_PG3 // # Elems in RAM
//<ElementDefines !End!>

// ------------------------------------------------
// Create element storage
// ------------------------------------------------
gslc_tsGui m_gui;
gslc_tsDriver m_drv;
gslc_tsFont m_asFont[MAX_FONT];
gslc_tsPage m_asPage[MAX_PAGE];

//<GUI_Extra_Elements !Start!>
gslc_tsElem m_asPage1Elem[MAX_ELEM_PG_MAIN_RAM];
gslc_tsElemRef m_asPage1ElemRef[MAX_ELEM_PG_MAIN];
gslc_tsElem m_asPage2Elem[MAX_ELEM_PG2_RAM];
gslc_tsElemRef m_asPage2ElemRef[MAX_ELEM_PG2];
gslc_tsElem m_asPage3Elem[MAX_ELEM_PG3_RAM];
gslc_tsElemRef m_asPage3ElemRef[MAX_ELEM_PG3];
gslc_tsElem m_asKeypadAlphaElem[1];
gslc_tsElemRef m_asKeypadAlphaElemRef[1];
gslc_tsXKeyPad m_sKeyPadAlpha;
gslc_tsXListbox m_sListbox1;
// - Note that XLISTBOX_BUF_OH_R is extra required per item
char m_acListboxBuf1[0 + XLISTBOX_BUF_OH_R];
gslc_tsXSlider m_sListScroll1;
gslc_tsXRingGauge m_sXRingGauge5;
gslc_tsXRingGauge m_sXRingGauge6;
gslc_tsXRingGauge m_sXRingGauge7;

#define MAX_STR 100

//<GUI_Extra_Elements !End!>

// ------------------------------------------------
// Program Globals
// ------------------------------------------------

// Element References for direct access
//<Extern_References !Start!>
extern gslc_tsElemRef *m_pElemInTxt1;
extern gslc_tsElemRef *m_pElemInTxt1_3;
extern gslc_tsElemRef *m_pElemInTxt2;
extern gslc_tsElemRef *m_pElemInTxt4;
extern gslc_tsElemRef *m_pElemInTxt5;
extern gslc_tsElemRef *m_pElemInTxt6;
extern gslc_tsElemRef *m_pElemInTxt7;
extern gslc_tsElemRef *m_pElemInTxt8;
extern gslc_tsElemRef *m_pElemInTxt9;
extern gslc_tsElemRef *m_pElemInTxt10;
extern gslc_tsElemRef *m_pElemInTxt11;
extern gslc_tsElemRef *m_pElemInTxt12;
extern gslc_tsElemRef *m_pElemListbox1;
extern gslc_tsElemRef *m_pElemXRingGauge5;
extern gslc_tsElemRef *m_pElemXRingGauge5_6;
extern gslc_tsElemRef *m_pElemXRingGauge5_7;
extern gslc_tsElemRef *m_pListSlider1;
extern gslc_tsElemRef *m_pElemKeyPadAlpha;
WifiFonction *m_wifiFonction;
bool connectionStateWifi = false;
bool connectionStateMQTT = false;

const char *brokerUser = "mqtt-user";
const char *brokerPass = "admin1234";
unsigned long delayTime;
WiFiClient espClient;
PubSubClient client(espClient);
byte *buffer;
boolean Rflag = false;
bool TopicInscris = false;
int r_len;
char *Topic;

bool isEspNow = false;

void demoDeserialiserJSON();
void afficherMeteoQuebec();
void afficherInformationMeteoAPartirJSON(const String &json);


void espNowSetup();

void espNow(char *p_ssid_name, char *p_ssid_pass, char *p_mqtt_broker);



void callback(char *topic, byte *payload, unsigned int length); // Fonction CallBack pour print un message recu
bool mqttConnect();                                             // Fonction pour se connecter au serveur MQTT

// callback when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status);

//<Extern_References !End!>

// Define debug message function
static int16_t DebugOut(char ch);

// ------------------------------------------------
// Callback Methods
// ------------------------------------------------
bool CbBtnCommon(void *pvGui, void *pvElemRef, gslc_teTouch eTouch, int16_t nX, int16_t nY);
bool CbCheckbox(void *pvGui, void *pvElemRef, int16_t nSelId, bool bState);
bool CbDrawScanner(void *pvGui, void *pvElemRef, gslc_teRedrawType eRedraw);
bool CbKeypad(void *pvGui, void *pvElemRef, int16_t nState, void *pvData);
bool CbListbox(void *pvGui, void *pvElemRef, int16_t nSelId);
bool CbSlidePos(void *pvGui, void *pvElemRef, int16_t nPos);
bool CbSpinner(void *pvGui, void *pvElemRef, int16_t nState, void *pvData);
bool CbTickScanner(void *pvGui, void *pvScope);

// ------------------------------------------------
// Create page elements
// ------------------------------------------------
void InitGUIslice_gen()
{
  gslc_tsElemRef *pElemRef = NULL;

  if (!gslc_Init(&m_gui, &m_drv, m_asPage, MAX_PAGE, m_asFont, MAX_FONT))
  {
    return;
  }

  // ------------------------------------------------
  // Load Fonts
  // ------------------------------------------------
  //<Load_Fonts !Start!>
  if (!gslc_FontSet(&m_gui, E_BUILTIN10X16, GSLC_FONTREF_PTR, NULL, 2))
  {
    return;
  }
  if (!gslc_FontSet(&m_gui, E_BUILTIN15X24, GSLC_FONTREF_PTR, NULL, 3))
  {
    return;
  }
  if (!gslc_FontSet(&m_gui, E_BUILTIN20X32, GSLC_FONTREF_PTR, NULL, 4))
  {
    return;
  }
  if (!gslc_FontSet(&m_gui, E_BUILTIN25X40, GSLC_FONTREF_PTR, NULL, 5))
  {
    return;
  }
  if (!gslc_FontSet(&m_gui, E_BUILTIN5X8, GSLC_FONTREF_PTR, NULL, 1))
  {
    return;
  }
  //<Load_Fonts !End!>

  //<InitGUI !Start!>
  gslc_PageAdd(&m_gui, E_PG_MAIN, m_asPage1Elem, MAX_ELEM_PG_MAIN_RAM, m_asPage1ElemRef, MAX_ELEM_PG_MAIN);
  gslc_PageAdd(&m_gui, E_PG2, m_asPage2Elem, MAX_ELEM_PG2_RAM, m_asPage2ElemRef, MAX_ELEM_PG2);
  gslc_PageAdd(&m_gui, E_PG3, m_asPage3Elem, MAX_ELEM_PG3_RAM, m_asPage3ElemRef, MAX_ELEM_PG3);
  gslc_PageAdd(&m_gui, E_POP_KEYPAD_ALPHA, m_asKeypadAlphaElem, 1, m_asKeypadAlphaElemRef, 1); // KeyPad

  // NOTE: The current page defaults to the first page added. Here we explicitly
  //       ensure that the main page is the correct page no matter the add order.
  gslc_SetPageCur(&m_gui, E_PG_MAIN);

  // Set Background to a flat color
  gslc_SetBkgndColor(&m_gui, GSLC_COL_BLACK);

  // -----------------------------------
  // PAGE: E_PG_MAIN FRONT PAGE

  // Create E_ELEM_TEXT1 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT1, E_PG_MAIN, (gslc_tsRect){130, 10, 271, 42},
                                (char *)"BIENVENUE", 0, E_BUILTIN25X40);

  static char m_sInputText12[50] = "HOMEGARDEN 5000";
  pElemRef = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT2, E_PG_MAIN, (gslc_tsRect){32, 60, 438, 42},
                                (char *)m_sInputText12, 50, E_BUILTIN25X40);
  m_pElemInTxt12 = pElemRef;

  // create E_ELEM_BTN1 button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui, E_ELEM_BTN1, E_PG_MAIN,
                                   (gslc_tsRect){110, 160, 300, 80}, (char *)"CONNECT", 0, E_BUILTIN15X24, &CbBtnCommon);
  gslc_ElemSetCol(&m_gui, pElemRef, GSLC_COL_GRAY, GSLC_COL_GREEN, GSLC_COL_GREEN_DK4);
  gslc_ElemSetTxtEnc(&m_gui, pElemRef, GSLC_TXT_ENC_UTF8);
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);

  // -----------------------------------
  // PAGE: E_PG2 PAGE WIFI MANAGER

  // Create wrapping box for listbox E_ELEM_LISTBOX1 and scrollbar
  pElemRef = gslc_ElemCreateBox(&m_gui, GSLC_ID_AUTO, E_PG2, (gslc_tsRect){40, 20, 420, 160});
  gslc_ElemSetCol(&m_gui, pElemRef, GSLC_COL_YELLOW, GSLC_COL_GRAY, GSLC_COL_BLACK);

  // Create listbox
  static uint8_t m_pXListboxBuf[25 * (50 + XLISTBOX_BUF_OH_R)];
  pElemRef = gslc_ElemXListboxCreate(&m_gui, E_ELEM_LISTBOX1, E_PG2, &m_sListbox1,
                                     (gslc_tsRect){40 + 2, 20 + 4, 420 - 4 - 20, 160 - 7}, E_BUILTIN15X24,
                                     m_pXListboxBuf, 100, 0);
  gslc_ElemXListboxSetSize(&m_gui, pElemRef, 5, 1); // 5 rows, 1 columns
  gslc_ElemXListboxItemsSetSize(&m_gui, pElemRef, XLISTBOX_SIZE_AUTO, XLISTBOX_SIZE_AUTO);
  gslc_ElemSetTxtMarginXY(&m_gui, pElemRef, 5, 0);
  gslc_ElemSetTxtCol(&m_gui, pElemRef, GSLC_COL_MAGENTA);
  gslc_ElemSetCol(&m_gui, pElemRef, GSLC_COL_YELLOW, GSLC_COL_GRAY, GSLC_COL_BLACK);
  gslc_ElemSetTxtAlign(&m_gui, pElemRef, GSLC_ALIGN_MID_MID);
  gslc_ElemXListboxSetSelFunc(&m_gui, pElemRef, &CbListbox);
  gslc_ElemSetFrameEn(&m_gui, pElemRef, true);
  m_pElemListbox1 = pElemRef;

  // Create vertical scrollbar for listbox
  pElemRef = gslc_ElemXSliderCreate(&m_gui, E_LISTSCROLL1, E_PG2, &m_sListScroll1,
                                    (gslc_tsRect){40 + 420 - 2 - 20, 20 + 4, 20, 160 - 8}, 0, 10, 0, 10, true);
  gslc_ElemSetCol(&m_gui, pElemRef, GSLC_COL_YELLOW, GSLC_COL_BLACK, GSLC_COL_YELLOW);
  gslc_ElemXSliderSetPosFunc(&m_gui, pElemRef, &CbSlidePos);

  static char m_sInputText1[50] = "virgile2002";
  pElemRef = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXTINPUT1, E_PG2, (gslc_tsRect){40, 230, 220, 34},
                                (char *)m_sInputText1, 50, E_BUILTIN5X8);
  gslc_ElemSetTxtAlign(&m_gui, pElemRef, GSLC_ALIGN_MID_MID);
  gslc_ElemSetTxtMargin(&m_gui, pElemRef, 5);
  gslc_ElemSetCol(&m_gui, pElemRef, GSLC_COL_GRAY, GSLC_COL_GRAY, GSLC_COL_BLACK);
  gslc_ElemSetFrameEn(&m_gui, pElemRef, true);
  gslc_ElemSetClickEn(&m_gui, pElemRef, true);
  gslc_ElemSetTouchFunc(&m_gui, pElemRef, &CbBtnCommon);
  gslc_ElemSetTxtEnc(&m_gui, pElemRef, GSLC_TXT_ENC_UTF8);
  m_pElemInTxt1 = pElemRef;

  // Create E_ELEM_TEXTINPUT2 text input field
  static char m_sInputText2[244] = "BELL056";
  pElemRef = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXTINPUT2, E_PG2, (gslc_tsRect){40, 190, 220, 34},
                                (char *)m_sInputText2, 244, E_BUILTIN5X8);
  gslc_ElemSetTxtAlign(&m_gui, pElemRef, GSLC_ALIGN_MID_MID);
  gslc_ElemSetTxtMargin(&m_gui, pElemRef, 5);
  gslc_ElemSetCol(&m_gui, pElemRef, GSLC_COL_GRAY, GSLC_COL_GRAY, GSLC_COL_BLACK);
  gslc_ElemSetFrameEn(&m_gui, pElemRef, true);
  gslc_ElemSetClickEn(&m_gui, pElemRef, true);
  gslc_ElemSetTouchFunc(&m_gui, pElemRef, &CbBtnCommon);
  m_pElemInTxt2 = pElemRef;
  // Serial.println(m_sInputText2);

  // Create E_ELEM_TEXTINPUT3 text input field
  static char m_sInputText3[50] = "192.168.2.164";
  pElemRef = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXTINPUT3, E_PG2, (gslc_tsRect){40, 270, 220, 34},
                                (char *)m_sInputText3, 50, E_BUILTIN5X8);
  gslc_ElemSetTxtAlign(&m_gui, pElemRef, GSLC_ALIGN_MID_MID);
  gslc_ElemSetTxtMargin(&m_gui, pElemRef, 5);
  gslc_ElemSetCol(&m_gui, pElemRef, GSLC_COL_GRAY, GSLC_COL_GRAY, GSLC_COL_BLACK);
  gslc_ElemSetFrameEn(&m_gui, pElemRef, true);
  gslc_ElemSetClickEn(&m_gui, pElemRef, true);
  gslc_ElemSetTouchFunc(&m_gui, pElemRef, &CbBtnCommon);
  m_pElemInTxt1_3 = pElemRef;

  // create E_ELEM_BTN2 button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui, E_ELEM_BTN2, E_PG2,
                                   (gslc_tsRect){280, 230, 180, 50}, (char *)"CONNECT", 0, E_BUILTIN5X8, &CbBtnCommon);
  gslc_ElemSetTxtCol(&m_gui, pElemRef, GSLC_COL_YELLOW);

  // Create E_ELEM_TEXTINPUT2 text input field
  static char m_sInputText4[100] = "ENTRER VOS INFORMATIONS";
  pElemRef = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT4, E_PG2, (gslc_tsRect){300, 200, 139, 10},
                                (char *)m_sInputText4, 100, E_BUILTIN5X8);
  m_pElemInTxt4 = pElemRef;

  // -----------------------------------
  // PAGE: E_PG3 PAGE SENSOR / PREDICTIONS

  // Create E_ELEM_BOX2 box
  pElemRef = gslc_ElemCreateBox(&m_gui, E_ELEM_BOX2, E_PG3, (gslc_tsRect){40, 10, 138, 200});

  // Create E_ELEM_BOX3 box
  pElemRef = gslc_ElemCreateBox(&m_gui, E_ELEM_BOX3, E_PG3, (gslc_tsRect){180, 10, 135, 200});

  // Create E_ELEM_BOX4 box
  pElemRef = gslc_ElemCreateBox(&m_gui, E_ELEM_BOX4, E_PG3, (gslc_tsRect){310, 10, 138, 200});

  // Create E_ELEM_BOX5 box
  pElemRef = gslc_ElemCreateBox(&m_gui, E_ELEM_BOX5, E_PG3, (gslc_tsRect){38, 220, 411, 90});

  // Create ring gauge E_ELEM_RINGGAUGE5
  static char m_sRingText5[11] = "hPa";
  pElemRef = gslc_ElemXRingGaugeCreate(&m_gui, E_ELEM_RINGGAUGE5, E_PG3, &m_sXRingGauge5,
                                       (gslc_tsRect){330, 90, 100, 100},
                                       (char *)m_sRingText5, 11, E_BUILTIN10X16);
  gslc_ElemXRingGaugeSetValRange(&m_gui, pElemRef, -100, 100);
  gslc_ElemXRingGaugeSetVal(&m_gui, pElemRef, 0); // Set initial value
  gslc_ElemXRingGaugeSetColorActiveGradient(&m_gui, pElemRef, GSLC_COL_BLUE_LT4, GSLC_COL_RED);
  m_pElemXRingGauge5 = pElemRef;

  // Create ring gauge E_ELEM_RINGGAUGE6
  static char m_sRingText6[11] = "C";
  pElemRef = gslc_ElemXRingGaugeCreate(&m_gui, E_ELEM_RINGGAUGE6, E_PG3, &m_sXRingGauge6,
                                       (gslc_tsRect){60, 90, 100, 100},
                                       (char *)m_sRingText6, 11, E_BUILTIN10X16);
  gslc_ElemXRingGaugeSetValRange(&m_gui, pElemRef, -30, 50);
  gslc_ElemXRingGaugeSetVal(&m_gui, pElemRef, 0); // Set initial value
  gslc_ElemXRingGaugeSetColorActiveGradient(&m_gui, pElemRef, GSLC_COL_BLUE_LT4, GSLC_COL_RED);
  m_pElemXRingGauge5_6 = pElemRef;

  // Create ring gauge E_ELEM_RINGGAUGE7
  static char m_sRingText7[11] = "%";
  pElemRef = gslc_ElemXRingGaugeCreate(&m_gui, E_ELEM_RINGGAUGE7, E_PG3, &m_sXRingGauge7,
                                       (gslc_tsRect){200, 90, 100, 100},
                                       (char *)m_sRingText7, 11, E_BUILTIN10X16);
  gslc_ElemXRingGaugeSetValRange(&m_gui, pElemRef, -100, 100);
  gslc_ElemXRingGaugeSetVal(&m_gui, pElemRef, 0); // Set initial value
  gslc_ElemXRingGaugeSetColorActiveGradient(&m_gui, pElemRef, GSLC_COL_BLUE_LT4, GSLC_COL_RED);
  m_pElemXRingGauge5_7 = pElemRef;

  // // Create E_ELEM_TEXT8 text label
  // pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT8,E_PG3,(gslc_tsRect){80,60,13,18},
  //   (char*)"0",0,E_BUILTIN10X16);
  // gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  // m_pElemInTxt5 = pElemRef;

  static char m_sInputText5[6] = "0";
  pElemRef = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT8, E_PG3, (gslc_tsRect){60, 60, 100, 18},
                                (char *)m_sInputText5, 6, E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui, pElemRef, GSLC_ALIGN_MID_MID);
  m_pElemInTxt5 = pElemRef;

  static char m_sInputText6[6] = "0";
  pElemRef = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT9, E_PG3, (gslc_tsRect){330, 60, 100, 18},
                                (char *)m_sInputText5, 6, E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui, pElemRef, GSLC_ALIGN_MID_MID);
  m_pElemInTxt6 = pElemRef;

  static char m_sInputText7[6] = "0";
  pElemRef = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT10, E_PG3, (gslc_tsRect){200, 60, 100, 18},
                                (char *)m_sInputText5, 6, E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui, pElemRef, GSLC_ALIGN_MID_MID);
  m_pElemInTxt7 = pElemRef;

  // Create E_ELEM_TEXT11 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT11, E_PG3, (gslc_tsRect){330, 20, 97, 18},
                                (char *)"PRESSION", 0, E_BUILTIN10X16);

  // Create E_ELEM_TEXT12 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT12, E_PG3, (gslc_tsRect){200, 20, 97, 18},
                                (char *)"HUMIDITE", 0, E_BUILTIN10X16);

  // Create E_ELEM_TEXT13 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT13, E_PG3, (gslc_tsRect){42, 20, 133, 18},
                                (char *)"TEMPERATURE", 0, E_BUILTIN10X16);

  // predictions

  // Create E_ELEM_TEXT15 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT15, E_PG3, (gslc_tsRect){60, 230, 79, 10},
                                (char *)"Precipitation", 0, E_BUILTIN5X8);

  // Create E_DRAW_LINE2 line
  pElemRef = gslc_ElemCreateLine(&m_gui, E_DRAW_LINE2, E_PG3, 150, 220, 150, 310);
  gslc_ElemSetCol(&m_gui, pElemRef, GSLC_COL_BLACK, GSLC_COL_GRAY_LT2, GSLC_COL_GRAY_LT2);

  // Create E_ELEM_TEXT16 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT16, E_PG3, (gslc_tsRect){170, 230, 55, 10},
                                (char *)"Vent km/h", 0, E_BUILTIN5X8);

  // Create E_DRAW_LINE3 line
  pElemRef = gslc_ElemCreateLine(&m_gui, E_DRAW_LINE3, E_PG3, 250, 220, 250, 310);
  gslc_ElemSetCol(&m_gui, pElemRef, GSLC_COL_BLACK, GSLC_COL_GRAY_LT2, GSLC_COL_GRAY_LT2);

  // Create E_ELEM_TEXT17 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT17, E_PG3, (gslc_tsRect){290, 230, 121, 18},
                                (char *)"Prediction", 0, E_BUILTIN10X16);

  static char m_sInputText9[12] = "0";
  pElemRef = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT20, E_PG3, (gslc_tsRect){50, 270, 95, 18},
                                (char *)m_sInputText9, 12, E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui, pElemRef, GSLC_ALIGN_MID_MID);
  m_pElemInTxt9 = pElemRef;

  // Create E_ELEM_TEXT21 text label
  static char m_sInputText10[12] = "0";
  pElemRef = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT21, E_PG3, (gslc_tsRect){160, 270, 80, 18},
                                (char *)m_sInputText10, 12, E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui, pElemRef, GSLC_ALIGN_MID_MID);
  m_pElemInTxt10 = pElemRef;

  // Create E_ELEM_TEXT22 text label
  static char m_sInputText11[18] = "0";
  pElemRef = gslc_ElemCreateTxt(&m_gui, E_ELEM_TEXT22, E_PG3, (gslc_tsRect){260, 270, 180, 18},
                                (char *)m_sInputText11, 18, E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui, pElemRef, GSLC_ALIGN_MID_MID);
  m_pElemInTxt11 = pElemRef;

  // -----------------------------------
  // PAGE: E_POP_KEYPAD_ALPHA

  static gslc_tsXKeyPadCfg_Alpha sCfgTx;
  sCfgTx = gslc_ElemXKeyPadCfgInit_Alpha();
  gslc_ElemXKeyPadCfgSetButtonSz((gslc_tsXKeyPadCfg *)&sCfgTx, 22, 33);
  m_pElemKeyPadAlpha = gslc_ElemXKeyPadCreate_Alpha(&m_gui, E_ELEM_KEYPAD_ALPHA, E_POP_KEYPAD_ALPHA,
                                                    &m_sKeyPadAlpha, 40, 0, E_BUILTIN5X8, &sCfgTx);
  gslc_ElemXKeyPadValSetCb(&m_gui, m_pElemKeyPadAlpha, &CbKeypad);
  //<InitGUI !End!>

  //<Startup !Start!>
  //<Startup !End!>
}

#endif // end _GUISLICE_GEN_H
