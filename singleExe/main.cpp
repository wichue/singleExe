#include "mainwindow.h"
#include <QtSingleApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QtSingleApplication a("myapp_id",argc, argv);//应用程序标识，保证唯一性
    if(a.isRunning())   //判断实例是否已经运行
    {
        QMessageBox::warning(nullptr,"提示","this is already running");
        a.sendMessage("raise_window_noop"); //sendMessage和setActivationWindow配套使用，设置setActivationWindow时第二个实例会给第一个实例发送消息，第一个实例可以选择弹出到最上层
        return EXIT_SUCCESS;
    }
    MainWindow w;
    a.setActivationWindow(&w,true);   //如果是第一个实例则绑定,true时第二个实例启动时最上层显示该窗口，false时不会把第一个实例弹到最上层
    w.show();
    return a.exec();
}
