#pragma once

#include <vector>
#include "Application.h"
#include "Renderer2D.h"
#include <Windows.h>

struct Entity {
	float x = 0, y = 0;
	float rotation = 0;
	float speed = 0;
	float r = 0, g = 0, b = 0;
	float size = 1;
};

class EntityDisplayApp : public aie::Application {
public:
	// IN APPLICATION 2 – A user of the named shared memory
	// gain access to a named shared memory block that already exists
	HANDLE fileHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, L"EntityIPC");
	HANDLE sizeHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, L"EntityCountIPC");

	// map the memory from the shared block to a pointer we can manipulate
	int* ptr_size = (int*)MapViewOfFile(sizeHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(int));
	int count = *ptr_size;

	Entity* data = (Entity*)MapViewOfFile(fileHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(Entity) * count);

	EntityDisplayApp();
	virtual ~EntityDisplayApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;


	// an array of an unknown number of entities
	std::vector<Entity> m_entities;
};