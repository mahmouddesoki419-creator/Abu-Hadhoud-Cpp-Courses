#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

enum enQuestionsLevel { EasyLevel = 1 , MedLevel = 2 , HardLevel = 3 , Mix = 4 };
enum enOperationsType { Add = 1 , Sub = 2 , Mul = 3 , Div = 4 , MixOp = 5 };// + , - , * ,/

int RandomNumber(int from , int to)
{
    return rand() % (to - from + 1) + from;
}

struct stQuestion
{
int Number1 = 0;
int Number2 = 0;
enQuestionsLevel Level;
enOperationsType Op;
int CorrectAnswer = 0;
int PlayerAnswer = 0;
bool AnswerResult = false;
};

struct stQuizz
{
    stQuestion QuestionList[100];
    short NumberOfQuestions;
    enQuestionsLevel SelectedLevel;
    enOperationsType OpType;
    short NumberOfWrongAnswers = 0;
    short NumberOfRightAnswers = 0;
    bool isPass = false;
};

short ReadHowManyQuestions()
{
    short NumberOfQuestions;
    do 
    {
        cout << "How Many Questions do you want to answer ? ";
        cin >> NumberOfQuestions;
    }while(NumberOfQuestions < 1 || NumberOfQuestions > 10);

    return NumberOfQuestions;
}

enQuestionsLevel ReadQuestionLevel()
{
    short questionLevel; 
    do 
    {
        cout << "Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";
        cin >> questionLevel;
    }while(questionLevel < 1 || questionLevel > 4);

    return (enQuestionsLevel)questionLevel;
}

enOperationsType ReadOpType()
{
    short OpType;
    do 
    {
        cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ";
        cin >> OpType;
    }while(OpType < 1 || OpType > 5);

    return (enOperationsType)OpType;
}

enOperationsType GetRandomOperationType()
{
    int Op = RandomNumber(1 , 4);
    return (enOperationsType) Op;
}

int SimpleCalculator(int Number1 , int Number2 , enOperationsType OpType)
{
    switch (OpType)
    {
    case enOperationsType::Add:
        return Number1 + Number2;
    case enOperationsType::Sub:
        return Number1 - Number2;
    case enOperationsType::Mul:
        return Number1 * Number2;
    case enOperationsType::Div:
        return Number1 / Number2;
    
    default:
        return Number1 + Number2;
    }
}

stQuestion GenrateQuestion(enQuestionsLevel QuestionLevel , enOperationsType OpType )// paremetars = +-*/نوع ادخال ليفل و العمليه 
{
    stQuestion Question;
    if(QuestionLevel == enQuestionsLevel::Mix)
    {
        QuestionLevel = (enQuestionsLevel) RandomNumber(1 ,3);// لو ماكس ايفض يسئل راندوم كل لفه ايختار واحده عشوائي
    }

    if(OpType == enOperationsType::MixOp)
    {
        OpType = GetRandomOperationType();
    }
    Question.Op = OpType;

    switch(QuestionLevel)
    {
    case enQuestionsLevel::EasyLevel:
        Question.Number1 = RandomNumber(1 , 10);
        Question.Number2 = RandomNumber(1 , 10);

        Question.CorrectAnswer = SimpleCalculator(Question.Number1 , Question.Number2 , Question.Op);
        Question.Level = QuestionLevel;//// ايرجع فقط القيمه المدخله من اليوذر 
        return Question;

    case enQuestionsLevel::MedLevel:
        Question.Number1 = RandomNumber(10 , 50);
        Question.Number2 = RandomNumber(10 , 50);

        Question.CorrectAnswer = SimpleCalculator(Question.Number1 , Question.Number2 , Question.Op);
        Question.Level = QuestionLevel;// ايرجع فقط القيمه المدخله من اليوذر 
        return Question;

    case enQuestionsLevel::HardLevel:
        Question.Number1 = RandomNumber(50 , 100);
        Question.Number2 = RandomNumber(50 , 100);

        Question.CorrectAnswer = SimpleCalculator(Question.Number1 , Question.Number2 , Question.Op);
        Question.Level = QuestionLevel;// ايرجع فقط القيمه المدخله من اليوذر 
        return Question; 
    }
    return Question;
}

void GenerateQuizzQuestions(stQuizz &Quizz)
{
    for(int Question = 0; Question < Quizz.NumberOfQuestions;Question++)//loop for read all questions علي حسب عدد مرات 
    {
        Quizz.QuestionList[Question] = GenrateQuestion(Quizz.SelectedLevel , Quizz.OpType);//read one question 
    }
}

string GetOpTypeSymbol(enOperationsType OpType)
{
    switch(OpType)
    {
    case enOperationsType::Add:
        return "+";
    case enOperationsType::Sub:
        return "-";
    case enOperationsType::Mul:
        return "*";
    case enOperationsType::Div:
        return "/";
    default:
        return "Mix";
    }
}

void PrintTheQuestion(stQuizz& Quizz , short QuestionNumber)
{
    cout << "\n";
    cout << "Question [" << QuestionNumber + 1 << "/" << Quizz.NumberOfQuestions << "]\n\n";
    cout << Quizz.QuestionList[QuestionNumber].Number1 << endl;
    cout << Quizz.QuestionList[QuestionNumber].Number2 << endl;
    cout << GetOpTypeSymbol(Quizz.QuestionList[QuestionNumber].Op);
    cout << "\n______________" << endl;
}

int ReadQuestionAnswer()
{
int Answer;
cin >> Answer;
return Answer;   
}

void SetScreenColor(bool CheakColorFromAnswer)
{// لو الاجابه الصح يبقي لون خضر لو غلط احمر مع جرس
    if(CheakColorFromAnswer == true)//اولويه :]   // 
    {
    system("color 2F");
    }
    else 
    {
        system("color 4F");
        cout << "\a";
    }
}

void CorrectTheQuestionAnswer(stQuizz& Quizz , short QuestionNumber)
{
    if(Quizz.QuestionList[QuestionNumber].PlayerAnswer != Quizz.QuestionList[QuestionNumber].CorrectAnswer)
    {
        Quizz.QuestionList[QuestionNumber].AnswerResult = false;
        Quizz.NumberOfWrongAnswers++;
        cout << "Wrong Answer :-( \n";
        cout << "The Right Answer is: ";
        cout << Quizz.QuestionList[QuestionNumber].CorrectAnswer;
        cout << "\n";
    }
    else 
    {
        Quizz.QuestionList[QuestionNumber].AnswerResult = true;
        Quizz.NumberOfRightAnswers++;
        cout << "Right Answer :-) \n";

    }
    cout << endl;
    SetScreenColor(Quizz.QuestionList[QuestionNumber].AnswerResult);
}

void AskAndCorrectQuestionListAnswer(stQuizz& Quizz)
{
    for(short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestions; QuestionNumber++)
    {
        PrintTheQuestion(Quizz , QuestionNumber);
        Quizz.QuestionList[QuestionNumber].PlayerAnswer = ReadQuestionAnswer();
        CorrectTheQuestionAnswer(Quizz , QuestionNumber);

    }
    Quizz.isPass = (Quizz.NumberOfRightAnswers >= Quizz.NumberOfWrongAnswers);
}

string GetFinalResultsText(bool Pass)
{
if(Pass)
    return "PASS :-)";
else 
    return "Fail :-(";
}

string GetQuestionLevelText(enQuestionsLevel LevelEnum)
{
    string arrLevels[4] = { "Easy" , "Med" , "Hard" , "Mix"};
    return arrLevels[LevelEnum - 1];
}


void PrintQuizzResults(stQuizz Quizz)
{
    cout << "\n";
    cout << "_______________________________________\n\n";
    cout << "Final Results is " << GetFinalResultsText(Quizz.isPass);
    cout << "\n_______________________________________\n\n";

    cout << "Number Of Questions: " << Quizz.NumberOfQuestions << endl;
    cout << "Questions Level    : " << GetQuestionLevelText(Quizz.SelectedLevel) << endl;
    cout << "OpType             : " << GetOpTypeSymbol(Quizz.OpType) << endl;
    cout << "Number Of Right Answer: " << Quizz.NumberOfRightAnswers << endl;
    cout << "Number Of Wrong Answer: " << Quizz.NumberOfWrongAnswers << endl;
    cout << "___________________________________________\n";
}

void PlayMathGame()
{
    stQuizz Quizz;
    Quizz.NumberOfQuestions = ReadHowManyQuestions();
    Quizz.SelectedLevel = ReadQuestionLevel();
    Quizz.OpType = ReadOpType();

    GenerateQuizzQuestions(Quizz);

    AskAndCorrectQuestionListAnswer(Quizz);// اسئل وصحح قائمه الاسئله والاجابه

    PrintQuizzResults(Quizz);

}

void ResetScreen()
{
    system("cls");
    system("color 0F");
}

void StartGame()
{
    char PlayAgain = 'Y';
    do 
    {
        ResetScreen();
        PlayMathGame();
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
