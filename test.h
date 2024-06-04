#ifndef TEST_H
#define TEST_H

#include <vector>
#include "question.h"

void displayQuestion(const string& question, const vector<string>& answers);
int getUserAnswer();
vector<int> conductTest(const vector<Question>& questions);

#endif
#pragma once
