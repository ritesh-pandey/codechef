#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	vector<long int> dollar(1000,0);
	dollar[0] = 0;
	for(int i=1; i<dollar.size(); i++){
		dollar[i] = max(i, dollar[i/2]+dollar[i/3]+dollar[i/4]);
	}
	cout<<dollar[12];
	/*
	int n;
	while(scanf("%d",&n) != EOF){
		
	}*/
	return 0;
}
