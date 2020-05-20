//----------------------------------------------------------------------
// Author: Michael Calmette
// File:   binSearch_test.cpp
//
// TODO: Vector based collection: Uses Binary Search program which utilizes 
// binary search with an add, remove, find and sort functions.
// File has 6 test cases for functions
//----------------------------------------------------------------------


#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include "binsearch_collection.h"

using namespace std;

// Test 1
TEST(BasicListTest, CorrectSize) {
  BinSearchCollection<string,double> c;
  ASSERT_EQ(0, c.size());
  c.add("b", 10.0);
  ASSERT_EQ(1, c.size());
  c.add("a", 20.0);
  ASSERT_EQ(2, c.size());
  c.add("c", 20.0);
  ASSERT_EQ(3, c.size());
}
  
// Test 2
TEST(BasicListTest, SimpleFind) {
  BinSearchCollection<string,double> c;
  double v;
  ASSERT_EQ(false, c.find("b", v));
  c.add("b", 10.0);
  ASSERT_EQ(true, c.find("b", v));
  ASSERT_EQ(10.0, v);
  ASSERT_EQ(false, c.find("a", v));
  c.add("a", 20.0);
  ASSERT_EQ(true, c.find("a", v));
  ASSERT_EQ(20.0, v);
}

// Test 3
TEST(BasicListTest, SimpleRemoveElems) {
  BinSearchCollection<string,int> c;
  c.add("b", 10);
  c.add("a", 20);
  c.add("d", 30);
  c.add("c", 30);
  ASSERT_EQ(4, c.size());
  int v;
  c.remove("a");
  ASSERT_EQ(3, c.size());
  ASSERT_EQ(false, c.find("a", v));
  c.remove("b");
  ASSERT_EQ(2, c.size());
  ASSERT_EQ(false, c.find("b", v));  
  c.remove("c");
  ASSERT_EQ(1, c.size());
  ASSERT_EQ(false, c.find("c", v));  
  c.remove("d");
  ASSERT_EQ(0, c.size());
  ASSERT_EQ(false, c.find("c", v));  
}

// Test 4
TEST(BasicListTest, SimpleRange) {
  BinSearchCollection<int,string> c;
  c.add(50, "e");
  c.add(10, "a");
  c.add(30, "c");
  c.add(40, "d");
  c.add(60, "f");
  c.add(20, "b");
  vector<string> vs;
  c.find(20, 40, vs);
  ASSERT_EQ(3, vs.size());
  // note that the following "find" is a C++ built-in function
  ASSERT_EQ(vs.end(), find(vs.begin(), vs.end(), "a"));
  ASSERT_NE(vs.end(), find(vs.begin(), vs.end(), "b"));
  ASSERT_NE(vs.end(), find(vs.begin(), vs.end(), "c"));
  ASSERT_NE(vs.end(), find(vs.begin(), vs.end(), "d"));
  ASSERT_EQ(vs.end(), find(vs.begin(), vs.end(), "e"));  
  ASSERT_EQ(vs.end(), find(vs.begin(), vs.end(), "f"));  
}
 
// Test 5
TEST(BasicListTest, SimpleSort) {
  BinSearchCollection<string,int> c;
  c.add("a", 10);
  c.add("e", 50);
  c.add("c", 30);
  c.add("b", 20);
  c.add("d", 40);
  vector<string> sorted_ks;
  c.sort(sorted_ks);
  ASSERT_EQ(5, sorted_ks.size());
  // check if in sorted order
  for (int i = 0; i < int(sorted_ks.size()) -1; ++i)
    ASSERT_LE(sorted_ks[i], sorted_ks[i+1]);
}


// TODO: ... additional tests ...
TEST(BasicListTest, AdditionalTest) {
  BinSearchCollection<string,double> c;
  c.add("AMZN",1700.50);
  c.add("APPL",290);
  c.add("MSFT",170);
  c.add("TSLA",780);
  c.add("C", 75.32);
  c.add("APPL",300); //try add same key
  ASSERT_EQ(6,c.size());
  c.remove("APPL"); //remove same key
  ASSERT_EQ(5,c.size());
  double y = 1700.50;
  ASSERT_EQ(true, c.find("AMZN", y)); 
  c.remove("AMZN");
  vector<string> sort;
  c.sort(sort);
  ASSERT_EQ(false, c.find("AMZN", y));
  for (int i = 0; i < int(sort.size()) -1; ++i)
    ASSERT_LE(sort[i], sort[i+1]);

  ASSERT_EQ(4,sort.size());
  ASSERT_EQ(true, sort.at(0) == "APPL");
  ASSERT_EQ(true, sort.at(1) == "C");
  ASSERT_EQ(true, sort.at(2) == "MSFT");
  ASSERT_EQ(true, sort.at(3) == "TSLA");
}



int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

