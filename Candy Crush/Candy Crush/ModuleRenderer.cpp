#include "ModuleRenderer.h"
#include "ModuleResources.h"
#include "ModuleWindow.h"

#include "Application.h"

using namespace std;

ModuleRenderer::ModuleRenderer() {}
ModuleRenderer::~ModuleRenderer()
{

}

bool ModuleRenderer::Init()
{
	cout << "Initializing Module Renderer..." << endl;

	renderer = SDL_CreateRenderer(App->window->GetWindow(), -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		return false;
	}
	else
	{
		//Initialize renderer color
		SDL_SetRenderDrawColor(renderer, 200, 100, 0, 1);
	}

	cout << "Module Renderer Initialized" << endl;

	return true;
}

update_status ModuleRenderer::PreUpdate() {
	//Clear screen
	SDL_RenderClear(renderer);
	return update_status::UPDATE_CONTINUE;
}

update_status ModuleRenderer::Update() {
	//Render texture to screen
	SDL_RenderCopy(renderer, App->resources->GetTexture("texture"), NULL, NULL);
	return update_status::UPDATE_CONTINUE;
}

update_status ModuleRenderer::PostUpdate() {

	//Update screen
	SDL_RenderPresent(renderer);
	return update_status::UPDATE_CONTINUE;
}

bool ModuleRenderer::CleanUp() {


	return true;

}

SDL_Renderer* ModuleRenderer::GetRenderer()
{
	return renderer;
}







