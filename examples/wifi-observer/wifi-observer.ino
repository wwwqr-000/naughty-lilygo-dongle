//IMPORTANT
// First follow the steps in the folder "./start-here" before trying this example
// It will not work properly if you didn't follow the setup there.

#include <WiFi.h>
#include <bb_spi_lcd.h>

//Defines
#define TFT_PURPLE  0x780F
//

const int maxRSSI = -70;    // -100 is almost no wifi-strength, 0 is as close as it can get.
const int msDelay = 2000;   //Delay in miliseconds between scans.

BB_SPI_LCD lcd;

void setup() {
  lcd.begin(DISPLAY_T_DONGLE_S3);
  lcd.setRotation(90);
  lcd.fillScreen(TFT_BLACK);

  lcd.setFont(NULL);
  lcd.setTextSize(2);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect(true);
  delay(100);
}

void writeRSSI(int index, int y) {
  lcd.setTextColor(TFT_PURPLE);
  lcd.setCursor(0, y);
  lcd.print(WiFi.RSSI(index));
}

void loop() {
  int n = WiFi.scanNetworks();//This will take a bit of time, so do this first before screen-refreshing.
  lcd.fillScreen(TFT_BLACK);
  lcd.setTextColor(TFT_GREEN);
  lcd.setCursor(0, 0);
  lcd.print("Filtered network list:");
  int y = 10;

  for (int i = 0; i < n; i++) {
    bool action = false;
    if (WiFi.RSSI(i) >= maxRSSI && WiFi.encryptionType(i) != WIFI_AUTH_OPEN) {
      writeRSSI(i, y);
      lcd.setTextColor(TFT_RED);
      lcd.setCursor(30, y);
      lcd.print(WiFi.SSID(i));
      action = true;
    }
    else if (WiFi.encryptionType(i) == WIFI_AUTH_OPEN) {
      writeRSSI(i, y);
      lcd.setTextColor(TFT_GREEN);
      lcd.setCursor(30, y);
      lcd.print(WiFi.SSID(i));
      action = true;
    }

    if (action) {
      y += 9;
      if (y > 120) {//Too many for screen display, stop to prevent buffer overflow
        break;
      }
    }
  }

  WiFi.scanDelete();
  delay(msDelay);
}
