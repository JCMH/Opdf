#include <gtkmm.h>
#include <iostream>

Gtk::Window* pWindow = 0;

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
    kit.run(*pWindow);
  }

  return 0;
}
