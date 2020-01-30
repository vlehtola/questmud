inherit "obj/monster";

reset(arg) {

object armour;
        ::reset(arg);
        if(arg) { return; }
   	    set_level(30);
        set_max_hp(query_max_hp()*2);

        set_gender(1);
        set_name("man");
        set_alias("human");
        set_short("A tall and sturdy man.");
        set_long("A tall and sturdy looking man wearing a worn-out\n"+
                 "leather apron and textile gloves. He seems to be\n"+
                 "working with the mill as Duranghom's baker's helper\n"+
                 "out here, doing all the hard work for baker. Drops\n"+
                 "of sweat are falling by his cheek as the work consumes\n"+
                 "him. Despite the physical requirements of the man's job,\n"+
                 "he still looks like quite happy with his profession.\n");
        set_al(50);
        set_al_aggr(200);
        set_race("human");
        set_log();
        armour = clone_object("/wizards/yodin/areas/windmill/obj/amulet.c");
        move_object(armour, this_object());
        init_command("wear amulet");
}
