///////////////////////////////////////////////////////////////////////////////////
////////////////////////// OTTOBOT Workshop 2024 CODE /////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
// This is the provided code for the 2024 OTTOBOT workshop. We 
// have provided some pre-built functions that make the OTTOBOT
// get its GROOVE on. This code was written by MTRNSOC Workshop
// and Project Directors 2024. 
// This is all thanks to OTTODIY: https://www.ottodiy.com/
// Make sure to have installed all libraries: https://github.com/OttoDIY/OttoDIYLib
///////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////
/////////////////////////// SETUP  //////////////////////////////
/////////////////////////////////////////////////////////////////
// The setup runs once 
// You do not need to edit this code
/////////////////////////////////////////////////////////////////

#include <Otto.h>

Otto Otto;  //This is Otto!

#define LeftLeg 2 
#define RightLeg 3
#define LeftFoot 4 
#define RightFoot 5 
#define Buzzer  13 
#define DIN A3 // Data In pin
#define CS A2  // Chip Select pin
#define CLK A1 // Clock pin
#define Orientation 1 // 8x8 LED Matrix orientation  Top  = 1, Bottom = 2, Left = 3, Right = 4 

char charRead;
int echoPin = 9;
int trigPin = 8;
float time;
float dist;

void setup(){
  Serial.begin(9600);
  Otto.init(LeftLeg, RightLeg, LeftFoot, RightFoot, true, Buzzer); 
  Otto.initMATRIX( DIN, CS, CLK, Orientation);
  Otto.home();
    delay(50);
  
	// Set the echoPin as an input
	pinMode(echoPin, INPUT); 
  	
  // Set the trigPin as an output
  pinMode(trigPin, OUTPUT); 
  
}

/////////////////////////////////////////////////////////////////
/////////////////////////// LOOP ////////////////////////////////
/////////////////////////////////////////////////////////////////
// The loop runs continually until the OTTOBOT is unplugged
// You can edit this code to create custom dance routines!
/////////////////////////////////////////////////////////////////

void loop() { 
  
  Otto.home();


  /////////////////////////////////////////////////////////////////
  ///////////////// ULTRASONIC SENSOR CODE ////////////////////////
  /////////////////////////////////////////////////////////////////
  
  // Clears the trigPin
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);

  // Sets trigPin to pulse for 10microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // returns the sound wave travel time in microseconds
	time = pulseIn(echoPin, HIGH);
  
  // calculate the distance
	dist = time * 0.0342/2;
  
  // print distance to check 
  Serial.print("Distance: ");
  Serial.println(dist);

  // If an object is <10cm away then move back 5 steps
  if (dist < 10 && dist != 0) {
    Otto.walk(3,1000,-1);
  }





  // This IF STATEMENT reads keyboard input
  if (Serial.available() > 0) {
    char charRead = Serial.read();
    
    /////////////////////////////////////////////////////////////////
    //////////////// PRE BUILT DANCE FUNCTIONS //////////////////////
    /////////////////////////////////////////////////////////////////
    // Feel Free to test these functions out via the serial monitor
    // Once you have tested these functions out you can edit them and
    // create your own cool dancing routine. 
    /////////////////////////////////////////////////////////////////
    
    if (charRead == 'q') {
    Serial.println("Walking Forwards");
    Otto.walk(2,1000,1); // WALK 2 STEPS FORWARD
    Otto.walk(2,1000,-1); // WALK 2 STEPS BACKWARD
    }

    if ((charRead) == ('w')) {
      Otto.turn(2,1000,1); // TURN 3 STEPS LEFT
      Otto.turn(2,1000,-1); // TURN 3 STEPS RIGHT
    }

    if ((charRead) == ('e')) {
      Otto.bend (1,500,1); // BENDING FORWARD (?)
      Otto.bend (1,2000,-1); //BENDING BACKWARD (?)
    }

    if ((charRead) == ('r')) {
      Otto.shakeLeg (1,1500, 1); // SHAKE LEG
      Otto.home(); // RETURN 
      Otto.shakeLeg (1,2000,-1); // SHAKE LEG
      Otto.home(); // RETURN 
    }

    if ((charRead) == ('t')) {
      Otto.moonwalker(3, 1000, 25,1); //LEFT
      Otto.moonwalker(3, 1000, 25,-1); //RIGHT  
    }

    if ((charRead) == ('y')) {
      Otto.crusaito(2, 1000, 20,1); // DANCE
      Otto.crusaito(2, 1000, 20,-1); // DANCE
    }

  }
  
  
}
  
/////////////////////////////////////////////////////////////////
////////////////OTHER OTTOBOT FUNCTIONS /////////////////////////
/////////////////////////////////////////////////////////////////
// Below are some other OTTOBOT functions you may like to 
// experiment with. Try swapping them with some of the above
// functions or integrating them into a dance routine. NOTE -
// Some of these functions may require additional hardware 
// in order to function properly.
/////////////////////////////////////////////////////////////////

  /*
  Otto.walk(2,1000,1); //2 steps, "TIME". IF HIGHER THE VALUE THEN SLOWER (from 600 to 1400), 1 FORWARD
  Otto.walk(2,1000,-1); //2 steps, T, -1 BACKWARD
  Otto.turn(2,1000,1);//3 steps turning LEFT
  Otto._tone(10, 3, 1);
  Otto.bendTones (100, 200, 1.04, 10, 10);
    Otto.home();
    delay(100);  
  Otto.turn(2,1000,-1);//3 steps turning RIGHT 
  Otto.bend (1,500,1); //usually steps =1, T=2000
  Otto.bend (1,2000,-1);    
  Otto.shakeLeg (1,1500, 1);   
    Otto.home();
    delay(100);
  Otto.shakeLeg (1,2000,-1);
  Otto.moonwalker(3, 1000, 25,1); //LEFT
  Otto.moonwalker(3, 1000, 25,-1); //RIGHT  
  Otto.crusaito(2, 1000, 20,1);
  Otto.crusaito(2, 1000, 20,-1);
    delay(100); 
  Otto.flapping(2, 1000, 20,1);
  Otto.flapping(2, 1000, 20,-1);
    delay(100);        
  Otto.swing(2, 1000, 20);
  Otto.tiptoeSwing(2, 1000, 20);
  Otto.jitter(2, 1000, 20); //(small T)
  Otto.updown(2, 1500, 20);  // 20 = H "HEIGHT of movement"T 
  Otto.ascendingTurn(2, 1000, 50);
  Otto.jump(1,500); // It doesn't really jumpl ;P
  Otto.home();
     delay(100);  
  Otto.playGesture(OttoHappy);
  Otto.playGesture(OttoSuperHappy);
  Otto.playGesture(OttoSad);
  Otto.playGesture(OttoVictory); 
  Otto.playGesture(OttoAngry); 
  Otto.playGesture(OttoSleeping);
  Otto.playGesture(OttoFretful);
  Otto.playGesture(OttoLove);
  Otto.playGesture(OttoConfused);        
  Otto.playGesture(OttoFart);
  Otto.playGesture(OttoWave);
  Otto.playGesture(OttoMagic);
  Otto.playGesture(OttoFail);
    Otto.home();
    delay(100);  
  Otto.putMouth(zero);
  delay(100);
  Otto.putMouth(one);
  delay(100);
  Otto.putMouth(two);
  delay(100);
  Otto.putMouth(three);
  delay(100);
  Otto.putMouth(four);
  delay(100);
  Otto.putMouth(five);
  delay(100);
  Otto.putMouth(6);
  delay(100);
  Otto.putMouth(7);
  delay(100);
  Otto.putMouth(8);
  delay(100);
  Otto.putMouth(9);
  delay(100);
  Otto.putMouth(smile);
  delay(100);
  Otto.putMouth(happyOpen);
  delay(100);
  Otto.putMouth(happyClosed);
  delay(100);
  Otto.putMouth(heart);
  delay(100);
  Otto.putMouth(angry);
  delay(100);
  Otto.putMouth(smallSurprise);
  delay(100);
  Otto.putMouth(bigSurprise);
  delay(100);
  Otto.putMouth(tongueOut);
  delay(100);
  Otto.putMouth(confused);
  delay(100);
  Otto.putMouth(21); //diagonal
  delay(100);
  Otto.putMouth(27); //interrogation
  delay(100);
  Otto.putMouth(23); //sad open
  delay(100);
  Otto.putMouth(24); //sad closed
  delay(100);
  Otto.putMouth(vamp1);
  delay(100);
  Otto.putMouth(vamp2);
  delay(100);
  Otto.putMouth(xMouth);
  delay(100);
  Otto.putMouth(okMouth);
  delay(100);
  Otto.putMouth(thunder);
  delay(100);
  Otto.putMouth(lineMouth);
  delay(100);
  Otto.putMouth(culito);
    delay(100); 
  Otto.putAnimationMouth(littleUuh,0);
  delay(1000); 
  Otto.putAnimationMouth(dreamMouth, 0);
  delay(1000); 
  Otto.putAnimationMouth(dreamMouth, 1);
  delay(1000); 
  Otto.putAnimationMouth(dreamMouth, 2);
  delay(1000); 
  */
  
