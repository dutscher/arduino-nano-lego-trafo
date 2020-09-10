// motor
// https://funduino.de/nr-34-motoren-mit-h-bruecke-l298n-ansteuern
// reed sensoren:
// https://draeger-it.blog/arduino-lektion-90-reed-kontakt-sensor-modul/?cn-reloaded=1
// bounce
// https://draeger-it.blog/arduino-lektion-87-taster-entprellen/

#include <Bounce2.h>

#define REED_BAHNHOF_GELB 7
Bounce bounceBahnhofGelb = Bounce(REED_BAHNHOF_GELB, 25);
#define REED_BAHNHOF_ROT 8
Bounce bounceBahnhofRot = Bounce(REED_BAHNHOF_ROT, 25);
#define MOTOR_SPEED 3
#define MOTOR_LINKS 5
#define MOTOR_RECHTS 6
// 255 = 15,8V
// 80 = 
// 50 = 12V -> 3v
int maxSpeed = 50;

void setup() {
  Serial.begin(9600);
  
  pinMode(REED_BAHNHOF_GELB, INPUT);
  pinMode(REED_BAHNHOF_ROT, INPUT);
  pinMode(MOTOR_SPEED, OUTPUT);
  pinMode(MOTOR_LINKS, OUTPUT);
  pinMode(MOTOR_RECHTS, OUTPUT);
  
  Serial.print("SETUP DONE");
  Serial.println();

  start();
}

void loop() {
//  start();
//  delay(10000);
//  stop();
//  delay(10000);
  
  bounceBahnhofGelb.update();
  bounceBahnhofRot.update();
  
  // put your main code here, to run repeatedly:
  if(bounceBahnhofGelb.fell()){
    Serial.println("BAHNHOF GELB EINGEFAHREN");
    stop();
    rechtsrum();
  }
  // digitalRead(REED_BAHNHOF_ROT) == LOW
  if(bounceBahnhofRot.fell()){
    Serial.println("BAHNHOF ROT EINGEFAHREN");
    stop();
    linksrum();
  }
}

void start() {
  // rechts: MOTOR_LINKS: HIGH / MOTOR_RECHTS: LOW
 digitalWrite(MOTOR_LINKS, HIGH);
  digitalWrite(MOTOR_RECHTS, LOW);
  analogWrite(MOTOR_SPEED, maxSpeed);
  Serial.println("starte mit " + String(maxSpeed));
}

void rechtsrum() {
  digitalWrite(MOTOR_LINKS, HIGH);
  digitalWrite(MOTOR_RECHTS, LOW);
  analogWrite(MOTOR_SPEED, maxSpeed);
}

void linksrum() {
  digitalWrite(MOTOR_LINKS, LOW);
  digitalWrite(MOTOR_RECHTS, HIGH);
  analogWrite(MOTOR_SPEED, maxSpeed);
}

void stop() {
  digitalWrite(MOTOR_LINKS, LOW);
  digitalWrite(MOTOR_RECHTS, LOW);
  analogWrite(MOTOR_SPEED, 0);
  Serial.println("starte mit " + String(0));
}
