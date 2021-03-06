#ifndef __MODULESTRUCTURES_H__
#define __MODULESTRUCTURES_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleParticles.h"

#define MAX_BUILDINGS 15

enum buildingtype
{
	//COLUMN,
	BAR,
	INN,
	FABTEN,
	HOTEL,
	SMALLEST_B,
	BARREL,
	BARRELROL
};

struct SDL_Texture;

struct Structure
{
	SDL_Rect Coll_Struct;
	Animation destroy;
	uint fx = 0;

	// Structures HP
	uint hits = 0;

	fPoint position;
	bool fx_played = false;
	bool Update();
	bool destroyed = false;
	bool created = false;
	
	Collider* collider = nullptr;
	buildingtype mytype;
	Structure();
	Structure(const Structure& p);
	~Structure();

	const Collider* get_collider()const;
};

class ModuleStructures : public Module
{
public:
	ModuleStructures();
	~ModuleStructures();
	update_status Update();
	bool Start();
	bool CleanUp();
	bool fabtendest = false;
	bool bardest = false;
	bool fabtenalive = true;
	bool baralive = true;
	void OnCollision(Collider* c1, Collider* c2);
	void AddStructure(Structure& particle, int x, int y);
	float cd1 = 0.0;
	int collapse_fabten = 0;

private:

	SDL_Texture* graphics = nullptr;
	Structure* active[MAX_BUILDINGS];
	uint last_building = 0;

public:
	Structure bar, bar2, bar3, bar4;
	Structure inn, hotel, smallest_b;
	Structure fabten, fabten2, fabten3, fabten4;
	Structure barrel, barrel2, barrel3;
	//Structure column;
};
#endif // __MODULESTRUCTURES_H__