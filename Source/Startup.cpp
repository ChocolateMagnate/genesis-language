/* MIT License (C) Genesis Contributors
 * This file is the central roadmap for the whole compiler that 
 * binds all components together. For more detailed description 
 * take a look at Source/Front-end.cpp. For the compiler implementation,
 * see Source/Genesis.cpp for the inner language's features parsing.*/
#include <iostream>
#include <fstream>
#include <string>
#include "Back-end.cpp"
#include "Front-end.cpp"
#include "Genesis.cpp"
using namespace std;

int main(){
    cout << "Genesis Compiler v0.1" << endl;
    string statement;
    ifstream source("/workspaces/genesis/Samples/code.gen");
    if (source.is_open()){
        bool condition = true;
        cout << "Source code loaded." << endl;
        for (int i = 0; i < 4; i++){
            getline(source, statement);
            auto data = cleanseComments(statement, condition);
            auto processed = get<0>(data);
            condition = get<1>(data);
            cout << "Source code: " << endl << statement << endl;
            cout << "Formatted code: " << endl << processed << endl;
        }
        source.close();
    }
    return 0;
}