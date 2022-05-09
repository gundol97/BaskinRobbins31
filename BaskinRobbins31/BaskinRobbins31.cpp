#include <iostream>
#include <queue>
#include <string>

std::queue <int> List;
bool Check;
void Make31() {
	for (int i = 0; i < 31; i++) {
		List.push(i + 1);
	}
}

int GetN() {
	std::string S;
	int X;
	while (true) {
		std::cin >> S;
		if (S.length() != 1) std::cout << "다시 입력하세요 (1~3 사이의 숫자)" << "\n";
		else if (std::stoi(S) <= 0 || std::stoi(S) > 3) std::cout << "다시 입력하세요 (1~3 사이의 숫자)" << "\n";
		else {
			X = std::stoi(S);
			break;
		}
	}
	return X;
}

bool UserTurn(int N) {
	Check = true;
	std::cout << "당신이 입력한 숫자 : ";
	for (int i = 0; i < N; i++) {
		std::cout << List.front() << " ";
		if (List.front() == 31) {
			std::cout << "당신의 패배입니다!";
			Check = false;
			break;
		}
		else {
			List.pop();
		}
	}
	std::cout << "\n";
	return Check;
}

bool ComputerTurn() {
	std::cout << "컴퓨터가 입력한 숫자 : ";
	Check = true;
	for (int i = 0; i < 3; i++) {
		std::cout << List.front() << " ";
		if (List.front() == 31) {
			std::cout << "당신의 승리입니다.";
			Check = false;
			break;
		}
		else if (List.front() % 4 == 2) {
			List.pop();
			break;
		}
		else List.pop();
	}
	std::cout << "\n";
	return Check;
}
void PlayTheGameUserFirst() {
	int N;
	Check = true;
	Make31();
	while (Check) {
		std::cout << "1~3 사이의 숫자를 입력하세요" << "\n";
		N = GetN();
		if (!UserTurn(N)) break;
		if (!ComputerTurn()) break;
	}
}

void PlayTheGameComputerFirst() {
	int N;
	Check = true;
	Make31();
	while (Check) {
		std::cout << "1~3 사이의 숫자를 입력하세요" << "\n";
		if (!ComputerTurn()) break;
		N = GetN();
		if (!UserTurn(N)) break;
	}
}

int main() {
	std::cout << "(선공/후공)을 선택하세요" << "\n";
	std::string Choice;
	std::cin >> Choice;
	while (true) {
		if (Choice == "선공") {
			PlayTheGameUserFirst();
			return 0;
		}
		else if (Choice == "후공") {
			PlayTheGameComputerFirst();
			return 0;
		}
		else {
			std::cout << "다시 입력하세요 (선공 / 후공)" << "\n";
			std::cin >> Choice;
		}
	}
}