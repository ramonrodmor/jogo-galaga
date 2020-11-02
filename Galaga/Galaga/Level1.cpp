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
#include "GameOver.h"
#include "Player.h"
#include "Alien.h"
#include "Missile.h"
#include <string>
#include <fstream>
using std::ifstream;
using std::string;

// ------------------------------------------------------------------------------
// Inicialização de membros estáticos da classe

Scene * Level1::scene = nullptr;
short Level1::playerCont = 0;
short Level1::enemyCont = 0;
int Level1::pontuacao = 0;

// ------------------------------------------------------------------------------

void Level1::Init()
{
	viewBBox = false;
	ctrlKeyB = false;

	// cria cena do jogo
	scene = new Scene();

	// cria background
	backg = new Sprite("Resources/Level1.jpg");

	// cria logos de vitória e derrota
	Win = new Sprite("Resources/LogoWin1.png");
	Lose = new Sprite("Resources/LogoLost.png");
		
	// ---------------------------
	// cria jogador
	Player * player = new Player();
	scene->Add(player, MOVING);
	Level1::scene->CollisionCallback(player);
	playerCont = 1;

	// ---------------------------
	// cria alienígenas

	float offset = 75;
	float posY = 60;

	Alien * alien = new Alien("Resources/Alien1.png");
	alien->bbox = new Rect(-28, -10, 28, 10);
	alien->MoveTo(offset, posY);
	scene->Add(alien, STATIC);

	alien = new Alien("Resources/Alien2.png");
	alien->bbox = new Rect(-28, -10, 28, 10);
	alien->MoveTo(2 * offset, posY + 30);
	scene->Add(alien, STATIC);

	alien = new Alien("Resources/Alien3.png");
	alien->bbox = new Rect(-28, -10, 28, 10);
	alien->MoveTo(3 * offset, posY);
	scene->Add(alien, STATIC);

	alien = new Alien("Resources/Alien4.png");
	alien->bbox = new Rect(-28, -10, 28, 10);
	alien->MoveTo(4 * offset, posY + 30);
	scene->Add(alien, STATIC);

	alien = new Alien("Resources/Alien1.png");
	alien->bbox = new Rect(-28, -10, 28, 10);
	alien->MoveTo(5 * offset, posY);
	scene->Add(alien, STATIC);

	alien = new Alien("Resources/Alien2.png");
	alien->bbox = new Rect(-28, -10, 28, 10);
	alien->MoveTo(6 * offset, posY + 30);
	scene->Add(alien, STATIC);

	alien = new Alien("Resources/Alien3.png");
	alien->bbox = new Rect(-28, -10, 28, 10);
	alien->MoveTo(7 * offset, posY);
	scene->Add(alien, STATIC);

	alien = new Alien("Resources/Alien4.png");
	alien->bbox = new Rect(-28, -10, 28, 10);
	alien->MoveTo(8 * offset, posY + 30);
	scene->Add(alien, STATIC);

	alien = new Alien("Resources/Alien4.png");
	alien->bbox = new Rect(-28, -10, 28, 10);
	alien->MoveTo(offset, posY + 60);
	scene->Add(alien, STATIC);

	alien = new Alien("Resources/Alien3.png");
	alien->bbox = new Rect(-28, -10, 28, 10);
	alien->MoveTo(3 * offset, posY + 60);
	scene->Add(alien, STATIC);

	alien = new Alien("Resources/Alien2.png");
	alien->bbox = new Rect(-28, -10, 28, 10);
	alien->MoveTo(5 * offset, posY + 60);
	scene->Add(alien, STATIC);

	alien = new Alien("Resources/Alien1.png");
	alien->bbox = new Rect(-28, -10, 28, 10);
	alien->MoveTo(7 * offset, posY + 60);
	scene->Add(alien, STATIC);
	
	enemyCont = 12;
}

// ------------------------------------------------------------------------------

void Level1::Update(float gameTime)
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
		Engine::Next<Home>();	// volta para a tela de abertura
	}
	else if (enemyCont == 0)
	{
		Sleep(2000);
		Engine::Next<Level2>();	// passa manualmente para o próximo nível
	}
	else if (playerCont == 0)
	{
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

void Level1::Draw()
{
	// desenha cena
	backg->Draw(window->CenterX(), window->CenterY(), 0.9f);
	scene->Draw();

	// desenha os sprites de vitória ou derrota
	if (enemyCont == 0)
	{
		Win->Draw(window->CenterX(), window->CenterY(), 0.8f);
	}

	if (playerCont == 0)
	{
		Lose->Draw(window->CenterX(), window->CenterY(), 0.8f);
	}

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

void Level1::Finalize()
{
	// apaga cena do jogo
	delete scene;
}