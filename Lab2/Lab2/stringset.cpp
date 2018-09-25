/*
  Jonathan Ayala
  Lab 2
  CpSc 2120-01
  9-8-18
*/

#include <iostream>
#include <string.h>
#include <assert.h>
#include "stringset.h"

using namespace std;

/* Return a hash for the string s in the range 0..table_size-1 */
int hashT(string s, int table_size)
{
  unsigned int i, h = 0;
  for (i=0; i<s.length(); i++)
    h = (h * 2917 + (unsigned int)s[i]) % table_size;
  return h;
}

/* Allocate a table of pointers to nodes, all initialized to NULL */
Node **allocate_table(int size)
{
  Node **table = new Node *[size];
  for (int i=0; i<size; i++)
    table[i] = NULL;
  return table;
}

Stringset::Stringset()
{
  size = 4; // initial size of table
  table = allocate_table(size);
  num_elems = 0;
}

Stringset::~Stringset()
{
  for (int i=0; i<size; i++) {
    while (table[i] != NULL) {
      Node *temp = table[i];
      table[i] = table[i]->next;
      delete temp;
    }
  }
  delete[] table;
}

/* Return true if key is in the set */
bool Stringset::find(string key)
{
  int h = hashT(key, size);
  Node *n = table[h];
  while (n != NULL)
  {
    if (n->key == key) return true;
    n = n->next;
  }
  return false;
}

/* Inserts a new key.  It is an error if key is already in the set. */
void Stringset::insert(string key)
{
  assert (!find(key));
  num_elems++;

  //resize the table
  if (num_elems == size)
  {

    int h;
    int count;
    int newsize = 2 * size;
    Node **temptable = allocate_table(newsize);

    for (count = 0; count < size; count++)
    {
	//check if the head is null
	if (table[count] != NULL)
	{
	  Node *pointer = table[count];
	  //while head isnt null re-hash old table values in the new temptable
          while ( pointer != NULL )
          {
            h = hashT(pointer->key, newsize);

            temptable[h] = pointer;

            pointer = pointer->next;
          }
	  table[count] = NULL;
	}
    }

    // delete the old table and set table equal to new table
    delete[] table;
    table = temptable;
    size = newsize;

  }

  //inserting a new key at the beginning of the hash table
  int h = hashT(key, size);
  table[h] = new Node(key, table[h]);


}

/* Removes a key.  It is an error if key isn't in the set */
void Stringset::remove(string key)
{
  assert (find(key));
  num_elems--;

  int h = hashT(key,size);
  //make a two pointers so that one can be deleted
  Node *counter = table[h];
  Node *nextC = table[h];

  nextC = nextC->next;

  //check to see if the first index is the key to be deleted
  if (counter->key == key)
  {
    delete counter;
    table[h] = nextC;
  }
  else
  {
    // iterate through the list until you reach to the node that equals the key
    while (nextC->key != key)
    {
      counter = counter->next;
      nextC = nextC->next;
    }
    nextC = nextC->next;
    Node *newN = counter->next;
    counter->next = nextC;
    delete newN;
  }

}

void Stringset::print(void)
{

  for (int i = 0; i < size; i++)
  {
    Node *count = table[i];
    while (count != NULL)
    {
      cout << count->key << endl;
      count = count->next;
    }
  }
}
