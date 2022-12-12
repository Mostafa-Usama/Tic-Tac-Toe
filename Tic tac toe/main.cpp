#include <iostream>
#include<algorithm>
#include <stdlib.h>
#include<time.h>
#include <windows.h>
using namespace std;

 HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void color(char x){

    if(x=='O')SetConsoleTextAttribute(h,12);
    else if(x=='X') SetConsoleTextAttribute(h,14);
    else SetConsoleTextAttribute(h,11);

}
bool choose (int x){

if (x != 1 && x !=2 && x != 3)
{
    cout << "Enter a valid option (1/2/3)" << endl;
    return false;
}
else return true;
}

int main()
{
int player1=0,comp=0,player2=0;

    srand(time(0));
    system("color 0B");

    cout << endl <<"                      Tic tac toe" << endl << endl << endl;

    while(true){

    int choice;
    cout << "Would you like to play against the computer or as 2 players? press 3 to quit(1/2/3): ";
    while(true){
    cin >> choice;
    if(choose(choice))
    break;
    }

    char arr[9];
    int c =0;
    for (int i = 49 ; i < 58; i++)
    {
        arr[c] = i;
        c++;
    }
    int xo;
    int turn =0;
    int computer;
// O = 79 X = 88

    if (choice == 3) {
        cout <<endl << "See you later" << endl;
        break;
    }
    cout << endl << endl << endl;
    cout <<"-------|------|-------"<< endl;
    cout <<"|      |      |      |"<< endl;
    cout <<"|  1   |   2  |   3  |"<< endl;
    cout <<"|      |      |      |"<< endl;
    cout <<"-------|------|-------"<< endl;
    cout <<"|      |      |      |"<< endl;
    cout <<"|  4   |   5  |   6  |"<< endl;
    cout <<"|      |      |      |"<< endl;
    cout <<"-------|------|-------"<< endl;
    cout <<"|      |      |      |"<< endl;
    cout <<"|  7   |   8  |   9  |"<< endl;
    cout <<"|      |      |      |"<< endl;
    cout <<"-------|------|-------"<< endl;
    cout << endl << endl << endl;

    if(choice == 2)
    {
        while (true)
        {

            if (turn == 9)
            {
            cout <<"It's a draw !!! try one more time" << endl << endl;
            cout << "Player1: " << player1 << "   Player2: " << player2 << endl<< endl;
                break;
            }
            if (turn % 2 ==0)
            {
                cout << "It's X's turn, Choose where to place your mark: ";
            }
            else
                cout << "It's O's turn, Choose where to place your mark: ";

            cin >> xo;
            if (xo >9 || xo < 1)
            {
                cout << "Enter a valid square" << endl;
                continue;
            }

            if (arr[xo-1] == 'X' || arr[xo-1] == 'O')
            {
                cout << "Square taken... choose another one" << endl;
                continue;
            }

            if (turn % 2 ==0)
            {
                arr[xo-1] ='X';
            }
            else
                arr[xo-1] ='O';

            turn++;

    cout << endl << endl << endl;
    cout <<"-------|------|-------"<< endl;
    cout <<"|      |      |      |"<< endl;
    cout <<"|  ";color(arr[0]);cout<<arr[0];
    color('0');
    cout<<  "   |   ";color(arr[1]);cout<<arr[1];
    color('0');
    cout<< "  |   ";color(arr[2]);cout<< arr[2];
    color('0');
    cout<< "  |"<< endl;
    cout <<"|      |      |      |"<< endl;
    cout <<"-------|------|-------"<< endl;
    cout <<"|      |      |      |"<< endl;
    cout <<"|  ";color(arr[3]);cout<<arr[3];
    color('0');
    cout<<  "   |   ";color(arr[4]);cout<<arr[4];
    color('0');
    cout<< "  |   ";color(arr[5]);cout<< arr[5];
    color('0');
    cout<< "  |"<< endl;
    cout <<"|      |      |      |"<< endl;
    cout <<"-------|------|-------"<< endl;
    cout <<"|      |      |      |"<< endl;
    cout <<"|  ";color(arr[6]);cout<<arr[6];
    color('0');
    cout<<  "   |   ";color(arr[7]);cout<<arr[7];
    color('0');
    cout<< "  |   ";color(arr[8]);cout<< arr[8];
    color('0');
    cout<< "  |"<< endl;    cout <<"|      |      |      |"<< endl;
    cout <<"-------|------|-------"<< endl;
    cout << endl << endl << endl;

            if ((arr[0] == arr[1]&& arr[1] == arr[2]) ||
                    (arr[3] == arr[4]&& arr[4] == arr[5]) ||
                    (arr[6] == arr[7]&& arr[7] == arr[8]) ||
                    (arr[0] == arr[3]&& arr[3] == arr[6]) ||
                    (arr[1] == arr[4]&& arr[4] == arr[7]) ||
                    (arr[2] == arr[5]&& arr[5] == arr[8]) ||
                    (arr[0] == arr[4]&& arr[4] == arr[8]) ||
                    (arr[2] == arr[4]&& arr[4] == arr[6]))
            {
        if (turn % 2 != 0){
            cout << "we have a winner, Player 1 Won!!" << endl<< endl;
            player1++;
            }
        else
            {

            cout << "we have a winner, Player 2 Won!!" << endl<<endl;
            player2++;

            }
            cout << "Player1: " << player1 << "   Player2: " << player2 << endl<< endl;
            break;
            }
        }
    }
    else if (choice == 1)
    {
        while (true)
        {
            if (turn == 9)
            {
            cout <<"It's a draw !!! try one more time" << endl<< endl;
            cout << "Player1: " << player1 << "   Computer: " << comp << endl<< endl;
                break;
            }
            if (turn % 2 ==0)
            {
                cout << "It's your turn, Choose where to place your mark: ";
                cin >> xo;
            if (xo >9 || xo < 1)
            {
                cout << "Enter a valid square" << endl;
                continue;
            }

            else if (arr[xo-1] == 'X'|| arr[xo-1] == 'O')
            {
                cout << "Square taken... choose another one" << endl;
                continue;
            }

            else
            {
                arr[xo-1] ='X';
            }

            }

            else
            {
                cout << "The computer is thinking...." << endl;
                Sleep(3000);

                // lord have mercy
            if (arr[0] == arr[1] &&(arr[2] != 'O' && arr[2] != 'X' )) computer = 3;
            else if (arr[3] == arr[4]&&(arr[5] != 'O' && arr[5] != 'X' )) computer = 6;
            else if (arr[6] == arr[7]&&(arr[8] != 'O' && arr[8] != 'X' )) computer = 9;
            else if (arr[0] == arr[3]&&(arr[6] != 'O' && arr[6] != 'X')) computer = 7;
            else if (arr[1] == arr[4]&&(arr[7] != 'O' && arr[7] != 'X')) computer = 8;
            else if (arr[2] == arr[5]&&(arr[8] != 'O' && arr[8] != 'X')) computer = 9;
            else if (arr[0] == arr[4]&&(arr[8] != 'O' && arr[8] != 'X')) computer = 9;
            else if (arr[2] == arr[4]&&(arr[6] != 'O' && arr[6] != 'X')) computer = 7;
            else if (arr[0] == arr[2]&&(arr[1] != 'O' && arr[1] != 'X' )) computer = 2; //
            else if (arr[3] == arr[5]&&(arr[4] != 'O' && arr[4] != 'X' )) computer = 5;
            else if (arr[6] == arr[8]&&(arr[7] != 'O' && arr[7] != 'X' )) computer = 8;
            else if (arr[0] == arr[6]&&(arr[3] != 'O' && arr[3] != 'X')) computer = 4;
            else if (arr[1] == arr[7]&&(arr[4] != 'O' && arr[4] != 'X')) computer = 5;
            else if (arr[2] == arr[8]&&(arr[5] != 'O' && arr[5] != 'X')) computer = 6;
            else if (arr[0] == arr[8]&&(arr[4] != 'O' && arr[4] != 'X')) computer = 5;
            else if (arr[2] == arr[6]&&(arr[4] != 'O' && arr[4] != 'X')) computer = 5;
            else if (arr[1] == arr[2]&&(arr[0] != 'O' && arr[0] != 'X' )) computer = 1; //
            else if (arr[4] == arr[5]&&(arr[3] != 'O' && arr[3] != 'X' )) computer = 4;
            else if (arr[7] == arr[8]&&(arr[6] != 'O' && arr[6] != 'X' )) computer = 7;
            else if (arr[3] == arr[6]&&(arr[0] != 'O' && arr[0] != 'X')) computer = 1;
            else if (arr[4] == arr[7]&&(arr[1] != 'O' && arr[1] != 'X')) computer = 2;
            else if (arr[5] == arr[8]&&(arr[2] != 'O' && arr[2] != 'X')) computer = 3;
            else if (arr[4] == arr[8]&&(arr[0] != 'O' && arr[0] != 'X')) computer = 1;
            else if (arr[4] == arr[6]&&(arr[2] != 'O' && arr[2] != 'X')) computer = 3;
            else{
                while(true){
                    computer = 1+(rand() % 9);
                    if (arr[computer-1] != 'O' && arr[computer-1] != 'X')
                        break;
                }
            }
                  arr[computer-1] = 'O';
            }

            turn++;

             cout << endl << endl << endl;
    cout <<"-------|------|-------"<< endl;
    cout <<"|      |      |      |"<< endl;
    cout <<"|  ";color(arr[0]);cout<<arr[0];
    color('0');
    cout<<  "   |   ";color(arr[1]);cout<<arr[1];
    color('0');
    cout<< "  |   ";color(arr[2]);cout<< arr[2];
    color('0');
    cout<< "  |"<< endl;
    cout <<"|      |      |      |"<< endl;
    cout <<"-------|------|-------"<< endl;
    cout <<"|      |      |      |"<< endl;
    cout <<"|  ";color(arr[3]);cout<<arr[3];
    color('0');
    cout<<  "   |   ";color(arr[4]);cout<<arr[4];
    color('0');
    cout<< "  |   ";color(arr[5]);cout<< arr[5];
    color('0');
    cout<< "  |"<< endl;
    cout <<"|      |      |      |"<< endl;
    cout <<"-------|------|-------"<< endl;
    cout <<"|      |      |      |"<< endl;
    cout <<"|  ";color(arr[6]);cout<<arr[6];
    color('0');
    cout<<  "   |   ";color(arr[7]);cout<<arr[7];
    color('0');
    cout<< "  |   ";color(arr[8]);cout<< arr[8];
    color('0');
    cout<< "  |"<< endl;    cout <<"|      |      |      |"<< endl;
    cout <<"-------|------|-------"<< endl;
    cout << endl << endl << endl;

            if ((arr[0] == arr[1]&& arr[1] == arr[2]) ||
                    (arr[3] == arr[4]&& arr[4] == arr[5]) ||
                    (arr[6] == arr[7]&& arr[7] == arr[8]) ||
                    (arr[0] == arr[3]&& arr[3] == arr[6]) ||
                    (arr[1] == arr[4]&& arr[4] == arr[7]) ||
                    (arr[2] == arr[5]&& arr[5] == arr[8]) ||
                    (arr[0] == arr[4]&& arr[4] == arr[8]) ||
                    (arr[2] == arr[4]&& arr[4] == arr[6]))
            {
                 if (turn % 2 != 0){
            cout << "we have a winner, Player 1 Won!!" << endl<< endl;
            player1++;
            }
        else
            {

            cout << "we have a winner, The computer won!!" << endl<<endl;
            comp++;

            }
            cout << "Player1: " << player1 << "   Computer: " << comp << endl<< endl;
                break;
            }
        }
    }

    }

    return 0;
}
