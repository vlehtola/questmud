inherit "obj/monster";
 
reset(arg) {
    ::reset(arg);
    if (arg) { return; }
    set_level(5+random(2));
    set_race("bird");
    set_name("pigeon");
    set_alias("bird");
    set_short("A "+({ "brown", "white", "black", "skinny", "hungry",})[random(5)]+" pigeon is flying here");
    set_long("A cute looking pigeon is flying here and there over\n"
             "the garden looking for food that people bring into\n"+
             "the garden for them to eat.\n");
             
    set_al(0);
    set_animal(1);
    set_aggressive(0);
}
