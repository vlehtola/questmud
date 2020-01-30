inherit "room/room";

reset(arg) {
 if(arg) return;
 set_light(3);
 short_desc = "Inside the Tower of Sorcery";
 long_desc = "Long desc.\n";
 add_exit("northwest", "/guilds/sorcerer/tower/floor2/room8.c");
 add_exit("down","/guilds/sorcerer/grizz_followers.c");
}