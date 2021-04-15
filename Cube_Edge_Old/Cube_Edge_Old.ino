#include <Adafruit_NeoPixel.h>
#define PIN 6;
int pixelLen = 60;//25//49//42//30 //25 for Headbox 30 for Clockbox
Adafruit_NeoPixel strip = Adafruit_NeoPixel(pixelLen, 6, NEO_RGB + NEO_KHZ800); //RGB for cables, GRB for strips
int currentpixel = 0;
int chainpos = 0;
int r = 255;
int g = 255;
int b = 255;
int rando;
int curro;
int brightness = 0;
int flashswitch = 0;
int sweepswitcher = 0;
int randomposition = 0;
String moder;
int gtemp;
int btemp;
int rtemp;
int dtemp;
int horizEdgeLen = 11;
int vertEdgeLen = 16;
int leftEdgeStart = 0;
int leftWalk = 0;
int rightEdgeStart = 0;
int rightWalk = 0;
bool isWalking = false;
bool isWalkingDone = false;
bool go = true;
bool flashdone = false;
bool IsConnected = true;
byte Cycler = 1;

enum CommandDelimeters : byte
{
  Td = (byte)'T',
  Cd = (byte)'C',
  Rd = (byte)'R',
  Gd = (byte)'G',
  Bd = (byte)'B',
  Md = (byte)'M',
  Dd = (byte)'D',
  Xd = (byte)'X',
  Sd = (byte)'S',
  EocD = (byte)'~'
};

enum ReconstructionMode : byte
{
  Unknown = 0,
  Tm,
  Cm,
  Rm,
  Gm,
  Bm,
  Mm,
  Dm,
  Xm,
  Sm,
  EocM
};

enum Type : byte
{
  Cmd = 0,
  Data,
  Live,
  Ext
};

enum Mode : byte
{
  Off = 0,
  Solid,
  RandomCloudy,//4
  Flash,//8
  Sweep, //3
  Twinkle,
  RandomTwinkle,//5?
  RandomFlash, //1 //7
  TheaterChase,
  Chroma,
  FadeIn,
  FadeOut,
  SuddenFlash,
  RandomBreath,
  Breath,
  FallingStars, //2 //6
  ChristmasChase,
  Pong,
  Waterfall,
  Lightning,
  Waves,
  Levels,
  Rain,
  Pause,
  SoundSync
  //3 male, 1 female
};

struct lpc
{
  byte Type;
  byte Box;
  byte R;
  byte G;
  byte B;
  byte Mode;
  byte Delay;
  bool IsRandom;
  byte Sound;
};

const byte MAX_SEGMENT_LENGTH_IN_BYTES = 3;
byte numberOfBytesInSegment = 0;
byte reconstructionMode = (byte)Unknown;
byte segmentBytesTemp[MAX_SEGMENT_LENGTH_IN_BYTES] = {0, 0, 0};
lpc lpc;


void diagnostics(int info)
{
  if (info == 1 && Serial.available())
  {
    Serial.println(lpc.Mode);
  }
  if (info == 99)
  {
    Serial.println("Disconnecting");
    IsConnected = false;
  }
}
void setup()
{
  Serial.begin(9600);
  strip.begin();
  strip.show();
  randomSeed(123);
  while (currentpixel <= pixelLen)
  {
    strip.setPixelColor(currentpixel, 43, 219, 82); //codename wintergreen
    currentpixel++;
    strip.show();
    delay(50);
  }
  currentpixel = 0;
  off();
  Serial.println("Box_Online");
}

void loop()
{
  if (IsConnected)
  {
    if (Serial.available())
    {
      byte byteFromSerialPort = Serial.read();
      Serial.write(byteFromSerialPort);
      ProcessByte(byteFromSerialPort);
      flashdone = false;
      currentpixel = 0;
    }
    if (lpc.Box == chainpos || lpc.Box == 0)
    {
      chooser(lpc.Mode, lpc.R, lpc.G, lpc.B, lpc.Delay, lpc.Sound);
      diagnostics(lpc.Type);
    }
  }
  else
  {
    chooser(Cycler / 10000, 255, 255, 255, 100, 0);
    Cycler++;
    if (Cycler > 14)
    {
      Cycler = 1;
    }
  }
}
