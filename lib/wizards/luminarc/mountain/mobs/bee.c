inherit "obj/monster";
reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_level(8);
    set_name("bee");
    set_alias("bee");
    set_short("freezing bee flying here");
    set_long("this small bee looks like it might bite you..");
    set_al(20);
    set_aggressive(0);
    set_animal(1);

}


