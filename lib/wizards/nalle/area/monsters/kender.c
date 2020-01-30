inherit "obj/monster";

reset(arg) {
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    set_race("kender");
    set_gender(0);
    call_other(this_object(), "set_level", 16);
    call_other(this_object(), "set_name", "kender");
    call_other(this_object(), "set_alias", "Kender");
    call_other(this_object(), "set_short", "An irritating little kender");
    call_other(this_object(), "set_long", "This is a small, slightly gnome-like creature.\n" +
                                          "It seems bored.\n");
    call_other(this_object(), "set_al", 2);
    call_other(this_object(), "set_aggressive", 0);

    armour = clone_object("/wizards/nalle/area/eq/rags");
    move_object(armour, this_object());
    init_command("wear rags");
}
