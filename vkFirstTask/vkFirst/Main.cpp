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
			{1, "од"}, {2, "дв"}, {3, "тр"}, {4, "четыре"}, {5, "пят"},
			{6, "шест"}, {7, "сем"}, {8, "вос"}, {9, "девят"}, {10, "десят"},
			{11, "одиннадцат"}, {12, "двенадцат"}
		};
		unordered_map<int, string> minuteWords = {
			{1, "Одна минута"}, {2, "Две минуты"}, {3, "Три минуты"}, {4, "Четыре минуты"}, {5, "Пять минут"},
			{6, "Шесть минут"}, {7, "Семь минут"}, {8, "Восемь минут"}, {9, "Девять минут"}, {10, "Десять минут"},
			{11, "Одиннадцать минут"}, {12, "Двенадцать минут"}, {13, "Тринадцать минут"}, {14, "Четырнадцать минут"},
			{15, "Четверть"}, {16, "Шестнадцать минут"}, {17, "Семнадцать минут"}, {18, "Восемнадцать минут"},
			{19, "Девятнадцать минут"}, {20, "Двадцать минут"}, {21, "Двадцать одна минута"}, {22, "Двадцать две минуты"},
			{23, "Двадцать три минуты"}, {24, "Двадцать четыре минуты"}, {25, "Двадцать пять минут"}, {26, "Двадцать шесть минут"},
			{27, "Двадцать семь минут"}, {28, "Двадцать восемь минут"}, {29, "Двадцать девять минут"}, {30, "Половина"}
		};

		string hour = hourWords[hours];
		string minute = minuteWords[minutes];

		if(minutes == 0) {
			std::string hourWord = hourWords[hours];
			std::regex hourRegex("(од|дв|тр|четыре|пят|шест|сем|вос|девят|десят|одиннадцат|двенадцат)");
			std::regex_replace(hourWord, hourRegex, "$&ь");
			if(hours == 1) return hourWord + "ин час";
			if(hours == 2) return hourWord + "а часа";
			if(hours == 3) return hourWord + "и часа";
			if(hours == 4) return hourWord + "e часа";
			if(hours == 9 || hours == 10 || hours == 11 || hours == 12) return hourWord + "ь часов";
			if(hours == 5 || hours == 6 || hours == 7) return hourWord + "ь часов";
			if(hours == 8) return hourWord + "емь часов";
		}

		if(minutes == 1 && hours >= 5 && hours <= 12 && hours != 8) return minute + " после " + hour + "и";
		if(minutes == 1 && hours == 8) return minute + " после " + hour + "ьми";

		if(minutes >= 1 && minutes < 30 && minutes != 15 && hours < 5) {
			if(hours == 1) return minute + " после часа";
			if(hours == 2) return minute + " после двух";
			if(hours == 3) return minute + " после трех";
			if(hours == 4) return minute + " после четырех";
			if(hours == 5) return minute + " после пяти";
		}
		if(minutes == 15) {
			if(hours == 1) return minute + " второго";
			if(hours == 2) return minute + " третьего";
			if(hours == 3) return minute + " четвертого";
			if(hours == 4) return minute + " пятого";
			if(hours == 5) return minute + " шестого";
			if(hours == 6) return minute + " седьмого";
			if(hours == 7) return minute + " восьмого";
			if(hours == 8) return minute + " девятого";
			if(hours == 9) return minute + " десятого";
			if(hours == 10) return minute + " одиннадцатого";
			if(hours == 11) return minute + " двенадцатого";
			if(hours == 12) return minute + " первого";
		}
		if(minutes == 59) {
			if(hours == 0) return minuteWords[60 - minutes] + " до часа";
			if(hours == 1) return minuteWords[60 - minutes] + " до двух";
			if(hours == 2) return minuteWords[60 - minutes] + " до трех";
			if(hours == 3) return minuteWords[60 - minutes] + " до четырех";
			if(hours == 4) return minuteWords[60 - minutes] + " до пяти";
			if(hours == 5) return minuteWords[60 - minutes] + " до шести";
			if(hours == 6) return minuteWords[60 - minutes] + " до семи";
			if(hours == 7) return minuteWords[60 - minutes] + " до восьми";
			if(hours == 8) return minuteWords[60 - minutes] + " до девяти";
			if(hours == 9) return minuteWords[60 - minutes] + " до десяти";
			if(hours == 10) return minuteWords[60 - minutes] + " до одиннадцати";
			if(hours == 11) return minuteWords[60 - minutes] + " до двенадцати";
			if(hours == 12) return minuteWords[60 - minutes] + " до часа";
		}
		
		if(minutes < 30 && hours >= 5 && hours <= 12 && hours != 8)	return minute + " после " + hour + "и";
		if(minutes < 30 && hours == 8) return minute + " после " + hour + "ьми";
		
		if(minutes == 30) {
			if(hours == 1) return minute + " второго";
			if(hours == 2) return minute + " третьего";
			if(hours == 3) return minute + " четвертого";
			if(hours == 4) return minute + " пятого";
			if(hours == 5) return minute + " шестого";
			if(hours == 6) return minute + " седьмого";
			if(hours == 7) return minute + " восьмого";
			if(hours == 8) return minute + " девятого";
			if(hours == 9) return minute + " десятого";
			if(hours == 10) return minute + " одиннадцатого";
			if(hours == 11) return minute + " двенадцатого";
			if(hours == 12) return minute + " первого";
		}

		if(minutes == 45) {
			if(hours == 1) return "пятнадцать минут до двух";
			if(hours == 2) return "пятнадцать минут до трех";
			if(hours == 3) return "пятнадцать минут до четырех";
			if(hours == 4) return "пятнадцать минут до пяти"; 
			if(hours == 5) return "пятнадцать минут до шести";
			if(hours == 6) return "пятнадцать минут до семи";
			if(hours == 7) return "пятнадцать минут до восьми";
			if(hours == 8) return "пятнадцать минут до девяти";
			if(hours == 9) return "пятнадцать минут до десяти";
			if(hours == 10)return "пятнадцать минут до одиннадцати";
			if(hours == 11)return "пятнадцать минут до двенадцати";
			if(hours == 12)return "пятнадцать минут до часа";
		}
		if(minutes > 30 && (hours % 12) + 1 >= 5 && (hours % 12) + 1 <= 12 && (hours % 12) + 1 != 8) {
			return minuteWords[60 - minutes] + " до " + hourWords[(hours % 12) + 1] + "и";
		}
		if(minutes > 30 && (hours % 12) + 1 < 5) {
			if(hours == 1) return minuteWords[60 - minutes] + " до двух";
			if(hours == 2) return minuteWords[60 - minutes] + " до трех";
			if(hours == 3) return minuteWords[60 - minutes] + " до четырех";
			if(hours == 4) return minuteWords[60 - minutes] + " до пяти";
		}
		if(minutes > 30 && (hours % 12) + 1 == 8) {
			return minuteWords[60 - minutes] + " до " + hourWords[(hours % 12) + 1] + "ьми";
		}
		minute = minuteWords[60 - minutes];
		return minute + " до часа";
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
