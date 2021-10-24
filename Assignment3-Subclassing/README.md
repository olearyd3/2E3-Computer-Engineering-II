# Assignment 3 -- Subclassing

In this assignment, you are to enhance the functionality of Assignment 2 -- which does sorting and printing dates in date order -- to sorting and printing events in date order. Do this by creating a new class called event by subclassing the date class. The event class should extend the date class by having a description field. The description field should be a string object and should be used to describe the event that has or will occur on the date. You should include appropriate getter and setter methods and constructors if appropriate.

Using the event class, write a program to read in up to 20 events, one event per line, in the format:

    year month day:descriptive text

To finish entering dates, enter:

    0 0 0
    
Your program should use an array of event objects. Do not use separate arrays for each of the components of the events.

Here is an example of five events being entered:

    2020 10 23:A day in October
    2000 2 14:Valentine's Day
    2017 7 19:A fine July day
    2008 4 16:April showers -- on and on for hours and hours
    2040 1 31:What a day this will be
    0 0 0

Your program should then print the events out  in ascending order:

    2000 2 14 Valentine's Day
    2008 4 16 April showers -- on and on for hours and hours
    2017 7 19 A fine July day
    2020 10 23 A day in October
    2040 1 31 What a day this will be
    
Your program should issue a prompt at the start:

    Enter the events in year month day:description format, one per line. To finish, enter the date 0 0 0.
    
Note -- you shouldn't have to do much to the date class -- maybe make some private items protected. Make all the enhancements part of the event class.
Hint: to read in an event, read the date information (as in Assignment 2) followed by the colon character, all using the extraction operator (">>") and then use the std::getline() function to read in the rest of the line, which has the event description.
