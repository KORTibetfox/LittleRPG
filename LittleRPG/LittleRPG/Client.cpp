// LittleRPG.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
// 주석 재밌다 아아아아아아아아아아아아아아아아아아아아아아아아아
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Character.h"

using namespace std;

int main() {

    cout << "원하는 직업을 선택하세요 (input) : w, m, a " << endl;

    char select; cin >> select;

    Character* character = nullptr;



    switch (select)
    {
    case 'w':
        Warrior *warrior = new Warrior();
        character

            break;

    case 'm':

        break;

    case 'a':

        break;
    }

    cout << "당신이 고른 직업은 : " << character. << endl;

    return 0;
}