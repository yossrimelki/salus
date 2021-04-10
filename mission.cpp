#include "mission.h"
#include <QSqlQuery>
#include <QDebug>
#include <QString>
Mission::Mission(int ID_MISSION,int ID_ENFANT,int NB_POINT,QString NOM,QString DESCRIPTION,QString DATE_FIN)
{
    this->ID_MISSION=ID_MISSION;
    this->ID_ENFANT=ID_ENFANT ;
    this->NOM=NOM;
    this->DESCRIPTION=DESCRIPTION;
    this->NB_POINT=NB_POINT;
    this->DATE_FIN=DATE_FIN;
}

bool Mission::ajouter(){

    QSqlQuery query;
    QString id_string= QString::number(ID_ENFANT);
    QString res= QString::number(ID_MISSION);
    QString nbpoint_string= QString::number(NB_POINT);
    query.prepare("INSERT INTO MISSION(ID_MISSION,ID_ENFANT,NOM,DESCRIPTION,NB_POINT,DATE_FIN)"
                  "VALUES (:idmission,:idenfant, :forename, :description, :nbpoint,:datefin)");
                        //query.bindValue(":idmission",id_string );
                        query.bindValue(":idmission",res);
                        query.bindValue(":idenfant",id_string);
                        query.bindValue(":forename", NOM);
                        query.bindValue(":description", DESCRIPTION);
                        query.bindValue(":nbpoint", nbpoint_string);
                        query.bindValue(":datefin", DATE_FIN);



    return query.exec();
}
bool Mission::supprimer(int idenfant,int idmission)
{
    QSqlQuery query;
    query.prepare("delete from MISSION where ((ID_ENFANT=:idenfant)AND (ID_MISSION=:idmission))");
    query.bindValue(":idenfant",idenfant);
    query.bindValue(":idmission",idmission);

    return query.exec();
}
bool Mission::miseajour(int idenfant,int idmission)
{
    QSqlQuery query;
    query.prepare("UPDATE MISSION SET NOM=:nom, DESCRIPTION=:description , NB_POINT=:nbpoint , DATE_FIN=:date_fin  WHERE ID_ENFANT=:idenfant AND ID_MISSION=:idmission");
    QString nbpoint_string= QString::number(NB_POINT);
    query.bindValue(":idmission",idmission);
    query.bindValue(":idenfant",idenfant);
    query.bindValue(":nbpoint", nbpoint_string);
    query.bindValue(":nom", NOM);
    query.bindValue(":description", DESCRIPTION);
    query.bindValue(":date_fin", DATE_FIN);

    return query.exec();
}
QSqlQueryModel * Mission::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from MISSION");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_ENFANT"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID_MISSION"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NB_POINT"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DESCRIPTION"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("DATE_FIN"));
    return model;
}
