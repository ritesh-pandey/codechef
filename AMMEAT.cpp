#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		long long int N,M;
		scanf("%lld %lld",&N,&M);
		vector<long long int> P(N);
		for(long long int i=0; i<N; i++){
			scanf("%lld", &P[i]);
		}
		sort(P.begin(), P.end());
		long long int sum = 0;
		int flag = 0;
		for(long long int i=N-1; i>0; i--){
			sum += P[i];
			if(sum >= M){
				printf("%lld\n", N-i);
				flag = 1;
				break;
			}
		}
		if(flag == 0)
			printf("%d\n", -1);
	}
	return 0;
}
