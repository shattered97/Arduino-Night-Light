/*  Brian Watral
Night light - 3 colors fades through all the colors
16 Aug 13
*/

//Pins 3/5/6 have the LEDs connected to them
//Pin 0 is used for the photocell - on/off switch
int Green = 3;
int Red = 5;
int Blue = 6;
int lightPin = 0;
int threshold = 1020; //Greater than this no light present
int timer =20; //Timer for fade control

//setup the pins
void setup()
{
  Serial.begin(9600);  //Set Serial communcation
  pinMode(Green, OUTPUT);
  pinMode(Red, OUTPUT);
  pinMode(Blue, OUTPUT);
}

//Loop to run the lights
void loop()
{
 Serial.println(analogRead(lightPin)); //Check light level
 
 if(analogRead(lightPin) > threshold ) //turn if above threshold
 {
    FadeLights();  //Fade the lights cycle
 }
 else //If light present turn off lights
 {
   analogWrite(Red, 0);
   analogWrite(Green, 0);
   analogWrite(Blue, 0);
 }
}

void FadeLights()
{
  for(int x=0; x<256; x++)  //Loop through Green down Blue up
 {
   analogWrite(Green, (255-x));
   analogWrite(Blue, x);
   delay(timer);
 }
 delay(timer * 10);  //increase delay for effect
 for(int y=0; y<256; y++) //Loop through Blue down Red up
 {
   analogWrite(Blue, (255-y));
   analogWrite(Red, y);
   delay(timer);
 }
 delay(timer * 10); //increase delay for effect
 for(int z=0; z<256; z++)  //Loop through Red down Green up
 {
   analogWrite(Red, (255-z));
   analogWrite(Green, z);
   delay(timer);
 }
 delay(timer * 10);  //increase delay for effect  .
}
  
  
