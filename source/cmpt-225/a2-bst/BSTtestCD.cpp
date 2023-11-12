#include <iostream>
#include "BinarySearchTreeCD.h"
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

    cout << "Start of BSTtestCD" << endl;

    key = CAP/2;
    for( i = 1 ; i <= NUMS ; i++ ){
        key = (key + GAP) % CAP ;
        t.insert( key );
    }

    if( NUMS < 40 ){
        cout << "Tree:" << endl ;
        t.displayTree();
        for(int j = 0; j < 7; j++)
            cout << "Num of nodes at depth " <<  j << ": " << t.countDeep(j) << endl;
    }

    cout << "End of BSTtestCD" << endl;

    return 0;
}