inherit "room/room";

reset(arg) {
 if(arg) return;
 set_light(3);
 short_desc = "Inside the Tower of Sorcery";
 long_desc = "Long desc.\n";
 add_exit("out", "out: 100 100");
 add_exit("east", "/guilds/sorcerer/tower/floor1/room2.c");
}