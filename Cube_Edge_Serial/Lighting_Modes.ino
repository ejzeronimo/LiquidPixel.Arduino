////////////////////////////////          OFF
//void off() {
//  fill_solid( strip, pixelLen, CRGB(0, 0, 0));
//  FastLED.show();
//}
//////////////////////////////          SOLID
void solid(int r, int g, int b) {
  fill_solid( strip, pixelLen, CRGB(r, g, b));
  FastLED.show();
}
//////////////////////////////          RANDOM CLOUDY BLOBS
void randomCloudyBlobs(int r, int g, int b, int delayMs) {
  int blobCount = random16(3, pixelLen / 7);
  int blobPos[blobCount];

  for (int i = 0; i < blobCount; i++) {
    blobPos[i] = random16(pixelLen);
    fill_solid(strip + blobPos[i] - 1, 3, CRGB(r, g, b));
  }

  FastLED.show();

  for (int br = 0; br < random16(30, 50);  br++) {
    nscale8(strip, pixelLen, 255 - br);

    FastLED.show();
    smartDelay(delayMs);
  }
}
//////////////////////////////          FLASH
void flash(byte r, byte g, byte b, int delayMs) {
  fill_solid(strip, pixelLen, CRGB(r, g, b));
  FastLED.show();
  smartDelay(delayMs);
  fill_solid(strip, pixelLen, CRGB(0, 0, 0));
  FastLED.show();
  smartDelay(delayMs);
}
//////////////////////////////          SWEEP
void sweep(byte r, byte g, byte b, int delayMs) {
  //depreciated, will get rid of!
}
//////////////////////////////          TWINKLE
void randomTwinkle(int r, int g, int b, int delayMs) {
  int blobCount = random16(3, pixelLen / 5);
  int blobPos[blobCount];

  for (int i = 0; i < blobCount; i++) {
    blobPos[i] = random16(pixelLen);
    fill_solid(strip + blobPos[i], 1, CRGB(r, g, b));
  }

  FastLED.show();

  for (int br = 0; br < random16(30, 50);  br++) {
    nscale8(strip, pixelLen, 255 - br);

    FastLED.show();
    smartDelay(delayMs);
  }
}
//////////////////////////////          RANDOM TWINKLE
void randomTwinkleRainbow(int delayMs)
{
  int blobCount = random16(3, pixelLen / 5);
  int blobPos[blobCount];

  for (int i = 0; i < blobCount; i++) {
    blobPos[i] = random16(pixelLen);
    fill_solid(strip + blobPos[i], 1, CRGB(random16(255), random16(255), random16(255)));
  }

  FastLED.show();

  for (int br = 0; br < random16(30, 50);  br++) {
    nscale8(strip, pixelLen, 255 - br);

    FastLED.show();
    smartDelay(delayMs);
  }
}
//////////////////////////////          RANDOM FLASH
void randomFlash(int delayMs) {
  fill_solid(strip, pixelLen, CRGB(random16(255), random16(255), random16(255)));
  FastLED.show();
  smartDelay(delayMs);
  fill_solid(strip, pixelLen, CRGB(0, 0, 0));
  FastLED.show();
  smartDelay(delayMs);
}
//////////////////////////////          THEATER CHASE
void theaterChase(byte r, byte g, byte b, int delayMs)
{
  int i = 0;
  if (strip[0].r != 0 || strip[0].g != 0 || strip[0].b != 0) {
    i = 1;
  }
  fill_solid(strip, pixelLen, CRGB(0, 0, 0));
  for ( i; i < pixelLen; i += 2) {
    fill_solid(strip + i, 1, CRGB(r, g, b));
  }
  FastLED.show();
  smartDelay(delayMs);
}
//////////////////////////////          CHROMA
void chroma(int delayMs)
{
  for (int i = 0; i < 255; i++) {
    fill_rainbow( strip, pixelLen, i);
    FastLED.show();
    smartDelay(delayMs);
  }
}

//////////////////////////////          FADE IN
void fadeIn(byte r, byte g, byte b, int delayMs) {
  CRGB temp[pixelLen];
  for (int i = 0; i < pixelLen; i++) {
    temp[i] = CRGB(r, g, b);
  }

  for (int i = 0; i < 255; i++) {
    nblend(strip, temp, pixelLen, 25);
    smartDelay(delayMs);
    FastLED.show();
  }
}
//////////////////////////////          FADE OUT
void fadeOut(int delayMs) {

  for (int i = 0; i < 255; i++) {
    fadeToBlackBy (strip, pixelLen, 25);
    smartDelay(delayMs);
    FastLED.show();
  }
}
//////////////////////////////          SUDDEN FLASH
void sudden(byte r, byte g, byte b, int delayMs)
{
  if (oneTimePerCommand)
  {
    fill_solid( strip, pixelLen, CRGB(r, g, b));
    FastLED.show();
    smartDelay(delayMs);
    fill_solid( strip, pixelLen, CRGB(0, 0, 0));
    FastLED.show();
    oneTimePerCommand = false;
  }
}
//////////////////////////////          RANDOM BREATH
void randomBreath(int delayMs) {
  CRGB rand = CRGB(random16(255), random16(255), random16(255));
  for (int i = 0; i < 255; i += 5) {
    fill_solid(strip, pixelLen, rand);
    fadeLightBy (strip, pixelLen, 255 - i);
    FastLED.show();
    smartDelay(delayMs);
  }
  for (int i = 0; i < 255; i += 5) {
    fill_solid(strip, pixelLen, rand);
    fadeLightBy (strip, pixelLen, i);
    FastLED.show();
    smartDelay(delayMs);
  }
}
//////////////////////////////          BREATH
void rgbFadeInAndOut(byte r, byte g, byte b, int delayMs) {
  for (int i = 0; i < 255; i += 5) {
    fill_solid( strip, pixelLen, CRGB(r, g, b));
    fadeLightBy (strip, pixelLen, 255 - i);
    FastLED.show();
    smartDelay(delayMs);
  }
  for (int i = 0; i < 255; i += 5) {
    fill_solid( strip, pixelLen, CRGB(r, g, b));
    fadeLightBy (strip, pixelLen, i);
    FastLED.show();
    smartDelay(delayMs);
  }
}
//////////////////////////////          FALLING STARS -- redo at some point
void fallingStars(byte r, byte g, byte b, int delayMs) {
  int trailLen = 10;
  for (int pos = 0; pos < (pixelLen + trailLen); pos++) {
    if (pos < pixelLen) {
      strip[pos] = CRGB(r, g, b);
    }
    for (int i = 1; i < trailLen; i++) {
      int rf = round(r / (i * i));
      int gf = round(g / (i * i));
      int bf = round(b / (i * i));
      int curpos = pos - i;
      if (curpos >= 0 && curpos < pixelLen) {
        strip[curpos] = CRGB(rf, gf, bf);
      }
      smartDelay(2);
      FastLED.show();
    }
    smartDelay(delayMs);
    if ((pos - trailLen) >= 0 && (pos - trailLen) < pixelLen) {
      strip[pos - trailLen] = CRGB(0, 0, 0);
    }
  }
}
//////////////////////////////          CHRISTMAS CHASE -- kill at some point
void xmasChase(int delayMs) {
  int i = 0;
  if (strip[0].g != 255) {
    i = 1;
  }
  fill_solid(strip, pixelLen, CRGB(0, 255, 0));
  for ( i; i < pixelLen; i += 2) {
    fill_solid(strip + i, 1, CRGB(255, 0, 0));
  }
  FastLED.show();
  smartDelay(delayMs);
}
//////////////////////////////          PONG -- redo at some point
void pong(byte r, byte g, byte b, int delayMs) {
  int trailLen = 6;
  for (int pos = 0; pos < (pixelLen); pos++) {
    if (pos < pixelLen) {
      strip[pos] = CRGB(r, g, b);
    }
    for (int i = 1; i < trailLen; i++) {
      int rf = round(r / i);
      int gf = round(g / i);
      int bf = round(b / i);
      int curpos = pos - i;
      if (curpos >= 0 && curpos < pixelLen) {
        strip[curpos] = CRGB(rf, gf, bf);
      }
      smartDelay(2);
      FastLED.show();
    }
    smartDelay(delayMs);
    if ((pos - trailLen) >= 0 && (pos - trailLen) < pixelLen) {
      strip[pos - trailLen] = CRGB(0, 0, 0);
    }
  }
  for (int pos = pixelLen; pos > 0; pos--) {
    if (pos < pixelLen) {
      strip[pos] = CRGB(r, g, b);
    }
    for (int i = 1; i < trailLen; i++) {
      int rf = round(r / i);
      int gf = round(g / i);
      int bf = round(b / i);
      int curpos = pos + i;
      if (curpos >= 0 && curpos < pixelLen) {
        strip[curpos] = CRGB(rf, gf, bf);
      }
      smartDelay(2);
      FastLED.show();
    }
    smartDelay(delayMs);
    if ((pos + trailLen) >= 0 && (pos + trailLen) < pixelLen) {
      strip[pos + trailLen] = CRGB(0, 0, 0);
    }
  }
}
//////////////////////////////          WATERFALL
void waterfall(byte r, byte g, byte b, int delayMs)
{
  int i = 0;
  while (i <= pixelLen) {
    fill_solid( strip, i, CRGB(r, g, b));
    i++;
    FastLED.show();
    smartDelay(delayMs);
  }
}
//////////////////////////////          WATERFALL RAINBOW --add to options
void waterfallRainbow(int delayMs)
{
  int i = 0;
  while (i <= pixelLen) {
    fill_rainbow( strip, i, 0);
    i++;
    FastLED.show();
    smartDelay(delayMs);
  }
}
//////////////////////////////          LIGHTNING
void lightning(byte r, byte g, byte b, int delayMs) {
  if (oneTimePerCommand) {
    solid(r, g, b);
    smartDelay(round(delayMs / 6)); // how long on
    solid(0,0,0);
    smartDelay(round(delayMs / 4)); // how long off
    solid(r, g, b);
    smartDelay(round(delayMs / 2)); // how long on
    solid(0,0,0);
    oneTimePerCommand = false;
  }
}
//////////////////////////////          WAVES -- redo at some point
void waves(byte r, byte g, byte b, int delayMs) {
  int trailLen = 10;
  int swellLen = 2;
  for (int pos = 0; pos < (pixelLen + trailLen); pos++) {
    for (int i = 1; i < swellLen; i++) {
      int rs = round(r / (i * i));
      int gs = round(g / (i * i));
      int bs = round(b / (i * i));
      int prepos = pos + i;
      if (prepos >= 0 && prepos < pixelLen) {
        strip[prepos] = CRGB(rs, gs, bs);
      }
      smartDelay(2);
      FastLED.show();
    }
    if (pos < pixelLen) {
      strip[pos] = CRGB(r, g, b);
    }
    for (int i = 1; i < trailLen; i++) {
      int rf = round(r / (float)((i * i) / 4));
      int gf = round(g / (float)((i * i) / 4));
      int bf = round(b / (float)((i * i) / 4));
      int curpos = pos - i;
      if (curpos >= 0 && curpos < pixelLen) {
        strip[curpos] = CRGB(rf, gf, bf);
      }
      smartDelay(2);
      FastLED.show();
    }
    smartDelay(delayMs);
    if ((pos - (4 * trailLen)) >= 0 && (pos - (4 * trailLen)) < pixelLen) {
      strip[pos - (4 * trailLen)] = CRGB(0, 0, 0);
    }
  }
}
//////////////////////////////          LEVELS -- redo at some point
void levels(byte r, byte g, byte b, int delayMs) {
  int trailLen = pixelLen;
  int maxheight = round(pixelLen / random16(1, 5));
  for (int pos = -1; pos <= maxheight; pos++) {
    if (pos < pixelLen) {
      strip[pos] = CRGB(r, g, b);
    }
    for (int i = 1; i < trailLen; i++) {
      int rf = round(r / i);
      int gf = round(g / i);
      int bf = round(b / i);
      int curpos = pos + i;
      if (curpos >= 0 && curpos < pixelLen) {
        strip[curpos] = CRGB(rf, gf, bf);
      }
      smartDelay(2);
      FastLED.show();
    }
    smartDelay(delayMs);
  }
  for (int pos = maxheight; pos >= 0; pos--) {
    if (pos < pixelLen) {
      strip[pos] = CRGB(r, g, b);
    }
    for (int i = 1; i < trailLen; i++) {
      int rf = round(r / i);
      int gf = round(g / i);
      int bf = round(b / i);
      int curpos = pos + i;
      if (curpos >= 0 && curpos < pixelLen) {
        strip[curpos] = CRGB(rf, gf, bf);
      }
      smartDelay(2);
      FastLED.show();
    }
    smartDelay(delayMs);
  }
}
//////////////////////////////          RAIN -- redo at some point
void rain(byte r, byte g, byte b, int delayMs) {
  int trailLen = 1;//round(pixelLen/delayMs);
  int offset = 4 + trailLen;
  int k;
  for (int q = 0; q < offset; q++) {
    for (int i = 0; i < (pixelLen + trailLen + 1); i = i + offset) {
      if ((i + q) >= 0 && (i + q) < pixelLen) {
        strip[i + q] = CRGB(r, g, b);
      }
      for (int w = 0; w < trailLen; w++) {
        k = w + 1;
        int rf = round(r / (k * k));
        int gf = round(g / (k * k));
        int bf = round(b / (k * k));
        int curpos = i + q - k;
        if (curpos >= 0 && curpos < pixelLen) {
          strip[curpos] = CRGB(rf, gf, bf);
        }
        if ((i + q - (trailLen + 1)) >= 0 && (i + q - (trailLen + 1)) < pixelLen) {
          strip[i + q - (trailLen + 1)] = CRGB(0, 0, 0);
        }
        smartDelay(2);
      }
    }
    FastLED.show();
    smartDelay(delayMs);
  }
}
//////////////////////////////          SOUNDSYNC
void soundsync(byte r, byte g, byte b)
{
  //strip.setBrightness(sound);
  //strip.show();
  //  for ( int i = 0; i <= pixelLen; i++)
  //  {
  //    strip.setPixelColor(i, r, g, b);
  //    strip.show();
  //  }
}
