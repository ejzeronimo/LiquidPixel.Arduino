void chooser(byte moded, byte R, byte G, byte B, byte De)
{
  switch (moded)
  {
    case Off:
      off();
      break;
    case Solid:
      solid(R, G, B);
      break;
    case RandomCloudy:
      randomcloudyblobs(R, G, B, De);
      break;
    case Flash:
      flash(R, G, B, De);
      break;
    case Sweep:
      sweep(R, G, B, De);
      break;
    case Twinkle:
      randomtwinkle(R, G, B, De);
      break;
    case RandomTwinkle:
      randomtwinklerainbow(De);
      break;
    case TheaterChase:
      theaterChase(R, G, B, De);
      break;
    case RandomFlash:
      randomflash(De);
      break;
    case Chroma:
      chroma(De);
      break;
    case FadeIn:
      fadein(R, G, B, De);
      break;
    case FadeOut:
      fadeout(R, G, B, De);
      break;
    case SuddenFlash:
      sudden(R, G, B, De);
      break;
    case RandomBreath:
      randomfadeinandout(De);
      break;
    case Breath:
      rgbFadeInAndOut(R, G, B, De);
      break;
    case FallingStars:
      fallingstars(R, G, B, De);
    case ChristamsChase:
      xmaschase(De);
      break;
    case Pong:
      pong(R, G, B, De);
      break;
    default:
      break;
  }
}
