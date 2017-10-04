#include <Adafruit_NeoPixel.h>
#define PIN 6;
int pixelLen = 1;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(pixelLen, 6, NEO_GRB + NEO_KHZ800);
int currentpixel = 0;
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
  RandomCloudy,
  Flash,
  Sweep,
  Twinkle,
  RandomTwinkle,
  RandomFlash,
  TheaterChase,
  Chroma,
  FadeIn,
  FadeOut,
  SuddenFlash,
  RandomBreath,
  Breath
};

typedef struct lpc
{
  byte Type;
  byte Box;
  byte R;
  byte G;
  byte B;
  byte Mode;
  byte Delay;
  bool IsRandom;
};

const byte MAX_SEGMENT_LENGTH_IN_BYTES = 3;
byte numberOfBytesInSegment = 0;
byte reconstructionMode = (byte)Unknown;
byte segmentBytesTemp[MAX_SEGMENT_LENGTH_IN_BYTES] = {0, 0, 0};
lpc lpc;


void diagnostics()
{
  if (lpc.Type == 99)
  {
    Serial.println("Disconnected");
    IsConnected = false;
  }
  if (IsConnected)
  {
    Serial.println(lpc.Mode);
    delay(50);
  }
  else
  {
    Cycler++;
    delay(10000);
    if (Cycler > 14)
    {
      Cycler = 1;
    }
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
    strip.setPixelColor(currentpixel, 255, 57, 123);
    currentpixel++;
    strip.show();
    delay(50);
  }
  currentpixel = 0;
  Serial.println("Box_Online");
}

void loop()
{
  if (IsConnected)
  {
    if (Serial.available())
    {
      byte byteFromSerialPort = Serial.read();
      ProcessByte(byteFromSerialPort);
      flashdone = false;
    }
    chooser(lpc.Mode, lpc.R, lpc.G, lpc.B, lpc.Delay);
    diagnostics();
  }
  else
  {
    chooser(Cycler, 255, 255, 255, 100);
  }
}
