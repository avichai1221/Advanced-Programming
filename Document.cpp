#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "Document.h"

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
}
void Document::minus(int number_line){
    currentLine=currentLine-number_line;


}
void Document::plus(int number_line){
    currentLine=currentLine+number_line;

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

}
void Document::a(){

    std::vector<string>::iterator it;
    while(true){
        it=v.begin()+(currentLine);
        string temp;
        getline(cin,temp);
        if(!temp.compare(".")) break;
        v.insert(it,temp);
        currentLine++;
    }
}
void Document::i(){

    currentLine=currentLine-1;
    std::vector<string>::iterator it;

    while(true){
        it=v.begin()+(currentLine);
        string temp;
        getline(cin,temp);
        if(!temp.compare(".")) break;
        v.insert(it++,temp);
        currentLine++;
    }
}
void Document::c(){
    std::vector<string>::iterator it;
 int save=currentLine;
    while(true){
        it=v.begin()+(currentLine-1);
        string temp;
        getline(cin,temp);
        if(!temp.compare(".")) break;
        currentLine=currentLine-1;
        v.erase((v.begin()+(currentLine)));
        currentLine=save;
        v.insert(it,temp);

    }

}
void Document::d(){
    v.erase((v.begin()+(currentLine-1)));
    currentLine--;
}
void Document::sleshText(string line){
    int temp=currentLine;
    for(int i = currentLine; i< v.size(); i++){

        size_t found = v[i].find(line);
        if(found !=  string::npos){
            currentLine=i+1;
            return;
        }
    }
    num(1);
    for(int j=0;j<temp;j++){
        size_t found = v[j].find(line);
        if(found !=  string::npos){
            currentLine=j+1;
            return;
        }
    }
    currentLine=v.size();
    cout<<currentLine<<endl;
}



void Document::j(){
    string temp=v[currentLine-1]+ v[currentLine];
    v[currentLine-1]=temp;
    v.erase(v.begin() + currentLine);
}
void Document::sOldNew(string oldText, string newText){
    replace(v[currentLine-1], oldText, newText);
}
bool Document::replace(string& str, const string& from, const string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}