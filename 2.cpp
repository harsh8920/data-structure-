#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string ispalindrome(string S){
    for(int i=0; i<S.length()/2;i++){
        if(S[i]!=S[S.length()-i-1]){
            return "NO";

        }
    }
    return "Yes";
}




int main(){
//     int n,c,r;
//     cout<<"enter no:"<<endl;
//     cin>>n;
//      c=n;
// int s=0;
//     while(n>0){
//          r=n%10;
        
//         s=s*10+r;
//         n=n/10;
//     }
//     if(c==s){
//         cout<<"no is palindrome";
//     }
//     else {
//         cout<<" not palindrome";

//     }

string S ="ABCDCBA";
cout <<ispalindrome(S);
return 0;
}
