#include<iostream>
using namespace std ;
void Display(int a[],int n);
// For Bubble sorting
void BubbleSort (int arr[],int n){
    for (int i = 0; i < (n-1); i++)  //also write 'n' but waste one step of time
    {
        bool flag = false;  //More Optimized code
        for (int j = 0; j < (n-1)-i; j++)  //Optimized Code use 5-i
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = true; 
            }
        }
        if(flag == false) break;
    }
}

int main(){
    int arr[] = {5,2,4,8,4,1,4,1,5,7,3,2,5,43,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    BubbleSort(arr,n);
    Display(arr,n);

    return 0 ;
}

// For displaying Data
void Display(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] ;
    }
}

// Bubble Sort But not much optimize code
// void BubbleSort (int arr[]){
//     for (int i = 0; i < 6; i++)
//     {
//         for (int j = 0; j < 5; j++)
//         {
//             if (arr[j] > arr[j+1])
//             {
//                 int temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//             }
//             cout << "HAMZA"<< endl;
//         }
//     }
// }

// void BubbleSort (int arr[]){
//     for (int i = 0; i < 6; i++)
//     {
//         for (int j = 0; j < 5-i; j++)  //Optimized Code use 5-i
//         {
//             if (arr[j] > arr[j+1])
//             {
//                 int temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//             }
//         }
//     }
// }
