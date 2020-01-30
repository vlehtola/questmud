inherit "obj/armour";

start() {
    set_slot("neck");
    set_name("necklace");
    set_short("The necklace of Worlds");
    set_long(   "Zadax, the traveller between worlds, created this necklace from\n"+
		"different pieces of magical materials that he had collected from\n"+
		"many different worlds. With his knowledge of magical energies he\n"+
		"located the finest metals and precious stones. He managed to forge\n"+
		"those materials into this unique magical necklace");
    set_weight(10);
    set_stats("con",-4);
    set_stats("int",8);
    set_stats("wis",4);
    set_stats("spr",8);
    set_resists("electric",8);
}
