#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
	extra_reset();

object mage;

extra_reset() {
    set_not_out(1);   
    if (!mage) {
	mage = clone_object("wizards/onarion/tower/monsters/redappr");
	move_object(mage, this_object());
    }
}

ONE_EXIT("wizards/onarion/tower/tower3", "west",
	 "Apprentice mage's bedroom",
	 "This is a bedroom of an apprentice mage.\n" +
	 "There are very little furniture, only a bed and a simple table.\n" +
	 "To the west lies the living room.\n", 3)
