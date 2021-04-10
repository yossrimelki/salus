#include "connection.h"
#include "QSqlDatabase"

Connection::Connection()
{

}
bool Connection::CreateConnection(){
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("salus_projet");
    db.setUserName("Yossri");
    db.setPassword("esprit21");

    if (db.open()){
        test=true;
    }
    return test;
}
