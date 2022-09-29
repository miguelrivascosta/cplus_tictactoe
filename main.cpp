#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

int intro();
bool checkIntroOption(string);
void runOption(int);
bool checkStringValidValues(string, string *,int);
string checkNewMove(string, char *);
void playerVsPlayer();
void playerVsIA();
void printDashboard(string *, char *, int , int *);
string checkEndConditions(char *, string, char);
bool checkWinner(char *, char);
bool checkDraw(char *);
void updateScores(char *, int *);
void inicializeDashboard(char*);
bool checkPlayAgainOption(string);
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
    int scores[3] = {0,0,0};
    /*
    cout<<"Write name of first player: ";
    getline(cin, players[0], '\n');
    
    cout<<"Write name of second player: ";
    getline(cin, players[1],'\n');
    */
    players[0] = "miguel";
    players[1] = "carlos";

    int startPlayer = 0;
    int actualPlayer = 0;
    string newMove;
    string mssg;
    while(true){
        mssg = "";
        while(true){
            system("clear");

            if(mssg != ""){
                cout<<mssg<<endl;
            }

            printDashboard(players,dashboard,actualPlayer,scores);
            getline(cin,newMove,'\n');
            mssg = checkNewMove(newMove, dashboard);

            if(mssg == ""){
                dashboard[stoi(newMove)-1] = symbols[actualPlayer];  
            }else{
                continue;
            }

            mssg = checkEndConditions(dashboard, players[actualPlayer], symbols[actualPlayer]);
            
            if(mssg == ""){
                actualPlayer = (actualPlayer+1)%2;
                continue;
            }else{
                cout<<mssg<<endl<<endl;
                break;
            }
        }
        
        updateScores(dashboard,scores);
        inicializeDashboard(dashboard);

        string playAgainOption;

        while(true){
            cout<<"Do you want to play again? (y/n): ";
            getline(cin, playAgainOption, '\n');


            if(!checkPlayAgainOption(playAgainOption)){
                cout<<"Choose a correct option!";
            }else{
                if(playAgainOption == "n"){
                    return;
                }else{
                    startPlayer = (startPlayer+1)%2;
                    actualPlayer = startPlayer;
                    break;
                }
            }
        }
    }
    

}

bool checkPlayAgainOption(string playAgainOption){

    if(playAgainOption != "y" && playAgainOption != "n"){
        return false;
    }else{
        return true;
    }

}
void inicializeDashboard(char * dashboard){
    for (int i = 0; i < 9; i++)
    {
        dashboard[i] = ' ';
    }
    
}

void updateScores(char * dashboard, int * scores){
    if(checkDraw(dashboard)){
        scores[2]++;
    }else if(checkWinner(dashboard,'x')){
        scores[0]++;
    }else{
        scores[1]++;
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

string checkNewMove(string newMove, char * dashboard){
    int sizeValidInputValues = 9;
    string validInputValues[sizeValidInputValues] = {"1","2","3","4","5","6","7","8","9"};
    string mssg = "";
    if(newMove.length() > 1){
        return "You have chosen an invalid value, it has more than 1 character!";
    }
    if(!checkStringValidValues(newMove,validInputValues,sizeValidInputValues)){
        return "You have chosen an invalid character, it should be x or o!";
        
    }

    if(dashboard[stoi(newMove)-1] != ' '){
        return "There are already a symbol in this place!";
        
    }
    return "";
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

string checkEndConditions(char * dashboard, string name, char sym){

        if(checkWinner(dashboard,sym)){
            return name+" won!";
        } else if(checkDraw(dashboard)){
            return "It was a draw";
        } else{
            return "";
        }
}

bool checkWinner(char * dashboard,char sym){
    if ( (dashboard[0] == sym) && (dashboard[1] == sym) && (dashboard[2] == sym) || (dashboard[3] == sym) && (dashboard[4] == sym) && (dashboard[5] == sym) || (dashboard[6] == sym) && (dashboard[7] == sym) && (dashboard[8] == sym))
    {
        return true;
    }

    if (dashboard[0] == sym && dashboard[3] ==  sym && dashboard[6] == sym || dashboard[1] == sym && dashboard[4] == sym && dashboard[7] == sym || dashboard[2] == sym && dashboard[5] == sym && dashboard[8] == sym)
    {
        return true;
    }

    // Diagonal lines x
    if (dashboard[0] == sym && dashboard[4] == sym && dashboard[8] == sym || dashboard[2] == sym && dashboard[4] == sym && dashboard[6] == sym)
    {
        return true;
    }

    return false;
}

bool checkDraw(char * dashboard){
    for (int i = 0; i < 9; i++)
    {
        if(dashboard[i] == ' '){
            return false;
        }
    }
    return true;
}