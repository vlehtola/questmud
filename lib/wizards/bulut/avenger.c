inherit "obj/monster";

reset(arg) {
    object boots,axe;
    ::reset(arg);
    if(arg) { return; }
    set_level(55);
    set_alias("troll");
    set_name("avenger");
    set_short("A huge troll planning for revenge");
    set_long("A horrible angry looking, smelling huge troll is towering in "+
"front of you. You would not with to get his closer attention.\n");
    set_al(0);
    set_aggressive(0);
    set_whimpy(15);
    set_move_at_random(0);
    axe = clone_object("/wizards/bulut/avenger_axe.c");
    move_object(axe, this_object());
    init_command("wield axe");
    boots = clone_object("/wizards/bulut/newboots.c");
    move_object(boots, this_object());
    init_command("wear boots");
    set_skill("strike", 80);
    set_skill_chance("strike", 20);
    set_log(1);

}
