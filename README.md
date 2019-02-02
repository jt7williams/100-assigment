

# CS 100 Programming Project
**Winter 2019**

William Montes SID: 862095355

Wesley DeVore	 SID: 862081656


# INTRODUCTION

This program is a command shell that will be able to take in commands from user input and execute them in the correct order while handling errors given by incorrect commands. This program will use a composite of connector and command objects stored in a tree to achieve this functionality. We will be using a parsing function to split up the user input into its commands, complete with any arguments for it being converted into a vector of strings and passed into the command constructor, and connectors which include and, or, and the semi-colon. These objects will be passed into a tree, and the tree will execute the commands by an in-order traversal through it with each connector evaluating the left node, then only evaluating the right node if necessary.

# UML DIAGRAM

# CLASS DESCRIPTION

**window**

The first class that our project will use will be the *window* class that generates the test box that the user interacts with and handles the input and output. 

**composite**

The group of classes that we are using will be part of a base that has the **compute()** function. This function be what is run throughout the tree to get the proper functionality.

The group goes into one of two classes, the *command* class and the *separator* class.

The *command* class is the class that holds the type of command being executed such as echo and ls and its **compute()** will excecute that command when called. This class will be constructed with a string and a vector of strings. The string will hold the type of command, like echo and ls, whereas the vector will hold the arguments that come with that command if any.

The *separator* class contains a left and right base child, and can be split into three subclasses of *and*, *or*, and *semiColon*. These classes inherit the **compute()** function from *separator*, but all three execute it in a different way. 

The *and* class will run **compute()** on its left child and only run right child if the left child **compute()** returns a positive. 

The *or* class will run **compute()** on its left child and only run right child if the left child **compute()** returns a negative. 

The *semiColon* class will always run its left child **compute()** and then its right child **compute()** if it has a right child.

# PROTOTYPE/RESEARCH

# ROADMAP & ISSUES
