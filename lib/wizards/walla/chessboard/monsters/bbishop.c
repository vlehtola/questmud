inherit "obj/monster";
 
reset(arg) {
        ::reset(arg);
        if (arg) { return; }
        set_level(25);
        set_name("bishop");
        set_alias("bishop");
        set_gender(1);
        set_short("A black bishop");
        set_long("A black bishop stands tall before you.\n");
        set_al(10);
        set_aggressive(0);
        set_move_at_random(0);
         
}
