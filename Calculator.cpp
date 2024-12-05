
/*#include "raylib.h"

int main() {
    // Initialize window
    InitWindow(800, 600, "Image Resizing Example");

    // Load the image
    Image image = LoadImage("Bag.png");

    // Resize the image to a specific width and height (e.g., 128x128)
    ImageResize(&image, 800, 600);

    // Convert the resized image to a texture
    Texture2D texture = LoadTextureFromImage(image);

    // Free the image data (no longer needed after converting to texture)
    UnloadImage(image);

    // Main game loop
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw the resized texture
        DrawTexture(texture, 0, 0, WHITE);

        EndDrawing();
    }

    // Unload texture and close the window
    UnloadTexture(texture);
    CloseWindow();

    return 0;
}
*/
/*
#include<iostream>
#include<raylib.h>
#include"button.hpp"
using namespace std;

const int Swidth = 550;
const int Sheight = 800;
void main()
{
	InitWindow(Swidth, Sheight, "button");
	SetTargetFPS(60);
    //Button startButton("Night.png", { GetScreenWidth() + 10, GetScreenHeight() + 10 },
      //  { GetScreenWidth() - 10, GetScreenHeight() / 5 }, "Screen", BLUE, WHITE);

    Image image = LoadImage("Sun.png");
    ImageResize(&image, Swidth, Sheight);
    Button startButton({ 10 , 10 }, { 525, 250 }, YELLOW, "Start", BLACK);
    Button n1({ 10,260 }, { 50,50 }, WHITE, "1",BLACK);
    // Convert the resized image to a texture
    Texture2D texture = LoadTextureFromImage(image);

    // Free the image data (no longer needed after converting to texture)
    UnloadImage(image);

	while (WindowShouldClose()==false)
	{
		BeginDrawing();
		ClearBackground(BLACK);
		DrawTexture(texture, 0, 0, WHITE);
       startButton.Draw();
       n1.Draw();
		EndDrawing();

	}
	CloseWindow();
}*/
#include <iostream>
#include <raylib.h>
#include "button.hpp"

using namespace std;

const int Swidth = 550;
const int Sheight = 800;

// Store the current input text
std::string input = "";
std::string result = "";
bool calculating = false;

void PerformCalculation(const std::string& expression) {
    try {
        // Simple evaluation (you could use an expression parser or switch to more complex eval systems)
        result = std::to_string(std::stod(expression));
    }
    catch (...) {
        result = "Error";
    }
}

int main() {
    InitWindow(Swidth, Sheight, "Calculator");
    SetTargetFPS(60);

    // Create buttons for digits and operations
    Button startButton({ 10, 10 }, { 525, 50 }, YELLOW, "Start", BLACK); // Optional
    Button clearButton({ 10, 70 }, { 100, 50 }, RED, "Clear", WHITE);

    // Numeric buttons
    Button n1({ 10, 130 }, { 50, 50 }, WHITE, "1", BLACK);
    Button n2({ 70, 130 }, { 50, 50 }, WHITE, "2", BLACK);
    Button n3({ 130, 130 }, { 50, 50 }, WHITE, "3", BLACK);
    Button n4({ 10, 190 }, { 50, 50 }, WHITE, "4", BLACK);
    Button n5({ 70, 190 }, { 50, 50 }, WHITE, "5", BLACK);
    Button n6({ 130, 190 }, { 50, 50 }, WHITE, "6", BLACK);
    Button n7({ 10, 250 }, { 50, 50 }, WHITE, "7", BLACK);
    Button n8({ 70, 250 }, { 50, 50 }, WHITE, "8", BLACK);
    Button n9({ 130, 250 }, { 50, 50 }, WHITE, "9", BLACK);
    Button n0({ 70, 310 }, { 50, 50 }, WHITE, "0", BLACK);

    // Operator buttons
    Button addButton({ 190, 130 }, { 50, 50 }, BLUE, "+", WHITE);
    Button subButton({ 190, 190 }, { 50, 50 }, BLUE, "-", WHITE);
    Button mulButton({ 190, 250 }, { 50, 50 }, BLUE, "*", WHITE);
    Button divButton({ 190, 310 }, { 50, 50 }, BLUE, "/", WHITE);
    Button eqButton({ 250, 310 }, { 50, 50 }, GREEN, "=", WHITE);

    // Create texture for background if needed
    Image image = LoadImage("Sun.png");
    ImageResize(&image, Swidth, Sheight);
    Texture2D texture = LoadTextureFromImage(image);
    UnloadImage(image);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw the background image if needed
        DrawTexture(texture, 0, 0, WHITE);

        // Display input and result
        DrawText(input.c_str(), 10, 70, 30, BLACK);
        DrawText(result.c_str(), 10, 400, 30, BLACK);

        // Draw the buttons
        startButton.Draw();
        clearButton.Draw();
        n1.Draw();
        n2.Draw();
        n3.Draw();
        n4.Draw();
        n5.Draw();
        n6.Draw();
        n7.Draw();
        n8.Draw();
        n9.Draw();
        n0.Draw();
        addButton.Draw();
        subButton.Draw();
        mulButton.Draw();
        divButton.Draw();
        eqButton.Draw();

        // Handle button clicks
        if (clearButton.IsClicked()) {
            input = "";
            result = "";
        }
        if (n1.IsClicked()) input += "1";
        if (n2.IsClicked()) input += "2";
        if (n3.IsClicked()) input += "3";
        if (n4.IsClicked()) input += "4";
        if (n5.IsClicked()) input += "5";
        if (n6.IsClicked()) input += "6";
        if (n7.IsClicked()) input += "7";
        if (n8.IsClicked()) input += "8";
        if (n9.IsClicked()) input += "9";
        if (n0.IsClicked()) input += "0";
        if (addButton.IsClicked()) input += "+";
        if (subButton.IsClicked()) input += "-";
        if (mulButton.IsClicked()) input += "*";
        if (divButton.IsClicked()) input += "/";
        if (eqButton.IsClicked()) {
            PerformCalculation(input);
            calculating = true;
        }

        EndDrawing();
    }

    CloseWindow(); // Close window and OpenGL context
    return 0;
}
