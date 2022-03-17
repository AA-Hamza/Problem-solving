/*
 * Problem Link https://www.codewars.com/kata/52742f58faf5485cae000b9a/train/cpp
*/

#define YEAR_SECONDS ((365*24*60*60))
#define MONTH_SECONDS ((30*24*60*60))
#define DAY_SECONDS ((24*60*60))
#define HOUR_SECONDS ((60*60))
#define MINUTE_SECONDS ((60))

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string add_s(int num) {
    if (num > 1)
        return "s";

    return "";
}

string date_to_string(int n, string name) {
    if (!n)
        return "none";

    return to_string(n)+" "+name+add_s(n);
}


std::string format_duration(int seconds) {
    if (seconds == 0)
        return "now";

    int years = seconds / YEAR_SECONDS;
    seconds %= YEAR_SECONDS;

    /*
    int months = seconds / MONTH_SECONDS;
    seconds %= MONTH_SECONDS;
    */
    int months = 0;

    int days = seconds / DAY_SECONDS;
    seconds %= DAY_SECONDS;

    int hours = seconds / HOUR_SECONDS;
    seconds %= HOUR_SECONDS;

    int minutes = seconds / MINUTE_SECONDS;
    seconds %= MINUTE_SECONDS;

    int num_of_date_types = (bool)years+(bool)months+(bool)days+(bool)hours+(bool)minutes+(bool)seconds;

    vector<string> result;
    result.push_back(date_to_string(years, "year"));
    result.push_back(date_to_string(months, "month"));
    result.push_back(date_to_string(days, "day"));
    result.push_back(date_to_string(hours, "hour"));
    result.push_back(date_to_string(minutes, "minute"));
    result.push_back(date_to_string(seconds, "second"));

    vector<string> final_result;
    copy_if(result.begin(), result.end(), back_inserter(final_result), [](string tmp){return tmp!="none";});
    if (num_of_date_types>1) {
        final_result.insert(final_result.end()-1, "and");

        if (num_of_date_types > 2) {
            for (int i = 0; i < final_result.size() - 3; ++i) {
                //if (final_result[i] != "")
                    final_result[i] += ",";
            }
        }
    }
    string final_string;

    for (int i=0; i < final_result.size()-1; ++i) {
        //if (final_result[i] != "")
            final_string += final_result[i]+" ";
    }
    //if (final_result[final_result.size()-1] != "")
        final_string += final_result[final_result.size()-1];

    return final_string;
}

int main() {
    cout << format_duration(0) << endl;
    cout << format_duration(1) << endl;
    cout << format_duration(62) << endl;
    cout << format_duration(120) << endl;
    cout << format_duration(3662) << endl;
}
