//check.h
//Patrick Polcuch
//2348668
//CPSC350Assignment3

#include "GenStack.h"//so I can use my Stack
#include <fstream>

using namespace std;

class syntaxChecker{
public:

  syntaxChecker();
  ~syntaxChecker();
  static bool checkSyntax(string fileName);
  static bool isOpenDelim(char c);
  static bool isCloseDelim(char c);
  static bool arePair(char o,char c);
  static char delimPair(char d);

};
