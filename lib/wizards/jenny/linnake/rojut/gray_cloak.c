inherit "obj/armour";

start() {
        set_slot("cloak");
        set_name("cloak");
        set_short("Unattractive looking old cloak");
        set_long("Very unattractive looking old cloak that smells\n"+
                 "bad, looks bad and even sound bad. It's painted\n"+
                 "gray and there are some holes in it.");
        set_value(1000);
        set_weight(600);
        set_stats("con", 1);
        set_stats("wis", 3);
        set_stats("int", 6);
        set_stats("spreg", 7); 
}
