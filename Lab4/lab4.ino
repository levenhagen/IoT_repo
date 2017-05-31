
int pin = 10;
int pinPotenciometro = A0;

int fade;

void setup()
{
  Serial.begin(9600); 
  
  pinMode(pin, OUTPUT); 
}
 
void loop()
{
  //determina o "fading" e "escreve"
  fade = (255 - map( analogRead(pinPotenciometro), 0, 1024, 0, 255 ));
  analogWrite(pin, fade);


 
}
