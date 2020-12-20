#include "ModuleRenderer.h"
#include "ModuleResources.h"
#include "ModuleWindow.h"
#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"

#include "Application.h"

#if defined(IMGUI_IMPL_OPENGL_LOADER_GL3W)
#include <GL/gl3w.h>            // Initialize with gl3wInit()
#elif defined(IMGUI_IMPL_OPENGL_LOADER_GLEW)
#include <glew.h>				// Initialize with glewInit()
#elif defined(IMGUI_IMPL_OPENGL_LOADER_GLAD)
#include <glad/glad.h>          // Initialize with gladLoadGL()
#elif defined(IMGUI_IMPL_OPENGL_LOADER_GLAD2)
#include <glad/gl.h>            // Initialize with gladLoadGL(...) or gladLoaderLoadGL()
#elif defined(IMGUI_IMPL_OPENGL_LOADER_GLBINDING2)
#define GLFW_INCLUDE_NONE       // GLFW including OpenGL headers causes ambiguity or multiple definition errors.
#include <glbinding/Binding.h>  // Initialize with glbinding::Binding::initialize()
#include <glbinding/gl/gl.h>
using namespace gl;
#elif defined(IMGUI_IMPL_OPENGL_LOADER_GLBINDING3)
#define GLFW_INCLUDE_NONE       // GLFW including OpenGL headers causes ambiguity or multiple definition errors.
#include <glbinding/glbinding.h>// Initialize with glbinding::initialize()
#include <glbinding/gl/gl.h>
using namespace gl;

#endif

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
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
		SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

		context = SDL_GL_CreateContext(App->window->GetWindow());
		SDL_GL_MakeCurrent(App->window->GetWindow(), context);
		SDL_GL_SetSwapInterval(1); // Enable vsync

		if (glewInit() != GLEW_OK)
		{
			SDL_Log("Failed to init GLEW");
		}

		else
		{
			IMGUI_CHECKVERSION();
			ImGui::CreateContext();
			ImGui::StyleColorsDark();
			ImGui_ImplSDL2_InitForOpenGL(App->window->GetWindow(), context);
			ImGui_ImplOpenGL3_Init("#version 150");
		}

		//Initialize renderer color
		//SDL_SetRenderDrawColor(renderer, 200, 100, 0, 1);
	}

	cout << "Module Renderer Initialized" << endl;

	return true;
}

update_status ModuleRenderer::PreUpdate() {
	//Clear screen
	//SDL_RenderClear(renderer);

	ImGui::NewFrame();


	return update_status::UPDATE_CONTINUE;
}

update_status ModuleRenderer::Update() {
	//Render texture to screen
	//SDL_RenderCopy(renderer, App->resources->GetTexture("texture"), NULL, NULL);

	ImGui::ShowDemoWindow(&show_demo_window);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	return update_status::UPDATE_CONTINUE;
}

update_status ModuleRenderer::PostUpdate() {

	//Update screen
	//SDL_RenderPresent(renderer);

	ImGui::Render();
	glViewport(0, 0, App->window->width, App->window->height);
	glClearColor(0.1, 0.1, 0.1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	SDL_GL_SwapWindow(App->window->GetWindow());
	return update_status::UPDATE_CONTINUE;
}

bool ModuleRenderer::CleanUp() {
	
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();

	SDL_GL_DeleteContext(context);
	SDL_Quit();
	return true;

}

SDL_Renderer* ModuleRenderer::GetRenderer()
{
	return renderer;
}







