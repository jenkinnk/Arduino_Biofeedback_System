void  mode1(){
  
  //LED array modification demonstration mode
  sendDataToProcessing(2, 50);   //send sample heart rate
  sendDataToProcessing(2, 50);
  sendDataToProcessing(3, 50);  //send sample baseline
  
  for(int count = 50; count < 80; count++){
    sendDataToProcessing(2, count);    //continuously send heart rate (count) incremented by 1
        
  }
}
