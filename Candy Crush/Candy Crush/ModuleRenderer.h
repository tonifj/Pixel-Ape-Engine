#ifndef _MODULERENDERER_H
#define _MODULERENDERER_H
#include "Module.h"


class ModuleRenderer : public Module {
public:
	ModuleRenderer();
	~ModuleRenderer();
	bool Init() override;
	update_status PreUpdate() override;
	update_status Update() override;
	update_status PostUpdate() override;
	bool CleanUp() override;

	SDL_Renderer* GetRenderer();

private:
	SDL_Renderer* renderer = nullptr;

};

#endif;
