#pragma once

class player
{
private:
    int score = 0;
    int *ans;

public:
    void updateScore()
    {
        score++;
    }
    int getScore()
    {
        return score;
    }
    void setAns(int _n)
    {
        ans = new int(_n);
    }
    int *playerAns()
    {
        return this->ans;
    }
};