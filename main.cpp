#include <iostream>
#include "account.h"
#include "freeuser.h"
#include "premiumuser.h"
#include "artist.h"

using namespace std;

// Function to prompt the user for account type choice
string promptForAccountTypeChoice() {
    cout << "Select your account type:" << endl;
    cout << "1. Free Account" << endl;
    cout << "2. Premium Account" << endl;
    cout << "3. Artist Account" << endl;

    int choice;
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    switch (choice) {
        case 1:
            return "Free";
        case 2:
            return "Premium";
        case 3:
            return "Artist";
        default:
            cout << "Invalid choice. Defaulting to Free Account." << endl;
            return "Free";
    }
}

// Function to create an account based on account type
Account* createAccount(const string& accountType, const string& username, const string& password) {
    if (accountType == "Free") {
        return new Freeuser(username, password);
    } else if (accountType == "Premium") {
        return new Premiumuser(username, password);
    } else if (accountType == "Artist") {
        return new Artist(username, password);
    } else {
        cout << "Invalid choice. Defaulting to Free Account." << endl;
        return new Freeuser(username, password);
    }
}

int main() {
    string userUsername;
    string userPassword;
    string anotherUsername;

    cout << "Enter your Username: ";
    cin >> userUsername;
    cout << "Enter your Password: ";
    cin >> userPassword;

    string initialAccountType = promptForAccountTypeChoice();
    Account* mainAccount = createAccount(initialAccountType, userUsername, userPassword);

    mainAccount -> DisplayProfile();
    cout << endl;


    Premiumuser Account1("evie", "");
    Freeuser Account2("emjelic", "");
    Artist Account3("Knock2", "");

    Account1.setPlaylists({"bangers", "untitled.2022", "add some spice into ur life", "study.pt2", "breathe", "lovesickness is a disease"});
    Account2.setPlaylists({"?!", "soft", "main"});
    Account3.setPlaylists({"ROOM2 EP", "niteharts"});
    
    //songs in playlist 1
    Account3.addSongToPlaylist("ROOM2 EP", "Make U SWEAT!");
    Account3.addSongToPlaylist("ROOM2 EP", "REWiND");
    Account3.addSongToPlaylist("ROOM2 EP", "gettin' hott");
    Account3.addSongToPlaylist("ROOM2 EP", "Are U Feelin Me");
    Account3.addSongToPlaylist("ROOM2 EP", "JUMP in");
    Account3.addSongToPlaylist("ROOM2 EP", "Rock Ur World");

    //songs in playlist 2
    Account3.addSongToPlaylist("nineharts", "Beam");
    Account3.addSongToPlaylist("nineharts", "Click");
    Account3.addSongToPlaylist("nineharts", "Nightrealm");
    Account3.addSongToPlaylist("nineharts", "Chamber");
    Account3.addSongToPlaylist("nineharts", "Aarena");
    Account3.addSongToPlaylist("nineharts", "2HEARTs");
    Account3.addSongToPlaylist("nineharts", "SPEAK up!");
    Account3.addSongToPlaylist("nineharts", "blind + desire");
    Account3.addSongToPlaylist("nineharts", "SAY");
    Account3.addSongToPlaylist("nineharts", "murdah");
    
    // Main Menu
    int choice;
    do {
        cout << endl << "Options:" << endl;
        cout << "1. Display Profile" << endl;
        cout << "2. Play a Song" << endl;
        cout << "3. Follow another account" << endl;
        cout << "4. Liked Songs" << endl;
        cout << "5. Friend's Playlist" << endl;
        cout << "6. Recently Played Albums" << endl;
        cout << "7. Search History" << endl;
        cout << "8. Listening History" << endl;
        cout << "9. Monthly Listeners (Artist Only)" << endl;
        cout << "10. Listening Along (Premium Only)" << endl;
        cout << "11. Offline Listening (Premium Only)" << endl;
        cout << "0. Exit" << endl;

        cout << endl << "Enter the number for the action you'd like to perform: ";
        cin >> choice;


        switch (choice){
            case 1:
                mainAccount-> DisplayProfile();
                break;
            case 2:{
                cout << "Select a playlist from an artist or other (KNOCK2//other):" << endl;
                string artistOption;
                cin >> artistOption;

                if (artistOption == "KNOCK2"){
                    cout << "Select 'ROOM2 EP' or 'nineharts' to choose a list of songs." << endl;
                    string playlistOption;
                    cin.ignore();
                    getline(cin, playlistOption);

                    if (playlistOption == "ROOM2 EP" || playlistOption == "nineharts"){
                        const vector<string>& songs = Account3.getPlaylistSongs(playlistOption);
                        
                        cout << "Available songs in playlist '" << playlistOption << "':" << endl;
                        for (size_t i = 0; i < songs.size(); ++i){
                            cout << i + 1 << ". " << songs[i] << endl;
                        }

                        cout << "Enter the number of the song you want to play: " << endl;
                        size_t selectedSongIndex;
                        cin >> selectedSongIndex;
                        if (selectedSongIndex > 0 && selectedSongIndex <= songs.size()){
                            const string& selectedSong = songs[selectedSongIndex - 1];
                            cout << "Now Playing: '" << selectedSong << "' by KNOCK2" << endl;
                            mainAccount->addToRecentlyPlayed(playlistOption);
                            mainAccount->addToListeningHistory(selectedSong);
                        } else{
                            cout << "Invalid song number. Please enter a valid number" << endl;
                        }
                    } else{
                        cout << "Invalid playlist option. Please enter a valid option" << endl;
                    }

                } else if (artistOption == "other"){
                    cout << "Enter the name of the song: " << endl;
                    string songName;
                    cin.ignore();
                    getline(cin, songName);

                    cout << "Enter the name of the artist: " << endl;
                    string artistName;
                    getline(cin, artistName);

                    cout << "Now Playing: '" << songName << "' by " << artistName << endl;
                    mainAccount->addToListeningHistory(songName);
                    mainAccount->addToSearchHistory(songName);
                } else{
                    cout << "Invalid option. Please enter a valid option" << endl;
                }
            }
                break;
            case 3:{ //FOLLOW
                cout << "Enter the username of the account you would like to follow, (evie, emjelic, or KNOCK2): ";
                cin >> anotherUsername;

                if (anotherUsername == "evie"){
                    mainAccount->Follow(Account1);
                } else if (anotherUsername == "emjelic"){
                    mainAccount->Follow(Account2);
                } else if (anotherUsername == "Knock2"){
                    mainAccount->Follow(Account3);
                } else {
                    cout << "Invalid username. Please enter a valid username." << endl;
                    break;
                }

                cout << mainAccount->getUsername() << " is now following " << anotherUsername << endl;
                }
                break;

            case 4:{
                User* userAccount = static_cast<User*>(mainAccount);

                if (userAccount) {
                    const vector<string>& likedSongs = userAccount->getLikedSongs();

                    for (const string& song : likedSongs) {
                        cout << song << endl;
                    }

                    cout << "Enter the name of a song you'd like to add to your likes: ";
                    vector<string> newLikedSongs;
                    string songName;
                    while (cin >> songName && songName != "done"){
                        newLikedSongs.push_back(songName);
                        mainAccount->addToSearchHistory(songName);
                        cout << "Enter another song (type 'done' to finish): ";
                    }

                    userAccount->setLikedSongs(newLikedSongs);
                    cout << "Liked songs updated." << endl;
                } else {
                    cout << "Current account is not a User-type account." << endl;
                }
                
                break;
            }

            case 5:{ // FRIEND PLAYLISTS
                cout << "Enter the username of the account (evie/emjelic/KNOCK2): ";
                cin >> anotherUsername;

                Account* friendAccount = nullptr;

                if (anotherUsername == "evie") {
                    friendAccount = &Account1;
                } else if (anotherUsername == "emjelic") {
                    friendAccount = &Account2;
                } else if (anotherUsername == "KNOCK2") {
                    friendAccount = &Account3;
                } else {
                    cout << "Invalid username. Please enter a valid username." << endl;
                    break;
                }

                const vector<string>& playlists = friendAccount->getPlaylists();
                cout << "Available playlists for " << friendAccount->getUsername() << ":" << endl;
                
                for (size_t i = 0; i < playlists.size(); ++i) {
                    cout << i + 1 << ". " << playlists[i] << endl;
                }

                cout << "Do you want to add a playlist from " << friendAccount->getUsername() << "? (yes//no): ";
                string playlistOption;
                cin >> playlistOption;

                if (playlistOption == "yes") {
                    cout << "Enter the number of the playlist you want to add: ";
                    size_t selectedPlaylistIndex;
                    cin >> selectedPlaylistIndex;

                    if (selectedPlaylistIndex > 0 && selectedPlaylistIndex <= playlists.size()) {
                        const string& selectedPlaylist = playlists[selectedPlaylistIndex - 1];
                        mainAccount->AddFriendPlaylist({selectedPlaylist});
                        mainAccount->addToListeningHistory({selectedPlaylist});
                        cout << "Playlist added to your playlists." << endl;
                    } else {
                        cout << "Invalid playlist number. Please enter a valid number." << endl;
                    }
                } else if (playlistOption == "no") {
                    cout << "No playlist added." << endl;
                } else {
                    cout << "Invalid option. Please enter 'yes' or 'no'." << endl;
                }
                break;
            }
            case 6:
                mainAccount->displayRecentlyPlayed();
                break;
            case 7:
                mainAccount->displaySearchHistory();
                break;
            case 8:
                mainAccount->displayListeningHistory();
                break;
            case 9:
                if (mainAccount-> getAccountType() == "Artist") {
                    Artist* artistAccount = dynamic_cast<Artist*>(mainAccount);
                    int randomListeningCount = rand() % 100000000;
                    artistAccount->setMonthlyListeners(randomListeningCount);

                    cout << "Your Monthly Listening: " << randomListeningCount << endl;
                } else {
                    cout << "Invalid choice. This option is only available for Artist accounts." << endl;
                }
                break;
            case 10:
                if (mainAccount-> getAccountType() == "Premium") {
                    string listeningAlongOption;
                    do{
                        cout << "Do you want to start listening along? (yes/no): " << endl;
                        cin >> listeningAlongOption;

                        if (listeningAlongOption == "yes"){
                            Premiumuser* premiumAccount = static_cast<Premiumuser*>(mainAccount);
                            premiumAccount->setListeningAlong(true);
                            cout << "Listening along is now enabled" << endl;
                        } else if (listeningAlongOption == "no"){
                            cout << "Listening along disabled" << endl;
                        } else{
                            cout << "Invalid option. Please enter 'yes' or 'no'." << endl;
                        }
                    } while (listeningAlongOption != "yes" && listeningAlongOption != "no");
                } else {
                    cout << "Invalid choice. This option is only available for Premium accounts." << endl;
                }
                break;
            case 11:
                if (mainAccount-> getAccountType() == "Premium") {
                    string offlineListeningOption;
                    do{
                        cout << "Do you want to start offline listening? (yes/no): " << endl;
                        cin >> offlineListeningOption;

                        if (offlineListeningOption == "yes"){
                            Premiumuser* premiumAccount = static_cast<Premiumuser*>(mainAccount);
                            premiumAccount->setOfflineListening(true);
                            cout << "Listening along is now enabled" << endl;
                        } else if (offlineListeningOption == "no"){
                            cout << "Listening along disabled" << endl;
                        } else{
                            cout << "Invalid option. Please enter 'yes' or 'no'." << endl;
                        }
                    } while (offlineListeningOption != "yes" && offlineListeningOption != "no");
                } else {
                    cout << "Invalid choice. This option is only available for Premium accounts." << endl;
                }
                break;

            case 0:
                // Exit the program
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 0 and 7." << endl;
        }

    } while (choice != 0);

    return 0;

}