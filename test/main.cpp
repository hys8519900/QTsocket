#include <QApplication>

#include <iostream>
#include <string>
#include <fstream>

#include "finddialog.h"
#include "basesocket.h"
#include "mainwindow.h"
#include "eventlabel.h"
#include "paintedwidget.h"
#include "mysocket.h"

using namespace std;

//通过socket获得图片并显示

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //MainWindow w;
    //w.show();

    /*
    EventLabel *label = new EventLabel();
    label->setWindowTitle("MouseEvent Demo");
    label->resize(300,200);
    label->show();
    */

    //FindDialog *dialog = new FindDialog;
    //dialog->show();

    PaintedWidget w;

    string strPic;
    try
    {


        MyClientSocket s("img0.bdstatic.com",80);
        s.SendLine("GET /img/image/shouye/sjtb-9782042352.jpg HTTP/1.0");
        s.SendLine("Host: img0.bdstatic.com");
        s.SendLine("");

        string respond = s.ReceiveAll();

        cout << "Respond length: " << respond.size() <<endl;
        //store Respond
        string RespondSave = respond;
        size_t pos;
        int length = 0;
        pos = respond.find("Content-Length:");
        if(pos != string::npos)
        {
            pos += strlen("Content-Length:");
            respond = respond.substr(pos);
            //respond.replace(0,pos,"");

            pos = respond.find_first_of("\n");
            respond = respond.substr(0,pos);
            length = atoi(respond.c_str());
            cout << "Content-Length: " << length << endl;
        }
        strPic = RespondSave.substr(RespondSave.size()- length);
        /*
        ofstream outfile("pic.jpg",ios::binary);
        outfile << strPic;
        outfile.close();
        */
    }
    catch(const char *s)
    {
        cerr << s <<endl;
    }
    catch(std::string s)
    {
        cerr<< s <<endl;
    }
    catch(...)
    {
        cerr << "unhandled exception\n";
    }

    if(!strPic.empty())
        w.getStrPic(strPic);
    w.show();

    return a.exec();
}
