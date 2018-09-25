/*
  Jonathan Ayala
  Lab 1
  CpSc 2120-01
  9-4-18
*/
#ifndef INTSET_H /* Prevent multiple inclusion... */
#define INTSET_H

struct Node
{
  int number;
  Node *next;
};

class Intset {

 private:

  Node *head = new Node;

 public:
  Intset();
  ~Intset();
  bool find(int key);
  void insert(int key);
  void remove(int key);
  void print(void);
};

#endif
