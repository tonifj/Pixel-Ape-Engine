#ifndef _APPLICATION_H
#define _APPLICATION_H
#include "Globals.h"
#include "Module.h";


#include <vector>
class ModuleWindow;
class ModuleResources;
class ModuleInput;
class ModuleRenderer;

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
	ModuleInput* input = nullptr;
	ModuleRenderer* renderer = nullptr;

private:
	
	std::vector<Module*> modules;
	

};

extern Application* App;
#endif
