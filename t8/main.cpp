#include <string>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <FL/fl_ask.H>
#include <vector>
#include <iostream>
#include <fstream>
#include "window.h"

using namespace std;

class Data {
private:
  int id;
  std::string type;
  std::string title;
  std::string campo;
public:
  Data(int id, std::string title, std::string campo, std::string type) {
    this->id = id;
    this->title = title;
    this->type = type;
    this->campo = campo;
  }
  int getId() {
    return id;
  }
  std::string getTitle() {
    return title;
  }

  std::string getType() {
    return type;
  }
  std::string getField() {
    return campo;
  }

  void setId(int id){
    this->id = id;
  }

  void setTitle(std::string title) {
    this->title = title;
  }

  void setField(std::string campo) {
    this->campo = campo;
  }
  void setType(std::string type) {
    this->campo = type;
  }
};


class View : public UserInterface {

private:
  std::vector<Data> data;

public:

  View() {
    btnClear->callback((Fl_Callback*) cbBtnClear, (void*)(this));
    btnUpdate->callback((Fl_Callback*) cbBtnUpdate, (void*)(this));
    btnDelete->callback((Fl_Callback*) cbBtnDelete, (void*)(this));
    btnInsert->callback((Fl_Callback*) cbBtnInsert, (void*)(this));
    browser->callback((Fl_Callback*) cbBrowser, (void*)(this));
    btnExport->callback((Fl_Callback*) cbBtnExport, (void*)(this));
  }

  void show() {
    // Mostra janela
    w->show();
  }

  // Funcao callback chamada quando pressionado botao 'Clear'
  static void cbBtnClear(Fl_Widget* btn, void* userdata) {
    View* gui = static_cast<View*>(userdata);
    gui->inputId->value("");
    gui->inputTipo->value("");
    gui->inputTitle->value("");
    gui->inputField->value("");
    gui->browser->clear();
  }

  // Funcao callback chamada quando pressionado botao 'Insert'
  static void cbBtnInsert(Fl_Widget* btn, void* userdata) {
    View* gui = static_cast<View*>(userdata);
    std::string Id(gui->inputId->value());
    int inputId = stoi(Id);
    std::string inputType(gui->inputTipo->value());
    std::string inputField(gui->inputField->value());
    std::string inputTitle(gui->inputTitle->value());
    gui->data.push_back(Data(inputId,inputTitle,inputField,inputType));
    gui->browser->add((Id+" : "+inputTitle+" :"+inputField+" : "+inputType).c_str());
  }

  // Funcao callback chamada quando selecionada uma linha no Fl_Browser
  static void cbBrowser(Fl_Widget* btn, void* userdata) {
    View* gui = static_cast<View*>(userdata);
    int index = gui->browser->value(); // 1-based index
    gui->inputId->value(to_string(gui->data[index-1].getId()).c_str());
    gui->inputTipo->value(gui->data[index-1].getType().c_str());
    gui->inputField->value(gui->data[index-1].getField().c_str());
    gui->inputTitle->value(gui->data[index-1].getTitle().c_str());
  }

  // Funcao callback chamada quando pressionado botao 'Update'
  static void cbBtnUpdate(Fl_Widget* btn, void* userdata) {
    View* gui = static_cast<View*>(userdata);
    int index = gui->browser->value(); // 1-based index
    std::cout << index << std::endl;
    if (index > 0) {
      std::string id(gui->inputId->value());
      std::string inputField(gui->inputField->value());
      std::string inputType(gui->inputTipo->value());
      int inputId = stoi(id);
      gui->data[index-1].setId(inputId);
      gui->data[index-1].setField(inputField);
      gui->data[index-1].setType(inputType);
      std::cout << inputId << std::endl;
      std::cout << inputField << std::endl;
      std::cout << inputType << std::endl;
      gui->browser->text(index,(inputId+" : "+inputField+" : "+inputType+" : ").c_str());
    }
  }

  // Funcao callback chamada quando pressionado botao 'Delete'
  static void cbBtnDelete(Fl_Widget* btn, void* userdata) {
    View* gui = static_cast<View*>(userdata);
    int index = gui->browser->value(); // 1-based index
    std::cout << index << std::endl;
    if (index > 0) {
      int inputId(std::stoi(gui->inputId->value()));
      std::string inputField(gui->inputField->value());
      std::string inputType(gui->inputTipo->value());
      gui->data.erase(gui->data.begin() + index-1);
      gui->browser->remove(index);
    }
  }

  static void cbBtnExport(Fl_Widget* btn, void* userdata) {
      View* gui = static_cast<View*>(userdata);
      ofstream myfile;
      myfile.open ("projeto.csv");
      std::string Titulo(gui->inputTitle->value());
      std::string Index(gui->inputId->value());
      std::string Campo(gui->inputField->value());
      std::string Tipo(gui->inputTipo->value());
      myfile << "Titulo,Index,Campo,Tipo\n";
      myfile << Titulo+","+Index+","+Campo+","+Tipo;
      myfile.close();
  }
};

int main() {
  View gui;
  gui.show();
  return Fl::run();
}
