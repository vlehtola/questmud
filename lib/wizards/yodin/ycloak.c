inherit "obj/armour";

start() {
        set_slot("cloak");
        set_name("cloak");
        set_short("dirty old cloak");
        set_long("yak");
        set_value(0);
        set_weight(600);
        set_stats("con", 25);
        set_stats("wis", 25);
        set_stats("int", 25);
        set_stats("spreg", 25); 
       set_stats("str",25);
       set_stats("dex",25);

}

init() {
::init();

  add_action("toss","toss");
}
  toss() {
  write("You can't toss this item.\n");
  return 1;
}


