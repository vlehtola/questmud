inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_level(50);   
    set_name("morgoth");
    set_alias("wizard");
    set_short("MORGOTH");
    set_long("Morgoth the Wizard.\n");
    set_al(10);
    set_aggressive(0);
    set_animal(1);
} 
