inherit "obj/food";

reset(arg) {
set_name("sack of flour");
set_alias("sack");
set_short("Large sack full of flour");
  set_long("This is large sack full of flour, which has started to rot.\n");
set_weight(10);
set_value(0);
set_strength(10000);
}
query_no_save() { return 1; }
