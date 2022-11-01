#include<iostream>
#include<string>
#include<fstream>

using namespace std;

struct Question {
    string question;
    string a;
    string b;
    string c;
    char correctAnswer;
};

struct Questionnaire {
    Question* questions = new Question;
};

void displayQuestion(Questionnaire q){
    cout<<q.questions->question<<endl;
    cout<<q.questions->a<<endl;
    cout<<q.questions->b<<endl;
    cout<<q.questions->c<<endl;
}

Questionnaire buildQuestionnaire(string path)
{
    Questionnaire q;
    ifstream fs;
    char answer;
    string pom;
    int line = 0;
    int count = 0;

    fs.open(path);
    if(fs){
        
        /*Finding the number of questions in the file*/
        while(!fs.eof()){
        getline(fs, pom);
        line++;
        }

        fs.close();

        /*Display the questions and let user choose answer*/
        fs.open(path);
        for(int i = 0; i < line-1; i++){
        getline(fs, q.questions->question, ';');
        getline(fs, q.questions->a, ';');
        getline(fs, q.questions->b, ';');
        getline(fs, q.questions->c, ';');
        fs>>q.questions->correctAnswer;

        displayQuestion(q);

        cout<<"Choose the correct answer: ";
        cin>>answer;

        /*Check if the answer is correct*/
        if (answer==q.questions->correctAnswer || answer==char(int(q.questions->correctAnswer)+32))
            count++;

        cout<<endl;
        }
        
        cout<<"\nYour point: "<<count;
    }
    else
        cout<<"\nFail to open file!";
        
    fs.close();
    return q;
}

int main(){
    string path;
    cout<<"Questions file path: ";
    cin>>path;
    buildQuestionnaire(path);
}