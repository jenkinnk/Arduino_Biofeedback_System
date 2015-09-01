void mode3(){

   if (QS == true){                    // Quantified Self flag is true when arduino finds a heartbeat
   
     if (digitalRead(baselinePin) == HIGH){   //If button is pressed
        digitalWrite(baselineSent, HIGH);    //Illuminate LED to show that a baseline heart rate was sent 
        sendDataToProcessing(3, BPM);        //Send a '3' to signify a baseline heart rate is coming, then send the BPM     
     }
     else{
       sendDataToProcessing(2,BPM);          //If the button was not pressed, send a '2' to signify a current heart rate value is coming, then send the BPM
     }  
  
     QS = false; 
   }
}
