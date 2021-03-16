//
// Created by avichai on 3/15/21.
//
#include <string>
#include <iostream>
#include "Editor.hpp"
#include <regex>

using namespace std;

Editor::Editor(){
    document=Document();
}

void Editor::loop(){
    string a;
    while(1){
        getline(cin, a);
        if (!a.compare("q"))
            break;
        sendLine(a);
    }
}
void Editor :: sendLine(string line){
    regex forNum("[0-9]*");
    regex forPlusMinusNum("[/+-]+[0-9]*");
    static bool isText = false; //הראשון לא יהיה טקסט בטוח
    int len = line.length();
    if(isText){
        document.write(line);
        //cout<<"write"<<endl;
        if(!line.compare("."))
            isText = false;
        return;
    }
    if(line.at(0) == '/'){
        document.sleshText(line.substr(1));
        return;
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
        isText = true;
        document.a();
        //cout<<"a"<<endl;
        return;
    }
    if(!line.compare("i")){
        isText = true;
        document.i();
        //cout<<"i"<<endl;
        return;
    }
    if(!line.compare("c")){
        isText = true;
        document.c();
        //cout<<"c"<<endl;
        return;
    }
    if(line[0]=='w'){
        string temp1=line.substr(2,line.size());
        document.w(temp1);
        cout<<temp1<<endl;
        return;
    }
    if(!line.compare("d")){
        document.d();
        //cout<<"d"<<endl;
        //cout<<numberLine<<endl;
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



    if( len > 1 && line.substr(len-1,len) == "j"){
        int index=0;
        while(1){
            if(line.at(index) == ',') break;
            index++;
        }
        string temp1=line.substr(0,index);
        string temp2=line.substr(index+1,len-1);
        int numberLine1=stoi(temp1);
        int numberLine2=stoi(temp2);
        document.j(numberLine1-1,numberLine2-1);
        cout<<"j"<<endl;
        cout<<numberLine1<<endl;
        cout<<numberLine2<<endl;
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

Editor::Editor(vector<string> s) {
    document=Document(s);

}


