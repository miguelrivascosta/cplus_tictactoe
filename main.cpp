#include <iostream>
#include <string.h>
using namespace std;

int intro();
bool checkIntroOption(string);
bool checkStringValidValues(string, string *,int);
int main() {
    int introOption = intro();
    cout<<"INTRO: "<<introOption<<endl;
    
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

        if(checkIntroOption(introOption)){
            cout<<"You have chosen: "<<introOption<<endl;
            return stoi(introOption);
        }else{
            continue;
        }
        
    }
}

bool checkIntroOption(string introOption){
    string validInputValues[3] = {"0","1","2"};
    if(introOption.length() > 1){
        cout<<"You have chosen an invalid value, it has more than 1 character!"<<endl;
        return false;
    }
    if(!checkStringValidValues(introOption,validInputValues,3)){
        cout<<"You have chosen an invalid character, it should be 0, 1 or 2!"<<endl;
        return false;
    }
    return true;
}

bool checkStringValidValues(string value,string * validValues, int size){

    for (int i = 0; i < size; i++)
    {
        if(value.compare(validValues[i]) == 0){
            return true;
        }
    }
    return false;
}