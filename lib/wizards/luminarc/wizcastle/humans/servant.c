inherit "obj/monster";
reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_level(10);
    set_name("servant");
    set_alias("woman");
    set_short("Woman servant cleaning floors");
    set_long("This old woman looks like she has been cleaning floors\n"+ 
             "forever. She has long white hair and she is wearing white\n"+ 
             "clothes. Small wrinkles can be spotted on her face. Long\n"+ 
             "broom moves smoothly in her hands. This woman is really a\n"+
             "professional.\n");
    set_gender(2);
    set_al(10);
    set_aggressive(0);
    set_race("human");
}


