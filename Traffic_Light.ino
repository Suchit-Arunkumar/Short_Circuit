// Defining LEDs and Push Button
int green = 8;
int yellow = 9;
int red = 10;

int pushButton = 7;
int read = 0;

void setup() 
{
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(pushButton, INPUT);
  
  Serial.begin(9600);
}

void loop() 
{
  read = digitalRead(pushButton);
  Serial.println(read);  // Debugging output
  
  if (read == 0) { // Normal traffic light cycle
    digitalWrite(red, LOW);
	digitalWrite(yellow, LOW);
    digitalWrite(green, HIGH);

    // Check button while green is on
    for (int i = 0; i < 30; i++) 
	{ 
      if (digitalRead(pushButton) == HIGH) 
		{
         crossing();  // Jump to pedestrian crossing
		 return;
        }
      delay(100);
    }

    digitalWrite(green, LOW);
	digitalWrite(red, LOW);
    digitalWrite(yellow, HIGH);

    // Check button while yellow is on
    for (int i = 0; i < 30; i++) 
	{ 
      if (digitalRead(pushButton) == HIGH) 
		{
         crossing();
		 return;
		}
      delay(100);
    }

    digitalWrite(yellow, LOW);
	digitalWrite(green, LOW);
    digitalWrite(red, HIGH);

    // Check button while red is on
    for (int i = 0; i < 30; i++) 
	{ 
      if (digitalRead(pushButton) == HIGH) 
	  {
       crossing();
       return;
      }
      delay(100);
    }
  }
 else if (read == 1) 
	{
     crossing();
	}
}
 void crossing() // Immediate transition to red
 {
  digitalWrite(green, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);
  delay(5000); 
 }
