/**********************************************************************************
// Missile (Código Fonte)
// 
// Criação:		21 Dez 2012
// Atualização:	16 Mai 2014
// Compilador:	Visual C++ 12
//
// Descrição:	Mísseis do jogo Galaga
//
**********************************************************************************/

#include "Missile.h"
#include "Galaga.h"
#include "Level1.h"
#include "Level2.h"
#include "Engine.h"
#include "Alien.h"

// ---------------------------------------------------------------------------------

Missile::Missile(Image * img)
{
	sprite = new Sprite(img);
	vely    = 250;
	Colision = false;		// Colisão do míssil
	type = MISSILE;
}

// ---------------------------------------------------------------------------------

Missile::~Missile()
{
	delete sprite;
}

// ---------------------------------------------------------------------------------

void Missile::OnCollision(Object * obj)
{
	// se o objeto que colidiu com o míssil for inimigo e este não tiver vidas, remove da cena, caso contrário diminui uma vida
	if (obj->Type() == ENEMY || obj->Type() == ENEMYE)
	{
		Colision = true;
		Level1::pontuacao += 10;

		if (obj->vidas == 0)
		{
			Level1::scene->Remove(obj, STATIC);
			Level1::enemyCont--;
		}
		else
			obj->vidas--;
	}

	if (obj->Type() == PLAYER && vely < 0)
	{
		Colision = true;
		if (obj->vidas == 0)
		{
			Level1::scene->Remove(obj, MOVING);
			Level1::pontuacao -= 10;
			Level1::playerCont--;
		}
		else
			obj->vidas--;
	}
}

// ---------------------------------------------------------------------------------

void Missile::Update(float gameTime)
{
	// míssil se move apenas no eixo y
	Translate(0, -vely * gameTime);

	// remove mísseis que saem da janela
	if (y < 0 || y > 600 || Colision==true)
		Level1::scene->Remove();
}

// ---------------------------------------------------------------------------------
