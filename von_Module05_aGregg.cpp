#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>


// Module 05/06 Assignment - A Vector of Names
// Author - Alex Gregg - 2/22/2019
//  Menu Prototyping for UG_GAME

//Assignment requirements:
/*
Vector of names is declared on line: 47
    #1 - Add a name     - Lines: 16 - 19    --Method: AddName(std::string input)
    #2 - Change a name  - Lines: 47 - 87    --Method: ReplaceName(std::string inpt)
    #3 - Remove a name  - Lines: 25 - 44    --Method: RemoveName(std::string input)
    #4 - List names     - Lines: 108 - 118  --Method: ShowNames()

    uses of each:
        #1  -   2 uses
        #2  -   1 uses
        #3  -   1 uses
        #4  -   2 uses
*/
//Program Logic Map
/*
BEGIN
    Start - int Main()
        Choice 1 - PlayMenu()
            Select 1 - AddName()
            Select 2 - SelectLoadout() -- Lines: 145-203
                SHOWS LOADOUTS - ShowNames()
                Choice 1 - plays game
                Choice 2 - AddName()
                Choice 3 - RemoveName()
                Choice 4 - ReplaceName()
            <-- Choice 5 - Back to last menu
            Select 3 - ShowNames()
        <-- Select 4 - Back to main menu
        Choice 2 - ....Options
END <-- Choice 3 - Stops program

*/

std::vector<std::string> names;             //To avoid confusion, This is where the vector of names is declared 

static void AddName(std::string input)      // Adds the new name to the names vector.                 #1 - Add a name
{
    names.push_back(input);
}

static void RemoveName(std::string input)   // Removes the name from the names vector.                #3 - Remove a name
{
    std::vector<std::string>::iterator iter;
    if(!names.empty())
    {
        std::cout << "Removing: " << input << std::endl;
        for(iter = names.begin(); iter != names.end(); iter++){
            
            if(*iter == input){
                names.erase(iter);
                break;
            }else if(iter == names.end()){
                std::cout << "Could not find that name." << std::endl;
            }else{
                continue;
            }
        }
    } else{
            std::cout << "There are no names to remove." << std::endl;
        }
}

static void ReplaceName(std::string inpt)   // Replaces the name in names with what the user desires. #2 - Change a name
{
    std::vector<std::string>::iterator iter;
    std::string replace;
    if(!names.empty())
    {
        for(iter = names.begin(); iter != names.end(); iter++){
            
            if(*iter == inpt){
                std::cout << "What would you like to replace the name with?(no spaces): ";
                std::cin >> replace;
                *iter = replace;
                break;
            }else if(iter == names.end()-1){
                std::cout << "Could not find that name." << std::endl;
                std::cout << "Would you like to add a name? (y or n): ";
                std::cin >> replace;
                if(replace == "y"){
                    std::cin.clear();
                    std::cout << "What name would you like to add? (no spaces): ";
                    std::cin >> replace;
                    names.push_back(replace);
                    break;
                }
            }else{
                continue;
            }
        }
    } else{
        std::cout << "Theres nothing to replace.." << std::endl;
        std::cout << "Would you like to add a name? (y or n): ";
        std::cin >> replace;
        if(replace == "y"){
            std::cin.clear();
            std::cout << "What name would you like to add? (no spaces): ";
            std::cin >> replace;
            names.push_back(replace);
        }
    }
    

}

int LettersInName(std::string inpt)         // Gets the number of letters in a name.                  #infinity - NotRequired
{
    int numLetters = 0;
    std::vector<std::string>::iterator iter;
    for(iter = names.begin(); iter != names.end(); iter++){
        if(*iter == inpt){
            numLetters = iter->size();
            break;
        }else if(iter == names.end() - 1){
            numLetters = 0;
        }
        else{
            continue;
        }
    }
    return numLetters;
}

static void ShowNames()                     // Displays all the names.                                #4 - List names
{
    std::vector<std::string>::iterator iter;
    if(!names.empty()){
        for(iter = names.begin(); iter != names.end(); iter++){
            std::cout <<"\t" << *iter << std::endl;
        }
    }else{
        std::cout << "\tThere are no players listed." << std::endl;
    }
        
}

int GetInput()                              // Gets input for the main menu.
{

    int inpt;

    std::cout << "UG_GAME MENU:" << std::endl;
    std::cout << "Play Game: \t0" << std::endl;
    std::cout << "Options: \t1" << std::endl;
    std::cout << "Quit Game: \t2" << std::endl;

    std::cin >> inpt;
    return inpt;
}

static void SelectLoadout()                 // Allows the user to select a Save Game
{
    std::string selection;
    std::vector<std::string>::iterator slIter;
    bool loadoutSelect = true;

    std::cout << "Player Loadouts:" << std::endl;
    ShowNames(); 
    std::cout << "Play a Loadout: \tNameOfLoadout" << std::endl;
    std::cout << "Create a Loadout: \tcreate" << std::endl;
    std::cout << "Delete a loadout: \tdelete" << std::endl;
    std::cout << "Rename a loadout: \trename" << std::endl;
    std::cout << "Back to menu: \t\tback" << std::endl;
    std::cin >> selection;
    system("CLS");
    while(loadoutSelect){
        if(selection == "create"){
            std::cin.clear();
            selection = "";

            std::cout << "What would you like to name this loadout? (no spaces): ";
            std::cin >> selection;
            AddName(selection);
            std::cout << "Game loadout: " << selection << " was created." << std::endl;
        }else if(selection == "delete"){
            std::cout << "Type the name of the loadout to delete\n(THEY WILL BE DELTED PERMANENTLY): ";
            std::cin >> selection;
            RemoveName(selection);
        }else if(selection == "rename"){
            std::cout << "What is the name of the loadout you wish to rename?: " << std::endl;
            std::cin.clear();
            std::cin >> selection;
            ReplaceName(selection);
        }else if(selection == "back"){
            break;
        }else{
            for(slIter = names.begin(); slIter != names.end(); slIter++){
                if(*slIter == selection){
                    std::cout << "Game starting...." <<std::endl;
                    break;
                }else if(slIter == names.end() -1){
                    std::cout << "Command not recognized" << std::endl;
                    break;
                }else{
                    continue;
                }
            }
        }
        std::cout << "Player Loadouts:" << std::endl;
        ShowNames(); 
        std::cout << "Play a Loadout: \tNameOfLoadout" << std::endl;
        std::cout << "Create a Loadout: \tcreate" << std::endl;
        std::cout << "Delete a loadout: \tdelete" << std::endl;
        std::cout << "Rename a loadout: \trename" << std::endl;
        std::cout << "Back to menu: \t\tback" << std::endl;
        std::cin >> selection;    
        system("CLS");
    }
    
}

static void PlayMenu()                      // Allows the player to decide if they want to start a new game or load a save
{
    int inpt = 0;
    std::string selection = "";
    bool playMenu = true;

    std::cout << "Start new game: \t0" << std::endl;
    std::cout << "Load a save: \t\t1" << std::endl;
    std::cout << "List Loadouts: \t\t2" << std::endl;
    std::cout << "Back to menu: \t\t3" << std::endl;
    std::cin >> inpt;
    system("CLS");
    while(playMenu){
        switch (inpt)
        {
            case 0:
                std::cin.clear();
                selection = "";
                std::cout << "What would you like to name this loadout? (no spaces): ";
                std::cin >> selection;
                AddName(selection);
                std::cout << "Game loadout: " << selection << " was created." << std::endl;
                std::cout << "Game starting....\n\n" << std::endl;
                break;
            case 1:
                SelectLoadout();
                break;
            case 2:
                std::cout << "Loadouts: " <<std::endl;
                ShowNames();
                break;
            case 3:
                std::cout << "Returning" << std::endl;
                playMenu = false;
                break;
            default:
                std::cout << "Input was not valid" << std::endl;
                break;
        }
        if(playMenu == false){
            break;
        }

        std::cout << "Start new game: \t0" << std::endl;
        std::cout << "Load a save: \t\t1" << std::endl;
        std::cout << "List Loadouts: \t\t2" << std::endl;
        std::cout << "Back to menu: \t\t3" << std::endl;
        std::cin >> inpt;
        
        system("CLS");
    }
    
}

int main()                                  // The start of the actual execution
{

    bool mainMenu = true;
    int choice = 0;
    
    AddName("Alex");
    AddName("Stihl");
    AddName("Someone");
    AddName("Triton");
    
    choice = GetInput();
    system("CLS");
    while(mainMenu){
        std::cout << std::endl;

        switch (choice)
        {
            case 0:
                PlayMenu();
                break;
            case 1:
                std::cout << "Sorry, at the moment there are no settings to change." << std::endl;
                break;
            case 2:
                std::cout << "Quitting..." << std::endl;
                mainMenu = false;
                break;
            default:
                break;
        }
        if(mainMenu == false){
            break;
        }
        std::cout << "\n\n";

        choice = GetInput();
        
        system("CLS");
    }

}