#include "Entity.h"
#include "ConsoleControl/ConsoleControl.h"


Entity::Entity()
{
	_isActive = true;
	_id = 0;
	_position.X = 0;
	_position.Y = 0;
}


Entity::~Entity()
{
}

void Entity::init()
{
}

void Entity::update()
{
}

void Entity::render()
{
}

void Entity::setCollisionMap(Mapa * objMap)
{
	objMap->getMap(_collision);
}

void Entity::deactivate()
{
	_isActive = false;
	ConsoleSetColor(BLACK, BLACK);
	ConsoleXY(_position.X, _position.Y);
}

bool Entity::isOverlaping()
{
	return false;
}
