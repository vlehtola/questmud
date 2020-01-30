inherit "obj/base_object";

reset(arg) {
::reset(arg);
if (arg) { return; }
set_name("rag");
set_alias("hv0700123123");
set_short("A rag, ripped from the cloak of castle North Face");
set_long("You are holding in your hands the symbol from the cloak of Castle\n"+
         "North Face. It represents the symbol of the anvil and the axe,\n"+
         "the symbol of the dwarves of castle North Face.\n");
set_weight(1);
set_value(1);
set_no_get(1);
}

set_id(arg) {
    return name == arg;
}



