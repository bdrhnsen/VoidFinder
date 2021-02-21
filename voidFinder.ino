#include <Servo.h>
// Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;
// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 4;
Servo servo;
long distance;
long degree;
float distance_in_cm;
float avg_dist_for_one_degree;
float total_distance_in_one_scan, avg_distance_total;
const int pingPin = 12; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 11; // Echo Pin of Ultrasonic Sensor
long duration; // duration of signal
float dist_angle_arr[150];
float possible_void[40]={0.0};
int temp,temp2,temp3,counter,angle,nec_delay;
float heading;
void setup() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);  
  
  servo.attach(10);
pinMode(pingPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(115200); // Starting Serial Terminal
}

void loop() {
  counter=0;
  temp2=0;
  for (int i = 0; i<120; i+=2){//for each angle from 19degrees till 170 degrees I find corresponding distance measurement
  servo.write(i);
  int temp=0;
  duration = readUltraSonic();
  distance=microseconds2Millimeters(duration);
  delay(350);
  distance_in_cm=distance/10;
  dist_angle_arr[i]=distance_in_cm;
  total_distance_in_one_scan=total_distance_in_one_scan+distance_in_cm;
  }
  avg_distance_total=total_distance_in_one_scan/60;//if distances are higher than average for some of the degrees in a row I assume it to be the non-obstacle area
   Serial.print(" avg_distance_total: ");
   Serial.println(avg_distance_total);
  for (int p=0; p<120;p++){
    if (dist_angle_arr[p]>(avg_distance_total+5)){
      possible_void[p]=p;
    temp2=temp2+p;
    counter++;
    }
    }
  heading=temp2/counter;
   //I found heading with the assumption of the middle point of the obstacle free region should be my heading.
  //neutral sensor is at 60 degrees

if (heading<60){
  angle=(60.0-heading);
  rotate_to_right(angle);
  go_straight();
  stop_moving();
}
if(heading>60){
  angle=(heading-60.0);
 //u_turn();
 rotate_to_left(angle);
  go_straight();
  stop_moving();
}
}
long readUltraSonic(){
digitalWrite(pingPin, LOW);
delayMicroseconds(2);
digitalWrite(pingPin, HIGH);
delayMicroseconds(10);
digitalWrite(pingPin, LOW);
return pulseIn(echoPin, HIGH, 25000);
}
long microseconds2Millimeters(long microseconds) {
long distance_in_mm=0;
// I tried to eliminate the spikes, otherwise sometimes it measures 4000mm or 0mm
distance_in_mm=0.1715*microseconds;
 if (distance_in_mm>350){
  return distance_in_mm;
 }
 if(distance_in_mm==0){
  return distance_in_mm;
 }
 else
 return distance_in_mm;
}

void u_turn(){
  rotate_to_right(180);
}
 void rotate_to_right(float angle){
    //500ms delay corresponds to almost 100degrees of rotation
  Serial.print("angle");
  Serial.println(angle);
  analogWrite(enA, 255);
  analogWrite(enB, 255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  nec_delay=angle*5;
  delay(nec_delay);
    // so I will assume for every one degree rotation necassary I should give 5ms delay
  }
   void rotate_to_left(float angle){
    //500ms delay corresponds to almost 100degrees of rotation
   Serial.print("angle");
  Serial.println(angle);
  analogWrite(enA, 255);
  analogWrite(enB, 255);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  nec_delay=angle*5;
  delay(nec_delay);
    // so I will assume for every one degree rotation necassary I should give 5ms delay
  }
  void stop_moving(){
  analogWrite(enA, 255);
  analogWrite(enB, 255);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(1000);
  }
  void go_straight(){
  analogWrite(enA, 255);
  analogWrite(enB, 255);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(3500);
  
  }
  
