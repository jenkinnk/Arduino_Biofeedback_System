void  mode0(){
  
  //Default mode -- set baseline and current heart rate to 0
  sendDataToProcessing(2, 0);   //send sample heart rate
  sendDataToProcessing(2, 0);
  sendDataToProcessing(3, 0);  //send sample baseline

}
