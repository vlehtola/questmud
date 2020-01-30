inherit "obj/food";

reset(arg) {
::reset(arg);
if (arg) { return; }
set_name("suffeli");
set_short("A bar of 'suffeli'");
set_long("The chocolate bar is wrapped into a pink and burgundy wrapper, and has\n"+
         "'Suffeli' marked upon it. You feel this was a gift from Walla.\n");
set_weight(3);
set_value(0);
set_strength(100000);
}

set_id(arg) {
    return name == arg;
}
