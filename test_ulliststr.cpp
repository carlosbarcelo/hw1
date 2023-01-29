#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite
using namespace std;

int main(int argc, char* argv[])
{
  ULListStr list;
  list.push_back("one");
  list.push_back("two");
  list.push_back("three");
  list.push_front("zero");
  list.push_back("four");
  list.pop_back();
  list.pop_front();

  
  for(size_t i = 0; i < list.size(); i++){
    cout << list.get(i) << endl;
  }
}
