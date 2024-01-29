/***************************************************
 DFPlayer - A Mini MP3 Player For Arduino
 <https://www.dfrobot.com/index.php?route=product/product&product_id=1121>

 ***************************************************
 This example shows the all the function of library for DFPlayer.

 Created 2016-12-07
 By [Angelo qiao](Angelo.qiao@dfrobot.com)

 GNU Lesser General Public License.
 See <http://www.gnu.org/licenses/> for details.
 All above must be included in any redistribution
 ****************************************************/

/***********Notice and Trouble shooting***************
 1.Connection and Diagram can be found here
<https://www.dfrobot.com/wiki/index.php/DFPlayer_Mini_SKU:DFR0299#Connection_Diagram>
 2.This code is tested on Arduino Uno, Leonardo, Mega boards.
 ****************************************************/

//DFPlayer setup
#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

//Variable setup for sensing when hat is on head or to choose which voiceline to play
int voiceline1 = 0;
int voiceline2 = 0;
int pressure_state = 0;

// https://wiki.dfrobot.com/DFPlayer_Mini_SKU_DFR0299  <- Use this link for mp3  code controls

void setup() {
  // DFplayer setup
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
  myDFPlayer.volume(10); //Set volume between 0~30)

}

void loop() {
  //Prints detailed message from DFPlayer for different errors
  if (myDFPlayer.available()) {
    printDetail(myDFPlayer.readType(), myDFPlayer.read());
  }

//Waits for if hat is on head to play voice lines and move servos
  if (pressure_state == down) {
    hatOn();
    chooseHouse();
  }
}

//code to choose a random voiceline for when the hat is put on
void hatOn() {
  voiceline1 = random(0, 4);
  if (voiceline1 == 0) {
    myDFPlayer.play(1);
  } else if ( voiceline1 == 1) {
    myDFPlayer.play(2);
  } else if (voiceline1 == 2) {
    myDFPlayer.play(3);
  } else if (voiceline1 == 3) {
    myDFPlayer.play(4);
  }
}

//code to randomly sort students into houses
void chooseHouse() {
  voiceline2 = random(0, 100);
  if (voiceline2 =>0 && voiceline2 <= 32) {
    griffindor();
  } else if (voiceline2 => 33 && voiceline2 =< 65) {
    slytherin();
  } else if (voiceline2 => 66 && voiceline2 =< 98) {
    hufflepuff();
  } else if (voiceline2 == 99) {
    ravenclaw();
  }
}

//code for griffindor voice line synced with servo movements
void griffindor() {
  myDFPlayer.play(5);
  servo stuff
}

//code for slytherin voice line synced with servo movements
void slytherin() {
  myDFPlayer.play(6);
  servo stuff
}

//code for hufflepuff voice line synced with servo movements
void hufflepuff() {
  myDFPlayer.play(7);
  servo stuff
}

//code for ravenclaw voice line synced with servo movements
void ravenclaw() {
  myDFPlayer.play(8);
  servo stuff
}

//code for the error message stuff for the DFPlayer
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
