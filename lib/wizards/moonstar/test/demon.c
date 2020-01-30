inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_level(random(17)+53);
    set_name("demon");
    set_short("A huge bloodred vortex-demon");
    set_long("A huge bloodred demon is living inside the vortex of gods. Demon has\n"+
"red eyes and huge horns. It doesn't look really friendly and it is staring\n"+
"you intensively. Demon has huge muscles and it is wielding a huge maul in\n"+
"its right hand.\n");
    set_al(-100);
    set_animal(1);
}

