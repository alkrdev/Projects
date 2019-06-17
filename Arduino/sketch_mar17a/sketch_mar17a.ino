#include <IRremote.h>
#include <IRremoteInt.h>
#include <IRremoteTools.h>

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  Serial.println(results.value, HEX);
}
