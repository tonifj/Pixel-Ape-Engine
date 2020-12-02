//Modules
#include "ModuleWindow.h"
#include "ModuleResources.h"
#include "ModuleInput.h"
#include "ModuleRenderer.h"

#include "Application.h"


Application::Application()
{
	modules.push_back(window = new ModuleWindow());
	modules.push_back(renderer = new ModuleRenderer());
	modules.push_back(resources = new ModuleResources());

	modules.push_back(input = new ModuleInput());

}

Application::~Application()
{
	for (std::vector<Module*>::iterator it = modules.begin(); it != modules.end(); ++it)
	{
		delete *it;
	}
}

bool Application::Init()
{
	bool result = true;

	for (auto& module : modules)
	{
		bool ret = module->Init(); //return false if some module initializes wrongly
		if (!ret) {
			result = ret;
		}
	}
	return result;
}

update_status Application::Update()
{
	update_status result = update_status::UPDATE_CONTINUE;

	for (auto& module : modules)
	{
		update_status ret = module->PreUpdate();
		if (ret == update_status::UPDATE_ERROR || ret == update_status::UPDATE_STOP) {
			result = ret;
		}
	}

	for (auto& module : modules)
	{
		update_status ret = module->Update();
		if (ret == update_status::UPDATE_ERROR || ret == update_status::UPDATE_STOP) {
			result = ret;
		}
	}

	for (auto& module : modules)
	{
		update_status ret = module->PostUpdate();
		if (ret == update_status::UPDATE_ERROR || ret == update_status::UPDATE_STOP) {
			result = ret;
		}
	}
	return result;
}

bool Application::CleanUp()
{
	bool result = true;
	for (auto& module : modules)
	{
		bool ret = module->CleanUp();
		if (!ret) {
			return result;
		}
	}
	return result;
}