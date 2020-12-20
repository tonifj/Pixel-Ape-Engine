#ifndef _MODULEINPUT_H
#define _MODULEINPUT_H

#include "Module.h"
#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"

class ModuleInput : public Module {

public:

	ModuleInput();
	~ModuleInput();
	bool Init() override;

	update_status PreUpdate() override;
	update_status Update() override;
	update_status PostUpdate() override;
	ImGuiIO io;

private:
	bool quit = false;
	bool up = false, down = false, left = false, right = false;
};
#endif