#pragma once
#include "Cube.h"
#include <vector>
#include "Camera.h"
#include "Light.h"
class World
{
private:
	const int size = 8;
	//int map[8][8] = { CubeType::CAT };
	std::vector<Cube*> cubes;
	Light* light;
	Camera camera;
public:
	World();
	//~World();
	void Create();
	void Draw();
	inline Camera* Camera() { return &camera; }
	inline Light* GetLight() { return light; }

};

