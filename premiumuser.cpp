#include "premiumuser.h"

Premiumuser::Premiumuser(const string& userUsername, const string& userPassword){
    username = userUsername;
    password = userPassword;
}

void Premiumuser::Follow(Account& other){
    followingCount++;
}

void Premiumuser::DisplayProfile() const{
    cout << "\nPremium User Profile Information:" << endl;
    cout << "Username: " << username << endl;
    cout << "Account Type: " << accountType << endl;
    cout << "Follower Count: " << followerCount << endl;
    cout << "Following Count: " << followingCount << endl;
    cout << "Listening Along: " << (listeningAlong ? "Yes" : "No") << endl;
    cout << "Offline Listening: " << (offlineListening ? "Yes" : "No") << endl;
    if (!playlists.empty()) {
        cout << "Playlists:" << endl;
        for (const string& playlist : playlists) {
            cout << "- " << playlist << endl;
        }
    } else {
        cout << "No playlists available." << endl;
    }
    DisplayLikedSongs();
}

const string& Premiumuser::getAccountType() const {
    return accountType;
}

bool Premiumuser::isListeningAlong() const {
    return listeningAlong;
}

bool Premiumuser::isOfflineListening() const {
    return offlineListening;
}

void Premiumuser::setListeningAlong(bool newListeningAlong) {
    listeningAlong = newListeningAlong;
}

void Premiumuser::setOfflineListening(bool newOfflineListening) {
    offlineListening = newOfflineListening;
}

void Premiumuser::ListeningAlongWithUsers(const string& otherUser){
    cout << username << " is now listening along with " << otherUser << endl;
}

const string& Premiumuser::getUsername() const {
    return username;
}

void Premiumuser::CreateNewAccount(const string &newUsername, const string &newPassword){
    setUsername(newUsername);
    setPassword(newPassword);
}

