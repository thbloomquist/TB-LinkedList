//
//  LinkedList.cpp
//

#include "LinkedList.h"
#include "Flags.h"

/* **************************************************************** */

#if CONSTRUCTOR || ALL
// Constructor
template <class T>
LinkedList<T>::LinkedList()
{
    // TODO: Allocate dummy node
    dummy = new Node<T>(0);
    dummy->next = dummy;
    dummy->prev = dummy;

}
#endif

/* **************************************************************** */

#if DESTRUCTOR || ALL
// Destructor
template <class T>
LinkedList<T>::~LinkedList()
{
//     TODO: Remove any nodes
//
//     TODO: Free dummy node
     makeEmpty();
     delete dummy;
}
#endif

/* **************************************************************** */

#if ALL || GETFIRST
// TODO: getFirst
template <class T>
const T &LinkedList<T>::getFirst() const {
        return dummy->next->data;
}
#endif

/* **************************************************************** */

#if ALL || GETLAST
// TODO: getLast
template <class T>
const T &LinkedList<T>::getLast() const {
    return dummy->prev->data;
}
#endif

/* **************************************************************** */

#if ALL || FIND
// TODO: find
template <class T>
bool LinkedList<T>::find(const T &x) const {
    Node<T> *n = findNode(x);
        return dummy != n;
    }
#endif

/* **************************************************************** */

#if ALL || FINDNODE
// TODO: findNode
template <class T>
Node<T> *LinkedList<T>::findNode(const T &x) const {
    Node<T> *n = dummy->next;

    if(isEmpty()) {
        return n->prev;
    } else {
        while(n->data != dummy->data) {
            if(n->data == x) {
                return n;
            }
            n = n->next;
        }
    }
    return dummy;
}
#endif

/* **************************************************************** */

#if ALL || INSERT
// TODO: insert
template <class T>
void LinkedList<T>::insert(const T &x) {
    Node<T> *n = new Node<T>(x);
    n->next = dummy->next;
    dummy->next->prev = n;
    dummy->next = n;
    n->prev = dummy;
}
#endif

/* **************************************************************** */

#if ALL || REMOVE
// TODO: remove
template <class T>
void LinkedList<T>::remove(const T &x) {
    if(isEmpty()) {

    } else {
        Node<T> *n = findNode(x);
        if(n->data == x) {
            n->prev->next = n->next;
            n->next->prev = n->prev;
            delete n;
        }
    }
}
#endif

/* **************************************************************** */

#if ALL || ISEMPTY
// TODO: isEmpty
template <class T>
bool LinkedList<T>::isEmpty() const {
    return dummy->next->data == dummy->data;
}
#endif

/* **************************************************************** */

#if ALL || MAKEEMPTY
// TODO: makeEmpty
template <class T>
void LinkedList<T>::makeEmpty() {
    Node<T> *curNode = dummy->next;
    if(isEmpty()) {

    } else {
        while(curNode->data != dummy->data) {
            //delete all the nodes
            Node<T> *nxtNode = curNode->next;
            remove(curNode->data);
            curNode = nxtNode;
        }
    }
}
#endif

/* **************************************************************** */

#if ALL || COPY_CONSTRUCTOR
// TODO: Copy constructor
template <class T>
LinkedList<T>::LinkedList(const LinkedList &lst) {
    dummy = new Node<T>(0);
    dummy->next = dummy;
    dummy->prev = dummy;
    *this = lst;
}
#endif

/* **************************************************************** */

#if ALL || ASSIGN
// TODO: Assignment operator
template <class T>
const LinkedList<T> & LinkedList<T>::operator=(const LinkedList<T> &rhs) {
    makeEmpty();

    Node<T> *cNode = rhs.dummy->prev;
    while(cNode->data != dummy->data) {
        Node<T> *nNode = cNode->prev;
        insert(cNode->data);
        cNode = nNode;
    }
    return *this;
}


#endif

/* **************************************************************** */
// Do NOT modify anything below this line
/* **************************************************************** */

#ifndef BUILD_LIB
// Print list
template <class T>
void LinkedList<T>::printList()
{
    if(isEmpty())
    {
        // Empty list
        std::cout << "Empty List" << std::endl;
    } else {
        // Iterate to end
        Node<T> *p = dummy->next;
        
        // Loop to end
        while (p != dummy)
        {
            std::cout << p->data << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }
}
#endif

template class LinkedList<int>;
