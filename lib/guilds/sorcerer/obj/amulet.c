inherit "obj/armour";

start() {
set_class(2);
set_name("amulet");
set_short("Amulet of High sorcerer");
set_long("The amulet of high sorcerer is the symbol of true sorcerer.\n"+
         "This amulet is only given to the sorcerer who has mastered\n"+
         "the powers of sorcerers and has true faith on Izyldran\n");
set_stats("int", 1);
set_stats("wis", 1);
set_stats("spr", 30);
set_value(10000);
set_weight(10);
set_slot("amulet");
}

