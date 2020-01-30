inherit "obj/monster";
 
reset(arg) {
    object takki,housu,belt;
    ::reset(arg);
    if (arg) return;
    set_level(50);
    set_name("monk");
    set_alias("monk");
    set_short("Monk of the black moon");
    set_long("Raistlin has long, grey beard, thick silver-coloured hair and impressive,\n"+
             "beatiful eyes, which complete his wizard-like appearance. He is dressed\n"+
             "in robes, which are made to measure for him and his proportions. He is\n"+
             "rumoured to known some secret witchcraft.\n");
    set_al(0);
    set_gender(1);
    set_hp(1);
    set_race("human");
 
    takki = clone_object("/wizards/walla/area2/stuph/basicrobes");
    move_object(takki, this_object());
    init_command("wear robes");
 
    housu = clone_object("/wizards/walla/area2/stuph/basicpants");
    move_object(housu, this_object());
    init_command("wear pants");
 
    belt = clone_object("/wizards/walla/area2/stuph/blackbelt");
    move_object(belt, this_object());
    init_command("wear belt");
}


