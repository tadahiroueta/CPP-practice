#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include <limits>

using namespace std;

const vector<string> firstDigitsReadings({
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen"
});

const vector<string> doubleDigitsReadings({
    "",
    "ten",
    "twenty",
    "thirty",
    "fourty",
    "fifty",
    "sixty",
    "seventy",
    "eighty",
    "ninety"
});

/**
 * @param n the number to be read
 * @return the written reading of the number
 * @pre @p n must be within range [0, 1'000'000'000'000]
 */
string say(unsigned long long n) {
    assert(0 <= n && n < 1'000'000'000'000'000);

    if (n < 20) return firstDigitsReadings[n];

    if (n < 100) return doubleDigitsReadings[n / 10] + (n % 10 == 0 ? "" : "-" + say(n % 10));

    if (n < 1'000) return firstDigitsReadings[n / 100] + " hundred" + (n % 100 == 0 ? "" : " " + say(n % 100));

    if (n < 1'000'000) return say(n / 1'000) + " thousand" + (n % 1'000 == 0 ? "" : " " + say(n % 1'000));

    if (n < 1'000'000'000) return say(n / 1'000'000) + " million" + (n % 1'000'000 == 0 ? "" : " " + say(n % 1'000'000));

    return say(n / 1'000'000'000) + " billion" + (n % 1'000'000'000 == 0 ? "" : " " + say(n % 1'000'000'000));
}

int main() {
    cout << "Input a number (0-999,999,999,999)" << endl;
    string input;
    cin >> input;
    unsigned long long number = stoll(input);
    cout << say(number);
}