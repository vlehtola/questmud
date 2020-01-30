inherit "obj/monster";
 
reset(arg) {
	::reset(arg);
	if (arg) { return; }
	set_level(40);
	set_name("man");
	set_alias("twin");
	set_gender(1);
	set_short("Twin Ning, the tea-man");
	set_long("Twin Ning carries a small pot of tea, and walks around, checking that\n"+
	"everyone is content. Twin is a bit on the older side, and his brew seems\n"+
	"to smell lovely.\n");
	set_al(69);
	set_aggressive(0);
	set_move_at_random(0);
	set_log();
 
}


