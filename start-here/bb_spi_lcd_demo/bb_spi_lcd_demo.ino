#include <bb_spi_lcd.h>
#include "Roboto_Black_40.h"

const uint16_t colorArr[8] = {0x7e0, 0x67e0, 0xffe0, 0xfe40, 0xfbc0, 0xf800, 0xf81f, 0xffff};

BB_SPI_LCD lcd;//Initialize LCD obj

void setup() {
  lcd.begin(DISPLAY_T_DONGLE_S3); //Init display + backlight
  lcd.setRotation(90);// Switch the screen around, so text is displayed the right way (Or the wrong one, you can change it here)
  lcd.fillScreen(TFT_BLACK);
  lcd.setFreeFont(&Roboto_Black_40);
}

void loop() {
int cIndex = 0;
  while (true) {
    lcd.setTextColor(colorArr[cIndex & 7]);// Set the color of the text to the assigned color in the array, based on the iColor-index
    cIndex++;
    lcd.setCursor(0, 40);
    lcd.print("wwwqr");
    lcd.setCursor(0, 70);
    lcd.print("000");
    delay(500);
  }
}
