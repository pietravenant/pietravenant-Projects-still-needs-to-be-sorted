#ifndef SQUAB_H
#define SQUAB_H
#include "position.h"

class Squab
{

public:
    Squab(int x, int y);
    int getScore() const;
    void incScore();
    Position getPos();
    void move(char dn, int de);
    bool lineOfSight(Squab s) const;
    Squab * clone()const;

private:
    int score;
    Position Pos;

};

#endif // SQUAB_H
