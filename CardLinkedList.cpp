//
//                         CardLinkedList.cpp
//
//           A class that manages a linked list of cards
//
//  The data are stored as a singly-linked sequence of nodes accessed
//  from a single pointer (in the data member 'm_front') to the first
//  node in the list (or the nullptr if the list is empty). Each node
//  has a Card instance named card.
//
//  Author: Noah Mendelsohn 
//
//  Tufts University, Fall 2021
//  CS 11: Project 2
//
//  Modified by: Rennie Kipchirchir
//  Date: 22 Nov 2021
// 
//  Anything else you would like to include:
//

/**********************************************************/
/***      Students: Fill in the TODO items below        ***/
/***  You may add additional private member functions   ***/
/**********************************************************/

#include <iostream>
#include <iomanip>     // gets setw for debug printing
#include <string>

#include "CardLinkedList.h"

using namespace std;

/*------------------------------------------------------------------
 *                    Constructor(s) and Destructor
 *----------------------------------------------------------------*/

//
// Purpose:  Constructor initializes an empty list
//
CardLinkedList::CardLinkedList()
{
    // TODO
    m_front = nullptr;
    m_list_length = 0;
}

//
// Purpose:  Destructor recycles the space associated with all nodes
//           in the list
//
CardLinkedList::~CardLinkedList()
{
    // TODO
    while (m_front != nullptr){
        Node *temp = m_front;
             m_front = m_front->next;
             delete temp;
    }
}

/*------------------------------------------------------------------
 *          Public functions to manipulate and query the list
 *----------------------------------------------------------------*/

//
// Purpose:  Return the current size of the list
//           i. e., the number of words/nodes in the list
//
unsigned int CardLinkedList::num_cards()
{
    // TODO
    return m_list_length;
}

//
// Purpose:  Add Card node to the list at the specified position. If index is
//           out of range then return quietly
//
//           Recycles the node containing the word (and its count)
//
void CardLinkedList::add_card_at(unsigned int index, Card c)
{
    
    unsigned int count = 0;
    
    if (m_front != nullptr){
        Node *prev;
        prev = m_front;
        while (prev->next != nullptr and count < (index - 1)){
            prev = prev->next;
            count++;
        }
        if (index == 0){
            //adding to the front
            Node *newNode = new Node;
            newNode->card = c;
            newNode->next = m_front;
            m_front = newNode;
            m_list_length++;
        }
        else if (prev == nullptr and index == count + 1){
            //adding to back
            Node *newNode = new Node;
            prev->next = newNode;
            newNode->card = c;
            newNode->next = nullptr;
            m_list_length++;
        }
        else if (prev == nullptr){
            // out of range return quietly
            return;
        }
        else {
            //add at position other than front or back
            Node *newNode = new Node;
            newNode->card = c;
            newNode->next = prev->next;
            prev->next = newNode;
            
            
            m_list_length++;
        }
    } else {
        //add to front as list is empty
        Node *newNode = new Node;
        m_front = newNode;
        newNode->card = c;
        newNode->next = nullptr;;
        m_list_length++;
    
    } 
}

//
// Purpose:  Remove word from the list.  That is, it removes and
//           recycles the node containing the word (and its count)
//
void CardLinkedList::remove_card_at(unsigned int index)
{
    //TODO
    Node *temp;
    unsigned int count = 0;
    

    if (m_front == nullptr){
        //list is empty
        return;
        
    } else if (index == 0){
        //removing from front and reducing length
        temp = m_front;
        m_front = m_front->next;
        delete temp;
        m_list_length--;
        
    } else {
        temp = m_front;
        while (temp->next != nullptr and count < (index  - 1) ) {
            
            count++;
            temp = temp->next;
            }
            
    } 

    if (temp == nullptr){
        //index out of range
        return;
    } else if (index > 0){
        //removing at position and reducing length
        Node *prev = temp->next->next;
        delete temp->next;
        temp->next = prev; 
        m_list_length--;
    }
    
}


//
// Purpose:  Return the index-th element of the list
// Params:   index must be in range [0 .. size) where
//           size is the number of words stored in the list
// Effects:  if index is out of range, prints error message and returns
//           NO_CARD_HERE
Card CardLinkedList::get_card_at(unsigned int index)
{
    // TODO
    Node *np;
    unsigned int count = 0;

    
    //Iterate to find the card of given index
    for (np = m_front; (np != nullptr and count < index); np = np->next){
        count++;
    }
    
    
    if (np == nullptr){
        //card with given index is out of range, returns NO_CARD_HERE
        return NO_CARD_HERE;
    
    } 
    else {
        //returns given card
        return np->card;
    }
}


//
// Purpose:  Print out the underlying list to cout
// Effects:  Prints to cout
// Notes:    This function is here for debugging purposes.
//           It will not be called in the final version of the program.
//           Still LEAVE IT AS-IS:  WE WILL USE IT FOR TESTING.
//
void CardLinkedList::debug_print()
{
    int index_num = 0;

    cout << "DEBUG: CardLinked List (num_cards = " << num_cards()
         << ") ["  << endl;
    cout <<  "  Index_num   Node Address  Face Value" << endl;
    for (Node *curr_p = m_front; curr_p != nullptr; curr_p = curr_p->next) {
        cout <<  setw(9) << index_num++;
        cout <<  setw(16) << curr_p;
        cout <<  "       ";
        curr_p->card.debug_print();
        cout << endl;
    }
    cout << "]" << endl;
}

