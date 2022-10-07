#include <DmxSimple.h>

const int taster1 = 7;
const int taster2 = 8;
const int dmxout = 3;
const int player = 5;
const int led_on = 10;
const int led_buzzer = 11;
int tasterstatus = 0;

void setup() {
  pinMode(taster1, INPUT);
  pinMode(taster2, INPUT);
  pinMode(player, OUTPUT);

  DmxSimple.usePin(3);
  DmxSimple.maxChannel(4);

  Serial.begin(9600);

  digitalWrite(player, HIGH);
  digitalWrite(led_on, HIGH);
}

void loop() {
  
  if (tasterstatus == 0 && digitalRead(taster1) == HIGH) {
    tasterstatus = 1;
    digitalWrite(led_buzzer, HIGH);
    DmxSimple.write(1, 255); //DMX Kanal 1 auf 255
    digitalWrite(player, LOW);
    delay(100);
    digitalWrite(player, HIGH);
    delay (2000);
    digitalWrite(led_buzzer, LOW);
    tasterstatus = 0;
  }
  if (tasterstatus == 0 && digitalRead(taster2) == HIGH) {
    tasterstatus = 1;
    digitalWrite(led_buzzer, HIGH);
    DmxSimple.write(2, 255); //DMX Kanal 2 auf 255
    digitalWrite(player, LOW);
    delay(100);
    digitalWrite(player, LOW);
    delay (2000);
    tasterstatus = 0;
  }


}
