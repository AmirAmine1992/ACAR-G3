
#ifndef ACAR
#define ACAR
//Author Rafik Belkadi

#include <Arduino.h>
#include "Grove_I2C_Motor_Driver.h"

#define MID 3      // Capteur du milieu
#define L 4       // Capteur Gauche
#define R 5       // Capteur Droit

//EXPERIMENTALE
//La Led qui s'allume si la position est trouvée.
int ledPin = 13;
	
	//EXPERIMENTALE ET A NE PAS PRENDRE EN COMPTE !
	// Création du type de donnée Position pour l'utiliser dans des switch case.
typedef enum Position{
  
  POSITION1_RIGHT,
  POSITION1_MID,
  
  POSITION2_LEFT,
  POSITION2_RIGHT,
  
  POSITION3_LEFT,
  POSITION3_RIGHT,
  POSITION3_DOWN,
  
  POSITION12_RIGHT,
  POSITION12_LEFT,
  
  POSITION8_LEFT,
  POSITION8_RIGHT,
  
  POSITION16_LEFT,
  POSITION16_RIGHT,
  
} Position;




			//Ce que la voiture peut faire : 
//------------------------------
	//Tourner à droite 90°
void turnRight90(); 	// tant que la ligne noir n'est pas trouvée
void turnRight();	 // à utiliser avec un delay 

	//Tourner à gauche 90°
void turnLeft90();	// tant que la ligne noir n'est pas trouvée
void turnLeft();	// à utiliser avec un delay 

	//Avancer tout droit
void moveForward();

	//Tourne à 180°
void turn180();

	//Fonction de correction de la trajectoire
void correct();

	//Arrête un moteur donné en parametre
void stopMotor(int idMotor);

	//Arrête la voiture
void stopCar();

//------------------------------

			//Verification de l'action à faire :
//------------------------------

	// Verifie si il ya un virage à droite sans aucune autre possibilité ( ni gauche ni avant )
bool isTurnRightAngle();

	// Même chose pour la gauche
bool isTurnLeftAngle();

	// Verifie si il est uniquement possible d'avancer
bool isMoveForwardOnly();

	// Même chose mais cette fois avec la possibilité de tourner à gauche
bool isMoveForwardWithLeft();

	// Même chose mais avec la droite
bool isMoveForwardWithRight();

	// Vérifie si il y a une intersection (possibilité de continuer tout droit à gauche ou à droite )
bool isIntersection();
	
	//Experimentale et à ne pas prendre en compte
	// Même chose mais sans la possibilité d'avancer tout droit
bool isIntersection_Without_Mid();

	// Verifie qu'il n'y a aucune possibilité ( gauche, droite, tout droit).
bool isGoback();
	






// LES DEUX FONCTIONS SUIVANTES SONT EXPERIMENTALES ET NE SONT PAS DUTOUT A PRENDRE EN COMPTE
//------------------------------------------------------------------------------------------------
	// Méthode ne retournant rien, donne des ordres pour parcourir la map selon la position retournée par la méthode whereAmI().
void whatToDo()

	// Méthode retournant la position courante de la voiture
Position whereAmI() 
//------------------------------

#endif