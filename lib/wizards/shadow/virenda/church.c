#include "std.h"

int reboot_time, time_from_reset, last_reset_cycle;
int list_length;

reset(arg)
{
    if (time_from_reset)
	last_reset_cycle = time() - time_from_reset;
    time_from_reset = time();
    if (arg)
	return;
    set_light(1);
    reboot_time = time();
}

init()
{
    add_action("pray", "pray");
    add_action("pray", "regenerate");
    add_action("west", "west");
    add_action("east", "east");
    add_action("south", "south");
    add_action("north", "north");
}

short() {
    return "Village church";
}

long(str)
{
    if (str == "clock") {
	int i, j;
	write("The clock shows ");
	i = time() - reboot_time;
	j = i / 60 / 60 / 24;
	if (j == 1)
	    write("1 day ");
	else if (j > 0)
	    write(j + " days ");
	i -= j * 60 * 60 * 24;
	j = i / 60 / 60;
	if (j == 1)
	    write("1 hour ");
	else if (j > 0)
	    write(j + " hours ");
	i -= j * 60 * 60;
	j = i / 60;
	if (j == 1)
	    write("1 minute ");
	else if (j > 0)
	    write(j + " minutes ");
	i -= j * 60;
	if (i == 1)
	    write("1 second");
	else if (i > 0)
	    write(i + " seconds");
	write("\n");
	if (call_other(this_player(), "query_level") < 100)
	    return;
	write("Time since reset is " + (time() - time_from_reset) +
	      " seconds.\n");
	if (last_reset_cycle)
	    write("Reset cycle: " + last_reset_cycle + "\n");
	write("Free block list length: " + list_length + "\n");
	return;
    }
    if (str == "pit") {
	write("In the middle of the church is a deep pit.\n"+
	      "It was used for sacrifice in the old times, but nowadays\n" +
	      "it is only left for tourists to look at.\n");
	return;
    }
    write("You are in the local church of Virenda.\n");
    write("There is a huge pit in the center,\n"); 
    write("This church has the service of reviving ghosts. Dead people come\n");
    write("to the church and pray. You see a shimmering doorway to the north.\n");
    write("Over the door there is some writing:\n");
    write("  * * *  WIZ AND IMMORTALS ONLY * * *\n");
    write("There is a clock on the wall.\n");
    write("There is an exit to south.\n");

}

id(str) {
    return str == "door" || str == "pit" || str == "clock";
}

xyzzy() {
    write("Everything shimmers.\n");
    write("You wake up elsewhere...\n");
    call_other(this_player(), "move_player", "elsewhere#room/test");
}


pray() {
    return call_other(this_player(), "remove_ghost", 0);
}

prevent_look_at_inv(str)
{
    return str != 0;
}

north() {
    if (call_other(this_player(), "query_level", 0) < 100) {
	write("A strong magic force stops you.\n");
	say(call_other(this_player(), "query_name", 0) +
	    " tries to go through the field, but fails.\n");
	return 1;
    }
    write("You wriggle through the force field...\n");
    call_other(this_player(), "move_player", "north#room/wizhall");
    return 1;
}

south() {
    call_other(this_player(), "move_player", "south#players/shadow/virenda/road1");
    return 1;
}

east() {
    call_other(this_player(), "move_player", "east#players/shadow/virenda/road24");
    return 1;
}

west() {
    call_other(this_player(), "move_player", "west#players/shadow/virenda/road26");
    return 1;
}

query_drop_castle() {
    return 1;
}
