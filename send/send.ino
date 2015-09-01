//  VARIABLES
int pulsePin = 0;                 // Pulse Sensor purple wire connected to analog pin 0
int baselinePin = 8;               // pin used to indicate when to send the baseline heart rate
bool base = false;
int mode = 0;                     //Set by switch input and used to determine which  mode function to run                 
int currentBPM = 0;

// these variables are volatile because they are used during the interrupt service routine!
volatile int BPM;                   // used to hold the pulse rate
volatile int baseline;
volatile int Signal;                // holds the incoming raw data
volatile int IBI = 600;             // holds the time between beats, must be seeded! 
volatile boolean Pulse = false;     // true when pulse wave is high, false when it's low
volatile boolean QS = false;        // becomes true when Arduoino finds a beat.
volatile int baselineSent = 13;

//LED pin to demonstrate accelerometer functionality in mode2
volatile int accelOutputPin = 9;

//Switch input pins
int mode1Switch = 2;
int mode2Switch = 3;
int mode3Switch = 4;
int mode4Switch = 5;

void setup(){
  
  //Accelerometer demo LED
  pinMode(accelOutputPin,OUTPUT);
  
  //Switch input pins
  pinMode(mode1Switch,INPUT);
  pinMode(mode2Switch,INPUT);
  pinMode(mode3Switch,INPUT);
  pinMode(mode4Switch,INPUT);
  
  //Read pins connected to switch and set mode based on switch input
  if(digitalRead(mode1Switch)){
    mode = 1;    //LED array modification demo mode
  }
  else if(digitalRead(mode2Switch)){
    mode = 2;    //Accelerometer modification demo mode
  }
  else if(digitalRead(mode3Switch)){ 
    mode = 3;    //Gameplay LED array modification mode
  }
  else if(digitalRead(mode4Switch)){
    mode = 4;    //Gameplay accelerometer modification mode
  }
  else{
    mode = 4;    //Default mode, no functionality
  }
  
  pinMode(baselinePin, INPUT);       //Button to send resting heart rate
  interruptSetup();                 //Sets up to read Pulse Sensor signal every 2mS 
  Serial.begin(9600);               //Set baud rate to 9600  
}



void loop(){
  //Check which mode and run the corresponding mode function
  if(mode == 1){
    mode1();
  }
  else if(mode == 2){
    mode2();
  }
  else if(mode == 3){
    mode3();
  }
  else if(mode == 4){
    mode4();
  }
  else{
    mode0();
  }
}

void sendDataToProcessing(int type, int data ){
    Serial.write(type);                //Send symbol prefix to signify what type of data is coming -- '2' = current heart rate, '3' = baseline
    delay(2000);                       //Delay for 2 seconds
    Serial.write(data);                //Send heart rate data culminating in a carriage return
  }

