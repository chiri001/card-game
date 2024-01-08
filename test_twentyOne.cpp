//
//
//
//                   Tufts University, Fall 2021 
//                        CS 11: Project 2
//
//    Written by: Rennie Kipchirchir     <29/11/2021>
//

#include <iostream>
#include "Card.h"
#include "CardLinkedList.h"
#include "Deck.h"
using namespace std;


Deck *initialize_game_deck(string filename)
{
    Deck *game_deck = new Deck(filename);

    // Clean up and return
    return game_deck;
}

int main(int argc, char *argv[]){
    
    //Card c(2);
    //Deck draw_card;

        if (argc != 2) {
            cerr << "ERROR: Expected 2 command line arguments, "
                 << "but you provided " << argc << " instead" << endl
                 << "Usage: ./twentyone [filename]" << endl;
            exit(1);
        }

        Deck *game_deck;
        string filename = argv[1];
        game_deck = initialize_game_deck(filename);
        game_deck->debug_print();

    
    // Deck *game_deck;
    // 
    // for (int i = 0; i < 5; i++){
    //     Card c(i);
    //     game_deck  = initialize_game_deck(c);
    //     game_deck->put_card_on_top(c);
    //     cout << c.value() << endl;
    // 
    //     //cout << c.value() << endl;
    // 
    // }
    //  game_deck->draw_top_card();
     
    
    
    
//    Card new_card(game_deck->draw_top_card());
    
    
    
    
    //draw_card.draw_top_card(); 
    
    // for (int i = 0; i < 5; i++){
    //     Deck *cd;
    //     Card c(i);
    //     CardLinkedList l;
    //     cd->put_card_on_top(c);
    //     cout << c.value() << endl;
    // }
    //cout << c.value() << endl;
    
    
    return 0;
}