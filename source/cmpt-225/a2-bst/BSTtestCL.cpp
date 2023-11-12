#include <iostream>
#include "BinarySearchTreeCL.h"
using namespace std;

    // Test program
int main( )
{
    BinarySearchTree<int> t;
    //int NUMS = 400000;
    int NUMS = 17;
    const int GAP  = 3 ;
    const int CAP  = 19;
    int i;
    int key ;

    cout << "Start of BSTtestCL" << endl;

    key = CAP/2;
    for( i = 1 ; i <= NUMS ; i++ ){
        key = (key + GAP) % CAP ;
        t.insert( key );
    }

    if( NUMS < 40 ){
        cout << "Tree:" << endl ;
        t.displayTree(); 
        cout << "Num of leaves when NUMS = "<< NUMS << ":\t" << 6 << endl;
        cout << "Num of leaves from function:\t" << t.countLeaves() << endl;
    }
    
    cout << "End of BSTtestCL" << endl;

    return 0;
}