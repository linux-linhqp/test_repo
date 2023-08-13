#include <taglib/taglib.h>
#include <taglib/fileref.h>
#include <iostream>

int main() {
    // Path to the MP3 file
    const char* filePath = "/home/linhqp/Music/Mot-Nam-Moi-Binh-An-Son-Tung-M-TP.mp3";

    // Open the audio file
    TagLib::FileRef file(filePath);
    if (!file.isNull() && file.tag()) {
        // Retrieve the tag information
        TagLib::Tag* tag = file.tag();

        // Print the current tags
        std::cout << "Title: " << tag->title() << std::endl;
        std::cout << "Artist: " << tag->artist() << std::endl;
        std::cout << "Album: " << tag->album() << std::endl;
        std::cout << "Year: " << tag->year() << std::endl;

        // Modify the tags
        tag->setTitle("New Song Title");
        tag->setArtist("New Artist");
        tag->setAlbum("New Album");
        tag->setYear(2023);

        // Save the changes
        file.save();

        std::cout << "Tags updated successfully!" << std::endl;
    } else {
        std::cerr << "Failed to open the file or retrieve tags." << std::endl;
    }

    return 0;
}

