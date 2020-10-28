//syntaxChecker.cpp
#include "check.h"

syntaxChecker::syntaxChecker(){//no constructor needed

}

syntaxChecker::~syntaxChecker(){

}

bool syntaxChecker::checkSyntax(string fileName){
  ifstream myFile;
  myFile.open(fileName);

  GenStack <char>*openDelim = new GenStack<char>();

  char c;
  int Line = 1;
  while(myFile.get(c)){
    if(isOpenDelim(c)){
      openDelim->push(c);
    }
    else if(isCloseDelim(c)){
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
    else if(c=='\n'){
      Line++;
    }
  }

  if(!openDelim->isEmpty()){
    cout<<"Reached end of file: missing "<<delimPair(openDelim->pop())<<endl;
    return false;
  }


  myFile.close();
  return true;
}

bool syntaxChecker::isOpenDelim(char c){
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

bool syntaxChecker::isCloseDelim(char c){
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

bool syntaxChecker::arePair(char o,char c){//checks if the delimiters match and gives user appropriate responce
  if(c == delimPair(o)){
    return true;
  }
  return false;
}

char syntaxChecker::delimPair(char d){
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
