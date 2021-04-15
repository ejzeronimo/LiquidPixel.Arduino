#include <FastLED.h>
#define PIN 13
#define pixelLen 25//MUST BE SET BEFORE DOWNLOAD
#define id 0//MUST BE SET BEFORE DOWNLOAD
#define MAX_SEGMENT_LENGTH_IN_BYTES 37
#define MAX_PAYLOAD_LENGTH 9
CRGB strip[pixelLen];
bool oneTimePerCommand = true;
byte numberOfBytesInSegment = 0;
byte reconstructionMode = 0;
int lastPayloadDelimit = -1;
byte segmentBytesTemp[MAX_SEGMENT_LENGTH_IN_BYTES];

struct LPC {
  byte Target;
  byte Type;
  byte Payload[MAX_PAYLOAD_LENGTH];
  byte Mode;
  int Delay;
};

LPC lpcCommand;
LPC lpcTemp;

enum Mode : byte {
  Off = 0,
  Solid, //1
  RandomCloudy,//2
  Flash,//3
  Sweep, //4
  Twinkle, //5
  RandomTwinkle,//6
  RandomFlash,//7
  TheaterChase, //8
  Chroma, //9
  FadeIn, //10
  FadeOut,//11
  SuddenFlash,//12
  RandomBreath,//13
  Breath,//14
  FallingStars,//15
  ChristmasChase,//16
  Pong,//17
  Waterfall,//18
  Lightning,//19
  Waves,//20
  Levels,//21
  Rain,//22
  Pause,//23
  SoundSync//24
};

boolean smartDelay(int ms) {
  long startMs = millis(); //get the time
  while (millis() < (startMs + ms)) {
    yield(); //do nothing?
    if (Serial.available()) {
      return false; //back out to get new command
    }
  }
  return true;
}

void setup() {
  Serial.begin(57600);

  FastLED.addLeds<NEOPIXEL, PIN>(strip, pixelLen).setCorrection(TypicalLEDStrip);

  waterfallRainbow(50);
  solid(0,0,0);

  Serial.println("Box_#" + (String)id + "_Online");
}

void loop() {
  if (Serial.available()) {
    byte byteFromSerialPort = Serial.read();
    ProcessByte(byteFromSerialPort);
  }
  else if ((lpcCommand.Target == id || lpcCommand.Target == 0)) {
    chooser(lpcCommand.Mode, lpcCommand.Payload[0], lpcCommand.Payload[1], lpcCommand.Payload[2], lpcCommand.Delay);
  }
}
