inherit "room/room";

reset(arg) {
 if(arg) return;
 set_light(3);
 short_desc = "Inside the Tower of Sorcery";
 long_desc = "Long desc.\n";
 add_exit("southeast", "/guilds/sorcerer/tower/floor1/room10.c");
 add_exit("down", "/guilds/sorcerer/tower/floor1/basement.c");
}