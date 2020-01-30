inherit "room/room";

reset(arg) {
 if(arg) return;
 set_light(3);
 short_desc = "Inside the Tower of Sorcery";
 long_desc = "Long desc.\n";
 add_exit("northeast", "/guilds/sorcerer/tower/floor2/room10.c");
 add_exit("west", "/guilds/sorcerer/tower/floor2/room3.c");
 add_exit("south", "/guilds/sorcerer/tower/floor2/room1.c");
}