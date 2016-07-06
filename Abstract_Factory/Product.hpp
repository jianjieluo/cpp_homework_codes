#ifndef PRODUCT_H_
#define PRODUCT_H_
#include <string>
using namespace std;

class Window {
    public:
        Window() {}
        virtual string getToolkit() = 0;
        virtual string getType() = 0;
};

class MFC_ToolBox : public Window {
    public:
        MFC_ToolBox() {}
        virtual string getToolkit();
        virtual string getType();
};
string MFC_ToolBox::getToolkit() {
    return "MFC";
}
string MFC_ToolBox::getType() {
    return "ToolboxWindow";
}

class MFC_Layers : public Window {
    public:
        MFC_Layers() {}
        virtual string getToolkit();
        virtual string getType();
};
string MFC_Layers::getToolkit() {
    return "MFC";
}
string MFC_Layers::getType() {
    return "LayersWindow";
}

class MFC_Main : public Window {
    public:
        MFC_Main() {}
        virtual string getToolkit();
        virtual string getType();
};
string MFC_Main::getToolkit() {return "MFC";}
string MFC_Main::getType() {return "MainWindow";}

class Gtk_ToolBox : public Window {
    public:
        Gtk_ToolBox() {}
        virtual string getToolkit();
        virtual string getType();
};
string Gtk_ToolBox::getToolkit() {return "Gtk";}
string Gtk_ToolBox::getType() {return "ToolboxWindow";}

class Gtk_Layers : public Window {
    public:
        Gtk_Layers() {}
        virtual string getToolkit();
        virtual string getType();
};
string Gtk_Layers::getToolkit() {return "Gtk";}
string Gtk_Layers::getType() {return "LayersWindow";}

class Gtk_Main : public Window {
    public:
        Gtk_Main() {}
        virtual string getToolkit();
        virtual string getType();
};
string Gtk_Main::getToolkit() {return "Gtk";}
string Gtk_Main::getType() {return "MainWindow";}

class Qt_Toolbox : public Window {
    public:
        Qt_Toolbox() {}
        virtual string getToolkit();
        virtual string getType();
};
string Qt_Toolbox::getToolkit() {return "Qt";}
string Qt_Toolbox::getType() {return "ToolboxWindow";}

class Qt_Layers : public Window {
    public:
        Qt_Layers() {}
        virtual string getToolkit();
        virtual string getType();
};
string Qt_Layers::getToolkit() {return "Qt";}
string Qt_Layers::getType() {return "LayersWindow";}

class Qt_Main : public Window {
    public:
        Qt_Main() {}
        virtual string getToolkit();
        virtual string getType();
};
string Qt_Main::getToolkit() {return "Qt";}
string Qt_Main::getType() {return "MainWindow";}
#endif
