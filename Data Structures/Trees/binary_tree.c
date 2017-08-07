#include<stdlib.h>
#include<stdio.h>

typedef struct tree{
   int data;
   struct tree *right, *left;
}node;

typedef node **TreePtr;
typedef node *NodePtr;

void insert(TreePtr tree, int val);
void print_preorder(NodePtr tree);
void print_inorder(NodePtr tree);
void print_postorder(NodePtr tree);
void delete_tree(NodePtr tree);
NodePtr search(TreePtr tree, int val);

void main()
{
   int ch, data, key, i = 0;
   NodePtr root;
   NodePtr tmp;
   root = NULL;
   
   printf("Enter number of required entries: ");
   scanf("%d", &ch); 
   while(i != ch){
      if(i == 0){
         printf("Enter value for the root of tree (node %d): ", i);
         scanf("%d", &data);
         insert(&root,data);
         i++;
      }
      else{
         printf("Enter value for node %d: ", i);
         scanf("%d", &data);
         insert(&root, data);
         i++;
      }
   }
   
   //Search for node
   printf("Enter the value to find: ");
   scanf("%d", &key);  
   tmp = search(&root, key);
   if (tmp)
      printf("Searched node: %d\n", tmp->data);
   else
      printf("Data Not found in tree.\n");
      
   //Printing tree
   printf("Pre Order Display\n");
   print_preorder(root);

   printf("In Order Display\n");
   print_inorder(root);

   printf("Post Order Display\n");
   print_postorder(root);
}

void insert(TreePtr tree, int val){
   NodePtr temp = NULL;
   if(!(*tree)){
      temp = (node *)malloc(sizeof(node));
      temp->left = temp->right = NULL;
      temp->data = val;
      *tree = temp;
      return;
   }

   if(val == (*tree)->data)
      printf("Duplicate node. Duplicate node not added to tree.\n");
   
   else if(val < (*tree)->data){
      printf("%d < %d. Inserting to left of parent.\n", val, (*tree)->data);
      insert(&(*tree)->left, val);
   }
   
   else if(val > (*tree)->data){
      printf("%d > %d. Inserting to right of parent.\n", val, (*tree)->data);
      insert(&(*tree)->right, val);
   }
}

void print_preorder(NodePtr tree){
   if(tree){
      printf("%d\n",tree->data);
      print_preorder(tree->left);
      print_preorder(tree->right);
   }

}

void print_inorder(NodePtr tree){
   if(tree){
      print_inorder(tree->left);
      printf("%d\n",tree->data);
      print_inorder(tree->right);
   }
}

void print_postorder(NodePtr tree){
   if(tree){
      print_postorder(tree->left);
      print_postorder(tree->right);
      printf("%d\n",tree->data);
   }
}

void delete_tree(NodePtr tree){
   if(tree){
      delete_tree(tree->left);
      delete_tree(tree->right);
      free(tree);
   }
}

NodePtr search(TreePtr tree, int val){
   if(!(*tree))
      return NULL;
   
   if(val < (*tree)->data)
      search(&((*tree)->left), val);
   
   else if(val > (*tree)->data)
      search(&((*tree)->right), val);
   
   else if(val == (*tree)->data)
      return *tree;
}