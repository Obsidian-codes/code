#include <fstream>
#include <iostream>
#include <string>

const double WIDTH = 800;
const double HEIGHT = 600;
const double HEIGHT_GRASS = 50;


void rect(std::ostream& house, double x, double y, double w, double h,
    std::string fill, std::string stroke="none") {
    house << "<rect x='" << x << "' y='" << y << "' width='" << w << "' height='" << h
    << "' fill='" << fill <<"' stroke='" << stroke << "' />\n";
}

void circle(std::ostream& house, double cx, double cy, double r,
    std::string fill, std::string stroke="none") {
    house << "<circle cx='" << cx << "' cy='" << cy << "' r='" << r
    << "' fill='" << fill <<"' stroke='" << stroke << "' />\n";
}

void path(std::ostream& house, std::string d,
    std::string fill, std::string stroke="none") {
    house << "<path d='" << d << "' fill='" << fill <<"' stroke='" << stroke << "' />\n";
}


int main() {
    std::ofstream house("house.svg");

    if (!house) {
        std::cout << "Can't open house file :(\n";
        return 1;
    }

    house << "<svg width='" << WIDTH << "' height='" << HEIGHT << "' xmlns='http://www.w3.org/2000/svg'>\n";

    // Sky
    rect(house, 0, 0, WIDTH, HEIGHT, "skyblue", "none");

    //grass
    rect(house, 0, HEIGHT - HEIGHT_GRASS, WIDTH, HEIGHT_GRASS, "green", "none");

    //house
    rect(house, 200, 350 - HEIGHT_GRASS, 400, 250, "brown", "none");
    //ROOF
    path(house, "m 200 300 l 200 -150 l 200 150 z", "red", "none");
    //door
    rect(house, 460, 350, 100, 200, "black", "none");
    circle(house, 540, 450, 10, "yellow", "none");

    circle(house, 100, 100, 100, "yellow", "none");

    //window
    rect(house, 250, 350, 150, 100, "white", "none");
    house << "</svg>\n";
    house.close();

    return 0;
}
