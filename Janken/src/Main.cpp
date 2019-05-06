
#include <Siv3D.hpp> // OpenSiv3D v0.3.1

#include "game_manager.h"

void Main()
{
	auto manager = &GameManager::instance();

	manager->initialize();
	manager->loop();
	manager->exit();
}
