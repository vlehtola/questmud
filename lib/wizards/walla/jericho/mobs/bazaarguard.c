inherit "obj/monster";
 
reset(arg) {
    object ase,kilpi,kypara;
    ::reset(arg);
    if (arg) return;
    set_level(20+random(5));
    set_name("guard");
    set_alias("man");
    set_short("A man, guarding the bazaar");
    set_long("The town folks have decided to hire men to guard the\n"+
             "safety of the salesmen at the bazaar, since many of them\n"+
             "have been plundered and killed recently. The man is charged\n"+
             "badly bruised.\n");
    set_al(50);
    set_al_aggr(50);
    set_gender(1);
    set_race("human");
    

    ase = clone_object("/wizards/walla/jericho/stuph/morningstar");
    move_object(ase, this_object());
    init_command("wield morningstar");
 
    kilpi = clone_object("/wizards/walla/jericho/stuph/shield");
    move_object(kilpi, this_object());
    init_command("wear shield");
 
    kypara = clone_object("/wizards/walla/jericho/stuph/helmet");
    move_object(kypara, this_object());
    init_command("wear helmet");
}
 

