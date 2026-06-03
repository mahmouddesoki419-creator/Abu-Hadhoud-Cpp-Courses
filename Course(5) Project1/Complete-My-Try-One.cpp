#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

enum enItemsToy { Stone = 1 , Paper = 2 , Scissors = 3};

enum enWinner { Player = 1 , Computer = 2 , NoWinner = 3};

int randomNumber(int from , int to)
{
    int randNum = rand() % (to - from + 1) + from;
    return randNum;
}

int NumberPlayer(string message)
{   
        int numberChoicePlayer = 0;

        do 
        {
            cout << message;
            cin >> numberChoicePlayer;
        }while(numberChoicePlayer > 3 || numberChoicePlayer < 1);

        cout << "\n";
        return numberChoicePlayer;
}

int readHowManyRound(int from, int to)
{
    int rounds = 0;
    do
    {
        cout << "How many Rounds " << from << " to " << to << endl;
        cin >> rounds;
    } while (rounds > to || rounds < from);

    return rounds;
}

string printItems(int numberItem)
{
    switch (numberItem)
    {
    case 1:
    return "Stone";
        break;
    case 2:
    return "Paper";
    break;
    case 3:
    return "Scissors";
    break;
    default: return 0;
    break;
    }
}

enWinner WhoWonTheRound(enItemsToy numP1 , enItemsToy numComputer)
{
    if(numP1 == numComputer) return enWinner::NoWinner;
    
    if ((numP1 == enItemsToy::Stone && numComputer == enItemsToy::Scissors) || 
        ( numP1 == enItemsToy::Paper && numComputer == enItemsToy::Stone) || 
        (numP1 == enItemsToy::Scissors && numComputer == enItemsToy::Paper))
        {
            return enWinner::Player;
        }
    else 
            return enWinner::Computer;
}

string WinnerName(enWinner Winner)
{
    string arrWinnerName[] = { "" , "Player1" , "Computer" , "NoWinner"};
    return arrWinnerName[Winner];
}

string mostWinner(int p1 , int computer )
{
    if(p1 > computer)
    {
        return "Player1";
    }
    else if(computer > p1)
    {
        return "Computer";
    }
    else
    return "No Winner";
}

bool AskPlayAgain()
{
    char YOrN;
    cout << "\t\tDo you want to play again? Y/N? ";
    cin >> YOrN;
    while(YOrN != 'Y' && YOrN != 'y' && YOrN != 'n' && YOrN != 'N')
    {
        cout << "\t\tEnter an error, please select( Y / N )? ";
        cin >> YOrN;
    }

    if(YOrN == 'Y' || YOrN == 'y')
    return true;
    else 
    return false;
}


void LoobPrintRounds()
{
    int countRound = readHowManyRound(1 , 10);
    int counterP1Won = 0;
    int counterComputerWon = 0;
    int counterDrawTimes = 0;
    do 
    {
    for(int i = 0; i < countRound; i++ )
    {        
        cout << "\nRound ["<< i + 1 << "] begins:" << endl;
        enItemsToy PlayerChoice = (enItemsToy) NumberPlayer("Your Choice: [1]:stone, [2]:Paper, [3]:Scissors ? ");
        enItemsToy ComputerChoice = (enItemsToy) randomNumber(1 , 3);

        enWinner RoundWinner = WhoWonTheRound(PlayerChoice , ComputerChoice);

        cout << "_________________Round[" << i + 1 << "] __________________" << endl;
        cout << "\nPlayer1   Choice: " << printItems(PlayerChoice) << endl;
        cout << "Computer Choice : " << printItems(ComputerChoice) << endl;

        cout << "Round Winner    : [" << WinnerName(RoundWinner)  << "]"<< endl;
        if(RoundWinner == enWinner::Computer)
        {
            cout << "\a";
            counterComputerWon++;
        }
        else if(RoundWinner == enWinner::Player)
        {
            counterP1Won++;
        }
        else 
        {
            counterDrawTimes++;
        }

        cout << "____________________________________________________\n\n\n";
        
    }

    cout << "\t\t_______________________________________________\t" << endl;
    cout << "\n\t\t\t+++ G a m e   O v e r +++\t\t" << endl; 
    cout << "\t\t_________________________________________________\t" << endl;
    cout << "\n\t    _____________________ [  Game Result ]_____________________" << endl;

    cout << "\tGame Round           : " << countRound << endl;
    cout << "\tPlayer1 Won Times    : " << counterP1Won << endl;
    cout << "\tComputer Won Times   : " << counterComputerWon << endl;
    cout << "\tDraw Times           : " << counterDrawTimes << endl;
    cout << "\tFinal Winner         : " << mostWinner(counterP1Won , counterComputerWon) << endl;
    cout << "\t______________________________________________________________________\n";
    }
while(AskPlayAgain());
}


int main()
{
    srand((unsigned)time(NULL));
    LoobPrintRounds();

    return 0;
}
