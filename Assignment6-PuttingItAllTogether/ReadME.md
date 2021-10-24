# Assignment 6 -- Putting It All Together

In this assignment, you'll have to use most of the techniques we have looked at in the module to solve a tricky problem efficiently and elegantly. However, Assignment 5 is a very good starting point.

Write a program to read the contents of a book, such as might be found at the Gutenberg Project, and store the words and the number of times they occur -- a Binary Tree is strongly suggested.

The book must be read from a file, and not from the standard input cin. The user must be able to specify the name of the file in response to a prompt. If the file can not be found, a suitable error message must be printed and the user asked again.

Having read in the book, the program must print out the total number of words in the book and the total number of distinct words.

It should then be possible to repeatedly ask the program to print all word pairs that start with begin with a given word. 

For example, if the user wishes to get all word pairs in the book where the first word is "the" it should be possible for the user to enter the word "the" and for the program to print the total number of pairs and then list them, in alphabetical order of the second word, followed by the number of occurrences of the word pair, as exemplified below.

To terminate the program on cin, the user should signify end of file by typing Control-D, shown as ^D below. 

Here is a sample session:

     Please enter the name of the book file:
     sample.txt
     An error occurred attempting to open the file "sample.txt".
     Please enter the name of the book file:
     samples.txt
     The file "samples.txt" contains 290 words of which 188 are distinct.
     Please enter the word you wish to check:
     the
     Word pairs starting with "the" were found 29 times.
     "the Monophysite" was found once.
     "the barbarians," was found once.
     "the boundless" was found once.
     "the common" was found once.
     "the consequence" was found once.
     "the depths" was found once.
     "the distinctness" was found once.
     "the empire;" was found once.
     "the events." was found once.
     "the historian." was found once.
     "the infinite" was found once.
     "the less" was found once.
     "the manner" was found once.
     "the memory" was found once.
     "the middle" was found once.
     "the operations" was found once.
     "the part" was found once.
     "the reader," was found once.
     "the real" was found once.
     "the regular" was found once.
     "the relative" was found once.
     "the same" was found once.
     "the separate" was found once.
     "the skill" was found twice.
     "the slower" was found once.
     "the superiority" was found once.
     "the thread" was found once.
     "the unity" was found once.
     Please enter the word you wish to check:
     of
     Word pairs starting with "of" were found 19 times.
     "of Gibbon's" was found once.
     "of Le" was found once.
     "of Tillemont," was found once.
     "of a" was found twice.
     "of composition" was found once.
     "of gradually" was found once.
     "of his" was found once.
     "of history," was found once.
     "of narrative," was found once.
     "of six" was found once.
     "of social" was found once.
     "of the" was found 7 times.
     Please enter the word you wish to check:
     period
     Word pairs starting with "period" were found once.
     "period of" was found once.
     Please enter the word you wish to check:
     his
     Word pairs starting with "his" were found 5 times.
     "his facts" was found once.
     "his materials," was found once.
     "his periods" was found once.
     "his way" was found once.
     "his work," was found once.
     Please enter the word you wish to check:
     foo
     The word "foo" was not found.
     Please enter the word you wish to check:
     controversy.
     Word pairs starting with "controversy." were not found.
     Please enter the word you wish to check:
     ^D
     Goodbye
     
Notes

Your implementation must be fast and efficient. It should read the file containing the book once only and should be designed to respond very quickly to a user's query. You probably will have to make a somewhat more complex data structure to maximise performance. Do not use any C++ STL vectors or other containers.
