#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
int main(){
	int num[10];
	while(cin>>num[0]){
		for(int i = 1; i < 6; i++) cin>>num[i];
		int tmax = num[0];
		int id = 0;
		for(int i = 0; i < 6; i++) if(tmax < num[i]) tmax = num[i],id=i;
		int tsum = num[0] * num[1] + num[2] * num[3] + num[4] * num[5];
		vector< int > key; key.clear();
		if(tmax * tmax == tsum){
			int last = tmax - num[id^1];
			for(int i = 0; i < 6; i += 2){
				if(i/2 != id/2){
					int good = -1;
					if(num[i] == last) good = num[i+1];
					if(num[i+1] == last) good = num[i];
					if(good != -1) key.push_back(good);
				}
			}
			if(key.size() == 2 && (key[0] + key[1] == tmax)){
				char first = 'A'+id/2;
				cout<<tmax<<endl;
				for(int i = 0; i < num[id^1]; i++){
					for(int j = 0; j < tmax; j++)
						printf("%c",first);
					puts("");

				}
				char second = 'A'; int sn = key[0];
				char third = 'B'; int tn = key[1];
				if(first == 'A') second = 'B';
				if(first == 'B' || second == 'B') third = 'C';
				for(int i = 0; i < last; i++){
					for(int j = 0; j < sn; j++) printf("%c",second);
					for(int j = 0; j < tn; j++) printf("%c",third);
					puts("");
				}

			}
			else{
				key.clear();
				for(int i = 0; i < 6; i++){
					if(num[i] != tmax) key.push_back(num[i]);
				}
				if(key.size() == 3){
					cout<<tmax<<endl;
					for(int i = 0; i < 3; i++){
						for(int j = 0; j <key[i]; j++){
							for(int k = 0; k < tmax; k++){
								printf("%c",'A' + i);
							}
							puts("");
						}
					}
				}
				else{
					puts("-1");
				}
			}
		}
		else{
			puts("-1");
		}
	}
	return 0;
}
