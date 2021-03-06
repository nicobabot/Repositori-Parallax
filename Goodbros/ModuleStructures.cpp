#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "Animation.h"
#include "ModuleFadeToBlack.h"
#include "ModuleScenefirst.h"
#include "ModuleAudio.h"
#include "ModuleStructures.h"
#include "Module_Points.h"
#include "ModuleEnemies.h"
#include "SDL/include/SDL_timer.h"

Structure::Structure()
{
	position.SetToZero();
}

Structure::Structure(const Structure& p) :
Coll_Struct(p.Coll_Struct), position(p.position),
fx(p.fx), mytype(p.mytype), destroy(p.destroy)
{}

Structure::~Structure(){
	if (collider != nullptr)
	{
		App->collision->EraseCollider(collider);
	}
}

bool Structure::Update()
{
	bool ret = true;

	return ret;
}

ModuleStructures::ModuleStructures()
{
	for (uint i = 0; i < MAX_BUILDINGS; ++i)
		active[i] = nullptr;
}

ModuleStructures::~ModuleStructures()
{
	if (bar.collider != nullptr)
	{
		App->collision->EraseCollider(bar.collider);
	}
	if (inn.collider != nullptr)
	{
		App->collision->EraseCollider(inn.collider);
	}
	if (barrel.collider != nullptr)
	{
		App->collision->EraseCollider(barrel.collider);
	}
}

// Load assets
bool ModuleStructures::Start()
{
	LOG("Loading buildings");
	graphics = App->textures->Load("bloodbros/enemy.png");

	/* Column
	column.Coll_Struct.x = 623;
	column.Coll_Struct.y = 2352;
	column.Coll_Struct.w = 98;
	column.Coll_Struct.h = 56;
	column.mytype = BARRELROL;

	column.destroy.PushBack({ 623, 2352, 98, 56 });
	column.destroy.PushBack({ 623, 2352, 98, 41 });
	column.destroy.PushBack({ 623, 2352, 98, 26 });
	column.destroy.PushBack({ 623, 2352, 98, 11 });
	column.destroy.PushBack({ 623, 2352, 98, 0 });
	column.destroy.loop = false;
	column.destroy.speed = 0.05f;*/

	// BAR
	bar.Coll_Struct.x = 80;
	bar.Coll_Struct.y = 2266;
	bar.Coll_Struct.w = 115;
	bar.Coll_Struct.h = 147;
	bar.mytype = BAR;

	bar2.Coll_Struct.x = 218;
	bar2.Coll_Struct.y = 2266;
	bar2.Coll_Struct.w = 115;
	bar2.Coll_Struct.h = 147;

	bar3.Coll_Struct.x = 345;
	bar3.Coll_Struct.y = 2266;
	bar3.Coll_Struct.w = 115;
	bar3.Coll_Struct.h = 147;

	bar4.Coll_Struct.x = 490;
	bar4.Coll_Struct.y = 2266;
	bar4.Coll_Struct.w = 115;
	bar4.Coll_Struct.h = 147;

	bar.destroy.PushBack({ 490, 2266, 115, 147 });
	bar.destroy.PushBack({ 490, 2266, 115, 128 });
	bar.destroy.PushBack({ 490, 2266, 115, 116 });
	bar.destroy.PushBack({ 490, 2266, 115, 110 });
	bar.destroy.PushBack({ 490, 2266, 115, 99 });
	bar.destroy.PushBack({ 490, 2266, 115, 87 });
	bar.destroy.PushBack({ 490, 2266, 115, 74 });
	bar.destroy.PushBack({ 490, 2266, 115, 60 });
	bar.destroy.PushBack({ 490, 2266, 115, 49 });
	bar.destroy.PushBack({ 490, 2266, 115, 32 });
	bar.destroy.PushBack({ 490, 2266, 115, 20 });
	bar.destroy.PushBack({ 490, 2266, 115, 12 });
	bar.destroy.PushBack({ 490, 2266, 115, 4 });
	bar.destroy.loop = false;
	bar.destroy.speed = 0.031f;

	// GREY BUILDING
	inn.Coll_Struct.x = 91;
	inn.Coll_Struct.y = 2150;
	inn.Coll_Struct.w = 105;
	inn.Coll_Struct.h = 92;
	inn.mytype = INN;

	// HOTEL
	hotel.Coll_Struct.x = 203;
	hotel.Coll_Struct.y = 2151;
	hotel.Coll_Struct.w = 72;
	hotel.Coll_Struct.h = 90;
	hotel.mytype = HOTEL;

	// FABTEN
	fabten.Coll_Struct.x = 77;
	fabten.Coll_Struct.y = 2548;
	fabten.Coll_Struct.w = 105;
	fabten.Coll_Struct.h = 138;
	fabten.mytype = FABTEN;

	fabten2.Coll_Struct.x = 198;
	fabten2.Coll_Struct.y = 2548;
	fabten2.Coll_Struct.w = 105;
	fabten2.Coll_Struct.h = 138;

	fabten3.Coll_Struct.x = 332;
	fabten3.Coll_Struct.y = 2548;
	fabten3.Coll_Struct.w = 105;
	fabten3.Coll_Struct.h = 138;

	fabten4.Coll_Struct.x = 469;
	fabten4.Coll_Struct.y = 2548;
	fabten4.Coll_Struct.w = 105;
	fabten4.Coll_Struct.h = 138;

	fabten.destroy.PushBack({ 469, 2548, 105, 138 });
	fabten.destroy.PushBack({ 469, 2548, 105, 128 });
	fabten.destroy.PushBack({ 469, 2548, 105, 118 });
	fabten.destroy.PushBack({ 469, 2548, 105, 108 });
	fabten.destroy.PushBack({ 469, 2548, 105, 98 });
	fabten.destroy.PushBack({ 469, 2548, 105, 88 });
	fabten.destroy.PushBack({ 469, 2548, 105, 78 });
	fabten.destroy.PushBack({ 469, 2548, 105, 68 });
	fabten.destroy.PushBack({ 469, 2548, 105, 58 });
	fabten.destroy.PushBack({ 469, 2548, 105, 48 });
	fabten.destroy.PushBack({ 469, 2548, 105, 38 });
	fabten.destroy.PushBack({ 469, 2548, 105, 28 });
	fabten.destroy.PushBack({ 469, 2548, 105, 18 });
	fabten.destroy.loop = false;
	fabten.destroy.speed = 0.031f;

	// Smallest building
	smallest_b.Coll_Struct.x = 289;
	smallest_b.Coll_Struct.y = 2159;
	smallest_b.Coll_Struct.w = 71;
	smallest_b.Coll_Struct.h = 82;
	smallest_b.mytype = SMALLEST_B;

	// BARREL
	barrel.Coll_Struct.x = 69;
	barrel.Coll_Struct.y = 2710;
	barrel.Coll_Struct.w = 31;
	barrel.Coll_Struct.h = 49;
	barrel.mytype = BARREL;

	barrel2.Coll_Struct.x = 105;
	barrel2.Coll_Struct.y = 2710;
	barrel2.Coll_Struct.w = 31;
	barrel2.Coll_Struct.h = 49;
	barrel2.mytype = BARREL;

	barrel3.Coll_Struct.x = 139;
	barrel3.Coll_Struct.y = 2710;
	barrel3.Coll_Struct.w = 31;
	barrel3.Coll_Struct.h = 49;
	barrel3.mytype = BARREL;


	smallest_b.created = false;
	hotel.created = false;
	inn.created = false;

	App->structuresmiddle->cd1 = 0;
	App->structuresfront->cd1 = 0;
	App->structuresback->cd1 = 0;

	return true;
}

// Unload assets
bool ModuleStructures::CleanUp()
{
	LOG("Unloading particles");
	App->textures->Unload(graphics);

	for (uint i = 0; i < MAX_BUILDINGS; ++i)
	{
		if (active[i] != nullptr)
		{
			active[i] = nullptr;
		}
	}
	return true;
}

// Update: draw background
update_status ModuleStructures::Update()
{
	for (uint i = 0; i < MAX_BUILDINGS; ++i)
	{
		Structure* p = active[i];

		// STRUCTURES
		if (p == nullptr)
			continue;

		if (p->Update() == false)
		{
			p->collider->to_delete = true;
			delete p;
			active[i] = nullptr;
		}
		if (active[i]->hits < 4)
		{
			App->render->Blit(graphics, p->position.x, p->position.y, &p->Coll_Struct, 0);
		}
		if (active[i]->hits >= 4 && active[i]->mytype != BARREL && active[i]->mytype != INN)
		{
			if (App->particles->collapse.fx_played == false)
			{
				App->audio->PlayFx(App->particles->collapse.fx, 5500);
				App->particles->collapse.fx_played = true;
			}
			App->collision->EraseCollider(p->collider);
			if (p->position.y >= 120)
			{
				App->structuresmiddle->fabten.destroy.GetCurrentFrame();
				App->structuresmiddle->bar.destroy.GetCurrentFrame();
			}
			else
			{
				App->render->Blit(graphics, p->position.x, p->position.y += 0.33f, &p->destroy.GetCurrentFrame());
			}
			if (p->destroy.Finished() == true && active[i]->destroyed == false)
			{
				App->player->win_condition++;
				active[i]->destroyed = true;
			}
		}
		if (active[i]->hits >= 4 && active[i]->mytype == INN)
		{
			App->collision->EraseCollider(p->collider);
			App->render->Blit(graphics, p->position.x, p->position.y, &p->destroy.GetCurrentFrame());
			if (p->destroy.Finished() == true && active[i]->destroyed == false)
			{
				App->player->win_condition++;
				active[i]->destroyed = true;
			}
		}
		if (active[i]->hits == 2 && active[i]->mytype == BARREL)
		{
			App->render->Blit(graphics, p->position.x, p->position.y, &p->Coll_Struct, 0);
			p->collider->SetPos(p->position.x, p->position.y + 8);
			if (p->fx_played == false)
			{
				p->fx_played = true;
			}
		}
		if (active[i]->hits == 3 && active[i]->mytype == BARREL)
		{
			App->render->Blit(graphics, p->position.x, p->position.y, &p->Coll_Struct, 0);
			p->collider->SetPos(p->position.x, p->position.y + 23);
			if (p->fx_played == false)
			{
				p->fx_played = true;
			}
			App->collision->EraseCollider(p->collider);
		}
		if (active[i]->mytype == INN && cd1 == 1 && inn.created == false)
		{
			p->collider = App->collision->AddCollider({ p->position.x, p->position.y, p->Coll_Struct.w, p->Coll_Struct.h }, COLLIDER_STRUCTURE, this);
			inn.created = true;
		}
		if (active[i]->mytype == HOTEL && cd1 == 1 && hotel.created == false)
		{
			p->collider = App->collision->AddCollider({ p->position.x, p->position.y, p->Coll_Struct.w, p->Coll_Struct.h }, COLLIDER_STRUCTURE, this);
			hotel.created = true;
		}
		if (active[i]->mytype == SMALLEST_B && cd1 == 1 && smallest_b.created == false)
		{
			p->collider = App->collision->AddCollider({ p->position.x, p->position.y, p->Coll_Struct.w, p->Coll_Struct.h }, COLLIDER_STRUCTURE, this);
			smallest_b.created = true;
		}
	}
	return UPDATE_CONTINUE;
}

void ModuleStructures::AddStructure(Structure& particle, int x, int y)
{
	Structure* p = new Structure(particle);
	p->position.x = x;
	p->position.y = y;
	if (particle.mytype == BARREL)
	{
		p->collider = App->collision->AddCollider({ p->position.x, p->position.y, particle.Coll_Struct.w, particle.Coll_Struct.h }, COLLIDER_DESTRUCT, this);
	}
	else if ((particle.mytype == INN || particle.mytype == HOTEL || particle.mytype == SMALLEST_B) && fabten.destroyed == false)
	{
	}
	else if (particle.mytype != INN)
	{
		p->collider = App->collision->AddCollider({ p->position.x, p->position.y, particle.Coll_Struct.w, particle.Coll_Struct.h }, COLLIDER_STRUCTURE, this);
	}
	active[last_building++] = p;
}

const Collider* Structure::get_collider() const
{
	return collider;
}


void ModuleStructures::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_BUILDINGS; ++i)
	{
		// Bar
		if (active[i] != nullptr && active[i]->get_collider() == c1 && active[i]->mytype == BAR)
		{
			if (active[i]->hits == 0)
			{
				active[i]->Coll_Struct.x = bar2.Coll_Struct.x;
				active[i]->Coll_Struct.y = bar2.Coll_Struct.y;
				active[i]->Coll_Struct.w = bar2.Coll_Struct.w;
				active[i]->Coll_Struct.h = bar2.Coll_Struct.h;
				active[i]->hits++;
			}
			else if (active[i]->hits == 1)
			{
				active[i]->Coll_Struct.x = bar3.Coll_Struct.x;
				active[i]->Coll_Struct.y = bar3.Coll_Struct.y;
				active[i]->Coll_Struct.w = bar3.Coll_Struct.w;
				active[i]->Coll_Struct.h = bar3.Coll_Struct.h;
				active[i]->hits++;
			}
			else if (active[i]->hits == 2)
			{
				active[i]->Coll_Struct.x = bar4.Coll_Struct.x;
				active[i]->Coll_Struct.y = bar4.Coll_Struct.y;
				active[i]->Coll_Struct.w = bar4.Coll_Struct.w;
				active[i]->Coll_Struct.h = bar4.Coll_Struct.h;
				active[i]->hits++;
			}
			else if (active[i]->hits == 3)
			{
				App->points->AddEnemy(ENEMY_TYPES::POINTS, active[i]->position.x + 45, active[i]->position.y + 27, 10000, NULL);
				active[i]->hits++;
				App->smoke->AddParticle(App->particles->smoke, active[i]->position.x - 10, active[i]->position.y + 125, COLLIDER_NONE, 0);
				App->particles->collapse.fx_played = false;
				App->structuresback->cd1 += 0.5;
				App->structuresmiddle->bardest = true;
			}
		}

		/* Column
		if (active[i] != nullptr && active[i]->get_collider() == c1 && active[i]->mytype == COLUMN)
		{
			if (active[i]->hits == 0)
			{
				active[i]->Coll_Struct.x = column.Coll_Struct.x;
				active[i]->Coll_Struct.y = column.Coll_Struct.y;
				active[i]->Coll_Struct.w = column.Coll_Struct.w;
				active[i]->Coll_Struct.h = column.Coll_Struct.h;
				active[i]->hits = 3;
			}
			else if (active[i]->hits == 3)
			{
				active[i]->hits++;
			}
		}*/

		// FABTEN
		if (active[i] != nullptr && active[i]->get_collider() == c1 && active[i]->mytype == FABTEN)
		{
			if (active[i]->hits == 0)
			{
				active[i]->Coll_Struct.x = fabten2.Coll_Struct.x;
				active[i]->Coll_Struct.y = fabten2.Coll_Struct.y;
				active[i]->Coll_Struct.w = fabten2.Coll_Struct.w;
				active[i]->Coll_Struct.h = fabten2.Coll_Struct.h;
				active[i]->hits++;
			}
			else if (active[i]->hits == 1)
			{
				active[i]->Coll_Struct.x = fabten3.Coll_Struct.x;
				active[i]->Coll_Struct.y = fabten3.Coll_Struct.y;
				active[i]->Coll_Struct.w = fabten3.Coll_Struct.w;
				active[i]->Coll_Struct.h = fabten3.Coll_Struct.h;
				active[i]->hits++;
			}
			else if (active[i]->hits == 2)
			{
				active[i]->Coll_Struct.x = fabten4.Coll_Struct.x;
				active[i]->Coll_Struct.y = fabten4.Coll_Struct.y;
				active[i]->Coll_Struct.w = fabten4.Coll_Struct.w;
				active[i]->Coll_Struct.h = fabten4.Coll_Struct.h;
				active[i]->hits++;
			}
			else if (active[i]->hits == 3)
			{
				App->points->AddEnemy(ENEMY_TYPES::POINTS, active[i]->position.x + 25, active[i]->position.y + 19, 10000, NULL);
				active[i]->hits++;
				App->smoke->AddParticle(App->particles->smoke, active[i]->position.x - 10, active[i]->position.y + 125, COLLIDER_NONE, 0);
				App->particles->collapse.fx_played = false;
				App->structuresback->cd1 += 0.5;
				App->structuresmiddle->fabtendest = true;
			}
		}

		// INN
		if (active[i] != nullptr && active[i]->get_collider() == c1 && active[i]->mytype == INN)
		{
			if (active[i]->hits >= 0 && active[i]->hits < 3)
			{
				active[i]->hits++;
			}
			else if (active[i]->hits == 3)
			{
				App->audio->PlayFx(App->particles->bombexplosion.fx, 1200);
				App->building_explosion->AddParticle(App->particles->building_explosion, active[i]->position.x - 5, active[i]->position.y + 45, COLLIDER_NONE, 0);
				App->building_explosion->AddParticle(App->particles->building_explosion, active[i]->position.x + 35, active[i]->position.y + 45, COLLIDER_NONE, 0);
				App->building_explosion->AddParticle(App->particles->building_explosion, active[i]->position.x + 70, active[i]->position.y + 45, COLLIDER_NONE, 0);
				App->building_explosion->AddParticle(App->particles->building_explosion, active[i]->position.x - 5, active[i]->position.y - 20, COLLIDER_NONE, 500);
				App->building_explosion->AddParticle(App->particles->building_explosion, active[i]->position.x + 35, active[i]->position.y - 20, COLLIDER_NONE, 500);
				App->building_explosion->AddParticle(App->particles->building_explosion, active[i]->position.x + 70, active[i]->position.y - 20, COLLIDER_NONE, 500);
				App->building_explosion->AddParticle(App->particles->building_explosion, active[i]->position.x - 5, active[i]->position.y, COLLIDER_NONE, 300);
				App->building_explosion->AddParticle(App->particles->building_explosion, active[i]->position.x + 35, active[i]->position.y, COLLIDER_NONE, 300);
				App->building_explosion->AddParticle(App->particles->building_explosion, active[i]->position.x + 70, active[i]->position.y, COLLIDER_NONE, 300);
				App->audio->PlayFx(App->particles->bombexplosion.fx, 1200);
				App->points->AddEnemy(ENEMY_TYPES::POINTS, active[i]->position.x + 30, active[i]->position.y, 7000, NULL);
				active[i]->hits++;
			}
		}

		// HOTEL
		if (active[i] != nullptr && active[i]->get_collider() == c1 && active[i]->mytype == HOTEL)
		{
			if (active[i]->hits >= 0 && active[i]->hits < 3)
			{
				active[i]->hits++;
			}
			else if (active[i]->hits == 3)
			{
				App->audio->PlayFx(App->particles->bombexplosion.fx, 1200);
				App->building_explosion->AddParticle(App->particles->building_explosion, active[i]->position.x - 3, active[i]->position.y + 45, COLLIDER_NONE, 0);
				App->building_explosion->AddParticle(App->particles->building_explosion, active[i]->position.x + 38, active[i]->position.y + 45, COLLIDER_NONE, 0);
				App->building_explosion->AddParticle(App->particles->building_explosion, active[i]->position.x - 3, active[i]->position.y + 20, COLLIDER_NONE, 300);
				App->building_explosion->AddParticle(App->particles->building_explosion, active[i]->position.x + 38, active[i]->position.y + 20, COLLIDER_NONE, 300);
				App->building_explosion->AddParticle(App->particles->building_explosion, active[i]->position.x + 15, active[i]->position.y - 20, COLLIDER_NONE, 500);
				App->audio->PlayFx(App->particles->bombexplosion.fx, 1200);
				App->points->AddEnemy(ENEMY_TYPES::POINTS, active[i]->position.x + 30, active[i]->position.y, 5000, NULL);
				active[i]->hits++;
			}
		}

		// Smallest building
		if (active[i] != nullptr && active[i]->get_collider() == c1 && active[i]->mytype == SMALLEST_B)
		{
			if (active[i]->hits >= 0 && active[i]->hits < 3)
			{
				active[i]->hits++;
			}
			else if (active[i]->hits == 3)
			{
				App->audio->PlayFx(App->particles->bombexplosion.fx, 1200);
				App->building_explosion->AddParticle(App->particles->building_explosion, active[i]->position.x - 3, active[i]->position.y + 40, COLLIDER_NONE, 0);
				App->building_explosion->AddParticle(App->particles->building_explosion, active[i]->position.x + 38, active[i]->position.y + 40, COLLIDER_NONE, 0);
				App->building_explosion->AddParticle(App->particles->building_explosion, active[i]->position.x - 3, active[i]->position.y + 15, COLLIDER_NONE, 300);
				App->building_explosion->AddParticle(App->particles->building_explosion, active[i]->position.x + 38, active[i]->position.y + 15, COLLIDER_NONE, 300);
				App->building_explosion->AddParticle(App->particles->building_explosion, active[i]->position.x + 10, active[i]->position.y - 20, COLLIDER_NONE, 500);
				App->audio->PlayFx(App->particles->bombexplosion.fx, 1200);
				App->points->AddEnemy(ENEMY_TYPES::POINTS, active[i]->position.x + 30, active[i]->position.y, 5000, NULL);
				active[i]->hits++;
			}
		}

		// BARREL
		if (active[i] != nullptr && active[i]->get_collider() == c1 && active[i]->mytype == BARREL)
		{
			if (active[i]->hits == 0)
			{
				active[i]->Coll_Struct.x = barrel2.Coll_Struct.x;
				active[i]->Coll_Struct.y = barrel2.Coll_Struct.y;
				active[i]->Coll_Struct.w = barrel2.Coll_Struct.w;
				active[i]->Coll_Struct.h = barrel2.Coll_Struct.h;
				active[i]->hits++;
				App->audio->PlayFx(App->particles->barrel_exp.fx, 1200);
				App->particles->AddParticle(App->particles->barrel, active[i]->position.x - 12, active[i]->position.y - 20, COLLIDER_NONE, 0);
			}
			else if (active[i]->hits == 1)
			{
				active[i]->Coll_Struct.x = barrel3.Coll_Struct.x;
				active[i]->Coll_Struct.y = barrel3.Coll_Struct.y;
				active[i]->Coll_Struct.w = barrel3.Coll_Struct.w;
				active[i]->Coll_Struct.h = barrel3.Coll_Struct.h;
				active[i]->hits++;
				App->audio->PlayFx(App->particles->barrel_exp.fx, 1200);
				App->particles->AddParticle(App->particles->barrel, active[i]->position.x - 12, active[i]->position.y - 5, COLLIDER_NONE, 0);
			}
			else if (active[i]->hits == 2)
			{
				App->points->AddEnemy(ENEMY_TYPES::POINTS, active[i]->position.x + 3, active[i]->position.y, 1000, NULL);
				active[i]->Coll_Struct.x = 0;
				active[i]->Coll_Struct.y = 0;
				active[i]->Coll_Struct.w = 0;
				active[i]->Coll_Struct.h = 0;
				active[i]->hits++;
				App->audio->PlayFx(App->particles->barrel_exp.fx, 1200);
				App->particles->AddParticle(App->particles->barrel, active[i]->position.x - 12, active[i]->position.y + 10, COLLIDER_NONE, 0);
			}
		}
	}
}