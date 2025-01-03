#include<iostream>
#include<string>
#include <iomanip>
#include<cstdlib>
#include<ctime>

using namespace std;

// Function to display the introduction
void intro () {
    cout <<"Welcome to Test Adventure Game 2.0" << endl;

    cout<<"|￣￣￣￣￣￣￣|" <<endl ;
    cout<<"|   Welcome    |" <<endl ;
    cout<<"|  To My Game  |" <<endl ;
    cout<<"|______________|" <<endl ;
    cout<<"(\\__/) ||" <<endl;
    cout<<"(^_-)   ||" <<endl;
    cout<<"/   づ   ||" <<endl ;
    cout<<"z(_(\")(\") ||" <<endl;

    cout <<"This game depends on the choices you make." << endl;
    cout <<"Good Luck!!" << endl;
}

// Function to handle game over logic
void gameOver (bool & playAgain) {
    cout <<"Game Over! Do you want to try again? \n y : Yes \n n : No" << endl;

    char choice;
    cin >> choice;

    // Validate the user's input
    while(true) {
        if(choice == 'y' ) {
            playAgain = true;
            break;
        } else if (choice == 'n' ) {
            cout <<"Thanks for playing!" << endl;
            playAgain = false;
            break;
        } else {
            cout <<"Invalid input. Please try again and choose between (y / n)." << endl;
            cin >> choice; // Correct input must be taken again
        }
    }
}

// Function to display the player's inventory
void displayInventory(string inventory[], int inventoryCount) {
    if(inventoryCount == 0) {
        cout<<"Your inventory is empty." << endl;
    } else {
        cout <<"Inventory: " << inventoryCount << " items" << endl;
        for(int i = 0 ; i < inventoryCount ; i++) {
            cout << inventory[i] << endl;
        }
    }
}

// Function to start the game
void startGame(bool &playAgain, bool &hasSword, bool &hasPotion, bool &hasArmor, bool &hasGem) {
    int health = 100; // Player's initial health
    const int max_Inventory = 5; // Maximum number of items in inventory
    int inventoryCount = 0; // Current count of inventory items
    string inventory[max_Inventory]; // Array to store inventory items
    srand(time(0)); // Seed the random number generator

    intro(); // Display the introduction

    cout << "You're standing in front of an eerie forest. You decide to \n 🌲🌲🌲🌲🌲🌲🌲🌲🌲🌲🌲🌲🌲🌲🌲 \n1 : Enter the forest \n2 : Look around the forest \n3 : Stay where you are \n4 : Go back home" << endl;
    
    int choose;
    cin >> choose;

    while (true) {
        if (choose == 1) {
            cout << "You enter the eerie-looking forest. Suddenly you feel a bit cold, and as soon as you react, a beast attacks you." << endl;
            
            cout<<" ()" <<endl ;
            cout<<"(.       )" <<endl ;
            cout <<"((((((()))))"<<endl;
            cout<<"|  o    o  |"<<endl ;
            cout<<" (.          ) "<<endl;
            cout <<" (    '  _ ' )" <<endl ;
            cout <<"/\\      / \\"<<endl ;
            cout<<" (_\\___/_)" <<endl ;
            cout <<" /       \\" <<endl ;
                   
            cout << "Do you want to: \n1 : Run \n2 : Check your inventory" << endl;

            int Do;
            cin >> Do;

            if (Do == 1) {
                cout << "As soon as you saw the beast, you ran away but got injured." << endl;
                health -= rand() % 81 + 20; // Reduce health randomly between 20 and 100
                cout << "Health: " << health << endl;

            } else if (Do == 2) {
                if (hasSword) {
                    cout << "You parried the beast's attack and injured it heavily. The beast ran away." << endl;
                    cout << "Do you want to look around and search the beast's lair?  \n3 : Yes \n4 : No" << endl;

                    int look;
                    cin >> look;

                    if (look == 3) {
                        cout << "You go into the beast's lair and find a potion." << endl;
                        displayInventory(inventory, inventoryCount);
                        if (inventoryCount < max_Inventory) {
                            inventory[inventoryCount++] = "Potion"; // Add potion to inventory
                            cout << "\" "<<inventoryCount <<" \" :"  << "Potion added to your inventory." << endl;
                            hasPotion = true;

                            cout << "Do you want to continue exploring the eerie forest? \n1 : Yes  \n2 : No" << endl;

                            int exploring;
                            cin >> exploring;

                            if (exploring == 1) {
                                cout << "You continue venturing deeper into the forest. The sound of water splashing catches your attention. Curious, you follow the noise and discover a beautiful riverbank. \n 🌊 🌊 🌊 🌊 🌊🌊🌊🌊🌊🌊🌊 \nAs you explore further, you stumble upon a suit of armor." << endl;
                                if (inventoryCount < max_Inventory) {
                                    inventory[inventoryCount++] = "Armor"; // Add armor to inventory
                                    cout << "\" "<<inventoryCount <<" \" :" << "Armor added to your inventory." << endl;
                                    hasArmor = true;
                                    if (hasArmor) {
                                        displayInventory(inventory, inventoryCount);
                                        health += 30; // Increase health with armor
                                        cout << "Health: " << health << endl;
                                    }
                                } else {
                                    cout <<"Your inventory is full" <<endl ;
                                }
                            } else if (exploring == 2) {
                                cout << "You're too tired to look around, so you decide to stay where you are." << endl;
                            }
                        }
                    } else if (look == 4) {
                        cout << "You're too tired to look around the lair and decide to leave." << endl;
                    }
                } else {
                    cout << "You didn't have anything to defend yourself with and got injured." << endl;
                    health -= rand() % 81 + 25; // Reduce health
                    cout << "Health: " << health << endl;
                }
            } else {
                cout << "Invalid input. Please choose between (1 / 2)." << endl;
                continue; // Restart the loop for invalid input
            }
        } else if (choose == 2) {
            cout << "You don't feel like venturing into the eerie forest, so you decide to look around the forest. Suddenly, you stumble upon a sword." << endl;
            if (inventoryCount < max_Inventory) {
                inventory[inventoryCount++] = "Sword"; // Add sword to inventory
                displayInventory(inventory, inventoryCount);
                cout << "\" "<<inventoryCount <<" \" :" <<"Sword added to your inventory." << endl;
                hasSword = true;
            } else {
                cout << "Your inventory is full." << endl;
            }
        } else if (choose == 3) {
            cout << "You're too tired to move, so you decide to stay where you are. While sleeping, \n💤💤💤 \nyou wake up sensing something. Oh no! It's a poisonous snake." << endl;
            
            cout <<"   \\/" <<endl;
            cout <<"    |" <<endl ;
            cout<<"   __  " <<endl ;
            cout <<"  /x x\\" <<endl ;
            cout <<" /     \\"<<endl ;
            cout <<" |.    | "<<endl ;
            cout <<"  \\   /" <<endl ; 
            
            cout << "You decide: \n1 : Run away \n2 : Jump" << endl;

            int decide;
            cin >> decide;

            if (decide == 1) {
                cout << "You try to run away from the snake, but it's too late. The snake bites you, and you got poisoned." << endl;
                health -= rand() % 86 + 15; // Reduce health
                cout << "Health: " << health << endl;
            } else if (decide == 2) {
                cout << "As soon as you feel the snake, you jump and attack it." << endl;
                cout << "Health: " << health << endl; // No health loss
            } else {
                cout << "Invalid input. Please try again and choose between (1 / 2)." << endl;
                continue;
            }
        } else if (choose == 4) {
            cout << "You decide to go back home.  \n 🏠🏠🏠 \nBut on the way, you got lost and then meet a stranger who gives you a gem. After that, you find your way home." << endl;
            if (inventoryCount < max_Inventory) {
                inventory[inventoryCount++] = "Gem"; // Add gem to inventory
                displayInventory(inventory, inventoryCount);
                cout << "Gem added to your inventory." << endl;
                hasGem = true;
                if (hasGem) {
                    health += 5; // Increase health
                    cout << "Health: " << health << endl;
                }
                displayInventory(inventory, inventoryCount);
                gameOver(playAgain); // End the game
                break;
            } else {
                cout<<"Your inventory is full" <<endl ;
            }
        } else {
            cout << "Invalid input. Please try again and choose a valid option (1-4)." << endl;
            continue ;
        }

        if (health <= 0) {
            cout << "You've lost all your health points (HP). Game Over!!" << endl;
            if (hasPotion) {
                health += 30; // Restore health with a potion
                cout << "Health: " << health << endl;
            }
            gameOver(playAgain);
            break;
        }

        // Loop prompt for further actions
        cout << "You're standing in front of an eerie forest. You decide to \n1 : Enter the forest \n2 : Look around the forest \n3 : Stay where you are \n4 : Go back home" << endl;
        cin >> choose;
    }
}

int main () {
    bool playAgain = true;
    bool hasSword = false;
    bool hasPotion = false;
    bool hasArmor = false;
    bool hasGem = false;
    cout <<"1 : Start \n2 : Exit" << endl; // Corrected "Exist" to "Exit"

    while (playAgain) {
        int option;
        cin >> option;

        if(option == 1) {
            startGame(playAgain, hasSword, hasPotion, hasArmor, hasGem);
        } else if (option == 2) {
            cout<<"Thanks for playing! Bye!" << endl;
            playAgain = false;
        } else {
            cout <<"Invalid input. Please try again and choose between (1 / 2)." << endl;
            continue ;
        }
    }
    return 0;
}