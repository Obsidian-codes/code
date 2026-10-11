#include <iostream>
#include <fstream>

int main()
{
    std::ofstream file("rectangle.svg");

    if (!file.is_open())
    {
        std::cout << "Could not create file.\n";
        return 1;
    }

    file << "<svg width=\"500\" height=\"500\" "
         << "xmlns=\"http://www.w3.org/2000/svg\">\n";

    file << "  <rect x=\"100\" y=\"100\" "
         << "width=\"200\" height=\"100\" "
         << "fill=\"blue\" stroke=\"black\" stroke-width=\"3\"/>\n";

    file << "</svg>\n";

    file.close();

    return 0;
}