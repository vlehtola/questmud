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
 
FIVE_EXIT("wizards/walla/chessboard/82", "west",
         "wizards/walla/chessboard/84","east",
         "wizards/walla/chessboard/73", "north",
         "wizards/walla/chessboard/72", "northwest",          
         "wizards/walla/chessboard/74","northeast",
         "On a black square in the chessboard",
         "You are on a black square of the chessboard.\n" +
         "This is the black bishop's place. \n", 3)
