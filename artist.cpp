#include "artist.h"

Artist :: Artist(const string& userUsername, const string& userPassword){
    username = userUsername;
    password = userPassword;
    monthlyListeners = 0;
}

const string& Artist::getUsername() const {
    return username;
}

void Artist::Follow(Account& other){
    followerCount++;
}

void Artist::DisplayProfile() const{
    cout << "\nArtist Profile Information:" << endl;
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


//set

void Artist::setMonthlyListeners(int newMonthlyListeners) {
    monthlyListeners = newMonthlyListeners;
}

void Artist::addSongToPlaylist(const string& playlist, const string& song) {
    playlistSongs[playlist].push_back(song);
}


//get
const int& Artist::getMonthlyListeners() const {
    return monthlyListeners;
}

const string& Artist::getAccountType() const {
    return accountType;
}

void Artist::CreateNewAccount(const string &newUsername, const string &newPassword){
    setUsername(newUsername);
    setPassword(newPassword);
    accountType = "Artist";
}

const vector<string>& Artist::getPlaylistSongs(const string& playlist) const {
    return playlistSongs.at(playlist);
}