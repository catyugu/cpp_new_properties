#include <iostream>
#include <vector>
#include <string>
class Playlist{
public:
    std::vector<std::string> songs;
    Playlist(std::initializer_list<std::string> songs){
        this->songs = songs;
    }
};
int main(){
    Playlist my_playlist = {"Stairway to Heaven", "Bohemian Rhapsody", "Hotel California"};
    for (const auto& song : my_playlist.songs){
        std::cout << song << std::endl;
    }
}