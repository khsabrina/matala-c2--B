#include "mat.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;
using namespace ariel;

int main() {
    //prints vaild matrix when row != col
    for ( int i = 1 ; i < 12 ; i = i*2 +1) {
        cout << ariel::mat(i, i*2 +1, '=', '%') << endl;
    }

    //print valid matrix when row == col 
    for ( int i = 1 ; i < 12 ; i = i*2 +1) {
        cout << ariel::mat(i, i, '=', '%') << endl;
    }
    
    //print exception for invalid input of number when the number is negative
    for (double i = -10 ; i< 0 ; i++){
        try {
        cout << ariel::mat(i, i, '$', '%') << endl; // Exception - not a valid code
    } catch (exception& ex) {
        cout << "   caught exception: " << ex.what() << endl;  // should print "Mat size is always odd"
        }
    }

    //print exception for invalid input of int when the number is even
    for (int i = 2 ; i< 20 ; i= i*2){
        try {
        cout << ariel::mat(i, i, '$', '%') << endl; // Exception - not a valid code
        } catch (exception& ex) {
        cout << "   caught exception: " << ex.what() << endl;  // should print "Mat size is always odd"
        }
    }

    //print exception for invalid input of char when char< 33 
    for (double i = 0 ; i< 33 ; i++){
        try {
        cout << ariel::mat(5, 7, i, '%') << endl; // Exception - not a valid code
        } catch (exception& ex) {
        cout << "   caught exception: " << ex.what() << endl;  // should print "Mat size is always odd"
        }
    }
}