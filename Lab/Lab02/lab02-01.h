int p1=10;	//push 1
int p2=11;	//push 2
int led;
byte I=B01100110;

int move = 0;
int a_hold = 0;
int b_hold = 0;
int a_hold_Typ = 0;
int b_hold_Typ = 0;
/////////////////////////
void setup() 
{
  pinMode(p1, INPUT);
  pinMode(p2, INPUT);
  
  for (led=1; led<9; led++)
  	pinMode(led, OUTPUT);
}
///////////////////////////////////
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
///////////////////////////////////
void loop() {
  
  int a_button = digitalRead(p1);
  int b_button = digitalRead(p2);
  delay(30);
  //////////////////////
  if (a_button == 1)
  {
    move = 1;
  	a_hold = 1;
    b_hold = 0;
  }
  if (b_button == 1)
  {
    move = 1;
  	a_hold = 0;
    b_hold = 1;
  }
  //////////////////////
  if (a_button == 1)
   	 a_hold_Typ = ~a_hold_Typ;
  if (b_button == 1)
   	 b_hold_Typ = ~b_hold_Typ;
  //////////////////////
  if (move == 0)
  {
    int y;
    setPort(I);
    delay(500);
    y = I&1;
    I = I>>1;
    I = (y<<7)|I;
  }
  else	//move == 1
  {
    if (a_hold == 1)
    {
      if (a_hold_Typ == 0)
      {
        int y;
        setPort(I);
        delay(500);
        y = I&1;
        I = I>>1;
        I = (y<<7)|I;
      }
      else
      {
        int y;
        setPort(I);
        delay(500);
        y = I&B10000000;
        I = I<<1;
        I = (y>>7)|I;
      }
    }
    if (b_hold == 1)
    {
      if (b_hold_Typ == 0)
      {
        setPort(B11111111);
        delay(250);
        setPort(B00000000);
        delay(250);
      }
      else
      {
        setPort(B11110000);
        delay(250);
        setPort(B00001111);
        delay(250);
      }
    }
  }
}