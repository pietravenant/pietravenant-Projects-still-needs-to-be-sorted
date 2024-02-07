#ifndef CD_H
#define CD_H

#include <QString>

class Cd
{
public:
    Cd();
    Cd(QString &com, QString &a, double &cos, int &r);

    QString getComposer() const;
    QString getAlbum() const;
    double getCost() const;
    int getRating() const;

    void setComposer(QString com);
    void setAlbum(QString a);
    void setCost(double cos);
    void setRating(int r);

private:
    QString composer;
    QString album;
    double cost;
    int rating;
};

#endif // CD_H
