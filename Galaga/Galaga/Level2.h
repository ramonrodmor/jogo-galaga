/**********************************************************************************
// Level1 (Arquivo de Cabeçalho)
//
// Criação:		18 Jan 2013
// Atualização: 23 Mai 2014
// Compilador:	Visual C++ 12
//
// Descrição:	Nível 1 do jogo PacMan
//
**********************************************************************************/

#ifndef _GALAGA_LEVEl2_H_
#define _GALAGA_LEVEL2_H_

// ------------------------------------------------------------------------------
// Inclusões

#include "Game.h"
#include "Sprite.h"
#include "Scene.h"

// ------------------------------------------------------------------------------

class Level2 : public Game
{
private:
	Sprite * backg;					// background
	Sprite * Win;					// mensagem de vitória
	Sprite * Lose;					// mensagem de derrota
	bool viewBBox;					// habilita visualização da bounding box
	bool ctrlKeyB;					// controle da tecla B

public:

	void Init();					// inicializa jogo
	static Scene  * scene;			// gerenciador de cena
	void Update(float gameTime);	// atualiza lógica do jogo
	void Draw();					// desenha jogo
	void Finalize();				// finaliza jogo
};

// -----------------------------------------------------------------------------

#endif