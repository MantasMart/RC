#define ena 5
#define in1 6
#define in2 7
#define in3 8
#define in4 9
#define enb 10

int turnPWMforward = 90; //0 to 255
int turnPWMbackwards = 200;
int state = 0;
char direc = '0';

bool up = false;
bool down = false;
bool left = false;
bool right = false;

void set_drive_direction();

void setup() {
  pinMode(ena, OUTPUT);
  digitalWrite(ena, LOW);

  pinMode(in1, OUTPUT);
  digitalWrite(in1, LOW);

  pinMode(in2, OUTPUT);
  digitalWrite(in2, LOW);

  pinMode(in3, OUTPUT);
  digitalWrite(in3, LOW);

  pinMode(in4, OUTPUT);
  digitalWrite(in4, LOW);

  pinMode(enb, OUTPUT);
  digitalWrite(enb, LOW);
  
  Serial.begin(9600); // Default communication rate of the Bluetooth module
}
void loop() {
  if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port
// }

 if (state == 'w') {
  if(down == true) down = false;
  up = true;
 } 

 else if (state == 's') {
  if(up == true) up = false;
  down = true;
 } 

  else if (state == 'a') {
  if(right == true) right = false;
  left = true;
 } 

  else if (state == 'd') {
  if(left == true) left = false;
  right = true;  
 } 

  else if (state == 'u') {
  up = false;  
 } 

  else if (state == 'j') {
  down = false;
 } 

  else if (state == 'h') {
  left = false;
 } 

  else if (state == 'k') {
  right = false;  
 } 

 else if(state == 'p'){
  up = false;
  down = false;
  left = false;
  right = false;
  }
  
  state = 0;
  set_drive_direction();

  }
}

void set_drive_direction(){
  
    if(left == true && down == true) {
    //  direc = '8';
      Serial.println("BACKWARDS LEFT");
      digitalWrite(ena, HIGH);
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      
      analogWrite(enb, turnPWMbackwards);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      
      }
  
    else if(right == true && down == true){ 
    //  direc = '7';
    Serial.println("BACKWARDS RIGHT");
      analogWrite(ena, turnPWMbackwards);
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      
      digitalWrite(enb, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      
      }
      
    else if (right == true && up == true) {
     // direc = '6';
     Serial.println("FORWARD RIGHT");
      analogWrite(ena, turnPWMforward);
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      
      digitalWrite(enb, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      
      }
    else if (left == true && up == true){ 
     // direc = '5';
     Serial.println("FORWARD LEFT");
      digitalWrite(ena, HIGH);
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      
      analogWrite(enb, turnPWMforward);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      
      }
      
    else if (right == true){ 
     // direc = '4';
     Serial.println("RIGHT");
      digitalWrite(ena, HIGH);
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);

      digitalWrite(enb, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      
      }
      
    else if (left == true){ 
     // direc = '3';
     Serial.println("LEFT");
      digitalWrite(ena, HIGH);
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);

      digitalWrite(enb, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      
      }
      
    else if (down == true){ 
     // direc = '2';
     Serial.println("BACKWARDS");
      digitalWrite(ena, HIGH);
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);

      digitalWrite(enb, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      
      }
      
    else if (up == true){ 
     // direc = '1';
     Serial.println("FORWARD");
      digitalWrite(ena, HIGH);
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);

      digitalWrite(enb, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      
      }
      
    else{ 
     // direc = '0';
     Serial.println("STOP");
      digitalWrite(ena, LOW);
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);

      digitalWrite(enb, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      
      }

   // Serial.println(direc);
  }

