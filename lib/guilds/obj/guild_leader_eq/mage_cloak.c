inherit "obj/armour";

drop() { return 1; }

start() {
        set_class(1);
        set_slot("special");
        set_name("cloak");
        set_short("The blue cloak of Archmage");
        set_long("This cloak is made from blue fabric, on the backside is\n"+
                 "symbol of Archmage. Strange arcane powers are floating\n"+
                 "on the cloaks surface");
        set_weight(400);
        set_value(0);
        set_stats("int", 15);
        set_stats("con", 12);
        set_stats("spr", 20);
        set_resists("cold", 25);
        set_resists("fire", 25);
        set_resists("electric", 25);
}

query_no_save() { return 1; }
