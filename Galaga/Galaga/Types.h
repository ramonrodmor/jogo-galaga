/**********************************************************************************
// Types (Arquivo de Cabe�alho)
//
// Cria��o:		02 Abr 2011
// Atualiza��o:	18 Mai 2014
// Compilador:	Visual C++ 12
//
// Descri��o:	Isola os tipos espec�ficos da plataforma fornecendo tipos
//				consistentes para o Motor de Jogo.
//
**********************************************************************************/

#ifndef _DESENVJOGOS_TYPES_H_
#define _DESENVJOGOS_TYPES_H_

#include <d3d11.h>
#include <DirectXMath.h>
using namespace DirectX;

// nomes para tipos padr�es da linguagem C++ usados na engine
typedef unsigned char		uchar;
typedef unsigned short		ushort;
typedef unsigned long		ulong;
typedef long long			llong;
typedef unsigned long long	ullong;
typedef unsigned int		uint;

// formatos geom�tricos
enum GeometryTypes
{
	UNKNOWN_T,
	POINT_T,
	LINE_T,
	RECTANGLE_T,
	CIRCLE_T,
	POLYGON_T,
	MULTI_T
};

// defini��o de um v�rtice para o D3D
struct Vertex
{
	XMFLOAT3 pos;
	XMFLOAT4 color;
	XMFLOAT2 tex;
};

// defini��o de um sprite
struct SpriteInfo
{
	float x, y;
	float scale;
	float depth;
	float rotation;
	uint  width;
	uint  height;
	ID3D11ShaderResourceView* texture;
};

enum ObjectStatus
{
	STATIC,
	MOVING
};

#endif