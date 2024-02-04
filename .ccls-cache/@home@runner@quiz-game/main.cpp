#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
  cout << "Quiz Game!\n";
  fstream file("questions.txt");
  string line;
  vector<string> questions,answers;
  int score=0;
  //reading in file
  while(!file.eof()){
    getline(file,line);
    questions.push_back(line.substr(2));
    getline(file,line);                                
    answers.push_back(line.substr(2));
  }
  //shuffle questions/answers
  cout<<time(NULL)<<endl;
  srand(time(NULL));
  int num,sz=questions.size();
  int *picked = new int[sz];
  for(int i=0;i<sz;i++){
    while(true){
      num=rand()%sz;
      if(!picked[num]){
        picked[num]=1;
        break;
      }
    }
    questions.push_back(questions[num]);
    answers.push_back(answers[num]);
  }
  questions.erase(questions.begin(),questions.begin()+sz);
  answers.erase(answers.begin(),answers.begin()+sz);
  delete[] picked;
  //asking questions
  for(int i=0;i<sz;i++){
    cout << "Question " << i+1 << ": " << questions[i] << endl;
    getline(cin,line);
    //checking user input
    for(int j=0;j<line.size();j++){
      if(isupper(line[j])){
        line[j]=tolower(line[j]);
      }else if(isspace(line[j])/*&&(j==0||j==line.size()-1)*/){
        line.erase(j--,1);
      }
    }
    //checking answer
    for(int j=0;j<answers[i].size();j++){
      if(isupper(answers[i][j])){
        answers[i][j]=tolower(answers[i][j]);
      }else if(isspace(answers[i][j])/*&&(j==0||j==answers[i].size()-1)*/){
        answers[i].erase(j--,1);
      }
    }
    if(line==answers[i]){
      score++;
      cout << "Correct!\n";
    } else {
      cout << "Incorrect!\n";
    }
  }
    cout << "your score is " <<score<< "/"<<sz<<endl;
  float percent=((float)score/sz)*100;
  cout << "your percentage is " <<percent<<"%"<<endl;
//give grade A,B,C,D,or F
if (percent >= 90){
  cout << "yay got an A!!!!!!!!!!!!!!!! \n";
}else if(percent >= 80){
  cout << "Eww, you got a B.\n";
}else if (percent >=70){
  cout << "*throwing up sounds* you got a c\n";
}else if (percent >=60){
cout << "you got a D its fine we will put you in rehab and you to the worlds strictest boarding school for 936 years then we will slap in the face 9,000,000,000,000 and try again \n";
}else cout << "I give up... (you got an F)\n";
}