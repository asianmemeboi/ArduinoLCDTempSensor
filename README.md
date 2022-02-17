# Arduino LCD Temperature Sensor
Basically a pastebin for code and to help later
Let me explain: The liquidcrystal.ino file is used to display temperature onto a Liquid Crystal Display.
You will need: Arduino with a power cord, A Liquid Crystal Display, and a Temperature sensor connected to the Arduino

# Buttons
With this code you can press the select button on the LCD for help.
This will display what all the buttons do.
Pressing the UP button will start recording info to EEPROM.
Pressing the DOWN button will stop recording info to EEPROM.
You can change the interval variable in liquidcrystal.ino to change how often the Arduino uploads info to EEPROM.
It is default set to 10 minutes and it is in milliseconds.

# Errors that may occur
To read from the EEPROM you can run the eepromread.ino file.
Do not open the two files in a same instance or an error will pop up saying something like "redefinition of blahblahblah".
You should move the two files to different folders and run them seperately.

# ENJOY!
This code is pretty useful and can be used as a base for other projects (maybe)
You can also export stuff from EEPROM to a spreadsheet.
I am not sure how to though but you can probably find a way online.
