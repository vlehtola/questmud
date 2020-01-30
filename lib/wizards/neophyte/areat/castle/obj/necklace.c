inherit "obj/armour";
int i;
start() {
        set_slot("neck");
        set_name("necklace");
        set_short("Necklace of Pidur");
        set_long("This necklace has been on former king family for eternity,\n"+
                 "but now it is stolen by Pidur. The necklace is made from small\n"+
                 "golden rings that are embadded together one of the ancient"+
                 "dwarven blacksmith. A large silvery medallion is also placed\n"+
                 "on the other side of necklace. On the medallion reads something");
        set_value(1000);
        set_weight(200);
        set_stats("spr", 8);
        set_stats("int", 5);
        set_stats("con", 5);
        i = 3;
}

init() {
	add_action("read", "read");
	add_action("touch", "touch");
}

read(str) {
	if(str == "medallion") {
		write("You read the text on the medallion and it's says something about touching the kings.\n");
		return 1;
	}
}

touch(str) {
	if(str == "medallion") {
		if(i > 1) {
		write("You touch the medallion and it's starts to vibrate slowly.\n");
		call_out("safe_teleport", 5);
		i -= 1;
		return 1;
	}
	write("You touch the medallion but nothing seems to happeng.\n");
	return 1;
}
}

safe_teleport() {
	write("Finally the vibration ends and you are teleported back to city.\n");
	call_other("/guilds/spells/essence/_exs_zzt_trn.c", "resolve", 1);
	return 1;
}
