#ifndef SQL_H
#define SQL_H

#include <QSqlDatabase> //数据驱动
#include <QSqlQuery> //数据库执行语句
#include <QMessageBox>
#include <QDebug>

class sql
{
public:
    sql(const sql& s) = delete;
    static sql* getInstance()
    {
        static sql *Sql = new sql;
        return Sql;
    }
    ~sql();
    bool sql_Init(int Port, QString HostName, QString DatabaseName, QString UserName, QString Password);
    bool sql_Check(QString, QString);

private:
    sql() = default;
    sql& operator=(const sql& s) = delete;

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    int Port;
    QString HostName;
    QString DatabaseName;//数据库名称
    QString UserName;//用户名
    QString Password;//密码
};

#endif // SQL_H
