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
//////////////////////////////          SWEEP
void sweep(byte r, byte g, byte b, byte delayMs) {
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
//////////////////////////////          THEATER CHASE
void theaterChase(byte r, byte g, byte b, byte delayMs)
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

//////////////////////////////          FADE IN
void fadein(byte r, byte g, byte b, byte delayMs)
{
  if (brightness <= 255) {

    for (int i = 0; i < 58; i++) {
      strip.setPixelColor(i, r, g, b);
    };

    strip.setBrightness(brightness);
    strip.show();

    ++brightness;
    delay(delayMs);
  }
}
//////////////////////////////          FADE OUT
void fadeout(byte r, byte g, byte b, byte delayMs) {
  if (brightness >= 0)
  {

    for (int i = 0; i < pixelLen; i++) {
      strip.setPixelColor(i, r, g, b);
    };

    strip.setBrightness(brightness);
    strip.show();

    --brightness;
    delay(delayMs);
  }
  if (brightness <= 0)
  {
    for ( currentpixel = 0; currentpixel <= pixelLen; currentpixel++)
    {
      strip.setPixelColor(currentpixel, 0, 0, 0);
    }
    strip.show();
    currentpixel = 0;
    strip.setBrightness(255);
  }

}
//////////////////////////////          SUDDEN FLASH
void sudden(byte r, byte g, byte b, byte delayMs)
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
//////////////////////////////          RANDOM BREATH
void randomfadeinandout(byte delayMs)
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
void rgbFadeInAndOut(byte r, byte g, byte bui, byte delayMs)
{
  if (Serial.available())
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
void fallingstars(byte r, byte g, byte b, byte delayMs)
{
  int trailLen = 6;
  if (!Serial.available())
  {
    for(int pos = 0; pos < (pixelLen + trailLen); pos++)
    {
      strip.setPixelColor(pos,r,g,b);
      for(int i = 0; i < trailLen; i++)
      {
        int rf = round(r/i);
        int gf = round(g/i);
        int bf = round(b/i);
        int curpos = pos - i;
        strip.setPixelColor(curpos, rf , gf , bf );
        delay(2);
        strip.show();
      };
      delay(delayMs);
      off();
    };
  }
}
