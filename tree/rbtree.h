#ifndef RBTREE_H
#define RBTREE_H

typedef enum Color {red,black} color;
template <typename KEY, typename VAL>
class RBNode{
public:
   RBNode(enum Color col,KEY k,VAL v):color(col),key(k),val(v){
      left_child=right_child=parent=nullptr;
      is_leaf=false;
   };
   RBNode * left_child, *right_child, *parent;
   //RBNode * parent;
   KEY key;
   VAL val;
   Color color;
   //bool is_leaf;
};

template <typename KEY, typename VAL>
class RBTree{
public:
   RBNode<KEY,VAL>* root;
   VAL search(KEY key);
   bool insert(KEY key, VAL val);
   bool del(KEY)
private:
   void leftRotate();
   void rightRotate();
};


template <typename KEY, typename VAL>
bool insert(RBNode<KEY,VAL>* rb_node){//need to consider the impact from red and black color.
   RBNode<KEY,VAL>* cur_node;
   cur_node = root;
   if(!cur_node) {
      root=rb_node;return true;
   }
   while(cur_node){
      if( rb_node->key < cur_node->key){
         if(cur_node->left_child)            cur_node=cur_node->left_child;
         else {
            cur_node->left_child=rb_node;
            rb_node->parent=cur_node;
            return true;
         }
      }
      else{
         if( rb_node->key > cur_node->key){
         if(cur_node->right_child)            cur_node=cur_node->right_child;
         else {
            cur_node->right_child=rb_node;
            rb_node->parent=cur_node;
            return true;
         }
      }

   }
      
}
template <typename KEY, typename VAL>
void leftRotate(RBNode<KEY,VAL>* rb_node){
   RBNode<KEY,VAL>* pa,*right;
   //check the right child of rb_node(which is the node to be rotated ), maybe should be done out of this function, but I think a better place is here.
   pa=rb_node->parent;
   right=rb_node->right_child;
   right->parent=pa;
   rb_node->right_child = right->left_child;
   if(right->left_child)
      right->left_child->parent=rb_node;
   rb_node->parent=right;
   right->left_child=rb_node;
   if(pa==nullptr) 
      root=right;   
   else{
      if(rb_node->key == pa->left_child->key){
         pa->left_child=right;
      }
      else{
         pa->right_child = right;
      }
   }
   return ;
}

template <typename KEY, typename VAL>
void rightRotate(RBNode<KEY,VAL>* rb_node){
   RBNode<KEY,VAL>* pa,*left;
   //check the right child of rb_node(which is the node to be rotated ), maybe should be done out of this function, but I think a better place is here.
   pa=rb_node->parent;
   left=rb_node->left_child;
   left->parent=pa;
   rb_node->left_child = left->right_child;
   if(left->right_child)
      left->right_child->parent=rb_node;
   rb_node->parent=left;
   left->right_child=rb_node;
   if(pa==nullptr) 
      root=left;   
   else{
      if(rb_node->key == pa->left_child->key){
         pa->left_child=left;
      }
      else{
         pa->right_child = left;
      }
   }
   return ;
}

#endif
