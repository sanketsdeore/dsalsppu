#include <iostream>
#include <math.h>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

class BST {
    int n, x;
    public:
    node* root = nullptr;
    
    node* create (int);
    node* insert (node*, int);
    void input ();
    void inorder (node*);
    void display ();
    void search (node*, int);
    void min (node*);
    void mirror (node*);
    int depth (node*);
};

node* BST::create (int in_data) {
    node* p = new node();
    p -> data = in_data;
    p -> left = nullptr;
    p -> right = nullptr;
    return p;
}

node* BST::insert (node* temp, int in_data) {
    if (temp == nullptr) {
        temp = create (in_data);
    }
    else if (temp -> data > in_data) {
        temp -> left = insert (temp -> left, in_data);
    }
    else {
        temp -> right = insert (temp -> right, in_data);
    }
    return temp;
}

void BST::input () {
    cout << "\nEnter no. of elements: ";
    cin >> n;
    cout << "\nEnter the elements: ";
    for (int i = 0; i < n; i ++) {
        cin >> x;
        root = insert (root, x);
    }
}

void BST::inorder (node* temp) {
    if (temp != nullptr) {
        inorder (temp -> left);
        cout << temp -> data << " ";
        inorder (temp -> right);
    }
}

void BST::display () {
    cout << "\nInorder Traversal: ";
    inorder (root);
}

void BST::search (node* temp, int in_data) {
    if (temp != nullptr) {
        if (temp -> data == in_data) {
            cout << "\nElement Found!" << endl;
        }
        else if (temp -> data > in_data) {
            search (temp -> left, in_data);
        }
        else {
            search (temp -> right, in_data);
        }
    }
}

void BST::min (node* temp) {
    while (temp -> left != nullptr) {
        temp = temp -> left;
    }
    cout << "\nMinimum element: " << temp -> data;
}

void BST::mirror (node* temp) {
    if (temp != nullptr) {
        node* ptr;
        mirror (temp -> left);
        mirror (temp -> right);
        ptr = temp -> left;
        temp -> left = temp -> right;
        temp -> right = ptr;
    }
}

int BST::depth (node* temp) {
    if (temp != nullptr) {
        return (max (depth (temp -> left), depth (temp -> right)) + 1);
    }
}

int main () {
    BST b;
    int choice, n;
    
    do {
        cout << "\n***Menu***" << endl;
        cout << "\n1. Insert Elements.";
        cout << "\n2. Depth of Tree.";
        cout << "\n3. Minimum element.";
        cout << "\n4. Mirror Tree.";
        cout << "\n5. Search value.";
        cout << "\n6. Display.";
        cout << "\n7. Exit.";
        
        cout << "\nEnter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                b.input ();
                break;
            case 2:
                cout<< "\nDepth of the tree is: " << b.depth (b.root);
                break;
            case 3:
                b.min (b.root);
                break;
            case 4:
                cout << "\nMirroring tree..." << endl;
                b.mirror (b.root);
                b.display ();
                break;
            case 5:
                cout << "\nEnter value to search: ";
                cin >> n;
                b.search (b.root, n);
                break;
            case 6:
                b.display();
                break;
            case 7:
                cout << "\nExiting program..." << endl;
                break;
            default:
                cout << "\nInvalid Input." << endl;
                break;
        }
    } while (choice != 7);
    return 0;
}
