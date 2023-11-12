// #include <iostream>
// #include <time.h> 
// using namespace std;

// double elapsed_time( clock_t start, clock_t finish){
//    // returns elapsed time in milliseconds
//    return (finish - start)/(double)(CLOCKS_PER_SEC/1000);
// }

// int main (int argc, char * const argv[]) {

//    clock_t start, finish ;// used for getting the time.

//    start = clock();
//    /* stuff to time here */
//    for(int i = 0; i < 2000; i++)
//         cout << i << endl;


//    finish = clock();
//    double time_taken = elapsed_time(start,finish);

//     cout << "Runtime: " << time_taken << " ms\n" << endl;
// }

// #include "IVector.h"
// #include <iostream>
// using namespace std;

// int main( )
// {
//     const int N = 20;

//     IVector v ; // Make an int Vector 
//     v.display(); // print its contents
    
//     // Store N ints in the Vector
//     for( int i = 0 ; i < N; ++i )
//     {
//         v.push_back( i );
//     }

//     // print the contents
//     v.display();
    
//     return 0;
// }

#include "TVector.h"
#include <iostream>
using namespace std;


int main( )
{
    const int N = 20;

    TVector<string> v ; // Make an int Vector 
    v.display(); // print its contents
    
    // Store N ints in the Vector
    for( int i = 0 ; i < N; ++i )
    {
        v.push_back( "yee" );
    }

    // print the contents
    v.display();
    
    return 0;
}