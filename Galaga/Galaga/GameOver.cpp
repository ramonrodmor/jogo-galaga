/**********************************************************************************
// Home (Código Fonte)
//
// Criação:		18 Jan 2013
// Atualização: 23 Mai 2014
// Compilador:	Visual C++ 12
//
// Descrição:	Tela de abertura do jogo PacMan
//
**********************************************************************************/

#include "Engine.h"
#include "GameOver.h"
#include "Level1.h"

// ------------------------------------------------------------------------------

void GameOver::Init()
{
	backg = new Sprite("Resources/GameOver.jpg");

	ponC[0] = new Sprite("Resources/0.png");
	ponC[1] = new Sprite("Resources/1.png");
	ponC[2] = new Sprite("Resources/2.png");
	ponC[3] = new Sprite("Resources/3.png");
	ponC[4] = new Sprite("Resources/4.png");
	ponC[5] = new Sprite("Resources/5.png");
	ponC[6] = new Sprite("Resources/6.png");
	ponC[7] = new Sprite("Resources/7.png");
	ponC[8] = new Sprite("Resources/8.png");
	ponC[9] = new Sprite("Resources/9.png");

	ponD[0] = new Sprite("Resources/0.png");
	ponD[1] = new Sprite("Resources/1.png");
	ponD[2] = new Sprite("Resources/2.png");
	ponD[3] = new Sprite("Resources/3.png");
	ponD[4] = new Sprite("Resources/4.png");
	ponD[5] = new Sprite("Resources/5.png");
	ponD[6] = new Sprite("Resources/6.png");
	ponD[7] = new Sprite("Resources/7.png");
	ponD[8] = new Sprite("Resources/8.png");
	ponD[9] = new Sprite("Resources/9.png");

	ponU[0] = new Sprite("Resources/0.png");
	ponU[1] = new Sprite("Resources/1.png");
	ponU[2] = new Sprite("Resources/2.png");
	ponU[3] = new Sprite("Resources/3.png");
	ponU[4] = new Sprite("Resources/4.png");
	ponU[5] = new Sprite("Resources/5.png");
	ponU[6] = new Sprite("Resources/6.png");
	ponU[7] = new Sprite("Resources/7.png");
	ponU[8] = new Sprite("Resources/8.png");
	ponU[9] = new Sprite("Resources/9.png");

	if (Level1::pontuacao < 0)
		Level1::pontuacao = 0;

	pontos[2] = Level1::pontuacao % 10;
	Level1::pontuacao = Level1::pontuacao / 10;
	pontos[1] = Level1::pontuacao % 10;
	Level1::pontuacao = Level1::pontuacao / 10;
	pontos[0] = Level1::pontuacao % 10;
	Level1::pontuacao = 0;

	ctrlKeyESC = false;
}

// ------------------------------------------------------------------------------

void GameOver::Finalize()
{
	delete backg;
}

// ------------------------------------------------------------------------------

void GameOver::Update(float gameTime)
{
	// sai do jogo com a tecla ESC
	if (window->KeyUp(VK_ESCAPE))
		ctrlKeyESC = true;
	if (window->KeyDown(VK_ESCAPE))
	{
		// volta para a tela de abertura
		Engine::Next<Home>();
	}
}

// ------------------------------------------------------------------------------

void GameOver::Draw()
{
	backg->Draw(window->CenterX(), window->CenterY(), 0.9f);

	switch (pontos[0])
	{
	case 0: ponC[0]->Draw(80, 300, 0.1f); break;
	case 1: ponC[1]->Draw(80, 300, 0.1f); break;
	case 2: ponC[2]->Draw(80, 300, 0.1f); break;
	case 3: ponC[3]->Draw(80, 300, 0.1f); break;
	case 4: ponC[4]->Draw(80, 300, 0.1f); break;
	case 5: ponC[5]->Draw(80, 300, 0.1f); break;
	case 6: ponC[6]->Draw(80, 300, 0.1f); break;
	case 7: ponC[7]->Draw(80, 300, 0.1f); break;
	case 8: ponC[8]->Draw(80, 300, 0.1f); break;
	case 9: ponC[9]->Draw(80, 300, 0.1f); break;
	}
	
	switch (pontos[1])
	{
	case 0: ponD[0]->Draw(180, 300, 0.1f); break;
	case 1: ponD[1]->Draw(180, 300, 0.1f); break;
	case 2: ponD[2]->Draw(180, 300, 0.1f); break;
	case 3: ponD[3]->Draw(180, 300, 0.1f); break;
	case 4: ponD[4]->Draw(180, 300, 0.1f); break;
	case 5: ponD[5]->Draw(180, 300, 0.1f); break;
	case 6: ponD[6]->Draw(180, 300, 0.1f); break;
	case 7: ponD[7]->Draw(180, 300, 0.1f); break;
	case 8: ponD[8]->Draw(180, 300, 0.1f); break;
	case 9: ponD[9]->Draw(180, 300, 0.1f); break;
	}

	switch (pontos[2])
	{
	case 0: ponU[0]->Draw(280, 300, 0.1f); break;
	case 1: ponU[1]->Draw(280, 300, 0.1f); break;
	case 2: ponU[2]->Draw(280, 300, 0.1f); break;
	case 3: ponU[3]->Draw(280, 300, 0.1f); break;
	case 4: ponU[4]->Draw(280, 300, 0.1f); break;
	case 5: ponU[5]->Draw(280, 300, 0.1f); break;
	case 6: ponU[6]->Draw(280, 300, 0.1f); break;
	case 7: ponU[7]->Draw(280, 300, 0.1f); break;
	case 8: ponU[8]->Draw(280, 300, 0.1f); break;
	case 9: ponU[9]->Draw(280, 300, 0.1f); break;
	}
	
}

// ------------------------------------------------------------------------------
