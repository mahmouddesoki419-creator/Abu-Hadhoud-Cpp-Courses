#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enGameChoice { Stone = 1 , Paper = 2 , Scissors = 3 };//بتخزن قيم ارقام 
enum enWinner { Player1  = 1 , Computer = 2 , Draw = 3 };//سيم /^/

struct stRoundinfo 
{
    short RoundNumber = 0;
    enGameChoice Player1Choice;//readPlayer1Choice
    enGameChoice Computer;//get comp
    enWinner Winner;
    string WinnerName;
};

struct stGameResults 
{
short GameRounds = 0;
short player1WinTimes = 0;
short ComputerWinTimes = 0;
short DrawTimes = 0;
enWinner GameWinner;
string WinnerName = "";   
};

short RandomNumber(short from , short to)
{
    return rand() % (to - from + 1) + from;
}

short ReadHowManyRounds()
{
    short HowManyRounds = 0;
    do 
    {
        cout << "How Many Rounds 1 to 10 ? \n";
        cin >> HowManyRounds;
    }while(HowManyRounds > 10 || HowManyRounds < 1);
    return HowManyRounds;
}

enGameChoice ReadPlayer1Choice()
{
    short Player1Choice = 1;

    do 
    {
        cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors?  ";
        cin >> Player1Choice;
    }while(Player1Choice < 1 || Player1Choice > 3);

    return (enGameChoice) Player1Choice;
}

enGameChoice GetComputerChoice()
{
    return (enGameChoice) RandomNumber(1 , 3);
}

enWinner WhoWonTheRound(stRoundinfo RoundInfo)
{
    if(RoundInfo.Player1Choice == RoundInfo.Computer)
    {
        return enWinner::Draw;
    }

    switch (RoundInfo.Computer)
    {
    case enGameChoice::Stone:
        if(RoundInfo.Player1Choice == enGameChoice::Paper)
        {
            return enWinner::Player1;
        }
        break;

    case enGameChoice::Paper:
        if(RoundInfo.Player1Choice == enGameChoice::Scissors)
        {
            return enWinner::Player1;
        } 
        break;

    case enGameChoice::Scissors:
        if(RoundInfo.Player1Choice == enGameChoice::Stone)
        {
            return enWinner::Player1;       
        }
        break;
    
    }

    return enWinner::Computer;
}

string WinnerName(enWinner Winner)
{
    string arrGameChoice[3] = { "player1" , "Computer" , "Draw"};
    return arrGameChoice[Winner - 1];
    
}

string ChoiceName(enGameChoice ChoiceRound)
{
    string Choice[3] ={ "Stone" , "Paper" , "Scissors"};
    return Choice[ChoiceRound - 1]; 
}

void SetScreenOf_Color(enWinner Winner)
{
    switch(Winner)
    {
        case enWinner::Player1:
            system("color 2F"); //turn screen Green is win
            break;
        case enWinner::Computer:
            system("color 4F");//turn screen red is lose
            cout << "\a";
            break;
        default:
            system("color 6F");// is draw turn yellow
            break;  
    }
}

void PrintRound_Results(stRoundinfo RoundInfo)
{
    cout << "\n___________________ [" << RoundInfo.RoundNumber << "] ______________________\n\n";
    cout << "Player1 Choice : " << ChoiceName(RoundInfo.Player1Choice ) << endl;
    cout << "Computer Choice: " << ChoiceName(RoundInfo.Computer) << endl;
    cout << "Round Winner   : " << RoundInfo.WinnerName << endl;
    SetScreenOf_Color(RoundInfo.Winner);
    cout << "_________________________________________________________________________\n" << endl;


}

string Tabs(short CountTabs)
{
    string T = "";
    for(int i = 1; i < CountTabs; i++)
    {
        T += "\t"; 
    }
    return T;
}

void ShowGameOverScreen()
{
    cout << Tabs(2) << "_____________________________________________________\n\n";
    cout << Tabs(2) << "                  +++ G a m e   O v e r +++\n\n";
    cout << Tabs(2) << "_____________________________________________________\n\n";

}

enWinner WhoWonTheGame(short Player1 , short Computer)// comparison 
{
    if(Player1 > Computer)
        return enWinner::Player1;
    else if(Computer > Player1)
        return enWinner::Computer;
    else 
        return enWinner::Draw;
}

stGameResults FillGameResults(short GameRounds , 
short Player1WinTimes , short ComputerWinTimes , short DrawTimes)
{
    stGameResults GameResults;
    GameResults.GameRounds = GameRounds;
    GameResults.player1WinTimes = Player1WinTimes;
    GameResults.ComputerWinTimes = ComputerWinTimes;
    GameResults.DrawTimes = DrawTimes;
    GameResults.GameWinner = WhoWonTheGame(Player1WinTimes , ComputerWinTimes);
    GameResults.WinnerName = WinnerName(GameResults.GameWinner);
    return GameResults;
}

void ShowFinalGameResults(stGameResults GameResults)
{
    cout << Tabs(2) << "***************** [  Game Results  ] *************************\n";
    cout << Tabs(2) << "Game Rounds       : " << GameResults.GameRounds << endl;
    cout << Tabs(2) << "Player1 Won Times : " << GameResults.player1WinTimes << endl;
    cout << Tabs(2) << "Computer Won Times: " << GameResults.ComputerWinTimes << endl;
    cout << Tabs(2) << "Draw Times        : " << GameResults.DrawTimes << endl;
    cout << Tabs(2) << "Final Winner      : " << GameResults.WinnerName << endl;
    cout << Tabs(2) << "____________________________________________________________\n";
    SetScreenOf_Color(GameResults.GameWinner);

}

stGameResults  PlayGame(short HowManyRounds)
{
stRoundinfo RoundInfo;
short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

for(int GameRound = 1; GameRound <= HowManyRounds; GameRound++)
{
    cout << "\nRound [" << GameRound << "] begins: \n";
    
    RoundInfo.RoundNumber = GameRound;
    RoundInfo.Player1Choice = ReadPlayer1Choice();
    RoundInfo.Computer = GetComputerChoice();
    RoundInfo.Winner = WhoWonTheRound(RoundInfo);
    RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);


    //Increase WIN / Draw Counters
    if(RoundInfo.Winner == enWinner::Player1)
        Player1WinTimes++;
    else if(RoundInfo.Winner == enWinner::Computer)
        ComputerWinTimes++;
    else 
        DrawTimes++;


    PrintRound_Results(RoundInfo); 

}
   return FillGameResults(HowManyRounds , Player1WinTimes , ComputerWinTimes , DrawTimes);
};

void ResetScreen()
{
    system("cls");//Clean screen
    system("color 0F");//turn black color
}

void StartGame()
{
    char PlayAgain = 'Y';
    do 
    {
        ResetScreen();
        stGameResults GameResults = PlayGame(ReadHowManyRounds());
        ShowGameOverScreen();
        ShowFinalGameResults(GameResults);

        cout << endl << Tabs(3) << "Do you want to play Again ? Y/N? ";
        cin >> PlayAgain;
    }while(PlayAgain == 'Y' || PlayAgain == 'y');

}

int main()
{
    srand((unsigned)time(NULL));
    StartGame();

    return 0;
}
