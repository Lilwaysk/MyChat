#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include "sql.h"
#include "mainwindow.h"

#include <QDialog>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();
    bool suc = false;

private slots:
    void on_closeButton_clicked();

    void on_loginButton_clicked();

private:
    Ui::LoginDialog *ui;
    MainWindow *w;
    sql *s = sql::getInstance();
    void showWechatWindow();
};

#endif // LOGINDIALOG_H
