#include <fstream>
#include <iostream>
#include <string>

const double WIDTH = 600;
const double HEIGHT = 480;
const double HEIGHT_GRASS = 50;

void rect(std::ostream& out, double x, double y, double w, double h,
    std::string fill, std::string stroke="none") {
    out << "<rect x='" << x << "' y='" << y << "' width='" << w << "' height='" << h
    << "' fill='" << fill <<"' stroke='" << stroke << "' />\n";
}

void circle(std::ostream& out, double cx, double cy, double r,
    std::string fill, std::string stroke="none") {
    out << "<circle cx='" << cx << "' cy='" << cy << "' r='" << r
    << "' fill='" << fill <<"' stroke='" << stroke << "' />\n";
}

void path(std::ostream& out, std::string d,
    std::string fill, std::string stroke="none") {
    out << "<path d='" << d << "' fill='" << fill <<"' stroke='" << stroke << "' />\n";
}

double tower(std::ostream& out, double x, double w, double h) {
    rect(out, x, HEIGHT - HEIGHT_GRASS - h, w, h, "darkgrey");
    return HEIGHT - HEIGHT_GRASS - h;
}

void battlement(std::ostream& out, double x, double y, double size, double w){
    double newX = x;
    while(newX + size <= x + w) {
        rect(out, newX, y-size, size, size, "red", "black");
        newX += size;
        newX += size;
    }

}

int main() {
    std::ofstream out("castle.svg");
    if(!out) {
        std::cout << "Can't open castle file :(" << std::endl;
        return 1;
    }

    out << "<svg width='" << WIDTH <<"' height='" << HEIGHT << "' xmlns='http://www.w3.org/2000/svg'>\n";
//sky
    rect(out, 0, 0, WIDTH, HEIGHT, "skyblue");

    //wall
    rect(out, 160, 280, 280, 150, "lightgrey", "darkgrey");
    battlement(out, 160, 280, 20, 280);

    //tower1
    double height_towerA = tower(out, 60, 100, 230);
    battlement(out, 60, height_towerA, 20, 100);

    //tower 2
    double height_towerB = tower(out, 440, 100, 190);
    battlement(out, 440, height_towerB, 20, 100);

    rect(out, 0, HEIGHT - HEIGHT_GRASS, WIDTH,
        HEIGHT_GRASS, "forestgreen", "none");

    out <<"</svg>\n";
    return 0;
}