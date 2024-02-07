#include "position.h"


Position::Position(int x, int y)
{


}
void Position::changePos(int x, int y)
{
    Position::x = x;
    Position::y = y;
}

int Position::getX() const
{
    return x;
}

int Position::getY() const
{
    return y;
}
