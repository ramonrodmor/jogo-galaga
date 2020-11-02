/**********************************************************************************
// Alien (Arquivo de Cabe�alho)
//
// Cria��o:		21 Dez 2012
// Atualiza��o:	16 Mai 2014
// Compilador:	Visual C++ 12
//
// Descri��o:	Alien�gena do jogo Galaga
//
**********************************************************************************/

#ifndef _GALAGA_ALIENC_H_
#define _GALAGA_ALIENC_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"			// tipos espec�ficos da engine
#include "Object.h"			// interface de object
#include "Sprite.h"			// interface de sprites
#include <string>			// string da biblioteca STL
using std::string;			// usa string sem std::

// ---------------------------------------------------------------------------------

class AlienC : public Object
{
private:
	Sprite * sprite;				// sprite do alien
	Image  * missileE;				// imagem do m�ssil

public:

	AlienC(string filename);		// construtor
	~AlienC();						// destrutor

	void Update(float gameTime);	// atualiza o alien
	void Draw();					// desenha o alien
};

// ---------------------------------------------------------------------------------
// Fun��es Membro Inline
inline void AlienC::Draw()
{
	sprite->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif