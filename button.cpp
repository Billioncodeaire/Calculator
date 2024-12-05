/*#include "button.hpp"

Button::Button(const char* imagePath, Vector2 imagePosition)
{
	texture = LoadTexture(imagePath);
	position = imagePosition;
}
Button ::~Button()
{
	UnloadTexture(texture);
}
void Button::Draw()
{
	DrawTextureV(texture, position, WHITE);
}
/*#include "button.hpp"

Button::Button(const char* imagePath, Vector2 imagePosition, Vector2 size, const std::string& buttonText,
    Color bgColor, Color textColor)
{
    // Load the image from the file
    Image image = LoadImage(imagePath);  // LoadImage returns an Image object

    // Resize the image to the desired size
    ImageResize(&image, size.x, size.y);

    // Convert the resized image to a texture
    texture = LoadTextureFromImage(image);

    // Unload the image data since it's no longer needed after converting to a texture
    UnloadImage(image);

    // Initialize position, size, and other properties
    position = imagePosition;
    this->size = size;
    this->bgColor = bgColor;
    this->textColor = textColor;
    this->text = buttonText;

    // Define bounds for collision detection (button area)
    bounds = { position.x, position.y, size.x, size.y };
}

Button::~Button() {
    // Unload texture when button is destroyed
    UnloadTexture(texture);
}

void Button::Draw() {
    // Draw the background rectangle
    DrawRectangleRec(bounds, bgColor);

    // Draw the texture on top of the button if available
    if (texture.width > 0 && texture.height > 0) {
        DrawTextureV(texture, position, WHITE);  // Draw image texture
    }

    // Draw the button text, centered inside the button
    if (!text.empty()) {
        Vector2 textSize = MeasureTextEx(GetFontDefault(), text.c_str(), 20, 1);  // Get text size
        Vector2 textPosition = {
            position.x + (size.x - textSize.x) / 2,  // Horizontally center
            position.y + (size.y - textSize.y) / 2   // Vertically center
        };
        DrawTextEx(GetFontDefault(), text.c_str(), textPosition, 20, 1, textColor);
    }
}

bool Button::IsMouseOver() {
    Vector2 mousePos = GetMousePosition();
    return CheckCollisionPointRec(mousePos, bounds);  // Check if mouse is over button
}

bool Button::IsClicked() {
    return IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && IsMouseOver();  // Check if button is clicked
}
*/

#include "Button.hpp"

Button::Button(Vector2 position, Vector2 size, Color bgColor, const std::string& buttonText, Color textColor)
    : position(position), size(size), bgColor(bgColor), textColor(textColor), text(buttonText)
{
    // Define bounds for collision detection
    bounds = { position.x, position.y, size.x, size.y };
}

void Button::Draw() const {
    // Draw the button as a rounded rectangle
    DrawRectangleRounded(bounds, 0.2f, 20, bgColor); // 0.2f for corner radius, 20 for segments (roundness)

    // Draw the text centered on the button
    Vector2 textSize = MeasureTextEx(GetFontDefault(), text.c_str(), 20, 1.0f);
    Vector2 textPosition = { position.x + (size.x - textSize.x) / 2, position.y + (size.y - textSize.y) / 2 };
    DrawTextEx(GetFontDefault(), text.c_str(), textPosition, 20, 1.0f, textColor);
}

bool Button::IsClicked() const {
    // Check if the mouse is inside the button bounds and clicked
    return CheckCollisionPointRec(GetMousePosition(), bounds) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}
