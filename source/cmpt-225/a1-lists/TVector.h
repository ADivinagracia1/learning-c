#ifndef TVECTOR_H
#define TVECTOR_H

#include <iostream>

// This is a template class: Objecet is the type of
// the values or objects we are storing in the list. 
template <typename Object>
class TVector
{
  public:
    TVector( int initSize = 0 )
      : theSize{ initSize }, theCapacity{ initSize + 10 }
      {  
         objects = new Object[ theCapacity ]; 
      }
      
    ~TVector( )
      { delete [ ] objects; }

    bool empty( ) const  { return size( ) == 0; }
    int size( ) const { return theSize; }

    Object & operator[]( int index )
    {
        return objects[ index ];
    }

    const Object & operator[]( int index ) const
    {
        return objects[ index ];
    }

    void reserve( int newCapacity )
    {
        if( newCapacity > theSize ){

           Object *newArray = new Object[ newCapacity ];
           for( int k = 0; k < theSize; ++k ){
                 newArray[ k ] = std::move( objects[ k ] );
           }

           theCapacity = newCapacity;
           std::swap( objects, newArray );
           delete [ ] newArray;
        }
    }

    void push_back( const Object & x )
    {
        if( theSize == theCapacity ) reserve( 2 * theCapacity + 1 );
        objects[ theSize++ ] = x;
    }

    void pop_back( )
    {
        --theSize;
    }

    void display() const 
    // Assumes that the cout will do something reasonable with 
    // whatver type Objects is.
    {
        std::cout << "size=" << theSize << std::endl;

        for( int i = 0; i < theSize ; ++i ){
           std::cout << "[" << i << "]=" << objects[i] << std::endl;
        }
    }

  private:
    int theSize;
    int theCapacity;
    Object * objects;
};

#endif