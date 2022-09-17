#include <iostream>

using namespace std;

int intro();
int main() {
    intro();
    
    return 0;
}

int intro(){
    string introOption;
    while(true){
        cout<<"1. Player vs Player"<<endl;
        cout<<"2. Player vs IA"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"CHOOSE AN OPTION: ";
        getline(cin, introOption, '\n');
        cout<<"You have chosen: "<<introOption<<endl;
        
    }

    return 0;
}