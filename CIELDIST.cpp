#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main(){
	int T;
	cin>>T;
	while(T--){
		int DS,DT,D,diff;
		cin>>DS>>DT>>D;
		if(DS>=DT)
			diff = DS-DT;
		else
			diff = DT-DS;

		if(D > DS+DT){
			cout<<(D-DS-DT)<<".00\n";
		}
		else if(D == DS+DT || (diff<=D && (DS+DT)>=D)){
			cout<<"0.00\n";
		}
		else{
			cout<<(diff)<<".000\n";
		}
	}
	return 0;
}
