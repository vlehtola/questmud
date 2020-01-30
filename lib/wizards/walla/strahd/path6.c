#include "room.h" 
 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(2);
    if (!monster) {
        monster = clone_object("/wizards/walla/strahd/monsters/lamb");
        move_object(monster, this_object());
    }
}
 
TWO_EXIT("wizards/walla/strahd/path5", "northwest",
         "wizards/walla/strahd/path7", "west",
         "On a road, fading away to a path",
         "As you walk further into the mountanous area, the road fades away, and only a path\n" +
         "continues its way upwards. Although people have warned you many times not to go to the\n" +
         "misty area, you seem tempted to find out what lies ahead.\n", 2)
