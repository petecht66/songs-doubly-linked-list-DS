
#include "DNode.hpp"
#include "DLL.hpp"
#include <iostream>
#include <ranges>
#include <stdlib.h>
using namespace std;

//Check Playlist.cpp for instructions of what to write here and how to test it

DLL::DLL(){  // constructor - initializes an empty list
		last = NULL;
		first = NULL;
		numSongs = 0;
}

DLL::DLL(string t, string l, int m, int s){  // constructor, initializes a list with one new node with data x
		DNode *n = new DNode (t,l,m,s);
		first = n;
		last = n;
		numSongs=1;
}

void DLL::push(string n, string a, int m, int s) {  // does what you'd think
		DNode *newNode = new DNode (n,a,m,s);
        if (numSongs == 0){ // Case 1: Empty list
          first = newNode;;
          last = newNode;
        }
        else{ // Case 2: List of 1+
          last->next = newNode;
          newNode->prev = last;
          last = newNode;
          }
    }

Song *DLL::pop(){ //does what you'd think
          if (numSongs == 0){ // Case 1: Empty list
            cout<<"Empty list"<<endl;
            return new Song();
          }
          Song *popped = last->song;
          if (numSongs == 1){ // Case 2: One item
            delete last;
            first = NULL;
            last = NULL;
          }
          else{ // Case 3: Any other size list
          DNode *temp = last;
          last = last->next;
          last->next = NULL;
          delete temp;
          }
          numSongs--; //decrease size by 1
          return popped; //return Song
          }

void DLL::printList() {
          DNode *temp = first;
          if (numSongs == 0){
            cout<<"Empty list"<<endl;
            return;
          }
          while (temp != NULL){
            temp->song->printSong();
            temp=temp->next;
          }
}

void DLL::moveUp(string s) {
          if (numSongs == 0){
            cout<<"Empty list"<<endl;
            return;
          }
          if (numSongs == 1){
            cout << "Only one song" << endl;
            return;
          }
          DNode *temp = first;

          while (temp != NULL){
            if (temp->song->title == s) {
              if (temp == first){
                first = first->next;
                first->prev = NULL;
                last->next = temp;
                temp->prev = last;
                temp->next = NULL;
                last = temp;
              }
              else{
                DNode *prev = temp->prev;
                DNode *next = temp->next;
                prev->next = next;
                if (next != NULL){
                  next->prev = prev;
                }
                else{
                  last = prev;
                }
                temp->prev = prev->prev;
                temp->next = prev;
                if (prev->prev != NULL){
                  prev->prev->next = temp;
                }
                else{
                  first = temp;
                }
                prev->prev = temp;
              }
              return;
            }
            temp=temp->next; // Moving through list
          }
          cout << "Title not found" <<endl;
}

void DLL::listDuration(int *tm, int *ts) {
  *tm = 0; // initializing
  *ts = 0; // initializing
  DNode *temp = first;
  while (temp != NULL) {
    *tm += temp->song->min; // add current node's minutes
    *ts += temp->song->sec; // add current node's seconds
    temp = temp->next; // next node
  }
  if (*ts >= 60) { // correction loop if seconds can be converted to minutes
    *tm += *ts / 60; // converting seconds to minutes
    *ts = *ts % 60; // update seconds
  }
}

void DLL::moveDown(string s) {
  if (numSongs == 0) { // Empty list
    cout<<"Empty list"<<endl;
    return;
  }
  if (numSongs == 1) { // One item
    cout << "Only one song" << endl;
    return;
  }
  DNode *temp = first;
  while (temp != NULL) {
    if (temp->song->title == s) {
      if (temp == last){ // temp is last item
        last = last->prev;
        last->next = NULL;
        temp->prev = NULL;
        temp->next = first;
        first->prev = temp;
        first = temp;
      }
      else {
        DNode *next = temp->next;
        temp->prev->next = next;
        if (next != NULL) {
          next->prev = temp->prev;
        }
        temp->next = next->next;
        temp->prev = next;

        if (next->next != NULL) {
          next->next->prev = temp;
        }
        else { // node is first or in the middle
          last = temp;
        }
        next->next = temp;
      }
      return;
    }
    temp=temp->next; // next node
  }
  cout<<"Title not found"<<endl; // item with this title was not found
}

void DLL::makeRandom() {
    if (numSongs <= 1) { // don't need to randomize
      return;
    }
    srand(time(0)); // random number generator
    DNode *temp = first;
    for (int i = 0; i < numSongs; i++) {
      int randNum = rand() % numSongs;
      DNode *random = first;
      for (int j = 0; j < randNum; j++) {
        random = random->next;
      }
      if (temp != random) {
        DNode *tempPrev = temp->prev;
        DNode *tempNext = temp->next;
        DNode *randomNext = random->next;
        DNode *randomPrev = random->prev;
        if (tempNext == random) {
          if (tempPrev) tempPrev->next = random;
          if (randomNext) randomNext->prev = temp;
          random->prev = tempPrev;
          temp->next = randomNext;
          random->next = temp;
          temp->prev = random;
        }
        else if (randomNext == temp){
          if (randomPrev) randomPrev->next = temp;
          if (tempNext) tempNext->prev = random;
          temp->prev = randomPrev;
          random->next = tempNext;
          temp->next = random;
          random->prev = temp;
        }
        else {
          if (tempPrev) tempPrev->next = random;
          if (tempNext) tempNext->prev = random;
          if (randomPrev) randomPrev->next = temp;
          if (randomNext) randomNext->prev = temp;

          temp->prev = randomPrev;
          temp->next = randomNext;
          random->prev = tempPrev;
          random->next = tempNext;
        }
        if (temp == first) first = random;
        else if (random == first) first = temp;
        if (temp == last) last = random;
        else if (random == last) last = temp;
      }
      temp = temp->next; //move to next node
    }
}


int DLL::remove(string s) {
		if (numSongs == 0){ // Case 1: Empty list
        	cout << "Empty list" << endl;
            return -1;
        }
        DNode *temp = first;
        int foundIndex = 0; // Set index to first element

        while (temp != NULL){
          if (temp->song->title == s) {
            if (temp == first && temp == last){ // Case 1: One node in last
              delete temp;
              first = NULL;
              last = NULL;
            }
            else if (temp == first){ // Case 2: temp is first node, but not only one
              first = first->next;
              first->prev = NULL;
              delete temp;
            }
            else if (temp == last){ // Case 3: temp is last node
              last = last->prev;
              last->next = NULL;
              delete temp;
            }
            else{ // Case 4: temp in middle of list
              temp->prev->next = temp->next;
              temp->next->prev = temp->prev;
              delete temp;
            }
            numSongs--; // decrease size by 1
            return foundIndex;
          }
          temp = temp->next; // Change to next node if not found
          foundIndex++; // Increase index by 1
        }
          return -1; // title not found
}


DLL::~DLL(){ // destructor
  DNode *temp = first;
  while (temp != NULL) {
    DNode *next = temp->next;
    delete temp->song;
    delete temp;
    temp = next;
  }
  first = NULL; // resetting first to NULL
  last = NULL; // resetting last to NULL
  numSongs=0; // number of songs is zero
}
