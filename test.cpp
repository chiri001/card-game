#include <iostream>
using namespace std;

int main(){
    int elem = 0;
    int *array = new int[5];
    for (int i = 0; i < 5; i++){
        array[i] = i + 1;
        elem++;
    }
    for (int i = 0; i < 5; i++){
        cout << array[i];
    }
    cout << elem << endl;
    delete [] array;
    
    for (int i = 0; i < 5; i++){
        elem--;
    }
    for (int i = 0; i < 5; i++){
        cout << array[i];
    }
    cout << elem << endl;
    
    return 0;
}