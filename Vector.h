#ifndef VECTOR_H
#define VECTOR_H
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include "dsexceptions.h"
#include <string>

/*
    Anthony Diaz / adiaz6040@sdsu.edu
    CS 210 / Scovil
    Assignment 3
*/

template <typename Object>
class Vector
{
  public:
    // My Author Method that
    // prints my name.
    std::string author() const {
        return "Anthony Diaz | 134646574";
    }

    // The Merge method that I implemented.
    void merge(const Vector<Object>& other) {
        for (int i = 0; i < other.size(); ++i) {
            push_back(other[i]);
        }
    }

    //This is the remove_at method I made.
    void remove_at(int index) {
        if (index < 0 || index >= size() ) {
            throw std::out_of_range("Vector index out of range");
        }
            for (int i = index; i < theSize - 1; ++i) {
                objects[i] = objects[i + 1];
        } --theSize;
        if (theSize* 4 <  theCapacity) {
                reserve(2* theSize + 1);
        }
    }

    // This is the slice method I made.
      Vector<Object> slice(int index, int count ) const {

            if (index < 0 || index >= size() ) {
                throw std::out_of_range("Vector index out of range");
            }
            if (index + count  > theSize || count < 0) {
                throw std::out_of_range("Vector index out of range");
            }
            Vector<Object> temp(count);

            for (int i = index; i < index + count; ++i) {
                temp[i - index] = objects[i];
            } return temp;
    }

    // This is the insert_at I made.
    void insert_at(int index, const Object& element) {
        if (index < 0 || index > theSize ) {
            throw std::out_of_range("index out of range");
        }
        if (theSize == theCapacity) {
            reserve(2 * theCapacity + 1);
        }
            for (int i = theSize; i > index; --i) {
                objects[i] = objects[i - 1];
        }
        objects[index] = element;
        ++theSize;
    }

    explicit Vector( int initSize = 0 )
      : theSize{ initSize }, theCapacity{ initSize + SPARE_CAPACITY }
      { objects = new Object[ theCapacity ]; }
      
    Vector( const Vector & rhs )
      : theSize{ rhs.theSize }, theCapacity{ rhs.theCapacity }, objects{ nullptr }
    { 
        objects = new Object[ theCapacity ];
        for( int k = 0; k < theSize; ++k )
            objects[ k ] = rhs.objects[ k ];
    }
    
    Vector & operator= ( const Vector & rhs )
    {
        Vector copy = rhs;
        std::swap( *this, copy );
        return *this;
    }
    
    ~Vector( )
      { delete [ ] objects; }

    Vector( Vector && rhs )
      : theSize{ rhs.theSize }, theCapacity{ rhs.theCapacity }, objects{ rhs.objects }
    {
        rhs.objects = nullptr;
        rhs.theSize = 0;
        rhs.theCapacity = 0;
    }
   
    Vector & operator= ( Vector && rhs )
    {    
        std::swap( theSize, rhs.theSize );
        std::swap( theCapacity, rhs.theCapacity );
        std::swap( objects, rhs.objects );
        
        return *this;
    }
    
    bool empty( ) const
      { return size( ) == 0; }
    int size( ) const
      { return theSize; }
    int capacity( ) const
      { return theCapacity; }

    Object & operator[]( int index )
    {
                                                     #ifndef NO_CHECK
        if( index < 0 || index >= size( ) )
            throw ArrayIndexOutOfBoundsException{ };
                                                     #endif
        return objects[ index ];
    }

    const Object & operator[]( int index ) const
    {
                                                     #ifndef NO_CHECK
        if( index < 0 || index >= size( ) )
            throw ArrayIndexOutOfBoundsException{ };
                                                     #endif
        return objects[ index ];
    }

    void resize( int newSize )
    {
        if( newSize > theCapacity )
            reserve( newSize * 2 );
        theSize = newSize;
    }

    void reserve( int newCapacity )
    {
        if( newCapacity < theSize )
            return;

        Object *newArray = new Object[ newCapacity ];
        for( int k = 0; k < theSize; ++k )
            newArray[ k ] = std::move( objects[ k ] );

        theCapacity = newCapacity;
        std::swap( objects, newArray );
        delete [ ] newArray;
    }

      // Stacky stuff
    void push_back( const Object & x )
    {
        if( theSize == theCapacity )
            reserve( 2 * theCapacity + 1 );
        objects[ theSize++ ] = x;
    }
      // Stacky stuff
    void push_back( Object && x )
    {
        if( theSize == theCapacity )
            reserve( 2 * theCapacity + 1 );
        objects[ theSize++ ] = std::move( x );
    }

    void pop_back( )
    {
        if( empty( ) )
            throw UnderflowException{ };
        --theSize;
    }

    const Object & back ( ) const
    {
        if( empty( ) )
            throw UnderflowException{ };
        return objects[ theSize - 1 ];
    }

      // Iterator stuff: not bounds checked
    typedef Object * iterator;
    typedef const Object * const_iterator;

    iterator begin( )
      { return &objects[ 0 ]; }
    const_iterator begin( ) const
      { return &objects[ 0 ]; }
    iterator end( )
      { return &objects[ size( ) ]; }
    const_iterator end( ) const
      { return &objects[ size( ) ]; }

    static const int SPARE_CAPACITY = 2;

  private:
    int theSize;
    int theCapacity;
    Object * objects;
};

#endif