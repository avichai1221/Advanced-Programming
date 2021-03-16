/*
#include <fstream>
#include "Document.hpp"

// p prints the current line (ed maintains a current line)
void Documents::p(){
    cout<<full.at(currentLine)<<endl;
}
// n prints line number of current line followed by TAB followed by current line
void Documents::n(){
    cout<<(currentLine+1)<<"\t"<<full.at(currentLine)<<endl;
}
// %p prints all lines
void Documents::pAll(){

    for(string st: full){
        cout<<st<<endl;
    }
    cout<<currentLine<<endl;

}

// 7 makes line #7 the current line
void Documents::changeLine(int line){
    if(line>full.size()||line<=0){
        cout<<"?"<<endl;
        Q();
    }
    currentLine=line;
    cout<<full.at(currentLine)<<endl;
}
// a appends new text after the current line
void Documents::a(){
  */
/*  if(currentLine==-1){
        string temp;
        //need lines and with empty lines;
        getline(cin,temp);
        if(temp.compare(".")){
            full.push_back(temp);
            currentLine=0;
        }
    }*//*

    std::vector<string>::iterator it;

    while(true){
        it=full.begin()+(currentLine+1);
        string temp;
        //need lines and with empty lines;
        getline(cin,temp);
        if(!temp.compare(".")) break;
        full.insert(it,temp);
        currentLine++;
        //  pAll();
    }

}
// i inserts new text before the current line
void Documents::i(){
    */
/*if(currentLine==1){
        string temp;
        //need lines and with empty lines;
        getline(cin,temp);
        if(temp.compare(".")){
            full.push_back(temp);
            currentLine=0;
        }
    }*//*

    std::vector<string>::iterator it;

    while(true){
        it=full.begin()+(currentLine);
        string temp;
        //need lines and with empty lines;
        getline(cin,temp);
        if(!temp.compare(".")) break;
        full.insert(it++,temp);
        currentLine++;
    }
}
// c changes the current line for text that follows
void Documents::c(){
    d();
    std::vector<string>::iterator it;

    while(true){
        it=full.begin()+(currentLine+1);
        string temp;
        //need lines and with empty lines;
        getline(cin,temp);
        if(!temp.compare(".")) break;
        full.insert(it,temp);
        currentLine++;
    }

}
// d deletes the current line
void Documents::d(){
    //cout<<full.at(currentLine)<<" del"<<endl;
    full.erase((full.begin()+(currentLine)));
    currentLine--;
}
// /text searches forward after current line for the specified text. The search wraps to the
// beginning of the buffer and continues down to the current line, if necessary
void Documents::search(string find){
    for(int i =0; i<=currentLine ; i++)
    {
        if(full.at(i).find(find)!=string::npos){
            currentLine=i;
        }
    }
    cout<<full.at(currentLine)<<endl;

}
// s/old/new/ replaces old string with new in current line (google: C++ split or token)
void Documents::s(string s_old, string s_new){
    int check= full.at(currentLine).find(s_old);
    if(check!=-1){
        full.at(currentLine).replace(check,s_old.size(),s_new);
    }
    else{
        cout<<"?"<<endl;
        Q();
    }
}
// Q
// Quits the editor without saving
void Documents::Q(){
    exit(0);
}
void Documents::w(string fileName){
    ofstream myfile;
    myfile.open(fileName);
    for(int i =0; i< full.size(); i++){
        myfile << full[i] << endl;
    }
    myfile.close();
    cout << currentLine << endl;
    // currentLine = v.size();

}

void Documents::minus(int number_line){
    cout<<full[currentLine];

    currentLine=currentLine-number_line;
    cout<<full[currentLine];


}
void Documents::plus(int number_line){
    currentLine=currentLine+number_line;
    cout<<full[currentLine];

}

void Documents::dolar() {
    currentLine = full.size();
}
*/


#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "Document.hpp"

Document::Document(){
    currentLine = 0;

}
Document::Document(vector<string> s) {
    currentLine = 0;

    for (int i=0; i<s.size(); i++) {
        v.push_back(s[i]);
        currentLine++;
    }
}

void Document::pAll(){

    for(string st: v){
        cout<<st<<endl;
    }
    cout<<currentLine<<endl;

}

void Document::num(int number_line){
    currentLine=number_line;
   // cout<<v[currentLine];
}
void Document::minus(int number_line){
    currentLine=currentLine-number_line;
     cout<<v[currentLine];


}
void Document::plus(int number_line){
    currentLine=currentLine+number_line;
     cout<<v[currentLine];

}

void Document::dolar(){
    currentLine = v.size();

}
void Document::w(string fileName){
    ofstream myfile;
    myfile.open(fileName);
    for(int i =0; i< v.size(); i++){
        myfile << v[i] << endl;
    }
    myfile.close();
    cout << currentLine << endl;
   // currentLine = v.size();

}
void Document::a(){
  /*  if(currentLine==1){
        string temp;
        //need lines and with empty lines;
        getline(cin,temp);
        if(temp.compare(".")){
            v.push_back(temp);
            currentLine=0;
        }
    }*/
    std::vector<string>::iterator it;

    while(true){
        it=v.begin()+(currentLine);
        string temp;
        //need lines and with empty lines;
        getline(cin,temp);
        if(!temp.compare(".")) break;
        v.insert(it,temp);
        currentLine++;
        //  pAll();
    }
}
void Document::i(){
    currentLine=currentLine-1;
/*    if(currentLine==1){
        string temp;
        //need lines and with empty lines;
        getline(cin,temp);
        if(temp.compare(".")){
            v.push_back(temp);
            currentLine=1;
        }
    }*/
    std::vector<string>::iterator it;

    while(true){
        it=v.begin()+(currentLine);
        string temp;
        //need lines and with empty lines;
        getline(cin,temp);
        if(!temp.compare(".")) break;
        v.insert(it++,temp);
        currentLine++;
    }
}
// c changes the current line for text that follows
void Document::c(){
   // d();
    std::vector<string>::iterator it;

    while(true){
        it=v.begin()+(currentLine);
        string temp;
        //need lines and with empty lines;
        getline(cin,temp);
        if(!temp.compare(".")) break;
        v.insert(it,temp);
        currentLine++;
    }

}
void Document::d(){
    //cout<<full.at(currentLine)<<" del"<<endl;
    v.erase((v.begin()+(currentLine-1)));
    currentLine--;
}
void Document::sleshText(string line){
    for(int i = currentLine; i< v.size(); i++){
        size_t found = v[i].find(line);
        if(found !=  string::npos){
            currentLine=i+1;
            cout<< v[i]<< "="<<currentLine<<endl;
            return;
        }
    }
    currentLine=v.size();
    cout<<currentLine<<endl;
}
void Document::questionMarkText(string line){
    for(int i = 0; i< currentLine-1; i++){
        //size_t found = v[i].find(line);
        if(v[i].find(line) !=  string::npos){
            currentLine=i+1;
            cout<< v[i]<< "="<<currentLine<<endl;
            return;
        }
    }
    currentLine=0;
    cout<<currentLine<<endl;

}
void Document::sOldNew(string oldText, string newText){
    replace(v[currentLine-1], oldText, newText);
}
void Document::j(int number_line1 ,int number_line2){
    string temp=v[number_line1]+ " " + v[number_line2];
    v[number_line1]=temp;
    v.erase(v.begin() + number_line2);
}


/*

void Document :: write(string line){
    if(writeC){
        v[currentLine-1]=line;
        writeC=false;
        flagC=true;

    }
    else if(writeI){
        if(!line.compare(".")){
            writeI=false;
            return;
        }
        vector<string>::iterator it;
        it = v.begin();
        v.insert (it+currentLineI,line);
        currentLineI++;
        currentLine++;


    }
    else{
        if(!line.compare(".")){
            if(flagC){currentLine=v.size();
                flagC=false;}
            return;
        }
        vector<string>::iterator it;
        it = v.begin();
        v.insert (it+currentLine,line);
       // currentLine++;
    }
    //cout<<currentLine<<endl;
}

*/



bool Document::replace(string& str, const string& from, const string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

