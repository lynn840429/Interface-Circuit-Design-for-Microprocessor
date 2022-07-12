int p1=10;	//push 1
int p2=11;	//push 2
int led;

byte hold=B01100110;
byte a=B01100110;

void setup() {
  pinMode(p1, INPUT);
  pinMode(p2, INPUT);
  
  for (led=1; led<9; led++)
  	pinMode(led, OUTPUT);
}
///////////////////////////////////
void setPort(byte a)
{
	for (int i=0;i<=7;i++)
	{
		if ( ((a>>i)&1) == 1 )
			digitalWrite(i+1,HIGH);
		else
			digitalWrite(i+1,LOW);
	}
}

void setPort2(byte a)
{
	for (int i=0;i<=7;i++)
	{
		if ( ((a<<i)&1) == 1 )
			digitalWrite(i+1,HIGH);
		else
			digitalWrite(i+1,LOW);
	}
}
///////////////////////////////////
void loop() {
  
  //int y;
  //setPort(a);
  //delay(250);
  //y = a&1;
  //a = a>>1;
  //a = (y<<7)|a;
 
  
   
///////////////////////////////////
  int a=digitalRead(p1);
  if (a)
  {
  	delay(30);
  	if(a==digitalRead(p1))
  	{
   	 	int y;
        setPort(a);
        delay(250);
        y = a&1;
        a = a>>1;
        a = (y<<7)|a;
  	}
  }
  
  
  int b=digitalRead(p2);
  if (b)
  {
    
    setPort(B11110000);
    delay(500);
    setPort(B00001111);
    delay(500);
    
  	delay(30);
  	if(b==digitalRead(p2))
  	{
      	
   	 	setPort(B11111111);
      	delay(500);
      	setPort(B00000000);
      	delay(500);
  	}
  }
}