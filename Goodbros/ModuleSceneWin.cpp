#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneFirst.h"
#include "ModuleSceneWin.h"
#include "ModuleAudio.h"
#include "SDL\include\SDL.h"

ModuleSceneWin::ModuleSceneWin()
{}

ModuleSceneWin::~ModuleSceneWin()
{}

// Load assets
bool ModuleSceneWin::Start()
{
	LOG("Loading game intro");
	ticks = SDL_GetTicks();
	background = App->textures->Load("bloodbros/win_scene.png");
	App->audio->Load("bloodbros/Victory.ogg");
	App->render->camera.x = App->render->camera.y = 0;

	return true;
}

// UnLoad assets
bool ModuleSceneWin::CleanUp()
{
	LOG("Unloading game scene");
	App->textures->Unload(background);
	//App->audio->Disable();
	return true;
}

// Update: draw background
update_status ModuleSceneWin::Update()
{
	App->render->Blit(background, 0, 0, NULL);

	if (SDL_GetTicks() - ticks > 6000){
		App->fade->FadeToBlack(this, (Module*)App->scene_intro);
	}
	return UPDATE_CONTINUE;
}