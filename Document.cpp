#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "Document.hpp"

Document::Document(){
    currentLine = 0;
    currentLineI=0;
    writeI = false;
    writeC = false;
    flagC=false;
}
Document::Document(vector<string> s) {
    currentLine = 0;
    currentLineI=0;
    writeI = false;
    writeC = false;
    flagC=false;
    for (int i=0; i<s.size(); i++) {
        v.push_back(s[i]);
        currentLine++;
    }
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

}
void Document::i(){
    writeI=true;
    currentLineI=currentLine-1;
}
void Document::c(){
    writeC=true;
}
void Document::d(){
    v.erase(v.begin() + currentLine);
    currentLine=currentLine-1;

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


bool Document::replace(string& str, const string& from, const string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}
