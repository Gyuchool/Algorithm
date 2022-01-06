#include<iostream>

using namespace std;

int main(){
	char arr[8][8];
	int count = 0;

	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if (i + j == 2||i+j==0||i+j==4||i+j==6||i+j==8||i+j==10||i+j==12||i+j==14){
				if (arr[i][j] == 'F'){
					count++;
				}
			
			}

		}
	}

	cout << count << endl;

}
