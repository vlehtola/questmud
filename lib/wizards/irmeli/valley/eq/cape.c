inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_slot("cloak");
    set_name("cloak");
    set_alias("cape");
    set_short("White cape of the terror");
    set_long("A long, white cape is made of cotton. A golden trimming goes round\n"+
             "the cape, at the lower edge of the cape. A big symbol of red skull\n"+
             "has been sewed at the back of the cape");
    set_value(400);
    set_weight(100);
    set_resists("cold", 5);
    set_resists("fire", 2);
}
