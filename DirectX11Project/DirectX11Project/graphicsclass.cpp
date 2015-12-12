#include "graphicsclass.h"


GraphicsClass::GraphicsClass() {}


GraphicsClass::GraphicsClass(const GraphicsClass& other) {}


GraphicsClass::~GraphicsClass() {}


bool GraphicsClass::Initialize(int screenWidth, int screenHeight, HWND hwnd)
{
	bool result;

	//Create the Direct3D Object
	m_D3D = new D3DClass;
	if (!m_D3D)
	{
		return false;
	}

	//Intialize the Direct3D object
	result = m_D3D->Initialize(screenWidth, screenHeight, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize Direct3D", L"Error", MB_OK);
	}

	return true;
}


void GraphicsClass::Shutdown()
{
	if (m_D3D)
	{
		m_D3D->Shutdown();
		delete m_D3D;
		m_D3D = 0;
	}
	return;
}


bool GraphicsClass::Frame()
{
	bool result;

	//Render the graphics scene
	result = Render();
	if (!result)
	{
		return false;
	}

	return true;
}


bool GraphicsClass::Render()
{
	//Clear the buffers to begin the scene
	m_D3D->BeginScene(0.5f, 0.5f, 0.5f, 1.0f);

	//Present the rendered scene to the screen
	m_D3D->EndScene();

	return true;
}