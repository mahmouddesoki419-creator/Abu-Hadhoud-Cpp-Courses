#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

enum enQuestionsLevel { Easy = 1 , Med = 2 , Hard = 3 , Mix = 4 };
enum enOperationsType { Add = 1 , Sub = 2 , Mul = 3 , Div = 4 , MixOp = 5 };// + , - , * ,/
enum enPassOrNot { Pass = 1 , NotPass = 2 };

struct stResultQuizRound
{
    short QuizRound = 0;
    short Number1;
    short Number2 = 0;
    char Op;
    short result = 0;
    short resultUser = 0;
    enPassOrNot PassOrNot;
};

struct stResultGame
{
short numberOfQuizz = 0;
string Level = "";
string Op = "";
short CountRightAnswer = 0;
short CountWrongAnswer = 0;
};

int RandomNumber(int from , int to)
{
    return rand() % (to - from + 1) + from;
}

short ReadHowManyQuestions()
{
    short HowMany = 0;

    do 
    {
        cout << "How Many Questions do you want to answer ? ";
        cin >> HowMany;
    }while(HowMany < 1);

    return HowMany;
}

enQuestionsLevel ReadQuestionsLevel()
{
    short Level = 0;

    do 
    {
        cout << "Enter Questions level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";
        cin >> Level;
    }while(Level < 1 || Level > 4);

    return (enQuestionsLevel) Level;

}

enOperationsType ReadOperationType()
{
    short OpNumber = 0;

    do 
    {
        cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul , [4] Div, [5] Mix ? ";
        cin >> OpNumber;//4
    }while(OpNumber < 1 || OpNumber > 5);

    return (enOperationsType) OpNumber;
}

int ValidateLevel(enQuestionsLevel Level)// cheak level and send value 
{
    switch (Level)
    {
    case enQuestionsLevel::Easy:
    return RandomNumber(1 , 10);
        break;
    case enQuestionsLevel::Med:
    return RandomNumber(11 , 29);
        break;
    case enQuestionsLevel::Hard:
    return RandomNumber(30 , 99);
        break;
    }
    return RandomNumber(1 , 99);
}

char ValidateOp(enOperationsType OpType)
{
    switch(OpType)
    {
        case enOperationsType::Add:
        return '+';
        break;
        case enOperationsType::Sub:
        return '-';
        break;
        case enOperationsType::Mul:
        return '*';
        break;
        case enOperationsType::Div:
        return '/';
        break; 
    }
    return ValidateOp ((enOperationsType)RandomNumber(1 , 4));
//    
}

int CheakResultNumbers(stResultQuizRound Cheak)
{
    
    switch (Cheak.Op)
    {
    case '+':
    return Cheak.Number1 + Cheak.Number2;
        break;
    case '-':
    return Cheak.Number1 - Cheak.Number2;
        break;
    case '*':
    return Cheak.Number1 * Cheak.Number2;
        break;
    }
    return Cheak.Number1 / Cheak.Number2;
}

void FillRoundQuiz(stResultQuizRound &QuizRound)
{
     

    cout << QuizRound.Number1 << endl;
    cout << QuizRound.Number2 << " " << QuizRound.Op << endl;
    cout << "_______________________\n";
    cin >> QuizRound.resultUser;

}

string LevelQuiz(enQuestionsLevel LevelQuiz)
{
    string Level[4] = { "Easy" , "Mid" , "Hard" , "Mix"};
    return Level[LevelQuiz - 1];
}

string OpQuiz(enOperationsType OpType)
{
    string Op[5] = { " + " , " - " , " * ", " / " , " Mix "};
    return Op[OpType - 1];
}

void PrintpassOrNot(stResultGame CheakPassOrNot)
{
    cout << "______________________________________________\n";
    if(CheakPassOrNot.CountRightAnswer > CheakPassOrNot.CountWrongAnswer)
    {
        cout << "Final Results Is Pass :-)" << endl; 
    }
    else 
    {
        cout << "Final Results Is Fail :-(" << endl;
    }
    cout << "__________________________________________________\n";
}

void screenFinal(stResultGame ScreenFinal)
{
    if(ScreenFinal.CountRightAnswer >= ScreenFinal.CountWrongAnswer)
    {
        system("color 2F");
    }
    else 
        system("color 4F");
}

void PrintFinalResultsGame(stResultGame FinalResult)
{
cout << "Number Of Questions: " << FinalResult.numberOfQuizz << endl;
cout << "Questions Level    : " << FinalResult.Level << endl;
cout << "OpType             : " << FinalResult.Op << endl;
cout << "Number OF Right Answer: " << FinalResult.CountRightAnswer << endl;
cout << "Number Of Wrong Answer: " << FinalResult.CountWrongAnswer << endl;
cout << "\n________________________________________________\n";
screenFinal(FinalResult);
}

stResultGame FillResultsGame(short HowManyQuizz , short CountPass ,
     short CountNotPass , enQuestionsLevel Level , enOperationsType Op)
{
    stResultGame ResultGame;

    ResultGame.numberOfQuizz = HowManyQuizz;
    ResultGame.Level = LevelQuiz(Level);
    ResultGame.Op = OpQuiz(Op);
    ResultGame.CountRightAnswer = CountPass;
    ResultGame.CountWrongAnswer = CountNotPass;

    PrintpassOrNot(ResultGame);
    PrintFinalResultsGame(ResultGame);
    return  ResultGame ;
};

stResultGame LoopQuiz (short HowManyQuizz)
{
    stResultQuizRound ResultQuizRound;
    short CounterPass = 0;
    short CounterNotPass = 0;
    enQuestionsLevel Level =  ReadQuestionsLevel();
    enOperationsType OpType =  ReadOperationType();


    for(short quizRound = 1; quizRound <= HowManyQuizz; quizRound++)
    {
        cout << "\n\nQuestion [" << quizRound << "/" << HowManyQuizz << "]" << endl;
        ResultQuizRound.Number1 = ValidateLevel(Level);
        ResultQuizRound.Number2 = ValidateLevel(Level);
        ResultQuizRound.Op = ValidateOp(OpType);
        ResultQuizRound.result = CheakResultNumbers(ResultQuizRound);
        
        FillRoundQuiz(ResultQuizRound);

        if(ResultQuizRound.resultUser == ResultQuizRound.result)
        {
            cout << "Right Answer :-)\n";
            CounterPass++;
            system("color 2F");
        }   
        else
        {
            cout << "Wrong Answer :-(\n";
            cout << "The Right answer is: " << ResultQuizRound.result << endl;
            CounterNotPass++;
            system("color 4F");
            cout << "\a";
        } 


    }
    cout << "\n\n";

    return FillResultsGame(HowManyQuizz , CounterPass ,
         CounterNotPass , Level , OpType);
};

void ResetScreenColor()
{
    system("cls");
    system("color 0F");
}

void StartGame()
{
    char PlayAgain = 'Y';
    do 
    {
        ResetScreenColor();
        stResultGame ResultQuiz = LoopQuiz(ReadHowManyQuestions());
        cout << "Do you want to Play again? Y/N? ";
        cin >> PlayAgain;

    }while(PlayAgain == 'Y' || PlayAgain == 'y');

}

int main()
{
    srand((unsigned)time(NULL));
    StartGame();

    return 0;
}
