#include "question.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<Question> readTestFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Ошибка: не удается открыть файл" << endl;
        exit(1);
    }

    vector<Question> questions;
    string line;
    while (getline(file, line)) {
        Question question;
        question.text = line;

        for (int i = 0; i < 4; ++i) {
            getline(file, line);
            question.answers.push_back(line);
        }

        getline(file, line);
        question.correctAnswer = stoi(line);

        questions.push_back(question);
    }

    file.close();
    return questions;
}
