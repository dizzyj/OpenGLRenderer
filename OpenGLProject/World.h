#pragma once
#include "Cube.h"
#include <vector>
#include "Camera.h"
class World
{
private:
	const int size = 8;
	int map[8][8] = { CubeType::CAT };
	std::vector<Cube*> cubes;
	Camera camera;
public:
	World();
	//~World();
	void Create();
	void Draw();
	inline Camera* Camera() { return &camera; }

};

