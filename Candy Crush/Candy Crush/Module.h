#ifndef _MODULE_H
#define _MODULE_H
#include <SDL.h>
#include <iostream>
#include "Globals.h"

class Module {

public:

	Module() = default;
	update_status status;
	virtual bool Init() {
		return true;
	}

	virtual update_status PreUpdate()
	{
		return update_status::UPDATE_CONTINUE;
	}

	virtual update_status Update()
	{
		return update_status::UPDATE_CONTINUE;
	}

	virtual update_status PostUpdate()
	{
		return update_status::UPDATE_CONTINUE;
	}

	virtual bool CleanUp() {
		return true;
	}

};
#endif