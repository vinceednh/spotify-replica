#include "user.h"


User::User(){
    followingCount = 0;
}

User::User(const string& userUsername, const string& userPassword) {
    username = userUsername;
    password = userPassword;
    followingCount = 0;
}

void User::Follow(Account& other){
    followingCount++;
    friendsPlaylist.push_back(other.getUsername());
}

const string& User::getAccountType() const{
    static const string userType = "User";
    return userType;
}

void User::DisplayProfile() const{
    cout << "\nProfile Information:" << endl;
    cout << "Username: " << username << endl;
    cout << "Follower Count: " << followerCount << endl;
    cout << "Following Count: " << followingCount << endl;
    DisplayLikedSongs();
}

int User::getFollowingCount() const{
    return followingCount;
}

const vector<string>& User::getLikedSongs() const{
    return likedSongs;
}

const vector<string>& User::getFriendsPlaylists() const{
    return friendsPlaylist;
}

const vector<string>& User::getSearchHistory() const{
    return searchHistory;
}

void User::setFollowingCount(int newFollowing){
    followingCount = newFollowing;
}

const string& User::getUsername() const {
    return username;
}

void User::setLikedSongs(const vector<string>& newLikedSongs) {
    likedSongs = newLikedSongs;
}

void User::DisplayLikedSongs() const {
    cout << "Liked Songs:" << endl;
    const vector<string>& likedSongs = getLikedSongs();

    for (const string& song : likedSongs) {
        cout << "- " << song << endl;
    }
}

void User::CreateNewAccount(const string &newUsername, const string &newPassword){
    setUsername(newUsername);
    setPassword(newPassword);
}