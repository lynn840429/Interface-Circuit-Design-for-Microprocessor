byte numTo7[10]={B01111110,B00001100,B10110110,B10011110,B11001100,B11011010,B11111000,B01001110,B11111110,B11001110};
int A_IN[4] = {0,0,0,0};
int flag[4] = {0,0,0,0};
int s[4] = {1,0,0,0};
int hold1;
int b = 0;

void setup() {
  for (int DIN=2; DIN<=13; DIN++)
    pinMode(DIN, OUTPUT);	//D3~D13

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
}
////////////////////////////////////////
void setPort(byte L)
{
	for (int i=0;i<=7;i++)
	{
		if ( ((L>>i)&1) == 1 )
			digitalWrite(i+2,LOW);
		else
			digitalWrite(i+2,HIGH);
	}
}
////////////////////////////////////////
void loop() {
	if(analogRead(A0) >= 512)
		flag[0] = 1;
	else
		if(flag[0] == 1){
			A_IN[0]++;
			flag[0] = 0;
		}
	if(analogRead(A1) >= 512)
		flag[1] = 1;
	else
		if(flag[1] == 1){
			A_IN[1]++;
			flag[1] = 0;
		}
	if(analogRead(A2) >= 512)
		flag[2] = 1;
	else
		if(flag[2] == 1){
			A_IN[2]++;
			flag[2] = 0;
		}
	if(analogRead(A3) >= 512)
		flag[3] = 1;
	else
		if(flag[3] == 1){
			A_IN[3]++;
			flag[3] = 0;
		}
			
	//////////////////////////////進位
	if((A_IN[0]/10) == 1){
		A_IN[0] = ( A_IN[0]%10 );
		A_IN[1] = A_IN[1] + 1;
	}
	if((A_IN[1]/10) == 1){
		A_IN[1] = ( A_IN[1]%10 );
		A_IN[2] = A_IN[2] + 1;
	}
	if((A_IN[2]/10) == 1){
		A_IN[2] = ( A_IN[2]%10 );
		A_IN[3] = A_IN[3] + 1;
	}
	if((A_IN[3]/10) == 1){
		A_IN[3] = ( A_IN[3]%10 );
	}
	//////////////////////////////
	setPort(numTo7[A_IN[b]]);
  
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

