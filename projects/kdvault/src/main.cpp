#include "../include/vaultfile.h"
#include <string>
#include <iostream>
#include <filesystem>
#include <cstdlib> 
//adding these headers for colours
#define RED "\033[31m"
#define GREEN "\033[32m"
#define CYAN "\033[36m"
#define BOLD  "\033[1m"
#define RESET "\033[0m"
using namespace std;
namespace fs = std::filesystem;
void listVault() {
    string home = getenv("HOME");
    string path = home + "/.kdvault_storage/";
    
    cout << CYAN << BOLD << "\n      *** Files currently in Kd vault ***" << RESET << endl;
    if (fs::exists(path)) {
        for (const auto& entry : fs::directory_iterator(path)) {
            cout << "-> " << entry.path().filename().string() << endl;
        }
    } else {
        cout <<RED<<BOLD <<"Vault is empty or not initialized." <<RESET<< endl;
    }
    cout << "               **************" << endl;
}
int main(int argc, char* argv[]) 
{
    // Capture the folder where the user was when they ran the script
    // This is passed from kd.sh as $(pwd)
    string launchDir = (argc > 1) ? argv[1] : ".";
    string name, inputPath;
    int choice;
    cout << CYAN << BOLD << "              KD-VAULT TERMINAL      " << RESET<<endl;
    cout << "1. Lock a new file (Encrypt & Hide)\n2. Unlock a file (Show Vault & Restore)\nChoice: ";
    cin >> choice;
    cin.ignore(); 

    if (choice == 1) {
        cout << "Enter  the path of file you want to send to kd vault: ";
        getline(cin, inputPath);
        fs::path p(inputPath);

        // If the path is relative (like ./file.txt), join it with the launch directory
        if (p.is_relative()) {
            p = fs::path(launchDir) / p;
        }

        string filename = p.filename().string();
        string fullPath = p.string();

        cout << "FILE PATH: " << fullPath << endl;

        vaultfile v1(filename, fullPath);
        v1.encrypt();
        v1.movevault();
    }
    else if (choice == 2) {
        listVault(); 
        cout << "Enter the filename to unlock from the kd vault: ";
        getline(cin, name);
        
        // Determine the destination
        fs::path restoreDestination = fs::path(launchDir) / name;
        
        // Initialize the object
        vaultfile v1(name, restoreDestination.string());
        
        // ONLY proceed if the restoration actually works
        if (v1.restorevault()) { 
            v1.decrypt();         
            cout << GREEN << BOLD << "Success: File is now restored to: " << RESET << restoreDestination.string() << endl;
        } else {
            // If restorevault returns false, we dont  try to decrypt or show success
            cout << RED << BOLD << " Error: Could not find '" << name << "' in the vault." << RESET << endl;
        }

    } else {
        cout << RED << BOLD << "Invalid selection." << RESET << endl;
    }
    return 0;
}