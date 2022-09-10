#include <iostream>
#include <limits>
#include <typeinfo>
#include <string>
#include <cstdlib>

using namespace std;

int intro();
void startPlayerVsPlayer();
void printDashboard(string *, char *);
string *askPlayerNames();
int evaluateEndConditions(char *);
void newMovement(char *, int, string *);
bool checkValidInt(int, int *, int);

int main()
{

    int option = 1;
    switch (option)
    {
    case 0:
        cout << "You has chosen Player vs Computer" << endl;

        break;
    case 1:
        cout << "You has chosen Player vs Player" << endl;
        startPlayerVsPlayer();
        break;
    case 2:
        cout << "You has chosen \"Exit\"" << endl;
        break;
    default:
        cout << "Something bad happen!" << endl;
        break;
    }

    return 0;
}

string *askPlayerNames()
{
    string *names = new string[2];
    cout << "Write Player 1 name: ";
    getline(cin, names[0], '\n');
    cout << "Write Player 2 name: ";
    getline(cin, names[1], '\n');
    return names;
}

void startPlayerVsPlayer()
{

    string *names = askPlayerNames();
    char dashboard[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int player = 0;
    int player1Win, player2Win, draw;
    int result;
    //while (true)
    //{
    cout<<"****"<<endl;
        do
        {
            printDashboard(names, dashboard);
            newMovement(dashboard, player, names);
            player = (player + 1) % 2;
            system("clear");
            result = evaluateEndConditions(dashboard);
        } while (result == -1);

        switch (result)
        {
        case 0:
            cout << "Player 1 won (" << names[0] << ")!";
            player1Win++;
            break;
        case 1:
            cout << "Player 2 won (" << names[1] << ")!";
            player2Win++;
            break;
        case 2:
            cout << "It has been a draw!" << endl;
            draw++;
            break;
        default:
            cout << "Something bad has happened!" << endl;
            break;
        }
        for (int i = 0; i < 9; i++)
        {
            *(dashboard + i) = ' ';
        }
    //}

    delete[] names;
}

void newMovement(char *dashboard, int player, string *names)
{
    char sym;
    if (player == 0)
    {
        sym = 'x';
    }
    else
    {
        sym = 'o';
    }

    string opt;
    int fDigit;
    int digitValidOptions[9] = {1,2,3,4,5,6,7,8,9};
    while(true) {
        cout << "Player " << player + 1 << " (" << *(names + player) << "). Choose an option: ";
        std::getline(cin, opt, '\n');
        if (opt.length() > 1)
        {
            cout << "Error. Choose a correct option!" << endl;
            continue;
        }
        if (isdigit(opt[0]))
        {
            int digit = std::stoi(opt);

            if (!checkValidInt(digit,digitValidOptions,9))
            {
                cout << "Error. Choose a valid int!" << endl;
            }
            else
            {
                fDigit = digit;
                break;
            }
        }
    }

    *(dashboard + fDigit - 1) = sym;
    return;
}

int evaluateEndConditions(char *dashboard)
{

    // Horizontal  lines
    if (dashboard[0] == 'x' && dashboard[1] == 'x' && dashboard[2] == 'x' || dashboard[3] == 'x' && dashboard[4] == 'x' && dashboard[5] == 'x' || dashboard[6] == 'x' && dashboard[7] == 'x' && dashboard[8] == 'x')
    {
        return 0;
    }

    // Horizonal lines o
    if (dashboard[0] == 'o' && dashboard[1] == 'o' && dashboard[2] == 'o' || dashboard[3] == 'o' && dashboard[4] == 'o' && dashboard[5] == 'o' || dashboard[6] == 'o' && dashboard[7] == 'o' && dashboard[8] == 'o')
    {
        return 1;
    }

    // Vertical lines x
    if (dashboard[0] == 'x' && dashboard[3] == 'x' && dashboard[6] == 'x' || dashboard[1] == 'x' && dashboard[4] == 'x' && dashboard[7] == 'x' || dashboard[2] == 'x' && dashboard[5] == 'x' && dashboard[8] == 'x')
    {
        return 0;
    }

    // Vertical lines o
    if (dashboard[0] == 'o' && dashboard[3] == 'o' && dashboard[6] == 'o' || dashboard[1] == 'o' && dashboard[4] == 'o' && dashboard[7] == 'o' || dashboard[2] == 'o' && dashboard[5] == 'o' && dashboard[8] == 'o')
    {
        return 1;
    }

    // Diagonal lines x
    if (dashboard[0] == 'x' && dashboard[4] == 'x' && dashboard[8] == 'x' || dashboard[2] == 'x' && dashboard[4] == 'x' && dashboard[6] == 'x')
    {
        return 0;
    }

    // Diagonal lines o
    if (dashboard[0] == 'o' && dashboard[4] == 'o' && dashboard[8] == 'o' || dashboard[2] == 'o' && dashboard[4] == 'o' && dashboard[6] == 'o')
    {
        return 1;
    }

    // Check if it is not a draw
    for (int i = 0; i < 9; i++)
    {
        if (*(dashboard + i) == ' ')
        {
            return -1;
        }
    }

    return 2;
}
void printDashboard(string *names, char *dasbhoard)
{

    cout << "Player 1 "
         << "(" << *names << "): [x]" << endl;
    cout << "Player 1 "
         << "(" << *(names + 1) << "): [o]" << endl;
    cout << "-------------                       -------------" << endl;
    cout << "| 1 | 2 | 3 |                       | " << dasbhoard[0] << " | " << dasbhoard[1] << " | " << dasbhoard[2] << " |" << endl;
    cout << "-------------                       -------------" << endl;
    cout << "| 4 | 5 | 6 |                       | " << dasbhoard[3] << " | " << dasbhoard[4] << " | " << dasbhoard[5] << " |" << endl;
    cout << "-------------                       -------------" << endl;
    cout << "| 7 | 8 | 9 |                       | " << dasbhoard[6] << " | " << dasbhoard[7] << " | " << dasbhoard[8] << " |" << endl;
    cout << "-------------                       -------------" << endl;
}

int intro()
{

    int option_rt;
    int digitValidOptions[3] = {0,1,2};
    string option;
    while (true)
    {

        cout << "Hi! Welcome to Tic-Tac-Toe! Choose an option" << endl;
        cout << "0. Player vs Computer\n1. Player vs Player\n2. Exit" << endl;
        cout << "Choose your option: ";

        std::getline(cin, option, '\n');
        if (option.length() > 1)
        {
            cout << "Error. Choose a correct option!" << endl;
            continue;
        }

        if (isdigit(option[0]))
        {
            int digit = std::stoi(option);

            if (!checkValidInt(digit,digitValidOptions,3))
            {
                cout << "Error. Choose a correct option!" << endl;
            }
            else
            {
                return digit;
            }
        }
    }
}

bool checkValidInt(int digit, int * validOptions,int sizeValidOptions)
{
    for (int i = 0; i <= sizeValidOptions; i++)
    {
        if(*(validOptions+i) == digit){
            return true;
        }
    }
    return false;
}
