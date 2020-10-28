//header file GenStack.h
#include <iostream>
using namespace std;

template <class type>
class GenStack{
public:
  GenStack(){
    myArray = new type[128];
    mSize=128;
    top= -1;
  }

  GenStack(int maxSize){
    myArray = new type[maxSize];
    mSize = maxSize;
    top = -1;
  }

  ~GenStack(){
    delete myArray;
  }

  void push(type data){
    //check if full before procceding
    if(isFull()){
      resize();
    }
    myArray[++top] = data;
  }

  type pop(){
    //check if empty before proceeding
    if(isEmpty()){
      cout<<"Error: Can't pop from empty Stack"<<endl;
      return '\0';
    }
    return myArray[top--];
  }

  type peek(){
    if(isEmpty()){
      return '\0';
    }//check if empty first return'\0'
    return myArray[top];
  }

  bool isFull(){
    return(top==mSize-1);
  }

  bool isEmpty(){
    return (top==-1);
  }

  int getSize(){
    return top+1;
  }

  void resize(){
    mSize = mSize*2;
    type *newArray = new type[mSize];

    for(int i = 0; i<sizeof(myArray);i++){
      newArray[i] = myArray[i];
    }
    delete myArray;
    myArray = newArray;

  }


  int top;
  int mSize;

  type *myArray;
};
