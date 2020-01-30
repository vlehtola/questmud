inherit "room/room";

object guard1,guard2;

reset(arg) {
    add_exit("north", "out: 61 112");
    add_exit("south", "out: 61 112");
    add_exit("west", "out: 61 112");
    add_exit("east", "out: 61 112");
    add_exit("enter", "/guilds/mage/tower1");
    short_desc = "Tower entrance";
    long_desc = "You are standing in front of a huge stone tower that rises high\n"+
"above your head. There is a gate leading in. Strange glowing globes light\n"+
"both sides of the gate\n";
    set_light(3);

    if (!guard1) {
	guard1 = clone_object("guilds/mage/monsters/guard.c");
	move_object(guard1, this_object());
    }
    if (!guard2) {
	guard2 = clone_object("guilds/mage/monsters/guard.c");
	move_object(guard2, this_object());
    }
}

