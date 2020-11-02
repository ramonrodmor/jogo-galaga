/**********************************************************************************
// Home (Arquivo de Cabeçalho)
//
// Criação:		18 Jan 2013
// Atualização: 23 Mai 2014
// Compilador:	Visual C++ 12
//
// Descrição:	Tela de abertura do jogo PacMan
//
**********************************************************************************/

#ifndef _GALAGA_HOME_H_
#define _GALAGA_HOME_H_

// ------------------------------------------------------------------------------
// Inclusões

#include "Game.h"
#include "Sprite.h"

// ------------------------------------------------------------------------------

class Home : public Game
{
private:
	Sprite * backg;					// background
	bool ctrlKeyESC;				// controla o pressionamento do ESC

public:
	void Init();					// inicializa jogo
	void Update(float gameTime);	// atualiza lógica do jogo
	void Draw();					// desenha jogo
	void Finalize();				// finaliza jogo
};

// -----------------------------------------------------------------------------

#endif