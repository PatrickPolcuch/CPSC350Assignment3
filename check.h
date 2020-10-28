//check.h
#include "GenStack.h"
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
