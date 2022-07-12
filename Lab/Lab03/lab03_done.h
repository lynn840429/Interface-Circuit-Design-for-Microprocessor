int mode = 0;
int push = 13;	//button pin
int R = A0;	//resister pin
int R_value = 0;
byte numTo7[10] = {B11001110,B11111110,B10001110,B11111010,B11011010,B11001100,B01011110,B01110110,B00001100,B10111110};	//9~0
byte Lynn[4] = {B00001100,B10111110,B01110110,B10001110};	//1,0,2,7
int s_temp = 0;
int s1 = 0;
int s2 = 1;
int s3 = 1;
int s4 = 1;
int jump = 0;
int Sev1 = 9;
int Sev2 = 10;
int Sev3 = 11;
int Sev4 = 12;
int Sev_temp = 0;
int c = 0;

void setup() 
{
  for (int DIN=2; DIN<=13; DIN++)
    pinMode(DIN, OUTPUT);
  pinMode(push, INPUT);
  pinMode(R,INPUT);
}
//////////////////////////////////////
void setPort(byte L)
{
	for (int i=0;i<=7;i++)
	{
		if ( ((L>>i)&1) == 1 )
			digitalWrite(i+1,HIGH);
		else
			digitalWrite(i+1,LOW);
	}
}
//////////////////////////////////////
void loop() {
  mode = digitalRead(push);		//mode; push=1, not push=0
  delay(10);
  
  if (mode ==0 )	//not push
  {
      R_value = ( analogRead(R)/100 );	//read resister value
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
      digitalWrite(11,LOW);
      digitalWrite(12,LOW);

      if(R_value > 9)		//Flashing
      {
        setPort(B11111111);
        delay(200);
        setPort(B00000000);
        delay(200);
      }
      else				//0~9
      {
        setPort( numTo7[9-R_value] );
        delay(100);
      }
  }
  else				//push
  {
    setPort( Lynn[jump] );
    digitalWrite(Sev1,s1);
    digitalWrite(Sev2,s2);
    digitalWrite(Sev3,s3);
    digitalWrite(Sev4,s4);
    delay(10);
    s_temp = s4;
    s4 = s3;
    s3 = s2;
    s2 = s1;
    s1 = s_temp;
    jump++;
    c++;
    
    if (jump == 4)
      jump = 0;
    
    if (c == 20)
    {
      c = 0;
      Sev_temp = Sev1;
      Sev1 = Sev2;
      Sev2 = Sev3;
      Sev3 = Sev4;
      Sev4 = Sev_temp;
    }
  }
}