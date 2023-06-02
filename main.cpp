#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Item {
public:
    string name;
    int dmg;

    Item(string name, int dmg) : name(name), dmg(dmg) {}
};

class Gracz {
public:
    string name;
    int dmg;
    int hp;
    vector<Item> items;

    Gracz(string name, int dmg, int hp) : name(name), dmg(dmg), hp(hp) {}

    void AddItem(const Item& item) {
        items.push_back(item);
    }
};

class Teams {
public:
    vector<Gracz> Team1;
    vector<Gracz> Team2;

    void AddToTeam1(string name, int dmg, int hp) {
        Team1.push_back(Gracz(name, dmg, hp));
    }

    void AddToTeam2(string name, int dmg, int hp) {
        Team2.push_back(Gracz(name, dmg, hp));
    }

    void ShowTeam(int teamNumber) {
        
        vector<Gracz> team;
        if (teamNumber == 1) {
            cout << "===TEAM1=== \n";
            team = Team1;
        } else if (teamNumber == 2) {
            cout << "===TEAM2=== \n";

            team = Team2;
        } else {
            cout << "incorrect team number!" << endl;
            return;
        }

        for (int i = 0; i < team.size(); i++) {
            const Gracz& player = team[i];
            cout << "name: " << player.name << endl;
            cout << "dmg: " << player.dmg << endl;
            cout << "hp: " << player.hp << endl;

            if (!player.items.empty()) {
                cout << "Items:" << endl;
                for (int j = 0; j < player.items.size(); j++) {
                    const Item& item = player.items[j];
                    cout << "  name: " << item.name << endl;
                    cout << "  dmg: " << item.dmg << endl;
                }
            }
            else{
                cout << "  no items \n";
            }
        }

    }
};

int main() {
    Teams teams;

    teams.AddToTeam1("Jan", 5, 100);
    teams.AddToTeam1("Anna", 8, 200);
    teams.AddToTeam1("Kamil", 3, 50);

    teams.AddToTeam2("Kamil", 3, 50);
    teams.AddToTeam2("Kamil", 3, 50);
    teams.AddToTeam2("Kamil", 3, 50);

    teams.Team1[0].AddItem(Item("Sword", 10));
    teams.Team1[1].AddItem(Item("Axe", 12));
    teams.Team2[0].AddItem(Item("Bow", 7));
    teams.Team2[2].AddItem(Item("Wand", 5));

    teams.ShowTeam(1);
    teams.ShowTeam(2);

    return 0;
}
