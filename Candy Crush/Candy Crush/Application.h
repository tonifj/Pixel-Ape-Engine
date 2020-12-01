#ifndef _APPLICATION_H
#define _APPLICATION_H
#include "Globals.h"
#include "Module.h";


#include <vector>
class ModuleWindow;
class ModuleResources;

class Application {


public:
	
	//Load every module
	Application();

	//Destroy every module
	~Application();

	//Call to every module's init
	bool Init();
	update_status Update();
	bool CleanUp();

	ModuleWindow* window = nullptr;
	ModuleResources* resources = nullptr;

private:
	
	std::vector<Module*> modules;
	

};

extern Application* App;
#endif
