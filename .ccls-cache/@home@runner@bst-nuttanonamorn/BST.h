// An integer binary search tree
#include <stdio.h>
#include <stdlib.h>

struct treeNode {                                           
    struct treeNode *leftPtr; // pointer to left subtree
    int data; // node value                               
    struct treeNode *rightPtr; // pointer to right subtree
}; // end structure treeNode 

typedef struct treeNode TreeNode;
typedef TreeNode * TreeNodePtr; // synonym for TreeNode*
                    
typedef struct {
	int size;
	TreeNodePtr root;
}BST;

// prototypes

void insertNode( BST *, int );

void insertNode_R(TreeNodePtr * t,int value){
  if(*t==NULL){
    (*t) = (TreeNodePtr) malloc(sizeof(TreeNode));
	  if(*t){
		  (*t)->leftPtr=NULL;
		  (*t)->rightPtr=NULL;
		  (*t)->data=value;
   }
    else printf( "%d not inserted. No memory available.\n", value );
  }
  else{
     if((*t)->data>=value) insertNode_R(&(*t)->leftPtr,value); //left
        
     else insertNode_R(&(*t)->rightPtr,value); //right
      
   }
}

void insertNode( BST *b, int value ){
	 TreeNodePtr t =b->root,new_node;
	 int inserted=0;
	new_node =(TreeNodePtr) malloc(sizeof(TreeNode));
	if(new_node){
		new_node->leftPtr=NULL;
		new_node->rightPtr=NULL;
		new_node->data=value;
		/*First Node*/
		if(!b->root)	b->root=new_node;
		else {
    while(!inserted){
    if(t->data >=value){
      /* move/ insert to the left*/
      if(!t->leftPtr){
        t->leftPtr=new_node;
        inserted = 1;
        }
      else{
          t=t->leftPtr; 
      }
     } //end if left.
  	 
    else{
	      /* move/ insert to the right*/
      if(!t->rightPtr){
        t->rightPtr=new_node;
        inserted = 1;
        }
      else{
        t=t->rightPtr;
      }
    } // end else right.
   
  }//end while		
  }//end else;
  b->size++;
  }
  
}//end function


void inOrder( TreeNodePtr treePtr )
{ 
   // if tree is not empty, then traverse
   if ( treePtr != NULL ) {        
        
      inOrder( treePtr->leftPtr ); //Recursion to the left
 
      printf("%5d",treePtr->data) ;  //print the value 
   
      inOrder( treePtr->rightPtr ); //Recursion to the right
   } // end if                          
} // end 

void preOrder( TreeNodePtr treePtr )
{
  if (treePtr != NULL){
    
    printf("%5d",treePtr->data);
    
    preOrder(treePtr->leftPtr);
    
    preOrder(treePtr->rightPtr);
  }
}

void postOrder( TreeNodePtr treePtr )
{
  if (treePtr != NULL){
    
    postOrder(treePtr->leftPtr);
    
    postOrder(treePtr->rightPtr);

    printf("%5d",treePtr->data);
  }
}

void printTree( TreeNodePtr treePtr , int count)
{
  TreeNodePtr root_tree = treePtr;
  if (treePtr != NULL)
  {
    printTree(treePtr->rightPtr,count+1);
    
    for(int i=0; i<count; i++){
      printf("      ");
      }
    
    if(treePtr == root_tree) printf("%d\n",treePtr->data);
      
    else printf("%5d\n",treePtr->data);

    printTree(treePtr->leftPtr,count+1);
    
  }
}
