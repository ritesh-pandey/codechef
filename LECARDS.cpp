#include <iostream>
#include <vector>
#include <cstdio>

#define MOD 1000000007

using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int N;
		scanf("%d", &N);
		int C;
//		for(int i=0; i<N; i++)
//			scanf("%d", &C);
		if(N&1){
			long int subset = 1;
			for(int i=1; i<N; i++){
				subset = subset<<1;
				subset %= MOD;
			}
			printf("%ld\n", subset);
		}
		else{
			long int subset = 1;
			for(int i=1; i<N; i++){
				subset = subset<<1;
				subset %= MOD;
			}
			cout<<subset<<" ";
			int half = N/2;
			long long int mid = 1;
			for(int i=0; i<half; i++){
				mid = (((mid)*(N-i))/(i+1));
				//mid %= MOD;
				cout<<N-i<<" "<<mid<<" "<<i+1<<"\n";
			}
			cout<<mid<<"\n";
			mid = mid/2;
			mid = mid%MOD;
			//cout<<"mid/2: "<<mid<<"\n";
			long long int m = subset-mid;
			if(m < 0)
				m = MOD+m;
			else
				m = m%MOD;
			printf("%lld\n",m);
		}
	}
	return 0;
}

