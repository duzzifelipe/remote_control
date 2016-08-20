#define  PIN_D2_INT  0
#define R06A_VT 2
#define R06A_D0 3
#define R06A_D1 4
#define R06A_D2 5
#define R06A_D3 6

bool r06a_0, r06a_1, r06a_2, r06a_3 = false;
int dirty = 0;

void pinD2ISR(){
    digitalWrite(13, !digitalRead(13));
    
    if(digitalRead(R06A_D0) == HIGH) {
      r06a_0 = !r06a_0;
    }

    if(digitalRead(R06A_D1) == HIGH) {
      r06a_1 = !r06a_1;
    }

    if(digitalRead(R06A_D2) == HIGH) {
      r06a_2 = !r06a_2;
    }

    if(digitalRead(R06A_D3) == HIGH) {
      r06a_3 = !r06a_3;
    }
    
    dirty = 1;
}

void setup(){
  attachInterrupt(PIN_D2_INT, pinD2ISR, RISING);
  pinMode(R06A_D0, INPUT);
  pinMode(R06A_D1, INPUT);
  pinMode(R06A_D2, INPUT);
  pinMode(R06A_D3, INPUT);
  Serial.begin(9600);
}

void loop(){
  if(dirty){
    dirty = 0;
    
    Serial.print("A: ");
    Serial.println(r06a_2 ? "HIGH": "LOW ");
    
    Serial.print("B: ");
    Serial.println(r06a_0 ? "HIGH": "LOW ");
    
    Serial.print("C: ");
    Serial.println(r06a_3 ? "HIGH": "LOW ");
    
    Serial.print("D: ");
    Serial.println(r06a_1 ? "HIGH": "LOW ");
    
    Serial.println("");
  }
}
