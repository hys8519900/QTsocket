#if 0

get pic from net and draw

get jpg from url--> string strPic
PaintedWidget::getStrPic(strPic)

main:
    QApplication a(argc, argv);

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


#endif // NOTE_H
