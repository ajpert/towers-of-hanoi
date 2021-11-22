#include <iostream>
#include <cmath>
#include <cstdlib>


using namespace std;

void towers(int num_disks, int**b,int from_col, int to_col, int spare, int size);
void move(int**b,int from_col, int to_col, int size);

int main(int argc, char const *argv[]) {
    int size =  atoi(argv[1]);
    int **b;
    b = new int*[size];
    for(int i = 0; i < size; i++) {
        b[i] = new int[3];
    }

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < 3; j++) {
                b[i][j] = 0;
            }

        }
    
    for(int i = 0; i < size; i++) {
        b[i][0] = i + 1;
    }

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < 3; j++) {
                cout << b[i][j];
            }
                cout << endl;

        }
        

        towers(size,b,1,2,3,size);
        cout << pow(2,size) - 1 <<  " moves" << endl;

    for(int i = 0; i < size; i++) {
        delete[] b[i];
    }
        delete [] b;
    
    }
   
void towers(int num_disks, int**b,int from_col, int to_col, int spare, int size) {
    if(num_disks >= 1) {
        towers(num_disks-1,b,from_col,spare,to_col,size);




        move(b,from_col,to_col,size);


        for(int i = 0; i < size; i++) {
        for(int j = 0; j < 3; j++) {
                cout << b[i][j];
            }
                cout << endl;

        }
        cout << "--------" << endl;
        towers(num_disks-1,b,spare,to_col,from_col,size);

    }
}


void move(int**b,int from_col, int to_col, int size) {
    int to_row = 0;
    int from_row = 0;
    for(int i = size -1; i >= 0; i--) {
        if(b[i][from_col-1] != 0) {
            from_row = i;
        }
    }
     for(int i = 0; i < size; i++) {
        if(b[i][to_col-1] == 0) {
            to_row = i;
        }
    }
    b[to_row][to_col-1] = b[from_row][from_col-1];
    b[from_row][from_col-1] = 0;

}


