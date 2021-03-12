#include <stdio.h>

int rank[12];//high of tree

//부모 노드를 찾는 함수
int FindParent(int parent[], int x){
	if(parent[x] == x) return x;
	return parent[x] = FindParent(parent, parent[x]);
}
//두 부모 노드를 합치는 함수
void unionParent(int parent[], int a, int b){
	a = FindParent(parent, a);
	b = FindParent(parent, b);
	
	if( a == b)
		return;

	if(rank[a] < rank[b]){
		parent[a] = b;
	}
	else{
		parent[b] = a;
	}

	if(rank[a] == rank[b]){//높이가 같다면 +1
		rank[a]++;
	}
	/*
	if(a < b) parent[b] = a;
	else parent[a] = b;//a의 부모값 b
	*/
}

//같은 부모를 가지는지 확인(같은 그래프인지)
int SameParent(int parent[], int a, int b){
	a = FindParent(parent, a);
	b = FindParent(parent, b);
	if(a == b) return 1;
	return 0;
}

int main(void){
	int parent[11];
	for(int i = 1; i <= 10; i++){
		parent[i] = i;
		rank[i]=0;
	}
	unionParent(parent, 1, 2);
	unionParent(parent, 2, 3);
	unionParent(parent, 3, 4);
	unionParent(parent, 5, 6);
	unionParent(parent, 6, 7);
	unionParent(parent, 7, 8);
	printf(" 1과 5는 연결되어 있나요??  %d\n", SameParent(parent, 1, 5));
	unionParent(parent,1,5);
	printf(" 1과 5는 연결되어 있나요??  %d\n", SameParent(parent, 1, 5));
	return 0;
}
