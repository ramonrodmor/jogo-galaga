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

#ifndef _GALAGA_ALIEN_H_
#define _GALAGA_ALIEN_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"			// tipos específicos da engine
#include "Object.h"			// interface de object
#include "Sprite.h"			// interface de sprites
#include <string>			// string da biblioteca STL
using std::string;			// usa string sem std::

// ---------------------------------------------------------------------------------

class Alien : public Object
{
private:
	Sprite * sprite;				// sprite do alien
	Image  * missileE;				// imagem do míssil
	float velx;						// velocidade do alien em x
	float vely;						// velocidade do alien em y

public:
	Alien(string filename);			// construtor
	~Alien();						// destrutor

	void Update(float gameTime);	// atualiza o alien
	void Draw();					// desenha o alien
};

// ---------------------------------------------------------------------------------
// Funções Membro Inline
inline void Alien::Draw()
{ sprite->Draw(x, y, 0.1f); }

// ---------------------------------------------------------------------------------

#endif