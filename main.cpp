#include <iostream>
#include <fstream>
#include "Editor.h"



int main(int argc, char* argv[]) {


    switch (argc) {
        case 1: {
            Editor editor;
            editor.loop();
            break;
        }
        case 2: {
            vector<string> vector;

            ifstream file;
            string fileName=argv[1];
            file.open(fileName,ios::out);
            string tp;
            while(getline(file, tp)){ //read data from file object and put it into string.
                vector.push_back(tp);
            }
            Editor editor(vector);
            editor.loop();
            break;
        }


    }

    return 0;
}
