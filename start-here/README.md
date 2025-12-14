<h1>Getting started</h1>

<h1>(Windows 11-based)</h1>


<h2>First, what do we need?</h2>

* Arduino IDE
* Firmware.bin from lilygo
* esptool.py/ .exe (Python-install)
* T-Dongle S3


<h2>Nuke the example firmware</h2>

<p>We want to nuke (remove/ destroy) the example firmware that's on the dongle by default</p>
<p>To do this, we will use the esptool.py or esptool.exe</p>
<p>Enter the following command into a new cmd</p>
<code>esptool.exe --chip esp32s3 --port COM[ENTER_COM_NUMBER_HERE] erase-flash</code>

<p>Tip: to find the port number, go to device-manager in the windows settings, and look for:</p>

<code>Ports (COM & PLT)</code>
<p>If the dongle is connected through usb, it will show up here with a number, example: COM4</p>


<h2>Uploading most recent firmware</h2>

<p>Now we removed the example firmware, we will flash the most recent firmware to it</p>
<p>Go to the official Github repo:</p>
<code>https://github.com/Xinyuan-LilyGO/T-Dongle-S3/tree/main</code>
<p>And download the repo as a .zip</p>
<p>Unpack the zip file (folder "T-Dongle-S3-main" expected as result)</p>
<p>Now, in the unzipped folder, goto the "firmware" sub-folder</p>
<p>Click on the .bat file, called ("flash to device")</p>
<p>Now, wait untill promted with "Press any key to continue..." BUT DO NOT CONTINUE</p>
<p>Close the terminal, and wait a few seconds before unplugging the dongle</p>
<p>Plug the dongle back in, and the most recent firmware should start working at that moment, or re-start, to be sure it works</p>

<h2>Install Arduino IDE</h2>

<p>Now, try to install the Arduino IDE</p>


<h2>Add example project</h2>

<p>To get started, we can move these provided example-folders to the Arduino environment:</p>
<code>"bb_spi_lcd_demo" -> documents/Arduino/</code>
<code>"bb_spi_lcd-master" -> documents/Arduino/libraries/</code>

<h2>Configure Arduino IDE</h2>

<p>Now we will configure the Arduino IDE, to start, we will goto File -> Preferences</p>
<p>Open the window of "More board manager url's" and paste in the following line:</p>
<code>https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json</code>

<p>Now, goto "Tools -> Board -> Board manager" and enter the following search query:</p>
<code>ESP32</code>
<p>Now you will see a board lib named "esp32" by "Espressif Systems" Install that one (At the moment v3.3.4)</p>
<p>The install might take some time. (~10 minutes)</p>

<p>After that, we will select the correct board. In this case, the dongle is seen as this board:</p>
<code>ESP32S3 Dev Module</code>
<p>So goto "Tools -> Board" and select the correct board</p>
<p>And don't forget to set the port in here as well. ("Port" -> select the correct and active COM-port of the dongle)</p>


<h2>Upload the example sketch</h2>

<p>We already moved the example sketch to the correct location, and will use it now</p>
<p>Goto "File -> Sketch book -> 'bb_spi_lcd_demo'"</p>

<h2>And done!</h2>

<p>If there were no errors, you're done!</p>
<p>The display can display now, and you can extend from here on out. You can flash this to the dongle now!</p>