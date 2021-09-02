/*
  IST Lasers arduino setup
*/

int laserAPin = 9;    // Laser1 connected to digital pin 9
int laserBPin = 13;    // Laser2 connected to digital pin 13


int laserAPwm = 128;    // Laser 1 Pwm 1000mW ( 0 = off, 255 = 1000mW, 128 = 500mW)
int laserBPwm = 36;    // Laser 2 Pwm 3500mW ( 0 = off, 255 = 3500mW, 73 = 1000mW, 36 = 500mW)


String raw;
int value;



void setup() {
  Serial.begin(115200);
  Serial.setTimeout(1);
  analogWrite(laserAPin, laserAPwm);
  analogWrite(laserBPin, laserBPwm);

}


void loop() {
  while (!Serial.available());

  raw = Serial.readString();
  
  if (raw.startsWith("A")) {
    raw.remove(0,1);
    value = raw.toInt();
    analogWrite(laserAPin, value);
  }
  
  else if (raw.startsWith("B")) {
    raw.remove(0,1);
    value = raw.toInt();
    analogWrite(laserBPin, value);
  }
  
}
