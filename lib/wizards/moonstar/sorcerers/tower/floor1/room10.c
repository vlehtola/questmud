inherit "room/room";

reset(arg) {
 if(arg) return;
 set_light(3);
 short_desc = "Inside the Tower of Sorcery";
 long_desc = "Long desc.\n";
 add_exit("northwest", "/guilds/sorcerer/tower/floor1/room12.c");
 add_exit("east", "/guilds/sorcerer/tower/floor1/room9.c");
 add_exit("south", "/guilds/sorcerer/tower/floor1/room4.c");
}