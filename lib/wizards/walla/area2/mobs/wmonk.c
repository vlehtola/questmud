 inherit "obj/monster";

reset(arg) {
    object takki,housu,belt;
    ::reset(arg);
    if (arg) return;
    set_level(30);
    set_name("monk");
    set_alias("monk");
    set_short("Monk of the white moon");
    set_long("This young apprentice of the followers of the moon is clothed\n"+
             "in stained white robes, which are not very well fitting. The monk\n"+
             "has short hair, and a few freckles on his face. A slight hint of a\n"+
             "moustache can be on top of the upper lip.\n");
    set_al(0);
    set_gender(1);
    set_race("human");

    takki = clone_object("/wizards/walla/area2/stuph/basicrobes");
    move_object(takki, this_object());
    init_command("wear robes");

    housu = clone_object("/wizards/walla/area2/stuph/basicpants");
    move_object(housu, this_object());
    init_command("wear pants");

    belt = clone_object("/wizards/walla/area2/stuph/whitebelt");
    move_object(belt, this_object());
    init_command("wear belt");
}

