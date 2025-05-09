#include <iostream>
using namespace std;

void findMaxOccurance(int n){
 //   vector<int> freq(26, 0); // Frequency array for 26 lowercase alphabets

    int freq[26] = {0};
    char ch;

    for(int i = 0; i < n; i++){
        cin >> ch;
        freq[ch - 'a']++;
    }

    int maxCount = 0;
    char maxChar = '\0';

    for(int i = 0; i < 26; i++){
        if(freq[i] > maxCount){
            maxCount = freq[i];
            maxChar = 'a' + i;
        }
    }

    if(maxCount == 1){
        cout << "No Duplicates Present";
    }else{
        cout << maxChar << " " << maxCount << endl;
    }
}


int main(){
    int T; 

    cout << "Enter the test cases: ";
    cin >> T;

    cout << "Enter size: ";
    while(T--){
        int n; 
        cin >> n;
        findMaxOccurance(n);
    }
}
