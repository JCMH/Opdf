#include <gtkmm.h>
#include <iostream>

Gtk::Window* pWindow = 0;

/*
static
void on_button_clicked()
{
  if(pWindow)
    pWindow->hide(); //hide() will cause main::run() to end.
}
*/
int main(int argc, char **argv)
{
  Gtk::Main kit(argc, argv);

  //Load the GtkBuilder file and instantiate its widgets:
  Glib::RefPtr<Gtk::Builder> refBuilder = Gtk::Builder::create();
  try
  {
    refBuilder->add_from_file("opdf.glade");
  }
  catch(const Glib::FileError& ex)
  {
    std::cerr << "FileError: " << ex.what() << std::endl;
    return 1;
  }
  catch(const Gtk::BuilderError& ex)
  {
    std::cerr << "BuilderError: " << ex.what() << std::endl;
    return 1;
  }

  //Get the GtkBuilder-instantiated Dialog:
  refBuilder->get_widget("window1", pWindow);
  if(pWindow)
  {
/*
    //Get the GtkBuilder-instantiated Button, and connect a signal handler:
    Gtk::Button* pButton = 0;
    refBuilder->get_widget("quit_button", pButton);
    if(pButton)
    {
      pButton->signal_clicked().connect( sigc::ptr_fun(on_button_clicked) );
    }
*/
    kit.run(*pWindow);
  }

  return 0;
}
