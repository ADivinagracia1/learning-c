#include <iostream>
#include "BinarySearchTreeDL.h"
using namespace std;

    // Test program
int main( )
{
    BinarySearchTree<int> t;
//    int NUMS = 400000;
    int NUMS = 17;
    const int GAP  = 3 ;
    const int CAP  = 19;
    int i;
    int key ;

    cout << "Start of BSTtestDL" << endl;

    key = CAP/2;
    for( i = 1 ; i <= NUMS ; i++ ){
        key = (key + GAP) % CAP ;
        t.insert( key );
    }

    if( NUMS < 40 ){
        cout << "Keys:" << endl ;
        t.printTree( );
        cout << "Tree:" << endl ;
        t.displayTree(); 
        cout << "Links:" << endl ;
        t.displayLinks(); //Student Code
    }

    cout << "End of BSTtestDL" << endl;

    return 0;
}