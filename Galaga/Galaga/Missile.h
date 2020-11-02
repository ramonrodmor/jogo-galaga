/**********************************************************************************
// Missile (Arquivo de Cabeçalho)
// 
// Criação:		21 Dez 2012
// Atualização:	16 Mai 2014
// Compilador:	Visual C++ 12
//
// Descrição:	Mísseis do jogo Galaga
//
**********************************************************************************/

#ifndef _GALAGA_MISSILE_H_
#define _GALAGA_MISSILE_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"			// tipos específicos da engine
#include "Object.h"			// interface de object
#include "Sprite.h"			// interface de sprites
#include "Image.h"			// interface de image

// ---------------------------------------------------------------------------------

class Missile : public Object
{
private:
	Sprite * sprite;

public:
	Missile(Image * img);
	~Missile();

	void OnCollision(Object * obj);	// resolução da colisão
	bool Colision;					// testa colisão do míssil
	void Update(float gameTime);
	void Draw();
};

// ---------------------------------------------------------------------------------
// Funções Membro Inline
inline void Missile::Draw()
{
	sprite->Draw(x, y, 0.1f);
}

// ---------------------------------------------------------------------------------

#endif