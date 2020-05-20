# Binary Seach


## Class Setup
```
cmake CMakeLists.txt
make
```
To use the test file:
```
./binTest
```

To use the performance test:
```
./binperf rand-10k.txt
```

## About this project
Binary Search using a vector collection holding key-value pairs.  The project implements these functions to the list:
- add
- remove
- find
- range find
- keys (returns all keys by reference)
- sort (ascending order)
- size


The test file is used as a way to ensure that each function works with different test cases.  The performance file is used to find the speed and number of calls for each function. This can be used with a randomly generated key-value pairs that ranges from 10k pairs to 50k pairs.

Note: Need to have Cmake installed

# 10k items Performance
 
Test Results
=============

  Add Calls...: 10000
  
  Add Time....: 414253 microseconds
  
  Add Average.: 41.4253 microseconds


  Remove Calls...: 2000
  
  Remove Time....: 35951 microseconds
  
  Remove Average.: 17.9755 microseconds


  Find Calls...: 2000
  
  Find Time....: 0 microseconds
  
  Find Average.: 0 microseconds


  Range Calls...: 1
  
  Range Time....: 10 microseconds
  
  Range Average.: 10 microseconds

  Sort Calls...: 1
  
  Sort Time....: 953 microseconds
  
  Sort Average.: 953 microseconds
