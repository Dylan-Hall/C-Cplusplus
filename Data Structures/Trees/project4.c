/*
Dylan Hall
Project 4
11/23/16

Quick Notes:

Depth: Check
Dup: Check
Parent: Check
    
*/

#include<stdlib.h>
#include<stdio.h>

//BST Structure
typedef struct tree{
   int data, depth, duplicate;
   struct tree *right, *left, *parent;
}Node;

/* Aliases
 * @TreePtr is a pointer to the tree itself, the entire structure
 * @NodePtr is a pointer for specific elements
 * @basic constructors, root for the first node to retain tree identity, and temp to be used throughout the code when searching, swapping or removing.
 */
typedef Node **TreePtr;
typedef Node *NodePtr;
NodePtr root = NULL, temp = NULL;

/* Prototypes
 * @insert function, i.e. inserts data into the tree, double pointer needed to help hold integrity of the tree whilst placing data into correct spots.
 * @search function, i.e. searches for a specific node
 * @destroy function, simply frees the nodes from the tree
 * @print functions; print_inorder/print_levelorder/print_postorder
 * @level function, just determines the level a specific node is on
 * @setDepth function, sets the depth of each node
 * @height function, determines the location in the tree of each node for levelorder printing
 */
void insert(TreePtr tree, int val); 
NodePtr search(NodePtr tree, int val);
void destroy(NodePtr root);
void print_inorder(NodePtr tree);
void print_postorder(NodePtr tree);
void print_levelorder(NodePtr root);
void level(NodePtr root, int num);
void setDepth(NodePtr root, int depth);
int height(NodePtr root);

//Main Function
void main(void)
{
   int ch, data, key, num, i = 0;
   
   printf("Enter number of required entries: ");
   scanf("%d", &ch);
     
   //just a loop for each entry the user requests
   while(i != ch){
      printf("Enter value for node %d: ", i);
      scanf("%d", &data);
      insert(&root, data);
      i++;
   }
   setDepth(root, 0);
   num = height(root);

   //Search for node
   printf("Enter the value to find: ");
   scanf("%d", &key);
  
   temp = search(root, key);
   
   if(root){   
      printf("Inorder display: ");
      print_inorder(root);
      printf("\nPostorder display: ");
      print_postorder(root);
      printf("\nLevel order display: ");
      print_levelorder(root);
   }
   printf("Root parent: %d         root-left parent: %d            root-right parent: %d",root->parent->data, root->left->parent->data, root->right->parent->data);
   destroy(root);
   
}

/* Insert Data Function
 * Inserts data into nodes in the correct location in the tree
 * @Finally will set and retain number of duplicates
 * @also, will determine and retain the parent id of each child node
 */
void insert(TreePtr tree, int val){
   if(!(*tree)){
      printf("\n\nHere\n");
      temp = (NodePtr)malloc(sizeof(Node));
      temp->left = temp->right = NULL;
      temp->data = val;
      temp->duplicate = 0;
      temp->parent = temp;
      *tree = temp;
      return;
   }

   /*It allows the user to somewhat visualize the structure of the tree as the tree is created.
    *Just quick comparisons and displays them
    */
   if(val == (*tree)->data){ //If input == current node, register as duplicate.
      printf("Duplicate node. Duplicate node not added to tree.\n");
      (*tree)->duplicate++;
   }
   
   else if(val < (*tree)->data){ //If input < current node, insert to the left of node
      printf("%d < %d. Inserting to left of parent.\n", val, (*tree)->data);
      insert(&(*tree)->left, val);
      (*tree)->left->parent = *tree;
   }
   
   else if(val > (*tree)->data){ //If input > current node, insert to the right of node
      printf("%d > %d. Inserting to right of parent.\n", val, (*tree)->data);
      insert(&(*tree)->right, val);
      (*tree)->right->parent = *tree;
   }
}

//Search Function
NodePtr search(NodePtr root, int val){
   if(root){
      if(val < root->data)
         search(root->left, val);
      
      else if(val > root->data)
         search(root->right, val);
      
      else if(val == root->data){
         printf("Searched node: %d, was found at address: 0x%x\n", root->data, &root->data);
         return root;
      }
      else{
         printf("Data not found in tree.\n");
         return 0;
      }
   }
   else{
      printf("Tree is empty.\n");
      return 0;
   }
}

/* Find Height Function
 * Traverse each side of the tree, see below :(left and right variables):
 * if left > right, thats the total height of the tree, vice versa for the right side
 */
int height(NodePtr root) {
   if (!root) 
      return 0;
   else{
      //Traverse left and right sub-trees and return the greatest height. 
      int left = height(root->left),
          right = height(root->right);
        
      if (left > right) 
         return(left + 1);
      else 
         return(right + 1);
   }
}

//Destroy Tree Function, will free the nodes from the tree
void destroy(NodePtr root){
   if(root){
      destroy(root->left);
      destroy(root->right);
      free(root);
   }
}

//Inorder Display Function
void print_inorder(NodePtr root){
   if(root){
      print_inorder(root->left);
      printf("%d ",root->data);
      print_inorder(root->right);
   }
}

//Postorder Display Function
void print_postorder(NodePtr root){
   if(root){
      print_postorder(root->left);
      print_postorder(root->right);
      printf("%d ",root->data);
   }
}

/* Theses two functions get a little tricky */

//Level Order Display Function 
void print_levelorder(NodePtr root){
   int i, num = height(root);
   for(i = 1; i <= num; i++)
      level(root, i);
}    

//Level Traversal Function  
void level(NodePtr root, int num){
   if(!root)
      return;
   //if height is 1, just return root
   if(num == 1)
      printf("%d ", root->data);
   
   else{
      level(root->left, num - 1);
      level(root->right, num - 1);
   }
}

//setDepth Function
void setDepth(NodePtr root, int depth){
   if(root)
   {
      setDepth(root->left, depth++);
      root->depth = depth;
      setDepth(root->right, depth++);
   }
}
