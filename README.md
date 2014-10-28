khaninfection
=============
This is my attempt at the Limited Infection(https://docs.google.com/document/d/1NiKv-MjULOFyyc8f5w8R_EqvuPJ10wJVJgZhtTK9VKc/edit#)

To use this program, edit the main.cpp. Initialize a kagraph object and run adduser() on it for the number of users you want to have. This give you users you can then form connections between.

Run the function addrelation(int,int) where the two ints are the indexes of the coach and the student respectively. The index is the order the node was added starting from zero.

From there you may use the total or limited infections, add or remove users, or update individual users to the most recent version of the site one of their coaches has.

An example tester1 is set up in main.cpp

TODO

-Provide a visualizer

-Encapsulate objects

-Make a better limited_infection by using the numstudents value the user has
