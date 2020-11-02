/**********************************************************************************
// Home (Arquivo de Cabe�alho)
//
// Cria��o:		18 Jan 2013
// Atualiza��o: 23 Mai 2014
// Compilador:	Visual C++ 12
//
// Descri��o:	Tela de abertura do jogo PacMan
//
**********************************************************************************/

#ifndef _GALAGA_GAMEOVER_H_
#define _GALAGA_GAMEOVER_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Sprite.h"
#include "Home.h"

// ------------------------------------------------------------------------------

class GameOver : public Game
{
private:
	Sprite * backg;					// background
	Sprite * ponC[10];				// sprite para pontua��o
	Sprite * ponD[10];				// sprite para pontua��o
	Sprite * ponU[10];				// sprite para pontua��o
	int pontos[3];					// vetor para armazenar pontua��o
	bool ctrlKeyESC;				// controla o pressionamento do ESC


public:

	void Init();									// inicializa jogo
	void Update(float gameTime);					// atualiza l�gica do jogo
	void Draw();									// desenha jogo
	void Finalize();								// finaliza jogo
};

// -----------------------------------------------------------------------------

#endif