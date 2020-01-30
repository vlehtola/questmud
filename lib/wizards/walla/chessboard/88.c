#include "room.h" 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/chessboard/monsters/btower");
        move_object(monster, this_object());
    }
}
 
THREE_EXIT("wizards/walla/chessboard/87", "west",
         "wizards/walla/chessboard/77","northwest",
         "wizards/walla/chessboard/78", "north",
         "On a white square in the chessboard",
         "You are on a white square of the chessboard.\n" +
         "This is the black tower's place. \n", 3)
