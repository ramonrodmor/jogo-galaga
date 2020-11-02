/**********************************************************************************
// Player (Arquivo de Cabeçalho)
// 
// Criação:		21 Dez 2012
// Atualização:	16 Mai 2014
// Compilador:	Visual C++ 12
//
// Descrição:	Player do jogo Galaga
//
**********************************************************************************/

#ifndef _GALAGA_PLAYER_H_
#define _GALAGA_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"			// tipos específicos da engine
#include "Object.h"			// interface de object
#include "Sprite.h"			// interface de sprites

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
	Sprite * sprite;				// sprite do player
	Sprite * vida3;					// sprite de 3 vidas
	Sprite * vida2;					// sprite de 2 vidas
	Sprite * vida1;					// sprite de 1 vida
	Sprite * vida0;					// sprite sem vidas
	Image  * missile;				// imagem do míssil
	short mD;						// define canhão que atira missil
	float vel;						// velocidade horizontal do player
	bool keyCtrl;					// controla pressionamento de tecla

public:
	
	Player();						// construtor
	~Player();						// destrutor

	void OnCollision(Object * obj);	// resolução da colisão
	void Update(float gameTime);	// atualização do objeto
	void Draw();					// desenha o objeto
};

// ---------------------------------------------------------------------------------

#endif