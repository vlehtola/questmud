inherit "obj/monster";

reset(arg) {
     object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 10);
    call_other(this_object(), "set_name", "citizen");
    call_other(this_object(), "set_alias", "armenian");
    call_other(this_object(), "set_short", "A poor citizen of the armenian quarters");
    call_other(this_object(), "set_long", "This poor man is nothing but a leprous begger, and he seems to be of\n" +
                                          "no interest to you. His legs are covered with some kind of eruptive pores, that can\n" +
                                          "be the sign of some sort of smallpox or something.\n");
    call_other(this_object(), "set_al", 0);
    call_other(this_object(), "set_aggressive", 0);

    armour  = clone_object("/wizards/walla/area/armour/monkkirobe");
    move_object(armour, this_object());
    init_command("wear robes");


}

