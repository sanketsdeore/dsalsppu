#include<iostream>

#include<math.h>

using namespace std;

struct Bstnode

{

  int data;

  Bstnode *left=NULL;

  Bstnode *right=NULL;

};

class Btree

{

  int n,x,flag;

  public:

     Bstnode *root;

     Btree()

     {

       root=NULL;

     }

     Bstnode *GetNewNode(int in_data)

     {

       Bstnode *ptr=new Bstnode();

       ptr->data=in_data;

       ptr->left=NULL;

       ptr->right=NULL;

       return ptr;       

     }

     Bstnode *insert(Bstnode *temp,int in_data)

     {

       if(temp==NULL)

       {

         temp=GetNewNode(in_data);

       }

       else if(temp->data > in_data)

       {

         temp->left=insert(temp->left,in_data);

       }

       else

       {

         temp->right=insert(temp->right,in_data);

       }

       return temp;

     }

     

     void input()

     {

       cout<<"ENTER NUMBER OF ELEMENTS IN THE BST: ";

       cin>>n;

       for(int i=0;i<n;i++)

       {

         cout<<"NUMBER= ";

         cin>>x;

         root=insert(root,x);

       }

     }

     

     int search(Bstnode *temp,int in_data)

     {

       if(temp!=NULL)

       {

         if(temp->data==in_data)

         {

           cout<<":-- RECORD FOUND --:"<<endl;

           return 1;

         }

         else if(in_data < temp->data)

         {

           this->search(temp->left,in_data);

         }

         else if(in_data > temp->data)

         {

           this->search(temp->right,in_data);

         }

       }

       else

       {

         return 0;

       }

     }

     

     void minvalue(Bstnode *temp)

     {

       while(temp->left!=NULL)

       {

         temp=temp->left;

       }

       cout<<"MINIMUM VALUE = "<<temp->data<<endl;

     }

     

     void maxvalue(Bstnode *temp)

     {

       while(temp->right!=NULL)

       {

         temp=temp->right;

       }

       cout<<"MAXIMUM VALUE = "<<temp->data<<endl;

     }

     

     void mirror(Bstnode *temp)

     {

       if(temp==NULL)

       {

         return;

       }

       else

       {

         Bstnode *ptr;

         mirror(temp->left);

         mirror(temp->right);

         ptr=temp->left;

         temp->left=temp->right;

         temp->right=ptr;

       }

     }

     

     void display()

     {

       cout<<endl<<"---- INORDER TRAVERSAL ----"<<endl;

       inorder(root);

       cout<<endl;

            }

     

     void inorder(Bstnode *temp)

     {

       if(temp!=NULL)

       {

         inorder(temp->left);

         cout<<temp->data<<" ";

         inorder(temp->right);

       }

     }

     

          

     int depth(Bstnode *temp)

     {

       if(temp!=NULL)

          //return 0;

          return(max((depth(temp->left)),(depth(temp->right)))+1);

     }

};



int main()

{

  int ch,val,cnt;

  int a=0;

  Btree obj;

  obj.input();

  obj.display();

  cout<<" 1.Number of nodes in longest path \n 2.Minimum Data Value found in the tree";

  cout<<"\n 3.Maximum Data Value found in the tree";

  cout<<"\n 4.Change a tree so that the roles of the left and right pointers are swapped at every node";

  cout<<"\n 5.Search a Value \n 6.Inorder Traversal \n 7.Preorder Traversal \n 8.Postorder Traversal \n 9.Exit";

  do

  {

     cout<<"\n Enter a Choice: "<<endl;

     cin>>ch;

    switch(ch)

    {

       case 1:

          cout<<endl<<obj.depth(obj.root)<<endl;

          break;

       case 2:

          obj.minvalue(obj.root);

          break;

       case 3:

          obj.maxvalue(obj.root);

          break;

       case 4:

         obj.mirror(obj.root);

         obj.display();

         break;

       case 5:

         cout<<"Enter value to be search: ";

         cin>>val;

         a=obj.search(obj.root,val);

         if(a==0)

         {

            cout<<"ELEMENT NOT FOUND"<<endl;

         }

         else

           cout<<"ELEMENT FOUND"<<endl;

         cout<<endl<<a<<endl;

         break;

       case 6:

         cout<<endl<<"---- INORDER TRAVERSAL ----"<<endl;

         obj.inorder(obj.root);

         cout<<endl;

         break;

      case 7:

         exit(0);

   }

   cout<<"Do you want to continue(yes=1 and no=0): "<<endl;

   cin>>cnt;

  }while(cnt==1);

  return 0;

}

