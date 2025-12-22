//IMPORTANT
// First follow the steps in the folder "./start-here" before trying this example
// It will not work properly if you didn't follow the setup there.

#include <USB.h>
#include <USBHIDKeyboard.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <bb_spi_lcd.h>

const char* ssid = "wireless-keyboard";
const char* ssidPw = "keyboard123";

USBHIDKeyboard Keyboard;
BB_SPI_LCD lcd;
WebServer server(80);

void lcdWriteLine(int index, const char* txt) {
  lcd.setCursor(0, index * 10);
  lcd.print(txt);
}

void cls() {
  lcd.fillScreen(TFT_BLACK);
}

void handleRoot() {
  server.send(200, "text/html", "<h1>T-Dongle S3 Lilygo wireless-keyboard example</h1><p>By wwwqr-000</p><p>Usage: '/send?val=test123' sends the keystrokes + enter</p>");
}

void valReceiver() {
  if (!server.hasArg("val")) {
    server.send(404, "text/html", "No 'val' argument given (Type: 'GET')");
    return;
  }

  String val = server.arg("val");
  Keyboard.println(val);
  server.send(200, "text/html", "Tried to send the given keystrokes");
}

void setup() {
  //Display setup
  lcd.begin(DISPLAY_T_DONGLE_S3);
  lcd.setRotation(90);
  lcd.fillScreen(TFT_BLACK);
  lcd.setTextColor(TFT_GREEN);
  lcd.setFont(NULL);
  lcd.setTextSize(3);
  //

  lcdWriteLine(0, "Initializing...");
  
  //Wifi setup
  WiFi.softAP(ssid, ssidPw);
  lcdWriteLine(1, ("IP: " + WiFi.softAPIP().toString()).c_str());
  //

  //Keyboard setup
  USB.begin();
  Keyboard.begin();
  lcdWriteLine(2, "Keyboard ready!");
  //

  //Website setup
  server.on("/", handleRoot);
  server.on("/send", valReceiver);
  server.begin();
  lcdWriteLine(3, "Website ready!");
  //

  lcdWriteLine(4, "Initializing done!");
  //Keyboard.println("Hello from T-Dongle-S3!");
}

void loop() {
  server.handleClient();
}
