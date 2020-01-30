inherit "obj/armour";

start() {
        set_class(1);
        set_slot("amulet");
        set_name("medallion");
        set_alias("amulet");
        set_short("Medallion of Fire");
        set_long("This medallion is the sign of a general in the Lich King's army.\n"+
                 "It is needed to protect the general in the fiery depths of the\n"+
                 "Lich King's army's training grounds. There is a small everburning\n"+
                 "flame enchanted to the medallion");
        set_resists("fire",12);
        set_stats("str",5);
        set_stats("dex",5);
        set_stats("con",5);
        set_weight(5);
}

