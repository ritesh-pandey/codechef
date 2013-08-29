#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <queue>
#include <cmath>

#define PREPRIME 10000000

using namespace std;

int main(){
	vector<long long int> prime(PREPRIME, 1);
	vector<long long int> primePass;
	long long int count = 1;
	for(long long int i=2; i<=3162; i++){
		if(prime[i] > 0){
			prime[i] = count;
			count++;
			primePass.push_back(i);
			for(long long int j=i+i; j<PREPRIME; j+=i)
				prime[j] = 0;
		}
	}
	for(long long int i=3163; i<PREPRIME; i++){
		if(prime[i] > 0){
			prime[i] = count;
			count++;
		}
	}
	int T;
	scanf("%d", &T);
	prime[0] = 0;
	prime[1] = 0;
	while(T--){
		int N;
		scanf("%d",&N);
		vector< vector<long long int> > server(N, vector<long long int>(N));
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				scanf("%lld",&server[i][j]);
			}
		}
		long long int unsuccess = 0;
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if(server[i][j] == -1)
					continue;
				else if(prime[server[i][j]] >= 1){
					unsuccess = unsuccess + prime[server[i][j]] - 1;
					continue;
				}
				else if(server[i][j]%2 == 0){
					unsuccess = unsuccess + server[i][j]/2;
					queue<int> hackX;
					queue<int> hackY;
					hackX.push(i);
					hackY.push(j);
					while(!hackX.empty()){
						if(hackY.front() > 0 && server[hackX.front()][hackY.front()-1] != -1 && server[hackX.front()][hackY.front()-1]%2 == 0){
							if(server[hackX.front()][hackY.front()-1] != 2){
								hackX.push(hackX.front());
								hackY.push(hackY.front()-1);
							}
						}
						if(hackX.front() < N-1 && server[hackX.front()+1][hackY.front()] != -1 && server[hackX.front()+1][hackY.front()]%2 == 0){
							if(server[hackX.front()+1][hackY.front()] != 2){
								hackX.push(hackX.front()+1);
								hackY.push(hackY.front());
							}
						}
						if(hackY.front() < N-1 && server[hackX.front()][hackY.front()+1] != -1 && server[hackX.front()][hackY.front()+1]%2 == 0){
							if(server[hackX.front()][hackY.front()+1] != 2){
								hackX.push(hackX.front());
								hackY.push(hackY.front()+1);
							}
                                                }
						if(hackX.front() > 0 && server[hackX.front()-1][hackY.front()] != -1 && server[hackX.front()-1][hackY.front()]%2 == 0){
							if(server[hackX.front()-1][hackY.front()] != 2){
								hackX.push(hackX.front()-1);
								hackY.push(hackY.front());
							}
                                                }
						server[hackX.front()][hackY.front()] = -1;
						hackX.pop();
						hackY.pop();
					}
					continue;
				}
				else if(server[i][j]%2 == 1){
                                        unsuccess = unsuccess + (server[i][j]+1)/2 + 1;
                                        queue<int> hackX;
                                        queue<int> hackY;
                                        hackX.push(i);
                                        hackY.push(j);
                                        while(!hackX.empty()){
                                                if(hackY.front() > 0 && server[hackX.front()][hackY.front()-1] != -1 && server[hackX.front()][hackY.front()-1]%2 == 1){
							if(prime[server[hackX.front()][hackY.front()-1]] == 0){
	                                                        hackX.push(hackX.front());
        	                                                hackY.push(hackY.front()-1);
							}
                                                }
                                                if(hackX.front() < N-1 && server[hackX.front()+1][hackY.front()] != -1 && server[hackX.front()+1][hackY.front()]%2 == 1){
							if(prime[server[hackX.front()+1][hackY.front()]] == 0){
	                                                      	hackX.push(hackX.front()+1);
        	                                                hackY.push(hackY.front());
							}
                                                }
                                                if(hackY.front() < N-1 && server[hackX.front()][hackY.front()+1] != -1 && server[hackX.front()][hackY.front()+1]%2 == 1){
							if(prime[server[hackX.front()][hackY.front()+1]] == 0){
	                                                        hackX.push(hackX.front());
        	                                                hackY.push(hackY.front()+1);
							}
                                                }
                                                if(hackX.front() > 0 && server[hackX.front()-1][hackY.front()] != -1 && server[hackX.front()-1][hackY.front()]%2 == 1){
							if(prime[server[hackX.front()-1][hackY.front()]] == 0){
	                                                        hackX.push(hackX.front()-1);
        	                                                hackY.push(hackY.front());
							}
                                                }
                                                server[hackX.front()][hackY.front()] = -1;
                                                hackX.pop();
                                                hackY.pop();
                                        }
					continue;
                                }
			}
		}
		cout<<unsuccess<<"\n";
	}
	return 0;
}
