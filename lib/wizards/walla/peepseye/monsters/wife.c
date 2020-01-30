inherit "obj/monster";
 
reset(arg) {
    ::reset(arg);
    if (arg) { return; }
    set_level(12);
    set_name("victoria");
    set_alias("woman");
    set_gender(2);
    set_short("Victoria, a beautiful woman");
    set_long("Victoria is a busy housewife. She has alot of work to do, since her husband, Beavis Hamill, the\n"+
             "mayor and judge of OilOhnRock is never at home. Victoria has to clean up all the mess and has to\n"+
             "make food for when Beavis comes home.\n");
    set_al(10);
    set_aggressive(0);
    set_move_at_random(0);
   
 
}
