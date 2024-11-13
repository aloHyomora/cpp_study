#include "pch.h"
#include "GameScene.h"
#include "Player.h"
#include "ObjectManager.h"


GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

void GameScene::Init()
{
	/*_player = new Player();_player->Init();*/

	{
		Player* player = GET_SINGLE(ObjectManager)->CreateObject<Player>();
		player->SetPos(Pos{ 400,400 });
		GET_SINGLE(ObjectManager)->Add(player);
	}	
}

void GameScene::Update()
{
	/*if(_player)
		_player->Update();*/

	const vector<Object*> objects = GET_SINGLE(ObjectManager)->GetObjects();
	for (Object* object : objects)
	{
		object->Update();
	}
}

void GameScene::Render(HDC hdc)
{
	/*if (_player)
		_player->Render(hdc);*/

	const vector<Object*> objects = GET_SINGLE(ObjectManager)->GetObjects();
	for (Object* object : objects)
	{
		object->Render(hdc);
	}
}
