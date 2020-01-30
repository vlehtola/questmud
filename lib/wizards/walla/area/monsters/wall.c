inherit "obj/monster"; 
 
reset(arg) {
    ::reset(arg);
set_race("thing");
    set_level(42);
    set_name("wall");
    set_alias("thing");
    set_short("A Living Wall");
    set_long("This wall just seems to have started to live. You think you can distinguish a face in \n" +
"the middle of the whole thing.\n");
    set_al(-10);
    set_aggressive(0);
    set_skill("dodge", 100);
    set_skill("tumble", 100);
    set_skill("parry", 100);
    set_skill("attack", 89);
    set_skill("critical", 100);
    set_dead_ob(this_object());
}
