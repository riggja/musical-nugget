#include "background.h"
using namespace std;

Background::Background(int i) {
    images = i;
    textures = new sf::Texture[images];
    string * addresses = new string[images];
    char buffer[30];
    for (int z = 0; z < images; z++) {
        int f = 1;
        // char *intStr = itoa(f, buffer, 10);
        // string str = string(intStr);
        sprintf(*addresses, "resources/images/Background%d.jpg", z);
        cout << addresses[z] << endl;
        f++;
    }
    for (int j = 1; j <= images; j++) {
        string address = "resources/images/Background1"; 
        // string num = std::to_string(f);
        // address += f;
        // address += ".jpg";
        // address = strip(address);
        address = "resources/images/Background1.jpg";
        if(!(textures[j].loadFromFile(addresses[j-1]))) {
            cout << "cannot load background" << endl;
            cout << address << endl;
        }
    }
}

Background::~Background() {
    delete [] textures;
}
