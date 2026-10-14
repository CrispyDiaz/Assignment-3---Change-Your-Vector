CS 210 - Assignment 3
(42 points)

Due: Upload .h and .cpp source code files to Canvas

Objectives:
Write and test a C++ program that implements a vector with custom enhancements.

Practice concepts from Ch. 3.

Tasks:
Create a class with a custom name (detailed below) that is a copy of the textbook's Vector.h file with the following added methods:

A method named insert_at(), which takes two parameters: an int representing the index to insert at, and a const Object & with the item to insert at that index.
This is a non-destructive method - the item at that index is not overwritten.  All incumbent items in the vector must also remain in the vector and be relocated in their relative order within the vector.
The method must throw a std::out_of_range exception if the index parameter is negative or greater than the current size of the vector.  (i.e. indices 0->size are valid for this method.)
If the vector is at capacity when the method is called you need to dynamically double the capacity of the vector (plus one item, as in the incumbent code) before the item is inserted.
A method named remove_at(), which takes one parameter: an int representing the index of the item to remove.
This will mutate the vector - the item at that index is removed, as the name suggests.  All incumbent items in the vector must also remain in the vector and be relocated in their relative order within the vector.  There should be no vacant locations between items.
The method must throw a std::out_of_range exception if the index parameter is negative or greater than highest valid index of the vector.  (i.e. indices 0->(size-1) are valid for this method.)
If the vector is at less that 25% capacity after the item is removed you need to dynamically change the capacity of the vector so that it is double the new size of the vector (plus one item, as in the incumbent code)  before exiting the method.
A method named slice(), which takes two parameters: an int representing the index to start the slice at, and another int that represents the total number of items in the slice.
The method will dynamically create a vector of the appropriate size and return it once it has been populated.
The return vector will be comprised of the items in the vector being called, starting at the index represented by the first parameter, and will be populated with the number of items in the second parameter, starting at the provided index.
This is a non-destructive method - no items in the vector are changed.
The method must throw a std::out_of_range exception if the start index parameter is negative or greater than the last occupied index of the vector.  (i.e. indices 0->(size-1) are valid for this method.) It must also throw this exception if there are not enough items in the vector between the start index and the last occupied index.
A method named merge(), which takes one parameter: a const Vector & representing another vector whose contents will be appended to the end of the existing vector being called in the order in which they are stored in the Vector parameter.
The vector is being changed.  Note that this may result in the Vector being dynamically expanded during this process.  Any expansion should be double the previous size (plus one item, as in the incumbent code).
This is a non-destructive method for the parameter - the Vector parameter should not be changed in any way
Note that slice() is the only method that will return anything.
Write a method called author() that will return a string comprised of your full (first and last, as it appears in Canvas) name, and your SDSU ID #.
Write a simple .cpp file with a main() that will create a vector with at least five items and walk it through calls to each of the 5 required methods (call author() first), and call a method you write to first print out the original vector, and then to print out appropriate results of either the original vector or, in the case of slice(), the returned vector.  (Note that you may have seen a very similar method recently.)
Add code to main() that precedes each section with a descriptive caption of what has just been done (e.g. "after calling insert_at(5, 6) ") before outputting the vector.  Include at least one blank line in between each section, but do not space excessively or inconsistently.
None of the incumbent code in Vector.h is to be changed in any way, except for:
A comment block you add at the very top with the same info requested for the previous assignments.
You can change any code that throws an ArrayIndexOutOfBoundsException to throw a std::out_of_range exception instead.
