//
//  main.cpp
//  Areana
//
//  Created by Leo Ramzell on 2018-09-01.
//  Copyright © 2018 Leo Ramzell. All rights reserved.
//

#include <iostream>

using namespace std;

int main(){
    
    int weapon, plhp, enemy, enemyhp, stage, pldmg, enemydmg, multi, pldmg1 , enemymulti, block, potion, loot, pheal, hitchance, wdmg, rest, recover, enemydmgdeal, plhpmax, shieldhp, shieldblock, plpoison, wblock, poisondmg, wblockmulti, wblockdmg, wpoison, poisontick;
    
    char choise, omstart, tuto;
    srand(time(0));
    
    cout << "---------------------------------------" << endl;
    cout << "----------Welcome to the arena---------" << endl;
    cout << "-----This is where you fight or Die----" << endl;
    cout << "---------------------------------------" << endl;
    cout << "-Have you played this game before? Y/N-" << endl;
    cin >> tuto ;
    if (tuto == 'N' || tuto == 'n') {
        cout << "In this game your fight each enemy that appear infront of you until there no one left." << endl;
        cout << "First you pick a your weapon then you get to meet your enemy to fight." << endl;
        cout << " " << endl;
        cout << "In each fight you can do three actions: " << endl;
        cout << "Attack - You attack your enemy." << endl;
        cout << "Block - You bock the enemys attack and revocer some hp." << endl;
        cout << "Potion - Where you drink a potion and heal X hp." << endl;
        cout << " " << endl;
        cout << "Between each fight the crowd might find the fight entertaining and shout diffirent stuff and you will be rewarded depending of what they are saying." << endl;
    }
    
    do{
    shieldblock = 4;
    shieldhp = 5; //How amnt hits your shield can take
    plhpmax = 40; // player max hp
    plhp = 30; //Start hp
    stage = 0; // What difficulty
    potion = 2; // How many potions you start with

    cout << "---------------------------------------" << endl;
    cout << "-----------Pick your weapon------------" << endl;
    cout << "----(1)Axe---(2)Sword----(3)Daggers----" << endl;
    cout << "---(4)Posion dager---(5)Spike Shield---" << endl;
    cin >> weapon ;
            if (weapon == 1) { // Axe dmg (5-12)
                cout << "So you have picked the Axe." << endl;
                cout << "Its has high dmg but its hard to hit with." << endl;
                wdmg = 8;
                multi = 5;
            }
            else if (weapon == 2){ // Sword dmg (5-8)
                cout << "So you have picked the sword." << endl;
                cout << "Its has medium dmg but is more reliable weapon." << endl;
                wdmg = 4;
                multi = 5;
            }
            else if (weapon == 3){ // Daggers dmg (1-4)*2 aka (2-8)
                cout << "So you have picked the daggers." << endl;
                cout << "Its does the low amout of dmg but you have 2 of them." << endl;
                wdmg = 4;
                multi = 1;
            }
            else if (weapon == 4){ //Posinus dagger  dmg (1-4) + dot
                cout << "So you have picked the posion dager." << endl;
                cout << "Its does the low amout of dmg but its poisons your enemy each time hit them." << endl;
                wdmg = 4;
                multi = 1;
                plpoison = 0;
                poisontick = 0;
                wpoison = 0;
            }
            else if (weapon == 5){ //Spiked shield dmg (3-6) + (1-3) dmg block
                cout << "So you have picked the spike shield." << endl;
                cout << "Its does the low to medium amout of dmg but you have also block dmg." << endl;
                wdmg = 4;
                multi = 3;
                wblockdmg = 3;
                wblockmulti = 1;
            }
            else{ //If you pick no weapon you get no weapon and start to fight with fists (1-3)
                cout << "You have pick no weapon and choisen to fight bare handed." << endl;
                cout << "Good luck" << endl;
                wdmg = 3;
                multi = 1;
                
            }
    cout << " " << endl;
    cout << "You have 30 hp." << endl;
    cout << "You have " << potion << " potions." << endl;
    cout << " " << endl;
    
    do{  //Decides what enemies you would meet
    if (stage <= 2) //3 enemeis in stage 1
    {
        enemy = rand() % 2+1;
        if (enemy == 1) // Thief 15 hp 4-6 dmg
        {
            cout << "You see a Thief walking in to the arena " << endl;
            enemyhp = 15;
            enemydmg = 3;
            enemymulti = 4;
        }
        else if (enemy == 2) // Bandit 20hp 2-5 dmg
        {
            cout << "You see a Bandit walking in to the arena " << endl;
            enemyhp = 20;
            enemydmg = 4;
            enemymulti = 2;
        }
    }
    else if (stage <= 5 && stage > 2 && stage < 6) //3 enemies in stage 2 (Kan får problem)
    {
        enemy = rand() % 2+1;
        if (enemy == 1) // Bigger Bandit 24hp 8-11 dmg
        {
             cout << "You see a Bigger Bandit walking in to the arena " << endl;
            enemyhp = 24;
            enemydmg = 4;
            enemymulti = 8;
        }
        else if (enemy == 2) // Barb 30hp 7-10 dmg
        {
             cout << "You see a Barbarian walking in to the arena " << endl;
            enemyhp = 30;
            enemydmg = 4;
            enemymulti = 7;
        }
    }
    else if (stage <= 7 && stage > 5 && stage < 8) //2 enemies in stage 3
    {
        enemy = rand() % 2+1;
        if (enemy == 1) {
            cout << "You see a Gladiator walking out in to the arena" << endl; //Gladi 40hp 9-14 dmg
            enemyhp = 40;
            enemydmg = 6;
            enemymulti = 9;
        } else if (enemy == 2){
            cout << "You see a Knight walking out in to the arena" << endl;//knight 50hp 7-11 dmg
            enemyhp = 50;
            enemydmg = 5;
            enemymulti = 7;
        }
       
    }
    else
    {
        cout << "You have defeated all of your enemies you are the sole victor" << endl; //The player have won
        return 0;
    }
    cout << " " << endl;
            do
            {
                block = 0;
                cout << "So what do you do?" << endl;
                cout << "(A)ttack,(B)locking,(P)otion" << endl; // Choose what to do
                cin >> choise;
                cout << " " << endl;
                if (choise == 'A' || choise == 'a')
                {
                    pldmg = rand() % wdmg + multi; // How much dmg you would deal
                    
                    cout << "You try to attack your enemy" << endl;
                    cout << " " << endl;
                    if (weapon == 3) //The other dagger
                    {
                        pldmg1 = rand() % wdmg + multi;
                        pldmg = pldmg1 + pldmg;
                    }
                    if (weapon == 1)
                    {
                        hitchance = rand() % 10 +1;
                        if (hitchance <= 8) // 80% to hit
                        {
                            cout << "You feel the hit with your axe." << endl;
                            cout << " " << endl;
                        }
                        else // 20% to miss
                        {
                            cout << "You feel that your axe misses your enemy." << endl;
                            cout << " " << endl;
                            pldmg = pldmg - pldmg;
                        }
                    }
                    if (weapon == 4) {
                        if (poisontick == 0) { //Inc every other time
                             plpoison+= 2; //How much poison inc
                            poisontick++;
                        } else {
                            poisontick--;
                        }
                        poisondmg = plpoison;
                    }
                    if (weapon == 5) {
                        wblock = rand() % wblockdmg + wblockmulti;
                    }

                    cout << "You deal " << pldmg << endl;
                }
                else if (choise == 'B' || choise == 'b')
                {
                    if (shieldhp == 0) {
                        cout << "Your shield is broken.\nThey will repair it after the fight.\n";
                        cout << " " << endl;
                    } else {
                        cout << "You try to block the incoming attack" << endl;
                        cout << " " << endl;
                    }
                    
                }
                else if (choise == 'P' || choise == 'p')
                {
                    if (potion > 0)
                    {
                        cout << "You drink your potion." << endl;
                        pheal = rand() % 16 +15; // How much healing potions does (15-30hp)
                        cout << "You heal " << pheal << "hp." << endl;
                        cout << " " << endl;
                        plhp = plhp + pheal;
                        potion--;
                        cout << "You have " << potion << " potions left." << endl;
                    }
                    else //If you have no potions left
                    {
                        cout << "You have no potion, you idiot." << endl;
                        cout << " " << endl;
                    }
                }
                else
                {
                    cout << "You did nothing, nice job idiot." << endl;
                    cout << " " << endl;
                }
                enemydmgdeal = rand() % enemydmg + enemymulti; // How much the enemy does
        if (weapon == 5) {
             enemydmgdeal -= wblock;
            cout << "You block " << wblock << " dmg." << endl;
            if (wblock > enemydmgdeal) {
                enemydmgdeal = 0;
        }
        }
                if (choise == 'A' || choise == 'a')
                {
                        enemyhp = enemyhp - pldmg; //How much dmg the enemy takes
                    
                }
                else if (choise == 'B' || choise == 'b')
                {
                    if (shieldhp > 1) {
                        block = rand() % 7 +shieldblock; //How much dmg blocked (4-10)
                        cout << "You block " << block << " dmg";
                        recover = rand() % 5 +3; //How much health you recover (3-7)
                        cout << " and you recover " << recover << "hp." << endl;
                        plhp = plhp + recover;
                        shieldhp--;
                    } else if (shieldhp == 1)
                    {
                        block = rand() % 7 +shieldblock; //How much dmg blocked (4-10)
                        cout << "You block " << block << " dmg";
                        recover = rand() % 5 +3; //How much health you recover (3-7)
                        cout << " and you recover " << recover << "hp." << endl;
                        plhp = plhp + recover;
                        shieldhp--;
                        cout << "Your shield have been broken" << endl;
                    }
                    else
                    {
                        cout << "\n";
                    }
                }
                if (weapon == 4) {
                    cout << "The poison deals " << poisondmg << " dmg" << endl;
                    enemyhp = enemyhp - poisondmg;
                }
                if (block >= enemydmgdeal) // If you block more then dmg
                {
                    enemydmgdeal = 0;
                }
                else
                {
                    enemydmgdeal = enemydmgdeal - block;
                }
                
                
                cout << "You take " << enemydmgdeal <<  endl;
                cout << " " << endl;
                
                plhp = plhp - enemydmgdeal; //When you take dmg
                
                if (plhp >= plhpmax) //Caps you hp
                {
                    plhp = plhpmax;
                }
                cout << "Your hp " << plhp << endl;
                
                cout << "The enemys hp " << enemyhp << endl;
                cout << " " << endl;
                
                block = 0;
            } while (plhp > 0 && enemyhp > 0);
        
        if (plhp <= 0)
        {
        cout << "You have been defeated." << endl; // Shows when you die
        cout << " " << endl;
        }
       else if (enemyhp <= 0) //If you have won the battle
        {
            cout << "You have defeated your enemy." << endl;
            cout << " " << endl;

            loot = rand() % 150 +1; //Chance for loot
             cout << "You see if the crowd was entertained." << endl;
            cout << " " << endl;
            if (loot <= 50)
            {
                cout << "They were not entertained." << endl;
                cout << "You get nothing." << endl;
                cout << "You get more rest." << endl;
                rest = rand() % 5 + 5;
                cout << "You recover " << rest << "hp." << endl;
                cout << " " << endl;
            }
            else if (loot <= 75 && loot > 50) //You get a potion
            {
                cout << "You can hear them chant:" << endl;
                cout << "POTION!" << endl;
                cout << "POTION!" << endl;
                cout << "POTION!" << endl;
                cout << " " << endl;
                cout << "You see a big guy come to you and he gives you a red healing potion (you can tell it can heal you)" << endl;
                potion++;
                cout << " " << endl;
            }
            else if (loot <= 100 && loot > 75) //You weapon gets stronger by 1 dmg for ex. 4-6 becomes 5-7
            {
                cout << "You can hear them chant: " << endl;
                cout << "WEAPON! " << endl;
                cout << "WEAPON! " << endl;
                cout << "WEAPON! " << endl;
                cout << " " << endl;
                cout << "You see a big guy come out and signs you in to a dark room." << endl;
                cout << "In that room you can see a smith." << endl;
                cout << "The smith tells you that the crowed has chosen upgrade your weapon." << endl;
                cout << "The smith takes your weapon and upgrades its." << endl;
                cout << "Your weapon deals more damage." << endl;
                multi++;//Här blir ökar dmg
                if (weapon == 4) {
                    wpoison++;
                }
                if (weapon == 5) {
                    wblockmulti += 1;
                }
                cout << " " << endl;
            }
            else if (loot <= 125 && loot > 100)
            {
                cout << "You can hear them chant: " << endl;
                cout << "DOCTOR!\nDOCTOR!\nDOCTOR!\n";
                cout << "You see a big guy wave you in to a door.\nWhen you step in to the door you see a witch doctor.\nThen everything goes black.\nNext time you wake up you feel tougher.\n Your max hp has increase by 10.\n\n";
                plhpmax = plhpmax + 10;
                plhp = plhp + 10;
            } else if (loot <= 150 && loot > 125)
            {
                 cout << "You can hear them shout: " << endl;
                cout << "SHIELD!\nSHIELD!\nSHIELD!\n";
                cout << "You see a big guy come out and signs you in to a dark room." << endl;
                cout << "In that room you can see a smith." << endl;
                cout << "The smith then takes your sheild and upgrades it.\n";
                cout << "Your shield can block damge now.\n";
                shieldblock = shieldblock +2;
            }
            if (weapon == 4) {
                plpoison = 0 + wpoison;
                poisontick = 0;
                poisondmg = 0;
            }
            shieldhp = 5;
            cout << "You have " << potion << " potions." << endl;
            cout << " " << endl;
            rest = rand() % 15 +10; //Heal after rest (15-25)
            cout << "You rest for a day.You healed " << rest << "hp." << endl;
            plhp = plhp + rest;
            if (plhp >= plhpmax)
            {
                plhp = plhpmax;
            }
            cout << "You have " << plhp << "hp left." << endl;
            cout << "Here comes the next one." << endl;
            cout << " " << endl;
            stage++; // Difficulty gets increast
        }

        } while (plhp > 0);
            cout << "You wanna try again: Y/N" << endl;
            cin >> omstart;
    }while (omstart == 'Y' || omstart == 'y');
    return 0;
        
}
