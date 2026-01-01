//IMPORTANT
// First follow the steps in the folder "./start-here" before trying this example
// It will not work properly if you didn't follow the setup there.

#include <WiFi.h>
#include "name.h"

void setup() {
  WiFi.softAP(ssid, NULL);
}

void loop() {
  delay(1000);
}
