inherit "obj/monster";

reset(arg) {
    object money;
    object clubi,clubi2;
    ::reset(arg);
    if(arg) { return; }
    set_level(65+random(3));
    set_name("swamp troll");
    set_alias("troll");
    set_skill("dodge", 20);
    set_skill("parry", 20);
    set_skill("inner strength", 70);
    set_skill("counter spell", 20);
    set_skill("strike", 100);
    set_skill("double strike", 100);
    set_skill("throw weight", 100);
    set_str(query_str() - 120);
    set_con(query_con() - 200);
    set_max_hp(query_hp() - 20000);
    set_short("A HUGE sized swamp troll");
    set_long("This appears to be a somewhat large specimen of the troll race even in the\n"+
             "scale of the race itself. It stands tall here, ready to assault anything entering\n"+
             "its premises. The feet seem like logs attached to the larger upper body. The\n"+
             "flats of the hands are bigger than a shovel clearly telling from a lethal,\n"+
             "brute force they possess. The eyes are deep in the eye-sockets glaring at you\n"+
             "with fearsome strength in them and the all over muscular body seems to quaver\n"+
             "in exitement before the battle.\n");    
    set_al(-100);
    set_aggressive(0);
    
    clubi = clone_object("/wizards/devil/areat/gerrano/ekut/trollclub.c");
    move_object(clubi, this_object());
    init_command("wield club");

    clubi2 = clone_object("/wizards/devil/areat/gerrano/ekut/trollclub.c");
    move_object(clubi2, this_object());
    init_command("wield club");


}
