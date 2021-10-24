#include <iostream>
#include <string>
#include "word.hpp"

using namespace std;

int main() {
  //Read in the first word of the text
  word *book = nullptr;
  string t_word;
  cin >> t_word;
  book = new word();
  book -> assign(t_word); 
  book -> counter++;

  //Read in the rest of the words until the end of the file
  while (cin.eof() == false) {
    cin >> t_word; 
    word *new_word = new word();
    new_word -> assign(t_word);

    bool found = false;
    word *w = book;

    //Checking through the list of words to see how many times they occur
    while(w != nullptr) {
      //If the word has occurred before, increase its count by 1
      if(*w == *new_word) {
        w -> counter++;
        found = true;
      }
      if(found) {
        break;
      }
      if(w -> next != nullptr) {
        w = w -> next;
      }
      else {
        w -> next = new_word;
      }
    }
  }

  word *w = book; 

  //Print out all of the words that occur and the amount of times that they do
  while (w != nullptr) {
    cout << "\"" << *w << "\"" << " " << w -> counter << endl;
    w = w->next;
  }

  w = book;
  
  //Delete all the objects in the linked list
  while (w != nullptr) {
    word *t = w -> next;
    delete w;
    w = t;
  }
}
