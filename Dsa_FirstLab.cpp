#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    int size = 0;
    int* Array = nullptr;
    int Number = 0;

    ifstream read;
    read.open("Numbers.txt");

    if (read.is_open())
    {
        cout << "File Successfully Opened!" << endl;

        while (read >> Number)
        {
            int* tempArray = new int[size + 1];

            for (int i = 0; i < size; i++)
            {
                tempArray[i] = Array[i];
            }

            tempArray[size] = Number;

            delete[] Array;

            Array = tempArray;

            size++;
        }

        read.close();
    }
    else
    {
        cout << "Unable To Open File" << endl;
    }

    cout << "Array From File: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << Array[i] << " ";
    }

    cout << endl;
    cout << "Now Sorting Array...." << endl;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (Array[i] > Array[j])
            {
                int temp = Array[i];
                Array[i] = Array[j];
                Array[j] = temp;
            }
        }
    }

    cout << "Array After Sorting: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << Array[i] << " ";
    }

    ofstream write;
    write.open("Numbers.txt", ios::app);

    if (write.is_open())
    {
        cout << "File Successfully Opened!" << endl;

        write << endl;
        for (int i = 0; i < size; i++)
        {
            write << Array[i] << " ";
        }

        write.close();
    }
    else
    {
        cout << "Unable To Open File" << endl;
    }

    delete[] Array;

    system("pause");
    return 0;
}
