/**********************************************************************************
// PacMan (Código Fonte)
//
// Criação:		01 Jan 2013
// Atualização: 23 Mai 2014
// Compilador:	Visual C++ 12
//
// Descrição:	Exercício sobre detecção de colisão
//
**********************************************************************************/

#include "Engine.h"
#include "Resources.h"
#include "Home.h"
#include "Scene.h"
#include "Galaga.h"

// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Engine * engine = new Engine();

	// configura a janela do jogo
	engine->window->Mode(WINDOWED);
	engine->window->Size(800, 600);
	engine->window->Color(25, 25, 25);
	engine->window->Title("SPACE WAR");
	engine->window->Icon(IDI_ICON);
	engine->window->Cursor(IDC_CURSOR);

	// configura dispositivo gráfico
	//engine->graphics->VSync(true);

	// inicia o jogo
	engine->Start(new Home());

	delete engine;
	return 0;
}

// ----------------------------------------------------------------------------

