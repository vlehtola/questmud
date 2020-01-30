inherit "obj/monster";
reset(arg) {

::reset(arg);
if (arg) { return; }
    set_level(random(35)+5);
    set_name("ghost");
    set_short("A small ghost grinning at you!");
    set_long("The ghost is like a white shade.\n");
    set_al(50);
    set_undead(1);
    set_aggressive(1);
    set_gender(1);
    set_mage(1, random(50));
    set_dead_ob(this_object());
}
monster_died() {
	object ob;
	ob = present("navigator_ghost", environment(this_object()));
	ob->reduce_number();
	return 0;
}