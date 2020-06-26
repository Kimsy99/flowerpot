
#pragma once
/**
 * Handles all key events.
 */

void keyListener(unsigned char key, int mx, int my);
void keyUpListener(unsigned char key, int mx, int my);
void specialKeyListener(int key, int mx, int my);
void specialKeyUpListener(int key, int mx, int my);
void handleInput();
