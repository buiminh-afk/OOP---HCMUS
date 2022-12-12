#pragma once
#include "question.h"
#include "player.h"
#include "vector"
#include <fstream>
#include <string>
#include <time.h>

class triviaGame
{
private:
    player p1, p2;
    vector<question *> QList;
    bool *asked;

public:
    triviaGame() = default;
    void LoadFromFile(string);

    vector<question *> list()
    {
        return QList;
    };
    void play();
    ~triviaGame()
    {
        delete[] asked;
    }
};