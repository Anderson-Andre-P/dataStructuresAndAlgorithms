# DSA

An efficient way to store data.

## What are Data Structures?

We structure data in different ways depending on what data we have, and what we want to do with it.

First, let's consider an example without computers in mind, just to get the idea.

![Lowest value complexity](../images/arrays/familyTree.jpg)

If we want to store data about people we are related to, we use a family tree as the data structure. We choose a family tree as the data structure because we have information about people we are related to and how they are related, and we want an overview so that we can easily find a specific family member, several generations back.

With a data structure of your family family tree, it would be easy to see, for example, who your mother's mother is – your grandmother in this case, right? But without parent-child links present in the tree, it would be difficult to determine how individuals are related.

An data structure provide us the possibility to manage large amounts of data efficiently for uses such as large databases and internet indexing services.

Data structures are essential ingredients in creating fast and powerful algorithms. They help in managing and organizing data, reduce complexity, and increase efficiency.

## Different kinds of data structures

In computer science there are two different kinds of data structures.

**Primitive Data Structures:** are basic data structures provided by programming languages to represent single values, such as integers, floating-point numbers, characters, and booleans.

**Abstract Data Structures:** are higher-level data structures that are built using primitive data types and provide more complex and specialized operations. Some commim examples of abstract data structures include arrays, linked lists, stacks, queues, trees, and graphs.

## What are algorithms?

An algorithm is a set of step-by-step instructions to solve a given problem or achieve a specific goal.

For example, think an recipe writthen on a piece of paper, where the goal is to make certain dinner. The steps needed to make a specific dinner are described exactly.

When we talk about algorithms in computer science, the step-by-step instructions are written in a programming language, an algorithm uses data structures.

Algorithms are fundamental to computer programming as they provide step-by-step instructions for executing tasks. An efficient algorithm can help us to find the solution we are looking for, and transform a slow program into a faster one.

By studying algorithms, developers can erite better programs.

Algorithm examples:

- Finding the fastest toute in a GPS navigation system;
- Navigating an airplane or a car (cruise control);
- Finding what users search for (search engine);
- Sorting, for example sorting movies by rating.

The algorithms we will look at in this file are designed to solve specific problems, and are often made to work on specific data structures. For example, the "Bubble Sort" algorithm is designed to sort values, and is made to work on arrays.

## Data structures together with Algorithms

Data Structures and Algorithms (DSA) go hand in hand. A data structure (DS) is not worth much if you cannot search through it or manipulate ir efficiently using algorithms, and the algorithms in here are not worth much without a DS to work on.

DSA is about finding efficient ways to store and retrieve data, to perform operations on data, and to solve specific problems.

By understanding DSA, you can:

- Decide which data structure or algorithm is best for a given situation;
- Make programs that run faster or use less memory;
- understand how to approach complex problems and solve them in a systematic way.

## Where is DSA needed?

DSA are used in virtually every software system, from operating systems to web applications:

- For managing large amounts of data, such as in a social network or a search engine;
- For scheduling tasks, to decide which task a computer should first;
- For planning routes, like in a GPS system to find the shortest path from A to B;
- For optimizing processes, such as arranging tasks so they can be completed as quickly as possible;
- For solving complex problems: from finding the best way to pack a truck to making a computer 'learn' from data.

DSA is fundamental in nearly every part of the software world:

- Operating systems;
- Database systems;
- Web applications;
- Machine learning;
- Video games;
- Cryptographic systems;
- Data analysis;
- Search engines.

## Theory and Terminology

As we go along in this file, new theorical concepts and terminology will be needed so that we can better understanding the DSA we will be working on.

These new words and concepts will be introduced and explained properly when they are needed, but here is a list of some key terms, just to get an overview of what is coming.

| Term                | Description                                                                                                                                                                                                              |
| :------------------ | :----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Algorithm           | A set of step-by-step instructions to solve a specific problem                                                                                                                                                           |
| Data Structure (DS) | A way of organizing data so it can be used efficiently. Common data structures include arrays, linked lists, and binary trees.                                                                                           |
| Time Complexity     | A measure of the amount of time an algorithm takes to run, depending on the amount of data the algorithm is working on.                                                                                                  |
| Space Complexity    | A measure of the amount of memory an algorithm uses, depending on the amount of data the algorithm is working on.                                                                                                        |
| Big O Notation      | A mathematical notation that describes the limiting behavior of a function when the argument tends towards a particular value or infinity. Used in this tutorial to describe the time complexity of an algorithm.        |
| Recursion           | A programming technique where a function calls itself.                                                                                                                                                                   |
| Divide and Conquer  | A method of solving complex problems by breaking them into smaller, more manageable sub-problems, solving the sub-problems, and combining the solutions. Resursion is often used when using this method in an algorithm. |
| Brute Force         | A simple and straight forward way an algorithm can work by simply trying all possible solutions and then choosing the best one.                                                                                          |
