#include<iostream>
using namespace std;

int main(){
    int rows;
    cout << "Enter Rows: ";
    cin >> rows;

    int** jagged = new int*[rows];
    int* size = new int[rows];

    // Inputs________

    for (int i = 0; i < rows; i++)
    {
        cout << "Enter size of Rows "<< i+1<<" : ";
        cin >> size[i];

        jagged[i] = new int[size[i]];
        cout<<endl;
        cout << "Element for Rows "<<i+1 << " : " ;
        for (int j = 0; j < size[i]; j++)
        {
            cout << "Enter element "<< i+1<<" :";
            cin >> jagged[i][j];
        }
        
    }

    // For Printing

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < size[i]; j++)
        {
            cout << jagged[i][j] << " ";
        }
        cout << endl;
    }
    
    // Memory free 

    for (int i = 0; i < rows; i++)
    {
        delete [] jagged[i];
    }
    delete [] jagged;
    delete [] size;
    
    



    return 0;
}