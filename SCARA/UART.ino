void Read_command()
{
    static unsigned char data[255]={0}; 
     int i,msg;
          msg = Serial.available();
          
          if (msg>255) msg=0; //protection buffer
          if(msg > 0){for(i = 0; i < msg; i++){data[i] = Serial.read();}}
        
          if(data[0] == 255 && data[7] == 254) //packet data
          {
            vps = data[1];
            vpe= data[2];
            vpw= data[3];
            vpp1= data[4];
            vpp2= data[5];
            setkp=data[6];
          }
          
//          if(data[0] == 255 && data[2] == 254) //one character
//          {
//
//          }
//          
//          if(data[0] == 155 && data[9] == 154) //packet tuning parameter
//          {
//    
//          }
//
//          if(data[0] == 100 && data[12] == 99) //packet tuning offset motor
//          {
//          
//         }
          
 Serial.flush();
  }
