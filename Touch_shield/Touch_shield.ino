#include <FreeDefaultFonts.h>
#include <MCUFRIEND_kbv.h>
#include <mcufriend_serial.h>
#include <mcufriend_shield.h>
#include <mcufriend_special.h>
#include <mcufriend_special_2.h>

#include <Adafruit_GFX.h>
#include <UTFTGLUE.h>    
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;
#include <TouchScreen.h>


#define MINPRESSURE 10
#define MAXPRESSURE 1000

#if defined(__SAM3X8E__)
#undef __FlashStringHelper::F(string_literal)
#define F(string_literal) string_literal
#endif

#include "ColorName.h"
#include "Numpad.h"

uint8_t YP = A1;  // must be an analog pin, use "An" notation!
uint8_t XM = A2;  // must be an analog pin, use "An" notation!
uint8_t YM = 7;   // can be a digital pin
uint8_t XP = 6;   // can be a digital pin

uint16_t TS_LEFT = 920;
uint16_t TS_RT  = 150;
uint16_t TS_TOP = 940;
uint16_t TS_BOT = 120;


TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
UTFTGLUE myGLCD(0x0154,A2,A1,A3,A4,A0);
TSPoint tp;
bool state=true;
uint16_t identifier;



void setup(void)
{
  
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
  
  tft.begin(9600);
  tft.reset();
  identifier = tft.readID();
  int width=tft.width();

  Serial.begin(9600);
  
  
  ts = TouchScreen(XP, YP, XM, YM, 300);     //call the constructor AGAIN with new values.
  tft.begin(identifier);

  tft.setRotation(0);
  tft.fillScreen(BLACK);
  tft.setTextColor(LIME);

  TFTKeypad(0,0, tft.width(), tft.height(), YELLOW, BLACK);

  
}

void loop()
{
  int width=tft.width();
  uint16_t xpos, ypos;  //screen coordinates
  tp = ts.getPoint();   //tp.x, tp.y are ADC values
  
  // if sharing pins, you'll need to fix the directions of the touchscreen pins
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  pinMode(XP, OUTPUT);
  pinMode(YM, OUTPUT);
  //    digitalWrite(XM, HIGH);
  //    digitalWrite(YP, HIGH);
  // we have some minimum pressure we consider 'valid'
  // pressure of 0 means no pressing!

  if (tp.z > MINPRESSURE && tp.z < MAXPRESSURE) {
    ypos = map(tp.x, 930, 170, 0, 320);
    xpos = map(tp.y, 180, 900, 0, 240);
    int num = GetNumpadValue(0,0, tft.width(), tft.height(), xpos, ypos);
    
    TFTWrite(50, 250, "   ");
    tft.setTextColor(WHITE, BLACK);
    TFTWrite(50, 250, String(num));
    Serial.println(String(num));
  }
  //tft.println("VERTICAL SCROLL UP");
  //uint16_t maxscroll=250;
  //for (uint16_t i = 1; i <= maxscroll; i++) {
  //tft.vertScroll(0, maxscroll, -i);
  //tft.invertDisplay(!state);
  delay(20);
  }
   





