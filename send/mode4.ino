void mode4(){
  baseline = 50;

  if (QS == true){                // Quantified Self flag is true when arduino finds a heartbeat
    currentBPM = BPM;
    QS = false;
    
     //Serial.print("HR : ");
     //Serial.println(currentBPM);
     
     if (digitalRead(baselinePin) == HIGH){    //If button is pressed to set the baseline heart rate
       baseline = currentBPM;                        //Set the baseline heart rate to the current heart rate value      
     }
     
    if(currentBPM >  baseline + 19){
      fiveHundred();
    }
    else if(currentBPM > baseline + 9){
      oneThousand();
    }
  }
  else{
    if(currentBPM >  baseline + 19){
      fiveHundred();
    }
    else if(currentBPM > baseline + 9){
      oneThousand();
    }
  }
  
}

void fiveHundred(){
     digitalWrite(accelOutputPin,HIGH);
     delay(250);
     digitalWrite(accelOutputPin,LOW);
     delay(250);
}

void oneThousand(){
     digitalWrite(accelOutputPin,HIGH);
     delay(500);
     digitalWrite(accelOutputPin,LOW);
     delay(500);
}

/*

   if(currentBPM >  baseline + 19){         //If current heart rate is 20 BPM or more greater than baseline heart rate value 
     digitalWrite(accelOutputPin,HIGH);                  //Send PWM signal with period length 500ms
     delay(250);
     digitalWrite(accelOutputPin,LOW);
     delay(250);
   }
   else if(currentBPM > baseline + 9){      //If current heart rate is between 10 and 19 BPM greater than baseline heart rate value
     digitalWrite(accelOutputPin,HIGH);                  //Send PWM signal with period lengh 1000ms
     delay(500);
     digitalWrite(accelOutputPin,LOW);
     delay(500);
   }   
       QS = false;
}
else{
  if(currentBPM >  baseline + 19){
     digitalWrite(accelOutputPin,HIGH);
     delay(250);
     digitalWrite(accelOutputPin,LOW);
     delay(250);
   }
   else if(currentBPM > baseline + 9){
     digitalWrite(accelOutputPin,HIGH);
     delay(500);
     digitalWrite(accelOutputPin,LOW);
     delay(500);
   }   
}

*/
