#include "cd.h"

Cd::Cd()
{

}

Cd::Cd(QString &com, QString &a, double &cos, int &r) :
    composer(com),
    album(a),
    cost(cos),
    rating(r)
{

}

QString Cd::getComposer() const
{
    return composer;
}

QString Cd::getAlbum() const
{
    return album;
}

double Cd::getCost() const
{
    return cost;
}

int Cd::getRating() const
{
    return rating;
}

void Cd::setComposer(QString com)
{
    composer = com;
}

void Cd::setAlbum(QString a)
{
    album = a;
}

void Cd::setCost(double cos)
{
    cost = cos;
}

void Cd::setRating(int r)
{
    rating = r;
}
