inherit "room/room";

reset(arg) {
 if(arg) return;
 set_light(3);
 short_desc = "Inside the Tower of Sorcery";
 long_desc = "Long desc.\n";
 add_exit("north", "/guilds/sorcerer/tower/floor1/room4.c");
 add_exit("east", "/guilds/sorcerer/tower/floor1/room6.c");
}