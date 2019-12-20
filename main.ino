#include <Arduino.h>

long randNumber;
long randPrevious;
long randCubeNumber;
long randRainNumber;
static const uint8_t ledRow[] = {A1, A2, A3};
static const uint8_t ledCol[] = {2, 3, 4, 5, 6, 7, 8, 9, 11};
#define timer 100
#define transition 400
#define frequencynum 1

void setup () {
  // Initialize the serial monitor in case of diagnostics
  Serial.begin(9600);
  // This for loop defines the column pins, in which there are 9 of them in this case
  for(int i = 0; i < 9; i++) {pinMode(ledCol[i], OUTPUT); digitalWrite(ledCol[i], 0);}
  for(int j = 0; j < 3; j++) {pinMode(ledRow[j], OUTPUT); digitalWrite(ledRow[j], 1);}
  // Define the pin by which the random number's seed is obtained from. It uses the noise 
  // picked up by the analog pin to generate a random number
  randomSeed(analogRead(0)); // Get signal from analog pin A0
}

void turnOn () {
  for(int i = 0; i < 9; i++) {digitalWrite(ledCol[i], 1);}
  for(int j = 0; j < 3; j++) {digitalWrite(ledRow[j], 0);}
}

void turnOnColumns () {
  for(int i = 0; i < 9; i++) {digitalWrite(ledCol[i], 1);}
}

void turnOnRows () {
  for(int j = 0; j < 3; j++) {digitalWrite(ledRow[j], 0);}
}

void turnOff () {
  for(int i = 0; i < 9; i++) {digitalWrite(ledCol[i], 0);}
  for(int j = 0; j < 3; j++) {digitalWrite(ledRow[j], 1);}
}

void turnOffColumns () {
  for(int i = 0; i < 9; i++) {digitalWrite(ledCol[i], 0);}
}

void turnOffRows () {
  for(int j = 0; j < 3; j++) {digitalWrite(ledRow[j], 1);}
}

void singleLedTest () {
  digitalWrite(ledRow[1], LOW); digitalWrite(ledCol[2], HIGH);
}

void trail () {
  Serial.println(" Trail");
  digitalWrite(ledCol[0], 1); digitalWrite(ledRow[0], 0);
  delay(timer);
  digitalWrite(ledCol[0], 0);
  digitalWrite(ledCol[1], 1);
  delay(timer);
  digitalWrite(ledCol[1], 0);
  digitalWrite(ledCol[2], 1);
  delay(timer);
  digitalWrite(ledCol[2], 0);
  digitalWrite(ledCol[5], 1);
  delay(timer);
  digitalWrite(ledCol[5], 0);
  digitalWrite(ledCol[8], 1);
  delay(timer);
  digitalWrite(ledCol[8], 0);
  digitalWrite(ledCol[7], 1);
  delay(timer);
  digitalWrite(ledCol[7], 0);
  digitalWrite(ledCol[6], 1);
  delay(timer);
  digitalWrite(ledRow[0], 1);
  digitalWrite(ledRow[1], 0);
  delay(timer);
  digitalWrite(ledRow[1], 1);
  digitalWrite(ledRow[2], 0);
  delay(timer);
  digitalWrite(ledCol[6], 0);
  digitalWrite(ledCol[7], 1);
  delay(timer);
  digitalWrite(ledCol[7], 0);
  digitalWrite(ledCol[8], 1);
  delay(timer);
  digitalWrite(ledCol[8], 0);
  digitalWrite(ledCol[5], 1);
  delay(timer);
  digitalWrite(ledCol[5], 0);
  digitalWrite(ledCol[2], 1);
  delay(timer);
  digitalWrite(ledCol[2], 0);
  digitalWrite(ledCol[1], 1);
  delay(timer);
  digitalWrite(ledCol[1], 0);
  digitalWrite(ledCol[0], 1);
  delay(timer);
  digitalWrite(ledRow[2], 1);
  digitalWrite(ledRow[1], 0);
  delay(timer);
  digitalWrite(ledRow[1], 1);
  digitalWrite(ledRow[0], 0);
  delay(timer);
  digitalWrite(ledCol[0], 0);
  digitalWrite(ledCol[3], 1);
  delay(timer);
  digitalWrite(ledCol[3], 0);
  digitalWrite(ledCol[6], 1);
  delay(timer);
  digitalWrite(ledRow[0], 1);
  digitalWrite(ledRow[1], 0);
  delay(timer);
  digitalWrite(ledRow[1], 1);
  digitalWrite(ledRow[2], 0);
  delay(timer);
  digitalWrite(ledCol[6], 0);
  digitalWrite(ledCol[7], 1);
  delay(timer);
  digitalWrite(ledCol[7], 0);
  digitalWrite(ledCol[8], 1);
}

void expandingCube () {
  Serial.println(" Expanding Cube");
  // Generates random number to choose which corner to start from.
  randCubeNumber = random(3, 5);
  for(int i = 0; i < randCubeNumber; i++) {
    randNumber = random(1, 9);
    if (randNumber == randPrevious) {randNumber = random(1, 9);}

    // Starting from the bottom of the first column
    if(randNumber == 1) {
      digitalWrite(ledCol[0], 1); digitalWrite(ledRow[0], 0);
      delay(transition);
      digitalWrite(ledCol[1], 1); digitalWrite(ledRow[1], 0);
      digitalWrite(ledCol[3], 1);
      digitalWrite(ledCol[4], 1);
      delay(transition);
      digitalWrite(ledCol[2], 1); digitalWrite(ledRow[2], 0);
      digitalWrite(ledCol[5], 1);
      digitalWrite(ledCol[6], 1);
      digitalWrite(ledCol[7], 1);
      digitalWrite(ledCol[8], 1);
      delay(transition);
      digitalWrite(ledCol[0], 0); digitalWrite(ledRow[0], 1);
      digitalWrite(ledCol[1], 0);
      digitalWrite(ledCol[2], 0);
      digitalWrite(ledCol[3], 0);
      digitalWrite(ledCol[6], 0);
      delay(transition);
      digitalWrite(ledCol[4], 0); digitalWrite(ledRow[1], 1);
      digitalWrite(ledCol[5], 0);
      digitalWrite(ledCol[7], 0);
      delay(transition);
      digitalWrite(ledCol[8], 0); digitalWrite(ledRow[2], 1);
      delay(transition);
    }

    // Starting from the bottom of the third column
    else if(randNumber == 2) {
      digitalWrite(ledCol[2], 1); digitalWrite(ledRow[0], 0);
      delay(transition);
      digitalWrite(ledCol[1], 1); digitalWrite(ledRow[1], 0);
      digitalWrite(ledCol[4], 1);
      digitalWrite(ledCol[5], 1);
      delay(transition);
      digitalWrite(ledCol[0], 1); digitalWrite(ledRow[2], 0);
      digitalWrite(ledCol[3], 1);
      digitalWrite(ledCol[6], 1);
      digitalWrite(ledCol[7], 1);
      digitalWrite(ledCol[8], 1);
      delay(transition);
      digitalWrite(ledCol[0], 0); digitalWrite(ledRow[0], 1);
      digitalWrite(ledCol[1], 0);
      digitalWrite(ledCol[2], 0);
      digitalWrite(ledCol[5], 0);
      digitalWrite(ledCol[8], 0);
      delay(transition);
      digitalWrite(ledCol[3], 0); digitalWrite(ledRow[1], 1);
      digitalWrite(ledCol[4], 0);
      digitalWrite(ledCol[7], 0);
      delay(transition);
      digitalWrite(ledCol[6], 0); digitalWrite(ledRow[2], 1);
      delay(transition);
    }

    // Starting from the bottom of the seventh column
    else if(randNumber == 3) {
      digitalWrite(ledCol[6], 1); digitalWrite(ledRow[0], 0);
      delay(transition);
      digitalWrite(ledCol[3], 1); digitalWrite(ledRow[1], 0);
      digitalWrite(ledCol[4], 1);
      digitalWrite(ledCol[7], 1);
      delay(transition);
      digitalWrite(ledCol[0], 1); digitalWrite(ledRow[2], 0);
      digitalWrite(ledCol[1], 1);
      digitalWrite(ledCol[2], 1);
      digitalWrite(ledCol[5], 1);
      digitalWrite(ledCol[8], 1);
      delay(transition);
      digitalWrite(ledCol[0], 0); digitalWrite(ledRow[0], 1);
      digitalWrite(ledCol[3], 0);
      digitalWrite(ledCol[6], 0);
      digitalWrite(ledCol[7], 0);
      digitalWrite(ledCol[8], 0);
      delay(transition);
      digitalWrite(ledCol[1], 0); digitalWrite(ledRow[1], 1);
      digitalWrite(ledCol[4], 0);
      digitalWrite(ledCol[5], 0);
      delay(transition);
      digitalWrite(ledCol[2], 0); digitalWrite(ledRow[2], 1);
      delay(transition);
    }

    // Starting from the bottom of the ninth column
    else if(randNumber == 4) {
      digitalWrite(ledCol[8], 1); digitalWrite(ledRow[0], 0);
      delay(transition);
      digitalWrite(ledCol[4], 1); digitalWrite(ledRow[1], 0);
      digitalWrite(ledCol[5], 1);
      digitalWrite(ledCol[7], 1);
      delay(transition);
      digitalWrite(ledCol[0], 1); digitalWrite(ledRow[2], 0);
      digitalWrite(ledCol[1], 1);
      digitalWrite(ledCol[2], 1);
      digitalWrite(ledCol[3], 1);
      digitalWrite(ledCol[6], 1);
      delay(transition);
      digitalWrite(ledCol[2], 0); digitalWrite(ledRow[0], 1);
      digitalWrite(ledCol[5], 0);
      digitalWrite(ledCol[6], 0);
      digitalWrite(ledCol[7], 0);
      digitalWrite(ledCol[8], 0);
      delay(transition);
      digitalWrite(ledCol[1], 0); digitalWrite(ledRow[1], 1);
      digitalWrite(ledCol[3], 0);
      digitalWrite(ledCol[4], 0);
      delay(transition);
      digitalWrite(ledCol[0], 0); digitalWrite(ledRow[2], 1);
      delay(transition);
    }

    // Starting from the top of the first column
    else if(randNumber == 5) {
      digitalWrite(ledCol[0], 1); digitalWrite(ledRow[2], 0);
      delay(transition);
      digitalWrite(ledCol[1], 1); digitalWrite(ledRow[1], 0);
      digitalWrite(ledCol[3], 1);
      digitalWrite(ledCol[4], 1);
      delay(transition);
      digitalWrite(ledCol[2], 1); digitalWrite(ledRow[0], 0);
      digitalWrite(ledCol[5], 1);
      digitalWrite(ledCol[6], 1);
      digitalWrite(ledCol[7], 1);
      digitalWrite(ledCol[8], 1);
      delay(transition);
      digitalWrite(ledCol[0], 0); digitalWrite(ledRow[2], 1);
      digitalWrite(ledCol[1], 0);
      digitalWrite(ledCol[2], 0);
      digitalWrite(ledCol[3], 0);
      digitalWrite(ledCol[6], 0);
      delay(transition);
      digitalWrite(ledCol[4], 0); digitalWrite(ledRow[1], 1);
      digitalWrite(ledCol[5], 0);
      digitalWrite(ledCol[7], 0);
      delay(transition);
      digitalWrite(ledCol[8], 0); digitalWrite(ledRow[0], 1);
      delay(transition);
    }

    // Starting from the top of the third column
    else if(randNumber == 6) {
      digitalWrite(ledCol[2], 1); digitalWrite(ledRow[2], 0);
      delay(transition);
      digitalWrite(ledCol[1], 1); digitalWrite(ledRow[1], 0);
      digitalWrite(ledCol[4], 1);
      digitalWrite(ledCol[5], 1);
      delay(transition);
      digitalWrite(ledCol[0], 1); digitalWrite(ledRow[0], 0);
      digitalWrite(ledCol[3], 1);
      digitalWrite(ledCol[6], 1);
      digitalWrite(ledCol[7], 1);
      digitalWrite(ledCol[8], 1);
      delay(transition);
      digitalWrite(ledCol[0], 0); digitalWrite(ledRow[2], 1);
      digitalWrite(ledCol[1], 0);
      digitalWrite(ledCol[2], 0);
      digitalWrite(ledCol[5], 0);
      digitalWrite(ledCol[8], 0);
      delay(transition);
      digitalWrite(ledCol[3], 0); digitalWrite(ledRow[1], 1);
      digitalWrite(ledCol[4], 0);
      digitalWrite(ledCol[7], 0);
      delay(transition);
      digitalWrite(ledCol[6], 0); digitalWrite(ledRow[0], 1);
      delay(transition);
    }

    // Starting from the top of the seventh column
    else if(randNumber == 7) {
      digitalWrite(ledCol[6], 1); digitalWrite(ledRow[2], 0);
      delay(transition);
      digitalWrite(ledCol[3], 1); digitalWrite(ledRow[1], 0);
      digitalWrite(ledCol[4], 1);
      digitalWrite(ledCol[7], 1);
      delay(transition);
      digitalWrite(ledCol[0], 1); digitalWrite(ledRow[0], 0);
      digitalWrite(ledCol[1], 1);
      digitalWrite(ledCol[2], 1);
      digitalWrite(ledCol[5], 1);
      digitalWrite(ledCol[8], 1);
      delay(transition);
      digitalWrite(ledCol[0], 0); digitalWrite(ledRow[2], 1);
      digitalWrite(ledCol[3], 0);
      digitalWrite(ledCol[6], 0);
      digitalWrite(ledCol[7], 0);
      digitalWrite(ledCol[8], 0);
      delay(transition);
      digitalWrite(ledCol[1], 0); digitalWrite(ledRow[1], 1);
      digitalWrite(ledCol[4], 0);
      digitalWrite(ledCol[5], 0);
      delay(transition);
      digitalWrite(ledCol[2], 0); digitalWrite(ledRow[0], 1);
      delay(transition);
    }

    // Starting from the
    else if(randNumber == 8) {
      digitalWrite(ledCol[8], 1); digitalWrite(ledRow[0], 0);
      delay(transition);
      digitalWrite(ledCol[4], 1); digitalWrite(ledRow[1], 0);
      digitalWrite(ledCol[5], 1);
      digitalWrite(ledCol[7], 1);
      delay(transition);
      digitalWrite(ledCol[0], 1); digitalWrite(ledRow[2], 0);
      digitalWrite(ledCol[1], 1);
      digitalWrite(ledCol[2], 1);
      digitalWrite(ledCol[3], 1);
      digitalWrite(ledCol[6], 1);
      delay(transition);
      digitalWrite(ledCol[2], 0); digitalWrite(ledRow[0], 1);
      digitalWrite(ledCol[5], 0);
      digitalWrite(ledCol[6], 0);
      digitalWrite(ledCol[7], 0);
      digitalWrite(ledCol[8], 0);
      delay(transition);
      digitalWrite(ledCol[1], 0); digitalWrite(ledRow[1], 1);
      digitalWrite(ledCol[3], 0);
      digitalWrite(ledCol[4], 0);
      delay(transition);
      digitalWrite(ledCol[0], 0); digitalWrite(ledRow[2], 1);
      delay(transition);
    }
  }
}

void crossBox () {
  Serial.println(" Cross Box");
  digitalWrite(ledCol[1], 1);
  digitalWrite(ledCol[3], 1);
  digitalWrite(ledCol[4], 1);
  digitalWrite(ledCol[5], 1);
  digitalWrite(ledCol[7], 1);

  for(int j = 0; j < 3; j++) {digitalWrite(ledRow[j], 0); delay(timer);}

  delay(transition);

  for(int j = 0; j < 3; j++) {digitalWrite(ledRow[j], 1); delay(timer);}

  digitalWrite(ledCol[4], 0);

  for(int i = 0; i < 3; i++) {digitalWrite(ledCol[i], 1);}

  digitalWrite(ledCol[3], 1);
  digitalWrite(ledCol[5], 1);

  for(int i = 6; i < 9; i++) {digitalWrite(ledCol[i], 1);}

  for(int j = 0; j < 3; j++) {digitalWrite(ledRow[j], 0); delay(timer);}

  for(int j = 0; j < 3; j++) {digitalWrite(ledRow[j], 1); delay(timer);}
}

void rainDrop () {
  Serial.println(" Rain Drop");
  randRainNumber = random(10, 20);
  if (randNumber == randPrevious) {randNumber = random(10, 20);}

  for(int i = 0; i < randRainNumber; i++) {
    randNumber = random(0, 9);
    if (randNumber == randPrevious) {randNumber = random(0, 9);}

    digitalWrite(ledCol[randNumber], 1);
    digitalWrite(ledRow[2], 0);
    delay(timer);
    digitalWrite(ledRow[1], 0);
    delay(timer);
    digitalWrite(ledRow[2], 1);
    digitalWrite(ledRow[0], 0);
    delay(timer);
    digitalWrite(ledRow[1], 1);
    delay(timer);
    digitalWrite(ledRow[0], 1);
    digitalWrite(ledCol[randNumber], 0);
  }
}

void layer () {
  Serial.println(" Layer");
  randCubeNumber = random(3, 6);
  if (randNumber == randPrevious) {randNumber = random(3, 6);}

  for(int i = 0; i < randCubeNumber; i++) {
    randNumber = random(1, 6);
    if(randNumber == 1) {
      // Front to back
      digitalWrite(ledRow[0], 0);
      digitalWrite(ledRow[1], 0);
      digitalWrite(ledRow[2], 0);
      digitalWrite(ledCol[0], 1);
      digitalWrite(ledCol[1], 1);
      digitalWrite(ledCol[2], 1);
      delay(transition);
      digitalWrite(ledCol[0], 0);
      digitalWrite(ledCol[1], 0);
      digitalWrite(ledCol[2], 0);
      digitalWrite(ledCol[3], 1);
      digitalWrite(ledCol[4], 1);
      digitalWrite(ledCol[5], 1);
      delay(transition);
      digitalWrite(ledCol[3], 0);
      digitalWrite(ledCol[4], 0);
      digitalWrite(ledCol[5], 0);
      digitalWrite(ledCol[6], 1);
      digitalWrite(ledCol[7], 1);
      digitalWrite(ledCol[8], 1);
      delay(transition);
      turnOff();
    }

    if(randNumber == 2) {
      // Back to Front
      digitalWrite(ledRow[0], 0);
      digitalWrite(ledRow[1], 0);
      digitalWrite(ledRow[2], 0);
      digitalWrite(ledCol[6], 1);
      digitalWrite(ledCol[7], 1);
      digitalWrite(ledCol[8], 1);
      delay(transition);
      digitalWrite(ledCol[6], 0);
      digitalWrite(ledCol[7], 0);
      digitalWrite(ledCol[8], 0);
      digitalWrite(ledCol[3], 1);
      digitalWrite(ledCol[4], 1);
      digitalWrite(ledCol[5], 1);
      delay(transition);
      digitalWrite(ledCol[3], 0);
      digitalWrite(ledCol[4], 0);
      digitalWrite(ledCol[5], 0);
      digitalWrite(ledCol[0], 1);
      digitalWrite(ledCol[1], 1);
      digitalWrite(ledCol[2], 1);
      delay(transition);
      turnOff();
    }

    if(randNumber == 3) {
      // Top to Bottom
      digitalWrite(ledCol[0], 1);
      digitalWrite(ledCol[1], 1);
      digitalWrite(ledCol[2], 1);
      digitalWrite(ledCol[3], 1);
      digitalWrite(ledCol[4], 1);
      digitalWrite(ledCol[5], 1);
      digitalWrite(ledCol[6], 1);
      digitalWrite(ledCol[7], 1);
      digitalWrite(ledCol[8], 1);
      digitalWrite(ledRow[2], 0);
      delay(transition);
      digitalWrite(ledRow[1], 0);
      digitalWrite(ledRow[2], 1);
      delay(transition);
      digitalWrite(ledRow[1], 1);
      digitalWrite(ledRow[0], 0);
      delay(transition);
      digitalWrite(ledRow[0], 1);
      turnOffColumns();
    }

    if(randNumber == 4) {
      // Bottom to Top
      digitalWrite(ledCol[0], 1);
      digitalWrite(ledCol[1], 1);
      digitalWrite(ledCol[2], 1);
      digitalWrite(ledCol[3], 1);
      digitalWrite(ledCol[4], 1);
      digitalWrite(ledCol[5], 1);
      digitalWrite(ledCol[6], 1);
      digitalWrite(ledCol[7], 1);
      digitalWrite(ledCol[8], 1);
      digitalWrite(ledRow[0], 0);
      delay(transition);
      digitalWrite(ledRow[1], 0);
      digitalWrite(ledRow[0], 1);
      delay(transition);
      digitalWrite(ledRow[1], 1);
      digitalWrite(ledRow[2], 0);
      delay(transition);
      digitalWrite(ledRow[2], 1);
      turnOffColumns();
    }

    if(randNumber == 5) {
      // Left to Right
      digitalWrite(ledRow[0], 0);
      digitalWrite(ledRow[1], 0);
      digitalWrite(ledRow[2], 0);
      digitalWrite(ledCol[2], 1);
      digitalWrite(ledCol[5], 1);
      digitalWrite(ledCol[8], 1);
      delay(transition);
      digitalWrite(ledCol[2], 0);
      digitalWrite(ledCol[5], 0);
      digitalWrite(ledCol[8], 0);
      digitalWrite(ledCol[1], 1);
      digitalWrite(ledCol[4], 1);
      digitalWrite(ledCol[7], 1);
      delay(transition);
      digitalWrite(ledCol[1], 0);
      digitalWrite(ledCol[4], 0);
      digitalWrite(ledCol[7], 0);
      digitalWrite(ledCol[0], 1);
      digitalWrite(ledCol[3], 1);
      digitalWrite(ledCol[6], 1);
      delay(transition);
      turnOff();
    }

    if(randNumber == 6) {
      // Front to back
      digitalWrite(ledRow[0], 0);
      digitalWrite(ledRow[1], 0);
      digitalWrite(ledRow[2], 0);
      digitalWrite(ledCol[0], 1);
      digitalWrite(ledCol[3], 1);
      digitalWrite(ledCol[6], 1);
      delay(transition);
      digitalWrite(ledCol[0], 0);
      digitalWrite(ledCol[3], 0);
      digitalWrite(ledCol[6], 0);
      digitalWrite(ledCol[1], 1);
      digitalWrite(ledCol[4], 1);
      digitalWrite(ledCol[7], 1);
      delay(transition);
      digitalWrite(ledCol[1], 0);
      digitalWrite(ledCol[4], 0);
      digitalWrite(ledCol[7], 0);
      digitalWrite(ledCol[2], 1);
      digitalWrite(ledCol[5], 1);
      digitalWrite(ledCol[8], 1);
      delay(transition);
      turnOff();
    }
  }
}

void spiral () {
  Serial.println(" Spiral");
  for(int j = 0; j < 3; j++) {
    digitalWrite(ledRow[j], 0);
    for(int i = 0; i < 3; i++) {digitalWrite(ledCol[i], 1); delay(timer);}

    digitalWrite(ledCol[5], 1); delay(timer);

    for(int i = 8; i > 5; i--) {digitalWrite(ledCol[i], 1); delay(timer);}

    digitalWrite(ledCol[3], 1); delay(timer);
    digitalWrite(ledCol[4], 1); delay(timer);

    turnOffColumns();
    digitalWrite(ledRow[j], 1);
  }
}

void octahedron () {
  Serial.println(" Octahedron");
  for(int i = 0; i < 550; i++) {
    digitalWrite(ledCol[4], 1);
    digitalWrite(ledRow[0], 0);

    delay(frequencynum);

    digitalWrite(ledRow[0], 1);
    digitalWrite(ledRow[1], 0);
    digitalWrite(ledCol[4], 0);
    digitalWrite(ledCol[1], 1);
    digitalWrite(ledCol[3], 1);
    digitalWrite(ledCol[5], 1);
    digitalWrite(ledCol[7], 1);

    delay(frequencynum);

    digitalWrite(ledRow[1], 1);
    digitalWrite(ledRow[2], 0);
    digitalWrite(ledCol[1], 0);
    digitalWrite(ledCol[3], 0);
    digitalWrite(ledCol[5], 0);
    digitalWrite(ledCol[7], 0);
    digitalWrite(ledCol[4], 1);

    delay(frequencynum);

    digitalWrite(ledRow[2], 1);
    digitalWrite(ledCol[4], 0);
  }
}

void perimeter () {
  Serial.println(" Perimeter");
  for(int i = 0; i < 300; i++) {
    digitalWrite(ledRow[0], 0);
    for(int i = 0; i < 3; i++) {digitalWrite(ledCol[i], 1);}
    digitalWrite(ledCol[3], 1);
    digitalWrite(ledCol[5], 1);
    for(int i = 6; i < 9; i++) {digitalWrite(ledCol[i], 1);}

    delay(frequencynum);

    digitalWrite(ledRow[0], 1);
    for(int i = 0; i < 3; i++) {digitalWrite(ledCol[i], 0);}
    digitalWrite(ledCol[3], 0);
    digitalWrite(ledCol[5], 0);
    for(int i = 6; i < 9; i++) {digitalWrite(ledCol[i], 0);}

    digitalWrite(ledCol[0], 1);
    digitalWrite(ledCol[2], 1);
    digitalWrite(ledCol[6], 1);
    digitalWrite(ledCol[8], 1);
    digitalWrite(ledRow[1], 0);

    delay(frequencynum);

    digitalWrite(ledCol[0], 0);
    digitalWrite(ledCol[2], 0);
    digitalWrite(ledCol[6], 0);
    digitalWrite(ledCol[8], 0);
    digitalWrite(ledRow[1], 1);

    digitalWrite(ledRow[2], 0);
    for(int i = 0; i < 3; i++) {digitalWrite(ledCol[i], 1);}
    digitalWrite(ledCol[3], 1);
    digitalWrite(ledCol[5], 1);
    for(int i = 6; i < 9; i++) {digitalWrite(ledCol[i], 1);}

    delay(frequencynum);

    digitalWrite(ledRow[2], 1);
    for(int i = 0; i < 3; i++) {digitalWrite(ledCol[i], 0);}
    digitalWrite(ledCol[3], 0);
    digitalWrite(ledCol[5], 0);
    for(int i = 6; i < 9; i++) {digitalWrite(ledCol[i], 0);}
  }
}

void diagonal () {
  Serial.println(" Diagonal");
  randCubeNumber = random(3, 6);
  for(int i = 0; i < randCubeNumber; i++) {
    randNumber = random(1, 9);
    if (randNumber == randPrevious) {randNumber = random(3, 6);}
    // Front Bottom Right to Back Top Left
    if (randNumber == 1) {
      digitalWrite(ledCol[0], 1);
      digitalWrite(ledRow[0], 0);
      delay(transition);
      digitalWrite(ledCol[0], 0);
      digitalWrite(ledRow[0], 1);
      digitalWrite(ledCol[4], 1);
      digitalWrite(ledRow[1], 0);
      delay(transition);
      digitalWrite(ledCol[4], 0);
      digitalWrite(ledRow[1], 1);
      digitalWrite(ledCol[8], 1);
      digitalWrite(ledRow[2], 0);
      delay(transition);
      digitalWrite(ledCol[8], 0);
      digitalWrite(ledRow[2], 1);
    }
    // Front Bottom Left to Back Top Right
    if (randNumber == 2) {
      digitalWrite(ledCol[2], 1);
      digitalWrite(ledRow[0], 0);
      delay(transition);
      digitalWrite(ledCol[2], 0);
      digitalWrite(ledRow[0], 1);
      digitalWrite(ledCol[4], 1);
      digitalWrite(ledRow[1], 0);
      delay(transition);
      digitalWrite(ledCol[4], 0);
      digitalWrite(ledRow[1], 1);
      digitalWrite(ledCol[6], 1);
      digitalWrite(ledRow[2], 0);
      delay(transition);
      digitalWrite(ledCol[6], 0);
      digitalWrite(ledRow[2], 1);
    }
    // Back Bottom Right to Front Top Left
    if (randNumber == 3) {
      digitalWrite(ledCol[6], 1);
      digitalWrite(ledRow[0], 0);
      delay(transition);
      digitalWrite(ledCol[6], 0);
      digitalWrite(ledRow[0], 1);
      digitalWrite(ledCol[4], 1);
      digitalWrite(ledRow[1], 0);
      delay(transition);
      digitalWrite(ledCol[4], 0);
      digitalWrite(ledRow[1], 1);
      digitalWrite(ledCol[2], 1);
      digitalWrite(ledRow[2], 0);
      delay(transition);
      digitalWrite(ledCol[2], 0);
      digitalWrite(ledRow[2], 1);
    }
    // Back Bottom Left to Front Top Right
    if (randNumber == 4) {
      digitalWrite(ledCol[8], 1);
      digitalWrite(ledRow[0], 0);
      delay(transition);
      digitalWrite(ledCol[8], 0);
      digitalWrite(ledRow[0], 1);
      digitalWrite(ledCol[4], 1);
      digitalWrite(ledRow[1], 0);
      delay(transition);
      digitalWrite(ledCol[4], 0);
      digitalWrite(ledRow[1], 1);
      digitalWrite(ledCol[0], 1);
      digitalWrite(ledRow[2], 0);
      delay(transition);
      digitalWrite(ledCol[0], 0);
      digitalWrite(ledRow[2], 1);
    }
    // Front Top Right to Back Bottom Left
    if (randNumber == 5) {
      digitalWrite(ledCol[0], 1);
      digitalWrite(ledRow[2], 0);
      delay(transition);
      digitalWrite(ledCol[0], 0);
      digitalWrite(ledRow[2], 1);
      digitalWrite(ledCol[4], 1);
      digitalWrite(ledRow[1], 0);
      delay(transition);
      digitalWrite(ledCol[4], 0);
      digitalWrite(ledRow[1], 1);
      digitalWrite(ledCol[8], 1);
      digitalWrite(ledRow[0], 0);
      delay(transition);
      digitalWrite(ledCol[8], 0);
      digitalWrite(ledRow[0], 1);
    }
    // Front Top Left to Back Bottom Right
    if (randNumber == 6) {
      digitalWrite(ledCol[2], 1);
      digitalWrite(ledRow[2], 0);
      delay(transition);
      digitalWrite(ledCol[2], 0);
      digitalWrite(ledRow[2], 1);
      digitalWrite(ledCol[4], 1);
      digitalWrite(ledRow[1], 0);
      delay(transition);
      digitalWrite(ledCol[4], 0);
      digitalWrite(ledRow[1], 1);
      digitalWrite(ledCol[6], 1);
      digitalWrite(ledRow[0], 0);
      delay(transition);
      digitalWrite(ledCol[6], 0);
      digitalWrite(ledRow[0], 1);
    }
    // Back Top Right to Front Bottom Left
    if (randNumber == 7) {
      digitalWrite(ledCol[6], 1);
      digitalWrite(ledRow[2], 0);
      delay(transition);
      digitalWrite(ledCol[6], 0);
      digitalWrite(ledRow[2], 1);
      digitalWrite(ledCol[4], 1);
      digitalWrite(ledRow[1], 0);
      delay(transition);
      digitalWrite(ledCol[4], 0);
      digitalWrite(ledRow[1], 1);
      digitalWrite(ledCol[2], 1);
      digitalWrite(ledRow[0], 0);
      delay(transition);
      digitalWrite(ledCol[2], 0);
      digitalWrite(ledRow[0], 1);
    }
    // Back Top Left to Front Bottom Right
    if (randNumber == 8) {
      digitalWrite(ledCol[8], 1);
      digitalWrite(ledRow[2], 0);
      delay(transition);
      digitalWrite(ledCol[8], 0);
      digitalWrite(ledRow[2], 1);
      digitalWrite(ledCol[4], 1);
      digitalWrite(ledRow[1], 0);
      delay(transition);
      digitalWrite(ledCol[4], 0);
      digitalWrite(ledRow[1], 1);
      digitalWrite(ledCol[0], 1);
      digitalWrite(ledRow[0], 0);
      delay(transition);
      digitalWrite(ledCol[0], 0);
      digitalWrite(ledRow[0], 1);
    }
  }
}

void flash () {
  for (int i = 0; i < 7; i++) {
    turnOn(); delay(250);
    turnOff(); delay(timer);
  }
}

void loop() {
  // Random Selection Algorithm
  // Print a random number from 1 to 10
  randNumber = random(1, 11);
  if (randNumber == randPrevious) {randNumber = random(1, 10);}

  Serial.print(randNumber);
  if(randNumber == 1) {trail();}
  else if(randNumber == 2) {expandingCube();}
  else if(randNumber == 3) {layer();}
  else if(randNumber == 4) {rainDrop();}
  else if(randNumber == 5) {crossBox();}
  else if(randNumber == 6) {spiral();}
  else if(randNumber == 7) {octahedron();}
  else if(randNumber == 8) {perimeter();}
  else if(randNumber == 9) {diagonal();}
  else if(randNumber == 10) {flash;}
  //else if(randNumber == 11) {;}
  //else if(randNumber == 12) {;}
  //else if(randNumber == 13) {;}
  //else if(randNumber == 14) {;}
  //else if(randNumber == 15) {;}
  //else if(randNumber == 16) {;}
  delay(timer);
  turnOff();
}
