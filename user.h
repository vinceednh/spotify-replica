#ifndef USER_H
#define USER_H

#include "account.h"
#include <vector>

class User : public Account{
protected:
    int followingCount;
    vector <string> likedSongs;
    vector <string> searchHistory;
    vector <string> friendsPlaylist;

public:
    User();
    User(const string& userUsername, const string& userPassword);
    virtual ~User() = default;

    virtual void Follow(Account& other) = 0;
    virtual void DisplayProfile() const = 0;


    // Getters
    int getFollowingCount() const;
    const vector <string>& getLikedSongs() const;
    const vector <string>& getFriendsPlaylists() const;
    const vector <string>& getSearchHistory() const;
    const string& getUsername() const override;
    const string& getAccountType() const override;

    // Setters
    void setFollowingCount(int newFollowing);
    void setLikedSongs(const vector<string>& newLikedSongs);

    virtual void CreateNewAccount(const string& newUsername, const string& newPassword) override;
    void DisplayLikedSongs() const;
};

#endif