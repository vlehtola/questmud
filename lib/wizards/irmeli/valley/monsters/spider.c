inherit "obj/monster";
reset(arg) {

::reset(arg);
if (arg) { return; }
    set_level(10);
    set_name("spider");
    set_short("A spider weaving a web");
    set_long("A harmless looking spider weaving a web on the wall. It has eight long and\n"+
             "hairy legs, four legs on both sides of its body. The spider uses the web,\n"+
             "as a trap for its prey.\n");

    set_animal(1);
    set_gender(0);
    set_al(20);
    set_aggressive(0);

 }









