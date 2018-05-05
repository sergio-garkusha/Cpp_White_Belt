#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


void printAll (const map<string, vector<string>>& buses)
{
        if (buses.empty())
                cout << "No buses" << endl;
        else
                for (auto& bus : buses) {
                        cout << "Bus " << bus.first << ": ";

                        for (const string& stop : bus.second)
                                cout << stop << " ";

                        cout << endl;
                }
}

void printBuses (const map<string, vector<string>>& buses,
                        map<string, vector<string>>& stops,
                        const string& stop)
{
        if (stops.count(stop) == 0)
                cout << "No stop" << endl;
        else {
                for (string& bus : stops[stop])
                        cout << bus << " ";
                cout << endl;
        }
}

void printStops (map<string, vector<string>>& buses,
                        map<string, vector<string>>& stops,
                        const string& bus)
{
        if (buses.count(bus) == 0)
                cout << "No bus" << endl;
        else
                for (string& stop : buses[bus]) {
                        cout << "Stop " << stop << ": ";

                        if (stops[stop].size() == 1)
                                cout << "no interchange";
                        else
                                for (string& other_bus : stops[stop])
                                        if (bus != other_bus)
                                                cout << other_bus << " ";

                        cout << endl;
                }
}


int main() {
        int Q;
        map<string, vector<string>> buses, stops;
        cin >> Q;

        while (Q) {
                string op, stop, bus;
                cin >> op;

                if (op == "NEW_BUS") {
                        int stop_count;
                        cin >> bus >> stop_count;
                        vector<string>& sts = buses[bus];

                        sts.resize(stop_count);

                        for (string& s : sts) {
                                cin >> s;
                                stops[s].push_back(bus);
                        }
                } else if (op == "STOPS_FOR_BUS") {
                        cin >> bus;
                        printStops (buses, stops, bus);
                } else if (op == "BUSES_FOR_STOP") {
                        cin >> stop;
                        printBuses (buses, stops, stop);
                } else if (op == "ALL_BUSES")
                        printAll (buses);

                Q--;
        }

        return (0);
}
