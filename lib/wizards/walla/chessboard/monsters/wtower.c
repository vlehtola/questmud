inherit "obj/monster";
 
reset(arg) {
        ::reset(arg);
        if (arg) { return; }
        set_level(17);
        set_name("rook");
        set_alias("tower");
        set_gender(1);
        set_short("A white rook");
        set_long("A white rook stands tall before you.\n");
        set_al(10);
        set_aggressive(0);
        set_move_at_random(0);
         
}

