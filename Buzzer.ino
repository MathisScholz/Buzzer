#include <DmxSimple.h>

const int taster1 = 7;
const int taster2 = 8;
const int dmxout = 3;
int tasterstatus = 0;

void setup() {
  pinMode(taster1, INPUT);
  pinMode(taster2, INPUT);

  DmxSimple.usePin(3);
  DmxSimple.maxChannel(4);

  Serial.begin(9600);
}

void loop() {
  if (tasterstatus == 0 && digitalRead(taster1) == HIGH) {
    tasterstatus = 1;
    DmxSimple.write(1, 255); //DMX Kanal 1 auf 255
    //Sound abspielen
    delay (2000);
    tasterstatus = 0;
  }
  if (tasterstatus == 0 && digitalRead(taster2) == HIGH) {
    tasterstatus = 1;
    DmxSimple.write(2, 255); //DMX Kanal 2 auf 255
    //Sound abspielen
    delay (2000);
    tasterstatus = 0;
  }


}
