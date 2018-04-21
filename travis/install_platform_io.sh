# install PlatformIO
sudo pip install -U platformio
# update PlatformIO
platformio update

# install ArduinoJson (64), HttpClient (66), AUnit (2778), Crypto (1168) libraries
platformio lib -g install 64 66 2778 1168
