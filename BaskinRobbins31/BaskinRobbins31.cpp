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
		if (S.length() != 1) std::cout << "�ٽ� �Է��ϼ��� (1~3 ������ ����)" << "\n";
		else if (std::stoi(S) <= 0 || std::stoi(S) > 3) std::cout << "�ٽ� �Է��ϼ��� (1~3 ������ ����)" << "\n";
		else {
			X = std::stoi(S);
			break;
		}
	}
	return X;
}

bool UserTurn(int N) {
	Check = true;
	std::cout << "����� �Է��� ���� : ";
	for (int i = 0; i < N; i++) {
		std::cout << List.front() << " ";
		if (List.front() == 31) {
			std::cout << "����� �й��Դϴ�!";
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
	std::cout << "��ǻ�Ͱ� �Է��� ���� : ";
	Check = true;
	for (int i = 0; i < 3; i++) {
		std::cout << List.front() << " ";
		if (List.front() == 31) {
			std::cout << "����� �¸��Դϴ�.";
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
		std::cout << "1~3 ������ ���ڸ� �Է��ϼ���" << "\n";
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
		std::cout << "1~3 ������ ���ڸ� �Է��ϼ���" << "\n";
		if (!ComputerTurn()) break;
		N = GetN();
		if (!UserTurn(N)) break;
	}
}

int main() {
	std::cout << "(����/�İ�)�� �����ϼ���" << "\n";
	std::string Choice;
	std::cin >> Choice;
	while (true) {
		if (Choice == "����") {
			PlayTheGameUserFirst();
			return 0;
		}
		else if (Choice == "�İ�") {
			PlayTheGameComputerFirst();
			return 0;
		}
		else {
			std::cout << "�ٽ� �Է��ϼ��� (���� / �İ�)" << "\n";
			std::cin >> Choice;
		}
	}
}