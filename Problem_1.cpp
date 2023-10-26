#include<iostream>
using namespace std;
int main(){
    const int numstudent= 5;
    const int numsubject=5;

    int marks[numstudent][numsubject];
    for(int i=0;i<numstudent;i++){
        cout<<"enter marks for student "<<i+1<<":";
        for(int j=0;j<numsubject;j++){
            cin>>marks[i][j];
        }
    }

    for(int i=0;i<numstudent;i++){
     int total=0;
     for(int j=0;j<numsubject;j++){
        total+=marks[i][j];
     }
     double average= static_cast<double>(total)/numsubject;
     cout<<"total marks for student"<<i+1<<":"<<total<<endl;
     cout<<"average marks for student"<<i+1<<":"<<average<<endl;
    
    }

    return 0;
}
