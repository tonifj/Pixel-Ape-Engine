#include "ModuleResources.h"


using namespace std;

ModuleResources::ModuleResources() {}
ModuleResources::~ModuleResources()
{

}

bool ModuleResources::Init()
{
	cout << "Initializing Module Resources..." << endl;

	LoadResource(ResourceType::BITMAP, "../resources/img/hello_world.bmp", "test_img");

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
			bitmaps[id] = bmp;
			return success;
		}
	}


}

 SDL_Surface* ModuleResources::GetBitmap(std::string id)
{ 
	return bitmaps[id]; 
}





