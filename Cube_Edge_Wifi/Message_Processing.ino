//OLD ==== T0C0R247G42B71M1D50X0~T0C0R177G201B99M1D100X1~T0C0R77G20B9M19D25X0~T0C0R77G20B9M21D50X0~
//NEW ==== I0T0{43,218,82}M16D37~
enum CommandDelimeters : byte {
  Id = (byte)'I',
  Td = (byte)'T',
  Pd = (byte)'{',
  Md = (byte)'M',
  Dd = (byte)'D',
  EocD = (byte)'~'
};

enum ReconstructionMode : byte {
  Unknown = 0,
  Im,
  Tm,
  Pm,
  Mm,
  Dm,
  EocM
};

void ProcessByte(byte commandByte) {
  switch (commandByte) {
    case (byte)Id:
      ReconstructSegment();
      reconstructionMode = (byte)Im;
      break;
    case (byte)Td:
      ReconstructSegment();
      reconstructionMode = (byte)Tm;
      break;
    case (byte)Pd:
      ReconstructSegment();
      reconstructionMode = (byte)Pm;
      break;
    case (byte)Md:
      ReconstructSegment();
      reconstructionMode = (byte)Mm;
      break;
    case (byte)Dd:
      ReconstructSegment();
      reconstructionMode = (byte)Dm;
      break;
    case (byte)EocD:
      ReconstructSegment();
      reconstructionMode = (byte)EocM;
      Processlpc();//update the actual command struct
      break;
    default:
      segmentBytesTemp[numberOfBytesInSegment] = commandByte;
      numberOfBytesInSegment++;
      break;
  }
}

void ReconstructSegment() {
  if (reconstructionMode != (byte)Unknown && reconstructionMode != (byte)EocM) {
    byte segmentBytes[numberOfBytesInSegment];
    memcpy(segmentBytes, segmentBytesTemp, numberOfBytesInSegment);
    String segmentString = String((char *)segmentBytes);
    int segmentAsInt = segmentString.toInt();
    int delimCount = 0;

    //populate Liquid Pixel Command
    switch (reconstructionMode) {
      case (byte)Im:
        lpcTemp.Target = segmentAsInt;
        break;
      case (byte)Tm:
        lpcTemp.Type = segmentAsInt;
        break;
      case (byte)Pm:
        for (int i = 0; i < MAX_SEGMENT_LENGTH_IN_BYTES; i++) {
          if (segmentBytes[i] == (byte)',' || segmentBytes[i] == (byte)'}') {
            lpcTemp.Payload[delimCount] = segmentString.substring(lastPayloadDelimit + 1, i).toInt();
            lastPayloadDelimit = i;
            delimCount++;
          }
        }
        lastPayloadDelimit = -1;
        break;
      case (byte)Mm:
        lpcTemp.Mode = segmentAsInt;
        break;
      case (byte)Dm:
        lpcTemp.Delay = segmentAsInt;
        break;
      default:
        break;
    }
    //reset number of bytes since we are done with this segment
    memset(segmentBytesTemp, 0, sizeof(segmentBytesTemp));
    memset(segmentBytes, 0, sizeof(segmentBytes));
    numberOfBytesInSegment = 0;
  }
}

void Processlpc() {
//    String boxNumber = "Target number is: ";
//    Serial.println(boxNumber += lpcTemp.Target);
//    String commandType = "Command type is: ";
//    Serial.println(commandType += lpcTemp.Type);
//  
//    for (int i = 0; i < 6; i++) {
//      String redValue = "Payload value is: ";
//      Serial.println(redValue += lpcTemp.Payload[i]);
//    }
//  
//    String mode = "Mode is: ";
//    Serial.println(mode += lpcTemp.Mode);
//    String delayMs = "Delay is: ";
//    Serial.println(delayMs += lpcTemp.Delay);

  //make the temp into the main command and reset ont time vars
  lpcCommand.Target = lpcTemp.Target;
  lpcCommand.Type = lpcTemp.Type;
  memcpy(lpcCommand.Payload, lpcTemp.Payload, MAX_PAYLOAD_LENGTH);
  lpcCommand.Mode = lpcTemp.Mode;
  lpcCommand.Delay = lpcTemp.Delay;

  oneTimePerCommand = true;
}
