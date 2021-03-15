#include <string>
#include <iostream>
#include "Document.hpp"
using namespace std;
class Editor{
private:


    Document document;
    void sendLine(string line);
    vector<string> split(string str, char splitBy);



public:
    void loop();
    Editor();
    Editor(vector<string> s);

};









#ifndef EX1_T_M_EDITOR_HPP
#define EX1_T_M_EDITOR_HPP

#endif //EX1_T_M_EDITOR_HPP
