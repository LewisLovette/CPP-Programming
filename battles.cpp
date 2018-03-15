//University Work for 'Old School Game'
//- will not compile without otherfiles from uni github.

//Section for battles
#include <string>
#include <climits>  //for INT_MAX limits - so can handle incorrect input
#include "Player_Class/player.cpp"
#include "Player_Class/fighter.cpp"
#include "Player_Class/enemy.cpp"
#include "Player_Class/player.hpp"
#include "Player_Class/fighter.hpp"
#include "Player_Class/enemy.hpp"
#include "libsqlite.hpp"
#include "Saving.h"
using namespace std;

void battleState(Fighter &player, Player &enemy){    //call by reference (&) so that object is not a copy.
    //Default Values
    int winner = 2, attack, enemyDamage, attackPhase = 1, battlesWon = 1; //default for relevant if, else-if, else statement
    player.setTimer(0); //as all classes get to choose first hit

    //Setting up interactions with database
    sqlite::sqlite db("./GameDb.sql");
    auto cur = db.get_statement();  //auto used as tables may have different types
    try{
        cur-> set_sql(" UPDATE tbl_PlayerStats SET plyst_battlesWon = ?"
                      " WHERE plyst_key = 1;" );
        cur-> prepare();
        cur-> step();
		
		sqlite::sqlite db3("./GameDb.sql"); //  Database connection
	
		auto cur3 = db3.get_statement();
	
        //So can select data
		cur3->set_sql("SELECT plyst_battlesWon "
					"FROM tbl_PlayerStats "
					"WHERE plyst_key = 1;"); 

	
		cur3->prepare();
	
		cur3->step(); // Looks at the first entry

        battlesWon = (int)cur3-> get_int(0);
    }catch( sqlite::exception e ){  // catch all sql issues
        cout << endl << e.what() << endl;
    }
    
    //Battle Loop
    while(player.getHP() > 0 and enemy.getHP() > 0){
        cout << endl << endl << endl << "-----------Attack Phase: " << attackPhase << "-----------" << endl;
        cout << "Your hp is: " << player.getHP() << "\t\tBattles Won: " << battlesWon << endl;
        cout << "Enemy hp is: " << enemy.getHP()  << endl << endl;

        if(player.getTimer() > 0){  //if charging attack cooldown
            attack = 2;
        }
        else{
            cout << "Press 1, 2, 3 or 4 to use an attack: " << endl;
            cin >> attack;

            //handles incorrect input as no error is thrown so try/catch wouldn't work.      
            if(cin.fail()){
                cin.clear(); // clear input buffer - means cin can be used correctly again.
                cin.ignore(INT_MAX, '\n'); //Ignores the last thing inputted
                cout << endl << "You can only enter numbers, try again." << endl;
                continue;
            }
        }
        
        //Section for different ability
        if(attack == 1){
            cout << "You attacked: " << enemy.getName() << endl;
            player.attack(enemy);   //Stati damage number for now

        }else if(attack == 2){
            cout << "You have selected your Power Attack:" << endl;
            player.powerAttack(enemy);

        }else if(attack == 3){
            cout << "Normal Attack: " << endl;
            player.attack(enemy);

        }else if(attack == 4){
            cout << "You have decided to exit this battle and so take 50 percent damage" << endl;
            player.takeDamage((int)(player.getHP()/2));
            winner = 3;
            break;

        }else{
            continue;   //For if error occures, restarts same phase.
        }

        //Health checks to determine who/if someone has won.
        if(enemy.getHP() <= 0){
            winner = 1;
            break;
        }
        if(player.getHP() <= 0){
            winner = 2;
            break;
        }

        //Enemy damage sections, scales with level.
        enemyDamage = 15 + enemy.getLevel()*5;
        player.takeDamage(enemyDamage);
        cout << endl << "You have taken " << enemyDamage <<" damage from: " << enemy.getName() << endl;

        attackPhase++;
    }

    //Walue of winner determines statement
    if(winner == 1){
        cout << endl << "Congratulations you have defeated: " << enemy.getName() << endl;
        player.gainEXP(50+(enemy.getLevel()*5));
        
        //Database Interaction to keep track of the number of battles won
        battlesWon++;

        sqlite::sqlite db("./GameDb.sql"); //set-up to update database to insert new value
        auto cur = db.get_statement();

        //to update value
        cur-> set_sql(" UPDATE tbl_PlayerStats SET plyst_battlesWon = ? " 
                      " WHERE plyst_key = 1;" );
        cur-> prepare();
        cur-> bind(1, battlesWon);
        cur-> step();

		sqlite::sqlite db2("./GameDb.sql"); //  Database connection
	
		auto cur2 = db2.get_statement();
	
		cur2->set_sql("SELECT plyst_battlesWon "
					"FROM tbl_PlayerStats "
					"WHERE plyst_key = 1;"); 

		cur2->prepare();
	
		cur2->step(); // Looks at the first entry

		//Test
        //cout << endl << cur2-> get_int(0) << endl;

    }else if(winner == 2){
        cout << endl << "You have been defeated by: " << enemy.getName() << endl;
    }
    else{
        cout << endl << "Here we see a CHICKEN in it's natural habitat" << endl;
    }

}

//For testing.
int main(){
    Fighter playTest("Lew");
    Player enemTest("Enemy");

    battleState(playTest, enemTest);

    return 0;
}