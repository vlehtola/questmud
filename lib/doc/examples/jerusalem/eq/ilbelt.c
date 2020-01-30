inherit "obj/armour";

start() {
set_class(2);
set_name("belt");
set_short("A thin black belt { worn }");
set_long("A thin black belt made of leather. It has inscriptions\n"+
"on it, written in golden, undecipherable letters.\n" );
set_stats("int", 7);
set_stats("wis", 4);
set_stats("spr", 15);
set_value(1000);
set_weight(100);
set_slot("belt");
}

