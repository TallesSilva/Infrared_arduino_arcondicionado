#include <IRremote.h>

int led1 = 7;
int led2 = 6;

int bot1 = 5;
int stbot1 = 0;

int bot2 = 4; 
int stbot2 = 0;
 
char y;
int i = 0;
int ii = 0;
int pessoa = 0;


IRsend irsend;

void setup()
{
  Serial.begin(9600);
  pinMode(led1, OUTPUT); // uso do pino 4 (led1) como SAÍDA
  pinMode(led2, OUTPUT); 
  pinMode(bot1, INPUT);
  pinMode(bot2, INPUT);
   // Configuração da porta serial para comunicação à taxa de 9600 bps
}

void loop()
{ 
  stbot2=digitalRead(bot2);
  stbot1=digitalRead(bot1);


  if(stbot1==HIGH)
    {i=0;
      digitalWrite(led1, LOW);
    }
    if(stbot1!=HIGH)
    {
      if(i==0)
       {
      digitalWrite(led1, HIGH);
        pessoa++;
      i++;
       }
    }
if(stbot2==HIGH)
    {ii=0;
      digitalWrite(led2, LOW);
    }
    if(stbot2!=HIGH)
    {
      if(ii==0)
       {
      digitalWrite(led2, HIGH);
        pessoa--;
      ii++;
       }
    }
  
  if(pessoa<0)
    {
      pessoa = 0;
    }
  
  if(Serial.available()>0)
  {
    y = Serial.read();

    switch(y)
    {
      case 'P':
              Serial.print(pessoa);
              Serial.print('\n');
              break;
      case 'A':
             SendChannelUpCodeDesligar();
             delay(500);
             break;
      case 'B': 
             SendChannelUpCode24();
             delay(500);
              break;
      case 'C':
             SendChannelUpCode23();
             delay(500);
              break;
      case 'D':
             SendChannelUpCode22();
             delay(500);
              break;
      case 'E':
             SendChannelUpCode20();
             delay(500);
              break;
      case 'F':
             SendChannelUpCode19();
             delay(500);
             break;
      default:
              break;
    }
  } 
}

 

void SendChannelUpCodeDesligar() 
{
  int khz = 38; // 38kHz carrier frequency for the NEC protocol
  unsigned int irSignal[] = {8900,4450, 650,1650, 600,1700, 600,600, 600,550, 600,1700, 600,1650, 600,1700, 600,550, 600,600, 600,550, 650,550, 600,1700, 600,600, 550,600, 600,600, 550,600, 600,600, 600,550, 600,550, 650,550, 600,600, 600,550, 600,1700, 600,1700, 600,550, 650,1650, 600,550, 650,550, 600,1650, 650,550, 600,1700, 600,600, 550,600, 600,1700, 600,550, 650}; //AnalysIR Batch Export (IRremote) - RAW
  irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.
  delay(5000);
}

void SendChannelUpCode20()
{
  int khz = 38; // 38kHz carrier frequency for the NEC protocol
  unsigned int irSignal[] = {8950,4400, 650,1700, 550,600, 600,600, 550,1700, 600,600, 600,550, 650,1650, 600,550, 650,550, 600,600, 600,1650, 600,600, 600,550, 600,600, 600,550, 650,550, 600,600, 600,550, 600,600, 600,550, 600,600, 600,550, 600,1700, 600,1700, 600,550, 600,1700, 600,600, 600,550, 600,1700, 600,550, 600,1700, 600,550, 600,600, 600,1650, 650,550, 600}; //AnalysIR Batch Export (IRremote) - RAW
  irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.
  delay(5000);
}

void SendChannelUpCode19()
{
  int khz = 38; // 38kHz carrier frequency for the NEC protocol
  unsigned int irSignal[] = {9000,4400, 650,1650, 600,600, 550,600, 600,1700, 600,600, 600,550, 600,1700, 600,550, 600,1700, 600,1700, 550,600, 600,550, 600,600, 600,550, 650,550, 600,600, 600,550, 600,600, 600,550, 600,600, 600,550, 650,550, 600,1700, 600,1700, 600,550, 600,1700, 600,550, 600,600, 600,1650, 600,600, 600,1650, 600,600, 600,550, 650,1700, 600,550, 600}; //AnalysIR Batch Export (IRremote) - RAW
  irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.
  delay(5000);
}

void SendChannelUpCode22() 
{
  int khz = 38; // 38kHz carrier frequency for the NEC protocol
  unsigned int irSignal[] = {9000,4400, 650,1650, 600,600, 550,650, 550,1700, 600,600, 600,550, 600,1700, 600,550, 600,600, 600,1650, 600,1700, 600,550, 600,600, 600,550, 650,550, 600,600, 600,550, 600,600, 600,550, 600,600, 600,550, 650,550, 600,1700, 600,1700, 600,550, 600,1700, 600,550, 600,600, 600,1650, 600,600, 600,1650, 650,550, 600,600, 600,1700, 600,550, 600}; //AnalysIR Batch Export (IRremote) - RAW
  irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.
  delay(5000);
}

void SendChannelUpCode23()
{
  int khz = 38; // 38kHz carrier frequency for the NEC protocol
  unsigned int irSignal[] = {8950,4400, 650,1650, 600,600, 550,600, 600,1700, 600,600, 600,550, 600,1700, 600,550, 600,1700, 600,1700, 550,1700, 600,600, 600,550, 650,550, 600,600, 600,550, 600,600, 600,550, 600,600, 550,600, 600,600, 600,550, 600,1700, 600,1700, 600,550, 600,1700, 600,550, 600,600, 600,1650, 600,600, 600,1700, 600,550, 650,550, 600,1700, 600,550, 600}; //AnalysIR Batch Export (IRremote) - RAW
  irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.
  delay(5000);
}

void SendChannelUpCode24()
{
  int khz = 38; // 38kHz carrier frequency for the NEC protocol
  unsigned int irSignal[] = {9050,4350, 650,1650, 650,550, 600,550, 600,1700, 600,600, 600,550, 600,1700, 600,550, 600,600, 600,550, 600,600, 600,1650, 600,600, 600,550, 650,550, 600,600, 600,550, 600,600, 600,550, 600,600, 600,550, 600,600, 600,1650, 650,1650, 600,600, 600,1700, 600,550, 600,600, 600,1650, 600,600, 600,1650, 650,550, 600,550, 650,1650, 600,550, 650};  delay(5000);
}
