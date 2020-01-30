inherit "obj/monster";
reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_level(23);
    set_name("man");
    set_alias("man");
    set_short("Man repairing ladders here");
    set_long("This man is trying to repair ladders here. He has all kind\n"+ 
             "of tools with him like hammers, saw and some wood. Man has\n"+ 
             "long brown hair and blue eyes.\n");
    set_al(10);
    set_aggressive(0);
    set_race("human");

}

