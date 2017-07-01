// generated by Fast Light User Interface Designer (fluid) version 1.0303

#ifndef window_h
#define window_h
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>

class UserInterface {
public:
  UserInterface();
protected:
  Fl_Double_Window *w;
  Fl_Input *participantes;
  Fl_Button *reset;
  Fl_Box *nGanhador;
  Fl_Box *resultado;
  Fl_Button *sortear;
};
#endif