#include <Servo.h>

Servo myservo_main;  // create servo object to control a servo

Servo myservo_y;
// variable to read the value from the analog pin

int a;
int  m=0;
char input;
int count=0;
int yais;
int yaxis[10];
String val;
String tempX;

void fourth()
{
 myservo_main.write(50);  //  4th quardant              // sets the servo position according to the scaled value
myservo_y.write(50);
 delay(1500); 
  
  }

void third()
{
    myservo_main.write(45);  //3rd  quadrant                // sets the servo position according to the scaled value
myservo_y.write(80);
  delay(1500);
  }

void second()
{
    myservo_main.write(21);  //2nd quadrant                // sets the servo position according to the scaled value
myservo_y.write(51);
  delay(1500);
  }

  void first()
{
     myservo_main.write(24);  //  1st quardant              // sets the servo position according to the scaled value
 myservo_y.write(76);
  delay(1500);
  }

void setup()
{
Serial.begin(9600);
  myservo_main.attach(9);  // attaches the servo on pin 9 to the servo object

 myservo_y.attach(11);
    myservo_main.write(31);  //mean  quadrant                // sets the servo position according to the scaled value
 myservo_y.write(60);
 delay(10);

}
void loop()
{
 while(1){ 
  while(Serial.available()>0)
  {
  String val=Serial.readString();
  int len=val.length();
  if(val[0]=='x')
  {
    for(int i=0;i<len;i++)
    {
      int yais=val[i];
      count++;
      if(yais == 'y' || yais == '#')
      {
      yaxis[m]=count;
      
      m++;
      }
    }
  }

  m=0;
  count=0;
  tempX=val;
  String tempY=val;
  tempX.remove(yaxis[0],(yaxis[1]-1));
  tempX.remove(0,1);
  tempX = tempX.substring(0, tempX.length() - 1);
  
  tempY = tempY.substring(yaxis[0], tempY.length() - 1);

  int a = tempY[0];
  int b= tempY[1];
  int c= tempY[2];
  a=a-48;
  b=b-48;
  c=c-48;
  b=b*10;
  a=a*100;
  int Y=a+b+c;
  int d = tempX[0];
  d=d-48;
  d=d*100;
  int e = tempX[1];
  e=e-48;
  e=e*10;
  int f = tempX[2];
  f=f-48;
  int X=d+e+f;
  
len=0;
  Serial.println(X);
  Serial.println(Y);
  delay(100);
  Serial.println("-----------------------------------------");
  int blankX=126;
int blankY=126;
int Xreal=X-blankX;
int Yreal=Y-blankY;
//Serial.println(Xreal);
///Serial.println(Yreal);
if(Xreal > 0 && Yreal >0 )//1
{
  Serial.println("Fourth quadrent");
   fourth();
  
}
if(Xreal > 0 && Yreal < 0 )//2
{
  Serial.println("Third quadrent");
  third();
}

if(Xreal < 0 && Yreal  < 0 )//3
{
  Serial.println("First  quadrent");
first();
}
if(Xreal < 0 && Yreal > 0 )//4
{
  Serial.println("Second  quadrent");
  second();
}
 a=0;
  b=0;
  c=0;
  d=0;
  e=0;
  f=0;
 }



 
 }
  
} 
