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
    bool writeI;
    bool writeC;
    bool flagC;
    int currentLine;
    int currentLineI;
    bool replace(std::string& str, const std::string& from, const std::string& to);

public:
    Document();
    Document(vector<string> s);

    void num(int number_line);
    void minus(int number_line);
    void plus(int number_line);
    void dolar();
    void p ();
    void a();
    void i();
    void c();
    void d();
    void sleshText(string line);
    void questionMarkText(string text);
    void sOldNew(string oldText, string newText);
    void j(int number_line1 , int number_line2);
    void write(string line);


};
#ifndef EX1_T_M_DOCUMENT_HPP
#define EX1_T_M_DOCUMENT_HPP

#endif //EX1_T_M_DOCUMENT_HPP
