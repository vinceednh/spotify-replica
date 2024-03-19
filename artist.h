#ifndef ARTIST_H
#define ARTIST_H
#include "account.h"
#include <map>

class Artist : public Account{
private:
    string username;
    int monthlyListeners;
    map<string, vector<string>> playlistSongs;
    string accountType = "Artist";

public:
    Artist();
    Artist(const string& artistUsername, const string& artistPassword);
    virtual ~Artist() = default;
    void Follow(Account& other) override;
    void DisplayProfile() const override;
    const string& getUsername() const override;
    const string& getAccountType() const override;
    virtual void CreateNewAccount(const string& newUsername, const string& newPassword) override;    
    const vector<string>& getPlaylistSongs(const string& playlist) const;


    //Getters
    const int& getMonthlyListeners() const;

    //Setters
    void setMonthlyListeners(int newMonthlyListeners);
    void addSongToPlaylist(const string& playlist, const string& song);
};

#endif