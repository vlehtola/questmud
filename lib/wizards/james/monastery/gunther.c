inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_level(100);
    set_name("monk");
    set_alias("gunther");
    set_short("Gunther, the combat master of the monastery");
    set_long("A very old and thin monk. He returns your look with his evil eyes and \n" +
             "keeps watching you intently. He is standing in a combat stance and you\n" +
	     "get the feeling he is more powerful than his looks suggest.\n");
    set_al(-50);
    set_aggressive(0);
}

