// These headers define some of the classes and functions we need
#include <iostream>
#include <string>
#include <sstream>
#include <limits>

// ONLY MAKE CHANGES WHERE THERE IS A TODO

// These using declarations let us refer to things more simply
// e.g. instead of "std::cin" we can just write "cin"
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

// These methods are defined below the main function

// print instructions for inputting grades
void print_instructions();

// pretty print a summary of the grades
void print_results(double exam_average,
                   double hw_average,
                   double lw_average,
                   double reading,
                   double engagement,
                   double weighted_total,
                   char final_letter_grade);

// YOU ARE NOT EXPECTED TO UNDERSTAND THIS ONE... YET
// extract the category and score from the line
// and store the values in the provided variables
// if line := "exam 95", then category := "exam" and score := 95
// if the line is invalid, then category := "ignore"
void get_category_and_score(const string& line,
                            string* category,
                            double* score);

int main() {
    print_instructions();

    // ONLY MAKE CHANGES WHERE THERE IS A TODO

    // TODO(student): declare and initialize variables that you want

    string line;
    // read one line from standard input (discards the ending newline character)
    getline(cin, line);
    // read lines until an empty line is read

    double total_exam = 0, total_hw = 0, total_lw = 0, total_rd = 0, total_eg = 0, fin_score = 0;
    int num_exam = 0, num_hw = 0, num_lw = 0, num_rd = 0, num_eg = 0;

    bool final = false;

    while (!line.empty()) {
        string category;
        double score;
        get_category_and_score(line, &category, &score);

        // process the grade entry
        if (category == "exam") {
            total_exam += score;
            num_exam++;
        } else if (category == "final-exam") {
            final = true;
            total_exam += score;
            fin_score = score;
        } else if (category == "hw") {
            total_hw += score;
            num_hw++;
        } else if (category == "lw") {
            total_lw ++;
            num_lw++;
        } else if (category == "reading") {
            total_rd += score;
            num_rd++;
        } else if (category == "engagement") {
            total_eg += score;
            num_eg ++;
        } else {
            cout << "ignored invalid input" << endl;
        }

        // get the next line from standard input
        getline(cin, line);
    }
    
    if (num_exam == 1)
        num_exam++;

    if (!final)
        num_exam++;

    // TODO(student): compute component averages
    double exam_average = total_exam / num_exam;
    double hw_average = total_hw / num_hw;
    double lw_average = (total_lw / num_lw) * 100;
    double reading = total_rd / num_rd;
    double engagement = total_eg / num_eg;
    
    if (num_rd == 0)
        reading = 0;

    if (num_eg == 0)
        engagement = 0;

    if (num_lw == 0)
        lw_average = 0;

    if (num_hw == 0)
        hw_average = 0;

    if (reading + 15 > 100)
        reading = 100;
    else
        reading += 15;

    if (fin_score > exam_average)
        exam_average = fin_score;

    /**
    if (lw_average + 15 > 100) {
        lw_average = 100;
    } else {
        lw_average += 15;
    }*/

    if (engagement + 15 > 100)
        engagement = 100;
    else
        engagement += 15;

    // TODO(student): compute weighted total of components
    double weighted_total = hw_average * 0.4 + lw_average * 0.1 + reading * 0.05 + engagement * 0.05 + exam_average * 0.4;

    char final_letter_grade = (char) 0;
    if (weighted_total <= 100 && weighted_total >= 90)
        final_letter_grade = 'A';
    else if (weighted_total >= 80)
        final_letter_grade = 'B';
    else if (weighted_total >= 70)
        final_letter_grade = 'C';
    else if (weighted_total >= 60)
        final_letter_grade = 'D';
    else
        final_letter_grade = 'F';

    print_results(
        exam_average, hw_average, lw_average, reading, engagement,
        weighted_total, final_letter_grade);
}

// These methods are already implemented for you
// You should not need to modify them

void print_instructions() {
    cout << "enter grades as <category> <score>" << endl;
    cout << "  <category> := exam | final-exam | hw | lw | reading | engagement" << endl;
    cout << "     <score> := numeric value" << endl;
    cout << "enter an empty line to end input" << endl;
}

void get_category_and_score(
    const string& line,
    string* category,
    double* score) {
    // turn the string into an input stream
    std::istringstream sin(line);

    // read the category (as string) and score (as double) from the stream
    sin >> *category;
    sin >> *score;

    if (sin.fail()) {
        // the stream is in a fail state (something went wrong)
        // clear the flags
        sin.clear();
        // clear the stream buffer (throw away whatever garbage is in there)
        sin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // signal that the line was invalid
        *category = "ignore";
    }
}

void print_results(
    double exam_average,
    double hw_average,
    double lw_average,
    double reading,
    double engagement,
    double weighted_total,
    char final_letter_grade) {
    cout << "summary:" << endl;
    cout << "      exam average: " << exam_average << endl;
    cout << "        hw average: " << hw_average << endl;
    cout << "        lw average: " << lw_average << endl;
    cout << "           reading: " << reading << endl;
    cout << "        engagement: " << engagement << endl;
    cout << "    ---------------" << endl;

    cout << "    weighted total: " << weighted_total << endl;

    cout << "final letter grade: " << final_letter_grade << endl;
}