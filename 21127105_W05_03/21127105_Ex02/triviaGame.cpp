#include "triviaGame.h"

void triviaGame::LoadFromFile(string fileName)
{
    ifstream fi(fileName);
    string q, ans[4];
    int a;
    while (!fi.eof())
    {
        getline(fi, q);
        getline(fi, ans[0]);
        getline(fi, ans[1]);
        getline(fi, ans[2]);
        getline(fi, ans[3]);
        fi >> a;
        fi.ignore();
        question *quest = new question(q, ans, a);
        this->QList.push_back(quest);
    }
    asked = new bool(QList.size());
    for (int i = 0; i < QList.size(); i++)
        asked[i] = false;
    p1.setAns(QList.size());
    p2.setAns(QList.size());
    fi.close();
}

void triviaGame::play()
{
    srand(time(0));
    this->LoadFromFile("question.txt");
    for (int i = 0; i < QList.size(); i++)
    {
        int randQ = rand() % QList.size();
        while (asked[randQ])
            randQ = rand() % QList.size();
        asked[randQ] = true;
        cout << "----------------------------" << endl;
        QList[randQ]->display();
        cout << "Player 1's answer : ";
        cin >> p1.playerAns()[randQ];
        while (p1.playerAns()[randQ] > 4 || p1.playerAns()[randQ] < 1)
        {
            cout << "Player 1's answer (1-4) : ";
            cin >> p1.playerAns()[randQ];
        }
        cout << "Player 2's answer : ";
        cin >> p2.playerAns()[randQ];
        while (p2.playerAns()[randQ] > 4 || p2.playerAns()[randQ] < 1)
        {
            cout << "Player 2's answer (1-4) : ";
            cin >> p2.playerAns()[randQ];
        }
        if (p1.playerAns()[randQ] == QList[randQ]->answer())
            p1.updateScore();
        if (p2.playerAns()[randQ] == QList[randQ]->answer())
            p2.updateScore();
    }

    cout << "----------------------------" << endl;
    cout << "Player 1'score is " << p1.getScore() << " / " << QList.size() << endl;
    cout << "Player 2'score is " << p2.getScore() << " / " << QList.size() << endl;
    cout << "----------------------------" << endl;
}