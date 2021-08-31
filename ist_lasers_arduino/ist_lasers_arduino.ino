/*
  IST Lasers arduino setup
*/

int laser1Pin = 9;    // Laser1 connected to digital pin 9
int laser2Pin = 13;    // Laser2 connected to digital pin 13


int laser1Pwm = 128;    // Laser 1 Pwm 1000mW ( 0 = off, 255 = 1000mW, 128 = 500mW)
int laser2Pwm = 36;    // Laser 2 Pwm 3500mW ( 0 = off, 255 = 3500mW, 73 = 1000mW, 36 = 500mW)


int x;

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(1);
  analogWrite(laser1Pin, laser1Pwm);
  analogWrite(laser2Pin, laser2Pwm);

}


void loop() {
  while (!Serial.available());
  x = Serial.readString().toInt();
  Serial.print(x + 1);
}
