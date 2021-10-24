# Assignment 5 -- Files, Binary Trees, Error Handling

In this assignment, we are bringing together a number of ideas and techniques that you would have encountered -- file handling, dealing with errors and using binary trees for efficiency.

Write a program to read the contents of a book, such as might be found at the Gutenberg Project, and store the words and the number of times they occur in a binary tree.

The book must be read from a file, and not from the standard input cin. The user must be able to specify the name of the file in response to a prompt. If the file can not be found, a suitable error message must be printed and the user asked again.

Having read in the book, the program must print out the total number of words in the book and the total number of distinct words.

It should then be possible to repeatedly ask the program to print the number of times a word occurs in the book. If the word does not occur, a suitable message should be printed.

To terminate the program on cin, the user should signify  end of file by typing Control-D, shown here as ^D (this is a convention -- the ^ is interpreted as holding down the Control ("CTRL") key). 

Here is a sample session:

    Please enter the name of the book file:
    sample.txt
    An error occurred attempting to open the file "sample.txt".
    Please enter the name of the book file:
    samples.txt
    The file "samples.txt" contains 290 words of which 188 are distinct.
    Please enter the word you wish to check:
    the
    The word "the" was found 29 times.
    Please enter the word you wish to check:
    not
    The word "not" was found once.
    Please enter the word you wish to check:
    on
    The word "on" was found twice.
    Please enter the word you wish to check:
    fire
    The word "fire" was not found.
    Please enter the word you wish to check:
    ^D
    Goodbye
    
