  #include<stdio.h>
  #include<stdlib.h>
  struct node
  {
    int data;
    struct node *left,*right;
  };
  struct node * insert(struct node *root,int x)
  {
    if(root==NULL)
    {
      root=malloc(sizeof(struct node));
      root->data=x;
      root->left=root->right=NULL;
    }
    else if (x<root->data)
      root->left=insert(root->left,x);
    else if(x>root->data)
      root->right=insert(root->right,x);
    else
      printf("duplicate value\n");
      
      return root;
    }
  void display(struct node *root)
  {
    if(root!=NULL)
    {
      display(root->left);
      printf("%d\t",root->data);
      display(root->right);
    }
  }
  
  void search(struct node *root,int x)
  {
    if(root==NULL)
      printf("not found\n");
    else if (root->data==x)
      printf("found \n");
    else if (x<root->data)
      search(root->left,x);
    else
      search(root->right,x);
  }
  
  struct node* minimum(struct node *root)
    {
      while(root->left!=NULL)
        root=root->left;
      return root;
    }
  struct node* delete(struct node *root,int x)
    {
      if(root==NULL)
        return NULL;
      if(x < root->data)
        root->left=delete(root->left,x);
      else if (x>root->data)
        root->right=delete(root->right,x);
      else
      {
        struct node *temp;
        if(root->left == NULL)
          {
            temp=root->right;
            free(root);
            return temp;
          }
        if(root->right==NULL)
          {
            temp=root->left;
            free(root);
            return temp;
          }
        temp=minimum(root->right);
        root->data=temp->data;
        root->right = delete(root->right,temp->data);
        }
        return root;
      }
int main()
{
  struct node *root=NULL;
  int ch,x;
  while(1)
  {
    printf("\n1.insert");
    printf("\n2.display");
    printf("\n3.search");
    printf("\n4.delete");
    printf("\n5.exit");
    printf("\nenter choice");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
        printf("enter value:");
        scanf("%d",&x);
        root=insert(root,x);
        break;
      
      case 2:
        display(root);
        break;
        
      case 3:
      printf("enter value:");
      scanf("%d",&x);
      search(root,x);
      break;
      
      case 4:
        printf("enter value:");
        scanf("%d",&x);
        root=delete(root,x);
        break;
      
      case 5:
        exit(0);
      default:
        printf("wrong choice");
      }
      
    }
    return 0;
  }
      



















