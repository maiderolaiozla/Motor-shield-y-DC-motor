/* L298P Motor Shield-a
  Motor bat denbora jakin batez Aurrerantz eta gero Atzerantz mugitzen
  duen programa.
  Atzerantz doanean soinua aterako du.  
  2019 ko Azaroan by Axpi
  This example code is in the public domain.
*/

int E1 = 10; //Motorraren Abiadura PWM.
int M1 = 12; // Motorraren Norantza.
int piezoPin=4;
int x=0;
int geldirik=0;
int pwm1;          //Variable del PWM 1
int pwm2;          //Variable del PWM 2
int ledgorri=9;
int ledberde=11;

void setup()
{
pinMode(M1, OUTPUT);
pinMode (ledgorri, OUTPUT);
pinMode (ledberde, OUTPUT);
Serial.begin(9600);
}

void loop(){
  x=analogRead(0);
  Serial.print("X Ardatza=     ");
  Serial.println(x);
  
  if(x<500){    // Motorra AURRERANTZ
     digitalWrite(M1,HIGH);
     pwm1 = map(x, 0, 500, 255, 0);
     analogWrite(E1, pwm1);
     delay(200);
     Serial.print("Abiadura: ");
     Serial.println(pwm1);
     Serial.println("FORWARD");
     int argi = map (x, 0, 500, 255, 0);
     analogWrite (ledberde,argi);
     analogWrite (ledgorri, 0);
    }

 
   if(x>550){    // Motorra AURRERANTZ    // Motorra ATZERANTZ
   
    digitalWrite(M1,LOW);
    pwm2 = map(x, 550, 1023, 0, 255);
    analogWrite(E1, pwm2);
    delay(200);
    Serial.print("Abiadura: ");
    Serial.println(pwm2);
    Serial.println("BACKWARD");
    tone(piezoPin, 1000, 50);       // Tonua egin 
    delay(50);
    tone(piezoPin, 2000, 50);
    int argi2 = map (x, 550, 1023, 0, 255);
    analogWrite (ledgorri, argi2);
    analogWrite (ledberde, 0);
 }
 
      if(x<515 && x>485){    // Motorra AURRERANTZ
     digitalWrite(M1,HIGH);
     analogWrite(E1, geldirik);
     delay(200);
     Serial.print("Abiadura: ");
     Serial.println(geldirik);
     Serial.println("geldirik");
     analogWrite (ledberde,0);
     analogWrite (ledgorri, 0);
    }

}
