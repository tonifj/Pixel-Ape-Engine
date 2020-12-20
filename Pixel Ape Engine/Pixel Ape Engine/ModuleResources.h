#ifndef _MODULERESOURCES_H
#define _MODULERESOURCES_H

#include "Module.h"
#include <unordered_map>
#include <string>

enum class ResourceType {
	BITMAP,
	PNG,
	TEXTURE
};

class ModuleResources : public Module {

public:

	ModuleResources();
	~ModuleResources();
	bool Init() override;

	update_status PreUpdate() override;
	update_status Update() override;
	update_status PostUpdate() override;

	//Get images with format bitmap
	SDL_Surface* GetBitmap(std::string id);
	SDL_Surface* GetPNG(std::string id);
	SDL_Texture* GetTexture(std::string id);

	

private:
	 bool LoadResource(ResourceType type, std::string path, std::string id);

	std::unordered_map<std::string, SDL_Surface*> bitmaps = {};
	std::unordered_map<std::string, SDL_Surface*> pngs = {};
	std::unordered_map<std::string, SDL_Texture*> textures = {};



};
#endif