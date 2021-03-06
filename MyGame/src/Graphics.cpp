#include "Graphics.h"

void Graphics::Clear(float* rgba)
{
	pDeviceContex->ClearRenderTargetView(pRenderTargetView, rgba);
}

Graphics::Graphics(Window* window)
{

	DXGI_SWAP_CHAIN_DESC sd = {};
	sd.BufferDesc.Width = 0;
	sd.BufferDesc.Height = 0;
	sd.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 0;
	sd.BufferDesc.RefreshRate.Denominator = 0;
	sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.BufferCount = 1;
	sd.OutputWindow = window->GetNativeWindow();
	sd.Windowed = TRUE;
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	sd.Flags = 0;

	D3D11CreateDeviceAndSwapChain(
		nullptr,
		D3D_DRIVER_TYPE_HARDWARE,
		nullptr,
		0,
		nullptr,
		0,
		D3D11_SDK_VERSION,
		&sd,
		&pSwapChain,
		&pDevice,
		nullptr,//output feature pointer
		&pDeviceContex
	);
	ID3D11Resource* pBackBuffer = nullptr;
	pSwapChain->GetBuffer(0, __uuidof(ID3D11Resource), reinterpret_cast<void**>(&pBackBuffer));
	pDevice->CreateRenderTargetView(
		pBackBuffer,
		nullptr,
		&pRenderTargetView
	);
	pBackBuffer->Release();
}

Graphics::~Graphics()
{
	if (pRenderTargetView != nullptr) {
		pRenderTargetView->Release();
	}
	if (pDeviceContex != nullptr) {
		pDeviceContex->Release();
	}
	if (pSwapChain != nullptr) {
		pSwapChain->Release();
	}
	if (pDevice != nullptr) {
		pDevice->Release();
	}

}

void Graphics::SwapBuffer()
{
	pSwapChain->Present(1u, 0u);
}
