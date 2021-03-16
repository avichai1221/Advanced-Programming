//
// Created by avichai on 3/15/21.
//
#include <string>
#include <iostream>
#include <vector>
using namespace std;



class Document{
private:

    vector<string> v;
    int currentLine;
    bool replace(std::string& str, const std::string& from, const std::string& to);

public:
    Document();
    Document(vector<string> s);
    void pAll(); //הדפסה בשביל הנוחות (לא צריך במטלה)
    void num(int number_line);
    void minus(int number_line);
    void plus(int number_line);
    void dolar();
    void w (string fileName);
    void a();
    void i();
    void c();
    void d();
    void sleshText(string line);
    void sOldNew(string oldText, string newText);
    void j();


};
#ifndef EX1_T_M_DOCUMENT_HPP
#define EX1_T_M_DOCUMENT_HPP

#endif //EX1_T_M_DOCUMENT_HPP

