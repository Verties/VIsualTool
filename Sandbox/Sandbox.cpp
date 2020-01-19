#include "VisualTool.h"

struct WindowEventArgs
{
	int x, y;
};

class Window
{
public:
	vt_event::Event<WindowEventArgs&> OnButtonClicked;
};

void FunctionHandler(WindowEventArgs& args)
{
	std::cout << "FunctionHandler:\n" << "x=" << args.x << ", y=" << args.y << "\n\n";
}

class SomeClass
{
public:
	static void StaticMethodHandler(WindowEventArgs& args)
	{
		std::cout << "StaticMethodHandler:\n" << "x=" << args.x << ", y=" << args.y << "\n\n";
	}

	void MethodHandler(WindowEventArgs& args)
	{
		std::cout << "MethodHandler:\n" << "x=" << args.x << ", y=" << args.y << "\n\n";
	}
};

class MyApp : public vt::Application
{
public:
	MyApp()
	{
	}

	void Run() override
	{
		std::cout << "Hello MyApp!\n\n";

		Window window;
		WindowEventArgs args = { 1, 2 };
		window.OnButtonClicked += new vt_event::FunctionHandler<WindowEventArgs&>(FunctionHandler);
		window.OnButtonClicked += new vt_event::LambdaHandler<WindowEventArgs&>([](WindowEventArgs& args)
			{std::cout << "LambdaHandler:\n" << "x=" << args.x << ", y=" << args.y << "\n\n"; });
		window.OnButtonClicked += new vt_event::StaticMethodHandler<WindowEventArgs&>(SomeClass::StaticMethodHandler);
		SomeClass sc;
		window.OnButtonClicked += new vt_event::MethodHandler<SomeClass, WindowEventArgs&>(sc, &SomeClass::MethodHandler);
		window.OnButtonClicked(args);
	}
};

IMPLEMENT_APP(MyApp)