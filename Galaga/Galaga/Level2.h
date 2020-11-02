/**********************************************************************************
// Level1 (Arquivo de Cabe�alho)
//
// Cria��o:		18 Jan 2013
// Atualiza��o: 23 Mai 2014
// Compilador:	Visual C++ 12
//
// Descri��o:	N�vel 1 do jogo PacMan
//
**********************************************************************************/

#ifndef _GALAGA_LEVEl2_H_
#define _GALAGA_LEVEL2_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Sprite.h"
#include "Scene.h"

// ------------------------------------------------------------------------------

class Level2 : public Game
{
private:
	Sprite * backg;					// background
	Sprite * Win;					// mensagem de vit�ria
	Sprite * Lose;					// mensagem de derrota
	bool viewBBox;					// habilita visualiza��o da bounding box
	bool ctrlKeyB;					// controle da tecla B

public:

	void Init();					// inicializa jogo
	static Scene  * scene;			// gerenciador de cena
	void Update(float gameTime);	// atualiza l�gica do jogo
	void Draw();					// desenha jogo
	void Finalize();				// finaliza jogo
};

// -----------------------------------------------------------------------------

#endif