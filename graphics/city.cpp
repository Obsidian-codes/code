#include <fstream>
#include <iostream>
#include <string>

const double WIDTH = 1000;
const double HEIGHT = 1600;

void rect(std::ostream& city, double x, double y, double w, double h,
    std::string fill, std::string stroke="none") {
    city << "<rect x='" << x << "' y='" << y << "' width='" << w << "' height='" << h
    << "' fill='" << fill <<"' stroke='" << stroke << "' />\n";
}

void circle(std::ostream& city, double cx, double cy, double r,
    std::string fill, std::string stroke="none") {
    city << "<circle cx='" << cx << "' cy='" << cy << "' r='" << r
    << "' fill='" << fill <<"' stroke='" << stroke << "' />\n";
}

void path(std::ostream& city, std::string d,
    std::string fill, std::string stroke="none") {
    city << "<path d='" << d << "' fill='" << fill <<"' stroke='" << stroke << "' />\n";
}

void window(std::ostream& city, double x, double y, double w, double h){
    rect(city, x, y, w, h, "rgb(247, 229, 223)");
    return;
}

int main(){
    std::ofstream city ("city.svg");
    if(!city){
        std::cout << "Can't open city file :(" << std::endl;
        return 1;
    }

    city << "<svg width='" << WIDTH << "' height='" << HEIGHT << "' xmlns='http://www.w3.org/2000/svg'>\n";

    //sky
    rect(city, 0, 0, WIDTH, HEIGHT, "rgb(240, 180, 180)", "none");

    //building back
    rect(city, 0, HEIGHT - 900, 130, 900, "rgb(158, 98, 126)");
    window(city, 10, HEIGHT - 875, 50, 25);

    rect(city, 160, HEIGHT - 800, 100, 800, "rgb(158, 98, 126)");
    rect(city, 290, HEIGHT - 1100, 230, 1100, "rgb(158, 98, 126)");
    rect(city, 520, HEIGHT - 800, 190, 800, "rgb(158, 98, 126)");
    rect(city, 740, HEIGHT - 1000, 200, 1000, "rgb(158, 98, 126)");

    //buildings middle
    //buildings front
    city << "</svg>\n";
    city.close();
    return 0;
}