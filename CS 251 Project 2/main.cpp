/* Project 2 - Personality Tests (main.cpp)
 * Omkar Halleppanawar
 *
 * Project Description:
 * The personality test interface is written in main.cpp.  It will do all the
 * file reading, user input/output, call all the functions in driver.h,
 * etc. such that the personality quiz app  is fully functioning
 */

#include <set>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "driver.h"

using namespace std;

/* readFactor
 *
 * This function helps readLine by reading the factors from the line.
 * It takes as input the text containing the factors, a person set
 * and question set to fill depending on the file, and boolean
 * forQuestion, which is true if the file to be read is the question
 * file and false otherwise
 */
void readFactor(string factorText, Question& q, bool& forQuestion, Person& p) {
    stringstream ss(factorText);
    string category_str;  // contains OCEAN letter
    string factor_str;  // contains factor or score
    while (ss.good()) {
        getline(ss, category_str, ':');
        getline(ss, factor_str);
    }
    if (forQuestion) {
        q.factors.insert(make_pair(category_str[0], stoi(factor_str)));
    } else {
        p.scores.insert(make_pair(category_str[0], stoi(factor_str)));
    }
}

/* readLine
 *
 * This function helps readFile by reading a line from the file.
 * It takes as input the line to be read, a person set and question set
 * to fill depending on the file, and boolean forQuestion, which is true
 * if the file to be read is the question file and false otherwise
 */
void readLine(string line, set<Question>& questions, bool& forQuestion,
              set<Person>& people) {
    stringstream ss(line);
    string questionText;  // either name or question
    string factorText;  // either factors or scores
    getline(ss, questionText, '.');
    Question q;
    Person p;
    if (forQuestion) {
        q.questionText = questionText + ".";
    } else {
        p.name = questionText;
    }
    getline(ss, factorText, ' ');  // skip past space
    while (getline(ss, factorText, ' ')) {
        // read factors/scores one at a time until end of line
        readFactor(factorText, q, forQuestion, p);
    }
    if (forQuestion) {
        questions.insert(q);
    } else {
        people.insert(p);
    }
}

/* readFile
 *
 * This function can read the questions.txt file or any people files.
 * It takes as input the filename, a person set and question set to
 * fill depending on the file, and boolean forQuestion, which is true
 * if the file to be read is the question file and false otherwise
 */
void readFile(string filename, set<Question>& questions, bool& forQuestion,
                   set<Person>& people) {
    ifstream infile(filename);
    if (!infile.is_open()) {
        cout << "Error: unable to open " << "'" << filename << "'" << endl;
        return;
    }
    people.clear();  // clear people set so it can be reused
    string line;
    while (getline(infile, line)) {
        readLine(line, questions, forQuestion, people);
    }
    infile.close();
}

/* printOptions
 *
 * This function prints answer choice options for the menu
 */
void printOptions() {
    cout <<  endl;
    cout << "1. Strongly disagree" << endl;
    cout << "2. Disagree" << endl;
    cout << "3. Neutral" << endl;
    cout << "4. Agree" << endl;
    cout << "5. Strongly agree" << endl;
    cout << endl;
}

/* printTest
 *
 * This function prints test choice options for the menu
 */
void printTest() {
    cout <<  endl;
    cout << "1. BabyAnimals" << endl;
    cout << "2. Brooklyn99" << endl;
    cout << "3. Disney" << endl;
    cout << "4. Hogwarts" << endl;
    cout << "5. MyersBriggs" << endl;
    cout << "6. SesameStreet" << endl;
    cout << "7. StarWars" << endl;
    cout << "8. Vegetables" << endl;
    cout << "9. mine" << endl;
    cout << "0. To end program." << endl;
    cout << endl;
    cout << "Choose test number (1-9, or 0 to end): ";
}

/* peopleFile
 *
 * Function that returns the filename of the test
 * given the user's choice
 */
string peopleFile(int choice) {
    string filename;
    if (choice == 1) {
        filename = "BabyAnimals.people";
    } else if (choice == 2) {
        filename = "Brooklyn99.people";
    } else if (choice == 3) {
        filename = "Disney.people";
    } else if (choice == 4) {
        filename = "Hogwarts.people";
    } else if (choice == 5) {
        filename = "MyersBriggs.people";
    } else if (choice == 6) {
        filename = "SesameStreet.people";
    } else if (choice == 7) {
        filename = "StarWars.people";
    } else if (choice == 8) {
        filename = "Vegetables.people";
    } else if (choice == 9) {
        filename = "mine.people";
    }
    return filename;
}

/* getAnswers
 *
 * Function that takes number of questions wanted by user and selects that
 * number of random questions from the questions set. It prints the questions
 * out and saves the user's answers in the answer map
 */
void getAnswers(int numQ, set<Question>& questions, map<Question,
                int>& answers) {
    int answer;  // answer to question
    for (int i = 0; i < numQ; i++) {
        cout << endl << "How much do you agree with this statement?" << endl;
        Question q = randomQuestionFrom(questions);
        cout << "\"" << q.questionText << "\"" << endl;
        printOptions();
        cout << "Enter your answer here (1-5): ";
        cin >> answer;
        answers[q] = answer;
    }
}

/* findMatch
 *
 * Function that takes in question and people sets and answers map
 * and forQuestion bool. Uses these inputs to find the closest
 * match to the user's scores and prints the match in the interface
 */
void findMatch(map<Question, int>& answers, set<Question>& questions,
               set<Person>& people, bool& forQuestion) {
    int choice = -1;  // choice for which test to take
    string filename;
    map<char, int> scores;
    Person p;
    while (choice != 0) {
        printTest();
        cin >> choice;
        filename = peopleFile(choice);
        forQuestion = false;  // reading people files now
        if (choice != 0) {
            readFile(filename, questions, forQuestion, people);
        }
        scores = scoresFrom(answers);
        p = mostSimilarTo(scores, people);
        if (choice != 0) {
            cout << "You got " << p.name << "!" << endl;
        }
    }
}

int main() {
    cout << "Welcome to the Personality Quiz!" << endl;
    int numQ;
    cout << endl << "Choose number of questions: ";
    cin >> numQ;

    // read in questions.txt
    set<Question> questions;
    set<Person> people;
    bool forQuestion = true;  // true if file to be read is questions.txt, false otherwise
    readFile("questions.txt", questions, forQuestion, people);

    // get user's answers to questions
    map<Question, int> answers;
    getAnswers(numQ, questions, answers);
    
    // find closest match to user
    findMatch(answers, questions, people, forQuestion);
    cout << "Goodbye!" << endl;
    return 0;
}
