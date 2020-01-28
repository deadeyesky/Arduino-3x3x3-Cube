#include <Arduino.h>
//#include "sequences.h"

int speed = 1;
int rate = 1;

long randNumber;
long randPrevious;
long randCubeNumber;
long randRainNumber;

static const uint8_t ledRow[] = {A1, A2, A3};
static const uint8_t ledCol[] = {2, 3, 4, 5, 6, 7, 8, 9, 11};

#define time1 100
#define time2 250
#define transition 400
#define tree_time 1000
#define frequencynum 1

void setup () {
  // Initialize the serial monitor in case of diagnostics
  Serial.begin(9600);
  // This for loop defines the column pins, in which there are 9 of them in this case
  for(int i = 0; i < 9; i++) {pinMode(ledCol[i], OUTPUT);}
  for(int j = 0; j < 3; j++) {pinMode(ledRow[j], OUTPUT);}
  // Define the pin by which the random number's seed is obtained from. It uses the noise picked up by the pin to generate a random number
  randomSeed(analogRead(0));
  delay(transition);
}

void turnOn () {
  for(int i = 8; i >= 0; i--) {digitalWrite(ledCol[i], 1);}
  for(int j = 2; j >= 0; j--) {digitalWrite(ledRow[j], 0);}
}

void turnOnColumns () {for(int i = 8; i >= 0; i--) {digitalWrite(ledCol[i], 1);}}
void turnOnRows () {for(int j = 2; j >= 0; j--) {digitalWrite(ledRow[j], 0);}}
void turnOnCenter () {digitalWrite(ledCol[4], 1); digitalWrite(ledRow[1], 0);}
void turnOff () {
  for(int i = 8; i >= 0; i--) {digitalWrite(ledCol[i], 0);}
  for(int j = 2; j >= 0; j--) {digitalWrite(ledRow[j], 1);}
}
void turnOffColumns () {for(int i = 8; i >= 0; i--) {digitalWrite(ledCol[i], 0);}}
void turnOffRows () {for(int j = 2; j >= 0; j--) {digitalWrite(ledRow[j], 1);}}
void turnOffCenter () {digitalWrite(ledCol[4], 0); digitalWrite(ledRow[1], 1);}
void singleLedTest () {digitalWrite(ledRow[1], 0); digitalWrite(ledCol[2], 1);}

double randomFunction (double first_number, double last_number) {
  randNumber = random(first_number, last_number);
  if (randNumber == randPrevious) {randNumber = random(first_number, last_number);}
  randPrevious = randNumber;
  return randNumber;
}

void trail () {
  Serial.println(" Trail");
  digitalWrite(ledCol[0], 1); digitalWrite(ledRow[0], 0);
  delay(time1);
  digitalWrite(ledCol[0], 0);
  digitalWrite(ledCol[1], 1);
  delay(time1);
  digitalWrite(ledCol[1], 0);
  digitalWrite(ledCol[2], 1);
  delay(time1);
  digitalWrite(ledCol[2], 0);
  digitalWrite(ledCol[5], 1);
  delay(time1);
  digitalWrite(ledCol[5], 0);
  digitalWrite(ledCol[8], 1);
  delay(time1);
  digitalWrite(ledCol[8], 0);
  digitalWrite(ledCol[7], 1);
  delay(time1);
  digitalWrite(ledCol[7], 0);
  digitalWrite(ledCol[6], 1);
  delay(time1);
  digitalWrite(ledRow[0], 1);
  digitalWrite(ledRow[1], 0);
  delay(time1);
  digitalWrite(ledRow[1], 1);
  digitalWrite(ledRow[2], 0);
  delay(time1);
  digitalWrite(ledCol[6], 0);
  digitalWrite(ledCol[7], 1);
  delay(time1);
  digitalWrite(ledCol[7], 0);
  digitalWrite(ledCol[8], 1);
  delay(time1);
  digitalWrite(ledCol[8], 0);
  digitalWrite(ledCol[5], 1);
  delay(time1);
  digitalWrite(ledCol[5], 0);
  digitalWrite(ledCol[2], 1);
  delay(time1);
  digitalWrite(ledCol[2], 0);
  digitalWrite(ledCol[1], 1);
  delay(time1);
  digitalWrite(ledCol[1], 0);
  digitalWrite(ledCol[0], 1);
  delay(time1);
  digitalWrite(ledRow[2], 1);
  digitalWrite(ledRow[1], 0);
  delay(time1);
  digitalWrite(ledRow[1], 1);
  digitalWrite(ledRow[0], 0);
  delay(time1);
  digitalWrite(ledCol[0], 0);
  digitalWrite(ledCol[3], 1);
  delay(time1);
  digitalWrite(ledCol[3], 0);
  digitalWrite(ledCol[6], 1);
  delay(time1);
  digitalWrite(ledRow[0], 1);
  digitalWrite(ledRow[1], 0);
  delay(time1);
  digitalWrite(ledRow[1], 1);
  digitalWrite(ledRow[2], 0);
  delay(time1);
  digitalWrite(ledCol[6], 0);
  digitalWrite(ledCol[7], 1);
  delay(time1);
  digitalWrite(ledCol[7], 0);
  digitalWrite(ledCol[8], 1);
  delay(time1);
  turnOff();
  delay(transition);
}

void expandingCube () {
  Serial.println(" Expanding Cube");
  // Generates random number to choose which corner to start from.
  randCubeNumber = random(3, 5);
  for(int i = randCubeNumber; i >= 0; i--) {
    randomFunction(1, 9);

    // Starting from the bottom of the first column
    if(randNumber == 1) {
      digitalWrite(ledCol[0], 1); digitalWrite(ledRow[0], 0);
      delay(transition);

      digitalWrite(ledRow[1], 0); digitalWrite(ledCol[1], 1);
      for (int i = 4; i >= 3; i--) {digitalWrite(ledCol[i], 1);}
      delay(transition);

      turnOn();
      delay(transition);

      digitalWrite(ledRow[0], 1); digitalWrite(ledCol[6], 0);
      for (int i = 3; i >= 0; i--) {digitalWrite(ledCol[i], 0);}
      delay(transition);

      digitalWrite(ledRow[1], 1); digitalWrite(ledCol[7], 0);
      for (int i = 5; i >= 4; i--) {digitalWrite(ledCol[i], 0);}
      delay(transition); turnOff();
    }

    // Starting from the bottom of the third column
    else if(randNumber == 2) {
      digitalWrite(ledCol[2], 1); digitalWrite(ledRow[0], 0);
      delay(transition);

      digitalWrite(ledRow[1], 0); digitalWrite(ledCol[1], 1);
      for (int i = 5; i >= 4; i--) {digitalWrite(ledCol[i], 1);}
      delay(transition);

      turnOn();
      delay(transition);

      digitalWrite(ledRow[0], 1);
      for (int i = 1; i >= 0; i--) {digitalWrite(ledCol[i], 0);}
      for (int i = 8; i >= 2; i-=3) {digitalWrite(ledCol[i], 0);}
      delay(transition);

      digitalWrite(ledRow[1], 1); digitalWrite(ledCol[7], 0);
      for (int i = 4; i >= 3; i--) {digitalWrite(ledCol[i], 0);}
      delay(transition); turnOff();
    }

    // Starting from the bottom of the seventh column
    else if(randNumber == 3) {
      digitalWrite(ledCol[6], 1); digitalWrite(ledRow[0], 0);
      delay(transition);

      digitalWrite(ledRow[1], 0); digitalWrite(ledCol[7], 1);
      for (int i = 4; i >= 3; i--) {digitalWrite(ledCol[i], 1);}
      delay(transition);

      turnOn();
      delay(transition);

      digitalWrite(ledRow[0], 1);
      for (int i = 3; i >= 0; i-=3) {digitalWrite(ledCol[i], 0);}
      for (int i = 8; i >= 6; i--) {digitalWrite(ledCol[i], 0);}
      delay(transition);

      digitalWrite(ledRow[1], 1); digitalWrite(ledCol[1], 0);
      for (int i = 5; i >= 4; i--) {digitalWrite(ledCol[i], 0);}
      delay(transition); turnOff();
    }

    // Starting from the bottom of the ninth column
    else if(randNumber == 4) {
      digitalWrite(ledCol[8], 1); digitalWrite(ledRow[0], 0);
      delay(transition);
      digitalWrite(ledRow[1], 0); digitalWrite(ledCol[7], 1);
      for (int i = 5; i >= 4; i--) {digitalWrite(ledCol[i], 1);}
      delay(transition);

      turnOn();
      delay(transition);

      digitalWrite(ledRow[0], 1); digitalWrite(ledCol[2], 0);
      for (int i = 8; i >= 5; i--) {digitalWrite(ledCol[i], 0);}
      delay(transition);

      digitalWrite(ledRow[1], 1); digitalWrite(ledCol[1], 0);
      for (int i = 4; i >= 3; i--) {digitalWrite(ledCol[i], 0);}
      delay(transition); turnOff();
    }

    // Starting from the top of the first column
    else if(randNumber == 5) {
      digitalWrite(ledCol[0], 1); digitalWrite(ledRow[2], 0);
      delay(transition);

      digitalWrite(ledRow[1], 0); digitalWrite(ledCol[1], 1);
      for (int i = 4; i >= 3; i--) {digitalWrite(ledCol[i], 1);}
      delay(transition);

      turnOn();
      delay(transition);

      digitalWrite(ledRow[2], 1); digitalWrite(ledCol[6], 0);
      for (int i = 3; i >= 0; i--) {digitalWrite(ledCol[i], 0);}
      delay(transition);

      digitalWrite(ledRow[1], 1); digitalWrite(ledCol[7], 0);
      for (int i = 5; i >= 4; i--) {digitalWrite(ledCol[i], 0);}
      delay(transition); turnOff();
    }

    // Starting from the top of the third column
    else if(randNumber == 6) {
      digitalWrite(ledCol[2], 1); digitalWrite(ledRow[2], 0);
      delay(transition);

      digitalWrite(ledRow[1], 0); digitalWrite(ledCol[1], 1);
      for (int i = 5; i >= 4; i--) {digitalWrite(ledCol[i], 1);}
      delay(transition);

      turnOn();
      delay(transition);

      digitalWrite(ledRow[2], 1);
      for (int i = 2; i >= 0; i--) {digitalWrite(ledCol[i], 0);}
      for (int i = 8; i >= 5; i-=3) {digitalWrite(ledCol[i], 0);}
      delay(transition);

      digitalWrite(ledRow[1], 1); digitalWrite(ledCol[7], 0);
      for (int i = 4; i >= 3; i--) {digitalWrite(ledCol[i], 0);}
      delay(transition); turnOff();
    }

    // Starting from the top of the seventh column
    else if(randNumber == 7) {
      digitalWrite(ledCol[6], 1); digitalWrite(ledRow[2], 0);
      delay(transition);

      digitalWrite(ledRow[1], 0); digitalWrite(ledCol[7], 1);
      for (int i = 4; i >= 3; i--) {digitalWrite(ledCol[i], 1);}
      delay(transition);

      turnOn();
      delay(transition);

      digitalWrite(ledRow[2], 1);
      for (int i = 3; i >= 0; i-=3) {digitalWrite(ledCol[i], 0);}
      for (int i = 8; i >= 6; i--) {digitalWrite(ledCol[i], 0);}
      delay(transition);

      digitalWrite(ledRow[1], 1); digitalWrite(ledCol[1], 0);
      for (int i = 5; i >= 4; i--) {digitalWrite(ledCol[i], 0);}
      delay(transition); turnOff();
    }

    // Starting from the
    else if(randNumber == 8) {
      digitalWrite(ledCol[8], 1); digitalWrite(ledRow[0], 0);
      delay(transition);

      digitalWrite(ledRow[1], 0); digitalWrite(ledCol[7], 1);
      for (int i = 5; i >= 4; i--) {digitalWrite(ledCol[i], 1);}
      delay(transition);

      turnOn();
      delay(transition);

      digitalWrite(ledRow[0], 1); digitalWrite(ledCol[2], 0);
      for (int i = 8; i >= 5; i--) {digitalWrite(ledCol[i], 0);}
      delay(transition);

      digitalWrite(ledRow[1], 1); digitalWrite(ledCol[1], 0);
      for (int i = 4; i >= 3; i--) {digitalWrite(ledCol[i], 0);}
      delay(transition); turnOff();
    }
    delay(transition);
  }
}

void crossBox () {
  Serial.println(" Cross Box");
  digitalWrite(ledCol[4], 1);
  for (int i = 7; i >= 1; i-=2) {digitalWrite(ledCol[i], 1);}

  for(int j = 0; j < 3; j++) {digitalWrite(ledRow[j], 0); delay(time1);}
  delay(transition);

  for(int j = 0; j < 3; j++) {digitalWrite(ledRow[j], 1); delay(time1);}
  digitalWrite(ledCol[4], 0);

  turnOnColumns();
  digitalWrite(ledCol[4], 0);

  for(int j = 0; j < 3; j++) {digitalWrite(ledRow[j], 0); delay(time1);}

  for(int j = 0; j < 3; j++) {digitalWrite(ledRow[j], 1); delay(time1);}
}

void rainDrop () {
  Serial.println(" Rain Drop");
  randRainNumber = random(10, 16);

  // Begins the random column assortment
  for(int i = randRainNumber; i >= 0; i--) {
    randomFunction(0, 9);

    digitalWrite(ledCol[randNumber], 1);
    digitalWrite(ledRow[2], 0);
    delay(time1);
    digitalWrite(ledRow[1], 0);
    delay(time1);
    digitalWrite(ledRow[2], 1);
    digitalWrite(ledRow[0], 0);
    delay(time1);
    digitalWrite(ledRow[1], 1);
    delay(time1);
    digitalWrite(ledRow[0], 1);
    digitalWrite(ledCol[randNumber], 0);
  }
}

void layer () {
  Serial.println(" Layer");

  randCubeNumber = random(3, 5);

  for(int i = randCubeNumber; i >= 0; i--) {
    randomFunction(1, 6);
    if(randNumber == 1) {
      // Front to back
      turnOnRows();
      for (int i = 2; i >= 0; i--) {digitalWrite(ledCol[i], 1);}
      delay(transition);
      for (int i = 2; i >= 0; i--) {digitalWrite(ledCol[i], 0);}
      for (int i = 5; i >= 3; i--) {digitalWrite(ledCol[i], 1);}
      delay(transition);
      for (int i = 5; i >= 3; i--) {digitalWrite(ledCol[i], 0);}
      for (int i = 8; i >= 6; i--) {digitalWrite(ledCol[i], 1);}
      delay(transition);
      turnOff();
    }

    if(randNumber == 2) {
      // Back to Front
      turnOnRows();
      for (int i = 8; i >= 6; i--) {digitalWrite(ledCol[i], 1);}
      delay(transition);
      for (int i = 8; i >= 6; i--) {digitalWrite(ledCol[i], 0);}
      for (int i = 5; i >= 3; i--) {digitalWrite(ledCol[i], 1);}
      delay(transition);
      for (int i = 5; i >= 3; i--) {digitalWrite(ledCol[i], 0);}
      for (int i = 2; i >= 0; i--) {digitalWrite(ledCol[i], 1);}
      delay(transition);
      turnOff();
    }

    if(randNumber == 3) {
      // Top to Bottom
      turnOnColumns();
      digitalWrite(ledRow[2], 0);
      delay(transition);
      digitalWrite(ledRow[2], 1);
      digitalWrite(ledRow[1], 0);
      delay(transition);
      digitalWrite(ledRow[1], 1);
      digitalWrite(ledRow[0], 0);
      delay(transition);
      turnOff();
    }

    if(randNumber == 4) {
      // Bottom to Top
      turnOnColumns();
      digitalWrite(ledRow[0], 0);
      delay(transition);
      digitalWrite(ledRow[1], 0);
      digitalWrite(ledRow[0], 1);
      delay(transition);
      digitalWrite(ledRow[1], 1);
      digitalWrite(ledRow[2], 0);
      delay(transition);
      turnOff();
    }

    if(randNumber == 5) {
      // Left to Right
      turnOnRows();
      for (int i = 8; i >= 2; i-=3) {digitalWrite(ledCol[i], 1);}
      delay(transition);
      for (int i = 8; i >= 2; i-=3) {digitalWrite(ledCol[i], 0);}
      for (int i = 7; i >= 1; i-=3) {digitalWrite(ledCol[i], 1);}
      delay(transition);
      for (int i = 7; i >= 1; i-=3) {digitalWrite(ledCol[i], 0);}
      for (int i = 6; i >= 0; i-=3) {digitalWrite(ledCol[i], 1);}
      delay(transition);
      turnOff();
    }

    if(randNumber == 6) {
      // Front to back
      turnOnRows();
      for (int i = 6; i >= 0; i-=3) {digitalWrite(ledCol[i], 1);}
      delay(transition);
      for (int i = 6; i >= 0; i-=3) {digitalWrite(ledCol[i], 0);}
      for (int i = 7; i >= 1; i-=3) {digitalWrite(ledCol[i], 1);}
      delay(transition);
      for (int i = 7; i >= 1; i-=3) {digitalWrite(ledCol[i], 0);}
      for (int i = 8; i >= 2; i-=3) {digitalWrite(ledCol[i], 1);}
      delay(transition);
      turnOff();
    }
    delay(transition);
  }
}

void spiral () {
  Serial.println(" Spiral");
  for(int j = 0; j < 3; j++) {
    digitalWrite(ledRow[j], 0);
    for(int i = 0; i < 3; i++) {digitalWrite(ledCol[i], 1); delay(time1);}

    digitalWrite(ledCol[5], 1); delay(time1);

    for(int i = 8; i > 5; i--) {digitalWrite(ledCol[i], 1); delay(time1);}

    digitalWrite(ledCol[3], 1); delay(time1);
    digitalWrite(ledCol[4], 1); delay(time1);

    turnOffColumns();
    digitalWrite(ledRow[j], 1);
  }
}

void pulsingOctahedron () {
  Serial.println(" Octahedron");
  for(int i = 50; i >= 0; i--) {
    digitalWrite(ledCol[4], 1);
    digitalWrite(ledRow[0], 0);
    delay(50);

    digitalWrite(ledRow[0], 1);
    digitalWrite(ledCol[4], 0);
    digitalWrite(ledRow[1], 0);
    for (int i = 7; i >= 1; i-=2) {digitalWrite(ledCol[i], 1);}

    delay(50);

    digitalWrite(ledRow[1], 1);
    digitalWrite(ledRow[2], 0);
    for (int i = 7; i >= 1; i-=2) {digitalWrite(ledCol[i], 0);}
    digitalWrite(ledCol[4], 1);

    delay(50);

    digitalWrite(ledRow[2], 1);
    digitalWrite(ledCol[4], 0);
  }
}

void perimeter () {
  Serial.println(" Perimeter");
  for(int i = 400; i >= 0; i--) {
    digitalWrite(ledRow[0], 0);
    turnOnColumns(); digitalWrite(ledCol[4], 0);
    delay(frequencynum);

    turnOffColumns();
    turnOffRows();
    for(int i = 8; i >= 0; i-=2) {digitalWrite(ledCol[i], 1);}
    digitalWrite(ledCol[4], 0);
    digitalWrite(ledRow[1], 0);
    delay(frequencynum);

    turnOffColumns();
    turnOffRows();
    digitalWrite(ledRow[2], 0);
    turnOnColumns(); digitalWrite(ledCol[4], 0);
    delay(frequencynum);

    turnOff();
  }
}

void diagonal () {
  Serial.println(" Diagonal");
  randCubeNumber = random(3, 6);
  for(int i = randCubeNumber; i >= 0; i--) {
    randomFunction(1, 9);
    // Front Bottom Right to Back Top Left
    if (randNumber == 1) {
      digitalWrite(ledCol[0], 1);
      digitalWrite(ledRow[0], 0);
      delay(time2);
      digitalWrite(ledCol[0], 0);
      digitalWrite(ledRow[0], 1);
      digitalWrite(ledCol[4], 1);
      digitalWrite(ledRow[1], 0);
      delay(time2);
      digitalWrite(ledCol[4], 0);
      digitalWrite(ledRow[1], 1);
      digitalWrite(ledCol[8], 1);
      digitalWrite(ledRow[2], 0);
      delay(time2);
      digitalWrite(ledCol[8], 0);
      digitalWrite(ledRow[2], 1);
    }
    // Front Bottom Left to Back Top Right
    if (randNumber == 2) {
      digitalWrite(ledCol[2], 1);
      digitalWrite(ledRow[0], 0);
      delay(time2);
      digitalWrite(ledCol[2], 0);
      digitalWrite(ledRow[0], 1);
      digitalWrite(ledCol[4], 1);
      digitalWrite(ledRow[1], 0);
      delay(time2);
      digitalWrite(ledCol[4], 0);
      digitalWrite(ledRow[1], 1);
      digitalWrite(ledCol[6], 1);
      digitalWrite(ledRow[2], 0);
      delay(time2);
      digitalWrite(ledCol[6], 0);
      digitalWrite(ledRow[2], 1);
    }
    // Back Bottom Right to Front Top Left
    if (randNumber == 3) {
      digitalWrite(ledCol[6], 1);
      digitalWrite(ledRow[0], 0);
      delay(time2);
      digitalWrite(ledCol[6], 0);
      digitalWrite(ledRow[0], 1);
      digitalWrite(ledCol[4], 1);
      digitalWrite(ledRow[1], 0);
      delay(time2);
      digitalWrite(ledCol[4], 0);
      digitalWrite(ledRow[1], 1);
      digitalWrite(ledCol[2], 1);
      digitalWrite(ledRow[2], 0);
      delay(time2);
      digitalWrite(ledCol[2], 0);
      digitalWrite(ledRow[2], 1);
    }
    // Back Bottom Left to Front Top Right
    if (randNumber == 4) {
      digitalWrite(ledCol[8], 1);
      digitalWrite(ledRow[0], 0);
      delay(time2);
      digitalWrite(ledCol[8], 0);
      digitalWrite(ledRow[0], 1);
      digitalWrite(ledCol[4], 1);
      digitalWrite(ledRow[1], 0);
      delay(time2);
      digitalWrite(ledCol[4], 0);
      digitalWrite(ledRow[1], 1);
      digitalWrite(ledCol[0], 1);
      digitalWrite(ledRow[2], 0);
      delay(time2);
      digitalWrite(ledCol[0], 0);
      digitalWrite(ledRow[2], 1);
    }
    // Front Top Right to Back Bottom Left
    if (randNumber == 5) {
      digitalWrite(ledCol[0], 1);
      digitalWrite(ledRow[2], 0);
      delay(time2);
      digitalWrite(ledCol[0], 0);
      digitalWrite(ledRow[2], 1);
      digitalWrite(ledCol[4], 1);
      digitalWrite(ledRow[1], 0);
      delay(time2);
      digitalWrite(ledCol[4], 0);
      digitalWrite(ledRow[1], 1);
      digitalWrite(ledCol[8], 1);
      digitalWrite(ledRow[0], 0);
      delay(time2);
      digitalWrite(ledCol[8], 0);
      digitalWrite(ledRow[0], 1);
    }
    // Front Top Left to Back Bottom Right
    if (randNumber == 6) {
      digitalWrite(ledCol[2], 1);
      digitalWrite(ledRow[2], 0);
      delay(time2);
      digitalWrite(ledCol[2], 0);
      digitalWrite(ledRow[2], 1);
      digitalWrite(ledCol[4], 1);
      digitalWrite(ledRow[1], 0);
      delay(time2);
      digitalWrite(ledCol[4], 0);
      digitalWrite(ledRow[1], 1);
      digitalWrite(ledCol[6], 1);
      digitalWrite(ledRow[0], 0);
      delay(time2);
      digitalWrite(ledCol[6], 0);
      digitalWrite(ledRow[0], 1);
    }
    // Back Top Right to Front Bottom Left
    if (randNumber == 7) {
      digitalWrite(ledCol[6], 1);
      digitalWrite(ledRow[2], 0);
      delay(time2);
      digitalWrite(ledCol[6], 0);
      digitalWrite(ledRow[2], 1);
      digitalWrite(ledCol[4], 1);
      digitalWrite(ledRow[1], 0);
      delay(time2);
      digitalWrite(ledCol[4], 0);
      digitalWrite(ledRow[1], 1);
      digitalWrite(ledCol[2], 1);
      digitalWrite(ledRow[0], 0);
      delay(time2);
      digitalWrite(ledCol[2], 0);
      digitalWrite(ledRow[0], 1);
    }
    // Back Top Left to Front Bottom Right
    if (randNumber == 8) {
      digitalWrite(ledCol[8], 1);
      digitalWrite(ledRow[2], 0);
      delay(time2);
      digitalWrite(ledCol[8], 0);
      digitalWrite(ledRow[2], 1);
      digitalWrite(ledCol[4], 1);
      digitalWrite(ledRow[1], 0);
      delay(time2);
      digitalWrite(ledCol[4], 0);
      digitalWrite(ledRow[1], 1);
      digitalWrite(ledCol[0], 1);
      digitalWrite(ledRow[0], 0);
      delay(time2);
      digitalWrite(ledCol[0], 0);
      digitalWrite(ledRow[0], 1);
    }
  }
  delay(transition);
}

void flash () {
  Serial.println(" Flash");
  // All LEDs flash 7 times after 400 milliseconds
  for (int i = 7; i >= 0; i--) {
    turnOn(); delay(time2);
    turnOff(); delay(time2);
  }
}

void tree () {
  Serial.println(" Tree");
  // First frame
  digitalWrite(ledRow[0], 0); digitalWrite(ledCol[4], 1);
  delay(tree_time); turnOff();

  // Second frame
  for (int i = 1; i >= 0; i--) {digitalWrite(ledRow[i], 0);}
  digitalWrite(ledCol[4], 1);
  delay(tree_time); turnOff();

  // Third Frame
  for (int j = 333; j >= 0; j--) {
    digitalWrite(ledRow[0], 0);
    digitalWrite(ledCol[4], 1);
    delay(frequencynum);

    digitalWrite(ledRow[0], 1);
    digitalWrite(ledRow[1], 0);
    for (int i = 7; i >= 0; i-=2) {digitalWrite(ledCol[i], 1);}
    delay(frequencynum);

    digitalWrite(ledRow[1], 1);
    digitalWrite(ledRow[2], 0);
    for (int i = 7; i >= 0; i-=2) {digitalWrite(ledCol[i], 0);}
    delay(frequencynum); turnOff();
  }

  // Fourth frame
  for (int k = 450; k >= 0; k--) {
    turnOffRows();
    digitalWrite(ledRow[0], 0);
    digitalWrite(ledCol[4], 1);
    delay(frequencynum);

    digitalWrite(ledRow[0], 1);
    digitalWrite(ledRow[1], 0);
    for (int i = 8; i >= 0; i--) {digitalWrite(ledCol[i], 1);}
    delay(frequencynum);

    digitalWrite(ledRow[1], 1);
    digitalWrite(ledRow[2], 0);
    delay(frequencynum);
    turnOff();
  }
}

void randomDot () {
  Serial.println(" Random Dot");
  // Repeat this operation 30 times
  for (int i = 30; i >= 0; i--) {
    randomFunction(0, 9);

    digitalWrite(ledCol[randNumber], 1);
    // For this next step we are repuposing randCubeNumber to give us a random number between 0 and 2 for the random assignment of the rows:
    randCubeNumber = random(0, 3);
    digitalWrite(ledRow[randCubeNumber], 0);
    delay(time1);

    digitalWrite(ledCol[randNumber], 0);
    digitalWrite(ledRow[randCubeNumber], 1);
 }
}

void slant () {
  Serial.println(" Diagonal");
  randCubeNumber = random(3, 6);
  for(int i = randCubeNumber; i >= 0; i--) {
    randomFunction(1, 5);
    // Front Bottom Right to Back Top Left
    if (randNumber == 1) {
      for (int i = 0; i <= 2; i++) {
        digitalWrite(ledCol[i + 4], 1);
        digitalWrite(ledRow[i], 0);
        delay(time1);
      }
      for (int i = 0; i <= 2; i++) {
        digitalWrite(ledCol[i + 4], 0);
        digitalWrite(ledRow[i], 1);
        delay(time1);
      }
    }

    if (randNumber == 2) {
      for (int i = 2; i >= 0; i--) {
        digitalWrite(ledCol[i - 4], 1);
        digitalWrite(ledRow[i], 0);
        delay(time1);
      }
      for (int i = 2; i >= 0; i--) {
        digitalWrite(ledCol[i * 4], 0);
        digitalWrite(ledRow[i], 1);
        delay(time1);
      }
    }

    if (randNumber == 3) {
      for (int i = 0; i <= 2; i++) {
        digitalWrite(ledCol[i * 4], 1);
        digitalWrite(ledRow[i], 0);
        delay(time1);
      }
      for (int i = 0; i <= 2; i++) {
        digitalWrite(ledCol[i * 4], 0);
        digitalWrite(ledRow[i], 1);
        delay(time1);
      }
    }

    if (randNumber == 4) {
      for (int i = 2; i >= 0; i--) {
        digitalWrite(ledCol[(i) * 4], 1);
        digitalWrite(ledRow[i], 0);
        delay(time1);
      }
      for (int i = 2; i >= 0; i--) {
        digitalWrite(ledCol[i * 4], 0);
        digitalWrite(ledRow[i], 1);
        delay(time1);
      }
    }
  }
}

void hourglass () {
  Serial.println(" Hourglass");
  turnOnColumns(); digitalWrite(ledRow[2], 0);
  delay(tree_time); turnOff();

  for (int i = 350; i >= 0; i--) {
    turnOnCenter();
    delay(frequencynum);
    turnOffCenter();
    turnOnColumns();
    digitalWrite(ledRow[2], 0);
    delay(frequencynum);
    turnOff();
  }

  for (int i = 400; i >= 0; i--) {
    turnOnColumns();
    digitalWrite(ledRow[0], 0);
    delay(frequencynum);
    turnOff();
    turnOnCenter();
    delay(frequencynum);
    turnOffCenter();
    turnOnColumns();
    digitalWrite(ledRow[2], 0);
    delay(frequencynum);
    turnOff();
  }

  for (int i = 350; i >= 0; i--) {
    turnOnCenter();
    delay(frequencynum);
    turnOffCenter();
    turnOnColumns();
    digitalWrite(ledRow[0], 0);
    delay(frequencynum);
    turnOff();
  }

  turnOnColumns(); digitalWrite(ledRow[0], 0);
  delay(tree_time); turnOff();
}

void cartesian () {
  Serial.println(" Cartesian");
  for (int i = 500; i >= 0; i--) {
    digitalWrite(ledRow[0], 0); digitalWrite(ledCol[4], 1);
    for (int i = 7; i >= 0; i-=2) {digitalWrite(ledCol[i], 1);}
    delay(frequencynum);

    turnOff();
    digitalWrite(ledRow[1], 0);
    turnOnColumns();
    delay(frequencynum);

    turnOff();
    digitalWrite(ledRow[2], 0); digitalWrite(ledCol[4], 1);
    for (int i = 7; i >= 0; i-=2) {digitalWrite(ledCol[i], 1);}
    delay(frequencynum);

    turnOff();
  }
}

void checkerboard () {
  Serial.println(" Checkerboard");
  for (int i = 5; i >= 0; i--) {
    for (int i = 175; i >= 0; i--) {
      for (int i = 8; i >= 0; i-=2) {digitalWrite(ledCol[i], 1);}
      for (int j = 2; j >= 0; j-=2) {digitalWrite(ledRow[j], 0);}
      delay(frequencynum);

      for (int i = 8; i >= 0; i-=2) {digitalWrite(ledCol[i], 0);}
      for (int j = 2; j >= 0; j-=2) {digitalWrite(ledRow[j], 1);}
      for (int i = 7; i >= 1; i-=2) {digitalWrite(ledCol[i], 1);}
      digitalWrite(ledRow[1], 0);
      delay(frequencynum);

      for (int i = 7; i >= 1; i-=2) {digitalWrite(ledCol[i], 0);}
      digitalWrite(ledRow[1], 1);
      delay(frequencynum);
    }

    for (int i = 175; i >= 0; i--) {
      for (int i = 7; i >= 1; i-=2) {digitalWrite(ledCol[i], 1);}
      for (int j = 2; j >= 0; j-=2) {digitalWrite(ledRow[j], 0);}
      delay(frequencynum);

      for (int i = 7; i >= 1; i-=2) {digitalWrite(ledCol[i], 0);}
      for (int j = 2; j >= 0; j-=2) {digitalWrite(ledRow[j], 1);}
      for (int i = 8; i >= 0; i-=2) {digitalWrite(ledCol[i], 1);}
      digitalWrite(ledRow[1], 0);
      delay(frequencynum);

      turnOff();
      delay(frequencynum);
    }
  }
}

void crossDiamond () {
  Serial.println(" Cross Diamond");
  for (int i = 8; i >= 0; i-=2) {digitalWrite(ledCol[i], 1);}

  for(int j = 0; j < 3; j++) {digitalWrite(ledRow[j], 0); delay(time1);}
  delay(transition);

  for(int j = 0; j < 3; j++) {digitalWrite(ledRow[j], 1); delay(time1);}
  digitalWrite(ledCol[4], 0);

  for (int i = 7; i >= 1; i-=2) {digitalWrite(ledCol[i], 1);}
  for(int j = 0; j < 3; j++) {digitalWrite(ledRow[j], 0); delay(time1);}
  for(int j = 0; j < 3; j++) {digitalWrite(ledRow[j], 1); delay(time1);}
}

void loop() {
  turnOff();
  // Random Selection Algorithm
  // Print a random number from 1 to 17
  randomFunction(1, 18);
  Serial.print(randNumber);

  if(randNumber == 1) {trail();}
  else if(randNumber == 2) {expandingCube();}
  else if(randNumber == 3) {layer();}
  else if(randNumber == 4) {rainDrop();}
  else if(randNumber == 5) {crossBox();}
  else if(randNumber == 6) {spiral();}
  else if(randNumber == 7) {pulsingOctahedron();}
  else if(randNumber == 8) {perimeter();}
  else if(randNumber == 9) {diagonal();}
  else if(randNumber == 10) {flash();}
  else if(randNumber == 11) {tree();}
  else if(randNumber == 12) {randomDot();}
  else if(randNumber == 13) {slant();}
  else if(randNumber == 14) {hourglass();}
  else if(randNumber == 15) {cartesian();}
  else if(randNumber == 16) {checkerboard();}
  else if(randNumber == 17) {crossDiamond();}
  //else if(randNumber == 18) {();}
  //else if(randNumber == 19) {();}
  //else if(randNumber == 20) {();}
  delay(time1);
}
