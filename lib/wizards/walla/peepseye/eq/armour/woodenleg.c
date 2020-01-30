inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("leg");
    set_alias("wood");
    set_short("Pepe's wooden leg");
    set_long("This wooden leg attaches itself to your leg, even though you have one.\n");
    set_ac(21);
    set_value(400);
    set_weight(210);
    set_slot("legs");
}

