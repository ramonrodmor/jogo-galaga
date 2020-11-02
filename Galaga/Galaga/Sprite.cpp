/**********************************************************************************
// Sprite (Código Fonte)
//
// Criação:		11 Jul 2007
// Atualização:	11 Mai 2014
// Compilador:	Visual C++ 12
//
// Descrição:	Define uma classe para representar um sprite
//
**********************************************************************************/

#include "Sprite.h"
#include "Engine.h"

// ---------------------------------------------------------------------------------

Sprite::Sprite(string filename)
{
	// carrega imagem
	image = new Image(filename);
	localImage = true;

	// configura registro sprite
	spriteInfo.texture = image->View();
}

// ---------------------------------------------------------------------------------

Sprite::Sprite(const Image * img)
{
	// aponta para imagem externa
	image = img;
	localImage = false;

	// configura registro sprite
	spriteInfo.texture = image->View();
}

// ---------------------------------------------------------------------------------

Sprite::~Sprite()
{
	if (localImage)
		delete image;
}

// ---------------------------------------------------------------------------------

void Sprite::Draw(float x, float y, float z)
{
	spriteInfo.x = x;
	spriteInfo.y = y;
	spriteInfo.scale = 1.0f;
	spriteInfo.depth = z;
	spriteInfo.rotation = 0.0f;
	spriteInfo.width = image->Width();
	spriteInfo.height = image->Height();

	// adiciona o sprite na lista de desenho
	Engine::renderer->Draw(&spriteInfo);
}

// ---------------------------------------------------------------------------------