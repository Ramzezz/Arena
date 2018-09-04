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
    
    int weapon, plhp, enemy, enemyhp, stage, pldmg, enemydmg, multi, pldmg1 , enemymulti, block, potion, loot, pheal, hitchance, wdmg, rest, recover, enemydmgdeal, plhpmax;
    char choise, omstart;
    srand(time(0));

    do{
    weapon = 0;
    plhpmax = 40;
    plhp = 30; //Start hp
    stage = 1; // vilken nivå motståndarna är börjar med
    potion = 2; // Hur många potions du börjar med

    cout << "---Welcome to the arena player---" << endl;
    cout << "--------Pick your weapon---------" << endl;
    cout << "---1 Axe---2 Sword---3 Daggers---" << endl;
    cin >> weapon ;
    
    if (weapon == 1) { // yxans dmg
        cout << "So you have picked the Axe." << endl;
        cout << "Its has high dmg but its hard to hit with." << endl;
        wdmg = 5;
        multi = 5;
    }
    else if (weapon == 2){ // Svärds dmg
        cout << "So you have picked the sword." << endl;
        cout << "Its has avrage dmg but is more reliable weapon." << endl;
        wdmg = 3;
        multi = 4;
    }
    else if (weapon == 3){ // dolkarnas dmg
        cout << "So you have picked the daggers." << endl;
        cout << "Its does the least amout of dmg but you have 2 of them." << endl;
        wdmg = 3;
        multi = 1;
    }
    cout << "You have 30 hp." << endl;
    cout << "You have " << potion << " potions." << endl;
    cout << " " << endl;
    
    do{  //Bestämmer vilken typ av enemies du möter
    if (stage <= 2)
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
    else if (stage <= 4 && stage > 2 && stage < 5)
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
    else if (stage <= 5 && stage > 4 && stage < 6)
    {
        cout << "You see a Gladiator walking out in to the arena" << endl; //Gladi 40hp 5-9 dmg
        enemyhp = 40;
        enemydmg = 4;
        enemymulti = 5;
    }
    else
    {
        cout << "You have defeated all of your enemies you are the sole victor" << endl; //Spelaren har vunnit
        return 0;
    }
    cout << " " << endl;
    do
    {
        block = 0;
        cout << "So what do you do?" << endl;
        cout << "(A)ttack,(B)locking,(P)otion" << endl; // Välja vad du ska göra i fighten
        cin >> choise;
        cout << " " << endl;
        if (choise == 'A' || choise == 'a')
        {
            pldmg = rand() % wdmg + multi; // Hur dmg ditt vapen gör
            cout << "You try to attack your enemy" << endl;
            cout << " " << endl;
            if (weapon == 3) //Den andra dolken dmg
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
               cout << "You deal " << pldmg << endl;
        }
        else if (choise == 'B' || choise == 'b')
        {
                cout << "You try to block the incoming attack" << endl;
            cout << " " << endl;
        }
        else if (choise == 'P' || choise == 'p')
        {
            if (potion > 0)
            {
                cout << "You drink your potion." << endl;
                pheal = rand() % 16 +10; // Hur mycket potionen healar. (10-25hp)
                cout << "You heal " << pheal << "hp." << endl;
                cout << " " << endl;
                plhp = plhp + pheal;
                potion--;
                cout << "You have " << potion << " potions left." << endl;
            }
            else //Om du inte har några potions
            {
                cout << "You have no potion, you idoit." << endl;
                cout << " " << endl;
            }
        }
        enemydmgdeal = rand() % enemydmg + enemymulti; //Hur mycket fienden gör
        if (choise == 'A' || choise == 'a')
        {
            enemyhp = enemyhp - pldmg; //Hur mycket dmg motståndan tar
        }
      else if (choise == 'B' || choise == 'b')
        {
            block = rand() % 6 +5; //Hur mycket du blockerar (5-10)
            cout << "You block " << block << " dmg";
            recover = rand() % 2 +3; //När du blockerar får du hp. (3-4)
            cout << " and you recover " << recover << "hp." << endl;
            plhp = plhp + recover;
        }
        if (block >= enemydmgdeal)
        {
            enemydmgdeal = 0;
        }
        else
        {
            enemydmgdeal = enemydmgdeal - block;
        }
        cout << "You take " << enemydmgdeal <<  endl;
        cout << " " << endl;
        
        plhp = plhp - enemydmgdeal;
       
        if (plhp >= plhpmax)
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
        cout << "You have been defeated." << endl; // Visar när du har dött
        cout << " " << endl;
        }
       else if (enemyhp <= 0) //Om du har vunnit
        {
            cout << "You have defeated your enemy." << endl;
            cout << " " << endl;

            loot = rand() % 100 +1; //Chancen att få något
             cout << "You see if the crowed was entertained." << endl;
            cout << " " << endl;
            if (loot <= 40)
            {
                cout << "They were not entertained." << endl;
                cout << "You get nothing." << endl;
                cout << " " << endl;
            }
            else if (loot <= 70 && loot > 40) //Du får en potion
            {
                cout << "You can hear them shout:" << endl;
                cout << "POTION!" << endl;
                cout << "POTION!" << endl;
                cout << "POTION!" << endl;
                cout << " " << endl;
                cout << "You see a big guy come to you and he gives you a red healing potion (you can tell it can heal you)" << endl;
                potion++;
                cout << " " << endl;
            }
            else if (loot <= 100 && loot > 70) //Vapnet blir stakare med 1 dmg t.ex. 4-6 blir 5-7
            {
                cout << "You can hear them shout: " << endl;
                cout << "SMITH! " << endl;
                cout << "SMITH! " << endl;
                cout << "SMITH! " << endl;
                cout << " " << endl;
                cout << "You see a big guy come out and sigh you in to a dark room." << endl;
                cout << "In that room you can see a smith." << endl;
                cout << "The smith tells you that the crowed has chosen upgrade your weapon." << endl;
                cout << "So the smith takes you weapon and upgrades its." << endl;
                cout << "Your weapon deals more damage." << endl;
                multi++;//Här blir ökar dmg
                cout << " " << endl;
            }
            else if (loot <= 25 && loot > 20)
            {
                cout << "You can hear them shout: " << endl;
                cout << "" << endl;
            }

            cout << "You have " << potion << " potions." << endl;
            cout << " " << endl;
            rest = rand() % 11 +10; //Heal after rest (10-20)
            cout << "You rest for a day.You healed " << rest << "hp." << endl;
            plhp = plhp + rest;
            cout << "You have " << plhp << "hp left." << endl;
            cout << "Here comes the next one." << endl;
            cout << " " << endl;
            stage++; //Ökar nivån till en svårare
            cout << stage << endl;
        }

        } while (plhp > 0);
        cout << "You wanna try again: Y/N" << endl;
        cin >> omstart;
    }while (omstart == 'Y' || omstart == 'y');
    return 0;
        
}
