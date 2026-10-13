#include <iostream>
#include "Vector.h"
#include <random>
using namespace std;

/*
    Anthony Diaz / adiaz6040@sdsu.edu
    CS 210 / Scovil
    Assignment 3
*/

void print_List(const Vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    Vector<int> v1;
    Vector<int> v2;
    // The Author Method....
    cout << v1.author() << endl << endl;

    // Random Number Generator for the Vectors....
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(0, 99);

   // For loop to randomly generator the vector's elements....
   for (int i = 0; i < 5; ++i) {
       v1.push_back(distribution(gen));
   }
    for (int i = 0; i < 5; ++i) {
        v2.push_back(distribution(gen));
    }

    //Printing the 2 Original Vectors
    cout << "Here is the original Vector: ";
    print_List(v1);
    cout << endl << "And Here is the second Vector: ";
    print_List(v2);
    cout << endl;

    // Calling insert_at method...
    v1.insert_at(3,44);
    cout << "After inserting at (3,44)" << endl;
    print_List(v1);
    cout << endl;

    // Calling remove_at method...
    v1.remove_at(3);
    cout << "After calling remove_at(3)" << endl;
    print_List(v1);
    cout << endl;

    // Calling the slice method...
    Vector<int> slicedVector = v1.slice(1, 2);
    cout << "The returned vector after calling slice(1,2): " << endl;
    print_List(slicedVector);
    cout << endl;

    // Calling the merge method...
    v1.merge(v2);
    cout << "After calling merge(v2): " << endl;
    print_List(v1);
    cout << "And the second vector stays the same: ";
    print_List(v2);
    cout << endl;

}
