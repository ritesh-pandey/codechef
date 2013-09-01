#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		unsigned long long int N, K;
		scanf("%llu %llu", &N, &K);
		if(N==0 && K==0)
			printf("0 0\n");
		else if(N>0 && K>0){
			printf("%llu %llu\n", N/K, N%K);
		}
		else{
			if(N == 0){
				printf("0 0\n");
			}
			if(K == 0)
				printf("0 %llu\n", K);
		}
	}
	return 0;
}
