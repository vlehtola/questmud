inherit "obj/monster";
reset(arg) {
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    set_name("dwarf");
    set_level(7);
    set_exp(43000);
    set_gender(1);
    set_alias("child");
    set_short("A little dwarf child ");
    set_long("A child is about six years old in human life, but he looks so.\n"+
             "small so innocent. But he is also too quick he wants to touch\n"+
             "everything.\n");
    set_al_aggr(40);
    set_race("dwarf");
    weapon = clone_object("/wizards/belar/dwarf/eq/swo1g.c");
    move_object(weapon, this_object());
    init_command("wield sword");
}
