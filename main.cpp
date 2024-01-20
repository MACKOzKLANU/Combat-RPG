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

class Playerc {
public:
    string name;
    int dmg;
    int hp;
    vector<Item> items;

    Playerc(string name, int dmg, int hp) : name(name), dmg(dmg), hp(hp){ } 

    void AddItem(const Item& item) {
        items.push_back(item);
    }
};

class Combat;

class Teams {
public:
    vector<Playerc> Team1;
    vector<Playerc> Team2;

    void AddToTeam1(string name, int dmg, int hp) {
        Team1.push_back(Playerc(name, dmg, hp));
    }

    void AddToTeam2(string name, int dmg, int hp) {
        Team2.push_back(Playerc(name, dmg, hp));
    }

    void ShowTeam(int teamNumber) {

        vector<Playerc> team;
        if (teamNumber == 1) {
            printf("\x1B[31m==========TEAM1========== \033[0m\t\t");

            team = Team1;
        }
        else if (teamNumber == 2) {
            printf("\x1B[31m==========TEAM2==========\n\033[0m\t\t");


            team = Team2;
        }
        else {
            cout << "incorrect team number!" << endl;
            return;
        }

        for (int i = 0; i < team.size(); i++) {
            const Playerc& player = team[i];
            cout << "\n=========INFO=============" << endl;

            cout << "name: " << player.name << endl;
            cout << "dmg: " << player.dmg << endl;
            cout << "hp: " << player.hp << endl;
            cout << "==========================" << endl;


            if (!player.items.empty()) {
                cout << "==========ITEMS===========" << endl;

                for (int j = 0; j < player.items.size(); j++) {
                    const Item& item = player.items[j];
                    cout << "  name: " << item.name << endl;
                    cout << "  dmg: " << item.dmg << endl;
                    cout << "==========================" << endl;

                }
            }
            else {
                cout << "=========No items=========" << endl;

            }
        }

    }

        
        
    int SelectPlayer(int teamNumber) {
        vector<Playerc>& team = (teamNumber == 1) ? Team1 : Team2;

        cout << "=====Select player " << teamNumber << " =====" << endl;
        for (int i = 0; i < team.size(); i++) {
            cout << i + 1 << ". " << team[i].name << endl;
        }

        int playerIndex;
        cout << "==========================" << endl;

        cout << "Enter player index: ";
        cin >> playerIndex;
        system("clear");


        return playerIndex - 1;
    }

    void Fight();

};

class Combat {
public:
    void Fight(Playerc& player1, Playerc& player2) {
        
        cout << "==========FIGHT===========" << endl;

        cout << "Player 1: " << player1.name << " vs Player 2: " << player2.name << endl;

        while (player1.hp > 0 && player2.hp > 0) {
            player2.hp -= player1.dmg;
            cout << "==========================" << endl;

            cout << player1.name << " deals " << player1.dmg << " damage to " << player2.name << endl;
            cout << "==========================" << endl;

            cout << player2.name << " HP: " << player2.hp << endl;
            cout << "==========================" << endl;


            if (player2.hp <= 0) {
                cout << player2.name << " has been defeated!" << endl;
                break;
            }

            player1.hp -= player2.dmg;
            cout << player2.name << " deals " << player2.dmg << " damage to " << player1.name << endl;
            cout << player1.name << " HP: " << player1.hp << endl;
            cout << "==========================" << endl;


            int option;
            cout << "press 1 to continue or 2 to exit: ";
            cin >> option;
            system("clear");


            if (option == 2) {
                break;
            }
            

            if (player1.hp <= 0) {
                cout << player1.name << " has been defeated!" << endl;
                break;
            }
        }
    }
};

void Teams::Fight() {
    int team1Index = SelectPlayer(1);
    int team2Index = SelectPlayer(2);

    if (team1Index >= 0 && team1Index < Team1.size() && team2Index >= 0 && team2Index < Team2.size()) {
        Combat C;
        C.Fight(Team1[team1Index], Team2[team2Index]);
    }
    else {
        cout << "Invalid player index!" << endl;
    }
}

class Game{
public:
    void Start(){
        int gameoption;
        cout << "========== MENU ==========" << endl;
        cout << "1. Start" << endl;
        cout << "2. Exit" << endl;

        cout << "==========================" << endl;
        cin >> gameoption;
        system("clear");

        if(gameoption == 1){
            Teams T;
            T.AddToTeam1("John", 5, 100);
            T.AddToTeam1("Annie", 8, 200);
            T.AddToTeam1("Andrew", 3, 50);

            T.AddToTeam2("Angeline'a", 3, 50);
            T.AddToTeam2("Hairdresser", 3, 50);
            T.AddToTeam2("Tom", 3, 50);

            T.Team1[0].AddItem(Item("Koch P30L(Gun)", 10));
            T.Team1[1].AddItem(Item("Axe", 12));
            T.Team2[0].AddItem(Item("Bow", 7));
            T.Team2[2].AddItem(Item("Scissors", 5));

            T.ShowTeam(1);
            T.ShowTeam(2);
            cout << "do you want to FIGHT!?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            cout << "==========================" << endl;

            
            int yesno;
            cin >> yesno;
            system("clear");

            if(yesno == 1){
                T.Fight();

                
            }
            else{
                cout << "you have no enemies bye bye";
                
            }
            
            
        }

    }
};

int main() {
    Game G;
    G.Start();

    return 0;
}
