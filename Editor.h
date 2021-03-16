/*

#include <iostream>
#include <string>
#include <vector>
#include "Document.hpp"
#include <regex>
using namespace std;


class Editor{
private:

    Documents* Doc;

public:
    Editor(){Doc=new Documents();}
    void loop();
    Editor(vector<string> s) {
        Doc=new Documents(s);

    }
};
*/


#include <string>
#include <iostream>
#include "Document.h"
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

