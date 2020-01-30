inherit "obj/monster";
 
reset(arg) {
    ::reset(arg);
    if (arg) { return; }
    set_level(8);
    set_name("fox");
    set_short("A small fox");
    set_long("A small fox is running around the forest, apparently it is scared of something.\n");
    set_al(10);
    set_animal(1);
    set_aggressive(0);
    set_move_at_random(6);
}
