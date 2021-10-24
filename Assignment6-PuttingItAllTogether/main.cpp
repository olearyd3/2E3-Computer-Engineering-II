#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "node.hpp" 

using namespace std;      

// forward declarations
void print_tree(node* pair_tree, string word_being_checked);
bool process_word_pairs(string new_word1, string new_word2, node*& tree);
bool process_word(string new_word1, node*& single_tree);
int get_word_count(string word_to_check, node*& tree);
int get_word_pair_count(string word_to_check, node*& pair_tree);
int verify_tree(node* tree, string word_being_checked);

int main() {
	bool file_opened = false;
	string filename;
	ifstream ifile;               
  //while there has not been a correct file name entered, ask user to enter file name.
	while (file_opened == false) {
		cout << "Please enter the name of the book file:" << endl;
		cin >> filename;
    //try to open the file
		ifile.open(filename);
    //if the file opens, say it is open and leave loop
		if (ifile.is_open()) { 
			file_opened = true;
		} 
    //if it is not open, say error message and go back to loop start
    else {
			cout << "An error occurred attempting to open the file \"" << filename << "\"." << endl;
		}
	}       

	node* tree = nullptr; // start with an empty tree
  node* pair_tree = nullptr;
  int wordcount = 0;
  int individual_word_count = 0;
  int pair_word_count = 0;
  //while not at the end of the file being read in
  string t_word;
  string u_word;
  ifile >> t_word;
  if (process_word(t_word, tree)) {
    individual_word_count++;
  }
  wordcount++;
  while (ifile.eof() == false) {
    //if not the last word, add one to amount of words
      ifile >> u_word;
      if(ifile.fail() == false) {
        wordcount++;
      //if it is a new word add one to individual word count
        if (process_word_pairs(t_word, u_word, pair_tree)) {
          pair_word_count++;
        }
        if (process_word(u_word, tree)) {
          individual_word_count++;
        }
      }
    t_word = u_word;
  }

  //close the file and print out what it contains
  ifile.close();
  cout << "The file \"" << filename << "\" contains " << wordcount << " words of which " << individual_word_count << " are distinct." << endl;

  //while not reading in the end of the file, ask the user to enter a word to check
  while (cin.eof() == false) {
  	cout << "Please enter the word you wish to check:" << endl;
    //read in the word to be checked
  	string word_check;
  	cin >> word_check;
    //if it is not CTRL D
  	if (cin.fail() == false) {
      //get the amount of times the word appears from the tree using the function
			int occurrence_count = get_word_count(word_check, tree);
      //print out how many times it appears
			if(occurrence_count == 0) {
					cout << "The word \"" << word_check << "\""" was not found." << endl;
      }
			else if(occurrence_count == 1) {
        int verifycounter = (verify_tree(pair_tree, word_check));
            if(pair_word_count == verifycounter) {
            cout << "Word pairs starting with \"" << word_check << "\" were not found." << endl;
        }
			}
			else if(occurrence_count == 2) {
					cout << "Word pairs starting with \"" << word_check << "\" were found twice." << endl;
			}
			else {
					cout << "Word pairs starting with \"" << word_check << "\" were found " << occurrence_count << " times." << endl;
			}
      print_tree(pair_tree, word_check);
  	}
  }
  cout << "Goodbye" << endl;
  return 0;
}

// returns the number of times a word is found at the start of a pair or zero if not found
int get_word_count(string word_to_check, node*& single_tree) {
	int response;
	if (single_tree == nullptr) {
		response = 0; // word is not found
	} 
  else {
		if (word_to_check == *single_tree) {
			response = single_tree->count; // word is found
		} 
    else {
      //if alphabetically before current address, check the branch before for the word
			if (word_to_check < *single_tree) {
				response = get_word_count(word_to_check, single_tree->before);
			} 
      //check the branch after for the word 
      else {
				response = get_word_count(word_to_check, single_tree->after);
			}
		}
	}
	return response;
}

//Counts the amount of times word pairs appear
int get_word_pair_count(string word_to_check, node*& pair_tree) {
	int response;
	if (pair_tree == nullptr) {
		response = 0; // word pair is not found
	} 
  else {

    if (pair_tree->pair_name.find(word_to_check + " ") == 0 && pair_tree->found == false) {
			response = pair_tree->pair_count; // give respomse the value of pair count
		} 
    else {
      //if alphabetically before current address, check the branch before for the word
			if (word_to_check  < *pair_tree) {
				response = get_word_pair_count(word_to_check, pair_tree->before);
			} 
      //check the branch after for the word 
      else {
				response = get_word_pair_count(word_to_check, pair_tree->after);
			}
		}
	}
	return response;
}

// returns true if the word is new, false otherwise
bool process_word(string new_word1, node*& single_tree) {
	bool response;
  //if no memory with the word, assign it to memory
	if (single_tree == nullptr) {
		single_tree = new node();
    single_tree->assign(new_word1);
		response = true; // it is a new word 
	} 
  else {
     //if the word is the current tree place, add one to the count of the word in that place.
		if (new_word1 == *single_tree) {
			single_tree->count++;
			response = false; // it is not a new word
		} 
    //if the word  isn't found, search the tree alphabetically for it
    else {
			if (new_word1 < *single_tree) {
				response = process_word(new_word1, single_tree->before);
			} 
      else {
				response = process_word(new_word1, single_tree->after);
			}
		}
	}
  //return true means word is a new word, return false means it is not a new word
	return response;
}

// returns true if the word pair is new, false otherwise
bool process_word_pairs(string new_word1, string new_word2, node*& pair_tree) {
	bool response;
  string wordpair = new_word1 + " " + new_word2;
  //if no memory with the word, assign it to memory
	if (pair_tree == nullptr) {
		pair_tree = new node();
    pair_tree->assign(wordpair);
    pair_tree->pair_name = wordpair;
		response = true; // it is a new word pair
	} 
  else {
     //if the word pair is the current tree place, add one to the count of the word pair in that place.
		if (wordpair == *pair_tree) {
			pair_tree->pair_count++;
			response = false; // it is not a new word
		} 
    //if the word pair isn't found, search the tree alphabetically for it
    else {
			if (wordpair < *pair_tree) {
				response = process_word_pairs(new_word1, new_word2, pair_tree->before);
			} 
      else {
				response = process_word_pairs(new_word1, new_word2, pair_tree->after);
			}
		}
	}
  //return true means word is a new word, return false means it is not a new word
	return response;
}

void print_tree(node* tree, string word_being_checked) {
  if (tree != nullptr) {
    print_tree(tree->before, word_being_checked);
    if(tree->pair_name.find(word_being_checked + " ") == 0) {
      if(tree->pair_count == 1) {
        cout << "\"" << *tree << "\" was found once." << endl;
        
      }
      else if(tree->pair_count == 2) {
        cout << "\"" << *tree << "\" was found twice." << endl;
      }
      else {
        cout << "\"" << *tree << "\" was found " << tree->pair_count << " times." << endl;
      }
    }
    print_tree(tree->after, word_being_checked);
  }
}

int verify_tree(node* tree, string word_being_checked) {
  bool in_a_pair = false;
  int counter = 0;
  string entered_word = word_being_checked;
  if (tree != nullptr) {
    verify_tree(tree->before, word_being_checked);
    if(tree->pair_name.find(word_being_checked) == 0) {
      in_a_pair = true;
      cout << "Word pairs starting with \"" << entered_word << "\" were found once." << endl;
      counter = 100;
    }
    else {
      verify_tree(tree->after, word_being_checked);
    }
  }
  return counter;
}
