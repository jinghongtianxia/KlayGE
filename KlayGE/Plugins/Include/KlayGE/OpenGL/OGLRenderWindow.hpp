#ifndef _OGLRENDERWINDOW_HPP
#define _OGLRENDERWINDOW_HPP

#include <KlayGE/PreDeclare.hpp>
#include <KlayGE/RenderWindow.hpp>

#ifdef KLAYGE_DEBUG
	#pragma comment(lib, "KlayGE_RenderEngine_OpenGL_d.lib")
#else
	#pragma comment(lib, "KlayGE_RenderEngine_OpenGL.lib")
#endif

namespace KlayGE
{
	struct RenderSettings;

	class OGLRenderWindow : public RenderWindow
	{
	public:
		OGLRenderWindow(std::string const & name, RenderSettings const & settings);
		~OGLRenderWindow();

		LRESULT MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

		void Destroy();

		bool Closed() const;

		bool Ready() const;
		void Ready(bool ready);

		void Reposition(uint32_t left, uint32_t top);
		void Resize(uint32_t width, uint32_t height);
		void SwapBuffers();

		HWND WindowHandle() const;

		std::wstring const & Description() const;

		void CustomAttribute(std::string const & name, void* pData);

		bool RequiresTextureFlipping() const;

		// Method for dealing with resize / move & 3d library
		void WindowMovedOrResized();

	protected:
		std::string	name_;

		HWND	hWnd_;
		HGLRC	hRC_;
		HDC		hDC_;

		bool	ready_;				// Is ready i.e. available for update
		bool	closed_;

		static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg,
			WPARAM wParam, LPARAM lParam );

		std::wstring			description_;
	};
}

#endif			// _OGLRENDERWINDOW_HPP
