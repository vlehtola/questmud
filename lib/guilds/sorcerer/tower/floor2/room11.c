inherit "room/room";

reset(arg) {
 if(arg) return;
 set_light(3);
 short_desc = "Inside the Tower of Sorcery";
 long_desc = "Long desc.\n";
 add_exit("northeast", "/guilds/sorcerer/tower/floor2/room6.c");
 add_exit("up", "/guilds/sorcerer/tower/floor3/room1.c");
}