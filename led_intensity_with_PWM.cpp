void setup()
{

// set the mode of timer
  TCCR1B &= ~(1<<WGM13);
   TCCR1B |= (1<<WGM12);
   TCCR1A |= (1<<WGM10)|(1<<WGM11); // FAST PWM FOR 10 BITS

// SET PWM MODE
  TCCR1A |= (1<<COM1A1);
  TCCR1A &= ~(1<<COM1A0); // PWM IN NON INVERTING MODE
// SETTING THE PRESCALAR FOR THE TIMER FOR SETTING PWM FREQ
// FOR ATMEGA 328 CLOCK=16MHZ, LETS TAKE 250 KHZ=16MHZ/64

TCCR1B |= (1<<CS10) | (1<<CS11);
TCCR1B &= ~(1<<CS12);   // SETTING PRESCALAR 64


// O/P
DDRB |= (1<<DDB1);

// SETTING DUTY CYCLE
OCR1A = 0-1023; // ANY VALUE BETWEEN 0-100%
 
}

void loop()
{
  for(int i=0; i<1024; i++){OCR1A = i;  delay(2); } // 0-100% with 2ms delat
  delay (1000); //for keeping on led on for 1sec
  for(int i=1023; i>0; i--){OCR1A = i; delay(2);} // 100-0% with 2s delay
  delay (1000); 
  
}
