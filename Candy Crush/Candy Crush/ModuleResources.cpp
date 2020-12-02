#include "ModuleResources.h"
#include "ModuleWindow.h"
#include <SDL_image.h>

#include "Application.h"
using namespace std;

ModuleResources::ModuleResources() {}
ModuleResources::~ModuleResources()
{

}

bool ModuleResources::Init()
{
	cout << "Initializing Module Resources..." << endl;

	//Initializing SDL_IMAGE
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
		cout << "SDL_image could not initialize! " << IMG_GetError() << endl;



	LoadResource(ResourceType::BITMAP, "../resources/img/hello_world.bmp", "test_img");
	
	LoadResource(ResourceType::PNG, "../resources/img/image.png", "png_test");


	cout << "Module Resources Initialized" << endl;


	return true;
}

update_status ModuleResources::PreUpdate() {
	return update_status::UPDATE_CONTINUE;
}

update_status ModuleResources::Update() {
	return update_status::UPDATE_CONTINUE;
}

update_status ModuleResources::PostUpdate() {
	return update_status::UPDATE_CONTINUE;
}

bool ModuleResources::LoadResource(ResourceType type, std::string path, std::string id)
{

	//Loading success flag
	bool success = true;

	switch (type)
	{

	case ResourceType::BITMAP:
	{
		SDL_Surface* bmp = SDL_LoadBMP(path.c_str());
		if (bmp == NULL)
		{
			cout << "Unable to load image with path: " << path << endl;
			success = false;
		}

		else
		{
			bitmaps[id] = bmp;
		}
	}
	break;

	case ResourceType::PNG:
	{
		//The final optimized image
		SDL_Surface* optimizedSurface = NULL;

		//Load image at specified path
		SDL_Surface* loadedSurface = IMG_Load(path.c_str());
		if (loadedSurface == NULL)
		{
			cout << "Unable to load image with path: " << path << endl;
			success = false;
		}
		else
		{
			//optimizedSurface = SDL_ConvertSurface(loadedSurface, App->window->GetSurface()->format, 0);
			pngs[id] = loadedSurface;
		}
	}
	break;

	}

	return success;
}

SDL_Surface* ModuleResources::GetBitmap(std::string id)
{
	return bitmaps[id];
}

SDL_Surface* ModuleResources::GetPNG(std::string id)
{
	return pngs[id];
}





