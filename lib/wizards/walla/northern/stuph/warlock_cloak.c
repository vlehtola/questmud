inherit "obj/armour";

start() {
set_class(6);
  set_slot("cloak");
    set_name("cape");
    set_alias("cloak");
    set_short("A crimson cloak stained with blood");
    set_long("You are holding the cloak of Khazin-Talak, the dwarven death knight. The\n" +
             "cloak is designed to protect your back and it shrouds your body almost\n" +
             "entirely.");
    set_value(5000);
    set_stats("str",10);
    set_stats("con",5);
    set_stats("wis",-3);
    set_stats("int",-1);
    set_weight(5);

}
