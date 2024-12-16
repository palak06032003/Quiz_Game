#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Structure to hold a question and its options
struct Question {
    string questionText;
    vector<string> options;
    int correctAnswer; // Index of the correct option (0-based)
};

// Function prototypes
void displayQuestion(const Question &q, int questionNumber);
int askQuestion(const Question &q);
void displayScore(int score, int total);

int main() {
    vector<Question> quiz = {
        {"What is the capital of France?", {"1. Berlin", "2. Madrid", "3. Paris", "4. Rome"}, 2},
        {"Who wrote 'Hamlet'?", {"1. Charles Dickens", "2. William Shakespeare", "3. J.K. Rowling", "4. Mark Twain"}, 1},
        {"What is the smallest prime number?", {"1. 0", "2. 1", "3. 2", "4. 3"}, 2},
        {"Which planet is known as the Red Planet?", {"1. Earth", "2. Venus", "3. Mars", "4. Jupiter"}, 2},
        {"What is the largest mammal?", {"1. Elephant", "2. Blue Whale", "3. Great White Shark", "4. Giraffe"}, 1}
    };

    int score = 0;
    int totalQuestions = quiz.size();

    cout << "\n========== Welcome to the Quiz Game ==========" << endl;

    for (int i = 0; i < totalQuestions; ++i) {
        displayQuestion(quiz[i], i + 1);
        if (askQuestion(quiz[i])) {
            cout << "Correct!\n";
            ++score;
        } else {
            cout << "Wrong! The correct answer was option " << quiz[i].correctAnswer + 1 << ".\n";
        }
    }

    displayScore(score, totalQuestions);

    return 0;
}

void displayQuestion(const Question &q, int questionNumber) {
    cout << "\nQuestion " << questionNumber << ": " << q.questionText << endl;
    for (const auto &option : q.options) {
        cout << option << endl;
    }
    cout << "Enter your answer (1-" << q.options.size() << "): ";
}

int askQuestion(const Question &q) {
    int answer;
    cin >> answer;
    return (answer - 1 == q.correctAnswer);
}

void displayScore(int score, int total) {
    cout << "\n========== Quiz Over ==========" << endl;
    cout << "Your score: " << score << " out of " << total << endl;
    cout << "Thank you for playing!\n";
}

