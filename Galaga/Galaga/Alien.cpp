/**********************************************************************************
// Alien (Arquivo de Cabeçalho)
// 
// Criação:		21 Dez 2012
// Atualização:	16 Mai 2014
// Compilador:	Visual C++ 12
//
// Descrição:	Alienígena do jogo Galaga
//
**********************************************************************************/

#include "Alien.h"
#include "Galaga.h"
#include "Missile.h"
#include "Level1.h"
#include <string>
#include <fstream>
using std::ifstream;
using std::string;

// ---------------------------------------------------------------------------------

Alien::Alien(string filename)
{
	sprite = new Sprite(filename);
	missileE = new Image("Resources/MissileE.png");		// sprite do missil
	velx = 100.0f;
	vely = 10.0f;
	vidas = 3;
	type = ENEMY;
}

// ---------------------------------------------------------------------------------

Alien::~Alien()
{
	delete sprite;
}

// ---------------------------------------------------------------------------------

void Alien::Update(float gameTime)
{
	// dispara um míssil
	if ((rand() % 1000) == 1)
	{
		// criando míssil e definindo se é disparado pela direita ou esquerda
		Missile * m = new Missile(missileE);
		m->vely = -m->vely;
		m->bbox = new Rect(-1, -3, 1, 3);
			m->MoveTo(x, y, 0.1f);
		Level1::scene->Add(m, STATIC);
		Level1::scene->CollisionCallback(m);
	}

	Translate(velx * gameTime, vely * gameTime);

	// mantêm os alienígenas dentro da janela

	// alien saindo pela esquerda ou direita
	if ((x - 30 < 0) || (x + 31 > window->Width()))
		velx = -velx;
	
	// alien saindo por baixo
	if ((y > 600))
		MoveTo(x, 0);
}

// ---------------------------------------------------------------------------------
