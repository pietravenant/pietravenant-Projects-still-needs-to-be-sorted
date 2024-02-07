#ifndef POSITION_H
#define POSITION_H


class Position
{

public:
    Position(int x, int y);
    void changePos(int x, int y);
    int getX() const;
    int getY() const;

private:

    int x;
    int y;
};

#endif // POSITION_H
