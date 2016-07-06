#ifndef FACTORY_H_
#define FACTORY_H_
#include <string>
#include "Product.hpp"
using namespace std;

class UIFactory {
    public:
        UIFactory() {}
        virtual Window* getToolboxWindow() = 0;
        virtual Window* getLayersWindow() = 0;
        virtual Window* getMainWindow() = 0;
        void deleteWindow(Window* ptr) {delete ptr;}
};

class MFCUIFactory : public UIFactory {
    public:
        MFCUIFactory() {}
        Window* getToolboxWindow() {
            return new MFC_ToolBox();
        }
        Window* getLayersWindow() {
            return new MFC_Layers();
        }
        Window* getMainWindow() {
            return new MFC_Main();
        }
};

class GtkUIFactory : public UIFactory {
    public:
        GtkUIFactory() {}
        Window* getToolboxWindow() {
            return new Gtk_ToolBox();
        }
        Window* getLayersWindow() {
            return new Gtk_Layers();
        }
        Window* getMainWindow() {
            return new Gtk_Main();
        }
};

class QtUIFactory : public UIFactory {
    public:
        QtUIFactory() {}
        Window* getToolboxWindow() {
            return new Qt_Toolbox();
        }
        Window* getLayersWindow() {
            return new Qt_Layers();
        }
        Window* getMainWindow() {
            return new Qt_Main();
        }
};
#endif

