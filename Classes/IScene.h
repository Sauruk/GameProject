#pragma once
#include "cocos2d.h"

class IScene: public cocos2d::Scene {
public :
	static IScene* createScene() {
		return IScene::create();
	}
	virtual void menuCloseCallback(cocos2d::Ref* pSender);

private:
	CREATE_FUNC(IScene);
	static void problemLoading(const char* filename)
	{
		printf("Error while loading: %s\n", filename);
	}
};
