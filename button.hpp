/*
#include<raylib.h>
class Button {
public:
    Button(const char* imagePath, Vector2 imagePosition);
    ~Button();
    void Draw();
private:

    Texture2D texture;
    Vector2 position;
};
//#ifndef BUTTON_HPP
//#define BUTTON_HPP

/*#include <raylib.h>
#include <string>

class Button {
public:
    // Constructor takes image path, position, resize parameters, and text
    Button(const char* imagePath, Vector2 imagePosition, Vector2 size, const std::string& buttonText = "",
        Color bgColor = BLUE, Color textColor = WHITE);

    // Destructor to unload texture
    ~Button();

    // Method to draw the button
    void Draw();

    // Method to check if mouse is over the button
    bool IsMouseOver();

    // Method to check if the button is clicked
    bool IsClicked();

private:
    Texture2D texture;  // Texture for the button image
    Vector2 position;    // Position of the button
    Vector2 size;        // Size of the button (resize parameters)
    std::string text;    // Text on the button
    Color bgColor;       // Background color of the button
    Color textColor;     // Text color
    Rectangle bounds;    // Bounds of the button for collision detection
};

//#endif // BUTTON_HPP
*/
/*
#include <raylib.h>
#include <string>
using namespace std;
class Button {
public:
    Button(Vector2 position, Vector2 size, Color bgColor, const string& buttonText, Color textColor);
    void Draw() const;
    bool IsClicked() const;

private:
    Vector2 position;
    Vector2 size;
    Color bgColor;
    Color textColor;
    string text;
    Rectangle bounds;
};
*/
#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <raylib.h>
#include <string>

class Button {
public:
    Button(Vector2 position, Vector2 size, Color bgColor, const std::string& buttonText, Color textColor);
    void Draw() const;
    bool IsClicked() const;

private:
    Vector2 position;
    Vector2 size;
    Color bgColor;
    Color textColor;
    std::string text;
    Rectangle bounds;
};

#endif // BUTTON_HPP
