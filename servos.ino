#include <Servo.h>

//servo setup
Servo Mouth;//
Servo lEye;
Servo rEye;
int value = 0;
void setup() {
  Serial.begin(115200);

  Mouth.attach(3);
  lEye.attach(5);
  rEye.attach(6);

  Mouth.write(0);
  lEye.write(0);
  rEye.write(0);
}

void loop() {
  value = analogRead(A0); // reading the value of photoresitor
  Serial.println(value); //debugging code
  //Actual functions for the sorting hat
  hatOn();
  delay(2000);
}

//code to 'randomly' choose which servo function to play
void hatOn() {
  //code to see if its on your head from light values
  if (value <= 500) {
    int randomint = random(0, 3);
    Serial.println("first");
    Serial.println(randomint);
    if (randomint == 0) {
      a0005();
      delay(7500);
    } else if (randomint == 1) {
      a0007();
      delay(6000);
    } else if (randomint == 2) {
      a0006();
      delay(3000);
    }
    houseChoose();
  }
}

//code to 'randomly' choose which servo function to play
void houseChoose() {
  delay(500);
  int randomint = random(0, 4);
  Serial.println("Second");
  Serial.println(randomint);
  if (randomint == 0) {
    a0001();
    delay(2000);
  } else if (randomint == 1) {
    a0002();
    delay(2000);
  } else if (randomint == 2) {
    a0003();
    delay(2000);
  } else if (randomint == 3) {
    a0004();
    delay(2000);
  }
}

//all the servo sequences for each voice line
void a0001() {

  Mouth.write(0);
  lEye.write(0);
  rEye.write(0);
  delay(100);

  Mouth.write(180);
  lEye.write(180);
  rEye.write(180);
  delay(400);

  Mouth.write(0);
  lEye.write(0);
  rEye.write(0);
  delay(100);

  Mouth.write(180);
  lEye.write(180);
  rEye.write(180);
  delay(100);

  Mouth.write(0);
  lEye.write(0);
  rEye.write(0);
  delay(100);


  Mouth.write(180);
  lEye.write(180);
  rEye.write(180);
  delay(500);

  Mouth.write(0);
  lEye.write(0);
  rEye.write(0);
  delay(500);

  delay(200);
}

void a0002() {

  Mouth.write(180);
  lEye.write(180);
  rEye.write(180);
  delay(500);

  Mouth.write(90);
  lEye.write(90);
  rEye.write(90);
  delay(200);

  Mouth.write(180);
  lEye.write(180);
  rEye.write(180);
  delay(300);

  Mouth.write(0);
  lEye.write(0);
  rEye.write(0);
  delay(1000);

}

void a0003() {


  Mouth.write(0);
  lEye.write(0);
  rEye.write(0);
  delay(200);


  Mouth.write(180);
  lEye.write(180);
  rEye.write(180);
  delay(100);


  Mouth.write(0);
  lEye.write(0);
  rEye.write(0);
  delay(100);

  Mouth.write(90);
  lEye.write(90);
  rEye.write(90);
  delay(200);

  Mouth.write(180);
  lEye.write(180);
  rEye.write(180);
  delay(100);

  Mouth.write(0);
  lEye.write(0);
  rEye.write(0);
  delay(200);

  lEye.write(100);
  rEye.write(80);
  delay(100);

  lEye.write(100);
  rEye.write(80);
  delay(100);

  lEye.write(0);
  rEye.write(0);
  delay(400);

  Mouth.write(0);
  lEye.write(0);
  rEye.write(0);
  delay(500);

}

void a0004() {

  Mouth.write(0);
  lEye.write(0);
  rEye.write(0);
  delay(300);

  Mouth.write(80);
  lEye.write(180);
  rEye.write(180);
  delay(100);

  Mouth.write(180);
  lEye.write(180);
  rEye.write(180);
  delay(100);

  Mouth.write(0);
  lEye.write(0);
  rEye.write(0);
  delay(200);

  Mouth.write(180);
  lEye.write(180);
  rEye.write(180);
  delay(600);

  Mouth.write(0);
  lEye.write(0);
  rEye.write(0);
  delay(300);

  delay(400);

}

void a0005() {
  Mouth.write(80);
  lEye.write(50);
  rEye.write(100);
  delay(400);
  //
  Mouth.write(0);
  lEye.write(100);
  rEye.write(100);
  delay(300);

  Mouth.write(120);
  lEye.write(150);
  rEye.write(150);
  delay(400);

  Mouth.write(20);
  lEye.write(100);
  rEye.write(100);
  delay(400);

  Mouth.write(0);
  lEye.write(0);
  rEye.write(0);
  delay(100);
  delay(7500);
}

void a0006() {
  Mouth.write(80);
  lEye.write(80);
  rEye.write(80);
  delay(100);

  Mouth.write(0);
  lEye.write(0);
  rEye.write(0);
  delay(100);


  Mouth.write(100);
  lEye.write(60);
  rEye.write(80);
  delay(300);

  Mouth.write(0);
  lEye.write(0);
  rEye.write(0);
  delay(100);

  Mouth.write(100);
  lEye.write(180);
  rEye.write(180);
  delay(300);

  Mouth.write(0);
  lEye.write(0);
  rEye.write(0);
  delay(100);

  Mouth.write(100);
  lEye.write(60);
  rEye.write(80);
  delay(400);

  Mouth.write(50);
  lEye.write(100);
  rEye.write(100);
  delay(200);

  Mouth.write(0);
  lEye.write(0);
  rEye.write(0);
  delay(300);

  Mouth.write(100);
  lEye.write(80);
  rEye.write(50);
  delay(200);

  Mouth.write(50);
  lEye.write(40);
  rEye.write(20);
  delay(770);


  Mouth.write(0);
  lEye.write(0);
  rEye.write(0);
  delay(130);
}

void a0007() {
  Mouth.write(0);
  lEye.write(50);
  rEye.write(50);
  delay(200);

  Mouth.write(0);
  lEye.write(50);
  rEye.write(50);
  delay(200);

  Mouth.write(100);
  lEye.write(60);
  delay(100);

  Mouth.write(150);
  lEye.write(10);
  rEye.write(100);
  delay(200);

  Mouth.write(100);
  lEye.write(10);
  rEye.write(100);
  delay(300);

  Mouth.write(130);
  lEye.write(120);
  rEye.write(80);
  delay(200);

  Mouth.write(0);
  lEye.write(0);
  rEye.write(0);
  delay(500);

  Mouth.write(180);
  delay(300);

  Mouth.write(0);
  delay(100);

  Mouth.write(150);
  lEye.write(50);
  rEye.write(60);
  delay(300);

  Mouth.write(0);
  lEye.write(20);
  rEye.write(20);
  delay(400);

  Mouth.write(80);
  lEye.write(50);
  rEye.write(40);
  delay(200);

  Mouth.write(120);
  lEye.write(60);
  rEye.write(80);
  delay(200);

  Mouth.write(40);
  lEye.write(60);
  rEye.write(80);
  delay(500);

  Mouth.write(20);
  lEye.write(120);
  rEye.write(140);
  delay(200);

  Mouth.write(0);
  lEye.write(100);
  rEye.write(100);
  delay(500);
}
