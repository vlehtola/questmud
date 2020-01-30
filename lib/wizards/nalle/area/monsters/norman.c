inherit "obj/monster";

reset(arg) {
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    set_race("human");
    set_gender(1);
    call_other(this_object(), "set_level", 17);
    call_other(this_object(), "set_name", "norman");
    call_other(this_object(), "set_alias", "Norman");
    call_other(this_object(), "set_short", "Norman the lousy adventurer");
    call_other(this_object(), "set_long", "Norman was once a great adventurer. He was captured\n" +
                                          "and sent here for shooting the king's deer.\n");
    call_other(this_object(), "set_al", 2);
    call_other(this_object(), "set_aggressive", 0);


    armour = clone_object("/wizards/nalle/area/eq/rags");
    move_object(armour, this_object());
    init_command("wear rags");
}
