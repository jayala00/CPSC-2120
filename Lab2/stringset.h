#ifndef STRINGSET_H /* Prevent multiple inclusion... */
#define STRINGSET_H

#include <string>
using namespace std;

struct Node {
  string key;
  Node *next;
  // int val
  Node(string k, Node *n) { key = k; next = n; }
  Node() { key = ""; next = NULL; }
  //Node(string k, Node *n, int v) { key = k; next = n; val = v; }
  //Node() { key = ""; next = NULL; val = 0;}
};

class Stringset {

 private:
  Node **table;  // array of pointers to linked lists
  int size;      // size of table, as currently allocated
  int num_elems; // number of elements stored in the table

 public:
  Stringset();
  ~Stringset();
  bool find(string key);
  // int &operator[](string key);
  void insert(string key);
  // void insert(string key, int val);
  void remove(string key);
  void print(void);
};

#endif
