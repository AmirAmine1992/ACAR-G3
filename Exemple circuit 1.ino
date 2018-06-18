#include <Acar.h>

int i = 0;
int tab[] = {1,2,2,1,1,3,3,1,3,1,3,1,1,3,2};

void setup()
{
  Serial.begin(9600);  // initialize serial communications at 9600 bps:
  Motor.begin(I2C_ADDRESS);
    pinMode(ledPin, OUTPUT);
}

void loop()
{
//Correction()
//--------------------------------------------------
   correct();

  if(isMoveForwardWithLeft() || isMoveForwardWithRight() || isIntersection())
  {
    
    if (i<15){
    if (tab[i]==1) {
                      stopCar();
                      delay(500);
                      turnLeft90();
                      turnLeft();
                      delay(100);
                      i++;
                    }
               else {
                       if (tab[i]==2) { 
                                        stopCar();
                                        delay(500);
                                        turnRight90();
                                        turnRight();
                                        delay(200);
                                        i++;
                                      }
                                      else{
                                        stopCar();
                                        delay(500);
                                        moveForward();
                                        delay(700);
                                        moveForward();
                                       i++;
                                      }
    }
    }else {stopCar();}
  }
}