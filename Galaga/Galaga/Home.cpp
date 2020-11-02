/**********************************************************************************
// Home (C�digo Fonte)
//
// Cria��o:		18 Jan 2013
// Atualiza��o: 23 Mai 2014
// Compilador:	Visual C++ 12
//
// Descri��o:	Tela de abertura do jogo PacMan
//
**********************************************************************************/

#include "Engine.h"
#include "Home.h"
#include "Level1.h"

// ------------------------------------------------------------------------------

void Home::Init()
{
	backg = new Sprite("Resources/TitleScreen.jpg");
	ctrlKeyESC = false;
}

// ------------------------------------------------------------------------------

void Home::Finalize()
{
	delete backg;
}

// ------------------------------------------------------------------------------

void Home::Update(float gameTime)
{
	// sai do jogo com a tecla ESC
	if (window->KeyUp(VK_ESCAPE))
		ctrlKeyESC = true;
	if (ctrlKeyESC && window->KeyDown(VK_ESCAPE))
		window->Close();

	// passa ao primeiro n�vel com ENTER
	if (window->KeyDown(VK_RETURN))
		Engine::Next<Level1>();
}

// ------------------------------------------------------------------------------

void Home::Draw()
{
	backg->Draw(window->CenterX(), window->CenterY(), 0.9f);
}

// ------------------------------------------------------------------------------