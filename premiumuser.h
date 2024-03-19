#ifndef PREMIUMUSER_H
#define PREMIUMUSER_H
#include "user.h"

class Premiumuser : public User {
private:
    bool listeningAlong;
    bool offlineListening;
    string accountType = "Premium";

public:
    Premiumuser(const string& userUsername, const string& userPassword);
    virtual ~Premiumuser() = default;
    void Follow(Account& other) override;
    void DisplayProfile() const override;
    void ListeningAlongWithUsers(const string& otherUser);
    const string& getUsername() const override;
    const string& getAccountType() const override;
    virtual void CreateNewAccount(const string& newUsername, const string& newPassword) override;


    //Getters
    bool isListeningAlong() const;
    bool isOfflineListening() const;

    //Setters
    void setListeningAlong(bool newListeningAlong);
    void setOfflineListening(bool newOfflineListening);
};

#endif