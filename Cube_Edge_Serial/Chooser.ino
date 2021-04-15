void chooser(byte moded, byte R, byte G, byte B, byte De)
{
  switch (moded)
  {
    case Off:
      solid(0, 0, 0);
      break;
    case Solid:
      solid(R, G, B);
      break;
    case RandomCloudy:
      randomCloudyBlobs(R, G, B, De);
      break;
    case Flash:
      flash(R, G, B, De);
      break;
    case Sweep:
      //empty bc it is gone
      break;
    case Twinkle:
      randomTwinkle(R, G, B, De);
      break;
    case RandomTwinkle:
      randomTwinkleRainbow(De);
      break;
    case TheaterChase:
      theaterChase(R, G, B, De);
      break;
    case RandomFlash:
      randomFlash(De);
      break;
    case Chroma:
      chroma(De);
      break;
    case FadeIn:
      fadeIn(R, G, B, De);
      break;
    case FadeOut:
      fadeOut(De);
      break;
    case SuddenFlash:
      sudden(R, G, B, De);
      break;
    case RandomBreath:
      randomBreath(De);
      break;
    case Breath:
      rgbFadeInAndOut(R, G, B, De);
      break;
    case FallingStars:
      fallingStars(R, G, B, De);
      break;
    case ChristmasChase:
      xmasChase(De);
      break;
    case Pong:
      pong(R, G, B, De);
      break;
    case Waterfall:
      waterfall(R, G, B, De);
      break;
    case Lightning:
      lightning(R, G, B, De);
      break;
    case Waves:
      waves(R, G, B, De);
      break;
    case Levels:
      levels(R, G, B, De);
      break;
    case Rain:
      rain(R, G, B, De);
      break;
    case Pause:
      //empty bc that how it actually pauses
      break;
    case SoundSync:
      soundsync(R, G, B);
      break;
    default:
      break;
  }
}
