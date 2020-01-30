inherit "obj/weapon";


start() {
set_class(8);
set_sub_type("warhammer");
set_short("A warhammer of the demon guardian");
set_long("This is an enormous warhammer. This blunt weapon is capable of doing insane\n"
 "crushing damage to the target. The wielder must hold great strength for wielding\n"
 "a weapon of this size.\n");
 
set_stats("str",10);
set_stats("con",5);
set_stats("dex",-5);
set_stats("wis",-15);
set_stats("int",-10);
set_stats("hit",-10);
set_stats("dam",25);
}

