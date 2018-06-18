
void correct(){
  if(isMoveForwardOnly())
    moveForward();
  if(isTurnLeftAngle())
    turnLeft90();
  if(isTurnRightAngle())
    turnRight90();
}
				// Fonctions Pour le mouvement

//-----------------------------------
void turnRight(){
      stopMotor(MOTOR2);
  	Motor.speed(MOTOR1, -100);
}
void turnRight90(){
  while(!isMoveForwardOnly())
  {
    stopMotor(MOTOR2);
  	Motor.speed(MOTOR1, -100);
  }

}

//-----------------------------------
void turnLeft90(){
  while(!isMoveForwardOnly())
  {
    stopMotor(MOTOR1);
   	Motor.speed(MOTOR2, -100);
  }

}

//-----------------------------------
void moveForward(){
	Motor.speed(MOTOR2, -50);
	Motor.speed(MOTOR1, -50);

}

//-----------------------------------
void turn180(){
	turnRight90();
}

//-----------------------------------
void stopMotor(int idMotor){
	Motor.stop(idMotor);
}

//-----------------------------------
void stopCar(){
	Motor.stop(MOTOR1);
	Motor.stop(MOTOR2);
}
//-----------------------------------

//-----------------------------------
			//Fonctions Pour definir le comportement
//-----------------------------------
bool isTurnRightAngle(){
	if(digitalRead(R) && !digitalRead(L) && !digitalRead(MID))
	{
		return true;
	}
	return false;
}

//-----------------------------------
bool isTurnLeftAngle(){
		if(digitalRead(L) && !digitalRead(R) && !digitalRead(MID))
	{
		return true;
	}
	return false;
}
//-----------------------------------
bool isMoveForwardOnly(){
	if(digitalRead(MID) && !digitalRead(R) && !digitalRead(L) )
	{
		return true;
	}
	return false;
}
//-----------------------------------
bool isMoveForwardWithLeft(){
	if(digitalRead(MID) && digitalRead(L) && !digitalRead(R))
	{
		return true;
	}
	return false;
}
//-----------------------------------
bool isMoveForwardWithRight(){
	if(digitalRead(MID) && digitalRead(R) && !digitalRead(L))
	{
		return true;
	}
	return false;
}
//-----------------------------------
bool isIntersection(){
		if(digitalRead(MID) && digitalRead(R) && digitalRead(L))
	{
		return true;
	}
	return false;
}
//-----------------------------------
bool isIntersection_Without_Mid(){
	if(!digitalRead(MID) && digitalRead(R) && digitalRead(L))
	{
		return true;
	}
	return false;
}
//-----------------------------------
bool isGoback(){
	if(!digitalRead(MID) && !digitalRead(R) && !digitalRead(L))
	{
		return true;
	}
	return false;
}

// LES DEUX FONCTIONS SUIVANTES SONT EXPERIMENTALES ET NE SONT PAS DUTOUT A PRENDRE EN COMPTE
//-----------------------------------
void whatToDo(){
  Position pos = whereAmI();
  switch(pos)
  {
    case POSITION1_RIGHT  :
      if(isMoveForwardWithLeft())
        turnLeft90();
      moveForward();
      if(isTurnRightAngle())
        turnRight90();
      moveForward();
      if(isMoveForwardWithRight())
        turnRight90();
      moveForward();
      if(isIntersection_Without_Mid())
        turnLeft90();
      moveForward();
      if(isTurnLeftAngle())
        turnLeft90();
      moveForward();
      if(isTurnLeftAngle())
        turnLeft90();
      moveForward();
      if(isTurnLeftAngle())
        turnLeft90();
      moveForward();
      if(isTurnLeftAngle())
        turnLeft90();
      moveForward();
      if(isMoveForwardWithLeft())
        turnLeft90();
      moveForward();
      if(isTurnRightAngle())
        turnRight90();
      moveForward();
      if(isTurnLeftAngle())
        stopCar();
      break;
  }


}
//-----------------------------------------------
Position whereAmI(){
  if(isMoveForwardOnly())
  {
    while(isMoveForwardOnly() || isMoveForwardWithLeft() || isMoveForwardWithRight() || isIntersection() || isIntersection_Without_Mid() || isTurnLeftAngle() || isTurnRightAngle())
    {
      moveForward();
      //La plus facile
//-------------------------------------------------------
      if(isIntersection)
      {
        moveForward();
        if(isIntersection_Without_Mid())
        {
          turnLeft90();
          moveForward();
          if(isTurnLeftAngle)
          {
            moveForward();
            if(isMoveForwardWithLeft())
            {
              stopCar();
              digitalWrite(ledPin, HIGH);
              delay(3000);
              digitalWrite(ledPin, LOW);
              delay(2000);
              return POSITION1_RIGHT;
            }
            if(isTurnLeftAngle())
            {
              turnLeft90();
              moveForward();
              if(isMoveForwardWithLeft())
              {
                moveForward();
                if(isMoveForwardWithLeft())
                {
                  stopCar();
                  digitalWrite(ledPin, HIGH);
                  delay(3000);
                  digitalWrite(ledPin, LOW);
                  delay(2000);
                  return POSITION2_RIGHT;
                }
                stopCar();
                digitalWrite(ledPin, HIGH);
                delay(3000);
                digitalWrite(ledPin, LOW);
                delay(2000);
                return POSITION12_LEFT;
              }
            }
          }
        }
      }
      // Beaucoup moins
//-------------------------------------------------------
      if(isIntersection_Without_Mid())
      {
        turnLeft90();
        moveForward();
        if(isTurnLeftAngle())
        {
          turnLeft90();
          moveForward();
          if(isTurnLeftAngle())
          {
            stopCar();
            digitalWrite(ledPin, HIGH);
            delay(3000);
            digitalWrite(ledPin, LOW);
            delay(2000);
            return POSITION12_LEFT;
          }
          if(isMoveForwardWithLeft())
          {
            moveForward();
            if(isMoveForwardWithLeft())
            {
              stopCar();
              digitalWrite(ledPin, HIGH);
              delay(3000);
              digitalWrite(ledPin, LOW);
              delay(3000);
              return POSITION1_RIGHT;
            }
            if(isTurnLeftAngle())
            {
              stopCar();
              digitalWrite(ledPin, HIGH);
              delay(3000);
              digitalWrite(ledPin, LOW);
              delay(2000);
              return POSITION12_LEFT;
            }
          }
        }
        if(isMoveForwardWithLeft())
        {
          moveForward();
          if(isMoveForwardWithLeft())
          {
            moveForward();
            if(isTurnLeftAngle())
            {
              stopCar();
              digitalWrite(ledPin, HIGH);
              delay(3000);
              digitalWrite(ledPin, LOW);
              delay(2000);
              return POSITION3_RIGHT;
            }
            if(isMoveForwardWithLeft())
            {
              stopCar();
              digitalWrite(ledPin, HIGH);
              delay(3000);
              digitalWrite(ledPin, LOW);
              delay(2000);
              return POSITION2_RIGHT;
            }
          }
        }
      }
      //Cherchant à Gauche
//-------------------------------------------------------
      if(isTurnLeftAngle())
      {
        turnLeft90();
        moveForward();
        if(isIntersection_Without_Mid())
        {
          turnLeft90();
          moveForward();
          if(isMoveForwardWithLeft())
          {
            stopCar();
            digitalWrite(ledPin, HIGH);
            delay(3000);
            digitalWrite(ledPin, LOW);
            delay(2000);
            return POSITION2_RIGHT;
          }
          if(isTurnLeftAngle())
          {
            stopCar();
            digitalWrite(ledPin, HIGH);
            delay(3000);
            digitalWrite(ledPin, LOW);
            delay(2000);
            return POSITION12_LEFT;
          }
        }
      }
      if(isMoveForwardWithLeft())
      {
        moveForward();
        if(isTurnLeftAngle() && !isMoveForwardWithLeft())
        {
          turnLeft90();
          moveForward();
          if(isIntersection_Without_Mid())
          {
            stopCar();
            digitalWrite(ledPin, HIGH);
            delay(3000);
            digitalWrite(ledPin, LOW);
            delay(2000);
            return POSITION1_MID;
          }
          stopCar();
          digitalWrite(ledPin, HIGH);
            delay(3000);
            digitalWrite(ledPin, LOW);
          delay(2000);
          return POSITION16_RIGHT;
        }
        if(isMoveForwardWithLeft())
        {
          moveForward();
          if(isTurnLeftAngle())
          {
            stopCar();
            digitalWrite(ledPin, HIGH);
            delay(3000);
            digitalWrite(ledPin, LOW);
            delay(2000);
            return POSITION3_RIGHT;
          }
          if(isMoveForwardWithLeft())
          {
            stopCar();
            digitalWrite(ledPin, HIGH);
            delay(3000);
            digitalWrite(ledPin, LOW);
            delay(2000);
            return POSITION2_RIGHT;
          }
          else
          {
          stopCar();
          digitalWrite(ledPin, HIGH);
            delay(3000);
            digitalWrite(ledPin, LOW);
          delay(2000);
          return POSITION8_RIGHT;
          }
        }
      }
      //Cherchant à droite
//-------------------------------------------------------
      if(isMoveForwardWithRight())
      {
        moveForward();
        if(isMoveForwardWithRight())
        {
          moveForward();
          if(isMoveForwardWithRight())
          {
            stopCar();
            digitalWrite(ledPin, HIGH);
            delay(3000);
            digitalWrite(ledPin, LOW);
            delay(2000);
            return POSITION16_LEFT;
          }
          if(isTurnRightAngle())
          {
            stopCar();
            digitalWrite(ledPin, HIGH);
            delay(3000);
            digitalWrite(ledPin, LOW);
            delay(2000);
            return POSITION3_DOWN;
          }
        }
      }
    }
  }
}
