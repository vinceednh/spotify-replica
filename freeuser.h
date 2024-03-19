#ifndef FREEUSER_H
#define FREEUSER_H
#include "user.h"

class Freeuser : public User{
private:
    string advertisement;
    string accountType = "Free";

public:
    Freeuser(const string& userUsername, const string& userPassword);
    virtual ~Freeuser() = default;
    void Follow(Account& other) override;
    void DisplayProfile() const override;
    void DisplayAdvertisement() const;
    virtual void CreateNewAccount(const string& newUsername, const string& newPassword) override;


    //Getters
    const string& getAdvertisement() const;

    //Setters
    void setAdvertisement(const string& newAdvertisement);

    const string& getUsername() const override;
    const string& getAccountType() const override;
    
};


#endif