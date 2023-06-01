#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Gracz {
public:
    string name;
    int dmg;
    int hp;
     

    Gracz(string name, int dmg, int hp) : name(name), dmg(dmg), hp(hp){}
    

};


int main() {
    vector<Gracz> Team1;
    vector<Gracz> Team2;
    
    
    Team1.push_back(Gracz("Jan", 5, 100));
    Team1.push_back(Gracz("Anna", 8, 200));
    Team1.push_back(Gracz("Kamil", 3, 50));
    
    Team2.push_back(Gracz("Kamil", 3, 50));
    Team2.push_back(Gracz("Kamil", 3, 50));
    Team2.push_back(Gracz("Kamil", 3, 50));
    
        
        for(int i = 0;i < Team1.size();i++){
            cout << "name: " << Team1[i].name << endl;
            cout << "dmg: " << Team1[i].dmg << endl;
            cout << "hp: " <<Team1[i].hp << endl;
    }
        for(int i = 0;i < Team2.size();i++){
            cout << "name: " << Team2[i].name << endl;
            cout << "dmg: " << Team2[i].dmg << endl;
            cout << "hp: " <<Team2[i].hp << endl;
    }
    

    return 0;
}
