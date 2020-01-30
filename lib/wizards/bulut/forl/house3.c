#include "room.h"
object guard, guard2;

extra_reset() {
        if (!guard || !living(guard)) {
guard = clone_object("/wizards/bulut/forl/monsters/hguard2.c");
        move_object(guard, this_object());
}
        if (!guard2 || !living(guard2)) {
guard2 = clone_object("/wizards/bulut/forl/monsters/hguard2.c");
move_object(guard2, this_object());



}
}
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();


TWO_EXIT("wizards/bulut/forl/road9","out",
"wizards/bulut/forl/room1","west",
"Inside of a house",
"It is very clean here. The floor reflects your figure on itself.\n" +
"There is a open door at western wall.\n",3)
