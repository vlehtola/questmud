inherit "obj/monster";

reset(arg) {
    int i;
    ::reset(arg);
    if(arg) { return; }
    
    i = random(2);
    set_level(5+random(3)+i*3);
    set_name("rabbit");
    set_alias("bunny");
    if(i == 0) set_short("A white rabbit");
    if(i == 1) set_short("A brown rabbit");
    set_long("A cute small rabbit. Its fur is soft and clean and it has\n"+
             "small white teeth. It chews grass and looks quite happy but\n"+
             "you sense some uncertainty in its moves.\n");
    set_al(5);
    set_aggressive(0);
    set_animal(1);
    set_wc(query_level());
    set_ac(query_level()+i*2);


}

