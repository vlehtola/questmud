inherit "obj/armour";
drop() { return 1; }
start() {
        set_class(1);
        set_slot("special");
        set_name("orb");
         set_short("An orb of all-seeing eye");
        set_long("The orb is made from crystal and when looked in the orb. one can see\n"+
                 "almost anything. Inside the orb is an eye of a dragon.\n");
        set_weight(200);
        set_value(0);
        set_stats("int", 9);
        set_stats("wis", 9);
        set_stats("con", 10);
        set_stats("spr", 18);
        set_resists("cold", 25);
        set_resists("fire", 25);
        set_resists("electric", 25);
    }

query_no_save() { return 1; }
