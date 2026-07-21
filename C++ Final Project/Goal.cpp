#include "Goal.h"

Goal::Goal() {
    name = "";
    category = "";
    difficulty = "";
    xp = 0;
    completed = false;
}

Goal::Goal(string n, string cat, string diff, int xp, bool comp) {
    name = n;
    category = cat;
    difficulty = diff;
    xp = xp;
    completed = comp;
}

string Goal::getName() {
    return name;
}

string Goal::getCategory() {
    return category;
}

string Goal::getDifficulty() {
    return difficulty;
}

int Goal::getXP() {
    return xp;
}

bool Goal::isCompleted() {
    return completed;
}

void Goal::setName(string n) {
    name = n;
}

void Goal::setCategory(string comp) {
    category = comp;
}

void Goal::setDifficulty(string diff) {
    difficulty = diff;
}

void Goal::setXP(int xp) {
    xp = xp;
}

void Goal::setCompleted(bool comp) {
    completed = comp;
}
