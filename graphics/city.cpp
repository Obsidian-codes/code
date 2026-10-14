#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <random>
#include <string>

const double WIDTH = 1000;
const double HEIGHT = 1600;

std::random_device rd;
std::mt19937 gen(rd());

void rect(std::ostream &city, double x, double y, double w, double h,
          std::string fill, std::string stroke = "none") {
  city << "<rect x='" << x << "' y='" << y << "' width='" << w << "' height='"
       << h << "' fill='" << fill << "' stroke='" << stroke << "' />\n";
}

void balcony(std::ostream &city, double buildingX, double buildingY,
             double buildingW, double poleW = 10, double poleH = 20) {
  double x = buildingX;
  double y = buildingY;

  double gap = 20;

  while (x + poleW <= buildingX + buildingW) {
    rect(city, x, y, poleW, poleH, "rgb(9, 23, 34)");

    x += poleW + gap;
  }
}

void circle(std::ostream &city, double cx, double cy, double r,
            std::string fill, std::string stroke = "none") {
  city << "<circle cx='" << cx << "' cy='" << cy << "' r='" << r << "' fill='"
       << fill << "' stroke='" << stroke << "' />\n";
}

void path(std::ostream &city, std::string d, std::string fill,
          std::string stroke = "none") {
  city << "<path d='" << d << "' fill='" << fill << "' stroke='" << stroke
       << "' />\n";
}

void building_1(std::ostream &city, double x, double y, double w, double h) {
  rect(city, x, y, w, h, "rgb(158, 98, 128)");
}

void building_2(std::ostream &city, double x, double y, double w, double h) {
  rect(city, x, y, w, h, "rgb(41, 39, 52)");
}

void building_3(std::ostream &city, double x, double y, double w, double h) {
  rect(city, x, y, w, h, "rgb(9, 23, 34)");
}

// void window1(std::ostream &city, double x, double y, double w, double h) {
//   double newY = y;
//   while (newY + h <= y + 1000) {
//     rect(city, x, newY, w, h, "rgb(247, 229, 223)");
//     newY += h;
//     newY += 25;
//   }
// }

void window(std::ostream &city, double x, double y, double w, double h,
             double numx, double numy, int numCols) {
  double gap = 20;
  
  // Loop for rows (using numy as the vertical boundary)
  for (double newY = y; newY + h <= numy; newY += h + gap) {
    
    // Loop for columns based on the specified number of columns
    for (int i = 0; i < numCols; ++i) {
      double newX = x + i * (w + gap);
      
      if (newX + w <= numx) {
        rect(city, newX, newY, w, h, "rgb(247, 229, 223)");
      }
    }
  }
}

int main() {
  std::ofstream city("city.svg");
  if (!city) {
    std::cout << "Can't open city file :(" << std::endl;
    return 1;
  }

  city << "<svg width='" << WIDTH << "' height='" << HEIGHT
       << "' xmlns='http://www.w3.org/2000/svg'>\n";

  // sky
  rect(city, 0, 0, WIDTH, HEIGHT, "rgb(240, 192, 180)", "none");
  circle(city, 900, 100, 1200, "rgb(238, 140, 129)");
  circle(city, 900, 100, 900, "rgb(237, 158, 145)");
  circle(city, 900, 100, 600, "rgb(240, 188, 174)");
  circle(city, 900, 100, 300, "white");

  // building back
  building_1(city, 0, HEIGHT - 900, 130, 900);
  window(city, 10, HEIGHT - 870, 60, 20, 260, HEIGHT - 50, 1);

  // window1(city, 10, HEIGHT - 880, 60, 20);

  building_1(city, 160, HEIGHT - 800, 100, 800);
  window(city, 175, HEIGHT - 780, 25, 20, 260, HEIGHT - 580, 2);

  building_1(city, 290, HEIGHT - 1100, 230, 1100);
  window(city, 315, HEIGHT - 1080, 30, 20, 600, HEIGHT - 80, 4);

  building_1(city, 520, HEIGHT - 800, 160, 800);
  window(city, 540, HEIGHT - 770, 50, 20, 800, HEIGHT - 80, 2);

  building_1(city, 710, HEIGHT - 1000, 100, 1000);
  // window(city, 760, HEIGHT - 980, 50, 20, 900, HEIGHT - 80, 2);

  building_1(city, 810, HEIGHT - 1100, 100, 1000);
  window(city, 830, HEIGHT - 1070, 20, 50, 900, HEIGHT - 80, 2);


  // buildings middle
  building_2(city, 0, HEIGHT - 500, 151, 500);
  window(city, 10, HEIGHT - 480, 25, 20, 15, HEIGHT - 50, 2);

  building_2(city, 150, HEIGHT - 650, 250, 650);
  building_2(city, 400, HEIGHT - 500, 200, 500);
  building_2(city, 600, HEIGHT - 580, 180, 580);
  building_2(city, 780, HEIGHT - 400, 80, 400);
  building_2(city, 860, HEIGHT - 700, 140, 700);

  // buildings front
  
  building_3(city, 0, HEIGHT - 380, 340, 380);
  window(city, 15, HEIGHT - 370, 35, 20, 15, HEIGHT - 370, 3);

  building_3(city, 600, HEIGHT - 240, 400, 240);
  balcony(city, 600, HEIGHT - 260, 400);
  building_3(city, 600, HEIGHT - 270, 400, 10);

  building_3(city, 850, 1260, 150, 100);

  city << "</svg>\n";
  city.close();
  return 0;
}