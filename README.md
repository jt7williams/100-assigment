

# CS 100 Programming Project
**Winter 2019**

William Montes SID: 862095355

Wesley DeVore	 SID: 862081656


# INTRODUCTION

This program is a command shell that will be able to take in commands from user input and execute them in the correct order while handling errors given by incorrect commands. This program will use a composite of connector and command objects stored in a tree to achieve this functionality. We will be using a parsing function to split up the user input into its commands, complete with any arguments for it being converted into a vector of strings and passed into the command constructor, and connectors which include and, or, and the semi-colon. These objects will be passed into a tree, and the tree will execute the commands by an in-order traversal through it with each connector evaluating the left node, then only evaluating the right node if necessary.

# UML DIAGRAM

# CLASS DESCRIPTION

# PROTOTYPE/RESEARCH

# ROADMAP & ISSUES
