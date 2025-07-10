#include <bits/stdc++.h>
using namespace std;

const int CAPACITY = 10;

void push(int arr[], int &curr_size, int &start, int &end, int value){
    if((end + 1) % CAPACITY == start){
        cout << "Queue Overflow\n" << endl;
    }
    if(start == -1){
        start = 0;
    }
    end = (end + 1) % CAPACITY;
    arr[end] = value;
    curr_size++;
}

void pop(int arr[], int &start, int &end, int &curr_size){
    if(start == -1){
        cout << "Queue Underflow\n" << endl;
    }
    if(start == end){
        start = end = -1;
    }
    else{
        start = (start + 1) % CAPACITY;
    }
    curr_size -= 1;
}

void print_top(int arr[], int &start){
    if(start == -1){
        cout << "There are no elements in queue\n" << endl;
    }
    cout << "Top element is: " << arr[start] << "\n" << endl;
}

void length_of_queue(int &curr_size){
    cout << "Size of array is: " << curr_size << "\n" << endl;
}

int main(){
    int arr[CAPACITY], curr_size = 0, end = -1, start = -1;

    while(true){
        int choice;
        cout << "Enter your choice: " << endl;
        cout << "0. End and the print the queue \n 1. Push new element \n 2. Pop element \n 3. Print the topmost element \n 4. Print length of queue" << endl;
        cin >> choice;
        switch(choice){
        case 1: {
            int value;
            cout << "Enter value you want to push: " << endl;
            cin >> value;
            push(arr, curr_size, start, end, value);
            break;
        }

        case 2:
            pop(arr, start, end, curr_size);
            break;

        case 3:
            print_top(arr, start);
            break;

        case 4:
            length_of_queue(curr_size);
            break;

        case 0: {
            if(start == -1){
                cout << "Queue is empty\n" << endl;
            }
            else{
                cout << "Queue contents (front -> rear): ";
                int i = start;
                while(true){
                    cout << arr[i] << " ";
                    if(i == end) break;
                    i = (i + 1) % CAPACITY;
                }
                cout << '\n';
            }
            return 0;
        }

        default:
            cout << "Invalid choice\n";
        }
    }
}
