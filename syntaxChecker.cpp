//syntaxChecker.cpp
#include "check.h"

syntaxChecker::syntaxChecker(){//no constructor needed

}

syntaxChecker::~syntaxChecker(){

}

bool syntaxChecker::checkSyntax(string fileName){//checks the delimiter syntax and returns false if it runs into a delimiter error
  ifstream myFile;
  myFile.open(fileName);

  GenStack <char>*openDelim = new GenStack<char>();//creates stack to store open delimiters

  char c;//current character in fileName
  int Line = 1;//counts the lines
  while(myFile.get(c)){//itterates over every character in fileName
    if(isOpenDelim(c)){//puts open delimiters on the Stack
      openDelim->push(c);
    }
    else if(isCloseDelim(c)){//checks if close delimiters match syntax
      if(openDelim->isEmpty()){
        cout<<"Line "<<Line<<": Found "<<c<<" with no matching previous "<<delimPair(c)<<endl;
        return false;
      }
      char o = openDelim->pop();
      if(!arePair(o,c)){
        cout<<"Line "<<Line<<": Expected "<<delimPair(o)<<" , found "<<c<<endl;
        return false;
      }
    }
    else if(c=='\n'){//counts lines
      Line++;
    }
  }

  if(!openDelim->isEmpty()){//checks to makesure there are no missing delimiters when the file ends
    cout<<"Reached end of file: missing "<<delimPair(openDelim->pop())<<endl;
    return false;
  }

  myFile.close();
  return true;
}

bool syntaxChecker::isOpenDelim(char c){//checks if a character is an open delimiter
  if(c=='('){
    return true;
  }
  if(c=='{'){
    return true;
  }
  if(c=='['){
    return true;
  }
  return false;
}

bool syntaxChecker::isCloseDelim(char c){//checks if a character is an close delimiter
  if(c==')'){
    return true;
  }
  if(c=='}'){
    return true;
  }
  if(c==']'){
    return true;
  }
  return false;
}

bool syntaxChecker::arePair(char o,char c){//checks if the delimiters match
  if(c == delimPair(o)){
    return true;
  }
  return false;
}

char syntaxChecker::delimPair(char d){//gives the match for the given delimiter
  if(d=='('){
    return ')';
  }
  if(d=='{'){
    return '}';
  }
  if(d=='['){
    return ']';
  }
  if(d==')'){
    return '(';
  }
  if(d=='}'){
    return '{';
  }
  if(d==']'){
    return '[';
  }
  cout<<"Something went wrong (syntaxChecker::delimPair(char d))"<<endl;
  return '\0';
}
