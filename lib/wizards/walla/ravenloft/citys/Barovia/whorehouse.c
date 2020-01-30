#include "room.h"
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
extra_reset() {
    if (!present("poster")) {
        move_object("wizards/walla/ravenloft/citys/Barovia/whposter", this_object());
    }

    if (!items) {
        items = allocate(2);
        items[0] = "box";
        items[1] = "This is a magical charity box. If you want to reproche Walla for his sick mind use\n" +
                   "this box. Kick it, kill it, do whatever you please.";
    }

} 

object monster;
 
extra_reset() {
    set_not_out(2);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/ravenloft/citys/Barovia/monster/madame");
        move_object(monster, this_object());
    }
}

TWO_EXIT("wizards/walla/ravenloft/citys/Barovia/kartov5", "east",
         "wizards/walla/ravenloft/citys/Barovia/whoreup", "up",
         "In the whorehouse just inside Kartov Street",
         "This is the Whorehouse at Kartov street. It has been built to serve the need of sick old\n" +
         "perverts that this city might inhabit. Especially it is rumoured, that the Burgomaster, Kartov\n" +     
         "is a frequent visitor to this unholy place.\n" +
         "A madame stands at the desk and looks you over sexily. You wonder what a beautiful girl\n" +
         "like that does here, and fantasize what the whores look like. A poster on the back wall tells\n"+                               "the prices.\n", 2)


