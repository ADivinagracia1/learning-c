/*      
Name:   Andrei Divinagracia
StdN:   301360608
Date:   November 30, 2020
*/

#include <iostream>
#include <fstream>
#include <string>
#include <time.h> 
#include "AvlTree.h"
#include "BinarySearchTree.h"
using namespace std;

const int NUMS   = 1000;        //number of keys in the initial tree
const int LOOP   = 500000;      //number used counting the sequence of operations on the tree
const int GAP    = 317 ;        //dictates the values inside the key (Affects tree shape)
const int CAP    = NUMS+LOOP;   //highest key value in the tree

const int SAMPLE = 10000;       //number of clock cycles for output (smaller number = more values)
const int SRCH   = 5;           //Constant used to determine the keys to search in the tree
const int REMV   = 7;           //Constant used to determine the keys to remove in the tree

void BSTa3Test();
void AVLa3Test();
double elapsed_time( clock_t start, clock_t finish);

int main( ){

    BSTa3Test();
    AVLa3Test();

}

double elapsed_time( clock_t start, clock_t finish){
   // returns elapsed time in seconds
   return (finish - start) / (double)(CLOCKS_PER_SEC);
}

void BSTa3Test(){
    BinarySearchTree<int> t;
    int key, keySearch, keyRemove, bstSize = 0;
    double insAvg = 0, serAvg = 0, remAvg = 0;
    clock_t insStart, serStart, remStart, ins1, ser1, rem1;
    ofstream myFile;

    //Initial Tree - First #NUMS keys of the tree
    key = CAP/2 - GAP;
    for( int i = 0 ; i < NUMS ; i++ ){
        key = (key + GAP) % CAP;
        t.insert( key );
        bstSize++;
    }
    cout << endl;

    keySearch = key;
    keyRemove = key;
    myFile.open( "reportBST.csv" );

    //Insert and Search Sequence
    insStart = clock();
    for( int i = 1 ; i <= LOOP ; i++ ){
        key = (key + GAP) % CAP;
        keySearch = ( keySearch + GAP*SRCH ) % CAP;
        bstSize++;        

        // Insert Operation
        ins1 = clock();
        t.insert( key );
        insAvg += elapsed_time( ins1, clock() ) / i;
        if( bstSize % SAMPLE == 0 )
              myFile << "insert, " << elapsed_time( insStart, clock() ) << ", " << bstSize <<  ", " << t.getHeight()  << ", " <<  t.ipl()/bstSize << ", " << insAvg << endl;

        // // Search Operation 
        // ser1 = clock();
        // if( t.contains( keySearch ) ){
        //     serAvg += elapsed_time( ser1, clock() ) / i;

        //     if( bstSize % SAMPLE*0.1 == 0 )
        //         myFile << "contains, " << elapsed_time( insStart, clock() ) << ", " << bstSize <<  ", " << t.getHeight()  << ", " <<  t.ipl()/bstSize << ", " << serAvg << endl;
        // }
    }

    //Removal Sequence
    remStart = clock();
    for( int i = 1; i <= LOOP; i++){
        keyRemove = (keyRemove + GAP*REMV) % CAP;

        rem1 = clock();
        t.remove( keyRemove );
        remAvg += elapsed_time( rem1, clock() ) / i;

        bstSize--;

        if( bstSize % SAMPLE == 0 )
            myFile << "remove, " << elapsed_time( remStart, clock() ) << ", " << bstSize <<  ", " << t.getHeight()  << ", " <<  t.ipl()/bstSize << ", " << insAvg << endl;
    }
    myFile.close();
    
}

void AVLa3Test(){ //=====================================================================================================================================================================
    AvlTree<int> t;
    int key, keySearch, keyRemove, bstSize = 0;
    double insAvg = 0, serAvg = 0, remAvg = 0;
    clock_t insStart, serStart, remStart, ins1, ser1, rem1;
    ofstream myFile;

    //Initial Tree - First #NUMS keys of the tree
    key = CAP/2 - GAP;
    for( int i = 0 ; i < NUMS ; i++ ){
        key = (key + GAP) % CAP;
        t.insert( key );
        bstSize++;
    }
    cout << endl;

    keySearch = key;
    keyRemove = key;
    myFile.open( "reportAVL.csv" );

   //Insert and Search Sequence
    insStart = clock();
    for( int i = 1 ; i <= LOOP ; i++ ){
        key = (key + GAP) % CAP;
        keySearch = ( keySearch + GAP*SRCH ) % CAP;
        bstSize++;        

        // Insert Operation
        ins1 = clock();
        t.insert( key );
        insAvg += elapsed_time( ins1, clock() ) / i;
        if( bstSize % SAMPLE == 0 )
              myFile << "insert, " << elapsed_time( insStart, clock() ) << ", " << bstSize <<  ", " << t.getHeight()  << ", " <<  t.ipl()/bstSize << ", " << insAvg << endl;

        // // Search Operation 
        // ser1 = clock();
        // if( t.contains( keySearch ) ){
        //     serAvg += elapsed_time( ser1, clock() ) / i;

        //     if( bstSize % SAMPLE*0.1 == 0 )
        //         myFile << "contains, " << elapsed_time( insStart, clock() ) << ", " << bstSize <<  ", " << t.getHeight()  << ", " <<  t.ipl()/bstSize << ", " << serAvg << endl;
        // }
    }

    //Removal Sequence
    remStart = clock();
    for( int i = 1; i <= LOOP; i++){
        keyRemove = (keyRemove + GAP*REMV) % CAP;

        rem1 = clock();
        t.remove( keyRemove );
        remAvg += elapsed_time( rem1, clock() ) / i;

        bstSize--;

        if( bstSize % SAMPLE == 0 )
            myFile << "remove, " << elapsed_time( remStart, clock() ) << ", " << bstSize <<  ", " << t.getHeight()  << ", " <<  t.ipl()/bstSize << ", " << insAvg << endl;
    }
    myFile.close();
}