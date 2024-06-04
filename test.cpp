#include "test.h"
#include <iostream>
#include <limits>

using namespace std;

void displayQuestion(const string& question, const vector<string>& answers) {
    cout << question << endl;
    for (size_t i = 0; i < answers.size(); ++i) {
        cout << i + 1 << ". " << answers[i] << endl;
    }
}

int getUserAnswer() {
    int answer;
    cout << "Ваш ответ: ";
    cin >> answer;
    while (cin.fail() || answer < 1 || answer > 4) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Некорректный ввод. Пожалуйста, введите число от 1 до 4: ";
        cin >> answer;
    }
    return answer;
}

vector<int> conductTest(const vector<Question>& questions) {
    vector<int> userAnswers;
    for (const auto& question : questions) {
        displayQuestion(question.text, question.answers);
        int answer = getUserAnswer();
        userAnswers.push_back(answer);
    }
    return userAnswers;
}
