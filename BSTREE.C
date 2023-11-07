#include<stdio.h>
#include<conio.h>
struct Node
{
int data;
struct Node *left,*right;
};
struct Node *root;
struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) 
{
    if (root == NULL) {
        return createNode(data);
    }
    
    if (data < root->data) {
	root->left = insert(root->left,data);
    } else if (data >root->data) {
	root->right=insert(root->right,data);
    }
    
    return root;
}


struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node* deleteNode(struct Node* root, int data) {
    struct Node *temp;
    if (root == NULL) {
	return root;
    }

    if (data < root->data) {
	root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
	root->right = deleteNode(root->right, data);
    } else {
	if (root->left == NULL) {
	    struct Node* temp = root->right;
	    free(root);
	    return temp;
	} else if (root->right == NULL) {
	    struct Node* temp = root->left;
	    free(root);
	    return temp;
	}
	temp = minValueNode(root->right);
	root->data = temp->data;
	root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    
    if (key < root->data) {
        return search(root->left, key);
    }
    
    return search(root->right, key);
}
 void inorder(struct Node *p)
 {
 if(p!=NULL)
     {
       inorder(p->left);
       printf("\t%d",p->data);
       inorder(p->right);
     }
 }
 void main()
 {
 struct Node* root = NULL;
 struct Node *result;
 int n,i,value,ch;
 do{
 printf("Enter your choice \n1.Insert \n2.Inorder traversing \n3.Search \n4.Delete \n5.Exit\n");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1:
     {
    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);
    printf("Enter %d elements to insert:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
      }
      }
	    break;
  case 2:
	   inorder(root);
	   getch();
	   break;
  case 3:
       {
       printf("\nEnter a value to search in the BST: ");
       scanf("%d", &value);
       result = search(root, value);
       if (result != NULL) 
       {
       printf("%d found in the BST.\n", value);
       } 
       else {
        printf("%d not found in the BST.\n", value);
        }
        }
       break;
  case 4:
       {
    printf("Enter a value to delete from the BST: ");
    scanf("%d", &value);
    root = deleteNode(root, value);
    printf("In-order traversal after deleting %d: ", value);
    inorder(root);
       }
      break;
   case 5:
            exit(0);
  default:
      {
      printf("Invalid choice");
      getch();
      }
  }
  }while(1);
  }