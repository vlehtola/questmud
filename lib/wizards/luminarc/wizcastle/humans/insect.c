inherit "obj/monster";
reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_level(20);
    set_name("insect");
    set_alias("insect");
    set_short("Big insect flying here");
    set_long("this small insect looks like mosquito or something.");
    set_al(20);
    set_aggressive(0);
    set_animal(1);


}

