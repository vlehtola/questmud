inherit "obj/monster";

reset(arg) {
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    set_undead(1);    
    call_other(this_object(), "set_level", 17);
    call_other(this_object(), "set_name", "Spirit");
    call_other(this_object(), "set_alias", "spirit");
    call_other(this_object(), "set_short", "A spirit guarding the grove");
    call_other(this_object(), "set_long", "This is an undead being of some sort.\n");
    call_other(this_object(), "set_al", -20);
    call_other(this_object(), "set_aggressive", 0);
    set_block_dir("east");

    armour = clone_object("/wizards/nalle/area/eq/rags");
    move_object(armour, this_object());
    init_command("wear rags");

}
