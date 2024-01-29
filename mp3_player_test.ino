//Libraries Used for the MP3 Module Included.
#include <DFRobotDFPlayerMini.h>
#include "Arduino.h"
#include "SoftwareSerial.h"

//Code for the mp3 module was found at https://wiki.dfrobot.com/DFPlayer_Mini_SKU_DFR0299

//Setup for MP3 module pins
SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

int value = 0; //setup for photoresistor

void setup() {
  //Setup to read state of the mp3 module and for the mp3 module to communicate
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);

  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while (true);
  }
  Serial.println(F("DFPlayer Mini online."));
  myDFPlayer.setTimeOut(500); //Set serial communictaion time out 500ms
  myDFPlayer.volume(30); //Set volume between 0~30
  //myDFPlayer.EQ(DFPLAYER_EQ_CLASSIC); //Sets Equaliser
}

void loop() {
  //prints state of mp3 module and any error messages
  if (myDFPlayer.available()) {
    printDetail(myDFPlayer.readType(), myDFPlayer.read());
  }
  value = analogRead(A0); // reading the value of photoresitor
  Serial.println(value); //debugging code
  //Actual functions for the sorting hat
  hatOn();
  delay(2000);
}

//function to 'randomly' choose which house you get put in
void houseChoose() {
  delay(500);
  int randomint = random(0, 4);
  Serial.println("Second");
  Serial.println(randomint);
  if (randomint == 0) {
    myDFPlayer.play(1);
    delay(2000);
  } else if (randomint == 1) {
    myDFPlayer.play(6);
    delay(2000);
  } else if (randomint == 2) {
    myDFPlayer.play(4);
    delay(2000);
  } else if (randomint == 3) {
    myDFPlayer.play(5);
    delay(2000);
  }
}

// code to choose a 'random' preliminary voice line when you put the hat on your head, e.g. 'i know just what to do with you', or 'ahh right then right then'
void hatOn() {
  //code to check if it is dark or not, i.e if its on your head
  if (value <= 500) {
    int randomint = random(0, 3);
    Serial.println("first");
    Serial.println(randomint);
    if (randomint == 0) {
      myDFPlayer.play(7);
      delay(7500);
    } else if (randomint == 1) {
      myDFPlayer.play(2);
      delay(6000);
    } else if (randomint == 2) {
      myDFPlayer.play(3);
      delay(3000);
    }
    houseChoose();
  }
}

//code to for showing the error message that has happened in the mp3 module
void printDetail(uint8_t type, int value) {
  switch (type) {
    case TimeOut:
      Serial.println(F("Time Out!"));
      break;
    case WrongStack:
      Serial.println(F("Stack Wrong!"));
      break;
    case DFPlayerCardInserted:
      Serial.println(F("Card Inserted!"));
      break;
    case DFPlayerCardRemoved:
      Serial.println(F("Card Removed!"));
      break;
    case DFPlayerCardOnline:
      Serial.println(F("Card Online!"));
      break;
    case DFPlayerPlayFinished:
      Serial.print(F("Number:"));
      Serial.print(value);
      Serial.println(F(" Play Finished!"));
      break;
    case DFPlayerError:
      Serial.print(F("DFPlayerError:"));
      switch (value) {
        case Busy:
          Serial.println(F("Card not found"));
          break;
        case Sleeping:
          Serial.println(F("Sleeping"));
          break;
        case SerialWrongStack:
          Serial.println(F("Get Wrong Stack"));
          break;
        case CheckSumNotMatch:
          Serial.println(F("Check Sum Not Match"));
          break;
        case FileIndexOut:
          Serial.println(F("File Index Out of Bound"));
          break;
        case FileMismatch:
          Serial.println(F("Cannot Find File"));
          break;
        case Advertise:
          Serial.println(F("In Advertise"));
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
}
