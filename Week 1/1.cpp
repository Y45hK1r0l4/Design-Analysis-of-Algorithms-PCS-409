#include<iostream>
using namespace std;
void linearsearch(int arr[],int n,int key){
      int comparisons = 0;
  
      for(int i=0;i<n;i++){
        comparisons++;
        if(arr[i]==key){
            cout<<key<<" is present";
            return;
        }
    }
        cout<<key<< " not present";
      return ;
}
int main(){
    int n;
    cout<<"enter the size of array";
    cin>>n;
    int arr[n];
    cout<<"enter the element of the array";
    for(int i=0;i<n;i++){
                cin>>arr[i];
    }
    int key;
    cout<<"enter the key you want to search";
     cin>>key;
    linearsearch(arr,n,key);
}
