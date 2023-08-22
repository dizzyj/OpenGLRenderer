#include "World.h"

World::World() 
{
	
}

void World::Create()
{
	//creates a floor of cubes that is 8x8
	/*for (int i = 0; i < size; i++) {
		for (int k = 0; k < size; k++) {
			cubes.push_back(new Cube(CubeType::CAT,i-4,-1,k-4));
		}
	}*/

	cubes.push_back(new Cube(CubeType::CAT, -1, 0,0));
	cubes.push_back(new Cube(CubeType::CAT, 1, 0, 0));
	cubes.push_back(new Cube(CubeType::CAT, 0, -1, 0));
	cubes.push_back(new Cube(CubeType::CAT, 0, 1, 0));
}

void World::Draw()
{
	for (int i = 0; i < cubes.size(); i++) {
		cubes.at(i)->Draw(camera.GetView(), camera.GetProjection());
		//cubes.at(i)->Draw(camera.RotateDemo());
	}
	
}
