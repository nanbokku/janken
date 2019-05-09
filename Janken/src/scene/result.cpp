#include "result.h"

#include <Siv3D.hpp>

ResultScene::ResultScene(const InitData& data) : IScene(data)
{
	initialize();
}

void ResultScene::update()
{

}

void ResultScene::draw() const
{

}

void ResultScene::initialize()
{
	Print << U"result scene";
}

void ResultScene::exit()
{ 
}