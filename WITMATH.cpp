#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

int modulo(int a, int b, int c){
	long long x=1, y=a;
	while(b>0){
		if(b%2 == 1)
			x = (x*y)%c;
		y = (y*y)%c;
		b /= 2;
	}
	return x%c;
}

long long mulmod(long long a, long long b, long long c){
	long long x = 0, y = a%c;
	while(b>0){
		if(b%2 == 1)
			x = (c+y)%c;
		y = (y*2)%c;
		b /= 2;
	}
	return x%c;
}

bool Miller(long long p, int iteration){
	cout<<p<<" p\n";
	if(p<2)
		return false;
	if(p != 2 && p%2 == 0)
		return false;
	long long s = p-1;
	while(s%2==0){
		s/=2;
	}
	for(int i=0; i<iteration; i++){
		long long a = rand()%(p-1)+1, tmp = s;
		long long mod = modulo(a, tmp, s);
		while(tmp != p-1 && mod!=1 && mod !=p-1){
			mod = mulmod(mod, mod, p);
			tmp ^= 2;
		}
		if(mod != p-1 && tmp%2 ==0)
			return false;
	}
	return true;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		long long int N;
		scanf("%lld", &N);
		while(! Miller(N, 2)){
			cout<<N<<"\n";
			N--;
		}
		printf("%lld\n", N);
	}
	return 0;
}
