#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"

ModuleCollision::ModuleCollision()
{
	for(uint i = 0; i < MAX_COLLIDERS; ++i)
		colliders[i] = nullptr;
	matrix[COLLIDER_NONE][COLLIDER_STRUCTURE] = false;
	matrix[COLLIDER_NONE][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_NONE][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_NONE][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_NONE][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_NONE][COLLIDER_PLAYER_NOSHOT] = false;
	matrix[COLLIDER_NONE][COLLIDER_DESTRUCT] = false;
	matrix[COLLIDER_NONE][COLLIDER_DYNAMITE] = false;
	matrix[COLLIDER_NONE][COLLIDER_POINTS] = false;
	matrix[COLLIDER_NONE][COLLIDER_NONE] = false;
	matrix[COLLIDER_NONE][COLLIDER_BOMB_EXPLOSION] = false;

	matrix[COLLIDER_STRUCTURE][COLLIDER_STRUCTURE] = false;
	matrix[COLLIDER_STRUCTURE][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_STRUCTURE][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_STRUCTURE][COLLIDER_PLAYER_SHOT] = true;
	matrix[COLLIDER_STRUCTURE][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_STRUCTURE][COLLIDER_PLAYER_NOSHOT] = false;
	matrix[COLLIDER_STRUCTURE][COLLIDER_DESTRUCT] = false;
	matrix[COLLIDER_STRUCTURE][COLLIDER_DYNAMITE] = false;
	matrix[COLLIDER_STRUCTURE][COLLIDER_POINTS] = false;
	matrix[COLLIDER_STRUCTURE][COLLIDER_NONE] = false;
	matrix[COLLIDER_STRUCTURE][COLLIDER_BOMB] = false;
	matrix[COLLIDER_STRUCTURE][COLLIDER_BOMB_EXPLOSION] = false;

	matrix[COLLIDER_PLAYER][COLLIDER_STRUCTURE] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_ENEMY_SHOT] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_PLAYER_NOSHOT] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_DESTRUCT] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_DYNAMITE] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_POINTS] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_NONE] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_BOMB] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_BOMB_EXPLOSION] = true;

	matrix[COLLIDER_ENEMY][COLLIDER_STRUCTURE] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_PLAYER_SHOT] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_PLAYER_NOSHOT] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_DESTRUCT] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_DYNAMITE] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_POINTS] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_NONE] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_BOMB] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_BOMB_EXPLOSION] = false;

	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_STRUCTURE] = true;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_ENEMY_SHOT] = true;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_PLAYER_NOSHOT] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_DESTRUCT] = true;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_DYNAMITE] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_POINTS] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_NONE] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_BOMB] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_BOMB_EXPLOSION] = false;

	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_STRUCTURE] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_PLAYER_NOSHOT] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_DESTRUCT] = true;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_NONE] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_DYNAMITE] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_POINTS] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_NONE] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_BOMB] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_BOMB_EXPLOSION] = false;

	matrix[COLLIDER_PLAYER_NOSHOT][COLLIDER_STRUCTURE] = false;
	matrix[COLLIDER_PLAYER_NOSHOT][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_PLAYER_NOSHOT][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_PLAYER_NOSHOT][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_PLAYER_NOSHOT][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_PLAYER_NOSHOT][COLLIDER_PLAYER_NOSHOT] = false;
	matrix[COLLIDER_PLAYER_NOSHOT][COLLIDER_DESTRUCT] = false;
	matrix[COLLIDER_PLAYER_NOSHOT][COLLIDER_DYNAMITE] = false;
	matrix[COLLIDER_PLAYER_NOSHOT][COLLIDER_POINTS] = false;
	matrix[COLLIDER_PLAYER_NOSHOT][COLLIDER_NONE] = false;
	matrix[COLLIDER_PLAYER_NOSHOT][COLLIDER_BOMB] = false;
	matrix[COLLIDER_PLAYER_NOSHOT][COLLIDER_BOMB_EXPLOSION] = false;

	matrix[COLLIDER_DESTRUCT][COLLIDER_STRUCTURE] = false;
	matrix[COLLIDER_DESTRUCT][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_DESTRUCT][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_DESTRUCT][COLLIDER_PLAYER_SHOT] = true;
	matrix[COLLIDER_DESTRUCT][COLLIDER_ENEMY_SHOT] = true;
	matrix[COLLIDER_DESTRUCT][COLLIDER_PLAYER_NOSHOT] = false;
	matrix[COLLIDER_DESTRUCT][COLLIDER_DESTRUCT] = false;
	matrix[COLLIDER_DESTRUCT][COLLIDER_DYNAMITE] = false;
	matrix[COLLIDER_DESTRUCT][COLLIDER_POINTS] = false;
	matrix[COLLIDER_DESTRUCT][COLLIDER_NONE] = false;
	matrix[COLLIDER_DESTRUCT][COLLIDER_BOMB] = false;
	matrix[COLLIDER_DESTRUCT][COLLIDER_BOMB_EXPLOSION] = true;

	matrix[COLLIDER_DYNAMITE][COLLIDER_NONE] = false;
	matrix[COLLIDER_DYNAMITE][COLLIDER_PLAYER_NOSHOT] = false;
	matrix[COLLIDER_DYNAMITE][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_DYNAMITE][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_DYNAMITE][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_DYNAMITE][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_DYNAMITE][COLLIDER_STRUCTURE] = false;
	matrix[COLLIDER_DYNAMITE][COLLIDER_DYNAMITE] = false;
	matrix[COLLIDER_DYNAMITE][COLLIDER_DESTRUCT] = false;
	matrix[COLLIDER_DYNAMITE][COLLIDER_POINTS] = false;
	matrix[COLLIDER_DYNAMITE][COLLIDER_NONE] = false;
	matrix[COLLIDER_DYNAMITE][COLLIDER_BOMB] = false;
	matrix[COLLIDER_DYNAMITE][COLLIDER_BOMB_EXPLOSION] = false;

	matrix[COLLIDER_POINTS][COLLIDER_NONE] = false;
	matrix[COLLIDER_POINTS][COLLIDER_PLAYER_NOSHOT] = false;
	matrix[COLLIDER_POINTS][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_POINTS][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_POINTS][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_POINTS][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_POINTS][COLLIDER_STRUCTURE] = false;
	matrix[COLLIDER_POINTS][COLLIDER_DYNAMITE] = false;
	matrix[COLLIDER_POINTS][COLLIDER_DESTRUCT] = false;
	matrix[COLLIDER_POINTS][COLLIDER_POINTS] = false;
	matrix[COLLIDER_POINTS][COLLIDER_BOMB] = false;
	matrix[COLLIDER_POINTS][COLLIDER_BOMB_EXPLOSION] = false;

	matrix[COLLIDER_BOMB][COLLIDER_STRUCTURE] = false;
	matrix[COLLIDER_BOMB][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_BOMB][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_BOMB][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_BOMB][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_BOMB][COLLIDER_PLAYER_NOSHOT] = false;
	matrix[COLLIDER_BOMB][COLLIDER_DESTRUCT] = false;
	matrix[COLLIDER_BOMB][COLLIDER_NONE] = false;
	matrix[COLLIDER_BOMB][COLLIDER_DYNAMITE] = false;
	matrix[COLLIDER_BOMB][COLLIDER_POINTS] = false;
	matrix[COLLIDER_BOMB][COLLIDER_NONE] = false;
	matrix[COLLIDER_BOMB][COLLIDER_BOMB_EXPLOSION] = false;

	matrix[COLLIDER_BOMB_EXPLOSION][COLLIDER_STRUCTURE] = false;
	matrix[COLLIDER_BOMB_EXPLOSION][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_BOMB_EXPLOSION][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_BOMB_EXPLOSION][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_BOMB_EXPLOSION][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_BOMB_EXPLOSION][COLLIDER_PLAYER_NOSHOT] = false;
	matrix[COLLIDER_BOMB_EXPLOSION][COLLIDER_DESTRUCT] = true;
	matrix[COLLIDER_BOMB_EXPLOSION][COLLIDER_NONE] = false;
	matrix[COLLIDER_BOMB_EXPLOSION][COLLIDER_DYNAMITE] = false;
	matrix[COLLIDER_BOMB_EXPLOSION][COLLIDER_POINTS] = false;
	matrix[COLLIDER_BOMB_EXPLOSION][COLLIDER_NONE] = false;
	matrix[COLLIDER_BOMB_EXPLOSION][COLLIDER_BOMB] = false;
}

// Destructor
ModuleCollision::~ModuleCollision()
{}

update_status ModuleCollision::PreUpdate()
{
	// Remove all colliders scheduled for deletion
	for(uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if(colliders[i] != nullptr && colliders[i]->to_delete == true)
		{
			delete colliders[i];
			colliders[i] = nullptr;
		}
	}

	return UPDATE_CONTINUE;
}

// Called before render is available
update_status ModuleCollision::Update()
{
	Collider* c1;
	Collider* c2;

	for(uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		// skip empty colliders
		if(colliders[i] == nullptr)
			continue;

		c1 = colliders[i];

		// avoid checking collisions already checked
		for(uint k = i+1; k < MAX_COLLIDERS; ++k)
		{
			// skip empty colliders
			if(colliders[k] == nullptr)
				continue;

			c2 = colliders[k];

			if(c1->CheckCollision(c2->rect) == true)
			{
				if(matrix[c1->type][c2->type] && c1->callback) 
					c1->callback->OnCollision(c1, c2);
				
				if(matrix[c2->type][c1->type] && c2->callback) 
					c2->callback->OnCollision(c2, c1);
			}
		}
	}
	DebugDraw();

	return UPDATE_CONTINUE;
}


void ModuleCollision::DebugDraw()
{
	if(App->input->keyboard[SDL_SCANCODE_F1] == KEY_DOWN)
		debug = !debug;

	if(debug == false)
		return;

	Uint8 alpha = 80;
	for(uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if(colliders[i] == nullptr)
			continue;
		
		switch(colliders[i]->type)
		{
			case COLLIDER_NONE: // white
			App->render->DrawQuad(colliders[i]->rect, 255, 255, 255, alpha);
			break;
			case COLLIDER_STRUCTURE: // blue
			App->render->DrawQuad(colliders[i]->rect, 0, 0, 255, alpha);
			break;
			case COLLIDER_PLAYER: // green
			App->render->DrawQuad(colliders[i]->rect, 0, 255, 0, alpha);
			break;
			case COLLIDER_ENEMY: // red
			App->render->DrawQuad(colliders[i]->rect, 255, 0, 0, alpha);
			break;
			case COLLIDER_PLAYER_SHOT: // yellow
			App->render->DrawQuad(colliders[i]->rect, 255, 255, 0, alpha);
			break;
			case COLLIDER_ENEMY_SHOT: // magenta
			App->render->DrawQuad(colliders[i]->rect, 0, 255, 255, alpha);
			break;
			case COLLIDER_DESTRUCT: // Pink
			App->render->DrawQuad(colliders[i]->rect, 255, 0, 255, alpha);
			break;
			case COLLIDER_DYNAMITE: // Gray
			App->render->DrawQuad(colliders[i]->rect, 125, 125, 125, alpha);
			break;
			case COLLIDER_POINTS: // Dark green
			App->render->DrawQuad(colliders[i]->rect, 100, 155, 100, alpha);
			break;
			case COLLIDER_BOMB: // Dark green
			App->render->DrawQuad(colliders[i]->rect, 100, 155, 100, alpha);
			break;
			case COLLIDER_BOMB_EXPLOSION: // Dark green
			App->render->DrawQuad(colliders[i]->rect, 100, 155, 100, alpha);
			break;
		}
	}
}

// Called before quitting
bool ModuleCollision::CleanUp()
{
	LOG("Freeing all colliders");

	for(uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if(colliders[i] != nullptr)
		{
			delete colliders[i];
			colliders[i] = nullptr;
		}
	}

	return true;
}

Collider* ModuleCollision::AddCollider(SDL_Rect rect, COLLIDER_TYPE type, Module* callback)
{
	Collider* ret = nullptr;

	for(uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if(colliders[i] == nullptr)
		{
			ret = colliders[i] = new Collider(rect, type, callback);
			break;
		}
	}

	return ret;
}

bool ModuleCollision::EraseCollider(Collider* collider)
{
	for(uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if(colliders[i] == collider)
		{
			
			colliders[i] = nullptr;
			return true;
		}
	}

	return false;
}

bool Collider::CheckCollision(const SDL_Rect& r) const
{
	return (rect.x < r.x + r.w &&
			rect.x + rect.w > r.x &&
			rect.y < r.y + r.h &&
			rect.h + rect.y > r.y);
}