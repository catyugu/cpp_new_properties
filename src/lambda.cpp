#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Required for std::sort

struct Song {
    std::string title;
    int rating;
};

// A helper function to print the vector
void printPlaylist(const std::vector<Song>& playlist, const std::string& title) {
    std::cout << "--- " << title << " ---\n";
    for (const auto& song : playlist) {
        std::cout << song.title << " (Rating: " << song.rating << ")\n";
    }
    std::cout << "\n";
}

int main() {
    // 2. Create and populate the vector
    std::vector<Song> playlist = {
        {"Bohemian Rhapsody", 5},
        {"Sandstorm", 4},
        {"Baby Shark", 1},
        {"Stairway to Heaven", 5},
        {"Hotel California", 5}
    };

    // 3. Print the unsorted list
    printPlaylist(playlist, "Unsorted");

    // 4. Sort the vector using a lambda
    std::sort(playlist.begin(), playlist.end(), [](const Song& a, const Song& b) {
        // 5. Use a lambda function to compare the songs
        if (a.rating == b.rating) {
            return a.title < b.title; // Sort by title if ratings are equal
        }
        return a.rating > b.rating; // Sort by rating in descending order
    });

    // 6. Print the sorted list
    printPlaylist(playlist, "Sorted");

    return 0;
}