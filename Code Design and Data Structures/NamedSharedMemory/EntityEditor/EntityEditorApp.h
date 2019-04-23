#pragma once

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

class EntityEditorApp : public aie::Application {
public:
	// IN APPLICATION 1 – The host of the named shared memory
	// open a named shared memory block
	HANDLE fileHandle = CreateFileMapping(
		INVALID_HANDLE_VALUE, // a handle to an existing virtual file, or invalid
		nullptr, // optional security attributes
		PAGE_READWRITE, // read/write access control
		0, sizeof(Entity) * ENTITY_COUNT, // size of the memory block,
		L"EntityIPC");
	
	HANDLE sizeHandle = CreateFileMapping(
		INVALID_HANDLE_VALUE, // a handle to an existing virtual file, or invalid
		nullptr, // optional security attributes
		PAGE_READWRITE, // read/write access control
		0, sizeof(Entity) * ENTITY_COUNT, // size of the memory block,
		L"EntityCountIPC");

	Entity* entity = (Entity*)MapViewOfFile(fileHandle, FILE_MAP_ALL_ACCESS,
		0, 0, sizeof(Entity) * ENTITY_COUNT);

	int* entity_count = (int*)MapViewOfFile(sizeHandle, FILE_MAP_ALL_ACCESS,
		0, 0, sizeof(int));

	EntityEditorApp();
	virtual ~EntityEditorApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	// define a block of entities that should be shared
	enum { ENTITY_COUNT = 10 };
	Entity m_entities[ENTITY_COUNT];
};