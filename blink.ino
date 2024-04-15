/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// The dot function turns on the LED for 1 unit = 500ms and then turns it off.
void dot()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500); // We are assuming one unit = 500ms = 1/2 second.
  digitalWrite(LED_BUILTIN, LOW);
  space_between_parts_of_same_letter();
}

// The dash function turns on the LED for 3 units = 1500ms and then turns it off.
void dash()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1500);
  digitalWrite(LED_BUILTIN, LOW);
  space_between_parts_of_same_letter();
}

// Like the letter a has morse code . -  which means that this 
// function will be called between the dot and dash of the morse code of a.
void space_between_parts_of_same_letter()
{
  delay(500); 
}

// Like there is a word ae. The morse code of ae would be . - .  The first dot and 
// dash is for letter a and the second dot is for the letter e. So between the dash and the second dot we are going to call this function.
void space_between_letters()
{
  delay(1000); // We are writiing 1000 because we already get a delay of 500ms after every dot and a dash.
}


// Like are two words to be typed a e. Then the morse code for this would be . -  .
// The first dot and dash represent the letter a and then we give a space which means a new word has started. So between the dash and the second dot this function is going to 
// be called.
void space_between_words()
{
  delay(3000); // We are writiing 3000 because we already get a delay of 500ms after every dot and a dash.
}

// This function has all the morse codes for each character. 
void morse_code_for_character(char c)
{
  switch(c)
  {
    case 'A' : case 'a':
      dot(); dash();
      break;
    case 'B': case 'b':
      dash(); dot(); dot(); dot();
      break;
    case 'C': case 'c':
      dash(); dot(); dash(); dot();
      break;
    case 'D': case 'd':
      dash(); dot(); dot();
      break;
    case 'E': case 'e':
      dot();
      break;
    case 'F': case 'f':
      dot(); dot(); dash(); dot();
      break;
    case 'G': case 'g':
      dash(); dash(); dot();
      break;
    case 'H': case 'h':
      dot(); dot(); dot(); dot();
      break;
    case 'I': case 'i':
      dot(); dot();
      break;
    case 'J': case 'j':
      dot(); dash(); dash(); dash();
      break;
     case 'K': case 'k':
      dash(); dot(); dash();
      break;
    case 'L': case 'l':
      dot(); dash(); dot(); dot();
      break;
    case 'M': case 'm':
      dash(); dash();
      break;
    case 'N': case 'n':
      dash(); dot();
      break;
    case 'O': case 'o':
      dash(); dash(); dash();
      break;
    case 'P': case 'p':
      dot(); dash(); dash(); dot();
      break;
    case 'Q': case 'q':
      dash(); dash(); dot(); dash();
      break;
    case 'R': case 'r':
      dot(); dash(); dot();
      break;
    case 'S': case 's':
      dot(); dot(); dot();
      break;
    case 'T': case 't':
      dash();
      break;
    case 'U': case 'u':
      dot(); dot(); dash();
      break;
     case 'V': case 'v':
      dot(); dot(); dot(); dash();
      break;
    case 'W': case 'w':
      dot(); dash(); dash();
      break;
    case 'X': case 'x':
      dash(); dot(); dot(); dash();
      break;
    case 'Y': case 'y':
      dash(); dot(); dash(); dash();
      break;
    case 'Z': case 'z':
      dash(); dash(); dot(); dot();
      break;
    default:
    delay(3500); // If the character is not present run a delay for the time between two words that is 7 units = 3500ms.
    break;
  }
}

void blink_particular_name(String s)
{
  int len = s.length();
  for(int i = 0; i < len; i++)
  {
    if(s[i] == ' ')
    {
      space_between_words();
    }
    else
    {
      morse_code_for_character(s[i]);
      space_between_letters();
    }
  }
}

// the loop function runs over and over again forever
void loop() {
  blink_particular_name("Archit");
  delay(2000); // After the last letter we have a gap of 1500ms and to make a gap of one word we need 3500ms. So we add a delay of 2000ms and after that again word would be repeated.
}
