inherit "/obj/food";

reset(arg) {
::reset(arg);
if (arg) { return; }

set_name("potion");
set_short("A blue potion");
set_long("A strange-looking blue potion bubbles smoothily.\n");
set_weight(100);
}
