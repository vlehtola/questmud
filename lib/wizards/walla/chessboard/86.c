#include "room.h" 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/chessboard/monsters/bbishop");
        move_object(monster, this_object());
    }
}
 
FIVE_EXIT("wizards/walla/chessboard/85", "west",
         "wizards/walla/chessboard/87","east",
         "wizards/walla/chessboard/76", "north",
         "wizards/walla/chessboard/75", "northwest",          
         "wizards/walla/chessboard/77","northeast",
         "On a white square in the chessboard",
         "You are on a white square of the chessboard.\n" +
         "This is the black bishop's place. \n", 3)

