inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 45);
    call_other(this_object(), "set_al", -50);
    call_other(this_object(), "set_name",  "soldier");
    call_other(this_object(), "set_alias", "soldier");
    call_other(this_object(), "set_short", "A badly beaten soldier guarding the path");

    set_skill("stun", 90);
	set_skill("bare hands", 100);
	set_skill("critical", 40);
	set_skill("kick", 90);
    set_skill_chance("kick", 30);
	set_skill("dodge", 8);
    set_skill("tumble", 10);
    set_skill("attack", 90);
	set_skill("slash", 100);
	set_skill("alertness", 60);
	set_block_dir("north");
    set_block_message("Soldier grunts: I cannot let you in! You will die in there!");

		               set_long("This soldier is very badly beaten. He has no clothing or weapons.\n"
		                        "You start wondering how he is still alive. Even with badly beaten,\n"
		                        "he would be a great opponent if attacked.\n");

    call_other(this_object(), "set_aggressive", 0);

}
