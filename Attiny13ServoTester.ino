/* settings:
 *  Board: ATtiny13
 *  Brown-out Detection Level: "1.8V"
 *  Link Time Optimalisation: "LTO Enabled"
 *  Processor Version: "ATtiny13"
 *  Processor Speed: "9.6MHz Internal Oscillator"
 *  Programmer: "Arduino as ISP"
 */

#define POT A1   //potentiometer for changing position of servo
#define LED_MIN 4   //LED for minimal position
#define LED_MAX 3   //LED for maximal position

#define SERVO 0   //pin for servo connection

#define BTN 1   //pin for mode button

byte last_state = 0;   //last state of button
byte pos = 0;   //current position of mode


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

  //-----boot blink-----
  for(byte a = 0; a < 5; a ++){
    digitalWrite(LED_MIN, HIGH);
    digitalWrite(LED_MAX, LOW);
    delay(100);
    digitalWrite(LED_MIN, LOW);
    digitalWrite(LED_MAX, HIGH);
    delay(100);
  }

  digitalWrite(LED_MIN, LOW);
  digitalWrite(LED_MAX, LOW);
  //-----boot blink-----
}


void loop(){
  //-----potentiometer mode-----
  if(pos == 0){   
    int val = analogRead(POT);   
     
    if(val < 5) val = 5;   //ignore first 10 steps
    if(val > 1018) val = 1018;   //ignore last 13 steps
    val = 180-map(val, 5, 1018, 0, 180);
    
    pulseOut(SERVO, val);
  
    leds(val);

    if(check_change_mode() == 1) pos = 1;
  }
  //-----potentiometer mode-----

  //-----auto mode-----
  if(pos == 1){
    for(byte a = 0; a < 180; a ++){
      pulseOut(SERVO, a);
      leds(a);
      
      if(check_change_mode() == 1){
        pos = 2;
        break;    
      }
      delay(20);
    }
    delay(10);
  }
  
  if(pos == 1){
    for(byte a = 180; a > 0; a --){
      pulseOut(SERVO, a);
      leds(a);
  
      if(check_change_mode() == 1){
        pos = 2;
        break;    
      }
      delay(20);
    }
    delay(10);
  }
  //-----auto mode-----

  //-----90° mode-----
  if(pos == 2){
    pulseOut(SERVO, 90);
    
    if(check_change_mode() == 1) pos = 0;
  }
  //-----90° mode-----
  
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
  delay(200);
  digitalWrite(LED_MIN, LOW);
  digitalWrite(LED_MAX, LOW);
}
