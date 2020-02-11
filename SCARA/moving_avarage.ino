void sma(){
   for (int thisReading_fs = 0; thisReading_fs < numReadings_fs; thisReading_fs++) {
    readings_fs[thisReading_fs] = 0;
  }
  for (int thisReading_fe = 0; thisReading_fe < numReadings_fe; thisReading_fe++) {
    readings_fe[thisReading_fe] = 0;

  } for (int thisReading_fw = 0; thisReading_fw < numReadings_fw; thisReading_fw++) {
    readings_fw[thisReading_fw] = 0;
  }

  //moving avarage Remote
  for (int thisReading_rs = 0; thisReading_rs < numReadings_rs; thisReading_rs++) {
    readings_rs[thisReading_rs] = 0;
  }
  for (int thisReading_re = 0; thisReading_re < numReadings_re; thisReading_re++) {
    readings_re[thisReading_re] = 0;
  }
  for (int thisReading_rw = 0; thisReading_rw < numReadings_rw; thisReading_rw++) {
    readings_rw[thisReading_rw] = 0;
  }
  for (int thisReading_rsa = 0; thisReading_rsa < numReadings_rsa; thisReading_rsa++) {
    readings_rsa[thisReading_rsa] = 0;
  }
  for (int thisReading_rsb = 0; thisReading_rsb < numReadings_rsb; thisReading_rsb++) {
    readings_rsb[thisReading_rsb] = 0;
  }
}
void mv() {

  //Shoulder
  total_fs = total_fs - readings_fs[readIndex_fs];
  readings_fs[readIndex_fs] = analogRead(fs);
  total_fs = total_fs + readings_fs[readIndex_fs];
  readIndex_fs = readIndex_fs + 1;
  if (readIndex_fs >= numReadings_fs) {
    readIndex_fs = 0;
  }
  //Elbow
  total_fe = total_fe - readings_fe[readIndex_fe];
  readings_fe[readIndex_fe] = analogRead(fe);
  total_fe = total_fe + readings_fe[readIndex_fe];
  readIndex_fe = readIndex_fe + 1;
  if (readIndex_fe >= numReadings_fe) {
    readIndex_fe = 0;
  }

  //Wirst
  total_fw = total_fw - readings_fw[readIndex_fw];
  readings_fw[readIndex_fw] = analogRead(fw);
  total_fw = total_fw + readings_fw[readIndex_fw];
  readIndex_fw = readIndex_fw + 1;
  if (readIndex_fw >= numReadings_fw) {
    readIndex_fw = 0;
  }

  //RShoulder
  total_rs = total_rs - readings_rs[readIndex_rs];
  readings_rs[readIndex_rs] = analogRead(rs);
  total_rs = total_rs + readings_rs[readIndex_rs];
  readIndex_rs = readIndex_rs + 1;
  if (readIndex_rs >= numReadings_rs) {
    readIndex_rs = 0;
  }
  //RElbow
  total_re = total_re - readings_re[readIndex_re];
  readings_re[readIndex_re] = analogRead(re);
  total_re = total_re + readings_re[readIndex_re];
  readIndex_re = readIndex_re + 1;
  if (readIndex_re >= numReadings_re) {
    readIndex_re = 0;
  }
  //RWirst
  total_rw = total_rw - readings_rw[readIndex_rw];
  readings_rw[readIndex_rw] = analogRead(rw);
  total_rw = total_rw + readings_rw[readIndex_rw];
  readIndex_rw = readIndex_rw + 1;
  if (readIndex_rw >= numReadings_rw) {
    readIndex_rw = 0;
  }
  //RSA
  total_rsa = total_rsa - readings_rsa[readIndex_rsa];
  readings_rsa[readIndex_rsa] = analogRead(rsa);
  total_rsa = total_rsa + readings_rsa[readIndex_rsa];
  readIndex_rsa = readIndex_rsa + 1;
  if (readIndex_rsa >= numReadings_rsa) {
    readIndex_rsa = 0;
  }
  //RSB
  total_rsb = total_rsb - readings_rsb[readIndex_rsb];
  readings_rsb[readIndex_rsb] = analogRead(rsb);
  total_rsb = total_rsb + readings_rsb[readIndex_rsb];
  readIndex_rsb = readIndex_rsb + 1;
  if (readIndex_rsb >= numReadings_rsb) {
    readIndex_rsb = 0;
  }

  afs = total_fs / numReadings_fs;  //feedback shoulder
  afe = total_fe / numReadings_fe;
  afw = total_fw / numReadings_fw;


  ars = total_rs / numReadings_rs;
  are = total_re / numReadings_re;
  arw = total_rw / numReadings_rw;
  arsa = total_rsa / numReadings_rsa;
  arsb = total_rsb / numReadings_rsb;





}
