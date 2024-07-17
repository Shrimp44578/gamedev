#include <iostream>
#include <string>
using namespace std;

int turn_damage(void);

class player {
public:
    int health;
    int damage;
    int experience;
    int level;
    int damage_mod;
    int health_mod;

    int deal_damage() {
        int dealt_damage, rand_damage;
        rand_damage = turn_damage();
        dealt_damage = rand_damage + damage_mod;

        return dealt_damage;
    }
    
    int turn_damage() {
        srand((unsigned)time(NULL));  // Seed Gen
        int player_damage{};
        int player_damage_amt = 1 + (rand() % 90) ^ 2;  // Player Num Gen

        if (player_damage_amt <= 30)  // Player Damage Decider
        {
            player_damage = 10 - 2;
        }
        else if (player_damage_amt <= 60)
        {
            player_damage = 10;
        }
        else if (player_damage_amt < 90)
        {
            player_damage = 2 + 10;
        }
        else if (player_damage_amt == 90)
        {
            player_damage = 3 * 10;
        }

        return player_damage;

    }

    void enemy_dead(int experience_given) {
        int experience_till_nxt_lvl = level ^ 2;
        string mod_select;
        experience += experience_given;
        if (experience == experience_till_nxt_lvl) {
            level++;
            cout << "You have leveled up!\n";
            cout << "Enter\n";
            cout << "b for more damage\n";
            cout << "or n for more health\n";
            getline(cin, mod_select);
            cin.clear();
            if (mod_select == "b") {
                damage_mod++;
            }
            if (mod_select == "n") {
                health_mod++;
            }
            experience = 0;
        }

        if (experience > experience_till_nxt_lvl) {
            do {
                experience - experience_till_nxt_lvl;
                level++;
                cout << "You have leveled up!\n";
                cout << "Enter\n";
                cout << "b for more damage\n";
                cout << "or n for more health\n";
                getline(cin, mod_select);
                cin.clear();
                if (mod_select == "b") {
                    damage_mod++;
                }
                if (mod_select == "n") {
                    health_mod++;
                }
                experience_till_nxt_lvl = level ^ 2;
            } while (experience >= experience_till_nxt_lvl);
        }
    }
};

class enemy {
public:
    int health;
    int damage;
    int experience_given;
    int level;
};

player p1{
    p1.damage = 10,
    p1.experience = 0,
    p1.health = 100,
    p1.level = 1,
    p1.damage_mod = 0,
    p1.health_mod = 0
};

enemy boss{
    boss.damage = 10,
    boss.experience_given = 10,
    boss.health = 100,
    boss.level = 0
};

int player_health = 100;
int boss_health = 100;


int main() {
    int experience;
    int level;
    string ability;
    cout << "|---------" << boss_health << "---------|" << "\n\n\n\n";
    cout << "|---------" << player_health << "---------|" << "\n\n\n";
    for (size_t i = 0; i < 100; i++)
    {
        
        srand((unsigned)time(NULL) ^ 2); // Seed Gen
        int boss_damage;
        int boss_damage_amt = 1 + (rand() % 90); // Boss Num Gen

        cout << boss_damage_amt << endl;

        if (boss_damage_amt <= 30)  // Player Damage Decider
        {
            boss_damage = 8;
        }
        else if (boss_damage_amt <= 60)
        {
            boss_damage = 10;
        }
        else if (boss_damage_amt < 90)
        {
            boss_damage = 12;
        }
        else if (boss_damage_amt == 90)
        {
            boss_damage = 30;
        }


        getline(cin, ability);
        cin.clear();
        if (ability == "q") {               // Ability
            int x = p1.deal_damage();
            cout << x << endl;
            boss_health -= x;
            cout << "\n";
        }
        player_health -= boss_damage;
        cout << "|--------- " << boss_health << " ---------|" << "\n\n\n\n";
        cout << "|--------- " << player_health << " ---------|" << "\n\n";
    }
}
