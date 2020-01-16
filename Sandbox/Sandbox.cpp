#include <VisualTool.h>

class MyApp : public vt::Application
{
public:
	void Run() override
	{
		std::cout << "Hello MyApp!\n";
	}
};

IMPLEMENT_APP(MyApp)