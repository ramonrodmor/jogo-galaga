/**********************************************************************************
// Player (Arquivo de Cabeçalho)
// 
// Criação:		21 Dez 2012
// Atualização:	16 Mai 2014
// Compilador:	Visual C++ 12
//
// Descrição:	Player do jogo Galaga
//
**********************************************************************************/

#include "Engine.h"
#include "Player.h"
#include "Missile.h"
#include "Galaga.h"
#include "Level1.h"
#include "Level2.h"
#include <string>
#include <fstream>
using std::ifstream;
using std::string;

// ---------------------------------------------------------------------------------

Player::Player()
{
	vidas = 3;
	sprite  = new Sprite("Resources/Nave.png");			// sprite do player
	vida3 = new Sprite("Resources/Vidas3.png");
	vida2 = new Sprite("Resources/Vidas2.png");
	vida1 = new Sprite("Resources/Vidas1.png");
	vida0 = new Sprite("Resources/Vidas0.png");
	missile = new Image("Resources/Missile.png");		// sprite do missil
	mD = -1;											// determina canhão que atira míssil

	// imagem e bbox do objeto
	bbox = new Rect(-15, -25, 15, 25); 
	MoveTo(window->CenterX(), window->Height() - 60.0f);
	vel = 250;
	type = PLAYER;
	keyCtrl = true;
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
	delete sprite;
	delete missile;
}

// ---------------------------------------------------------------------------------

void Player::OnCollision(Object * obj)
{
	// se o objeto que colidiu com o Player for inimigo e este não tiver vidas, remove da cena, caso contrário diminui uma vida
	if (obj->Type() == ENEMY)
	{
		Level1::scene->Remove(obj, STATIC);
		Level1::enemyCont--;
		Level1::pontuacao -= 10;
		vidas--;
	}

	if (obj->Type() == ENEMYE)
	{
		obj->velx = -obj->velx;
		obj->vely = -obj->vely;
		Level1::pontuacao -= 10;
		vidas--;
	}
}

// ---------------------------------------------------------------------------------

void Player::Update(float gameTime)
{
	// habilita disparo de míssil se tecla for liberada
	if (window->KeyUp(VK_SPACE))
		keyCtrl = true;

	// dispara um míssil com a barra de espaço
	if (keyCtrl==true && window->KeyDown(VK_SPACE))
	{
		// criando míssil e definindo se é disparado pela direita ou esquerda
		Missile * m = new Missile(missile);
		m->bbox = new Rect(-1, -3, 1, 3);
		if (mD == -1)
			m->MoveTo(x - 22, y + 5, 0.1f);
		else
			m->MoveTo(x + 22, y + 5, 0.1f);
		mD = -mD;
		Level1::scene->Add(m, MOVING);
		Level1::scene->CollisionCallback(m);
		keyCtrl = false;
	}

	// desloca nave horizontalmente
	if (window->KeyDown(VK_RIGHT))
		Translate(vel*gameTime, 0);
			
	if (window->KeyDown(VK_LEFT))
		Translate(-vel*gameTime, 0);
	
	// mantém nave dentro da janela
	if (x - 23 < 0)
		MoveTo(23, y);
	if (x + 24 > window->Width())
		MoveTo(float(window->Width() - 24), y);
}

// ---------------------------------------------------------------------------------

void Player::Draw()
{
	switch (vidas)
	{
	case 3:
	{
			  vida3->Draw(757, 16, 0.1f);
			  sprite->Draw(x, y, 0.2f);
	}
	case 2:
	{
			  vida2->Draw(757, 16, 0.1f);
			  sprite->Draw(x, y, 0.2f);
	}
	case 1:
	{
			  vida1->Draw(757, 16, 0.1f);
			  sprite->Draw(x, y, 0.2f);
	}
	case 0:
	{
			  vida0->Draw(757, 16, 0.1f);
			  sprite->Draw(x, y, 0.2f);
	}
	default:
		break;
	}
}