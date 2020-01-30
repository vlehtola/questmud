inherit "obj/monster";
 
reset(arg) {
    object housut,paita;
    ::reset(arg);
    if (arg) return;
    set_level(30+random(5));
    set_name("init");
    set_alias("salesman");
    set_short("Init Sitab, the tailor");
    set_long("Init is a man who has dedicated his life to purchasing and\n"+
             "selling precious and fine cloths and fabrics to people\n"+
             "with exquisite taste, just like Init. Some people in \n"+
             "Jericho feel that he has been drinking from the fairy cup.\n");
    set_al(35);
    set_gender(1);
    set_race("human");
    

    housut = clone_object("/wizards/walla/jericho/stuph/init-pants");
    move_object(housut, this_object());
    init_command("wear pants");
 
    paita = clone_object("/wizards/walla/jericho/stuph/init-shirt");
    move_object(paita, this_object());
    init_command("wear shirt");
}
 

