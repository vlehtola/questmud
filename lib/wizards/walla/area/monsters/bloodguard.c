inherit "obj/monster"; 
 
reset(arg) {
    ::reset(arg);
set_race("human");
    set_level(40);
    set_name("guard");
    set_alias("nobleman");
    set_short("A Bloodguard");
    set_long("This nobleman has been exiled to live underground.\n");
    set_al(-10);
    set_aggressive(0);
    set_skill("dodge", 100);
    set_skill("tumble", 100);
    set_skill("parry", 100);
    set_skill("attack", 89);
    set_skill("critical", 100);
    set_dead_ob(this_object());
}
