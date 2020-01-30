inherit "obj/monster";
reset(arg) {
    object armour;    
    ::reset(arg);
    if(arg) { return; }
    set_level(34);
    set_max_hp(query_hp()+1000);
    set_str(query_str()+100);
    set_name("guard");
    set_alias("guard");
    set_short("Big guard making his duty");
    set_long("Tall and muscular guard is standing here. It seems that he\n"+ 
             "is searching for something. Guard is wearing bright, shining\n"+ 
             "equipment. Guard's whole body is almost fully protected\n"+
             "by metal, though his head seems to be unprotected. His blue \n"+ 
             "eyes gleam and the long, white hair is flapping wildly\n"+
             "as he turns his head rapidly from side to side.\n");

    set_al(10);
    set_race("human");
    set_gender(1);
    set_aggressive(0);

}

