//SOLUTION TWO: USING USER-DEFINED DATA TYPES
#include <iostream>
#include <vector>
using namespace std;

struct Song {
    string name;
    string singer;
    string genre;
    int year;
    float duration;
};

vector<Song> songs;
void addNewSong() {
    Song s;
    cout << "Enter song name: ";
    cin.ignore();
    getline(cin, s.name);
    cout << "Enter singer name: ";
    getline(cin, s.singer);
    cout << "Enter genre: ";
    getline(cin, s.genre);
    cout << "Enter year: ";
    cin >> s.year;
    cout << "Enter duration (in minutes): ";
    cin >> s.duration;

    songs.push_back(s);
    cout << "\n✅ Song added successfully!\n";
}
void viewAllSongs() {
    cout << "\n🎵 All Songs:\n";
    for (size_t i = 0; i < songs.size(); ++i) {
        cout << i + 1 << ". " << songs[i].name << endl;
    }
    if (songs.empty()) cout << "No songs available.\n";
}
void viewAllDetails() {
    cout << "\nSong Details:\n";
    for (const auto& s : songs) {
        cout << "--------------------------\n";
        cout << "Name: " << s.name << endl;
        cout << "Singer: " << s.singer << endl;
        cout << "Genre: " << s.genre << endl;
        cout << "Year: " << s.year << endl;
        cout << "Duration: " << s.duration << " minutes\n";
    }
    if (songs.empty()) cout << "No songs to display.\n";
}
void searchByYear() {
    int year;
    cout << "Enter year to search: ";
    cin >> year;
    bool found = false;
    for (const auto& s : songs) {
        if (s.year == year) {
            cout << "\n" << s.name << " by " << s.singer << endl;
            found = true;
        }
    }
    if (!found) cout << "No songs found from year " << year << ".\n";
}
void searchByName() {
    cin.ignore();
    string name;
    cout << "Enter song name to search: ";
    getline(cin, name);
    bool found = false;
    for (const auto& s : songs) {
        if (s.name == name) {
            cout << "\n" << s.name << " by " << s.singer << endl;
            found = true;
        }
    }
    if (!found) cout << "No song with name '" << name << "' found.\n";
}
void searchByArtist() {
    cin.ignore();
    string artist;
    cout << "Enter artist name to search: ";
    getline(cin, artist);
    bool found = false;
    for (const auto& s : songs) {
        if (s.singer == artist) {
            cout << "\n" << s.name << " - " << s.genre << " (" << s.year << ")\n";
            found = true;
        }
    }
    if (!found) cout << "No songs by '" << artist << "' found.\n";
}
void updateSong() {
    cin.ignore();
    string name;
    cout << "Enter the name of the song to update: ";
    getline(cin, name);
    for (auto& s : songs) {
        if (s.name == name) {
            cout << "Enter new song name: ";
            getline(cin, s.name);
            cout << "Enter new singer name: ";
            getline(cin, s.singer);
            cout << "Enter new genre: ";
            getline(cin, s.genre);
            cout << "Enter new year: ";
            cin >> s.year;
            cout << "Enter new duration: ";
            cin >> s.duration;
            cout << "\n✅ Song details updated!!\n";
            return;
        }
    }
    cout << "Song not found.\n";
}
int main() {
    int choice;
    do {
        cout << "\n*** SONG MANAGEMENT SYSTEM ***\n";
        cout << "1. Add a new song\n";
        cout << "2. View all songs\n";
        cout << "3. View details of all songs\n";
        cout << "4. Search Songs by Year\n";
        cout << "5. Search Songs by Name\n";
        cout << "6. Search Songs by Artist\n";
        cout << "7. Update details of a song\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addNewSong(); break;
            case 2: viewAllSongs(); break;
            case 3: viewAllDetails(); break;
            case 4: searchByYear(); break;
            case 5: searchByName(); break;
            case 6: searchByArtist(); break;
            case 7: updateSong(); break;
            case 8: cout << "\nProgram exits!\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 8);
    return 0;
}
