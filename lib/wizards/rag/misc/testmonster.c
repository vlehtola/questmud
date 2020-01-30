inherit "obj/monster";

init() {
	add_action("monster","set_monster");
	::init();
}

reset(arg) {
        ::reset(arg);
        if(arg) { return; }
        set_level(1);
        set_name("monster");
	set_alias("testmonster");
	set_alt_name("test");
        set_short("Rag's testmonster (1)");
	set_long("Testmonster of level 1\n");
}

lvl(arg) {
	if(!arg) {
		write("Error.\n");
		return 0;
	}
	arg = to_int(arg);
	set_level(arg);
	set_short(this_player()->query_name()+"'s testmonster ("+arg+")");
	set_long("Testmonster of level "+arg+"\n");
	return 1;
}

monster(arg) {
	if(!arg) {
		write("Usage: monster <log|mage|undead>\n");
		return 1;
	}
	if(arg == "log") {
		write("Monster set to eq monster.\n");
		set_log();
		return 1;
	}
	if(arg == "mage") {
		write("Monster set to mage.\n");
		set_mage(1);
		return 1;
	}
	if(arg == "undead") {
		write("Monster set to undead.\n");
		set_undead(1);
		return 1;
	}
	write("Usage: monster <log|mage|undead>\n");
	return 1;
}
