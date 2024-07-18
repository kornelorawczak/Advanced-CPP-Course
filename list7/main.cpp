#include <iostream>
#include <cmath>

using namespace std;

class Color{
protected:
    unsigned short red;
    unsigned short green;
    unsigned short blue;
public:
    Color() : red(0), green(0), blue(0) {}
    Color(unsigned short r, unsigned short g, unsigned short b){
        if (r < 256 && g < 256 && b < 256) {
            red = r;
            green = g;
            blue = b;
        }
        else{
            throw invalid_argument("Wrong input!");
        }
    }
    unsigned short get_r() const{
        return red;
    }
    unsigned short get_g() const{
        return green;
    }
    unsigned short get_b() const{
        return blue;
    }
    void set_r(unsigned short val){
        if (val > 255){
            throw invalid_argument("Wrong input!");
        }
        else{
            red = val;
        }
    }
    void set_g(unsigned short val){
        if (val > 255){
            throw invalid_argument("Wrong input!");
        }
        else{
            green = val;
        }
    }
    void set_b(unsigned short val){
        if (val > 255){
            throw invalid_argument("Wrong input!");
        }
        else{
            blue = val;
        }
    }
    void lighten(unsigned short percentage){
        unsigned short new_red = round(red*(1 + percentage/100));
        unsigned short new_green = round(green*(1 + percentage/100));
        unsigned short new_blue = round(blue*(1 + percentage/100));
        if (new_red < 255) {
            red = new_red;
        }
        else{
            red = 255;
        }
        if (new_green < 255) {
            green = new_green;
        }
        else{
            green = 255;
        }
        if (new_blue < 255) {
            blue = new_blue;
        }
        else{
            blue = 255;
        }

    }
    void darken(unsigned short percentage){
        unsigned short new_red = round(red*(1 - percentage/100));
        unsigned short new_green = round(green*(1 - percentage/100));
        unsigned short new_blue = round(blue*(1 - percentage/100));
        red = new_red;
        green = new_green;
        blue = new_blue;
    }
    static Color mergeColors(const Color& c1, const Color& c2){
        unsigned short new_red = (c1.red + c2.red) / 2;
        unsigned short new_green = (c1.green + c2.green) / 2;
        unsigned short new_blue = (c1.blue + c2.blue) / 2;
        return Color(new_red, new_green, new_blue);
    }
};

class Transparent_Color : virtual public Color{
private:
    unsigned short alpha;
public:
    Transparent_Color(unsigned short r, unsigned short g, unsigned short b, unsigned short a) : Color(r,g,b), alpha(a) {}
    unsigned short get_alpha() const{
        return alpha;
    };
    void set_alpha(unsigned short new_a){
        if (new_a > 255){
            throw invalid_argument("Wrong input!");
        }
        else{
            alpha = new_a;
        }
    }
};

class Signed_Color : virtual public Color {
private:
    string name;
public:
    Signed_Color(unsigned short r, unsigned short g, unsigned short b, const string& n = "") : Color(r,g,b) {
        string low_n;
        for (auto& letter : n){
            low_n += tolower(letter);
        }
        if (low_n == n){
            name = n;
        }
        else{
            throw invalid_argument("Color name has to be all lowercase!");
        }
    }
};

class ColorTN : public Transparent_Color, public Signed_Color{
public:
    ColorTN(unsigned short r, unsigned short g, unsigned short b, unsigned short a, const string& n = "")
            : Color(r, g, b), Transparent_Color(r, g, b, a), Signed_Color(r, g, b, n) {}
};

class Pixel{
protected:
    int x;
    int y;
public:
    const static int monitor_x = 2560;
    const static int monitor_y = 1440;

    Pixel(int x0, int y0){
        if (x0 >= 0 && y0 >= 0 && x0 <= monitor_x && y0 <= monitor_y){
            x = x0;
            y = y0;
        }
        else{
            throw invalid_argument("Given coordinates are out of monitor screen!");
        }
    }
    int get_x() const{
        return x;
    }
    int get_y() const{
        return y;
    }
    void set_x(int x0){
        if (x0 >= 0 && x0 <= monitor_x){
            x = x0;
        }
        else{
            throw invalid_argument("Given coordinate is out of monitor screen");
        }
    }
    void set_y(int y0){
        if (y0 >= 0 && y0 <= monitor_y){
            y = y0;
        }
        else{
            throw invalid_argument("Given coordinate is out of monitor screen");
        }
    }
    // I'm assuming that the pixel (0,0) is in the left right corner as it is in most of gamedev environments
    double left_upper_corner_dist() const{
        return sqrt(pow(x,2) + pow(y,2));
    }
    double right_upper_corner_dist() const{
        return sqrt(pow((monitor_x - x),2) + pow(y,2));
    }
    double right_lower_corner_dist() const{
        return sqrt(pow((monitor_x - x),2) + pow((monitor_y - y),2));
    }
    double left_lower_corner_dist() const{
        return sqrt(pow(x,2) + pow((monitor_y - y),2));
    }
    static double distance(const Pixel* p1, const Pixel* p2){
        int dx = p2->x - p1->x;
        int dy = p2->y - p1->y;
        return sqrt(pow(dx, 2) + pow(dy, 2));
    }
    static double distance(const Pixel& p1, const Pixel& p2){
        int dx = p2.x - p1.x;
        int dy = p2.y - p1.y;
        return sqrt(pow(dx, 2) + pow(dy, 2));
    }

};

class Colored_Pixel : public Pixel{
private:
    Color pixel_color;
public:
    Colored_Pixel(int x, int y) : Pixel(x, y), pixel_color(Color()) {}
    Colored_Pixel(int x, int y, unsigned short r, unsigned short g, unsigned short b) : Pixel(x, y), pixel_color(Color(r, g, b)) {}
    void set_color(unsigned short r, unsigned short g, unsigned short b){
        pixel_color = Color(r, g, b);
    }
    void move(int x0, int y0){
        int new_x = x + x0;
        int new_y = y + y0;
        if (new_x <= monitor_x && new_y <= monitor_y){
            x = new_x;
            y = new_y;
        }
        else{
            throw invalid_argument("You can't go out of the monitor");
        }
    }
};



int main() {

    return 0;
}
