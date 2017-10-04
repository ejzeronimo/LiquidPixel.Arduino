//T0C5R247G42B71M0D50X0~T0C3R177G201B99M1D100X1~T0C1R77G20B9M1D25X0~

void ProcessByte(byte commandByte)
{
  switch (commandByte)
  {
    case (byte)Td:
      ReconstructSegment();
      reconstructionMode = (byte)Tm;
      break;
    case (byte)Cd:
      ReconstructSegment();
      reconstructionMode = (byte)Cm;
      break;
    case (byte)Rd:
      ReconstructSegment();
      reconstructionMode = (byte)Rm;
      break;
    case (byte)Gd:
      ReconstructSegment();
      reconstructionMode = (byte)Gm;
      break;
    case (byte)Bd:
      ReconstructSegment();
      reconstructionMode = (byte)Bm;
      break;
    case (byte)Md:
      ReconstructSegment();
      reconstructionMode = (byte)Mm;
      break;
    case (byte)Dd:
      ReconstructSegment();
      reconstructionMode = (byte)Dm;
      break;
    case (byte)Xd:
      ReconstructSegment();
      reconstructionMode = (byte)Xm;
      break;
    case (byte)EocD:
      ReconstructSegment();
      reconstructionMode = (byte)EocM;
      Processlpc();
      break;
    default:
      segmentBytesTemp[numberOfBytesInSegment] = commandByte;
      numberOfBytesInSegment++;
      break;
  }
}

void ReconstructSegment()
{
  if (reconstructionMode != (byte)Unknown && reconstructionMode != (byte)EocM)
  {
    byte segmentBytes[numberOfBytesInSegment];
    memcpy(segmentBytes, segmentBytesTemp, numberOfBytesInSegment);
    String segmentString = String((char *)segmentBytes);
    byte segmentAsInt = segmentString.toInt();

    // populate Liquid Pixel Command
    switch (reconstructionMode)
    {
      case (byte)Tm:
        lpc.Type = segmentAsInt;
        break;
      case (byte)Cm:
        lpc.Box = segmentAsInt;
        break;
      case (byte)Rm:
        lpc.R = segmentAsInt;
        break;
      case (byte)Gm:
        lpc.G = segmentAsInt;
        break;
      case (byte)Bm:
        lpc.B = segmentAsInt;
        break;
      case (byte)Mm:
        lpc.Mode = segmentAsInt;
        break;
      case (byte)Dm:
        lpc.Delay = segmentAsInt;
        break;
      case (byte)Xm:
        lpc.IsRandom = (bool)segmentAsInt;
        break;
      default:
        break;
    }

    // reset number of bytes since we are done with this segment
    numberOfBytesInSegment = 0;
  }
}

void Processlpc()
{
//  String commandType = "Command type is: ";
//  Serial.println(commandType += lpc.Type);
//  String boxNumber = "Box number is: ";
//  Serial.println(boxNumber += lpc.Box);
//  String redValue = "Red value is: ";
//  Serial.println(redValue += lpc.R);
//  String greenValue = "Green value is: ";
//  Serial.println(greenValue += lpc.G);
//  String blueValue = "Blue value is: ";
//  Serial.println(blueValue += lpc.B);
//  String mode = "Mode is: ";
//  Serial.println(mode += lpc.Mode);
//  String delayMs = "Delay is: ";
//  Serial.println(delayMs += lpc.Delay);
//  String isRandom = "Random is: ";
//  Serial.println(isRandom += lpc.IsRandom);
}
