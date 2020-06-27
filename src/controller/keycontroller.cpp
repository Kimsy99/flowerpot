#include <iostream>
#include <cctype>
#include <map>
#include <GL/glut.h>
#include "../util/Camera.h"
#include "../model/Light.h"
//#include "../main.cpp"
/**
 * Handles all key events.
 */

extern Camera camera;
extern float movementSpeed;
extern Light light;
/**
 * Maps all characters to a flag indicating whether it is being pressed or not. Due to limitations, this
 * currently only works on letters and the whitespace characters (spaces and tabs).
 */
static std::map<unsigned char, bool> keyMap;

/** Maps all special keys to a flag indicating whether it is being pressed or not. */
static std::map<int, bool> specialKeyMap;

/**
 * If the input parameter is a letter key code, it converts it to a pure letter key code, i.e. discards
 * control and shift modifiers. If the input parameter is the key code for a whitespace character, then
 * it is returned without any modifications.
 */
static unsigned char getPureLetterKeyCode(unsigned char key)
{
	if (key == ' ' || key == '\t')
		return key;
	key = tolower(key); // Convert to lowercase
	int modifier = glutGetModifiers();
	if ((modifier & GLUT_ACTIVE_CTRL) != 0) // Handle Ctrl + letter cases
		key += 96;
	return key;
}

void keyListener(unsigned char key, int mx, int my)
{
	if (!isalpha(key) && !isalpha(key + 96) && key != ' ' && key != '\t')
		return;
	key = getPureLetterKeyCode(key);

	keyMap[key] = true;
	std::cout << "Pressed '" << key << "' (keycode " << (int)key << ") : " << keyMap[key] << std::endl;
}

void keyUpListener(unsigned char key, int mx, int my)
{
	if (!isalpha(key) && !isalpha(key + 96) && key != ' ' && key != '\t')
		return;
	key = getPureLetterKeyCode(key);

	keyMap[key] = false;
	std::cout << "Released '" << key << "' (keycode " << (int)key << ") : " << keyMap[key] << std::endl;
}

void specialKeyListener(int key, int mx, int my)
{
	specialKeyMap[key] = true;
	std::cout << "Pressed special key " << key << " : " << specialKeyMap[key] << std::endl;
}

void specialKeyUpListener(int key, int mx, int my)
{
	specialKeyMap[key] = false;
	std::cout << "Released special key " << key << " : " << specialKeyMap[key] << std::endl;
}

/**
 * Actual handling of all user input.
 */
void handleInput()
{
	if (specialKeyMap[114] || specialKeyMap[115]) // Left control and right control
		movementSpeed = 0.6F;
	else
		movementSpeed = 0.2F;
	if (keyMap['w'] || specialKeyMap[GLUT_KEY_UP])
		camera.moveForward(movementSpeed);
	if (keyMap['a'] || specialKeyMap[GLUT_KEY_LEFT])
		camera.strafe(-movementSpeed);
	if (keyMap['s'] || specialKeyMap[GLUT_KEY_DOWN])
		camera.moveForward(-movementSpeed);
	if (keyMap['d'] || specialKeyMap[GLUT_KEY_RIGHT])
		camera.strafe(movementSpeed);
	if (keyMap[' ']) // Space
		camera.elevate(movementSpeed);
	if (specialKeyMap[112] || specialKeyMap[113]) // Left shift and right shift
		camera.elevate(-movementSpeed);
}

/**
 * Handle changing in lighting
 * */
void handleLighting(Light light){
	if (keyMap['k'])
		light.shiftLighting(5);
	if (keyMap['j'])
		light.shiftLighting(-5);
}
