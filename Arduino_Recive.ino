int a;
int  m=0;
char input;
int count=0;
int yais;
int yaxis[10];
String val;
String tempX;
void setup()
{
Serial.begin(9600);
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
  Serial.println(tempX);
  tempY = tempY.substring(yaxis[0], tempY.length() - 1);
  Serial.println(tempY);
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
  Serial.println(Y+100); 
  Serial.println("-----------------------------------------");
 }
 }
  
} 
