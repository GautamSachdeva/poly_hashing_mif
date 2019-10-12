#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include<bits/stdc++.h>

using namespace std;

long long poly_hash(string name,int buckets){
	long long x = 263;
	long long p = 1000000007;
	long long hash = 0;
	for(int i = 0 ; i < name.size() ; i++){
		hash = hash + (int)name[i]*pow(x,i);
	}
	hash = hash%p;
	return hash%buckets;
}

struct query{
	string type,str;
	int ind;
};


int main(){
	vector<query> mif;
	int buckets,n;
	cin>>buckets;
	cin>>n;
	list<string> hash_table[buckets];
	mif.resize(n);
	for(int i = 0 ; i < n ; i++){
		cin >> mif[i].type;
		if(mif[i].type == "check"){
			cin >> mif[i].ind;
			
		}
		else{
			cin >> mif[i].str;
		}
	}
	for(int i = 0 ; i < n ; i++){
		if(mif[i].type == "add"){
			int m = poly_hash(mif[i].str,buckets);
			if(hash_table[m].empty()){
				hash_table[m].push_front(mif[i].str);
			}
			else{
				if(hash_table[m].end() == find(hash_table[m].begin(),hash_table[m].end(),mif[i].str)){
					hash_table[m].push_front(mif[i].str);
				}
			}
		}
		else if(mif[i].type == "find"){
			int m = poly_hash(mif[i].str,buckets);
			if(hash_table[m].end() == find(hash_table[m].begin(),hash_table[m].end(),mif[i].str)){
				cout << "no";
			}
			else{
				cout << "yes";
			}
			cout << endl;
		}
		else if(mif[i].type == "del"){
			int m = poly_hash(mif[i].str,buckets);
			list<string>::iterator it = find(hash_table[m].begin(),hash_table[m].end(),mif[i].str);
			if(it != hash_table[m].end()){
				hash_table[m].erase(it);
			}
			else{
				;
			}
		}
		else if(mif[i].type == "check"){
			if(hash_table[mif[i].ind].empty()){
				cout << endl;
			}
			else{
				list<string>::iterator it;
				bool flag = true;
				for(it = hash_table[mif[i].ind].begin(); it != hash_table[mif[i].ind].end();it++){
					if(flag){
						cout << *it;
						flag = false;
					}
					else{
						cout << " " << *it;
					}
				}
				cout << endl;
			}
		}
	}
}
