typedef enum KeyboardState{
RELASED, 
BUTTON_1, 
BUTTON_2, 
BUTTON_3, 
BUTTON_4} KeyboardState;

enum KeyboardState eKeyboardRead(void);
void KeyboardInit(void);
