#include <bits/stdc++.h>
#include <string>
using namespace std; // 言語の設定

int main(){
int a,count1=0,count2=0;
cin >> a;

while(a!=1){
if(a%2==1){
a=a*3+1;
count1++;
}else{
a=a/2; 
count2++;   
}}
cout << count1 << " " << count2 << endl;
}