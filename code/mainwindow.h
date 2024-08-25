#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qdom.h"
#include "filesrvdlg.h"
#include "filecntdlg.h"

#include <QMainWindow>
#include <QMessageBox>
#include <QUdpSocket>
#include <QNetworkInterface>
#include <QDateTime>
#include <QFile>
#include <QFileDialog>

class FileSrvDlg;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

// 单独设计的五种udp广播消息
enum ChatMsgType {
    ChatMsg,        // 聊天内容
    OnLine,         // 用户上线
    OffLine,        // 用户离线
    SfileName,      // 要传输的文件名
    RefFile         // 拒收文件
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initMainWindow();                                       // 窗口初始化
    void onLine(QString name, QString time);                     // 新用户上线方法
    void offLine(QString name, QString time);                    // 用户离线方法
    void sendChatMsg(ChatMsgType msgType, QString rmtName = ""); // 发送udp消息

    QString getLocHostIp();                                      // 获取本端ip地址
    QString getLocChatMsg();                                     // 获取本端的聊天信息内容
    void recvFileName(QString name, QString hostip, QString rmtname, QString filename);

protected:
   void closeEvent(QCloseEvent *event);                         // 重写关闭窗口的方法以便发送通知离线消息

private slots:
    void on_closeBtn_clicked();

    void on_sendPushButton_clicked();

    void on_searchPushButton_clicked();

    void on_transPushButton_clicked();

    void recvAndProcessChatMsg();

    void getSfileName(QString);

private:
    Ui::MainWindow *ui;
    QString myname = "";                // 本端当前的用户名
    QUdpSocket *myUdpSocket;            // udp套接口指针
    qint16 myUdpPort;                   // udp端口号
    QDomDocument myDoc;
    QString myFileName;
    FileSrvDlg *myfsrv;
};
#endif // MAINWINDOW_H
