/*
Arduino Leonardo Joystick!

*/


JoyState_t joySt;
#include <Esplora.h>
#include <USBAPI.h>

int joyX = 0;
int joyY = 0;
int deadZone = 30;
bool invertX = false;
bool invertY = false;

void setup()
{
  pinMode(13, OUTPUT);
  //Serial.begin(9600);


  joySt.xAxis = 0;
  joySt.yAxis = 0;
  /*joySt.zAxis = 0;
  joySt.xRotAxis = 0;
  joySt.yRotAxis = 0;
  joySt.zRotAxis = 0;
  joySt.throttle = 0;
  joySt.rudder = 0;
  joySt.hatSw1 = 0;
  joySt.hatSw2 = 0;
  joySt.buttons = 0;
*/
}


void loop()
{

  joyX = map(Esplora.readJoystickX(), -512, 512, 255, -255);
  joyY = map(Esplora.readJoystickY(), 512, -512, 255, -255);

  if (invertX) {
    joyX = joyX * -1;
  }
  if (invertY) {
    joyY = joyY * -1;
  }

  if (joyX > deadZone || joyX < -deadZone) {
    joySt.xAxis = joyX;
    if (joyX > 10) {
      //Serial.println("RIGHT");
    }
    else {
      //Serial.println("LEFT");
    }
  }
  else {
    joySt.xAxis = 0;
  }
  if (joyY > deadZone || joyY < -deadZone) {
    joySt.yAxis = joyY;
    if (joyY > 10) {
      //Serial.println("DOWN");
    }
    else {
      //Serial.println("UP");
    }
  }
  else {
    joySt.yAxis = 0;
  }

  /*
  	joySt.xAxis = random(255);
  	joySt.yAxis = random(255);
  	joySt.zAxis = random(255);
  	joySt.xRotAxis = random(255);
  	joySt.yRotAxis = random(255);
  	joySt.zRotAxis = random(255);
  	//joySt.throttle = random(255);
  	joySt.rudder = random(255);

  	joySt.throttle++;


  	joySt.buttons <<= 1;
  	if (joySt.buttons == 0)
  		joySt.buttons = 1;

  	joySt.hatSw1++;
  	joySt.hatSw2--;

  	if (joySt.hatSw1 > 8)
  		joySt.hatSw1 = 0;
  	if (joySt.hatSw2 > 8)
  		joySt.hatSw2 = 8;

  	delay(100);

  	if (joySt.throttle > 127)
  		digitalWrite(13, HIGH);
  	else
  		digitalWrite(13, LOW);
  */
  delay(10);
  // Call Joystick.move
  Joystick.setState(&joySt);

}
