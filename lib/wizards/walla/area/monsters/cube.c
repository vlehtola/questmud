inherit "obj/monster"; 
 
reset(arg) {
    ::reset(arg);
set_race("monster");
    set_level(41);
    set_name("cube");
    set_alias("thing");
    set_short("A Gelatinous Cube");
    set_long("You can actually see through this thing, which moves slowly against you.\n");
    set_al(-10);
    set_aggressive(0);
    set_skill("dodge", 100);
    set_skill("tumble", 100);
    set_skill("parry", 100);
    set_skill("attack", 89);
    set_skill("critical", 100);
    set_dead_ob(this_object());
}

