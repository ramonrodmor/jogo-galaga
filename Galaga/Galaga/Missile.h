/**********************************************************************************
// Missile (Arquivo de Cabe�alho)
// 
// Cria��o:		21 Dez 2012
// Atualiza��o:	16 Mai 2014
// Compilador:	Visual C++ 12
//
// Descri��o:	M�sseis do jogo Galaga
//
**********************************************************************************/

#ifndef _GALAGA_MISSILE_H_
#define _GALAGA_MISSILE_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"			// tipos espec�ficos da engine
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

	void OnCollision(Object * obj);	// resolu��o da colis�o
	bool Colision;					// testa colis�o do m�ssil
	void Update(float gameTime);
	void Draw();
};

// ---------------------------------------------------------------------------------
// Fun��es Membro Inline
inline void Missile::Draw()
{
	sprite->Draw(x, y, 0.1f);
}

// ---------------------------------------------------------------------------------

#endif