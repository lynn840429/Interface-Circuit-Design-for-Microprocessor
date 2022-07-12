byte nTo7[10]={B11111100,B01100000,B11011010,B11110010,B01100110,B10110110,B00111110,B11100100,B11111110,B11110110};
int num[4]={0,0,0,0};
int flag[4]={0,0,0,0};
int s[4]={1,0,0,0};
int hold1;
int b = 0;

void setPort( byte a){
  for (int i=0;i<8;i++){
    if ( ((a>>i)&1) == 1 ) 
      digitalWrite((i+2),LOW);
    else
      digitalWrite((i+2),HIGH);
  }
}

void setup() {
  for(int i=2;i<=13;i++){
    pinMode(i, OUTPUT);
  }
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
}

void loop() {
  
  if(analogRead(A0) >= 512)
    flag[0] = 1;
  else
    if(flag[0] == 1){
      num[0]++;
      flag[0] = 0;
    }
  if(analogRead(A1) >= 512)
    flag[1] = 1;
  else
    if(flag[1] == 1){
      num[1]++;
      flag[1] = 0;
    }
  if(analogRead(A2) >= 512)
    flag[2] = 1;
  else
    if(flag[2] == 1){
      num[2]++;
      flag[2] = 0;
    }
  if(analogRead(A3) >= 512)
    flag[3] = 1;
  else
    if(flag[3] == 1){
      num[3]++;
      flag[3] = 0;
    }
  
  /////進位
  if((num[0]/10) == 1){
    num[0] = (num[0]%10);
    num[1] = num[1] + 1;
  }
  if((num[1]/10) == 1){
    num[1] = (num[1]%10);
    num[2] = num[2] + 1;
  }
  if((num[2]/10) == 1){
    num[2] = (num[2]%10);
    num[3] = num[3] + 1;
  }
  if((num[3]/10) == 1){
    num[3] = (num[3]%10);
  }
  
  
  setPort(nTo7[num[b]]);
  
  digitalWrite(10,s[0]);
  digitalWrite(11,s[1]);
  digitalWrite(12,s[2]);
  digitalWrite(13,s[3]);
  delay(20);
  
  hold1 = s[3];
  s[3] = s[2];
  s[2] = s[1];
  s[1] = s[0];
  s[0] = hold1;
  b++;
  
  if(b == 4)
    b = 0;
   
}
