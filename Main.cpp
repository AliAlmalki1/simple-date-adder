#include <iostream>
#include <chrono>
#include <iomanip>
#include <ctime> 

using namespace std;

int main() {
    int next_session;
    auto now = chrono::system_clock::now();
    time_t now_c = chrono::system_clock::to_time_t(now);
    tm localTime = *localtime(&now_c);

    cout << "Today's date: " << put_time(&localTime, "%Y-%m-%d") << endl;
    cout << "Day of the week: " << put_time(&localTime, "%A") << endl;

    cout << "Enter the number of days to add: ""\n";
    cin >> next_session;

    localTime.tm_mday += next_session; 
    time_t futureTime_c = mktime(&localTime); 
    if (futureTime_c == -1){
        std::cerr << "Error calculating future time.\n";
        return 1;
    }
    tm futureLocalTime = *localtime(&futureTime_c);

    cout << "The next session date: " << put_time(&futureLocalTime, "%Y-%m-%d") << endl;
    cout << "The next session Day of the week: " << put_time(&futureLocalTime, "%A") << endl;

    return 0;
}
