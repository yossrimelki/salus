#ifndef POINTS_H
#define POINTS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class points
{
    int ID_ENFANT,NB_TOTAL;
public:
    points(){}
    points(int,int);
    int getID_ENFANT(){return ID_ENFANT;}
    int getNB_TOTAL(){return NB_TOTAL;}
    void setID_ENFANT(int ID_ENFANT){this->ID_ENFANT=ID_ENFANT;}
    void setNB_TOTAL(int NB_TOTAL){this->NB_TOTAL=NB_TOTAL;}
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * tri();
    bool supprimer (int);
    bool miseajour (int);


};

#endif // POINTS_H
