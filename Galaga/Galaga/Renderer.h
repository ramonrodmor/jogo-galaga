/**********************************************************************************
// Renderer (Arquivo de Cabe�alho)
//
// Cria��o:		11 Mai 2014
// Atualiza��o:	18 Mai 2014
// Compilador:	Visual C++ 12
//
// Descri��o:	Define um renderizador de grupos de sprites
//
**********************************************************************************/

#ifndef _DESENVJOGOS_RENDERER_H_
#define _DESENVJOGOS_RENDERER_H_

// ---------------------------------------------------------------------------------

#include "Window.h"												// cria e configura uma janela do Windows
#include "Graphics.h"											// inicializa dispositivo gr�fico da engine
#include "Geometry.h"											// formas geom�tricas para desenho
#include "Types.h"												// tipos espec�ficos da engine		
#include <vector>												// vetor da Standard Template Library
using namespace std;

// ---------------------------------------------------------------------------------

class Renderer
{
private:
	Window                   * window;							// ponteiro para janela do jogo
	Graphics                 * graphics;						// ponteiro para dispositivo gr�fico

	ID3D11InputLayout		 * inputLayout;						// input layout
	ID3D11VertexShader		 * vertexShader;					// vertex shader
	ID3D11PixelShader		 * pixelShader;						// pixel shader
	ID3D11RasterizerState	 * rasterState;						// estado do rasterizador
	ID3D11SamplerState		 * sampler;							// estado do amostrador de textura
	ID3D11Buffer			 * vertexBuffer;					// buffer de v�rtices
	ID3D11Buffer			 * indexBuffer;						// buffer de �ndices
	ID3D11Buffer			 * constantBuffer;					// buffer para o shader
	uint                       vertexBufferPosition;			// posi��o atual do vertex buffer

	static const uint MinBatchSize = 128;						// tamanho m�nimo do lote de sprites
	static const uint MaxBatchSize = 2048;						// tamanho m�ximo do lote de sprites	
	static const uint VerticesPerSprite = 4;					// n�mero de v�rtices por sprite
	static const uint IndicesPerSprite = 6;						// n�mero de �ndices por sprite

	// ----------------------------------------
	// Pixel Plot
	// ----------------------------------------
	ID3D11Texture2D *				pixelPlotTexture;			// textura para plotagem de pixels
	ID3D11ShaderResourceView *		pixelPlotView;				// visualiza��o para a textura de pixels
	SpriteInfo						pixelPlotSprite;			// sprite para a textura de pixels
	long	  						videoMemoryPitch;			// n�mero de pixels em cada linha da mem�ria de v�deo
	ulong *							videoMemory;				// ponteiro para a mem�ria de v�deo (32 bits por pixel)

	void PlotPixel(int x, int y, ulong color);					// plota pixels sem recorte (clipping)
	void PlotLine(int x, int y, int flag, ulong color);			// plota pixels para algoritmo de linha
	void DrawLine(int a1, int b1, int a2, int b2, ulong color);	// desenha linha sem recorte (clipping)
	int  ClipLine(int &x1, int &y1, int &x2, int &y2);			// recorta linha para desenhar na viewport
	// ----------------------------------------

	vector<SpriteInfo*> spriteVector;							// vetor de sprites

	// renderiza um grupo de sprites de mesma textura
	void RenderBatch(ID3D11ShaderResourceView * texture, SpriteInfo ** sprites, uint cont);

public:
	Renderer();													// construtor
	~Renderer();												// destrutor

	// ----------------------------------------
	// Pixel Plot
	// ----------------------------------------
	void BeginPixels();											// trava a textura de plotagem de pixels
	void Draw(Geometry * shape, ulong color);					// desenha geometria
	void Draw(Point * point, ulong color);						// desenha ponto
	void Draw(Line * line, ulong color);						// desenha linha  
	void Draw(Rect * rect, ulong color);						// desenha ret�ngulo  
	void Draw(Circle * circ, ulong color);						// desenha c�rculo  
	void Draw(Poly * pol, ulong color);							// desenha pol�gono
	void Draw(Multi * mul, ulong color);						// desenha multi-formas
	void EndPixels();											// destrava a textura de plotagem de pixels	
	// ----------------------------------------

	bool Initialize(Window * window, Graphics * graphics);		// inicializa o renderizador
	void Draw(SpriteInfo * sprite);								// adiciona sprite na lista
	void Render();												// envia sprites para desenho	
};

// --------------------------------------------------------------------------------
// Fun��es Membro Inline

// plota pixels sem fazer recorte (clipping)
inline void Renderer::PlotPixel(int x, int y, ulong color)
{
	videoMemory[x + y * videoMemoryPitch] = color;
}

// plot pixels for DrawLine method
inline void Renderer::PlotLine(int x, int y, int flag, ulong color)
{
	flag ? PlotPixel(y, x, color) : PlotPixel(x, y, color);
}

// ---------------------------------------------------------------------------------

#endif