#include "MainMenu.h"

USING_NS_CC;

MenuItem* createMenuItem(const std::string& text, const ccMenuCallback& callback, float yOffset)
{
    Label* label = Label::createWithTTF(text, "fonts/Marker Felt.ttf", 18);
    MenuItemLabel* item = MenuItemLabel::create(label, callback);
    item->setPosition(Vec2(0, yOffset));
    return item;
}

bool MainMenu::init()
{
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    Label* title = Label::createWithTTF("TDS GAME", "fonts/Marker Felt.ttf", 24);

    title->setPosition(Vec2(origin.x + visibleSize.width / 2,
    origin.y + visibleSize.height - title->getContentSize().height));

    this->addChild(title, 1);

    Vector<MenuItem*> menuItems;
    menuItems.pushBack(createMenuItem("Start", CC_CALLBACK_1(MainMenu::startGameCallback, this), 0));
    menuItems.pushBack(createMenuItem("Quit", CC_CALLBACK_1(MainMenu::menuCloseCallback, this), -25));

    Menu* menu = Menu::createWithArray(menuItems);
    menu->setPosition(Vec2(origin.x + visibleSize.width / 2,
        origin.y + visibleSize.height/2));
    this->addChild(menu, 2);

    return true;
}

void MainMenu::startGameCallback(cocos2d::Ref* pSender)
{
    _gameScene = GameScene::createScene();
    Director::getInstance()->replaceScene(_gameScene);
}

void IScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
}