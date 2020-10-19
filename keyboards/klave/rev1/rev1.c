#include "rev1.h"

#include "quantum.h"


void keyboard_pre_init_kb(void) {

    setPinOutput(B0);
    setPinOutput(D5);
    
    writePinHigh(B0);
    writePinHigh(D5);

    keyboard_pre_init_user();
    
}
