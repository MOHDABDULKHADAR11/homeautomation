//****MY IOT APP****//

int light=8;
int fan=7;

int received=0;
int light_state =0;
int fan_state =0;

void setup() {
  Serial.begin(9600);
  pinMode(light,OUTPUT);
  pinMode(fan,OUTPUT);

}

void loop() {

  if(Serial.available()>0)
  {
    received = Serial.read();
  }
  
if(light_state == 0 && received == '1')
{
  digitalWrite(light,HIGH);
  light_state=1;
  received=0;
  Serial.print("LIGHT IS TURNED ON");
}
if(light_state ==1 && received == '1')
{
  digitalWrite(light,LOW);
  light_state=0;
  received=0;
  Serial.print("\nLIGHT IS TURNED OFF");
}
if(fan_state ==0 && received == '3')
{
  digitalWrite(fan,HIGH);
  fan_state=1;
  received=0;
  Serial.print("\nFAN IS TURNED ON");
}
if(fan_state ==1 && received == '3')
{
  digitalWrite(fan,LOW);
  fan_state=0;
  received=0;
  Serial.print("\nFAN IS TURNED OFF");
}
}
