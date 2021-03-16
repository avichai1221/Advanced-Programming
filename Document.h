/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Documents {

private:
    vector<string> full;
    int currentLine;




public:
    Documents(): currentLine{1}{};

    Documents(vector<string> s) {
        currentLine = 0;

        for (int i=0; i<s.size(); i++) {
            full.push_back(s[i]);
            currentLine++;
        }
    }

// p prints the current line (ed maintains a current line)
    void p();
// n prints line number of current line followed by TAB followed by current line
    void n();
// %p prints all lines
    void pAll();
// 7 makes line #7 the current line
    void changeLine(int line);
// a appends new text after the current line
    void a();
// i inserts new text before the current line
    void i();
// c changes the current line for text that follows
    void c();
// d deletes the current line
    void d();
// /text searches forward after current line for the specified text. The search wraps to the
// beginning of the buffer and continues down to the current line, if necessary
    void search(string find);
// s/old/new/ replaces old string with new in current line (google: C++ split or token)
    void s(string sold, string snew);
// Q
// Quits the editor without saving
    void Q();
    void w (string fileName);
    void minus(int number_line);
    void plus(int number_line);
    void dolar();
};*/






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
    void pAll();
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
    void questionMarkText(string text);
    void sOldNew(string oldText, string newText);
    void j();
    void search(string find);
 //   void write(string line);
 void sw(string sold, string snew);


};
#ifndef EX1_T_M_DOCUMENT_HPP
#define EX1_T_M_DOCUMENT_HPP

#endif //EX1_T_M_DOCUMENT_HPP

