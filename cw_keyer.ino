int paddle_left = 3;
int paddle_right = 9;
int straight_key = 10;
int buzzer = 7;


bool alreadyPlaying = false;
int pot = A0;
int wpm = 30;


unsigned long saveTime;
unsigned long timeSinceLastButton;

void setup() {
  // put your setup code here, to run once:
  pinMode(paddle_left, INPUT_PULLUP);
  pinMode(paddle_right, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  pinMode(pot, INPUT);
  pinMode(straight_key, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  wpm = map(analogRead(pot), 0, 1023, 5, 50) / 2;
  int waitms = 1200 / wpm;
  int dit_speed = waitms;
  timeSinceLastButton = millis() - saveTime;
  int left_state = digitalRead(paddle_left);
  int right_state = digitalRead(paddle_right);
  int key_state = digitalRead(straight_key);
  if (key_state == 0) {
    tone(buzzer, 501);
  }
  else {
    noTone(buzzer);
  }
  if (left_state == 0) {
    //if (!alreadyPlaying) {
    tone(buzzer, 501);
    delay(dit_speed);
    noTone(buzzer);
    //alreadyPlaying = true;
    //}
    delay(dit_speed);
  }
  else {
    //alreadyPlaying = false;
  }
  if (right_state == 0) {
    //if (!alreadyPlaying) {
    tone(buzzer, 501);
    delay(dit_speed * 3);
    noTone(buzzer);
    //alreadyPlaying = true;
    //}
    delay(dit_speed);
  }
  else {
    //alreadyPlaying = false;
  }
}
