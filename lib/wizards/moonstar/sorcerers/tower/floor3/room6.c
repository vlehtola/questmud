inherit "room/room";

reset(arg) {
 if(arg) return;
 set_light(3);
 short_desc = "Inside the Tower of Sorcery";
 long_desc = "Long desc.\n";
 add_exit("southwest", "/guilds/sorcerer/tower/floor3/room3.c");
 add_exit("south", "/guilds/sorcerer/tower/floor3/room4.c");
 add_exit("southeast","/guilds/sorcerer/tower/floor3/room5.c");
 add_exit("up", "/guilds/sorcerer/soul_enchanters.c");
}