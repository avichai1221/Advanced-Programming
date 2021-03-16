//
// Created by avichai on 3/15/21.
//
#include <string>
#include <iostream>
#include "Editor.h"
#include <regex>

using namespace std;

Editor::Editor(){
    document=Document();
}
Editor::Editor(vector<string> s) {
    document=Document(s);

}
void Editor::loop(){
    string input;
    while(1){
        getline(cin, input);
        if (!input.compare("q"))
            break;
        sendLine(input);
    }
}
void Editor :: sendLine(string line){
    regex forNum("[0-9]*");
    regex prAll("%p");
    regex src(R"(/\w+/)");
    regex forPlusMinusNum("[/+-]+[0-9]*");
    int len = line.length();
    if(line.at(0) == '/'){
        string help= line.substr(1,line.size()-2);
        document.sleshText(help);
        return;
    }

   if(regex_match(line, prAll)){
        document.pAll();

    }

    if( !line.compare("$")){
        document.dolar();
        return;
    }
    if(line.at(0) == 's'){
        vector<string> arr = split(line, '/');
        if(arr.size() >= 3){
            document.sOldNew(arr[1], arr[2]);
            return;
        }
    }
    if(!line.compare("a")){
        document.a();
        return;
    }
    if(!line.compare("i")){
        document.i();
        return;
    }
    if(!line.compare("c")){
        document.c();
        return;
    }
    if(line[0]=='w'){
        string temp1=line.substr(2,line.size());
        document.w(temp1);
        return;
    }
    if(!line.compare("d")){
        document.d();
        return;
    }
    if(regex_match(line,forNum)){ //מספרים
        int numberLine=stoi(line);
        document.num(numberLine);
        return;
    }
    if(regex_match(line,forPlusMinusNum)){ //פלוס מינוס מספר
        string temp=line.substr(1,len);
        int numberLine=stoi(temp);
        if(line[0]=='-')
            document.minus(numberLine);
        if(line[0]=='+')
            document.plus(numberLine);

        return;
    }



    if(!line.compare("j")){
        document.j();
        return;
    }

}


vector<string> Editor::split(string str, char splitBy){
    vector<string> words;
    string word = "";
    for (auto x : str) {
        if (x == splitBy) {
            words.push_back(word);
            word = "";
        }
        else{
            word = word + x;
        }
    }
    words.push_back(word);
    return words;
}




