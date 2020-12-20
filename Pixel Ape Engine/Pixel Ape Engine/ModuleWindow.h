#ifndef _MODULEWINDOW_H
#define _MODULEWINDOW_H
#include "Module.h"

class ModuleResources;

class ModuleWindow : public Module{
public:
	ModuleWindow();
	~ModuleWindow();
	bool Init() override;
	update_status PreUpdate() override;
	update_status Update() override;
	update_status PostUpdate() override;
	bool CleanUp() override;


	SDL_Window* GetWindow();
	SDL_Surface* GetSurface();

	unsigned width = 640;
	unsigned height = 480;
private:
	//Create window where to render
	SDL_Window* window = nullptr;

	//Surface contained by the window
	SDL_Surface* window_surface = nullptr;

	//Scren dimensions


};

#endif;
