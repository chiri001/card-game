//
//                       test_linked_list.cpp
//
//     A testing program that creates a CardLinkedList object and
//     tries the basic operations on it, using debug_print to report
//     on the internal state of all objects as it goes.
//
//                   Tufts University, Fall 2021 
//                        CS 11: Project 2
//
//    Modified by: Rennie Kipchirchir
//

#include <iostream>
#include "Card.h"
#include "CardLinkedList.h"
using namespace std;

int main()
{
    // cout << "Making card: value 33" << endl;
    // Card c33(33);
    // c33.debug_print();
    // cout << endl;  // newline for viewing convenience
    // 
    //  cout << "Making linked list" << endl;
    //  CardLinkedList ll;
    //  ll.debug_print();
    // 
    // cout << "Adding card 33 to list" << endl;
    // ll.add_card_at(0, c33);
    // ll.debug_print();

    // Add your own tests here
    
    CardLinkedList cl;
    for (int i = 1; i < 21; i++){
        //making 5 cards of calue 0 to 4 respectively
        Card c(i);
        cl.add_card_at(i, c);
        cl.debug_print();
        
    }
    Card c(98);
    c.debug_print();
    cl.add_card_at(19, c);
    
    
    Card card = cl.get_card_at(0);
         cout << card.value() << endl;

    //prints cards and their position and address
    cl.debug_print();
    
    // unsigned int j = 0;
    // while (j < 12){
    //     //gets value at given position and prints it.
    //     Card c = cl.get_card_at(j);
    //     cout << c.value() << endl;
    //     j++;
    // 
    // }
    
    //gets card at given position, prints value of the card at this position
    //and removes it, then debugs print- showing the cards left
    // Card c = cl.get_card_at(4);
    // cout << "removing card at " << c.value() << endl;
    // cl.remove_card_at(4);
    // cl.debug_print();
    // 
    // 
    // //print number of cards in the list
    // cout << cl.num_cards() << endl;


    return 0;
}

