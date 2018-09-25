/*
  Jonathan Ayala
  Lab 1
  CpSc 2120-01
  9-4-18
*/
#include <iostream>
#include <assert.h>
#include "intset.h"

using namespace std;

Intset::Intset()
{
  head = NULL;
}


/* Return true if key is in the set */
bool Intset::find(int key)
{
  if (head == NULL)
  {
    return false;
  }

  Node *countNode = head;
  while (countNode != NULL)
  {
    if (countNode->number == key)
    {
      return true;
    }
    countNode = countNode->next;
  }

  return false;

}

/* Inserts a new key.  It is an error if key is already in the set. */
void Intset::insert(int key)
{

  assert (!find(key));

  if (head == NULL)
  {
    Node *temp = new Node;
    temp->number = key;
    temp->next = NULL;
    head = temp;
  }
  if (head != NULL)
  {
    Node *frontNode = head;
    Node *backNode = head->next;
    if (key < head->number)
    {
      Node *newN = new Node;
      newN->number = key;
      newN->next = frontNode;
      head = newN;
    }
    if (key > frontNode->number)
    {
      while (backNode != NULL && key > backNode->number)
      {
        frontNode = frontNode->next;
        backNode = backNode->next;
      }

      Node *newNode = new Node;
      newNode->number = key;
      newNode->next = backNode;
      frontNode->next = newNode;
    }
  }
}
/* Removes a key.  It is an error if key isn't in the set */
void Intset::remove(int key)
{

  assert (find(key));

  Node *countNode = head;
  Node *nextCount = head;

  nextCount = nextCount->next;
  if (countNode->number == key)
  {
    delete countNode;
    head = nextCount;
  }
  else
  {
    while (nextCount->number != key)
    {
      countNode = countNode->next;
      nextCount = nextCount->next;
    }
      nextCount = nextCount->next;
      Node *newN = countNode->next;
      countNode->next = nextCount;
      delete newN;
  }
}

void Intset::print(void)
{
  Node *countNode = head;
  while (countNode != NULL)
  {
    cout << countNode->number << endl;
    countNode = countNode->next;
  }
}
