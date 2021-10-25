# ECE1895-DesignProject2-RRRK
Ravi Gandhi, Reece Basehore, Ryan Hankee, Kamden Sarkey; Design Project 2 for ECE 1895 Fall 2021
void setup() {
  // put your setup code here, to run once:
  //pinMode(A0, INPUT_PULLUP);//Enable - did not need to be an input
  pinMode(A1, INPUT_PULLUP);//IO1
  pinMode(A2, INPUT_PULLUP);//IO2
  pinMode(A3, INPUT_PULLUP);//IO3
  pinMode(A4, OUTPUT);
  //pinMode(A5, INPUT_PULLUP) --reset if needed
}

void loop() {
  // put your main code here, to run repeatedly:
int input_answer;
int score = 0;
while(true){  //while power on
  int correct_answer = command();
    while(digitalRead(A0)){ //while Enable high
      delay(3000);
      int input_answer = 0;
      if(digitalRead(A1) && (!digitalRead(A2)) && (!digitalRead(A3))){
        input_answer = 1;//while first input activated
      }
      else if((!digitalRead(A1)) && (digitalRead(A2)) && (!digitalRead(A3))){
        input_answer = 2;//while second input activated
      }
      else if((!digitalRead(A1)) && (!digitalRead(A2)) && (digitalRead(A3))){
        input_answer = 3;//while third input activated
      }
      else{
        input_answer = 0;
      }
      digitalWrite(A0, LOW);
    }
    if(input_answer == correct_answer){
      //call correct audio file
      delay(3000);
      score++;
    }
    else{
      //call end of game audio
      //announce score
      
    }
  }
}

int command(){
  int randomNumber = random(1,4);
  digitalWrite(A0, HIGH);
  //call audio file
  delay(3000);
  return randomNumber;
}
