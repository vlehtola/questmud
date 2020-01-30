inherit "/obj/food";

reset(arg) {
::reset(arg);
if (arg) { return; }

set_name("apple");
set_short("A juicy apple");
set_long("Quite big and juicy-looking apple. The apple is mostly greenish-yellow\n" + 
         "from its colouring and it smells good. It looks suitable for eating.\n");
set_weight(20);
set_strength(800);
}
