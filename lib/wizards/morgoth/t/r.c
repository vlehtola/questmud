inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_level(random(2)+3);
    set_name("bird");
    set_short("A little bird is singing here");
    set_long("This little bird is singing here.\n");
    set_al(40);
    set_animal(1);
}


