/**********************************************************************************
// Game (Arquivo de Cabe�alho)
//
// Cria��o:		08 Dez 2012
// Atualiza��o:	15 Mai 2014
// Compilador:	Visual C++ 12
//
// Descri��o:	Uma class abstrata para representar um jogo.
//
//              Para criar um jogo o programador deve criar uma classe derivada
//              de Game e sobrescrever os m�todos Init, Update, Draw e Finalize.
//              Para rodar o jogo, deve-se passar o objeto Game para o m�todo
//              Start() de um objeto Engine.
//
**********************************************************************************/

#ifndef _DESENVJOGOS_GAME_H_
#define _DESENVJOGOS_GAME_H_

// ---------------------------------------------------------------------------------

#include "Window.h"

// ---------------------------------------------------------------------------------

class Game
{
	// Membros protegidos s�o privados para o mundo externo mas
	// p�blicos para as classes derivadas, ou seja, as classes
	// derivadas de Game ser�o capazes de acessar estes membros.
protected:
	static Window * window;					// janela do jogo

public:
	Game();										// construtor
	virtual ~Game();							// destrutor

	// Estes m�todos s�o puramente virtuais, isto �, devem ser 
	// implementados em todas as classes derivas de Game.

	virtual void Init() = 0;	// inicializa��o do jogo
	virtual void Update(float gameTime) = 0;	// atualiza��o do jogo
	virtual void Draw() = 0;	// desenho da cena
	virtual void Finalize() = 0;	// finaliza��o do jogo
};

// ---------------------------------------------------------------------------------

#endif