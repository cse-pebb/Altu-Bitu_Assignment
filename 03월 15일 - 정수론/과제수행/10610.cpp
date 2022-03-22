﻿#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//30의 배수인 경우 가장 큰 30의 배수를 찾아서 return하는 함수 
int findGreat30(vector<int>& v) {
	//내림차순으로 정렬하면 최댓값 찾을 수 있음. 맨 뒤는 항상 0
	sort(v.begin(), v.end(), greater<>()); //내림차순 정렬 

	//v에는 각 자릿수가 저장되어있으므로 이를 합쳐서 하나의 숫자로 만들기
	int answer = 0;
	for (int i = 0; i < v.size(); i++) {
		answer += v[i] * pow(10, v.size() - i - 1);
	}
	return answer; //가장 큰 30의 배수 반환 
}

//30의 배수가 되기 위한 조건 2개를 확인해주는 함수 
int is30(vector<int>& v) {
	//30의 배수X -> return -1
	//1. 각 자릿수의 합이 3의 배수가 아닌 경우(3의 배수 조건) 
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += v[i]; //각 자릿수의 합
	}
	if (sum % 3 != 0) return -1; //합이 3의 배수가 아닐 경우 return -1

	//2. 각 자릿수의 숫자들 중 적어도 1개가 0이면(10의 배수 조건) 30의 배수 존재 
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 0) return findGreat30(v); //만들 수 있는 가장 큰 30의 배수 return 	
	}
	return -1; //0이 하나도 없을 경우 return -1
}

int main() {
	string n; //각 자릿수를 나누기 위해 문자열로 받기 
	cin >> n;

	vector<int> v; //문자열을 각 자릿수로 나누고 정수형으로 변환하여 저장할 vector
	for (int i = 0; i < n.length(); i++) {
		int temp = n[i] - '0'; //각 자릿수로 나누고 정수형으로 형 변환 
		v.push_back(temp); 	// v에 각자리수 저장
	}

	cout << is30(v);
}
