/**********************************************************************************
// D3DGalaga (Arquivo de Cabe�alho)
//
// Cria��o:		23 Set 2011
// Atualiza��o: 16 Mai 2014
// Compilador:	Visual C++ 12
//
// Descri��o:	Usa a classe Scene para gerenciar muitos objetos na tela
//
**********************************************************************************/

#include "Game.h"
#include "Scene.h"
#include "Sprite.h"

// ------------------------------------------------------------------------------

enum GalagaObjects					// tipos de objetos existentes na cena
{
	PLAYER,
	ENEMY,
	MISSILE,
	ENEMYE
};

class Galaga : public Game
{
private:
	Sprite * title;					// t�tulo do jogo

public:
	//static Scene * scene;			// cena do jogo

	void Init();					// inicializa��o do jogo
	void Update(float gameTime);	// atualiza o jogo
	void Draw();					// desenha o jogo
	void Finalize();				// finaliza o jogo
};

// ------------------------------------------------------------------------------
