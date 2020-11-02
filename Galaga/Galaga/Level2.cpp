/**********************************************************************************
// D3DGalaga (Código Fonte)
//
// Criação:		23 Set 2011
// Atualização: 16 Mai 2014
// Compilador:	Visual C++ 12
//
// Descrição:	Usa a classe Scene para gerenciar muitos objetos na tela
//
**********************************************************************************/

#include "Engine.h"
#include "Home.h"
#include "Level1.h"
#include "Level2.h"
#include "Player.h"
#include "AlienC.h"
#include "Missile.h"
#include "GameOver.h"
#include <string>
#include <fstream>
using std::ifstream;
using std::string;

// ------------------------------------------------------------------------------
// Inicialização de membros estáticos da classe

Scene * Level2::scene = nullptr;

// ------------------------------------------------------------------------------

void Level2::Init()
{
	viewBBox = false;
	ctrlKeyB = false;

	// cria cena do jogo
	scene = new Scene();

	// cria background
	backg = new Sprite("Resources/Level2.jpg");

	// cria logos de vitória e derrota
	Win = new Sprite("Resources/LogoWin2.png");
	Lose = new Sprite("Resources/LogoLost.png");

	// ---------------------------
	// cria jogador

	Player * player = new Player();
	scene->Add(player, MOVING);
	Level2::scene->CollisionCallback(player);
	Level1::playerCont = 1;

	// ---------------------------
	// cria alienígenas

	float offset = 100;
	float posY = 60;

	AlienC * alien = new AlienC("Resources/AlienC.png");
	alien->bbox = new Rect(-92, 49, 92, 59);
	alien->MoveTo(92, posY);
	scene->Add(alien, STATIC);
	Level1::enemyCont = 1;

}

// ------------------------------------------------------------------------------

void Level2::Update(float gameTime)
{
	// habilita/desabilita bounding box
	if (window->KeyUp('B'))
		ctrlKeyB = true;
	if (ctrlKeyB && window->KeyDown('B'))
	{
		viewBBox = !viewBBox;
		ctrlKeyB = false;
	}

	if (window->KeyDown(VK_ESCAPE))
	{
		// volta para a tela de abertura
		Engine::Next<Home>();
	}
	else if (Level1::enemyCont == 0 || Level1::playerCont == 0)
	{
		// passa manualmente para o próximo nível
		Sleep(2000);
		Engine::Next<GameOver>();
	}
	else
	{
		// atualiza cena
		scene->Update(gameTime);
		scene->CollisionDetection();
	}
}

// ------------------------------------------------------------------------------

void Level2::Draw()
{
	// desenha cena
	backg->Draw(window->CenterX(), window->CenterY(), 0.9f);
	scene->Draw();

	// desenha os sprites de vitória ou derrota
	if (Level1::enemyCont == 0)
		Win->Draw(window->CenterX(), window->CenterY(), 0.8f);

	if (Level1::playerCont == 0)
		Lose->Draw(window->CenterX(), window->CenterY(), 0.1f);

	// desenha bounding box dos objetos
	if (viewBBox)
	{
		Engine::renderer->BeginPixels();
		scene->Begin();
		Object * obj = nullptr;
		while (obj = scene->Next())
			Engine::renderer->Draw(obj->bbox, 0xffff00ff);
		Engine::renderer->EndPixels();
	}
}

// ------------------------------------------------------------------------------

void Level2::Finalize()
{
	// apaga cena do jogo
	delete scene;
}