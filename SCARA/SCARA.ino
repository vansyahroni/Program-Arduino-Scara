#include <MServo.h>
#include <stdio.h>
#include <math.h>

char START_BYTE = '*'; //three characters used for Serial communication
char DELIMITER = ',';
char END_BYTE = '#';


float vps, vpe, vpw, vpp1, vpp2;

int SpotPin = A10;  // Pin that connect to Potentiometer
int SdirAPin = 26;  // Pin A to control the motor direction
int SdirBPin = 24;  // Pin B to control the motor direction
int SpwmPin = 2;   // Pin to control the motor speed

int EpotPin = A9;  // Pin that connect to Potentiometer
int EdirAPin = 32;  // Pin A to control the motor direction
int EdirBPin = 34;  // Pin B to control the motor direction
int EpwmPin = 3;   // Pin to control the motor speed

int WpotPin = A8;  // Pin that connect to Potentiometer
int WdirAPin = 40;  // Pin A to control the motor direction
int WdirBPin = 42;  // Pin B to control the motor direction
int WpwmPin = 4;   // Pin to control the motor speed

int minAngle = 0;
int maxAngle = 180;

int minAngleW = 0;
int maxAngleW = 360;

int val = 0;
int diff = 1;

int p1 = 10;
int p2 = 11;
int p3 = 12;
unsigned long previousMillis = 0;


#define  fs A10
#define  fe A9
#define  fw A8

#define  rs A15
#define  re A14
#define  rw A13
#define  rsa A12
#define  rsb A11

//Moving Avarage

//feedback
int vfs = 0;
int vfe = 0;
int vfw = 0;

//remote
int vrs = 0;
int vre = 0;
int vrw = 0;
int vrsa = 0;
int vrsb = 0;

//feedback
const int numReadings_fs = 10;
const int numReadings_fe = 10;
const int numReadings_fw = 10;

//remote
const int numReadings_rs = 10;
const int numReadings_re = 10;
const int numReadings_rw = 10;
const int numReadings_rsa = 10;
const int numReadings_rsb = 10;

//feedback
int readings_fs[numReadings_fs];      // the readings from the analog input
int readings_fe[numReadings_fe];      // the readings from the analog input
int readings_fw[numReadings_fw];      // the readings from the analog input

//remote
int readings_rs[numReadings_rs];
int readings_rw[numReadings_re];
int readings_re[numReadings_rw];
int readings_rsa[numReadings_rsa];
int readings_rsb[numReadings_rsb];

//feedback
int readIndex_fs = 0;              // the index of the current reading
int readIndex_fe = 0;              // the index of the current reading
int readIndex_fw = 0;              // the index of the current reading


//remote
int readIndex_rs = 0;              // the index of the current reading
int readIndex_re = 0;              // the index of the current reading
int readIndex_rw = 0;              // the index of the current reading
int readIndex_rsa = 0;              // the index of the current reading
int readIndex_rsb = 0;              // the index of the current reading


//feedback
int total_fs = 0;                  // the running total
int total_fe = 0;                  // the running total
int total_fw = 0;                  // the running total

//remote
int total_rs = 0;                  // the running total
int total_re = 0;                  // the running total
int total_rw = 0;                  // the running total
int total_rsa = 0;                  // the running total
int total_rsb = 0;                  // the running total

//feedback
int afs;                // the average
int afe;                // the average
int afw;                // the average

//remote
int ars = 0;                // the average
int are = 0;                // the average
int arw = 0;                // the average
int arsa = 0;                // the average
int arsb = 0;                // the average

float KP, setkp;
float fKP=2;
MServo myservoS(SpotPin, SdirAPin, SdirBPin, SpwmPin);
MServo myservoE(EpotPin, EdirAPin, EdirBPin, EpwmPin);
MServo myservoW(WpotPin, WdirAPin, WdirBPin, WpwmPin);

void setup() {

  Serial.begin(115200);
  pinMode(p1, OUTPUT);
  pinMode(p2, OUTPUT);
  pinMode(p3, OUTPUT);
  mservo();
  sma();


}

void loop() {

  Read_command();
  mv();

   KP= setkp/100.f;
  
  
  myservoS.write(vps);

  myservoW.write(vpw);
  
   myservoE.write(vpe);

  
  myservoS.setKP(KP);
  myservoE.setKP(KP);
  myservoW.setKP(KP);
  myservoE.update();
  myservoS.update();
  myservoW.update();
  delay(50);
  pneumatic();



  Serial.write(START_BYTE); Serial.print(DELIMITER);
  Serial.print(myservoS.getAngle()); Serial.print(DELIMITER);
  Serial.print(myservoE.getAngle()); Serial.print(DELIMITER);
  Serial.print(myservoW.getAngle()); Serial.print(DELIMITER);


  Serial.write(END_BYTE); Serial.println(); //send a carriage return

  //debug();

}
