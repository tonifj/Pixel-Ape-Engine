#ifndef _MODULEINPUT_H
#define _MODULEINPUT_H

#include "Module.h"

class ModuleInput : public Module {

public:

	ModuleInput();
	~ModuleInput();
	bool Init() override;

	update_status PreUpdate() override;
	update_status Update() override;
	update_status PostUpdate() override;

private:
	bool quit = false;
	bool up = false, down = false, left = false, right = false;
};
#endif