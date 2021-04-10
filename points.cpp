#include "points.h"
#include <QSqlQuery>
#include <QDebug>
#include <QString>

points::points(int ID_ENFANT,int NB_TOTAL)
{
    this->ID_ENFANT=ID_ENFANT ;
    this->NB_TOTAL=NB_TOTAL;

}

bool points::ajouter(){

    QSqlQuery query;
    QString id_string= QString::number(ID_ENFANT);
    QString res= QString::number(NB_TOTAL);
    query.prepare("INSERT INTO POINTS(ID_ENFANT,NB_TOTAL)"
                  "VALUES (:idenfant, :nbtotal)");

                        query.bindValue(":idenfant",id_string);

                        query.bindValue(":nbtotal", res);




    return query.exec();
}

bool points::supprimer(int idenfant)
{
    QSqlQuery query;
    query.prepare("delete from POINTS where ID_ENFANT=:idenfant");
    query.bindValue(":idenfant",idenfant);

    return query.exec();
}


QSqlQueryModel * points::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from POINTS");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_ENFANT"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NB_TOTAL"));
    return model;
}

QSqlQueryModel * points::tri()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from POINTS ORDER BY NB_TOTAL DESC");
    return model;
}


bool points::miseajour(int idenfant)
{
    QSqlQuery query;

    query.prepare("UPDATE POINTS SET NB_TOTAL=(NB_TOTAL + :nbtotal) WHERE ID_ENFANT=:idenfant");
    QString nbpoint_string= QString::number(NB_TOTAL);
    query.bindValue(":idenfant",idenfant);
    query.bindValue(":nbtotal", nbpoint_string);

    return query.exec();
}
