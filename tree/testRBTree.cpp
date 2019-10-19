#include <string>
#include <iostream>
#include "rbtree.h"

using namespace std;

template<typename KEY, typename VAL>
void testRBNode(){
    RBNode<KEY,VAL> tmp_node = RBNode<string, int>(red,"hello",4);
    cout<<tmp_node.key;
    cout<<tmp_node.left_child;
    return;
}
int main(){
    testRBNode<string,int>();
    return 0;
}