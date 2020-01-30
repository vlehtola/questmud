inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_level(41);
    set_name("spirit");
    set_alias("spirit");
    set_undead(1);
    set_short("A restless spirit");
    set_long("A restless spirit looks like it has lost something\n" +
                   "or somebody. If you look at the spirits face\n"+
                   "against the moonlight you notice that it's crying.\n" +
                   "Acid tears are burning on its face.\n");    
    set_al(-100);
    set_aggressive(0);
    set_block_dir();
    
}
