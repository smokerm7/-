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
        grade = "�������";
    }
    else if (score >= 80) {
        grade = "������";
    }
    else if (score > 60) {
        grade = "�����������������";
    }
    else {
        grade = "�����";
    }

    cout << "���������� �����" << endl;
    cout << "���������� ������: " << correctCount << endl;
    cout << "����� ���������� ��������: " << questions.size() << endl;
    cout << "������� ���������� �������: " << score << "%" << endl;
    cout << "�������� ������: " << grade << endl;

    return grade;
}
