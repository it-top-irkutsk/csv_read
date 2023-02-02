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
        int position = line.find(';', 0);
        string last_name = line.substr(0, position);
        line = line.substr(position + 1);

        position = line.find(';', 0);
        string first_name = line.substr(0, position);
        line = line.substr(position + 1);

        position = line.find(';', 0);
        string patronymic = line.substr(0, position);
        line = line.substr(position + 1);

        position = line.find(';', 0);
        string date_of_birth = line.substr(0, position);

        cout << "Пользователь: ";
        cout << last_name << " " << first_name << " " << patronymic << ", ";
        cout << date_of_birth << endl;
    }

    return 0;
}
