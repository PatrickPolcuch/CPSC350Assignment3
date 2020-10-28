//main.cpp
//Patrick Polcuch
//2348668
//CPSC350Assignment3

#include "check.h"

int main(int argc,char** argv){
  bool good = syntaxChecker::checkSyntax(argv[1]);
  if(!good){
    return 1;
  }
  cout<<"Delimiters match"<<endl;

  while(true){//checks if the user wants to check another file
    cout<<"Would you like to check another file?(yes/no)"<<endl;
    string userIn = "";
    cin>>userIn;

    if(userIn.compare("no")==0||userIn.compare("No")==0||userIn.compare("n")==0||userIn.compare("N")==0){//covering all my bases
      return 1;
    }

    if(userIn.compare("yes")==0||userIn.compare("Yes")==0||userIn.compare("y")==0||userIn.compare("Y")==0){
      cout<<"What is the name of the file you would like to check?"<<endl;
      cin>>userIn;
      good = syntaxChecker::checkSyntax(userIn);
      if(!good){
        return 1;
      }
      cout<<"Delimiters match"<<endl;
      continue;
    }

    cout<<"Responce not recognized, goodbye"
    break;
  }

  return 1;
}
