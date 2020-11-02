/**********************************************************************************
// D3DGalaga (Arquivo de Cabeçalho)
//
// Criação:		23 Set 2011
// Atualização: 16 Mai 2014
// Compilador:	Visual C++ 12
//
// Descrição:	Usa a classe Scene para gerenciar muitos objetos na tela
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
	Sprite * title;					// título do jogo

public:
	//static Scene * scene;			// cena do jogo

	void Init();					// inicialização do jogo
	void Update(float gameTime);	// atualiza o jogo
	void Draw();					// desenha o jogo
	void Finalize();				// finaliza o jogo
};

// ------------------------------------------------------------------------------
