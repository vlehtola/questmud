inherit "obj/monster";
reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_level(35+random(5));
    set_name("ghost");
    set_alias("ghost");
    set_undead(1);
    set_short("A corrupted ghost ");
    set_long("A corrupted ghost is watching you from the shadows.\n" +
                    "The ghost is small but it is dangerous and unexpected.\n"+
                    "The ghost's eyes are a bit strange. A bright yellow light\n"+
                    "coming from a torch which the ghost is carrying.\n");    
    set_al(-100);
    set_aggressive(0);
    set_block_dir();
    
}
