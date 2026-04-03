#include"../include/vaultfile.h"
#include<fstream>//for reading and writing files
#include<string>
#include <cstdio> //for rename
#include<cstdlib>//for getenv
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define CYAN    "\033[36m"  
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#include<iostream>
using namespace std;
//implementing the encrypt() function to encrypt file ie overridng the pure virtual function of lockable class
void vaultfile:: encrypt()
{
    //first we open the file
    fstream fileStream(filepath , ios::in | ios::out | ios::binary);
    //check if file is open
    if(!fileStream.is_open())
    {
        cout<<RED<<BOLD<<"Error opening file for encryption!"<<RESET<<endl;
        return;
    }
    cout<<"Encrypting file: "<<filename<<endl;
    //loginc for scrambling will go next
    char ch;
    char key='K';//simple key for XOR encryption
    //reading character byte by byte
    while(fileStream.get(ch))
    {
        ch^=key;
        //shifting the pointer once step back
        fileStream.seekp(-1, ios::cur);
        fileStream.put(ch);//put the scrambled character back to the file
        fileStream.seekg(fileStream.tellp());//ensure that get pointer is sync with put pointer
    }
    fileStream.close();
    //cout<<"File encrypted successfully!"<<endl;
}
//implementing the decrypt() function to decrypt the file
void vaultfile::decrypt()
{
    fstream fileStream(filepath, ios::in | ios::out | ios::binary);
    //CHECK IF FILE IS OPEN
    if(!fileStream.is_open())
    {
        cout<<RED<<BOLD<<"error opening file for decryption!"<<RESET<<endl;
        return;
    }
    cout<<"decrypting file: "<<filename<<endl;
    char ch;
    char key='K';//same key is used for decrypting
    while(fileStream.get(ch))
    {
        ch=ch^key;//xor operation to get original character
        fileStream.seekp(-1, ios::cur);
        fileStream.put(ch);//put the decrypted character back to the file
        fileStream.seekg(fileStream.tellp());//sync get pointer with put pointer
    }
    fileStream.close();
    //cout<<"file decrypted successfully!"<<endl;
}
//implementing the movevault() function to move the file to vault location
void vaultfile::movevault() {
    string home = getenv("HOME");
    string vaultPath = home + "/.kdvault_storage/" + filename;

    if (rename(filepath.c_str(), vaultPath.c_str()) == 0) {
       // cout << "File hidden in: " << vaultPath << endl;
       cout<<GREEN<<BOLD<<"File encrypted and hidden in kd vault "<<RESET<<endl;
        filepath = vaultPath; // Update the object's internal record
    } else {
        perror("Could not move to  kd vault");
    }
}
bool vaultfile::restorevault() {
    string home = getenv("HOME");
    string vaultPath = home + "/.kdvault_storage/" + filename;

    // rename() returns 0 on success
    if (rename(vaultPath.c_str(), filepath.c_str()) == 0) {
        return true; 
    } else {
        // We don't print perror here anymore because main.cpp handles the error message
        return false;
    }
}

