inherit "obj/monster";

reset(arg) {
    object boots,axe;
    ::reset(arg);
    if(arg) { return; }
    set_level(46);
    set_alias("troll");
    set_name("avenger");
    set_short("A troll planning for revenge");
    set_long("A rough looking troll planning for revenge.\n");
    set_al(0);
    set_skill("axes", 90);
    set_skill("cut", 90);
    set_aggressive(0);
    set_whimpy(15);
    set_move_at_random(0);
    axe = clone_object("/wizards/bulut/avenger_axe.c");
    move_object(axe, this_object());
    init_command("wield axe");
    boots = clone_object("/wizards/bulut/boots.c");
    move_object(boots, this_object());
    init_command("wear boots");



}
