#include "room.h"

FIVE_EXIT("wizards/manta/hill/room2.c", "enter",
	   "out: 130 77", "north",
	   "out: 130 77", "south",
	   "out: 130 77", "west",
	   "out: 130 77", "east",
           "Front of fortress",
           "You are standing near big fortress which seems to be destroyed, but by whom?\n" +
           "You can see a figure of a castle inside fortress.\n", 3)

init() {
 ::init();
 add_action("enter","enter");
}

enter() {
 if (this_player()->query_level() < 10) {
write("You can hear some terrifying noises coming from the fortress and dare\n");
write("not to enter. Maybe when your a bit older and more experienced.\n");
    return 1;
 }
}
