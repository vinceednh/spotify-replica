#include "account.h"
#include <iostream>

using namespace std;

Account::Account() : username(""), password(""), followerCount(0) {
}

Account::Account(const string& userUsername, const string& userPassword)
    : username(userUsername), password(userPassword), followerCount(0) {
}

void Account::Follow(Account& other) {
    followerCount++;
}

void Account::DisplayProfile() const {
    cout << "\nProfile Information:" << endl;
    cout << "Username: " << username << endl;
    cout << "Follower Count: " << followerCount << endl;
    if (!playlists.empty()) {
        cout << "Playlists:" << endl;
        for (const string& playlist : playlists) {
            cout << "- " << playlist << endl;
        }
    } else {
        cout << "No playlists available." << endl;
    }
}


//Getter Functions
const string& Account::getUsername() const {
    return username;
}

const string& Account::getPassword() const {
    return password;
}

int Account::getFollowerCount() const {
    return followerCount;
}

const string& Account::getAccountType() const {
    static const string accountType = "Unknown";
    return accountType;
}

const vector<string> &Account::getPlaylists() const {
    return playlists;
}

const vector<string> &Account::getUserGeneratedPlaylists() const {
    return userGeneratedPlaylists;
}

//Setter Functions
void Account::setUsername(const string& newUsername) {
    username = newUsername;
}

void Account::setPassword(const string& newPassword) {
    password = newPassword;
}

void Account::setFollowerCount(int count) {
    followerCount = count;
}

void Account::setPlaylists(const vector<string>& newPlaylists) {
    playlists = newPlaylists;
}

void Account::CreateNewAccount(const string& newUsername, const string& newPassword){
    setUsername(newUsername);
    setPassword(newPassword);
}

void Account::AddFriendPlaylist(const vector<string>& friendPlaylist) {
    for (const string& song : friendPlaylist) {
        playlists.push_back(song);
    }
}


//displaying histories using stack
void Account::displayHistory(const stack<string>& history) const{
    stack<string> tempHistory = history;
    while(!tempHistory.empty()){
        cout << "- " << tempHistory.top() << endl;
        tempHistory.pop();
    }
}

void Account::addToListeningHistory(const string& song){
    listeningHistory.push(song);
}

void Account::addToSearchHistory(const string& query){
    searchHistory.push(query);
}

void Account::addToRecentlyPlayed(const string& album){
    recentlyPlayed.push(album);
}

void Account::displayListeningHistory() const{
    cout << "Listening History:" << endl;
    displayHistory(listeningHistory);
}

void Account::displaySearchHistory() const{
    cout << "Search History:" << endl;
    displayHistory(searchHistory);
}

void Account::displayRecentlyPlayed() const{
    cout << "Recently Played Albums:" << endl;
    displayHistory(recentlyPlayed);
}