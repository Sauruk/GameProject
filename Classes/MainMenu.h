#pragma once
#include "IScene.h"
#include "GameScene.h"

class MainMenu: public IScene
{
public:
	static MainMenu* createScene() {
		return MainMenu::create();
	}
	bool init();
	CREATE_FUNC(MainMenu);
	void startGameCallback(cocos2d::Ref* pSender);
private :
	IScene* _gameScene;

};

