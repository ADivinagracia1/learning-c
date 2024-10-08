#ifndef IVECTOR_H
#define IVECTOR_H

#include <iostream>

class IVector
{
  public:
    // Constructor
    IVector( int initSize = 0 )
      : theSize{ initSize }, theCapacity{ initSize + 10 }
      {  
         objects = new int[ theCapacity ]; 
      }
      
    // Destructor
    ~IVector( )
      { delete [ ] objects; }

    // Check for emptyness
    bool empty( ) const  { return size( ) == 0; }

    // Return size of list 
    int size( ) const { return theSize; }

    // Access the element at a given index
    // This is the non-const version, so you can change the element.
    int & operator[]( int index )
    {
        return objects[ index ];
    }

    // Access the element at a given index
    // This is the const version, for accessing the value only
    const int & operator[]( int index ) const
    {
        return objects[ index ];
    }

    // Increase the capacity (i.e., array size)
    void reserve( int newCapacity )
    {
        if( newCapacity > theSize ){

           int *newArray = new int[ newCapacity ];
           for( int k = 0; k < theSize; ++k ){
                 newArray[ k ] = std::move( objects[ k ] );
           }

           theCapacity = newCapacity;
           std::swap( objects, newArray );
           delete [ ] newArray;
        }
    }

    // Add new element to end of the list 
    void push_back( const int & x )
    {
        if( theSize == theCapacity ) reserve( 2 * theCapacity + 1 );
        objects[ theSize++ ] = x;
    }

    // remove last element from list
    void pop_back( )
    {
        --theSize;
    }

    // Print out the size and contents of the list
    void display() const 
    {
        std::cout << "size=" << theSize << std::endl;

        for( int i = 0; i < theSize ; ++i ){
           std::cout << "[" << i << "]=" << objects[i] << std::endl;
        }
    }

    /* ============================ STUDENT CODE BEGIN ================================= */
    void visitAll(){

        for( int i = 0; i < theSize ; ++i ){
          //objects[i];
          objects[i];   //returns data
        }
    }

    void push_front(const int & x)
    {
        if( theSize == theCapacity ) reserve( 2 * theCapacity + 1 );
    
        theSize++;
        for( int i = theSize - 1; i >= 0 ; i-- ){
          objects[i] = objects[i - 1];
          //std::cout << "[" << i << "] = " << objects[i] << "\t\tSize: " << theSize << std::endl; 
        }     
        objects[0] = x; //adding to front 
    }
    /* ============================= STUDENT CODE END ================================== */

  private:
    int theSize;
    int theCapacity;
    int * objects; // The array is of type int.
};

#endif