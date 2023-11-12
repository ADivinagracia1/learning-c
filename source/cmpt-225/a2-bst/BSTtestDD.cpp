#include <iostream>
#include "BinarySearchTreeDD.h"
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

    cout << "Start of BSTtestDD" << endl;

    key = CAP/2;
    for( i = 1 ; i <= NUMS ; i++ ){
        key = (key + GAP) % CAP ;
        t.insert( key );
    }

    if( NUMS < 40 ){
        cout << "Tree using displayTree():" << endl ;
        t.displayTree();
        for(int j = 0; j < 6; j++)
            t.displayDeep(j);
    }

    cout << "End of BSTtestDD" << endl;

    return 0;
}