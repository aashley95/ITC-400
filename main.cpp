
// Created by asia on 3/26/20.
//

#include <gtkmm.h>
#include <iostream>
#include "blocker.cpp"
#include <stdlib.h>

Gtk::Window* pWindow = nullptr;
Gtk::MessageDialog* pDialog = nullptr;

static
void on_button4_clicked()
{
    system("shutdown -r");
}

static
void on_button2_clicked()
{
    delete pDialog;
    delete pWindow;
}

static
void on_button3_clicked(){
    edit();
}

static
void on_button_clicked()
{
    block();
    auto app = Gtk::Application::create();
    auto refBuilder = Gtk::Builder::create();
    refBuilder->add_from_file("gui.glade");
    refBuilder->get_widget("message1", pDialog);
    if (pDialog)
    {
        Gtk::Box* pBox = nullptr;
        refBuilder->get_widget("box2", pBox);

        Gtk::Button* pButton = nullptr;
        refBuilder->get_widget("button2", pButton);

        Gtk::Button* pButton2 = nullptr;
        refBuilder->get_widget("button4", pButton2);


        if(pButton)
        {
            pButton->signal_clicked().connect( sigc::ptr_fun(on_button2_clicked) );
        }

        if(pButton2){
            pButton->signal_clicked().connect( sigc::ptr_fun(on_button4_clicked) );
        }

        app->run(*pDialog);

    }

    delete pDialog;

}

int main(int argc, char **argv)
{
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    auto refBuilder = Gtk::Builder::create();
    try{
        refBuilder->add_from_file("gui.glade");
    }
    catch(const Glib::FileError& ex)
    {
        std::cerr << "FileError: " << ex.what() << std::endl;
        return 1;
    }
    catch(const Glib::MarkupError& ex){
        std::cerr << "MarkupError: " << ex.what() << std::endl;
        return 1;
    }


    //Get the builder instantiated window
    refBuilder->get_widget("window1", pWindow);
    if (pWindow)
    {
        //get all widgets
        Gtk::Box* pBox = nullptr;
        refBuilder->get_widget("box1", pBox);

        Gtk::Label* pLabel = nullptr;
        refBuilder->get_widget("title1", pLabel);

        Gtk::TextView* pTextView = nullptr;
        refBuilder->get_widget("textview1", pTextView);

        Gtk::Button* pButton = nullptr;
        refBuilder->get_widget("button1", pButton);
        //connect signal handler to button
        if(pButton)
        {
            pButton->signal_clicked().connect( sigc::ptr_fun(on_button_clicked) );
        }

        Gtk::Button* pButton3 = nullptr;
        refBuilder->get_widget("button3", pButton3);
        if(pButton3){
            {
                pButton3->signal_clicked().connect( sigc::ptr_fun(on_button3_clicked) );
            }

        }

        app->run(*pWindow);

    }

    delete pWindow;

    return 0;

}
