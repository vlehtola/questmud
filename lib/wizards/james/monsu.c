inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
set_level(50);
set_name("ghost");
set_short("A ghost");
set_long("A strange ghost.\n");
set_al(0);
    set_aggressive(0);
set_undead(1);


}                                                        
