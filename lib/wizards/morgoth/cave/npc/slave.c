inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_level(1);   
    set_name("monster");
    set_alias("monster");
    set_short("Little monster is wandering here.");
    set_long("Dibbadii\n");
    set_al(10);
    set_aggressive(0);
} 
