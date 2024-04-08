// LittleRPG.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

#include <SFML/Graphics.hpp>

using namespace std;

class Unit
{
    protected:
        string name;
        int level;

    public:
        Unit()
        {
            this->name = "Hello";
            this->level = 10;
            cout << this->name << this->level << endl;
        }

        string getName()
        {
            return this->name;
        }

        int getLevel()
        {
            return this->level;
        }


};

class Tibetfox : public Unit
{
public:
    Tibetfox()
    {
        this->name = "korean tibet fox";
        this->level = 999999;
    }
};

class Player : public Unit
{

};

class Game
{
    public:
        Game(){}

    private:
        int a;
};

int main()
{
    
    Unit unit;
    Tibetfox* tibetPointer = new Tibetfox();
    cout << tibetPointer->getLevel() << "레벨 고인물 : " << tibetPointer->getName() << endl;

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}