#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <windows.h>
#include <time.h>
using namespace std;

int main()
{
    //Defining all variables!
    string PlayerName;
    string Command;
    string CivName;
    string RandomName[15] {"gre","bo","han","nai","ast","fu","cha","en","li","uth","est","ar","a","ua","ph"};
    string RandomNameCap[15] {"Gre","Bo","Han","Nai","Ast","Fu","Cha","En","Li","Uth","Est","Ar","A","Ua","Ph"};
    int Gold = 0;
    int Wood = 0;
    int Food = 0;
    int Amount = 0;
    int TimeTilAttack = rand() % 30 + 120;
    int Pop = 0;
    int Miner = 0;
    int Logger = 0;
    int Farmer = 1;
    int Soldier = 0;
    int Wall;
    int Level = 0;
    int Defense = 0;
    int Attack = 0;
    bool IfIsCreator = false;
    //Actual game
    srand(time(NULL));
    cout << "Loading...\n"; //For theatrics
    Sleep(3000);
    cout << "\nWelcome to CmdCiv\n**Version 1.0**\n\n";
    Sleep(1000);
    cout << "What is your name? \n";
    cin >> PlayerName;
    cout << "What is the name of your civ? \n";
    cin >> CivName;
    cout << "Remember to read the manual\n";
    Sleep (1500);
    cout << "Starting Game...\n\n";
    Sleep(1000);
    cout << "Start!\n\n\n\n";
    Sleep (1000);
    //Game Loop
    while (true)
    {
        // "Clear" the screen
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

        Level = Pop/5+1;
        if (Food < 0)
        {
            Food = 0;
            Pop--;
        }
        if (Wood < 0)
        {
            Wood = 0;
        }
        if (Gold < 0)
        {
            Gold = 0;
        }
        if (TimeTilAttack > 0)
        {
            //Display Stats
            cout << CivName << "  Level: " << Level << "\n\n";
            cout << "Attack: " << Attack << "\n";
            cout << "Defense: " << Defense << "\n";
            cout << "Gold: " << Gold << "\n";
            cout << "Wood: " << Wood << "\n";
            cout << "Food: " << Food << "\n";
            cout << "Miner: " << Miner << "\n";
            cout << "Lumberjack: " << Logger << "\n";
            cout << "Farmer: " << Farmer << "\n";
            cout << "Soldier: " << Soldier << "\n";
            cout << "Population: " << Pop << "\n";
            cout << "Next attack in: " << TimeTilAttack << " seconds \n";
        }
        else
        {
            Command = RandomNameCap[rand() % 15] + RandomName[rand() % 15];
            Amount = ((rand() % 10)*Level + (rand() % 5));
           cout << CivName << " is being attacked by " << Command << "\n";
           Sleep(500);
           cout << "Battling...\n";
           Sleep(2000);
           if (Defense > Amount )
           {
                cout << CivName << " wins! " << Defense << "/" << Amount;
                Amount = ((rand() % 10 + 5) * Level + (rand() % 3));
                cout << "\nGain " << Amount << " food\n";
                Food += Amount;
                Amount = ((rand() % 10 + 5) * Level + (rand() % 3));
                cout << "Gain " << Amount << " wood\n";
                Wood += Amount;
                Amount = ((rand() % 5 + 2) * Level + (rand() % 3));
                cout << "Gain " << Amount << " gold\n";
                Gold += Amount;
           }
           else
           {
                cout << Command << " wins!" << Amount << "/" << Defense << "\nLose " << Amount << " food\n";
                Amount = ((rand() % 10 + 5) * Level + (rand() % 3));
                Food -= Amount;
                Amount = ((rand() % 10 + 5) * Level + (rand() % 3));
                cout << "Lose " << Amount << " wood\n";
                Wood -= Amount;
                Amount = ((rand() % 5 + 2) * Level + (rand() % 3));
                cout << "Lose " << Amount << " gold\n";
                Gold -= Amount;
           }
           TimeTilAttack = rand() % 120 + 60;
           cout << "Continue in 3 seconds";
           Sleep(3000);
        }

        if(GetAsyncKeyState(VK_SPACE) != 0)
        {
            cout << "\n"<< PlayerName << ":";
            cin >> Command;
            if (Command == "exit")
            {
                break;
            }
            else if (Command == "getFarmer")
            {
                cout << "\nHow Many? \n";
                cin >> Amount;
                if (Food >= Amount * 50)
                {
                    Farmer +=  Amount;
                    Food -= Amount*50;
                }
            }
            else if (Command == "getLogger")
            {
                cout << "\nHow Many? \n";
                cin >> Amount;
                if (Food >= Amount * 50)
                {
                    Logger +=  Amount;
                    Food -= Amount*50;
                }
            }
            else if (Command == "getMiner")
            {
                cout << "\nHow Many? \n";
                cin >> Amount;
                if (Food >= Amount * 50)
                {
                    Miner +=  Amount;
                    Food -= Amount*50;
                }
            }
            else if (Command == "getSoldier")
            {
                cout << "\nHow Many? \n";
                cin >> Amount;
                if (Food >= Amount * 50 && Wood >= Amount * 10)
                {
                    Soldier += Amount;
                    Food -= Amount*50;
                    Wood -= Amount*10;
                }
            }
            else if (Command == "getWall")
            {
                cout << "\nHow Many? \n";
                cin >> Amount;
                if (Wood >= Amount * 100)
                {
                    Wall += Amount;
                    Wood -= Amount*100;
                }
            }
            else if (Command == "sellFarmer")
            {
                cout << "\nHow Many? \n";
                cin >> Amount;
                if (Amount <= Farmer)
                {
                    Farmer -= Amount;
                    Food += Amount*25;
                }
            }
            else if (Command == "sellLogger")
            {
                cout << "\nHow Many? \n";
                cin >> Amount;
                if (Amount <= Logger)
                {
                    Logger -= Amount;
                    Food += Amount*25;
                }
            }
            else if (Command == "sellMiner")
            {
                cout << "\nHow Many? \n";
                cin >> Amount;
                if (Amount <= Miner)
                {
                    Miner -= Amount;
                    Food += Amount*25;
                }
            }
            else if (Command == "sellSoldier")
            {
                cout << "\nHow Many? \n";
                cin >> Amount;
                if (Amount <= Soldier)
                {
                    Soldier -= Amount;
                    Food += Amount*25;
                    Wood += Amount*5;
                }
            }
            else if (Command == "sellWall")
            {
                cout << "\nHow Many? \n";
                cin >> Amount;
                if (Amount <= Wall)
                {
                    Wall -= Amount;
                    Wood += Amount*50;
                }
            }
            else if (Command == "help")
            {
                cout << "\n.........................\n get - costs resource to \n purchase a worker. \n sell - gives back resource \n to sell a worker. \n You can get or sell \n Farmer \n Logger \n Miner \n Soldier \n Wall \n.........................\nType y to continue\n";
                cin >> Command;
            }
            else if (Command == "credits")
            {
                cout << "\nThis game was created by Shaun Wu\nas a programing exercise. \nType y to continue.\n";
                cin >> Command;
            }
            else if (Command == "Iamthecreator")
            {
                if (PlayerName == "Shaun")
                {
                    IfIsCreator = true;
                    Attack += 100000000;
                    Defense += 100000000;
                    Gold += 100000000;
                    Food += 100000000;
                    Wood += 100000000;
                }
                else
                {
                    cout << "\nYou are NOT the creator. Start back from scratch!\nType y to continue.";

                    Attack = 0;
                    Defense = 0;
                    Gold = 0;
                    Food = 0;
                    Wood = 0;
                    Farmer = 1;
                    Miner = 0;
                    Logger = 0;
                    Soldier = 0;
                    TimeTilAttack = 10;
                    cin >> Command;
                }
            }
            else if (Command == "attack")
            {
                         Command = RandomNameCap[rand() % 15] + RandomName[rand() % 15];
                    Amount = ((rand() % 10)*Level + (rand() % 5));
                   cout << CivName << " attacking " << Command << "\n";
                   Sleep(500);
                   cout << "Battling...\n";
                   Sleep(2000);
                   if (Attack > Amount)
                   {
                        cout << CivName << " wins! " << Defense << "/" << Amount;
                        Amount = ((rand() % 15 + 10) * Level + (rand() % 5));
                        cout << "\nGain " << Amount << " food\n";
                        Food += Amount;
                        Amount = ((rand() % 15 + 10) * Level + (rand() % 5));
                        cout << "Gain " << Amount << " wood\n";
                        Wood += Amount;
                        Amount = ((rand() % 20 + 5) * Level + (rand() % 3));
                        cout << "Gain " << Amount << " gold\n";
                        Gold += Amount;
                   }
                   else
                   {
                        cout << Command << " wins!" << Amount << "/" << Defense << "\nLose " << Amount << " food\n";
                        Amount = ((rand() % 10 + 5) * Level + (rand() % 3));
                        Food -= Amount;
                        Amount = ((rand() % 10 + 5) * Level + (rand() % 3));
                        cout << "Lose " << Amount << " wood\n";
                        Wood -= Amount;
                        Amount = ((rand() % 5 + 2) * Level + (rand() % 3));
                        cout << "Lose " << Amount << " gold\n";
                        Gold -= Amount;
                   }
                   TimeTilAttack = rand() % 120 + 60;
                   cout << "Continue in 3 seconds";
                   Sleep(3000);
            }
        }
        Food += Farmer*3 - Pop;
        Wood += Logger;
        Gold += Miner;
        if (IfIsCreator == false)
        {
            Defense = Soldier + Wall*10;
            Attack = Soldier;
        }
        Pop = Farmer + Logger + Miner + Soldier;
        TimeTilAttack--;
        Sleep(1000);
    }
    return Gold;
}
