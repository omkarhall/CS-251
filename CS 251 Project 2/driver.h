/* Project 2 - Personality Tests (driver.h)
 * Omkar Halleppanawar
 *
 * Project Description:
 * driver.h is the data processing framework that works behind the
 * scenes to tabulate scores from the personality quiz and determines
 * who the user is most similar to.
 */

#include <math.h>
#include <limits>
#include <string>
#include <map>
#include <set>
#include "myrandom.h"

using namespace std;

constexpr double lowest_double = std::numeric_limits<double>::lowest();

/* Type: Question
 *
 * Type representing a personality quiz question.
 */
struct Question {
    string questionText;  // Text of the question
    map<char, int> factors;   // Map from factors to +1 or -1
    friend bool operator< (const Question& lhs, const Question& rhs) {
        return lhs.questionText < rhs.questionText;
    }
    friend bool operator== (const Question& lhs, const Question& rhs) {
        return lhs.questionText == rhs.questionText;
    }
    friend bool operator!= (const Question& lhs, const Question& rhs) {
        return lhs.questionText != rhs.questionText;
    }
};

/* Type: Person
 *
 * Type representing a person, used to represent people when determining
 * who's the closest match to the user.
 */
struct Person {
    string name;      // Name of the person
    map<char, int> scores;  // Map from factors to +1 or -1
    friend bool operator< (const Person& lhs,   const Person& rhs) {
        return lhs.name < rhs.name;
    }
    friend bool operator== (const Person& lhs, const Person& rhs) {
        return lhs.name == rhs.name;
    }
    friend bool operator!= (const Person& lhs, const Person& rhs) {
        return lhs.name != rhs.name;
    }
};

/* randomElement
 *
 * This function selects, at random, a Question from the inputted questions set
 * and returns the question.  Note, this function does not remove the randomly
 * selected question from the set.
*/
Question randomElement(set<Question>& questions) {
    int ind = randomInteger(0, (int)questions.size()-1);
    int i = 0;
    for (auto e : questions) {
        if (i == ind) {
            return e;
        }
        i++;
    }
    return {};
}

/* randomQuestionFrom
 *
 * This function chooses a random question from the Question set,
 * removes it from the set, then returns it.
 */
Question randomQuestionFrom(set<Question>& questions) {
    if (questions.size() == 0) {
        throw "The question set is empty.";
    }
    Question q = randomElement(questions);
    questions.erase(q);
    return q;
}

/* scoresFrom
 *
 * This function takes as input a map containing the user’s
 * answers to their personality quiz questions, then
 * returns a map representing their OCEAN scores.
 */
map<char, int> scoresFrom(map<Question, int>& answers) {
    map<char, int> scores;
    int multiplier = 0;  // from answer what to multiply factor by
    for (auto &e : answers) {
        multiplier = e.second - 3;
        for (auto &f : e.first.factors) {
            if (scores.count(f.first) == 1) {
                scores[f.first] += f.second * multiplier;
            } else {
                scores[f.first] = f.second * multiplier;
            }
        }
    }
    return scores;
}

/* normalize
 *
 * This function takes as anput a map containing the user's
 * raw scores and returns a map representing the normalized
 * verson of their scores
 */
map<char, double> normalize(map<char, int>& scores) {
    map<char, double> normalized;
    double root = 0;
    for (auto &e : scores) {
        root += pow(e.second, 2);
    }
    if (root == 0) {
        // if root is 0 scores map is full of 0's
        throw "Scores map does not contain any non-zero values.";
    }
    root = pow(root, 0.5);
    for (auto &e : scores) {
        normalized[e.first] = scores[e.first] / root;
    }
    return normalized;
}

/* cosineSimilarityOf
 *
 * This function takes as input two sets of normalized scores,
 * then returns their cosine similarity
 */
double cosineSimilarityOf(const map<char, double>& lhs,
                          const map<char, double>& rhs) {
    double similarity = 0;
    for (auto &e : lhs) {
        if (lhs.count(e.first) != 0 && rhs.count(e.first) != 0) {
            // only add to similarity if it is in both maps
            similarity += lhs.at(e.first) * rhs.at(e.first);
        }
    }
    return similarity;
}

/* mostSimilarTo
 *
 * This function takes as input the user’s raw OCEAN scores and a Set of
 * fictional people. This function then returns the Person whose
 * scores have the highest cosine similarity to the user’s scores.
 */
Person mostSimilarTo(map<char, int>& scores, set<Person>& people) {
    if (people.size() == 0) {
        throw "No people to compare.";
    }
    Person p;  // keeps track of person with highest similarity
    try {
        map<char, double> normalizedUser = normalize(scores);
        double current;
        double max = lowest_double;
        for (auto e : people) {
            current = cosineSimilarityOf(normalizedUser, normalize(e.scores));
            if (current > max) {
                max = current;
                p = e;
            }
        }
    } catch(const char* msg) {
        // error was thrown from normalize()
        throw msg;
    }
    return p;
}
