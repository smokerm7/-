#include "evaluation.h"
#include <iostream>

using namespace std;

string evaluateResults(const vector<Question>& questions, const vector<int>& userAnswers) {
    int correctCount = 0;
    for (size_t i = 0; i < questions.size(); ++i) {
        if (userAnswers[i] == questions[i].correctAnswer) {
            ++correctCount;
        }
    }

    double score = static_cast<double>(correctCount) / questions.size() * 100;
    string grade;
    if (score == 100) {
        grade = "Отлично";
    }
    else if (score >= 80) {
        grade = "Хорошо";
    }
    else if (score > 60) {
        grade = "Удовлетворительно";
    }
    else {
        grade = "Плохо";
    }

    cout << "Результаты теста" << endl;
    cout << "Правильные ответы: " << correctCount << endl;
    cout << "Общее количество вопросов: " << questions.size() << endl;
    cout << "Процент правильных ответов: " << score << "%" << endl;
    cout << "Итоговая оценка: " << grade << endl;

    return grade;
}
