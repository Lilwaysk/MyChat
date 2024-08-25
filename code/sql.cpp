#include "sql.h"

#include <QSqlQueryModel>
#include "mainwindow.h"
#include <QTableView>
#include <QtDebug>
#include <QWidget>
#include <QMessageBox>
#include <QSqlError>


bool sql::sql_Init(int Port, QString HostName, QString DatabaseName, QString UserName, QString Password)
{
    QSqlQuery query(db);
    db.setHostName(HostName);
    db.setPort(Port);
    db.setDatabaseName(DatabaseName);//数据库名称
    db.setUserName(UserName);//用户名
    db.setPassword(Password);//密码

    bool ok = db.open();

    if(ok)
        qDebug()<<"数据库连接成功";
    else
        qDebug()<<"数据库连接失败";

    QString createTableUser="create table if not exists user_list(usrname varchar(10),psw varchar(20));";
    query.exec(createTableUser);

    return true;
}

bool sql::sql_Check(QString usr, QString pwd)
{
    QSqlQuery query(db);
    QString str = QString("SELECT * FROM user_list WHERE usrname = '%1' AND psw = '%2';").arg(usr).arg(pwd);//查询表中的用户名和密码
    if(!query.exec(str))
    {
        qDebug() <<query.lastError().text(); //输出错误信息
        return false;
    }

    if(query.next())   //获取到数据
        return true;
    else
        return false;
}
