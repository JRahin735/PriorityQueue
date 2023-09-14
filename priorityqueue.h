/* -------------------------------------------------------
 * @file priorityqueue.h
 * @author Rahin Jain
 * CS 251 - UIC spring '23
 * Assignment details and provided code are created and
 * owned by Adam T Koehler, PhD - Copyright 2023.
 * -----------------------------------------------------*/

#pragma once

#include <iostream>
#include <sstream>
#include <set>
using namespace std;
template<typename T>

class priorityqueue {

private:

    struct NODE {
        int priority;       // used to build BST
        T value;            // stored data for the p-queue
        bool dup;           // marked true when there are duplicate priorities
        NODE* parent;       // links back to parent
        NODE* link;         // links to linked list of NODES with duplicate priorities
        NODE* left;         // links to left child
        NODE* right;        // links to right child
    };

    NODE* root;             // pointer to root node of the BST
    int size;               // # of elements in the pqueue
    NODE* curr;             // pointer to next item in pqueue (see begin and next)

    // HELPER FUNCTIONS ----------------------------------------------------------------------

    // Stores all the data in the BST into a stringStream
    void _convertingString (NODE * func_root, ostream &out) {

        // edge case: tree is empty
        if(func_root == nullptr) {
            return;
        }

        _convertingString(func_root->left, out);

        // saving data in the out stream
        out << func_root->priority <<" value: "<< func_root->value << endl;
        if(func_root->dup){

            NODE * nav = func_root->link;
            while(nav != nullptr) {

                out <<nav->priority <<" value: "<< nav->value << endl;
                nav = nav->link;
            }
        }

        _convertingString(func_root->right,out);
    }

    void _deletion (NODE* func_root) {

        // edge case: tree is empty
        if (func_root == nullptr) {
            return;
        }

        // deleting links while traversing to te bottom of the tree
        if (func_root->dup) {
            _deletion(func_root->link);
        }

        // going left->right
        _deletion(func_root->left);
        _deletion(func_root->right);

        // deleting bottom most node
        delete func_root;

    }


    // Checks is the trees' dup values are equal
    bool dupCheck (NODE* currTree, NODE* otherTree) const{

        // edge case: both nodes have no dups
        if (!(currTree->dup) && !(otherTree->dup)) {
            return true;
        }

        // edge case: one of the nodes are dups and one doesn't
        else if (!(currTree->dup) && otherTree->dup) {
            return false;
        }
        else if (currTree->dup && !(otherTree->dup)) {
            return false;
        }

        // both of the nodes have dups
        else {

            NODE* currNav = currTree;
            NODE* otherNav = otherTree;

            while ((currNav != nullptr) && (otherNav != nullptr) && (currNav->link != nullptr) && (otherNav->link != nullptr)) {

                // iterates in the node content matches
                if ((currNav->link->priority == otherNav->link->priority) && (currNav->link->value == otherNav->link->value)) {
                    currNav = currNav->link;
                    otherNav= otherNav->link;
                }
                // false if data doesn't match
                else {
                    return false;
                }
            }
            return true;
        }
    }

    // Checks if both the trees are equal
    bool _isEqual (NODE* currTree, NODE* otherTree) const{

        // edge case: checks if both the trees are empty
        if (currTree == nullptr && otherTree == nullptr) {
            return true;
        }

        // edge case: checks if one of the trees are empty
        else if (currTree == nullptr && otherTree != nullptr) {
            return false;
        }
        else if (otherTree == nullptr && currTree != nullptr) {
            return false;
        }

        // if none of the trees are not empty
        else {
            if (dupCheck(currTree, otherTree)&&_isEqual(currTree->left, otherTree->left) &&
                _isEqual(currTree->right, otherTree->right) && (currTree->priority == otherTree->priority)
                && (currTree->value == otherTree->value)) {
                return true;
            }
            else {
                return false;
            }
        }
    }

    // Copys the data from other to a new tree and return that
    NODE* _copying (NODE* other) {

        if (other == nullptr) {
            return nullptr;
        }

        // Creating a new node to be inserted in the tree
        NODE* starNode = new NODE;
        starNode->priority = other->priority;
        starNode->value = other->value;
        starNode->dup = other->dup;
        starNode->parent = nullptr;
        starNode->left = nullptr;
        starNode->right = nullptr;
        starNode->link = nullptr;


        // Creating nodes for the duplicated priorities
        if (other->dup) {
            
            NODE* prev = starNode;
            NODE* nav = other;
            while (nav->link != nullptr) {

                NODE* starDupNode = new NODE;
                starDupNode->priority = nav->link->priority;
                starDupNode->value = nav->link->value;
                starDupNode->dup = nav->link->dup;
                starDupNode->parent = prev;
                starDupNode->left = nullptr;
                starDupNode->right = nullptr;
                starDupNode->link = nullptr;

                prev->link=starDupNode;

                nav = nav->link;
                prev = prev->link;
            }
        }
        // traversing right-> left to copy other levels of the tree
        starNode -> right = _copying(other->right);
        starNode -> left = _copying(other->left);

        return starNode;
    }

public:

    // default constructor:
    priorityqueue() {

        root = nullptr;
        size = 0;
        curr = root;
    }

    // Clears "this" tree and then makes a copy of the "other" tree.
    // Sets all member variables appropriately.
    priorityqueue& operator=(const priorityqueue& other) {

        clear();
        this->root = _copying(other.root);
        this->size = other.size;
        this->curr = other.curr;

        return *this;
    }

    // Frees the memory associated with the priority queue but is public.
    void clear() {

        _deletion(root);
        root = nullptr;
        size = 0;
        curr = nullptr;
    }

    // Frees the memory associated with the priority queue.
    ~priorityqueue() {

        clear();
    }

    // Inserts the value into the custom BST in the correct location based on
    // priority.
    void enqueue(T value, int priority) {

        // updating size
        size++;

        // creating a node to be added
        NODE* starNode = new NODE;
        starNode->value = value;
        starNode->priority = priority;
        starNode->dup = false;
        starNode->parent = nullptr;
        starNode->link = nullptr;
        starNode->left = nullptr;
        starNode->right = nullptr;

        bool isDup = false;

        NODE * nav = root;
        NODE * parentNav = nullptr;

        // edge case: if tree is empty
        if (root == nullptr) {

            root = starNode;
            root->parent = nullptr;
            return;
        }

        // taking nav to the postion where the node will be inserted
        while (nav != nullptr) {

            if (priority < nav->priority) {

                parentNav = nav;
                nav = nav->left;
            }

            else if (priority > nav->priority) {

                parentNav = nav;
                nav = nav->right;
            }

            else if (priority == nav->priority) {

                nav->dup = true;
                parentNav = nav;
                isDup = true;
                break;
            }
        }

        // adding in the node
        if(isDup) {

            while (nav->link != nullptr) {

                nav->dup = true;
                nav = nav->link;
            }

            nav->link = starNode;
            nav->dup = true;
            nav->link->parent = nav;
        }

        else if (priority < parentNav->priority) {

            nav = starNode;
            parentNav->left = nav;
            nav->parent = parentNav;
        }

        else if (priority > parentNav->priority) {

            nav = starNode;
            parentNav->right = nav;
            nav->parent = parentNav;
        }
    }

    // returns the value of the next element in the priority queue and removes
    // the element from the priority queue.
    T dequeue() {

        // updating size
        size--;

        T output;
        NODE * nav = root;

        // edge case: if tree is empty
        if (root == nullptr) {
            return T();
        }

        // if root is the left most node
        if (nav->left == nullptr) {

            if (nav->link == nullptr) {

                if (nav->right == nullptr) {

                    // If root doesn't have right node and dups
                    output = root->value;
                    delete nav;
                    root = nullptr;
                    return output;
                }
                else if (nav->right != nullptr) {

                    // If root has right node but no dups
                    NODE* temp = root;
                    root = root->right;
                    output = temp->value;
                    delete temp;
                    root->parent = nullptr;
                    return output;
                }
            }
            else if (nav->link != nullptr){

                if (nav->right == nullptr) {

                    // if root has dup but no right node
                    NODE* temp = root;
                    root = root->link;
                    output = temp->value;
                    delete temp;
                    root->parent == nullptr;
                    return output;
                }
                else if (nav->right != nullptr) {

                    // if root has dup and right node
                    NODE* temp = root;
                    NODE* tempRight = root->right;
                    root = root->link;
                    root->right = tempRight;
                    tempRight->parent = root;

                    output = temp->value;
                    temp -> right = nullptr;
                    temp -> link = nullptr;
                    delete temp;
                    root -> parent = nullptr;
                    return output;
                }
            }
        }
        // if root has left child
        else if (nav->left != nullptr){

            // go to the left most node
            while (nav->left != nullptr) {
                nav = nav->left;
            }

            if (nav->link == nullptr) {

                if (nav->right == nullptr) {

                    // if left most node doens't have right node or dups
                    output = nav->value;
                    NODE* temp = nav;
                    nav->parent->left = nullptr;
                    delete temp;
                    return output;
                }
                else if (nav->right != nullptr) {

                    // if left most node has right node but no dups
                    output = nav->value;
                    NODE* temp = nav;
                    NODE* tempRight = nav->right;
                    nav->parent->left = tempRight;
                    tempRight->parent = nav->parent;

                    delete temp;
                    return output;
                }
            }
            else if (nav->link != nullptr) {

                if (nav->right == nullptr) {

                    // if left most node has dups but no right
                    output = nav->value;
                    NODE* temp = nav;
                    NODE* tempLink = nav->link;

                    nav->parent->left = tempLink;
                    temp->link->parent = nav->parent;
                    delete temp;
                    return output;
                }
                else if (nav->right != nullptr) {

                    // if left most node has dups and right
                    output = nav->value;
                    NODE* temp = nav;
                    NODE* tempLink = nav->link;
                    NODE* tempRight = nav->right;

                    temp->parent->left = tempLink;
                    tempLink->parent = temp->parent;

                    tempRight->parent = tempLink;
                    tempLink->right = tempRight;
                    temp->right = nullptr;
                    temp->link = nullptr;
                    temp->parent = nullptr;

                    delete temp;
                    return output;
                }
            }
        }
    }

    // Returns the # of elements in the priority queue, 0 if empty.
    int Size() {

        return size;
    }

    // Resets internal state for an inorder traversal.  After the
    // call to begin(), the internal state denotes the first inorder
    // node; this ensure that first call to next() function returns
    // the first inorder node value.
    void begin() {

        NODE* nav = root;
        while (nav->left != nullptr) {
            nav = nav->left;
        }
        curr = nav;
    }

    // Uses the internal state to return the next inorder priority, and
    // then advances the internal state in anticipation of future
    // calls.  If a value/priority are in fact returned (via the reference
    // parameter), true is also returned.
    // False is returned when the internal state has reached null,
    // meaning no more values/priorities are available.  This is the end of the
    // inorder traversal.
    bool next(T& value, int &priority) {

        // edge case: tree is empty
        if (curr == nullptr) {
            return false;
        }

        value = curr->value;
        priority = curr->priority;

        // if curr has dups
        if(curr->dup) {

            curr = curr->link;
            return true;
        }
        while (curr->parent != nullptr && curr->priority == curr->parent->priority) {
            curr = curr->parent;
        }

        // taking next val to the right if there is a right node
        if(curr->right != nullptr) {
            curr = curr->right;

            while(curr->left != nullptr){
                curr = curr->left;
            }
            return true;

        }
            // if there is no right node, next needs to traverse up the tree
        else {

            while (curr->parent != nullptr && curr->parent->priority < curr->priority){
                curr = curr->parent;

                if (curr->parent == nullptr){
                    curr = nullptr;
                    return false;
                }
            }

            if(curr->parent!= nullptr){
                curr = curr->parent;
                return true;
            }
        }
        return true;
    }

    // Returns a string of the entire priority queue, in order.
    string toString() {

        stringstream out;

        _convertingString(root, out);
        string output = out.str();

        return output;
    }

    // returns the value of the next element in the priority queue but does not
    // remove the item from the priority queue.
    T peek() {

        if (root == nullptr) {
            return T();
        }

        NODE* nav = root;

        while (nav->left != nullptr) {
            nav = nav->left;
        }
        return nav->value;
    }

    // Returns true if this priority queue as the priority queue passed in as
    // other.Otherwise returns false.
    bool operator==(const priorityqueue& other) const {

        return _isEqual(this->root, other.root);
    }

    // return the root node for testing.
    void* getRoot() {

        return root;
    }
};
