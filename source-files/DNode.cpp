#include "DNode.hpp"
#include "DLL.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

DNode::DNode() {
    //Default constructor definition
    song = new Song();
    prev = NULL; //null pointer
    next = NULL; //null pointer
}

DNode::DNode(string s, string a, int lenmin, int lensec) {
    song = new Song(s, a, lenmin, lensec);  // new song with inputs
    prev = NULL; //null pointer
    next = NULL; //null pointer
}

