#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>

class Connection
{
    QSqlDatabase db;
public:
    Connection();
    bool CreateConnection();
};

#endif // CONNECTION_H
