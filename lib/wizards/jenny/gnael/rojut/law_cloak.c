inherit "obj/armour";

start() {
        set_slot("cloak");
        set_name("cloak");
        set_short("A long beautiful black cloak");
        set_long("A completely black gorgeous cloak made of silk.\n"+
                 "There is a text 'Law' written on the middle of\n"+
                 "the cloak and when you look the word you sense\n"+
                 "a warm aura going through your body");
        set_value(10000);
        set_weight(300);
        set_stats("con", 4);
        set_stats("str", 4);
        set_stats("dex", 9);
}
