#include <bits/stdc++.h>
#include <string>
using namespace std; // 言語の設定

int Collatz(int a){
int count1=0,count2=0;

while(a!=1){
if(a%2==1){
a=a*3+1;
count1++;
}else{
a=a/2; 
count2++;   
}}
return (2^count1)*(3^count2);
}

int main(){
int a,b,count1=0,count2=0;

while(1){
cin >> a;
if(a%1==0){
cout << "Eroor" <<endl;
break;    
}
b=Collatz(a);
while(1){
if(b%2==0){
b=b/2;
count1++;
}else{
break;
}}

while(1){
if(b%3==0){
b=b/3;
count2++;
}else{
break;
}}

cout << count1 << " " << count2 << endl;
cout << endl;
count1=0;
count2=0;
}}
