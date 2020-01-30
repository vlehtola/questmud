inherit "obj/monster";
reset(arg) {
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    set_name("dwarf");
    set_level(6);
    set_gender(1);
    set_alias("child");
    set_short("A little dwarf child ");
    set_long("A little child lafs and tosses a ball at you.\n"+
             "When he notices that you wont play with him he takes\n"+
             "the ball, and throws it to another child.\n");
    set_al_aggr(100);
    set_race("dwarf");
    weapon = clone_object("/wizards/belar/dwarf/eq/swo1g.c");
    move_object(weapon, this_object());
    init_command("wield sword");
}
