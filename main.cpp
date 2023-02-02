/*
 * Считывание данных о человеке из csv-файла.
 * Формат файла:
 * <фамилия>;<имя>;<отчество>;<дата рождения>;
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    system("chcp 65001");

    ifstream file;
    string path;

    cout << "Введите путь к csv-файлу: ";
    cin >> path;

    file.open(path);
    if (!file.is_open()) {
        cout << "!!! ОШИБКА !!!" << endl;
        cout << "Файл " << path << " не найден или отсутствует доступ!" << endl;

        file.close();
        return 1;
    }

    string line;
    while (getline(file, line)) {
        string temp_line = line;

        int position = temp_line.find(';', 0);
        string last_name = temp_line.substr(0, position);
        temp_line = temp_line.substr(position + 1);

        position = temp_line.find(';', 0);
        string first_name = temp_line.substr(0, position);
        temp_line = temp_line.substr(position + 1);

        position = temp_line.find(';', 0);
        string patronymic = temp_line.substr(0, position);
        temp_line = temp_line.substr(position + 1);

        position = temp_line.find(';', 0);
        string date_of_birth = temp_line.substr(0, position);

        string temp_date = date_of_birth;
        position = temp_date.find('.', 0);
        int day = stoi(temp_date.substr(0, position));
        temp_date = temp_date.substr(position + 1);

        position = temp_date.find('.', 0);
        int month = stoi(temp_date.substr(0, position));
        temp_date = temp_date.substr(position + 1);

        int year = stoi(temp_date.substr(0));

        cout << "Пользователь: ";
        cout << last_name << " " << first_name << " " << patronymic << endl;
        cout << "Дата рождения: " << endl;
        cout << "год: " << year << endl;
        cout << "месяц: " << month << endl;
        cout << "день: " << day << endl;
    }

    return 0;
}
