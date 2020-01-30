inherit "obj/monster";
 
reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_level(1+random(4));
    set_name("prisoner");
    set_alias("man");
    set_short("A half-dead prisoner");
    set_long("There is not much to say about this remnant of a man.\n"+
             "Where he hasn't been beaten up, his skin is of a strange\n"+
             "brownish colour. He looks as if he hasn't had anything to\n"+
             "eat for a long time.\n");
    set_al(0);
    set_gender(1);
    set_race("human");
 
 
}
