// 2022 FALL CISS 21 - Final Presentation (Hacked by USB) [PRESENTED!]
// robonxt
//
// Song: <SPIN ETERNALLY> by <camellia> https://www.youtube.com/watch?v=IuRwqB9NwVQ

#include "Keyboard.h"
#include "Mouse.h"

int responseDelay = 10; // response delay of the mouse, in ms
bool isRun = true;
int8_t xReading, yReading;
float rad = 0;
long counts = 0;

int cSize = 10;


void resetMouse() {
  delay(10);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(100);
  Keyboard.releaseAll();
  // type notepad + ENTER
  delay(200);
  Keyboard.print("notepad");
  Keyboard.press(KEY_RETURN);
  delay(200);
  Keyboard.releaseAll();

  // type stuff here
  delay(500);
  Keyboard.print(" ----- EvilFubarinoMini: Bad Mouse and Keyboard -----");
  Keyboard.print(" 2022 FALL CISS 21 - Final Presentation (Hacked by USB) \n robonxt \n Song: <SPIN ETERNALLY> by <camellia> https://www.youtube.com/watch?v=IuRwqB9NwVQ \n");

  Keyboard.print("Mouse and Keyboard permissions lost in ");
  for (int i = 5; i > 0; i--)
  {
    delay(600 - (i*100));
    Keyboard.print(i);
    Keyboard.print("...");
  }
  Keyboard.print("\n\nGET HACKED\n\n");
  for (int i = 0; i < 1000; i++)
  {
    Mouse.move(-10, -10, 0);
    delay(1);
  }
  for (int i = 0; i < 100; i++)
  {
    Mouse.move(5, 5, 0);
    delay(1);
  }
}

void setup() {
  randomSeed(analogRead(0));
  pinMode(PIN_BTN1, INPUT); // Use the PRG button!
  Serial.begin(9600);
  // initialize mouse and keyboard control:
  Mouse.begin();
  Keyboard.begin();
  delay(1000);
  while (!(digitalRead(PIN_BTN1) == LOW))
  {
  }

  resetMouse();
}

void MoveMouse()
{
  // read and scale the two axes:
  xReading = (int8_t)(sin(rad) * cSize);
  yReading = (int8_t)(cos(rad) * cSize);
//  Serial.print(xReading);
//  Serial.print(" ");
//  Serial.print(yReading);
//  Serial.print(" ");
//  Serial.print(rad, 2);
//  Serial.println();

  // 0 - 360 degrees is one time around a circle
  // 0 - 2*PI() radians is one time around a circle
  // 0 - 6.282 radians is one time around a circle
  rad += 0.06282; // 1/100 of a circle

  if (rad >= 6.282) {
    counts++;
    rad = 0; // reset to the start of a circle
    cSize = random(2, 20);
    responseDelay = random(5, 10);
    Keyboard.print("SPIN ETERNALLY FOR: ");
    Keyboard.print(counts);
    Keyboard.print(" TIMES! (0x");
    Keyboard.print(cSize);
    Keyboard.print('x');
    Keyboard.print(responseDelay);
    Keyboard.print("m) :D\n");
    if ((counts % 10) == 0)
    {
      resetMouse();
    }
  }
  // if the mouse control state is active, move the mouse:
  Mouse.move(xReading, yReading, 0);
  delay(responseDelay);
}

void loop() {
  if (isRun == true)
  {
    MoveMouse();
  }
  if (digitalRead(PIN_BTN1) == LOW)
  {
    delay(50);
    if (digitalRead(PIN_BTN1) == LOW)
    {
      if (isRun == true) {
        for (int i = 0; i < 50; i++)
        {
          Keyboard.print("HOW DARE YOU! ");
        }
        Keyboard.println("");
        Keyboard.releaseAll();
      }
      else
      {
        Keyboard.println("SPIN SPIN SPIN SPIN SPIN SPIN");
      }
      isRun = !isRun;
    }
  }
}
