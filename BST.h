// hanya essam eldin mohamed
// habiba amr mohamed
#include<string>
#include<iostream>
using namespace std;
#ifndef BST_H
#define BST_H
class Appointment {
    string patientName;
    int priorityLevel;
    string department;

public:
    Appointment () {
        patientName=" ";
        priorityLevel=0;
        department=" ";
    }


    Appointment (string name,int pLevel,string dep) {
        patientName= name;
        priorityLevel= pLevel;
        department= dep;
    }

    string getPatientName() const {
        return patientName;
    }
    int getPriorityLevel() const {
        return priorityLevel;
    }
    string getDepatment() const {
        return department;
    }

  void display ()const {
        cout << "[" << patientName << ", "
             << priorityLevel << ", "
             << department << "]" << endl;

    }



};

struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    Appointment data;

TreeNode() {
    left= nullptr;
    right = nullptr ; // data will be initialized by appointment constructor

}

    TreeNode(string name,int pLevel,string dep): data(name,pLevel,dep) {
    left= nullptr;
    right = nullptr ;

}
};




class BST {
  TreeNode* root;




    void insert(TreeNode*& currentNode,TreeNode*& newNode ) {
        if (currentNode==nullptr) {
            currentNode=newNode;
        }
        else if (newNode->data.getPriorityLevel()<=currentNode->data.getPriorityLevel()) {
            insert(currentNode->left,newNode);
        }
        else  {
            insert(currentNode->right,newNode);
        }
    }



  void displayInOrder(TreeNode* node) const {
         if (node) {
             displayInOrder(node->left);
             node->data.display();
             displayInOrder(node->right);
         }
     }




    void searchForAppointment(TreeNode* node,int pLevel,int & count) const {
      if (node == nullptr) { return; }

      searchForAppointment(node->left, pLevel, count);
      if (node->data.getPriorityLevel() == pLevel) {
          node->data.display();
          count++;
      }

        searchForAppointment(node->right ,pLevel,count);

    }



    void makeDeletion(TreeNode*& Ptr) {
        TreeNode* T;
        if (Ptr->left == nullptr && Ptr->right == nullptr) {
            delete Ptr;
            Ptr = nullptr;
        } else if (Ptr->right == nullptr) {
            T = Ptr;
            Ptr = Ptr->left;
            delete T;
        } else if (Ptr->left == nullptr) {
            T = Ptr;
            Ptr = Ptr->right;
            delete T;
        } else {

            T = Ptr->right;
            while (T->left) {
                T = T->left;
            }
            T->left = Ptr->left;
            T = Ptr;
            Ptr = Ptr->right;
            delete T;
        }
    }




    void cancel(TreeNode*& node, int priority, int& count) {
        if (node == nullptr) return;


        cancel(node->left,  priority, count);
        cancel(node->right, priority, count);

        if (node->data.getPriorityLevel() == priority) {
            count++;
            makeDeletion(node);
        }
    }



    void displayMoreUrgent(TreeNode* node, int priority, int& count) const {
        if (node == nullptr) return;
        displayMoreUrgent(node->left, priority, count);
        if (node->data.getPriorityLevel() <= priority) {
            node->data.display();
            count++;
        }
        displayMoreUrgent(node->right, priority, count);
    }





    void displayLessUrgent(TreeNode* node, int priority, int& count) const {
        if (node == nullptr) return;
        displayLessUrgent(node->left, priority, count);
        if (node->data.getPriorityLevel()>= priority) {
            node->data.display();
            count++;
        }
        displayLessUrgent(node->right, priority, count);
    }





    void destroySubTree(TreeNode*&nodePtr) {
        if (nodePtr)

        {
            if (nodePtr->left)

                destroySubTree(nodePtr->left);

            if (nodePtr->right)

                destroySubTree(nodePtr->right);

            delete nodePtr;
        }
    }

public:

    BST() {
        root = nullptr;
    }

    ~BST() {
        destroySubTree(root);
    }


    void scheduleAppointment(string name ,int pLevel,string department) {

        TreeNode* newNode=new TreeNode(name,pLevel,department);

       insert(root,newNode);
    }


    void displayAll() const {
        if (root == nullptr) {
            cout << "No appointments found." << endl;
            return;
        }
        displayInOrder(root);
    }

    void search(int key) {

        if (root == nullptr) {
            cout << "No appointments found." << endl;
            return;
        }
        int counter=0;
        searchForAppointment(root,key,counter);

        cout<<counter<<" appointments are found "<<endl;
    }

    void cancelAppointment(int key) {
        if (root == nullptr) {
            cout << "No appointments found." << endl;
            return;
        }

        int counter=0;

   cancel(root,key,counter);
        cout<<counter<<" appointments are cancelled "<<endl;

        }


    void displayMoreUrgentThan(int key ) {

        if (root == nullptr) {
            cout << "No appointments found." << endl;
            return;
        }
        int counter=0;

        displayMoreUrgent(root,key,counter);

        cout<<counter<<" Appointments are Found "<<endl;

    }


    void displayLessUrgentThan(int key) {

        if (root == nullptr) {
            cout << "No appointments found." << endl;
            return;
        }
        int counter=0;

        displayLessUrgent(root,key,counter);

        cout<<counter<<" Appointments are Found "<<endl;

    }

};


#endif
