#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


int main ()
{
        int Q;
        map<int, vector<string>> buses;
        int counter = 1;

        cin >> Q;

        while (Q) {
                int num, i;
                bool exists = false;
                cin >> num;
                vector<string> v(num);

                for (string& s : v)
                        cin >> s;

                for (const auto& item : buses)
                        if (item.second == v) {
                                i = item.first;
                                exists = true;
                        }

                if (exists)
                        cout << "Already exists for " << i << endl;
                else {
                        buses[counter] = v;
                        cout << "New bus " << counter << endl;
                        counter += 1;
                }

                Q--;
        }

        return (0);
}
