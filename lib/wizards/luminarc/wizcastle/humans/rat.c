inherit "obj/monster";
reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_level(30);
    set_name("rat");
    set_alias("rat");
    set_short("A HUGE rat");
    set_long("This huge rat is at least two times longer than other\n"+ 
             "rats. It has yellow teeths small black eyes. Skin of the\n"+
             "rat is brown and all kind of rubbish has stuck on it.\n"+ 
             "Rat makes its movements with no haste and it is sniffing\n"+
             "everything.\n");
    set_al(10);
    set_aggressive(0);
    set_animal(1);


}

