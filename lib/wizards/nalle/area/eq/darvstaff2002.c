inherit "obj/weapon";

start() {
    set_class(6);
    set_sub_type("staff");
    set_short("Staff of Arcane Rulership");
    set_long("A staves like this, are created by the Mages Conclave, for the leaders of \n" +
                    "all three magical orders, therefore they are extremely rare. It feels warm\n" +
                    "to the touch.\n");
    set_stats("int", 6);
    set_stats("wis" ,6);
    set_stats("con" ,2);
    set_stats("spr", 5);
    set_stats("hpr", 5);
}