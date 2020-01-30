inherit "obj/monster";

reset(arg) {
    object weapon;
        ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 45);
    call_other(this_object(), "set_name", "shadow");
    call_other(this_object(), "set_alias", "shadow");
    call_other(this_object(), "set_short", "A shadow protecting the entrance");
    call_other(this_object(), "set_long", "You see a huge black guardian demon in front of you. It is wielding\n"
                              "enormous warhammer. The demon itself is very muscular and their strength\n"
   							  "is something unbelievable.\n");

    call_other(this_object(), "set_aggressive", 0);
    set_block_dir("north");
    set_block_message("Guardian demon grunts: Im here to protect the nyx, You may not enter");


    weapon = clone_object("/wizards/aarrgh/nyxi/obj/warhammer.c");
	    move_object(weapon, this_object());
    init_command("wield dagger");
}
