#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

int intro();
bool checkIntroOption(string);
void runOption(int);
bool checkStringValidValues(string, string *,int);
bool checkNewMove(string, char *);
void playerVsPlayer();
void playerVsIA();
void printDashboard(string *, char *, int , int *);

int main() {
    runOption(intro());


    return 0;
}


void runOption(int introOption){
    switch (introOption)
    {
    case 1:
        playerVsPlayer();
        break;
    case 2:
        playerVsIA();
        break;
    case 0:
        cout<<"Goodbye!"<<endl;
        break;
    default:
        break;
    }
}

void playerVsPlayer() {
    string players[2];
    char symbols[2] = {'x','o'};
    char dashboard[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int score[3] = {0,0,0};
    /*
    cout<<"Write name of first player: ";
    getline(cin, players[0], '\n');
    
    cout<<"Write name of second player: ";
    getline(cin, players[1],'\n');
    */
    players[0] = "miguel";
    players[1] = "carlos";

    int actualPlayer = 0;
    string newMove;
    while(true){
        system("clear");
        printDashboard(players,dashboard,actualPlayer,score);
        getline(cin,newMove,'\n');
        if(checkNewMove(newMove, dashboard)){
            dashboard[stoi(newMove)-1] = symbols[actualPlayer];
            actualPlayer = (actualPlayer+1)%2;
        }else{
            continue;
        }


    }

}

void playerVsIA() {

}

int intro(){
    string introOption;
    
    while(true){
        cout<<"1. Player vs Player"<<endl;
        cout<<"2. Player vs IA"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"CHOOSE AN OPTION: ";
        //getline(cin, introOption, '\n');
        introOption="1";
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

bool checkNewMove(string newMove, char * dashboard){
    int sizeValidInputValues = 9;
    string validInputValues[sizeValidInputValues] = {"1","2","3","4","5","6","7","8","9"};
    if(newMove.length() > 1){
        cout<<"You have chosen an invalid value, it has more than 1 character!"<<endl;
        return false;
    }
    if(!checkStringValidValues(newMove,validInputValues,sizeValidInputValues)){
        cout<<"You have chosen an invalid character, it should be x or o!"<<endl;
        return false;
    }

    if(dashboard[stoi(newMove)-1] != ' '){
        cout<<"There are already a symbol in this place!"<<endl;
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


void printDashboard(string *names, char *dasbhoard, int startPlayer, int * player1_player2_draw)
{

    if(startPlayer == 0){
        cout << "(" << *names << "): [x] (*)" << endl;
        cout << "(" << *(names + 1) << "): [o]" << endl;
    }else{
        cout << "(" << *names << "): [x]" << endl;
        cout << "(" << *(names+1) << "): [o] (*)" << endl;
    }
    cout<<"**************************************************************************************************"<<endl;
    cout<<names[0]+" win: "<<player1_player2_draw[0]<<"            "+ names[1]+" win: "<<player1_player2_draw[1]<<"               draws: "<<player1_player2_draw[2]<<endl;
    cout<<"**************************************************************************************************"<<endl; 
    cout << "-------------                       -------------" << endl;
    cout << "| 1 | 2 | 3 |                       | " << dasbhoard[0] << " | " << dasbhoard[1] << " | " << dasbhoard[2] << " |" << endl;
    cout << "-------------                       -------------" << endl;
    cout << "| 4 | 5 | 6 |                       | " << dasbhoard[3] << " | " << dasbhoard[4] << " | " << dasbhoard[5] << " |" << endl;
    cout << "-------------                       -------------" << endl;
    cout << "| 7 | 8 | 9 |                       | " << dasbhoard[6] << " | " << dasbhoard[7] << " | " << dasbhoard[8] << " |" << endl;
    cout << "-------------                       -------------" << endl;
}