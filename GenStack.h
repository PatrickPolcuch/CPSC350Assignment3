//header file GenStack.h
//Patrick Polcuch
//2348668
//CPSC350Assignment3

//This file contains my Stack

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

  void push(type data){//places 'data' on the top of the stack
    //check if full before procceding
    if(isFull()){
      resize();
    }
    myArray[++top] = data;
  }

  type pop(){//removes and returns the top item of the stack
    //check if empty before proceeding
    if(isEmpty()){
      cout<<"Error: Can't pop from empty Stack"<<endl;
      return '\0';
    }
    return myArray[top--];
  }

  type peek(){//return the top item in the stack
    if(isEmpty()){
      return '\0';
    }//check if empty first return'\0'
    return myArray[top];
  }

  bool isFull(){//checks to see if the stack is full
    return(top==mSize-1);
  }

  bool isEmpty(){//checks to see if the stack is empty
    return (top==-1);
  }

  int getSize(){//returns the number f items in the stack
    return top+1;
  }

  void resize(){//doubles the array's size 
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
