#include <iostream>
#include <algorithm>
#include <queue>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main() {
	int N;
	scanf("%d", &N);
	queue <int> q;
	int k=0;
	int answer[10000];
	for (int i = 0; i < N; i++) {
		char command[6]={'\0',};
		int num;
		
		scanf("%s", command);
		if (!strcmp(command, "push")) {
			scanf("%d",&num);
			q.push(num);
		}
		else if (!strcmp(command, "pop")) {
			if (q.empty()) {
				answer[k]=-1;
				k++;
			}
			else {
				answer[k]=q.front();
				k++;
				q.pop();
			}
		}
		else if (!strcmp(command, "size")) {
			answer[k]=q.size();
			k++;
		}
		else if (!strcmp(command, "empty")) {
			if (q.empty()){
				answer[k]=1;
				k++;
			}
			else {
				answer[k]=0;
				k++;
			}
		}
		else if (!strcmp(command, "front")) {
			if(q.empty()){
				answer[k]=-1;
				k++;
			}
			else{
				answer[k]=q.front();
				k++;
			}
			
		}
		else if (!strcmp(command, "back")) {
			if(q.empty()){
				answer[k]=-1;
				k++;
			}
			else{
				answer[k]=q.back();
				k++;
			}
		}
	}
	for(int j=0; j<k; j++){
		printf("%d\n",answer[j]);
	}
}
