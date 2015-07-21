#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library

#define CLK 8  // MUST be on PORTB! (Use pin 11 on Mega)
#define LAT A3
#define OE  9
#define A   A0
#define B   A1
#define C   A2

#define FRAME 64
#define YOFFBOARD 16 //first coordinate not on board. Acts as upper bound.

#define Y1MAX 10
#define Y1MIN 2
#define Y2MAX 11
#define Y2MIN 2
#define Y3MAX 9
#define Y3MIN 3
#define Y4MAX 7
#define Y4MIN 1
#define Y5MAX 13
#define Y5MIN 5
#define Y6MAX 9
#define Y6MIN 2
#define Y7MAX 12
#define Y7MIN 5


RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

void setup() {
  Serial.begin(9600);
  matrix.begin();
  
  matrix.drawLine(0, 12, 31, 12, matrix.Color888(0, 0, 10));
  matrix.drawLine(0, 13, 31, 13, matrix.Color888(0, 0, 30));
  matrix.drawLine(0, 14, 31, 14, matrix.Color888(0, 0, 80));
}

//So. Many. Variables.
int shouldFade = 1;
//Streak Variables 
int y1 = Y1MIN;
int y2 = Y2MIN;
int y3 = Y3MIN;
int y4 = Y4MIN;
int y5 = Y5MIN;
int y6 = Y6MIN;
int y7 = Y7MIN;
//Swoop 1 Variables
int xpos1 = 18;
int ypos1 = 13;
int xpos2 = 17;
int ypos2 = 14;
int xpos3 = 21;
int ypos3 = 3;
int xpos4 = 21;
int ypos4 = 4;
int xpos5 = 21;
int ypos5 = 5;
//Swoop 2 Variables
int xpos6 = 10;
int ypos6 = 13;
int xpos7 = 9;
int ypos7 = 13;
int xpos8 = 4;
int ypos8 = 7;
int xpos9 = 5;
int ypos9 = 7;
int xpos10 = 6;
int ypos10 = 7;
//Swoop 3 Variables
int xpos11 = 30;
int ypos11 = 11;
int xpos12 = 31;
int ypos12 = 11;
int xpos13 = 22;
int ypos13 = 6;
int xpos14 = 23;
int ypos14 = 6;
int xpos15 = 24;
int ypos15 = 6;

void loop() {
//getyourstreakon
  //background setup
  if (y7 != YOFFBOARD){
    matrix.drawLine(0, 12, 31, 12, matrix.Color888(0, 0, 10));
    matrix.drawLine(0, 13, 31, 13, matrix.Color888(0, 0, 30));
    matrix.drawLine(0, 14, 31, 14, matrix.Color888(0, 0, 80));
    delay(2000);

    if (shouldFade == 1) {
      for(int i=0; i< 255; i++) {
        matrix.drawCircle(16, 36, 24, matrix.Color888(0, i, 0));
        matrix.drawCircle(16, 35, 24, matrix.Color888(0, i, 0));
        delay(16);
      }
      shouldFade = 0;
    } 
    else {
      matrix.drawCircle(16, 36, 24, matrix.Color888(0, 255, 0));
      matrix.drawCircle(16, 35, 24, matrix.Color888(0, 255, 0));   
    }
    
    // Streak 1
    if(y1 != YOFFBOARD && shouldFade == 0){
      // start from top, move down
      matrix.drawPixel(6, y1, matrix.Color888(204, 255, 229));
      // wait one frame
      delay(FRAME);
      // reset that current pixel
      matrix.drawPixel(6, y1, matrix.Color888(0, 0, 0));
      // increment y to go up 1 (down board)
      y1++;
      // reset at end of streak
      if (y1 > Y1MAX) y1 = YOFFBOARD;
    }
  
    // Streak 2
    if (y1 >= YOFFBOARD && y2 != YOFFBOARD){
      matrix.drawPixel(13, y2, matrix.Color888(204, 255, 229));
      delay(FRAME);
      matrix.drawPixel(13, y2, matrix.Color888(0, 0, 0));
      y2++;
      if (y2 > Y2MAX) y2 = YOFFBOARD;
    }
  
    // Streak 3
    if (y2 >= YOFFBOARD && y3 != YOFFBOARD){
      matrix.drawPixel(20, y3, matrix.Color888(204, 255, 229));
      delay(FRAME);
      matrix.drawPixel(20, y3, matrix.Color888(0, 0, 0));
      y3++;
      if (y3 > Y3MAX) y3 = YOFFBOARD;
    }
  
    // Streak 4
    if (y3 >= YOFFBOARD && y4 != YOFFBOARD){
      matrix.drawPixel(26, y4, matrix.Color888(204, 255, 229));
      delay(FRAME);
      matrix.drawPixel(26, y4, matrix.Color888(0, 0, 0));
      y4++;
      if (y4 > Y4MAX) y4 = YOFFBOARD;
    }
    // Streak 5
    if (y4 >= YOFFBOARD && y5 != YOFFBOARD){
      matrix.drawPixel(10, y5, matrix.Color888(204, 255, 229));
      delay(FRAME);
      matrix.drawPixel(10, y5, matrix.Color888(0, 0, 0));
      y5++;
      if (y5 > Y5MAX) y5 = YOFFBOARD;
    }
    // Streak 6
    if (y5 >= YOFFBOARD && y6 != YOFFBOARD){
      matrix.drawPixel(16, y6, matrix.Color888(204, 255, 229));
      delay(FRAME);
      matrix.drawPixel(16, y6, matrix.Color888(0, 0, 0));
      y6++;
      if (y6 > Y6MAX) y6 = YOFFBOARD;
    }
    // Streak 7
    if (y6 >= YOFFBOARD && y7 != YOFFBOARD){
      matrix.drawPixel(23, y7, matrix.Color888(204, 255, 229));
      delay(FRAME);
      matrix.drawPixel(23, y7, matrix.Color888(0, 0, 0));
      y7++;
      if (y7 > Y7MAX) y7 = YOFFBOARD;
    }  
  }
  
//swoopthereitis
  if(y7 == YOFFBOARD){
    //Background setup
    matrix.drawLine(0, 12, 31, 12, matrix.Color888(0, 0, 10));
    matrix.drawLine(0, 13, 31, 13, matrix.Color888(0, 0, 30));
    matrix.drawLine(0, 14, 31, 14, matrix.Color888(0, 0, 80));
    matrix.drawCircle(16, 36, 24, matrix.Color888(0, 255, 0));
    //Swoop 1, direction 1
    if (ypos1 > 6){
      matrix.drawPixel(xpos1, ypos1, matrix.Color888(0, 255, 0));
      matrix.drawPixel(xpos2, ypos2, matrix.Color888(0, 255, 0));
      delay(64);
      xpos1++;
      xpos2++;
      ypos1 = ypos1 - 2;
      ypos2 = ypos2 - 2;
    }
    //Swoop 1, direction 2
    if(ypos1 <= 6 && xpos5 != 0){
      matrix.drawPixel(22, 4, matrix.Color888(0, 255, 0));
      matrix.drawPixel(22, 5, matrix.Color888(0, 255, 0));
      matrix.drawPixel(21, 3, matrix.Color888(0, 255, 0));
      matrix.drawPixel(21, 4, matrix.Color888(0, 255, 0));
      matrix.drawPixel(xpos3, ypos3, matrix.Color888(0, 255, 0));
      matrix.drawPixel(xpos4, ypos4, matrix.Color888(0, 255, 0));
      matrix.drawPixel(xpos5, ypos5, matrix.Color888(255, 0, 127));
      delay(64);
      xpos3--;
      xpos4--;
      xpos5--;
    }
    
    if(xpos5 <= 0 && xpos6 > 4){
      //Background setup
      matrix.drawLine(0, 12, 31, 12, matrix.Color888(0, 0, 10));
      matrix.drawLine(0, 13, 31, 13, matrix.Color888(0, 0, 30));
      matrix.drawLine(0, 14, 31, 14, matrix.Color888(0, 0, 80));
      matrix.drawCircle(16, 36, 24, matrix.Color888(0, 255, 0));
      //Swoop 2, direction 1
      matrix.drawPixel(xpos6, ypos6, matrix.Color888(0, 255, 0));
      matrix.drawPixel(xpos7, ypos7, matrix.Color888(0, 255, 0));
      delay(64);
      xpos6--;
      ypos6--;
      xpos7--;
      ypos7--;
    }
    //Swoop 2, direction 2
    if(xpos6 <= 4){
      matrix.drawPixel(4, 7, matrix.Color888(0, 255, 0));
      matrix.drawPixel(5, 7, matrix.Color888(0, 255, 0));
      matrix.drawPixel(xpos8, ypos8, matrix.Color888(0, 255, 0));
      matrix.drawPixel(xpos9, ypos9, matrix.Color888(0, 255, 0));
      matrix.drawPixel(xpos10, ypos10, matrix.Color888(255, 0, 102));
      xpos8++;
      ypos8--;
      xpos9++;
      ypos9--;
      xpos10++;
      ypos10--;
    }
    if(ypos10 <= 0 && xpos11 > 21){
      //Background setup
      matrix.drawLine(0, 12, 31, 12, matrix.Color888(0, 0, 10));
      matrix.drawLine(0, 13, 31, 13, matrix.Color888(0, 0, 30));
      matrix.drawLine(0, 14, 31, 14, matrix.Color888(0, 0, 80));
      matrix.drawCircle(16, 36, 24, matrix.Color888(0, 255, 0));
      //Swoop 3, direction 1
      matrix.drawPixel(xpos11, ypos11, matrix.Color888(0, 255, 0));
      matrix.drawPixel(xpos12, ypos12, matrix.Color888(0, 255, 0));
      delay(64);
      xpos11 = xpos11 - 2;
      ypos11--;
      xpos12 = xpos12 - 2;
      ypos12--;
    }
    //Swoop 3, direction 2
    if(xpos11 <= 21){
      matrix.drawPixel(22, 6, matrix.Color888(0, 255, 0));
      matrix.drawPixel(23, 6, matrix.Color888(0, 255, 0));
      matrix.drawPixel(xpos13, ypos13, matrix.Color888(0, 255, 0));
      matrix.drawPixel(xpos14, ypos14, matrix.Color888(0, 255, 0));
      matrix.drawPixel(xpos15, ypos15, matrix.Color888(255, 0, 102));
      xpos13++;
      ypos13--;
      xpos14++;
      ypos14--;
      xpos15++;
      ypos15--;
    }
    if(ypos15 <= 0){
      delay(64);
      reset();
    }
  }
  matrix.swapBuffers(false);
}

void reset(){
  for (int x=0; x < 32; x++) {
    for (int y=0; y < 16; y++) {
     matrix.drawPixel(x,y, matrix.Color888(0, 0, 0));
    }
  }
  shouldFade = 1;
  //Streak Variables 
  y1 = Y1MIN;
  y2 = Y2MIN;
  y3 = Y3MIN;
  y4 = Y4MIN;
  y5 = Y5MIN;
  y6 = Y6MIN;
  y7 = Y7MIN;
  //Swoop 1 Variables
  xpos1 = 18;
  ypos1 = 13;
  xpos2 = 17;
  ypos2 = 14;
  xpos3 = 21;
  ypos3 = 3;
  xpos4 = 21;
  ypos4 = 4;
  xpos5 = 21;
  ypos5 = 5;
  //Swoop 2 Variables
  xpos6 = 10;
  ypos6 = 13;
  xpos7 = 9;
  ypos7 = 13;
  xpos8 = 4;
  ypos8 = 7;
  xpos9 = 5;
  ypos9 = 7;
  xpos10 = 6;
  ypos10 = 7;
  //Swoop 3 Variables
  xpos11 = 30;
  ypos11 = 11;
  xpos12 = 31;
  ypos12 = 11;
  xpos13 = 22;
  ypos13 = 6;
  xpos14 = 23;
  ypos14 = 6;
  xpos15 = 24;
  ypos15 = 6;
}
