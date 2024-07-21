#include "Board_Buttons.h"              // Board Support:Buttons
#include "Board_LED.h"                  // Board Support:LED

int main() {
    volatile int i;
    uint32_t ledIndex = 0;
    uint32_t lastButtonState = 0;

    Buttons_Initialize();
    LED_Initialize();

    while (1) {
        uint32_t currentButtonState = Buttons_GetState();

        // If button state changes
        if (currentButtonState && !lastButtonState) {
            LED_On(ledIndex);
            for (i = 0; i < 1000000; i++);  // Wait
            LED_Off(ledIndex);
            
            // Next LED
            ledIndex++;
            if (ledIndex >= 4) {
                ledIndex = 0;
            }
        }

        // Update state
        lastButtonState = currentButtonState;
    }
}
