inherit "obj/monster";
 
reset(arg) {
    ::reset(arg);
    if (arg) { return; }
    set_level(10);
    set_name("human");
    set_alias("human");
    set_gender(1);
    set_short("Ugly old human warrior");
    set_long("This warriors days are obviously over,\n"+
             "hes too weak to even raise hes sword anymore.\n"+
             "t�� o suffa ucko.\n");
    set_al(100);
    set_aggressive(0);
    set_move_at_random(0);
    set_log();
 
}
