inherit "obj/monster";
reset(arg) {
    object armour; 
    ::reset(arg);
    if (arg) { return; }
    set_level(20);
    set_name("citizen");
    set_short("A citizen of castle Asgroth (starving)");
    set_long("A citizen looks like a zombie because she hasn't got any food\n"+ 
             "in days. She is so thin that you can see her bones shining\n"+ 
             "through her skin, especially on her face and stomach. Her\n"+
             "hair is very dirty and looks like a mess.\n");
    
    set_al(20);
    set_gender(2);
    set_race("human");
    set_aggressive(0);

    armour = clone_object("/wizards/irmeli/castle/eq/leggings.c");
    move_object(armour, this_object());
    init_command("wear leggings");
}









