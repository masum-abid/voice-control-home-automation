
String voice;

int led1 = 2;
int led2 = 3;
int fan1 = 4;
int fan2 = 5;
int led3 = 6;

void allon() {
  digitalWrite (led1, HIGH);
  digitalWrite (led2, HIGH);
  digitalWrite (led3, HIGH);
  digitalWrite (fan1, HIGH);
  digitalWrite (fan2, LOW);
}

void allof() {
  digitalWrite (led1, LOW);
  digitalWrite (led2, LOW);
  digitalWrite (led3, LOW);
  digitalWrite (fan1, LOW);
  digitalWrite (fan2, LOW);
}

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(fan1, OUTPUT);
  //pinMode(fan2, OUTPUT);
  digitalWrite(fan1, LOW);
  digitalWrite(fan2, LOW);
}

void loop() {
  while(Serial.available()) {
    delay(10);
    char c=Serial.read();
    if(c=='#')
    {break; }
    voice += c;
}

if (voice.length() > 0) {
  Serial.println(voice);
  if (voice == "*light on")
  {allon() ; }
  else if (voice == "*light out")
  {allof() ; }
  
  else if (voice == "*bedroom on"){
    digitalWrite(2, HIGH) ;
    }
  else if (voice == "*bedroom out"){
    digitalWrite(2, LOW) ;
    }

   else if (voice == "*kitchen on"){
    digitalWrite(3, HIGH) ;
    }
  else if (voice == "*kitchen out"){
    digitalWrite(3, LOW) ;
    }

    else if (voice == "*dining on"){
    digitalWrite(6, HIGH) ;
    }
  else if (voice == "*dining out"){
    digitalWrite(6, LOW) ;
    }

   else if (voice == "*fan on"){
    digitalWrite(4, HIGH) ;
    }
  else if (voice == "*fan of"){
    digitalWrite(4, LOW) ;
    }
  
voice="";
}
}


