/*

#include "Editor.hpp"

void Editor::loop(){
// p prints the current line (ed maintains a current line)
    regex p("p");
// n prints line number of current line followed by TAB followed by current line
    regex n("n");
// %p prints all lines
    regex prAll("%p");
// 7 makes line #7 the current line
    regex changeLine(R"(\d)");
// a appends new text after the current line
    regex a("a");
// i inserts new text before the current line
    regex i("i");
// c changes the current line for text that follows
    regex c("c");
// d deletes the current line
    regex d("d");
// /text searches forward after current line for the specified text. The search wraps to the
// beginning of the buffer and continues down to the current line, if necessary
    regex src(R"(/\w+)");
// s/old/new/ replaces old string with new in current line (google: C++ split or token)
    regex swc(R"(s/\w+/\w+/?)");
// Q Quits the editor without saving
    regex Q("Q");
    regex w("w [.]");
    regex forNum("[0-9]*");
    regex forPlusMinusNum("[/+-]+[0-9]*");

    while(true){
        string work;
        int len = work.length();

        getline(cin,work);
        if(regex_match(work, swc)){
            //cout<<"swc"<<endl;
            string first=work.substr(2);
            int find1 =first.find("/");
            string one= first.substr(0,find1);
            int find2=first.rfind("/");
            string two;
            if(find2==find1) {
                two= first.substr(find1+1);
                //cout<<"in4"<<endl;
            }else{
                //cout<<first<<endl;
                two= first.substr((find1+1),find2-find1-1);
            }
            Doc->s(one,two);
            //  Doc->Q();
        }
        else if(regex_match(work, p)){
            // cout<<"p"<<endl;
            //  Doc->Q();
            Doc->p();
        }
        else if(regex_match(work, n)){
            // cout<<"n"<<endl;
            //  Doc->Q();
            Doc->n();
        }
        else if(regex_match(work, prAll)){
            //  cout<<"prAll"<<endl;
            //  Doc->Q();
            Doc->pAll();
        }
        else if(regex_match(work, changeLine)){
            // cout<<"changeLine"<<endl;
            //  Doc->Q();
            Doc->changeLine(stoi(work));//stoi string to int
        }
        else if(regex_match(work, a)){
            //  cout<<"a"<<endl;
            //   Doc->Q();
            Doc->a();
        }
        else if(regex_match(work, i)){
            // cout<<"i"<<endl;
            //  Doc->Q();
            Doc->i();
        }
        else if(regex_match(work, c)){
            // cout<<"c"<<endl;
            //  Doc->Q();
            Doc->c();
        }
        else if(regex_match(work, d)){
            //  cout<<"d"<<endl;
            //   Doc->Q();
            Doc->d();
        }
        else if(regex_match(work, src)){
            //  cout<<"src"<<endl;
            //   Doc->Q();
            string src=work.substr(1);
            Doc->search(src);
        }
        else if(regex_match(work,Q)){
            //   cout<<"Q"<<endl;
            Doc->Q();
        }
        else   if(work[0]=='w'){
            string temp1=work.substr(2,work.size());
            Doc->w(temp1);
            cout<<temp1<<endl;
            return;
        }
         else if( !work.compare("$")){
            Doc->dolar();

        }

        else if(regex_match(work,forPlusMinusNum)){ //פלוס מינוס מספר
            cout<<work+ " ";
            string temp=work.substr(1,work.length());

            int numberLine=stoi(temp);
            if(work[0]=='-')
                Doc->minus(numberLine);
            if(work[0]=='+')
                Doc->plus(numberLine);


        }

    }
}
*/



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
    regex prAll("%p");
    regex forPlusMinusNum("[/+-]+[0-9]*");
    static bool isText = false; //הראשון לא יהיה טקסט בטוח
    int len = line.length();
   /* if(isText){
       // document.write(line);
        //cout<<"write"<<endl;
        if(!line.compare("."))
            isText = false;
        return;
    }*/
    if(line.at(0) == '/'){
        document.sleshText(line.substr(1));
        return;
    }
     if(regex_match(line, prAll)){
        //  cout<<"prAll"<<endl;
        //  Doc->Q();
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
       // isText = true;
        document.a();
        //cout<<"a"<<endl;
        return;
    }
    if(!line.compare("i")){
        //isText = true;
        document.i();
       // cout<<"i"<<endl;
        return;
    }
    if(!line.compare("c")){
      //  isText = true;
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



