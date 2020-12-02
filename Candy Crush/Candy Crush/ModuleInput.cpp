#include "ModuleInput.h"


using namespace std;

ModuleInput::ModuleInput() {}
ModuleInput::~ModuleInput()
{

}

bool ModuleInput::Init()
{
	cout << "Initializing Module Input..." << endl;
	cout << "Module Input Initialized" << endl;


	return true;
}

update_status ModuleInput::PreUpdate() {
	//Handle events on queue
	//While application is running
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0)
	{
		//User requests quit
		if (e.type == SDL_QUIT)
		{
			SDL_Quit();
			return update_status::UPDATE_STOP;
		}

		else if (e.type == SDL_KEYDOWN)
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_UP:
				up = true;
				break;
			case SDLK_DOWN:
				down = true;
				break;
			case SDLK_LEFT:
				left = true;
				break;
			case SDLK_RIGHT:
				right = true;
				break;
			}
		}

		else if (e.type == SDL_KEYUP)
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_UP:
				up = false;
				break;
			case SDLK_DOWN:
				down = false;
				break;
			case SDLK_LEFT:
				left = false;
				break;
			case SDLK_RIGHT:
				right = false;
				break;
			}
		}
	}
	return update_status::UPDATE_CONTINUE;
}

update_status ModuleInput::Update() {
	
	return update_status::UPDATE_CONTINUE;
}

update_status ModuleInput::PostUpdate() {
	return update_status::UPDATE_CONTINUE;
}






