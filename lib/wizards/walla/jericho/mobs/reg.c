inherit "obj/monster";
 
reset(arg) {
    object hattu,housut,paita;
    ::reset(arg);
    if (arg) return;
    set_level(25+random(5));
    set_name("reg");
    set_alias("shopkeeper");
    set_short("Reg Rubseh, a prosperous shopkeeper");
    set_long("Reg has recently returned from a long exile in the eastern\n"+
             "parts of the world, and has brought numerous wonderful objects\n"+
             "to sell. He also seems to have put on some extra pounds of \n"+
             "weight, for worse days to come\n");
    set_al(55);
    set_al_aggr(200);
    set_gender(1);
    set_race("human");
    

    hattu = clone_object("/wizards/walla/jericho/stuph/reg-hat");
    move_object(hattu, this_object());
    init_command("wear hat");
 
    housut = clone_object("/wizards/walla/jericho/stuph/reg-pants");
    move_object(housut, this_object());
    init_command("wear pants");
 
    paita = clone_object("/wizards/walla/jericho/stuph/reg-shirt");
    move_object(paita, this_object());
    init_command("wear shirt");
}
 

