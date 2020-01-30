inherit "room/room";

reset(arg) {
 if(arg) return;
 set_light(3);
 short_desc = "Inside the Tower of Sorcery";
 long_desc = "Long desc.\n";
 add_exit("southwest", "/guilds/sorcerer/tower/floor2/room2.c");
 add_exit("down","/guilds/sorcerer/ratoma_followers.c");
}