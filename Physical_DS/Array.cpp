#include <iostream>

using namespace std;

class Array{
    private:
        int size;
        int length;
        int*arr;


    public:
        // Constructor to initialize the array
        Array(int arr_size){
            size = arr_size;
            length = 0;
            arr = new int[arr_size];
        }

        // Function to fill the array with user input
        void Fill(){
            int no_of_elements;
            cout<<"Enter the number ofelements of the array: ";
            cin>>no_of_elements;
            if(no_of_elements>size){
                cout<<"The number of elements exceeds the size of the array."<<endl;
                return;
            }
            cout<<"Enter the elements of the array: ";
            for(int i=0; i<no_of_elements; i++){
                cout<<"Element "<<i+1<<": ";
                cin>>arr[i];
            }
            length = no_of_elements;
        }

        // Function to display the elements of the array
        void Display(){
            cout<<"The elements of the array are: ";
            for(int i=0; i<length; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        // Function to get the size of the array
        int GetSize(){
            return size;
        }
        // Function to get the length of the array
        int GetLength(){
            return length;
        }

        // Function to search for an element in the array
        int search(int key){
            for(int i=0; i<length; i++){
                if(arr[i]==key){
                    return i;
                    break;
                }
            }
            return -1;
        }

        // Function to append an element at the end of the array
        void append(int key){
            if(length<size){
                arr[length]=key;
                length++;
            }
            else{
                cout<<"The array is full. Cannot append the element."<<endl;
            }
        }

        // Function to insert an element at a specific index in the array
        void insert(int index, int key){
            if(index<0 || index>length){
                cout<<"Invalid index. Cannot insert the element."<<endl;
                return;
            }
            if(length==size){
                cout<<"The array is full. Cannot insert the element."<<endl;
                return;
            }
            for(int i=length; i>index; i--){
                arr[i]=arr[i-1];
            }
            arr[index]=key;
            length++;
        }

        // Function to delete an element at a specific index in the array
        void Delete(int index){
            if(index<0 || index>=length){
                cout<<"Invalid index. Cannot delete the element."<<endl;
                return;
            }
            for(int i=index; i<length-1; i++){
                arr[i]=arr[i+1];
            }
            length--;
        }


        // Function to delete an element by value in the array
        void delete_by_value(int key){
            int index = search(key);
            if(index==-1){
                cout<<"Element not found in the array."<<endl;
                return;
            }
            Delete(index);
        }



        // Function to enlarge the size of the array
        void enlarge(int new_size){
            if(new_size<=size){
                cout<<"New size must be greater than the current size."<<endl;
                return;
            }
            else{
                int* new_arr = new int[new_size];
                for(int i=0; i<length; i++){
                    new_arr[i]=arr[i];
                }
                delete[] arr;
                arr = new_arr;
                size = new_size;
            }
        }

        // Function to merge two arrays
        void merge(Array arr2){
            int new_size = size + arr2.GetSize();
            int* new_arr = new int[new_size];
            for(int i=0; i<length; i++){
                new_arr[i]=arr[i];
            }
            for(int i=0; i<arr2.GetLength(); i++){
                new_arr[length+i]=arr2.arr[i];
            }
            delete[] arr;
            arr = new_arr;
            size = new_size;
            length += arr2.GetLength();
        }

        // Destructor to free the memory allocated for the array
        ~Array(){
            delete[] arr;
        }


    };


    
    int main() {
    cout << "--- Initializing Array (Size 5) ---" << endl;
    Array myArr(5);

    // 1. Test Fill
    myArr.Fill(); 
    myArr.Display();
    cout << "Current Length: " << myArr.GetLength() << ", Capacity: " << myArr.GetSize() << endl << endl;

    // 2. Test Search
    int key = 20;
    cout << "--- Testing Search ---" << endl;
    int pos = myArr.search(key);
    if (pos != -1)
        cout << "Found " << key << " at index " << pos << endl;
    else
        cout << key << " not found." << endl << endl;

    // 3. Test Append
    cout << "--- Testing Append (Adding 100) ---" << endl;
    myArr.append(100);
    myArr.Display();
    cout << endl;

    // 4. Test Insert (at index 1)
    cout << "--- Testing Insert (Value 55 at Index 1) ---" << endl;
    myArr.insert(1, 55);
    myArr.Display();
    cout << endl;

    // 5. Test Delete by Index
    cout << "--- Testing Delete (Index 0) ---" << endl;
    myArr.Delete(0);
    myArr.Display();
    cout << endl;

    // 6. Test Delete by Value
    cout << "--- Testing Delete by Value (100) ---" << endl;
    myArr.delete_by_value(100);
    myArr.Display();
    cout << endl;

    // 7. Test Enlarge
    cout << "--- Testing Enlarge (New Size 10) ---" << endl;
    myArr.enlarge(10);
    cout << "New Size: " << myArr.GetSize() << endl;
    myArr.append(999);
    myArr.Display();
    cout << endl;

    // 8. Test Merge
    cout << "--- Testing Merge with another Array ---" << endl;
    Array otherArr(3);
    otherArr.append(1);
    otherArr.append(2);
    
    cout << "Merging with: ";
    otherArr.Display();
    
    myArr.merge(otherArr);
    cout << "Final Merged Array: ";
    myArr.Display();
    cout << "Final Length: " << myArr.GetLength() << endl;

    return 0;
}