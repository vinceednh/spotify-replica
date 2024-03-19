#include "freeuser.h"

Freeuser::Freeuser(const string& userUsername, const string& userPassword){
    username = userUsername;
    password = userPassword;
}

void Freeuser::Follow(Account& other){
    followingCount++;
}

void Freeuser::DisplayProfile() const {
    cout << "\nFree User Profile Information:" << endl;
    cout << "Account Type: " << accountType << endl;
    cout << "Username: " << username << endl;
    cout << "Followers: " << followerCount << endl;
    cout << "Following: " << followingCount << endl;
    if (!playlists.empty()) {
        cout << "Playlists:" << endl;
        for (const string& playlist : playlists) {
            cout << "- " << playlist << endl;
        }
    } else {
        cout << "No playlists available." << endl;
    }
    DisplayLikedSongs();
    DisplayAdvertisement();
}

const string& Freeuser::getAdvertisement() const {
    static const string advertisement = "Please give us your money :)";
    return advertisement;
}

void Freeuser::setAdvertisement(const string& newAdvertisement) {
    advertisement = newAdvertisement;
}

void Freeuser::DisplayAdvertisement() const{
    cout << "Ad Break: " << getAdvertisement() << endl;
}

const string& Freeuser::getAccountType() const {
    return accountType;
}

const string& Freeuser::getUsername() const{
    return username;
}

void Freeuser::CreateNewAccount(const string &newUsername, const string &newPassword){
    setUsername(newUsername);
    setPassword(newPassword);
}