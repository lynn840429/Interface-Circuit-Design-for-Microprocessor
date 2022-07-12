byte nTo7[10]={B1111110,B0110000,B1101101,B1111001,B0110011,B1011011,B0011111,B1110010,B1111111,B1111011};
byte a[4]={B0110000,B1011011,B0110000,B1111001};
int hold1,hold2,hold3;
int var1 = 9;
int var2 = 10;
int var3 = 11;
int var4 = 12;
int s1 = 0;
int s2 = 1;
int s3 = 1;
int s4 = 1;
int c = 0;
int mode = 0;

void setPort( byte a){
  for (int i=0;i<7;i++){
    if ( ((a>>i)&1) == 1 ) 
      digitalWrite((i+1),HIGH);
    else
      digitalWrite((i+1),LOW);
  }
}
// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  for(int i=1;i<13;i++){
    pinMode(i, OUTPUT);
  }
  pinMode(A0, INPUT);
  pinMode(13, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  if(digitalRead(13) == LOW){
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);   
    digitalWrite(12,LOW);
    hold1 = ( analogRead(A0) / 100 );
    
    if(hold1 > 9){
      setPort(nTo7[8]);
      delay(200);
      digitalWrite(9,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(11,HIGH);   
      digitalWrite(12,HIGH);
      delay(200);
    }
    else
      setPort(nTo7[hold1]);
      delay(200);
    
  }
  else{
    setPort(a[mode]);

    digitalWrite(var1,s1);
    digitalWrite(var2,s2);
    digitalWrite(var3,s3);
    digitalWrite(var4,s4);
    delay(20);
    hold2 = s4;
    s4 = s3;
    s3 = s2;
    s2 = s1;
    s1 = hold2;
    mode++;
    c++;
    
    if(mode == 4)
      mode = 0;
    
    if(c == 50){
      c = 0;
      hold3 = var1;
      var1 = var2;
      var2 = var3;
      var3 = var4;
      var4 = hold3;
    }     
  }  
}
