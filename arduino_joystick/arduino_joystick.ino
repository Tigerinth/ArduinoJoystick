///////////11 BUTTON 1 JOYSTICK///////////

#include <Joystick.h>

#define RANGE 30

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_GAMEPAD,
                         //           TURKISH                         ENGLISH
                         
  11, 0,                 //buton sayısı, hat switch sayısı //0    number of buttons, number of hot switches
  true, true, false,     //x ve y ama z yok                       X axis, y axis, z axis
  false, false, false,   // rx ry rz yok                          rx, ry, rz
  false, false,          // rudder gaz yok                        rudder, gas
  false, false, false);  //gaz fren steering yok                  gas, brake, steering

//const bool initAutoSendState = true;
//int ZGazkolu = 0;
void setup() {
  //Buton pinleri    | Button pins
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);


  Joystick.begin();
  Joystick.setXAxisRange(-1, 1);
  Joystick.setYAxisRange(-1, 1);
  

  Serial.begin(115200);

}


int lastButtonState[12] = {0,0,0,0,0,0,0,0,0,0,0,0}; //+1
int X,oldX;
int Y,oldY;

void loop() {
  //pin değerlerini oku    |     read pin values 
  for(int index = 0; index < 12; index++) //+1
  {
    int currentButtonState = !digitalRead(index +2);
    if (currentButtonState != lastButtonState[index])
    {
      Joystick.setButton(index, currentButtonState);
      lastButtonState[index] = currentButtonState;
      
    }
  }
  //joystick pinleri || joystick pins
  X=analogRead(A1);
  Y=analogRead(A0);
  if ((X!=oldX) || (Y!=oldY))
  {
    if ((X>=512-RANGE) && (X<=512+RANGE))
    {Joystick.setXAxis(0);}
    else
      if (X>512+RANGE)
        {Joystick.setXAxis(-1);}
      else
        {Joystick.setXAxis(1);}
        
    if ((Y>=512-RANGE) && (Y<=512+RANGE))
    {Joystick.setYAxis(0);}
    else
      if (Y>512+RANGE)
        {Joystick.setYAxis(-1);}
      else
        {Joystick.setYAxis(1);}
    oldX=X; oldY=Y;
        
      
  }
  

  delay(10);

}
