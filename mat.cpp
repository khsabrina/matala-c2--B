#include <iostream>
#include <stdexcept>
using namespace std;
#include "mat.hpp"
#include <vector>
const int LOW_VALID_CHAR = 33;
const int HIGH_VALID_CHAR =126;

namespace ariel{
    string mat(int col, int row, char a , char b){
        if ((col%2 == 0 || row%2 == 0) && (col >= 0 && row >= 0)){
            throw invalid_argument{"Mat size is always odd"};
        }
        if (col< 0 || row< 0){
            throw invalid_argument{"The size of the mat can't be negative"};
        }
        if (a < LOW_VALID_CHAR || a > HIGH_VALID_CHAR || b < LOW_VALID_CHAR || b > HIGH_VALID_CHAR){
            throw invalid_argument{"Invalid input of char"};
        }
        string mat_str;
        vector<vector<char>> mat(row, vector<char>(col));
        int mat_num_rectangle = 0 ;
        //checking how many "rectangle" of the chars are going to be in the mat
        if (col<row){
             mat_num_rectangle = col / 2 +1;
        }
        else {mat_num_rectangle = row /2 +1;}
        //looping to create the mat from outside to inside
        // i is the number of "rectangle" that we are creating
        for (int i = 0; i< mat_num_rectangle ; i++){
            //when i&2 = 0 then it will create the "rectangle" of the first char
            if (i % 2 == 0){
                for(int j = i; j<col-i;j++){
                    mat[i][j] = a;
                }
                for(int j = i; j<row-i;j++){
                    mat[j][i] = a;
                }
                for(int j = i; j<col -i;j++){
                    mat[row-i-1][j] = a;
                }
                for(int j = i; j<row-i;j++){
                    mat[j][col-i-1] = a;
                }
            }
            //when i&2 != 0 then it will create the "rectangle" of the second char
            else{
                for(int j = i; j<col-i;j++){
                    mat[i][j] = b;
                }
                for(int j = i; j<row-i;j++){
                    mat[j][i] = b;
                }
                for(int j = i; j<col-i;j++){
                    mat[row-i-1][j] = b;
                }
                for(int j = i; j<row-i;j++){
                    mat[j][col-i-1] = b;
                }
            }
        }
        //moves the matrix of the mat to a string that presents the mat 
        for (int i=0; i<row;i++){
            for(int j=0;j<col;j++){
                mat_str += mat[i][j];
            }
            mat_str +=  "\n";
        }
        return mat_str;
    }

}
