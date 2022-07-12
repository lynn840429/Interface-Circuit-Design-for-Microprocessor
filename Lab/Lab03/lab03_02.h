//int led;
int mode = 0;
int push = 13;
int R = A0;
int val = 0;
int num = 0;
int Snum = 0;
int digital = 0;
byte numTo7;//[10] = {B11111100,B01100000,B11011010,B10011110,B01100110,B10110110,B00111110,B11100100,B11111110,B11100110};

void setup() {
  for (int D=2; D<=13; D++)
    pinMode(D, OUTPUT);
  pinMode(push, INPUT);
  pinMode(R,INPUT);
  //pinMode(led, OUTPUT);
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
  mode = digitalRead(push);		//mode
  delay(10);
  
  if (mode == 0)	//mode 1
  {
    val = analogRead(R);
    num = val/100;
    
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    setPort(numTo7);
    delay(100);
    
    switch (num)
    {
     case 0:
        numTo7 = B10111110;
      	break;
     case 1:
        numTo7 = B00001100;
      	break;
     case 2: 
        numTo7 = B01110110;
      	break;
     case 3:
        numTo7 = B01011110;
      	break;
     case 4:
        numTo7 = B11001100;
      	break;
     case 5:
        numTo7 = B11011010;
      	break;
     case 6:
        numTo7 = B11111010;
      	break;
     case 7:
        numTo7 = B10001110;
     	break;
     case 8:
        numTo7 = B11111110;
      	break;
     case 9:
        numTo7 = B11001110;
      	break;
     default :
        setPort(B11111111);
      	delay(200);
        setPort(B00000000);
        delay(200);
      	break;
    }
  }
  else				//mode == 1, mode 2, 1027
  {
    switch (Snum)
    {  
	case 0:	//1
		digitalWrite(9,LOW);
		digitalWrite(10,HIGH);
		digitalWrite(11,HIGH);
		digitalWrite(12,HIGH);
			
		switch (digital)
		{
		case 0:
			setPort(B00001100);	//1
			//delay(500);
			digital++;
			break;
		case 1:
			setPort(B10111110);	//0
			//delay(500);
			digital++;
			break;
		case 2:
			setPort(B01110110);	//2
			//delay(500);
			digital++;
			break;
		case 3:
			setPort(B10001110);	//7
			//delay(500);
			digital = 0;
			break;  
		default :
			break;
		}
		Snum++;
		//break;
	case 1:	//1
		digitalWrite(9,HIGH);
		digitalWrite(10,LOW);
		digitalWrite(11,HIGH);
		digitalWrite(12,HIGH);

		switch (digital)
		{
		case 0:
			setPort(B10111110);	//0
			//delay(500);
			digital++;
			break;
		case 1:
			setPort(B01110110);	//2
			//delay(500);
			digital++;
			break;
		case 2:
			setPort(B10001110);	//7
			//delay(500);
			digital++;
			break;
		case 3:
			setPort(B00001100);	//1
			//delay(500);
			digital = 0;
			break;  
		default :
			break;
		}
		Snum++;
		//break;
	case 2:	//2
		digitalWrite(9,HIGH);
		digitalWrite(10,HIGH);
		digitalWrite(11,LOW);
		digitalWrite(12,HIGH);
		setPort(B01110110);    	
			
		switch (digital)
		{
		case 0:
			setPort(B01110110);	//2
			//delay(500);
			digital++;
			break;
		case 1:
			setPort(B10001110);	//7
			//delay(500);
			digital++;
			break;
		case 2:
			setPort(B00001100);	//1
			//delay(500);
			digital++;
			break;
		case 3:
			setPort(B10111110);	//0
			//delay(500);
			digital = 0;
			break;  
		default :
			break;
		}
		Snum++;
		//break;
	case 3:	//7
		digitalWrite(9,HIGH);
		digitalWrite(10,HIGH);
		digitalWrite(11,HIGH);
		digitalWrite(12,LOW);
		setPort(B10001110);
			
		switch (digital)
		{
		case 0:
			setPort(B10001110);	//7
			//delay(500);
			digital++;
			break;
		case 1:
			setPort(B00001100);	//1
			//delay(500);
			digital++;
			break;
		case 2:
			setPort(B10111110);	//0
			//delay(500);
			digital++;
			break;
		case 3:
			setPort(B01110110);	//2
			//delay(500);
			digital = 0;
			break;  
		default :
			break;
		}
		Snum = 0;
		break;
	default :
		digitalWrite(9,HIGH);
		digitalWrite(10,HIGH);
		digitalWrite(11,HIGH);
		digitalWrite(12,HIGH);
		Snum = 0;
		break;
    }
  }
}