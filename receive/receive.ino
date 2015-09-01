volatile int LED1 = 4;
volatile int LED2 = 5;
volatile int LED3 = 7;
volatile int LED4 = 9;
volatile int LED5 = 10;
volatile int LED6 = 11;
volatile int LED7 = 13;

//string baseSet;

volatile int arrayBreakTime = 100;

volatile int INITIAL_BASELINE = 50;
volatile int BASELINE = 0;
volatile int DATA = 0;
volatile int TYPE = 0;
volatile int RATE = 0;

void setup(){
  //Serial.begin(115200);
  //Serial.flush();
  
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  
  /*
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
  digitalWrite(LED5, HIGH);
  digitalWrite(LED6, HIGH);
  digitalWrite(LED7, HIGH);
  
  delay(5000);
  
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  digitalWrite(LED6, LOW);
  digitalWrite(LED7, LOW);
  
  */
  
  //interruptSetup();
  
  BASELINE = INITIAL_BASELINE;
  
  Serial.begin(9600);
  
  DATA = 0;

}

void loop(){
  
  //DATA = 0;

  if(Serial.available() > 0){
    DATA = Serial.read();// - '0'; // converts to integer
    Serial.println(DATA);
  }
  
  if(DATA == 1 || DATA == 2 || DATA == 3){
    TYPE = DATA;
      //Serial.println(DATA);
  }
  else if(DATA > 10 && TYPE != 1){
    RATE = DATA;
      //Serial.println(DATA);
  }
  
  if(TYPE == 2){
      if(RATE > BASELINE + 19){
        //twentyOverPar();
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, LOW);
        digitalWrite(LED4, LOW);
        digitalWrite(LED5, LOW);
        digitalWrite(LED6, LOW);
        digitalWrite(LED7, LOW);
        
        digitalWrite(LED1, HIGH);
        delay(arrayBreakTime);
        digitalWrite(LED1, LOW);
        digitalWrite(LED3, HIGH);
        delay(arrayBreakTime);
        digitalWrite(LED3, LOW);
        digitalWrite(LED5, HIGH);
        delay(arrayBreakTime);
        digitalWrite(LED5, LOW);
        digitalWrite(LED3, HIGH);
        delay(arrayBreakTime);
        digitalWrite(LED3, LOW);
        digitalWrite(LED7, HIGH);
        delay(arrayBreakTime);
        digitalWrite(LED7, LOW);
        digitalWrite(LED3, HIGH);
        delay(arrayBreakTime);
        digitalWrite(LED3, LOW);
      }
      else{
        if (RATE > BASELINE + 9){
          //tenOverPar();
          digitalWrite(LED1, LOW);
          digitalWrite(LED2, LOW);
          digitalWrite(LED3, LOW);
          digitalWrite(LED4, LOW);
          digitalWrite(LED5, LOW);
          digitalWrite(LED6, LOW);
          digitalWrite(LED7, LOW);
          
          digitalWrite(LED2, HIGH);
          delay(arrayBreakTime);
          digitalWrite(LED2, LOW);
          digitalWrite(LED3, HIGH);
          delay(arrayBreakTime);
          digitalWrite(LED3, LOW);
          digitalWrite(LED4, HIGH);
          delay(arrayBreakTime);
          digitalWrite(LED4, LOW);
          digitalWrite(LED3, HIGH);
          delay(arrayBreakTime);
          digitalWrite(LED3, LOW);
          digitalWrite(LED6, HIGH);
          delay(arrayBreakTime);
          digitalWrite(LED6, LOW);
          digitalWrite(LED3, HIGH);
          delay(arrayBreakTime);
          digitalWrite(LED3, LOW);
      }
        else{ 
          //PAR
          digitalWrite(LED1, LOW);
          digitalWrite(LED2, LOW);
          digitalWrite(LED3, HIGH);
          digitalWrite(LED4, LOW);
          digitalWrite(LED5, LOW);
          digitalWrite(LED6, LOW);
          digitalWrite(LED7, LOW);
          delay(arrayBreakTime);
        }
      }
  }
  
  else {
    if(TYPE == 3){
    Serial.print("Baseline is now : ");
    Serial.println(RATE);
    BASELINE = RATE;
    }
  }


}
