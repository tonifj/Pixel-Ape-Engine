#include "ModuleWindow.h"
#include "ModuleResources.h"

#include "Application.h"

using namespace std;

ModuleWindow::ModuleWindow() {}
ModuleWindow::~ModuleWindow()
{
	//Destroy window
	SDL_DestroyWindow(window);
}

bool ModuleWindow::Init()
{
	cout << "Initializing Module Window..." << endl;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
		return false;
	}

	else //Create window
	{
		window = SDL_CreateWindow("Candy Crush", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
			return false;
		}

		else
		{
			//Get window surface
			window_surface = SDL_GetWindowSurface(window);

			//Fill the surface white
			SDL_FillRect(window_surface, NULL, SDL_MapRGB(window_surface->format, 0xFF, 0xFF, 0xFF));

			//Update the surface
			//SDL_BlitSurface(App->resources->GetPNG("png_test"), NULL, window_surface, NULL);
			SDL_UpdateWindowSurface(window);

		}
	}
	cout << "Module Window Initialized" << endl;

	return true;
}

update_status ModuleWindow::PreUpdate() {
	return update_status::UPDATE_CONTINUE;
}

update_status ModuleWindow::Update() {
	return update_status::UPDATE_CONTINUE;
}

update_status ModuleWindow::PostUpdate() {
	//Update the surface
	
	//SDL_UpdateWindowSurface(window);
	return update_status::UPDATE_CONTINUE;
}

bool ModuleWindow::CleanUp() {
	//Destroy window
	if (window != NULL)
	{
		SDL_DestroyWindow(window);
		SDL_FreeSurface(window_surface);
	}

	//Quit SDL subsystems
	SDL_Quit();
	return true;

}

SDL_Window* ModuleWindow::GetWindow()
{
	return window;
}







