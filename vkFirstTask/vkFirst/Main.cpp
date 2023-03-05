#include <iostream>
#include <string>
#include <unordered_map>
#include <regex>

using namespace std;

class TimeToWordConvertingInterface {
public:
	virtual string convert(int hours, int minutes) = 0;
};

class TimeToWordConverter : public TimeToWordConvertingInterface {
public:
	string convert(int hours, int minutes) {
		unordered_map<int, string> hourWords = {
			{1, "��"}, {2, "��"}, {3, "��"}, {4, "������"}, {5, "���"},
			{6, "����"}, {7, "���"}, {8, "���"}, {9, "�����"}, {10, "�����"},
			{11, "����������"}, {12, "���������"}
		};
		unordered_map<int, string> minuteWords = {
			{1, "���� ������"}, {2, "��� ������"}, {3, "��� ������"}, {4, "������ ������"}, {5, "���� �����"},
			{6, "����� �����"}, {7, "���� �����"}, {8, "������ �����"}, {9, "������ �����"}, {10, "������ �����"},
			{11, "����������� �����"}, {12, "���������� �����"}, {13, "���������� �����"}, {14, "������������ �����"},
			{15, "��������"}, {16, "����������� �����"}, {17, "���������� �����"}, {18, "������������ �����"},
			{19, "������������ �����"}, {20, "�������� �����"}, {21, "�������� ���� ������"}, {22, "�������� ��� ������"},
			{23, "�������� ��� ������"}, {24, "�������� ������ ������"}, {25, "�������� ���� �����"}, {26, "�������� ����� �����"},
			{27, "�������� ���� �����"}, {28, "�������� ������ �����"}, {29, "�������� ������ �����"}, {30, "��������"}
		};

		string hour = hourWords[hours];
		string minute = minuteWords[minutes];

		if(minutes == 0) {
			std::string hourWord = hourWords[hours];
			std::regex hourRegex("(��|��|��|������|���|����|���|���|�����|�����|����������|���������)");
			std::regex_replace(hourWord, hourRegex, "$&�");
			if(hours == 1) return hourWord + "�� ���";
			if(hours == 2) return hourWord + "� ����";
			if(hours == 3) return hourWord + "� ����";
			if(hours == 4) return hourWord + "e ����";
			if(hours == 9 || hours == 10 || hours == 11 || hours == 12) return hourWord + "� �����";
			if(hours == 5 || hours == 6 || hours == 7) return hourWord + "� �����";
			if(hours == 8) return hourWord + "��� �����";
		}

		if(minutes == 1 && hours >= 5 && hours <= 12 && hours != 8) return minute + " ����� " + hour + "�";
		if(minutes == 1 && hours == 8) return minute + " ����� " + hour + "���";

		if(minutes >= 1 && minutes < 30 && minutes != 15 && hours < 5) {
			if(hours == 1) return minute + " ����� ����";
			if(hours == 2) return minute + " ����� ����";
			if(hours == 3) return minute + " ����� ����";
			if(hours == 4) return minute + " ����� �������";
			if(hours == 5) return minute + " ����� ����";
		}
		if(minutes == 15) {
			if(hours == 1) return minute + " �������";
			if(hours == 2) return minute + " ��������";
			if(hours == 3) return minute + " ����������";
			if(hours == 4) return minute + " ������";
			if(hours == 5) return minute + " �������";
			if(hours == 6) return minute + " ��������";
			if(hours == 7) return minute + " ��������";
			if(hours == 8) return minute + " ��������";
			if(hours == 9) return minute + " ��������";
			if(hours == 10) return minute + " �������������";
			if(hours == 11) return minute + " ������������";
			if(hours == 12) return minute + " �������";
		}
		if(minutes == 59) {
			if(hours == 0) return minuteWords[60 - minutes] + " �� ����";
			if(hours == 1) return minuteWords[60 - minutes] + " �� ����";
			if(hours == 2) return minuteWords[60 - minutes] + " �� ����";
			if(hours == 3) return minuteWords[60 - minutes] + " �� �������";
			if(hours == 4) return minuteWords[60 - minutes] + " �� ����";
			if(hours == 5) return minuteWords[60 - minutes] + " �� �����";
			if(hours == 6) return minuteWords[60 - minutes] + " �� ����";
			if(hours == 7) return minuteWords[60 - minutes] + " �� ������";
			if(hours == 8) return minuteWords[60 - minutes] + " �� ������";
			if(hours == 9) return minuteWords[60 - minutes] + " �� ������";
			if(hours == 10) return minuteWords[60 - minutes] + " �� �����������";
			if(hours == 11) return minuteWords[60 - minutes] + " �� ����������";
			if(hours == 12) return minuteWords[60 - minutes] + " �� ����";
		}
		
		if(minutes < 30 && hours >= 5 && hours <= 12 && hours != 8)	return minute + " ����� " + hour + "�";
		if(minutes < 30 && hours == 8) return minute + " ����� " + hour + "���";
		
		if(minutes == 30) {
			if(hours == 1) return minute + " �������";
			if(hours == 2) return minute + " ��������";
			if(hours == 3) return minute + " ����������";
			if(hours == 4) return minute + " ������";
			if(hours == 5) return minute + " �������";
			if(hours == 6) return minute + " ��������";
			if(hours == 7) return minute + " ��������";
			if(hours == 8) return minute + " ��������";
			if(hours == 9) return minute + " ��������";
			if(hours == 10) return minute + " �������������";
			if(hours == 11) return minute + " ������������";
			if(hours == 12) return minute + " �������";
		}

		if(minutes == 45) {
			if(hours == 1) return "���������� ����� �� ����";
			if(hours == 2) return "���������� ����� �� ����";
			if(hours == 3) return "���������� ����� �� �������";
			if(hours == 4) return "���������� ����� �� ����"; 
			if(hours == 5) return "���������� ����� �� �����";
			if(hours == 6) return "���������� ����� �� ����";
			if(hours == 7) return "���������� ����� �� ������";
			if(hours == 8) return "���������� ����� �� ������";
			if(hours == 9) return "���������� ����� �� ������";
			if(hours == 10)return "���������� ����� �� �����������";
			if(hours == 11)return "���������� ����� �� ����������";
			if(hours == 12)return "���������� ����� �� ����";
		}
		if(minutes > 30 && (hours % 12) + 1 >= 5 && (hours % 12) + 1 <= 12 && (hours % 12) + 1 != 8) {
			return minuteWords[60 - minutes] + " �� " + hourWords[(hours % 12) + 1] + "�";
		}
		if(minutes > 30 && (hours % 12) + 1 < 5) {
			if(hours == 1) return minuteWords[60 - minutes] + " �� ����";
			if(hours == 2) return minuteWords[60 - minutes] + " �� ����";
			if(hours == 3) return minuteWords[60 - minutes] + " �� �������";
			if(hours == 4) return minuteWords[60 - minutes] + " �� ����";
		}
		if(minutes > 30 && (hours % 12) + 1 == 8) {
			return minuteWords[60 - minutes] + " �� " + hourWords[(hours % 12) + 1] + "���";
		}
		minute = minuteWords[60 - minutes];
		return minute + " �� ����";
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	TimeToWordConverter converter;
	int clock = 0;
	int min = 0;
	cin >> clock;
	cin >> min;
	
	cout << converter.convert(clock, min);

	/*for(int i = 1; i <= 12; i++) {
		for(int j = 0; j < 59; j++) {
		cout << converter.convert(i, j) << endl;
		}
	}*/

	return 0;
}
