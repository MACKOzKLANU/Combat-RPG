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

class Combat {
public:
    void Fight(Gracz& player1, Gracz& player2) {
        cout << "FIGHT!" << endl;
        cout << "Player 1: " << player1.name << " vs Player 2: " << player2.name << endl;

        while (player1.hp > 0 && player2.hp > 0) {
            player2.hp -= player1.dmg;
            cout << player1.name << " deals " << player1.dmg << " damage to " << player2.name << endl;
            cout << player2.name << " HP: " << player2.hp << endl;

            if (player2.hp <= 0) {
                cout << player2.name << " has been defeated!" << endl;
                break;
            }

            player1.hp -= player2.dmg;
            cout << player2.name << " deals " << player2.dmg << " damage to " << player1.name << endl;
            cout << player1.name << " HP: " << player1.hp << endl;
            
            int option;
            cout << "press 1 to continue or 2 to exit: ";
            cin >> option;
            if(option == 2){
                break;
            }

            if (player1.hp <= 0) {
                cout << player1.name << " has been defeated!" << endl;
                break;
            }
        }
    }
};


int main() {
    Teams T;
    Combat C;

    T.AddToTeam1("Jan", 5, 100);
    T.AddToTeam1("Anna", 8, 200);
    T.AddToTeam1("Kamil", 3, 50);

    T.AddToTeam2("Kamila", 3, 50);
    T.AddToTeam2("fryzjer", 3, 50);
    T.AddToTeam2("tomek", 3, 50);

    T.Team1[0].AddItem(Item("Sword", 10));
    T.Team1[1].AddItem(Item("Axe", 12));
    T.Team2[0].AddItem(Item("Bow", 7));
    T.Team2[2].AddItem(Item("Wand", 5));

    T.ShowTeam(1);
    T.ShowTeam(2);
    
    C.Fight(T.Team1[0], T.Team2[1]);


    return 0;
}
