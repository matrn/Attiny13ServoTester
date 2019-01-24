#define POT A1   //potentiometer for changing position of servo
#define LED_MIN 3   //LED for minimal position
#define LED_MAX 4   //LED for maximal position

#define SERVO 0   //pin for servo connection

#define BTN 1   //pin for mode button

byte last_state = 0;
byte pos = 0;


void setup(){  
  //Serial.begin(9600);
  //-----setup up all pins-----
  pinMode(POT, INPUT);
  pinMode(LED_MIN, OUTPUT);
  pinMode(LED_MAX, OUTPUT);
  pinMode(SERVO, OUTPUT);
  pinMode(BTN, INPUT_PULLUP);
  //-----setup up all pins-----
  
  #ifdef __AVR_ATtiny13__
  analogReference(0);//this line is essential for the Attiny13
  #endif
  
  digitalWrite(LED_MIN, LOW);
  digitalWrite(LED_MAX, LOW);
}


void loop(){
  if(pos == 0){
    byte val = map(analogRead(POT), 0, 1023, 0, 180);
    //Serial.println(val);
    pulseOut(SERVO, val);
  
    leds(val);

    if(check_change_mode() == 1) pos = 1;
  }
  if(pos == 1){
    for(byte a = 0; a < 180; a ++){
      pulseOut(SERVO, a);
      leds(a);
      
      if(check_change_mode() == 1){
        pos = 0;
        break;    
      }
      delay(5);
    }
    delay(10);
  }
  if(pos == 1){
    for(byte a = 180; a > 0; a --){
      pulseOut(SERVO, a);
      leds(a);

      if(check_change_mode() == 1){
        pos = 0;
        break;    
      }
      delay(5);
    }
    delay(10);
  }
  
  delay(20);
}



void pulseOut(byte pin, byte p){
  digitalWrite(pin, HIGH);
  delayMicroseconds(map(p, 0, 180, 544, 2400));  
  digitalWrite(pin, LOW);
}

/*
void delay_us(int tm){
  //while(tm --){
    delayMicroseconds(tm);
  //}
}
*/

byte check_change_mode(){
  byte rtn = 0;
  byte state = !digitalRead(BTN);
  if(state == 1 && last_state == 0){
    rtn = 1;
    blink();
  }
  
  last_state = state;

  return rtn;
}

void leds(byte val){
  if(val == 0){
    digitalWrite(LED_MIN, HIGH);
    digitalWrite(LED_MAX, LOW);
  }
  else if(val == 180){
    digitalWrite(LED_MIN, LOW);
    digitalWrite(LED_MAX, HIGH);
  }
  else{
    digitalWrite(LED_MIN, LOW);
    digitalWrite(LED_MAX, LOW);
  }
}

void blink(){
  digitalWrite(LED_MIN, HIGH);
  digitalWrite(LED_MAX, HIGH);
  delay(100);
  digitalWrite(LED_MIN, LOW);
  digitalWrite(LED_MAX, LOW);
}

