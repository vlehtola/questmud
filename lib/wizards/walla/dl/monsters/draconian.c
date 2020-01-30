inherit "obj/monster"; 
 
reset(arg) {
    ::reset(arg);
    if (arg) { return; }
    set_level(5);
    set_name("draconian");
    set_alias("monster");
    set_gender(1);
    set_short("Draconian");
    set_long("This is a draconian.\n"+
             "He has leather wings on his back and looks\n"+
             "really nasty.\n");
    set_al(10);
    set_aggressive(0);
    set_move_at_random(0);   
    
}

