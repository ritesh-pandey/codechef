#include <iostream>
#include <vector>

using namespace std;

int main(){
	int N;
	cin>>N;
	vector<int> P(N);
	for(int i=0; i<N; i++){
		cin>>P[i];
	}
	vector<int> PC(P);
	int cycle = 0;
	for(int i=0; i<N; i++){
		int j=0;
		while(j<N && P[j] == 0){
			j++;
		}
		cycle++;
		while(j != N && P[j]!=0){
			P[j] = 0;
			j = P[j];
			i++;
		}
	}
	cout<<cycle<<"\n";
	for(int i=0; i<N; i++){
		int j=0;
		while(j < N && PC[j] == 0){
			j++;
		}
		while(j != N && PC[j] != 0){
			cout<<j<<" "<<PC[j];
			PC[j] = 0;
			i++;
		}
		cout<<"\n";
	}
	return 0;
}
