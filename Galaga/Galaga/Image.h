/**********************************************************************************
// Image (Arquivo de Cabe�alho)
//
// Cria��o:		16 Mar 2012
// Atualiza��o:	11 Mai 2014
// Compilador:	Visual C++ 12
//
// Descri��o:	Define uma classe para representar imagens
//
**********************************************************************************/

#ifndef _DESENVJOGOS_IMAGE_H_
#define _DESENVJOGOS_IMAGE_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"		// tipos espec�ficos do motor
#include "Texture.h"	// fun��o para carregar textura
#include <string>		// classe string de C++
using std::string;		// classe pode ser usada sem std::

// ---------------------------------------------------------------------------------

class Image
{
private:
	ID3D11ShaderResourceView * textureView;		// view associada a textura
	uint width;									// altura da imagem
	uint height;								// largura da imagem

public:
	Image(string filename);						// constroi imagem a partir de um arquivo
	~Image();									// destrutor

	uint Width() const;							// retorna largura da imagem
	uint Height() const;						// retorna altura da imagem
	ID3D11ShaderResourceView * View() const;	// retorna ponteiro para a view da imagem
};

// ---------------------------------------------------------------------------------
// M�todos Inline

// retorna largura da textura
inline uint Image::Width() const
{
	return width;
}

// retorna altura da textura
inline uint Image::Height() const
{
	return height;
}

// retorna ponteiro para textura D3D
inline ID3D11ShaderResourceView * Image::View() const
{
	return textureView;
}

// --------------------------------------------------------------------------------

#endif



