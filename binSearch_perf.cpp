
#include <iostream>
#include "binsearch_collection.h"
#include "test_driver.h"

using namespace std;

int main(int argc, char** argv)
{
  if (argc != 2) {
    cout << "usage: " << argv[0] << " filename" << endl;
    return 1;
  }
  
  // run basic performance test 
  BinSearchCollection<string,double> test_collection;
  TestDriver<string,double> driver(argv[1], &test_collection);
  driver.run_tests();
  driver.print_results();
}
