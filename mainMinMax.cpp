#include <iostream>
#include <cstdlib>

void newMovement(char *, char);
int minmax(char *, bool);
bool checkWinner(char *, char);
bool checkDraw(char *);
int * emptyCells(char *, int);
int countEmptyCells(char *);
void printDashboard(char *);
bool checkEndConditions(char *);
int max(int,int);
int min(int,int);
void copyArrays(char *, char *);

int main() {
    /*char dashboard[9] = {'o',' ','x',
                         'x',' ',' ',
                        'x','o','o'};*/

    char dashboard[9] = {' ',' ',' ',
                         ' ',' ',' ',
                         ' ',' ',' '};
    //char dashboard[9] = {' ',' ',' ',' ',' ',' ',' ','x','o'};
    /*char dashboard[9] = {'x','o',' ',' ',' ',' ',' ',' ',' '};*/
    //int nEmptyCells = countEmptyCells(dashboard);

    int startPlayer = 0, actualPlayer = 0;

    char sym[2] = {'x','o'};

    int nEmptyCells;
    int * arrayEmptyCells;
    
    dashboard[rand()%10] = 'x';
    actualPlayer++;
    do{
        std::cout<<"****"<<std::endl;
        printDashboard(dashboard);
        std::cout<<"****"<<std::endl;
        if(actualPlayer == 0){
            
            
            //newMovement(dashboard,sym[actualPlayer]);
            nEmptyCells = countEmptyCells(dashboard);
            arrayEmptyCells = emptyCells(dashboard,nEmptyCells);
            int bestValue = -1;
            int newPosition;
            for (int i = 0; i < nEmptyCells; i++)
            {
                char * newDashboard = new char[9];
                copyArrays(newDashboard,dashboard);
                newDashboard[arrayEmptyCells[i]] = 'x';
                int newValue = minmax(newDashboard,false);
                if(newValue>bestValue){
                    newPosition = arrayEmptyCells[i];
                }
                
                //std::cout<<arrayEmptyCells[i]<<std::endl;
                delete [] newDashboard;
                
            }
            dashboard[newPosition] = 'x';
            delete [] arrayEmptyCells;
        }else{
            int position;
            std::cout<<"Choose a position: ";
            std::cin>>position;
            dashboard[position-1] = 'o';
        }
        actualPlayer = (actualPlayer+1)%2;
    }while(!checkEndConditions(dashboard));
    printDashboard(dashboard);
    std::cout<<"The game has finished!"<<std::endl;



}


bool checkEndConditions(char * dashboard){

        if(checkWinner(dashboard,'x')){
            std::cout<<"Player with \"x\" won!"<<std::endl;
            return true;
        } else if(checkWinner(dashboard,'o')){
            std::cout<<"Player with \"o\" won!"<<std::endl;
            return true;
        } else if(checkDraw(dashboard)){
            std::cout<<"It was a draw"<<std::endl;
            return true;
        } else{
            return false;
        }

}
void printDashboard(char * dashboard){
    for (int i = 0; i < 9; i++)
    {       

        if(dashboard[i] != ' '){
            std::cout<<dashboard[i];
        }else{
            std::cout<<i+1;
        }
        if((i+1)%3==0){
            std::cout<<std::endl;
        }
    }
    std::cout<<std::endl;
}

void newMovement(char * dashboard, char sym){
    int newMove;
    std::cout<<"Put the new move: ";
    std::cin>>newMove;
    dashboard[--newMove] = sym;
}

int countEmptyCells(char * dashboard){
    int ctd = 0;
    for (int i = 0; i < 9; i++)
    {
        if(dashboard[i] == ' '){
            ctd++;
        }
    }
    return ctd;
}

int * emptyCells(char * dashboard, int nEmptyCells){
    int ctd = 0;
    int * arrayEmptyCells = new int[nEmptyCells];
    for (int i = 0; i < 9; i++)
    {
        if(dashboard[i] == ' '){
            arrayEmptyCells[ctd++] = i;
        }
    }

    return arrayEmptyCells;
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

void copyArrays(char * newDashboard, char * dashboard){
    for (int i = 0; i < 9; i++)
    {
        newDashboard[i] = dashboard[i];
    }
    
}


int max(int a,int b){
    if(a>=b){
        return a;
    }else{
        return b;
    }
}

int min(int a, int b){
    if(a<=b){
        return a;
    }else{
        return b;
    }
}
int minmax(char * dashboard, bool isMaximizing){
    printDashboard(dashboard);
    
    if(checkWinner(dashboard,'x')){
        return 1;
    } else if(checkWinner(dashboard,'o')) {
        return -1;
    } else if(checkDraw(dashboard)){
        return 0;
    }

    int nEmptyCells = countEmptyCells(dashboard);
    int * arrayEmptyCells = emptyCells(dashboard,nEmptyCells);
    if(isMaximizing){
        int bestVal = -1;
        int newPosition;
        for (int i = 0; i < nEmptyCells; i++)
        {
            char * newDashboard = new char[9];
            copyArrays(newDashboard,dashboard);
            newDashboard[arrayEmptyCells[i]] = 'x';
            int newValue = minmax(newDashboard,!isMaximizing);
            if(newValue>bestVal){
                newPosition = arrayEmptyCells[i];
                bestVal = newValue;
            }
            //bestVal = max(bestVal,value);
            delete [] newDashboard;
        }
        delete [] arrayEmptyCells;
        return bestVal;
    }else{
        int bestVal = +1;
        int newPosition;
        for (int i = 0; i < nEmptyCells; i++)
        {
            char * newDashboard = new char[9];
            copyArrays(newDashboard,dashboard);
            newDashboard[arrayEmptyCells[i]] = 'o';
            int newValue = minmax(newDashboard,!isMaximizing);
            if(newValue<bestVal){
                newPosition = arrayEmptyCells[i];
                bestVal = newValue;
            }
            //bestVal = min(bestVal,value);
            delete [] newDashboard;
        }
        delete [] arrayEmptyCells;
        return bestVal;
    }

    delete [] arrayEmptyCells;
    return 0;
}


/*
function minimax(board, depth, isMaximizingPlayer):

    if current board state is a terminal state :
        return value of the board
    
    if isMaximizingPlayer :
        bestVal = -INFINITY 
        for each move in board :
            value = minimax(board, depth+1, false)
            bestVal = max( bestVal, value) 
        return bestVal

    else :
        bestVal = +INFINITY 
        for each move in board :
            value = minimax(board, depth+1, true)
            bestVal = min( bestVal, value) 
        return bestVal 
*/