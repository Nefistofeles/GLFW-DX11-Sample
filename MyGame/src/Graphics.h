#pragma once
#include <d3d11.h>
#include "Window.h"

#pragma comment(lib, "d3d11.lib")

class Graphics
{
private :
	ID3D11Device* pDevice = nullptr;
	IDXGISwapChain* pSwapChain = nullptr;
	ID3D11DeviceContext* pDeviceContex = nullptr;
	ID3D11RenderTargetView* pRenderTargetView = nullptr;
	
public :
	Graphics(Window* window);
	~Graphics();
	Graphics(const Graphics&) = delete;
	Graphics& operator=(const Graphics&) = delete;

	void SwapBuffer();
	void Clear(float* rgba);
};

