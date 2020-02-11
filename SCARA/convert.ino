void pneumatic(){
  if(vpp1>0){
    digitalWrite(p1, HIGH);
    digitalWrite(p2, LOW);
  }
  else {
    digitalWrite(p1, LOW);
    digitalWrite(p2, HIGH);
  }
  if(vpp2>0){
    digitalWrite(p3, HIGH);
  }
  else  digitalWrite(p3, LOW);

}

void mservo(){
   myservoS.setAngleConstrain(minAngle, maxAngle);
  myservoS.setPotConstrain(5, 700);
  myservoS.setTolerance(2);
  myservoS.setBase(255);

  myservoE.setAngleConstrain(minAngle, maxAngle);
  myservoE.setPotConstrain(150, 850);
  myservoE.setTolerance(0);
  myservoE.setBase(255);

  myservoW.setAngleConstrain(minAngleW, maxAngleW);
  myservoW.setPotConstrain(600, 0);
  myservoW.setTolerance(0);
  myservoW.setBase(255);

  previousMillis = millis();

 
}
