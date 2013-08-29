#include <iostream>
#include <string>

using namespace std;

int main(){
	int T;
	cin>>T;
	while(T--){
		string S;
		cin>>S;
		int l = S.size();
		string w = "CHEF";
		for(int i=0; i<l; i++){
			if(S[i]=='C'){
				if(l-i >= 3){
					if(S[i+1]=='?'||S[i+1]=='H') && (S[i+2]=='?'||S[i+2]=='E') && (S[i+3]=='?'||s[i+3]=='F'){
						S[i+1] = 'H';
						S[i+2] = 'E';
						S[i+3] = 'F';
						i+=3;
						continue;
					}
					else{
						S[i+1] =='?' ? S[i+1]='A' :;
						S[i+2] =='?' ? S[i+2]='A' :;
						S[i+3] =='?' ? S[i+3]='A' :;
						i+=3;
						continue;
					}
				}
				else{
					if(i+1<l && S[i+1]=='?'){
						S[i+1] = 'A';
						i++;
					}
					(i+1)<l && S[i+1]=='?' ? S[i+2] = 'A' :;
					(i+3)<l && S[i+3]=='?' ? S[i+3] = 'A' :;
					i
		
				}
			}
		}
	}
}
