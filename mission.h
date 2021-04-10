#ifndef MISSION_H
#define MISSION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>



class Mission
{
    int ID_MISSION,ID_ENFANT,NB_POINT;
    QString NOM,DESCRIPTION,DATE_FIN;
public:
    Mission(){}
    Mission(int,int,int,QString,QString,QString);
    int getID_MISSION(){return ID_MISSION;}
    int getID_ENFANT(){return ID_ENFANT;}
    int getNB_POINT(){return NB_POINT;}
    QString getNOM(){return NOM;}
    QString getDESCRIPTION(){return DESCRIPTION;}
    QString getDATE_FIN(){return DATE_FIN;}
    void setID_MISSION(int ID_MISSION){this->ID_MISSION=ID_MISSION;}
    void setID_ENFANT(int ID_ENFANT){this->ID_ENFANT=ID_ENFANT;}
    void setNB_POINT(int NB_POINT){this->NB_POINT=NB_POINT;}
    void setNOM(QString NOM){this->NOM=NOM;}
    void setDESCRIPTION(QString DESCRIPTION){this->DESCRIPTION=DESCRIPTION;}
    void setDATE_FIN(QString DATE_FIN){this->DATE_FIN=DATE_FIN;}
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer (int,int);
    bool miseajour (int,int);



};

#endif // MISSION_H
