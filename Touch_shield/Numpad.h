void TFTWrite(int x, int y, String text) {
  tft.setCursor(x, y);
  tft.println(text);
}
void TFTKeypad(int x, int y, int width, int height,  int keyColor, int fontColor){
  tft.setTextColor(fontColor, keyColor);
  tft.setTextSize(2);
  tft.setTextWrap(false);
  
  int xcord, ycord;
  int keyHeight = (height-15)/4;
  int keyWidth = (width-12)/3;
  tft.fillRect(x, y, width, height, BLACK);
  int i=1;
  for(ycord = y+3; ycord < y+height-5; ycord+=keyHeight+3){    
    for(xcord = x+3; xcord < x+width-5; xcord+=keyWidth+3){
      tft.fillRoundRect(xcord, ycord, keyWidth, keyHeight, 10, keyColor);
      if(i==10) TFTWrite(xcord+10, ycord+(keyHeight/3), "*");
      else if(i==11) TFTWrite(xcord+10, ycord+(keyHeight/3), "10");
      else if(i==12) TFTWrite(xcord+10, ycord+(keyHeight/3), "#");
      else TFTWrite(xcord+10, ycord+(keyHeight/3), String(i));
      i++;
    }
  }
}
int GetNumpadValue(int x, int y, int width, int height,  int c_x, int c_y){
  int xcord, ycord;
  int keyHeight = (height-15)/4;
  int keyWidth = (width-12)/3;
  int i=1;
  for(ycord = y+3; ycord < y+height-5; ycord+=keyHeight+3){    
    for(xcord = x+3; xcord < x+width-5; xcord+=keyWidth+3){
      if(c_x > xcord && c_x < (xcord+keyWidth) && c_y > ycord && c_y < (ycord+keyHeight)){
        return i;
      }
      i++;
    }
  }
  return -1;
}



