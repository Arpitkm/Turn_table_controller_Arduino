const int Dir = 6;
const int Pul = 7;
const int Mover = 2; // Interrupt Pin
const int Reverse = 3; // Interrupt Pin 2

//Variables
volatile boolean setdir = LOW;

void setup(){
  pinMode(Dir, OUTPUT);
  pinMode(Pul, OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(Mover),MoveFiveDegree,FALLING);
  attachInterrupt(digitalPinToInterrupt(Reverse), ReverseDir, FALLING);
  Serial.begin(9600);
}

void MoveFiveDegree(){
  static unsigned long last_click_time = 0;
  unsigned long interrupt_time = millis();
  if(interrupt_time - last_click_time > 200) { // To avoid Bouncing effect
   for(int i=0; i<=28; i++){
      digitalWrite(Pul,HIGH);
      delayMicroseconds(15000);
      digitalWrite(Pul,LOW);
      delayMicroseconds(15000);
      Serial.println("Moved");
   }
   last_click_time = interrupt_time;
  }
      
}

void ReverseDir(){
  static unsigned long last_click_time2 = 0;
  unsigned long interrupt_time2 = millis();
  if(interrupt_time2 - last_click_time2 > 200){
    setdir = !setdir;
  }
  last_click_time2 = interrupt_time2;
}

void loop(){
      
      digitalWrite(Dir,setdir);
}
