//
//  main.cpp
//  Taller7OtraVez
//
//  Created by Juanita Gomez on 4/10/19.
//  Copyright © 2019 Juanita Gomez. All rights reserved.
//

#include <iostream>
#include <set>
#include <vector>
using namespace std;

// 1
int Pow_k(int n, int k){
    if (k==0) return 1;
    else if(k>=1) return (n*Pow_k(n,k-1));
    else return -1;
}

// 3
string swap(string str){
    if (str.length() ==0) return "";
    else if (str.length() ==1) return str;
    else{
        return(str[str.length()] + swap(str.substr(1, str.length()))+str[0]);
        
    }
}

// 4

bool pal(string str){
    if (str.length() ==0) return false;
    else if (str.length() ==1) return true;
    else if(str[0] != str[str.length()-1]) return false;
    else return pal(str.substr(1, str.length()-2));
}

// 5

int Pascal(int n, int k){
    if(k==0 || n==0 || k==n) return 1;
    else return(Pascal(n-1,k)+Pascal(n-1,k-1));
            
}

// 6

void print_num(int n){
    if (n<10) cout<<n;
    else{
        int val= n/10;
        cout<<val;
        print_num(n%10);
    }
}

// 7

// 8

void to_binary(int n){
    if(n == 0) cout<<0;
    else if (n==1) cout<<1;
    else if(n<0) {
        cout<<"-";
        to_binary(-n);
    }
    else {
        int res = n%2;
        int val = n/2;
        to_binary(val);
        cout<<res;
    }
        
}

// 9

vector<int> join(vector<int> a, vector<int> b){
    vector<int> c;
    if((a.size()==0) && (b.size()==0)) return c;
    else if(a.size()==0){
        c.push_back(b[0]);
        b.erase(b.begin());
        vector<int> temp = join(a,b);
        temp.insert(temp.begin(),b[0]);
        return temp;
    }
    else if(b.size()==0){
        c.push_back(a[0]);
        a.erase(a.begin());
        vector<int> temp = join(a,b);
        temp.insert(temp.begin(),a[0]);
        return temp;
    }
    else{
        if (a[0]<b[0]){
            c.push_back(a[0]);
            a.erase(a.begin());
        }
        else {
            if(b[0]<=a[0]){
                c.push_back(b[0]);
                b.erase(b.begin());
            }
        }
        vector<int> temp = join(a,b);
        temp.insert(temp.begin(), c[0]);
        return temp;
    }
}

// 10

bool SubSum(set<int> a, int n){
    if(a.empty()) return (n == 0);
    else{
        int first = *(a.begin());
        a.erase(a.begin());
        return (SubSum(a, n-first)) || (SubSum(a,n)) ;
    }
}

// 10 mod

int SubSum2(set<int> a, int n){
    if(a.empty()) return 1;
    else{
        int first = *(a.begin());
        a.erase(a.begin());
        return ((SubSum2(a, n-first)) + (SubSum2(a,n)));
    }
}

//----------------------------------//-------------------------------------//
int main() {
    cout<<Pow_k(9,3)<<endl;
    cout<<swap("Juanita")<<endl;
    cout<<pal("ala")<<endl;
    cout<<Pascal(13,6)<<endl;
    print_num(1203);
    cout<<endl;
//    set<string> res = GenPen("BUS");
//    set<string>::iterator it;
//    for (it = res.begin(); it != res.end(); it++) cout << *it << endl;
    to_binary(-10);
    cout<<endl;
    vector<int> a;
    a.push_back(1);
    a.push_back(7);
    a.push_back(8);
    a.push_back(11);
    a.push_back(13);
    vector<int> b;
    b.push_back(1);
    b.push_back(4);
    b.push_back(6);
    b.push_back(8);
    b.push_back(13);
    vector<int> c;
    vector<int> d = join(a,b);
    for(int i=0; i<d.size(); i++) cout<<d[i]<<" ";
    cout<<endl;
    ///
    set<int> s = {-1,2,4,6,9};
    cout<<SubSum(s,8) <<endl;
    cout<<SubSum(s,8) <<endl;
    return 0;
}
    



