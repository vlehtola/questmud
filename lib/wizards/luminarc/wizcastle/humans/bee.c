inherit "obj/monster";
reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_level(35);
    set_name("bee");
    set_alias("bee");
    set_short("Large bee trying to look angry");
    set_long("This big bee looks like it might bite you. It has a long spike\n"+
             "in the tip of its tail. The bee is coloured with yellow and \n"+
             "black stripes. Big black eyes are shining in its head.\n");
    set_al(20);
    set_aggressive(0);
    set_animal(1);

}

