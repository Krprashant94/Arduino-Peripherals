#include <MCUFRIEND_kbv.h>

#include <UTFTGLUE.h> 
#include <Adafruit_GFX.h>
#include <TouchScreen.h>


uint8_t YP = A1;  // must be an analog pin, use "An" notation!
uint8_t XM = A2;  // must be an analog pin, use "An" notation!
uint8_t YM = 7;   // can be a digital pin
uint8_t XP = 6;   // can be a digital pin



TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
UTFTGLUE myGLCD(0x0154,A2,A1,A3,A4,A0);
TSPoint tp;

uint16_t identifier;



void setup(void)
{
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
  myGLCD.fillScreen(0x0000);
  myGLCD.setColor(0,255,0);
  myGLCD.setRotation(0);
  myGLCD.setCursor(10, 295);
  myGLCD.println("    Lissures Figure Analyzer");
  myGLCD.setRotation(1);

  
}

void loop()
{
  myGLCD.setColor(255, 0, 0);
  myGLCD.drawLine(245, 0, 245, 240);  
  myGLCD.drawLine(290, 0, 290, 240);  
  int buf_s[240], buf_c[240];
  int sin_y, cos_y;
  int s_cu_y, c_cu_y;
  for(int d=0; d<90*90;d++){
    myGLCD.setColor(0,0,0);
    myGLCD.drawCircle(c_cu_y, 119, 2);
    myGLCD.drawCircle(s_cu_y, 119, 2);
    for (int i=1; i<240; i++)
    {
      myGLCD.setColor(0,0,0);
      myGLCD.drawPixel(buf_s[i], i);
      myGLCD.drawPixel(buf_c[i], i);
      
      sin_y = 45+(sin((((i+d)*3)*3.14)/180)*40);
      cos_y = 135+(tan((((i+d)*3)*3.14)/180)*40);
      
      buf_s[i] = sin_y;
      buf_c[i] = cos_y;
      if(i==119){
        s_cu_y = sin_y;
        c_cu_y = cos_y;
      }
      myGLCD.setColor(55,105,200);
      myGLCD.drawPixel(sin_y, i);
      myGLCD.drawPixel(cos_y, i);

      
    }
    myGLCD.setColor(255, 0, 0);
    myGLCD.drawLine(45, 0, 45, 240);  
    myGLCD.drawLine(135, 0, 135, 240);  
    myGLCD.drawLine(1, 119, 290, 119);
    
    myGLCD.setColor(0, 255, 0);
    myGLCD.drawCircle(c_cu_y, 119, 2);
    myGLCD.drawCircle(s_cu_y, 119, 2);

    myGLCD.setColor(0,255,255);
    myGLCD.setColor(0, 255, 0);
    myGLCD.drawCircle(s_cu_y+200, 119+c_cu_y-135, 1);
    delay(20);
  }


}


