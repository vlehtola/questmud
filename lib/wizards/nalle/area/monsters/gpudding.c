inherit "obj/monster";

reset(arg) {
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    set_animal();
    set_gender(0);
    call_other(this_object(), "set_level", 13);
    call_other(this_object(), "set_name", "pudding");
    call_other(this_object(), "set_alias", "Pudding");
    call_other(this_object(), "set_short", "An angry christmas pudding guard");
    call_other(this_object(), "set_long", "This is a strange-looking creature. It is brown,\n" +
                                          "and has little blue eyes. It seems sad.\n");
    call_other(this_object(), "set_al", 2);
    call_other(this_object(), "set_aggressive", 1);

    armour = clone_object("/wizards/nalle/area/eq/rags");
    move_object(armour, this_object());
    init_command("wear rags");
}
