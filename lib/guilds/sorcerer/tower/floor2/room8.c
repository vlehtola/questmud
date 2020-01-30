inherit "room/room";

reset(arg) {
 if(arg) return;
 set_light(3);
 short_desc = "Inside the Tower of Sorcery";
 long_desc = "Long desc.\n";
 add_exit("north", "/guilds/sorcerer/tower/floor2/room1.c");
 add_exit("west", "/guilds/sorcerer/tower/floor2/room7.c");
 add_exit("southeast", "/guilds/sorcerer/tower/floor2/room12.c");
}