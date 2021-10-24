# Assignment 4 -- Linked Lists

Description

Write a program, using linked lists, to read the contents of a book, such as might be found at the Gutenberg Project, and print out a list of the words and the number of times they occur, in order of their first occurrence.

You must use a linked list to solve this problem. Any other approach, such as using an array instead, will be awarded zero marks.

You should derive a subclass called word from the C++ string class. The word class will need at least a link property and may need other stuff as well in order to do this assignment.

Example:

For example, if the entire book was the following:

"We feel that the unity and harmony of narrative, which shall comprehend this period of social disorganization, must be ascribed entirely to the skill and luminous disposition of the historian. It is in this sublime Gothic architecture of his work, in which the boundless range, the infinite variety, the, at first sight, incongruous gorgeousness of the separate parts, nevertheless are all subordinate to one main and predominant idea, that Gibbon is unrivalled. We cannot but admire the manner in which he masses his materials, and arranges his facts in successive groups, not according to chronological order, but to their moral or political connection; the distinctness with which he marks his periods of gradually increasing decay; and the skill with which, though advancing on separate parallels of history, he shows the common tendency of the slower or more rapid religious or civil innovations. However these principles of composition may demand more than ordinary attention on the part of the reader, they can alone impress upon the memory the real course, and the relative importance of the events. Whoever would justly appreciate the superiority of Gibbon's lucid arrangement, should attempt to make his way through the regular but wearisome annals of Tillemont, or even the less ponderous volumes of Le Beau. Both these writers adhere, almost entirely, to chronological order; the consequence is, that we are twenty times called upon to break off, and resume the thread of six or eight wars in different parts of the empire; to suspend the operations of a military expedition for a court intrigue; to hurry away from a siege to a council; and the same page places us in the middle of a campaign against the barbarians, and in the depths of the Monophysite controversy."

(From "The History Of The Decline And Fall Of The Roman Empire", by Edward Gibbon.)

The output would begin with the first word:

    "We" 2
    "feel" 1
    "that" 3
    "the" 29
    "unity" 1
    "and" 9
    "harmony" 1
    "of" 19
    "narrative," 1
    "which" 4
    "shall" 1
    "comprehend" 1
    "this" 2
    "period" 1
    "social" 1
    "disorganization," 1
    "must" 1
    "be" 1
    "ascribed" 1
    "entirely" 1
    "to" 10
    "skill" 2
    "luminous" 1
    "disposition" 1
    "historian." 1
    "It" 1
    "is" 2
    "in" 7
    "sublime" 1
    ...
    "depths" 1
    "Monophysite" 1
    "controversy." 1
    
Notes

For the purposes of this assignment, let a "word" be whatever cin reads into a string -- this is what the submission system will expect.
In particular, DO NOT attempt to identify words according to the the strict rules of English. For example, you can see in the example above that "narrative," and "controversy." are accepted as words, even though they include punctation marks. That's okay in this exercise. 
Similarly, DO NOT try to match words that are capitalised differently. For example, in English, the words "This" and "this" are the same word but they are capitalised differently. In this exercise, they should be treated and counted as separate words.
In this submission, your program will be checked against  short "book"s and some larger works from the Gutenberg Project. We will not be revealing all of the books we use.
