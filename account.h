#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cstdlib>
using namespace std;



class Account {

protected:
    string username;
    string password;
    string accountType;
    int followerCount;
    vector <string> playlists;
    vector <string> userGeneratedPlaylists;
    stack <string> listeningHistory;
    stack <string> searchHistory;
    stack <string> recentlyPlayed;
    void displayHistory(const stack<string>& history) const;



public:
    Account();
    Account(const string &userUsername, const string &userPassword);
    // Virtual
    virtual ~Account() = default;
    virtual void Follow(Account& other);
    virtual void DisplayProfile() const;
    virtual const string& getUsername() const = 0;
    virtual const string& getAccountType() const = 0;

    // Member Functions
    
    void AddFriendPlaylist(const vector <string>& friendPlaylist);
    void addToListeningHistory(const string& song);
    void addToSearchHistory(const string& query);
    void addToRecentlyPlayed(const string& album);
    void displayListeningHistory() const;
    void displaySearchHistory() const;
    void displayRecentlyPlayed() const;



    //Initializing Getter
    const string& getPassword() const;
    int getFollowerCount() const;
    const vector <string>& getPlaylists() const;
    const vector <string>& getUserGeneratedPlaylists() const;

    //Initializing Setters
    void setUsername(const string& newUsername);
    void setPassword(const string& newPassword);
    void setFollowerCount(int newFollowwer);
    void setPlaylists(const vector<string>& newPlaylists);

    virtual void CreateNewAccount(const string& newUsername, const string& newPassword) = 0;

};

#endif