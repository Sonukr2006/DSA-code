#include<iostream>
using namespace std;

int main(){

    int rows;
    cout<< "Enter row: ";
    cin >> rows;
    int cols;
    cout << "Enter Col : ";
    cin>> cols;

    // Creating dynamic memory allocation
    int ** arr = new int*[rows];
    for(int i = 0; i < rows; i++){
        arr[i] = new int[cols];
    }

    // Taking Input
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element : " ;
            cin >> arr[i][j];
        }
    }
    cout << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
        
    }

    for (int i = 0; i < rows; i++)
    {
        delete []arr[i];
    }

    delete []arr;
    
    
    



    return 0;
}