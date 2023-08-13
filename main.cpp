#include <iostream>
#include <string>
#include <vector>
#include <ncurses.h>

// Model
class MediaFile {
public:
    std::string name;
    std::string path;
    MediaFile(std::string name, std::string path) : name(name), path(path) {}
};

class MediaModel {
public:
    std::vector<MediaFile> files;
    void addFile(MediaFile file) {
        files.push_back(file);
    }
};

// View
class MediaView {
public:
    void showFiles(std::vector<MediaFile> files) {
        clear();
        printw("Media Files:\n");
        for (auto file : files) {
            printw("%s\n", file.name.c_str());
        }
        refresh();
    }
};

// Controller
class MediaController {
private:
    MediaModel model;
    MediaView view;
public:
    void addFile(MediaFile file) {
        model.addFile(file);
    }
    void showFiles() {
        view.showFiles(model.files);
    }
};

int main() {
    // Initialize ncurses
    initscr();
    cbreak();
    noecho();

    // Create controller
    MediaController controller;

    // Add some media files
    controller.addFile(MediaFile("Song 1", "/home/linhqp/Music/Mot-Nam-Moi-Binh-An-Son-Tung-M-TP.mp3"));
    // controller.addFile(MediaFile("Song 2", "C:/Users/os/Music/Playlists/ALoi-Double2TMasew-10119691.mp3"));
    // controller.addFile(MediaFile("Video 1", "/path/to/video1.mp4"));

    // Show media files
    controller.showFiles();

    // Wait for user input
    getch();

    // End ncurses
    endwin();

    return 0;
}
