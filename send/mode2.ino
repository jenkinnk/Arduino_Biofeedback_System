void mode2(){
  
   //Accelerometer modification demonstration mode
   digitalWrite(9,LOW);
   sendDataToProcessing(2, 0);   //Set sample heart rate of 0
   sendDataToProcessing(2, 0);   //Make sure the sample heart rate is set
   sendDataToProcessing(3, 0);   //Set sample baseline heart rate of 0
   
   for(int count = 0; count < 120; count++){
     //Increment heart rate by (count) by 1 from 0 to 120 and write the PWM signal to the LED pin
      if(count >  60){
        //Serial.println(count);
        digitalWrite(accelOutputPin,HIGH);
        delay(250);
        digitalWrite(accelOutputPin,LOW);
        delay(250);
      }
      else if(count > 30){
        //Serial.println(count);
        digitalWrite(accelOutputPin,HIGH);
        delay(500);
        digitalWrite(accelOutputPin,LOW);
        delay(500);
      }
      else{
        //Serial.println(count);
        delay(750);
      }
   }
}
