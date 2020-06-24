int Forward_Button =A0;  // INPUT
int Backward_Button =A1;
int speed_Button = A2;
                          //OUTPUT
int LED = A3;  // Warning if Forward_Button &  Backward_Button are HIGH in The Same time         
int Forward = 11;
int Backward = 10;
int Speed_Motor = 6;

int Speed_Reading;             //VARIABLES


void setup() {
 
pinMode(Forward_Button , INPUT);
pinMode(Backward_Button , INPUT);
pinMode(speed_Button , INPUT);
pinMode(LED , OUTPUT);
pinMode(Forward , OUTPUT);
pinMode(Speed_Motor , OUTPUT);

pinMode(Backward , OUTPUT);


}

void loop() {
  
      Speed_Reading = map (analogRead(speed_Button), 0 , 1023 , 0 , 255 );

  if(digitalRead(Forward_Button)== HIGH && digitalRead(Backward_Button)== LOW ){
    analogWrite(Speed_Motor, Speed_Reading );
    digitalWrite(Forward, HIGH );
    digitalWrite(Backward, LOW);
    digitalWrite(LED, LOW);
    

  }
    else if(digitalRead(Forward_Button)== LOW && digitalRead(Backward_Button)== HIGH ){
    analogWrite(Speed_Motor, Speed_Reading );
    digitalWrite(Forward,LOW );
    digitalWrite(Backward,HIGH);
    digitalWrite(LED,LOW);
    
    }
     else if(digitalRead(Forward_Button)== HIGH && digitalRead(Backward_Button)== HIGH ) {
    analogWrite(Backward,LOW );
    digitalWrite(Forward,LOW);
    digitalWrite(LED,HIGH);
    }
     else if(digitalRead(Forward_Button)== LOW && digitalRead(Backward_Button)== LOW ) {
    digitalWrite(Speed_Motor,LOW);
    delay(1000);
    analogWrite(Backward,LOW );
    digitalWrite(Forward,LOW);
    digitalWrite(LED,LOW);
    }
    }
