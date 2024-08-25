#include "logindialog.h"
#include "ui_logindialog.h"

#include <QLabel>
#include <QPixmap>
#include <QMessageBox>
#include <QDebug>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    s->sql_Init(3306, "127.0.0.1", "mychat", "root", "1234");
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::showWechatWindow()
{
    QString usr = ui->usrlineEdit->text();
    QString psw = ui->pwdlineEdit->text();
    if(!s->sql_Check(usr, psw))
    {
        QMessageBox::warning(0, tr("tips"), "登陆失败");
        return;
    }
    else
    {
        QMessageBox::warning(0, tr("tips"), "登陆成功");
        this->hide();
        w = new MainWindow(0);
        w->show();
    }

}

void LoginDialog::on_closeButton_clicked()
{
    close();
}

void LoginDialog::on_loginButton_clicked()
{
    showWechatWindow();
}
