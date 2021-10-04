#include <iostream>
#include <string>
#include <vector>
#include<iostream>

using namespace std;
int currentWeight;
vector<pair<int, int>> carsInBridge; // 다리위에 있는 차들의 무게와 시간

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;
    for (int i = 0; i < truck_weights.size(); i++) {
        if (!carsInBridge.empty() && carsInBridge[0].second >= bridge_length) { // 다리끝 도착
            currentWeight -= carsInBridge[0].first; //다리 무게 감소
            carsInBridge.erase(carsInBridge.begin()); // 탈출
        }
        if (currentWeight + truck_weights[i] <= weight && carsInBridge.size() + 1 <= bridge_length) { //올라갈수 있다면
            for (int j = 0; j < carsInBridge.size(); j++) {
                carsInBridge[j].second++; // 시간 1초 씩 증가
            }
            carsInBridge.push_back({ truck_weights[i], 1 });
            currentWeight += truck_weights[i];
            answer++;

            continue;
        }
        else {
            for (int j = 0; j < carsInBridge.size(); j++) {
                carsInBridge[j].second++; // 시간 1초 씩 증가
            }
            i--;
            answer++;
        }

    }
    if (carsInBridge.size() > 0) {
        answer += (bridge_length - carsInBridge[carsInBridge.size() - 1].second);
    }
    return answer;
}
