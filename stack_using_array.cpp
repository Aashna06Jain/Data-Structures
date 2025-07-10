#include <bits/stdc++.h>
using namespace std;

const int CAPACITY = 10;

int print_top(int arr[], int &top){
    if(top == -1){
        cout << "There are no elements\n" << endl;
        return -1;
    }
    cout << "Top element is: " << arr[top] << "\n" << endl;
    return arr[top];
}

void push(int arr[], int value, int &top){
    if (top == CAPACITY - 1) {
        cout << "Stack overflow\n";
        return;
    }
    arr[++top] = value;
}

void pop(int &top){
    if(top == -1){
        cout << "There are no elements to pop out\n" << endl;
        return;
    }
    top -= 1;
}

void length(int &top){
    cout << "Size of array is: " << top + 1 << "\n" << endl;
}


int main(){

    int arr[CAPACITY], top = -1;

    while(true){
        int choice;
        cout << "Enter your choice: " << endl;
        cout << "0. End the print the stack \n 1. Push new element \n 2. Pop element \n 3. Print the topmost element \n 4. Print length of stack" << endl;
        cin >> choice;
        switch(choice){
        case 1: {
            int value;
            cout << "Enter value you want to push: " << endl;
            cin >> value;
            push(arr, value, top);
            break;
        }

        case 2:
            pop(top);
            break;

        case 3:
            print_top(arr, top);
            break;

        case 4:
            length(top);
            break;

        case 0: {
            cout << "\nStack contents (bottom → top): ";
            for (int i = 0; i <= top; ++i) cout << arr[i] << ' ';
            cout << '\n';
            return 0;                // terminate cleanly
        }

        default:
            cout << "Invalid choice\n";
        }
    }
    return 0;
}