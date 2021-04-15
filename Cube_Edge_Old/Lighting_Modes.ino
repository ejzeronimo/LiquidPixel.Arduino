//////////////////////////////          OFF
void off()
{
  for ( currentpixel = 0; currentpixel <= pixelLen; currentpixel++)
  {
    strip.setPixelColor(currentpixel, 0, 0, 0);
  }
  strip.show();
  currentpixel = 0;
}
//////////////////////////////          SOLID
void solid(int red, int green, int blue)
{
  for ( currentpixel = 0; currentpixel <= pixelLen; currentpixel++)
  {
    strip.setPixelColor(currentpixel, red, green, blue);
  }
  strip.show();
  currentpixel = 0;
}
//////////////////////////////          RANDOM CLOUDY BLOBS
void randomcloudyblobs(int red, int green, int blue, int delayy)
{
  if (!Serial.available())
  {
    randomposition = random(pixelLen);
    rando = random(pixelLen);
    curro = rando;
    currentpixel = randomposition;
    strip.setPixelColor(randomposition, red, green, blue);
    strip.setPixelColor(randomposition + 1, red, green, blue);
    strip.setPixelColor(randomposition - 1, red, green, blue);
    strip.setBrightness(brightness);
    strip.show();
    for (brightness = 0; brightness <= 255;  brightness++)
    {
      strip.setPixelColor(randomposition, red, green, blue);
      strip.setPixelColor(randomposition + 1, red, green, blue);
      strip.setPixelColor(randomposition - 1, red, green, blue);
      strip.setBrightness(brightness);
      strip.show();
      delay(2);
    }
    strip.setPixelColor(rando, red, green, blue);
    strip.setPixelColor(rando + 1, red, green, blue);
    strip.setPixelColor(rando - 1, red, green, blue);
    strip.setBrightness(rando);
    strip.show();
    for (brightness = 0; brightness <= 255;  brightness++)
    {
      strip.setPixelColor(rando, red, green, blue);
      strip.setPixelColor(rando + 1, red, green, blue);
      strip.setPixelColor(rando - 1, red, green, blue);
      strip.setBrightness(brightness);
      strip.show();
      delay(2);
    }
    for (brightness = 255; brightness >= 0;  brightness--)
    {
      strip.setPixelColor(randomposition, red, green, blue);
      strip.setPixelColor(randomposition + 1, red, green, blue);
      strip.setPixelColor(randomposition - 1, red, green, blue);
      strip.setBrightness(brightness);
      strip.show();
      delay(2);
    }
    strip.setPixelColor(currentpixel, 0, 0, 0);
    strip.setPixelColor(currentpixel + 1, 0, 0, 0);
    strip.setPixelColor(currentpixel - 1, 0, 0, 0);
    strip.show();
    for (brightness = 255; brightness >= 0;  brightness--)
    {
      strip.setPixelColor(rando, red, green, blue);
      strip.setPixelColor(rando + 1, red, green, blue);
      strip.setPixelColor(rando - 1, red, green, blue);
      strip.setBrightness(brightness);
      strip.show();
      delay(2);
    }
    strip.setPixelColor(curro, 0, 0, 0);
    strip.setPixelColor(curro + 1, 0, 0, 0);
    strip.setPixelColor(curro - 1, 0, 0, 0);
    strip.show();
  }
  else
  {
    strip.setBrightness(255);
  }
}
//////////////////////////////          FLASH
void flash(byte r, byte g, byte b, int delayMs) {
  if (!Serial.available())
  {
    for (int i = pixelLen; i >= 0; i--) {
      strip.setPixelColor(i, r, g, b);
    };
    strip.show();
    delay(delayMs);
    for (int i = pixelLen; i >= 0; i--) {
      strip.setPixelColor(i, 0, 0, 0);
    };
    strip.show();
    delay(delayMs);
  }
}
//////////////////////////////          SWEEP
void sweep(byte r, byte g, byte b, int delayMs) {
  if (!isWalking && isWalkingDone)
  {
    // top on
    for (int i = rightEdgeStart + vertEdgeLen; i <= rightEdgeStart + vertEdgeLen + horizEdgeLen; i++)
    {
      strip.setPixelColor(i, r, g, b);
    }
    strip.show();

    delay(delayMs);

    // top off
    for (int i = rightEdgeStart + vertEdgeLen; i <= rightEdgeStart + vertEdgeLen + horizEdgeLen; i++)
    {
      strip.setPixelColor(i, 0, 0, 0);
    }
    strip.show();
  }

  if (!isWalking)
  {
    // bottom on
    for (int i = rightEdgeStart - horizEdgeLen; i < rightEdgeStart; i++)
    {
      strip.setPixelColor(i, r, g, b);
    }
    strip.show();

    delay(delayMs);

    // bottom off
    for (int i = rightEdgeStart - horizEdgeLen; i < rightEdgeStart; i++)
    {
      strip.setPixelColor(i, 0, 0, 0);
    }
    strip.show();
  }

  isWalkingDone = false;
  isWalking = true;

  // right walk
  strip.setPixelColor(rightWalk, r, g, b);
  if (rightWalk != horizEdgeLen)
    strip.setPixelColor(rightWalk - 1, 0, 0, 0);

  // left walk
  strip.setPixelColor(leftWalk, r, g, b);
  if (leftWalk != leftEdgeStart)
    strip.setPixelColor(leftWalk + 1, 0, 0, 0);
  strip.show();

  strip.show();
  rightWalk++;
  leftWalk--;
  delay(delayMs);

  // walk is done
  if (rightWalk == rightEdgeStart + vertEdgeLen || leftWalk == leftEdgeStart - vertEdgeLen)
  {
    isWalking = false;
    isWalkingDone = true;

    strip.setPixelColor(rightWalk - 1, 0, 0, 0);
    strip.setPixelColor(leftWalk + 1, 0, 0, 0);
    strip.show();

    rightWalk = rightEdgeStart;
    leftWalk = leftEdgeStart;
  }
}
//////////////////////////////          TWINKLE
void randomtwinkle(int red, int green, int blue, int delayy)
{
  if (!Serial.available())
  {
    randomposition = random(pixelLen);
    rando = random(pixelLen);
    currentpixel = randomposition;
    curro = rando;

    strip.setPixelColor(randomposition, red, green, blue);
    strip.setBrightness(brightness);
    strip.show();
    for (brightness = 0; brightness <= 255;  brightness++)
    {
      strip.setPixelColor(randomposition, red, green, blue);
      strip.setBrightness(brightness);
      strip.show();
      delay(2);
    }

    strip.setPixelColor(rando, red, green, blue);
    strip.setBrightness(brightness);
    strip.show();
    for (brightness = 0; brightness <= 255;  brightness++)
    {
      strip.setPixelColor(rando, red, green, blue);
      strip.setBrightness(brightness);
      strip.show();
      delay(2);
    }
    delay(delayy);
    for (brightness = 255; brightness >= 0;  brightness--)
    {
      strip.setPixelColor(randomposition, red, green, blue);
      strip.setBrightness(brightness);
      strip.show();
      delay(2);
    }
    strip.setPixelColor(currentpixel, 0, 0, 0);
    strip.show();

    for (brightness = 255; brightness >= 0;  brightness--)
    {
      strip.setPixelColor(rando, red, green, blue);
      strip.setBrightness(brightness);
      strip.show();
      delay(2);
    }

    strip.setPixelColor(curro, 0, 0, 0);
    strip.show();
    delay(delayy);
  }
  else
  {
    strip.setBrightness(255);
  }
}
//////////////////////////////          RANDOM TWINKLE
void randomtwinklerainbow(int delayy)
{

  if (!Serial.available())
  {
    randomposition = random(pixelLen);
    rando = random(pixelLen);
    currentpixel = randomposition;
    curro = rando;
    int red = random(255);
    int green = random(255);
    int blue = random(255);
    strip.setPixelColor(randomposition, red, green, blue);
    strip.setBrightness(brightness);
    strip.show();
    for (brightness = 0; brightness <= 255;  brightness++)
    {
      strip.setPixelColor(randomposition, red, green, blue);
      strip.setBrightness(brightness);
      strip.show();
      delay(2);
    }

    strip.setPixelColor(rando, red, green, blue);
    strip.setBrightness(brightness);
    strip.show();
    for (brightness = 0; brightness <= 255;  brightness++)
    {
      strip.setPixelColor(rando, red, green, blue);
      strip.setBrightness(brightness);
      strip.show();
      delay(2);
    }
    delay(delayy);
    for (brightness = 255; brightness >= 0;  brightness--)
    {
      strip.setPixelColor(randomposition, red, green, blue);
      strip.setBrightness(brightness);
      strip.show();
      delay(2);
    }
    strip.setPixelColor(currentpixel, 0, 0, 0);
    strip.show();

    for (brightness = 255; brightness >= 0;  brightness--)
    {
      strip.setPixelColor(rando, red, green, blue);
      strip.setBrightness(brightness);
      strip.show();
      delay(2);
    }

    strip.setPixelColor(curro, 0, 0, 0);
    strip.show();
    delay(delayy);

  }
  else
  {
    strip.setBrightness(255);
  }
}
//////////////////////////////          RANDOM FLASH
void randomflash(int delayMs) {
  if (!Serial.available())
  {
    byte r = random(255);
    byte g = random(255);
    byte b = random(255);
    for (int i = pixelLen; i >= 0; i--) {
      strip.setPixelColor(i, r, g, b);
    };
    strip.show();
    delay(delayMs);
    for (int i = pixelLen; i >= 0; i--) {
      strip.setPixelColor(i, 0, 0, 0);
    };
    strip.show();
    delay(delayMs);
  }
}
//////////////////////////////          THEATER CHASE
void theaterChase(byte r, byte g, byte b, int delayMs)
{
  if (!Serial.available())
  {
    for (int j = 0; j < 10; j++) { //do 10 cycles of chasing
      for (int q = 0; q < 3; q++) {
        for (int i = 0; i < pixelLen; i = i + 3) {
          strip.setPixelColor(i + q, r, g, b);  //turn every third pixel on
        }
        strip.show();

        delay(delayMs);

        for (int i = 0; i < pixelLen; i = i + 3) {
          strip.setPixelColor(i + q, 0, 0, 0);    //turn every third pixel off
        }
      }
    }
  }
}
//////////////////////////////          CHROMA
void chroma(int Delay)
{
  if (!Serial.available())
  {
    byte r;
    byte g;
    byte b;
    for (int i = pixelLen; i >= 0; i--)
    {
      r = random(255);
      b = random(255);
      g = random(255);
      strip.setPixelColor(i, r, g, b);
    };
    strip.show();
    delay(Delay);
  }
}

//////////////////////////////          FADE IN
void fadein(byte r, byte g, byte b, int delayMs)
{
  if (!Serial.available())
  {
    if (flashdone)
    {
      go = true;
    }
    if (go && !flashdone)
    {
      for (int brightness = 0; brightness < 255; brightness++)
      {
        for (int i = 0; i < pixelLen; i++)
        {
          strip.setPixelColor(i, r, g, b);
        };
        strip.setBrightness(brightness);
        strip.show();
        delay(delayMs);
      }
      go = false;
      flashdone = true;
    }
    strip.setBrightness(255);
    go = false;
    flashdone = true;
  }
}
//////////////////////////////          FADE OUT
void fadeout(byte r, byte g, byte b, int delayMs)
{
  if (!Serial.available())
  {
    if (flashdone)
    {
      go = true;
    }
    if (go && !flashdone)
    {
      for (int brightness = 255; brightness > 0; brightness--)
      {
        for (int i = 0; i < pixelLen; i++)
        {
          strip.setPixelColor(i, r, g, b);
        };
        strip.setBrightness(brightness);
        strip.show();
        delay(delayMs);
      }
      go = false;
      flashdone = true;
    }
    for (int i = 0; i < pixelLen; i++)
    {
      strip.setPixelColor(i, 0, 0, 0);
    };
    strip.setBrightness(255);
    go = false;
    flashdone = true;
  }
}
//////////////////////////////          SUDDEN FLASH
void sudden(byte r, byte g, byte b, int delayMs)
{
  if (!Serial.available())
  {
    if (go && !flashdone)
    {
      for ( currentpixel = 0; currentpixel <= pixelLen; currentpixel++)
      {
        strip.setPixelColor(currentpixel, r, g, b);
      }
      strip.show();
      currentpixel = 0;
      strip.show();
      delay(delayMs);
      for ( currentpixel = 0; currentpixel <= pixelLen; currentpixel++)
      {
        strip.setPixelColor(currentpixel, 0, 0, 0);
      }
      strip.show();
      currentpixel = 0;
      go = false;
      flashdone = true;
    }
    if (flashdone)
    {
      go = true;
    }
  }
}
//////////////////////////////          RANDOM BREATH
void randomfadeinandout(int delayMs)
{
  if (!Serial.available())
  {
    int r = random(255);
    int g = random(255);
    int bui = random(255);
    for (int b = 0; b < 255; b++) {
      for (int i = 0; i < pixelLen; i++) {
        strip.setPixelColor(i, r * b / 255, g * b / 255, bui * b / 255) ;
      };
      strip.show();
      delay(delayMs);
    };

    for (int b = 255; b > 0; b--) {
      for (int i = 0; i < pixelLen; i++) {
        strip.setPixelColor(i, r * b / 255, g * b / 255, bui * b / 255);
      };
      strip.show();
      delay(delayMs);
    };
  }
}
//////////////////////////////          BREATH
void rgbFadeInAndOut(byte r, byte g, byte bui, int delayMs)
{
  if (!Serial.available())
  {
    for (int b = 0; b < 255; b++) {
      for (int i = 0; i < pixelLen; i++) {
        strip.setPixelColor(i, r * b / 255, g * b / 255, bui * b / 255);
      };
      strip.show();
      delay(delayMs);
    };

    for (int b = 255; b > 0; b--) {
      for (int i = 0; i < pixelLen; i++) {
        strip.setPixelColor(i, r * b / 255, g * b / 255, bui * b / 255);
      };
      strip.show();
      delay(delayMs);
    };
  }
}
//////////////////////////////          FALLING STARS
void fallingstars(byte r, byte g, byte b, int delayMs)
{
  int trailLen = 10;//round(pixelLen/delayMs);
  if (!Serial.available())
  {
    for (int pos = 0; pos < (pixelLen + trailLen); pos++)
    {
      strip.setPixelColor(pos, r, g, b);
      for (int i = 0; i < trailLen; i++)
      {
        int rf = round(r / (i * i));
        int gf = round(g / (i * i));
        int bf = round(b / (i * i));
        int curpos = pos - i;
        strip.setPixelColor(curpos, rf , gf , bf );
        delay(2);
        strip.show();
      };
      delay(delayMs);
      strip.setPixelColor(pos - trailLen, 0, 0, 0);
    };
  }
}
//////////////////////////////          CHRISTMAS CHASE
void xmaschase(int delayMs)
{
  if (!Serial.available())
  {
    for (int j = 0; j < 10; j++) { //do 10 cycles of chasing
      for (int q = 0; q < 3; q++) {
        for (int i = 0; i < pixelLen; i = i + 3) {
          strip.setPixelColor(i + q, 255, 0, 0);  //turn every third pixel on
        }
        strip.show();

        delay(delayMs);

        for (int i = 0; i < pixelLen; i = i + 3) {
          strip.setPixelColor(i + q, 0, 255, 0);    //turn every third pixel off
        }
      }
    }
  }
}
//////////////////////////////          PONG
void pong(byte r, byte g, byte b, int delayMs)
{
  int trailLen = 6;
  if (!Serial.available())
  {
    for (int pos = 0; pos < (pixelLen); pos++)
    {
      strip.setPixelColor(pos, r, g, b);
      for (int i = 0; i < trailLen; i++)
      {
        int rf = round(r / i);
        int gf = round(g / i);
        int bf = round(b / i);
        int curpos = pos - i;
        strip.setPixelColor(curpos, rf , gf , bf );
        delay(2);
        strip.show();
      };
      delay(delayMs);
      strip.setPixelColor(pos - trailLen, 0, 0, 0);
    };
    for (int pos = pixelLen; pos > 0; pos--)
    {
      strip.setPixelColor(pos, r, g, b);
      for (int i = 0; i < trailLen; i++)
      {
        int rf = round(r / i);
        int gf = round(g / i);
        int bf = round(b / i);
        int curpos = pos + i;
        strip.setPixelColor(curpos, rf , gf , bf );
        delay(2);
        strip.show();
      };
      delay(delayMs);
      strip.setPixelColor(pos + trailLen, 0, 0, 0);
    };
  }
}
//////////////////////////////          WATERFALL
void waterfall(byte r, byte g, byte b, int delayMs)
{
  int i;
  if (!Serial.available())
  {
    while (currentpixel <= pixelLen)
    {
      strip.setPixelColor(currentpixel, r, g, b);
      currentpixel++;
      strip.show();
      delay(delayMs);
    }
    currentpixel = 0;
  }
}
//////////////////////////////          LIGHTNING
void lightning(byte r, byte g, byte b, int delayMs)
{
  //turn on
  //turn off
  //turn on for real
  //off
  if (!Serial.available())
  {
    if (go && !flashdone)
    {
      solid(r, g, b);
      delay(round(delayMs / 6)); // how long on
      off();
      delay(round(delayMs / 4)); // how long off
      solid(r, g, b);
      delay(round(delayMs / 2)); // how long on
      off();
      go = false;
      flashdone = true;
    }
    if (flashdone)
    {
      go = true;
    }
  }
}
//////////////////////////////          WAVES
void waves(byte r, byte g, byte b, int delayMs)
{
  int trailLen = 10;//round(pixelLen/delayMs);
  int swellLen = 2;
  if (!Serial.available())
  {
    for (int pos = 0; pos < (pixelLen + trailLen); pos++)
    {
      for (int i = 1; i < swellLen; i++)
      {
        int rs = round(r / ((i * i)));
        int gs = round(g / ((i * i)));
        int bs = round(b / ((i * i)));
        int prepos = pos + i;
        strip.setPixelColor(prepos, rs , gs , bs );
        delay(2);
        strip.show();
      };

      strip.setPixelColor(pos, r, g, b);

      for (int i = 1; i < trailLen; i++)
      {
        int rf = round(r / ((i * i) / 4));
        int gf = round(g / ((i * i) / 4));
        int bf = round(b / ((i * i) / 4));
        int curpos = pos - i;
        strip.setPixelColor(curpos, rf , gf , bf );
        delay(2);
        strip.show();
      };
      delay(delayMs);
      strip.setPixelColor(pos - (4 * trailLen), 0, 0, 0);
    };
  }
}
//////////////////////////////          LEVELS
void levels(byte r, byte g, byte b, int delayMs)
{
  int trailLen = pixelLen;
  int maxheight = round(pixelLen / random(1, 5));
  if (!Serial.available())
  {

    for (int pos = -1; pos <= maxheight; pos++)
    {
      strip.setPixelColor(pos, r, g, b);
      for (int i = 0; i < trailLen; i++)
      {
        int rf = round(r / i);
        int gf = round(g / i);
        int bf = round(b / i);
        int curpos = pos + i;
        strip.setPixelColor(curpos, rf , gf , bf );
        delay(2);
        strip.show();
      };
      delay(delayMs);
    };
    for (int pos = maxheight; pos >= 0; pos--)
    {
      strip.setPixelColor(pos, r, g, b);
      for (int i = 0; i < trailLen; i++)
      {
        int rf = round(r / i);
        int gf = round(g / i);
        int bf = round(b / i);
        int curpos = pos + i;
        strip.setPixelColor(curpos, rf , gf , bf );
        delay(2);
        strip.show();
      };
      delay(delayMs);
    };
  }
}
//////////////////////////////          RAIN
void rain(byte r, byte g, byte b, int delayMs)
{
  int trailLen = 1;//round(pixelLen/delayMs);
  int offset = 4 + trailLen;
  int k;
  if (!Serial.available())
  {
    for (int q = 0; q < offset; q++)
    {
      for (int i = 0; i < (pixelLen + trailLen + 1); i = i + offset)
      {
        strip.setPixelColor(i + q, r, g, b);  //turn every third pixel on
        for (int w = 0; w < trailLen; w++)
        {
          k = w + 1;
          int rf = round(r / (k * k));
          int gf = round(g / (k * k));
          int bf = round(b / (k * k));
          int curpos = i + q - k;
          strip.setPixelColor(curpos, rf , gf , bf );
          strip.setPixelColor(i + q - (trailLen + 1), 0, 0, 0);
          delay(2);
        };
      }
      strip.show();
      delay(delayMs);
    }
  }
}
//////////////////////////////          SOUNDSYNC
void soundsync(byte r, byte g, byte b, byte sound)
{
  strip.setBrightness(sound);
  strip.show();
//  for ( int i = 0; i <= pixelLen; i++)
//  {
//    strip.setPixelColor(i, r, g, b);
//    strip.show();
//  }
}
