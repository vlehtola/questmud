inherit "obj/monster";

reset(arg) {
    object takki;
    ::reset(arg);
    if (arg) return;
    set_level(50);
    set_name("monk");
    set_alias("monk");
    set_short("Monk of the white moon");
    set_long("Raistlin has long, grey beard, thick silver-coloured hair and impressive,\n"+
             "beatiful eyes, which complete his wizard-like appearance. He is dressed\n"+
             "in robes, which are made to measure for him and his proportions. He is\n"+
             "rumoured to known some secret witchcraft.\n");
    set_al(0);
    set_gender(1);
    set_race("human");

    takki = clone_object("/wizards/merak/misc/robes");
    move_object(takki, this_object());
    init_command("wear robes");

}

