
//----------------------------------------------------------------------
// File:   collection.h
//
// Assumptions:
//
//   1. Collections consist of a set of unique keys, where each key
//      has an associated value. A key together with its value is
//      called a "key-value pair".
//
//   2. Because a collection stores a particular key only once, if a
//      key can be associated with multiple underlying values, then
//      the key must be associated with a list containing the
//      underlying values. Thus, the collection would consist of
//      key-value pairs such that the key values are lists.
// 
//   3. A key should only be added into a collection if the key isn't
//      already in the collection. If a key is added more than once,
//      then the behavior of the collection becomes undefined (in
//      terms of finding and removing keys).
//----------------------------------------------------------------------

 
#ifndef COLLECTION_H
#define COLLECTION_H

#include <vector>

template<typename K, typename V>
class Collection
{
public:

  // add a new key-value pair into the collection 
  virtual void add(const K& a_key, const V& a_val) = 0;

  // remove a key-value pair from the collectiona
  virtual void remove(const K& a_key) = 0;

  // find and return the value associated with the key
  virtual bool find(const K& search_key, V& the_val) const = 0;

  // find and return the values with keys >= to k1 and <= to k2 
  virtual void find(const K& k1, const K& k2, std::vector<V>& vals) const = 0;
  
  // return all of the keys in the collection 
  virtual void keys(std::vector<K>& all_keys) const = 0;

  // return all of the keys in ascending (sorted) order
  virtual void sort(std::vector<K>& all_keys_sorted) const = 0;

  // return the number of key-value pairs in the collection
  virtual int size() const = 0;

};


#endif
