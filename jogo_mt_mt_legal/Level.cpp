#include "Level.h"
#include "graphics.h"
#include "MyDrawable.h"
#include "Player.h"
#include "inputManager.h"
#include "Collidable.h"
#include "CollisionManager.h"
#include "EnemyMelee.h"

Level* Level::active(NULL);

Level::Level(bool isPlayer2, int activeCase): drawables(), updatables()
{
    switch (activeCase) {
    case LEVEL_1:
        loadLevel1(isPlayer2);
        break;
    case LEVEL_2:
        loadLevel2(isPlayer2);
        break;
    case MENU:
        loadMenu();
        break;
    }
    
}

Level::~Level() //TODO
{

}

void Level::setDrawables(EntityList* drawlist) {
	drawables = drawlist;
}

EntityList* Level::getDrawables() const
{
	return drawables;
}

void Level::setUpdatables(list<Updatable*>* updatelist) {
	updatables = updatelist;
}

list<Updatable*>* Level::getUpdatables() const
{
	return updatables;
}

void Level::draw(sf::RenderWindow* window) {
	drawables->start();
	int size = drawables->getSize();
	for (int i = 0; i < size; i++)
	{
		window->draw(*(drawables->getCurrent()));
		drawables->next();
	}
}

void Level::update()
{
	list<Updatable*>::iterator itCurrent = updatables->begin();
	if (updatables->size() > 1)
	{
		list<Updatable*>::iterator itNext = itCurrent;
		itNext++;
		while (itNext != updatables->end())
		{
			(*itCurrent)->movement();
			itCurrent = itNext;
			itNext++;
		}
		(*itCurrent)->movement();
	}
	else if (updatables->size() == 1)
		(*itCurrent)->movement();
}

Level* Level::getActive()
{
	return active;
}

void Level::setActive(Level* pL) //Usar em algum outro lugar (tipo gerenciador/pilha de states)
{
	active = pL;
}

void Level::addUpdatable(Updatable* pU)
{
	updatables->push_back(pU);
}

void Level::addDrawable(Entity* pD) {
	drawables->pushBack(pD);
}

void Level::loadLevel1(bool isPlayer2) {

    Graphics* instance = Graphics::getInstance();
    sf::RenderWindow* window = instance->getWindow();

    Camera* view;
    view = new Camera(window);
    CollisionManager* gerenciadorColisao = CollisionManager::getInstance();

    //list<Updatable*>* updatables;
    //EntityList* drawables;
    //list<Alive*>* alives;
    //updatables = new list<Updatable*>;
    //drawables = new EntityList;
    //alives = new list<Alive*>;

    Player* player;
    Player* player2;
    Collidable* plataforma, * parede, * teto;
    //EntityList* colisionaveis;
    EnemyMelee* inimigo;

    //colisionaveis = new EntityList;
    plataforma = new Collidable;
    parede = new Collidable;
    teto = new Collidable;

    collidables->push_back(plataforma);
    collidables->push_back(parede);
    collidables->push_back(teto);

    plataforma->setPosition(sf::Vector2f(0, 1000));
    plataforma->setFillColor(sf::Color::Red);
    plataforma->setSize(sf::Vector2f(3000, 100));

    parede->setPosition(sf::Vector2f(300, 500));
    parede->setFillColor(sf::Color::Green);
    parede->setSize(sf::Vector2f(100, 300));

    teto->setPosition(sf::Vector2f(0, 400));
    teto->setFillColor(sf::Color::Blue);
    teto->setSize(sf::Vector2f(1000, 100));

    gerenciadorColisao->setCollidables(collidables);

    player = new Player(0, 1, 10);
    player->setFillColor(sf::Color::Cyan);
    player->setSize(sf::Vector2f(1, 1));
    player->setOrigin(sf::Vector2f(0, 0));
    player->setSize(sf::Vector2f(100, 100));


    if (isPlayer2) {
        player2 = new Player(1,1,10);
        player2->setFillColor(sf::Color::Magenta);
        player2->setSize(sf::Vector2f(1, 1));
        player2->setOrigin(sf::Vector2f(0, 0));
        player2->setSize(sf::Vector2f(100, 100));
    }

    inimigo = new EnemyMelee;
    inimigo->setPosition(1000, 900);

    aliveList->push_back(player);
    if (isPlayer2)
        aliveList->push_back(player2);
    aliveList->push_back(inimigo);

    gerenciadorColisao->setAliveList(aliveList);

    updatables->push_back(player);
    if (isPlayer2)
        updatables->push_back(player2);
    updatables->push_back(view);
    updatables->push_back(inimigo);

    drawables->pushBack(player);
    if (isPlayer2)
        drawables->pushBack(player2);
    drawables->pushBack(parede);
    drawables->pushBack(plataforma);
    drawables->pushBack(inimigo);
    drawables->pushBack(teto);

    Level::setActive(this);

    view->setPlayer1(player);
    if (isPlayer2)
        view->setPlayer2(player2);
}