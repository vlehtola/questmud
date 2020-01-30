inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    set_name("staff");
    set_short("Staff of Arcane Rulership");
    set_long("A staves like this, are created by the Mages Conclave, for the leaders of \n" +  
                    "all three magical orders, therefore they are extremely rare. It feels warm\n" +
                    "to the touch.\n");
    set_material(10);
    set_class(15);
    set_weapon_type("bludgeon");
    set_value(21000);
    set_weight(2);
    set_stats(4,5);
    set_stats(5,5);
}

