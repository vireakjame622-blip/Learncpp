#include <iostream>
using namespace std;

// Exercise 2:
// a. Take 10 numbers as input and print them in a reverse order.
// b. Count how many numbers are even in this array.

int main() {
    // ជំហានទី ១: ទទួលទិន្នន័យបញ្ចូលទៅក្នុង Array (Input)
    int n; 
    cout << "Enter the number of elements: ";
    cin >> n; 

    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << (i + 1) << ": ";
        cin >> arr[i];
    }

    // ជំហានទី ២ (ផ្នែក a): បង្ហាញបញ្ច្រាសតាមបែបងាយយល់បំផុត (Countdown Loop)
    cout << "\n--- (a) Array in Reverse Order ---" << endl;
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // ជំហានទី ៣ (ផ្នែក b): រាប់ចំនួនលេខគូ (Count Even Numbers)
    int evenCount = 0; // អថេរសម្រាប់រាប់
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            evenCount++; // បើជាលេខគូ បូកថែម ១
        }
    }
    cout << "\n--- (b) Count Even Numbers ---" << endl;
    cout << "Total even numbers in this array: " << evenCount << endl;

    return 0;
}
