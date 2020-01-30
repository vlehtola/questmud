inherit "obj/base_object";
 
reset(arg) {
::reset(arg);
if (arg) { return; }
set_name("soldier");
set_alias("conscript");
set_alias("dwarf");
set_short("A semi-conscious dwarven conscript");
set_long("You see a dwarf, trying to wake up, lying on the floor, still wearing\n"+
         "his armour. He seems to have fainted from the foul smell here.\n");
set_weight(100000);
set_value(1);
set_no_get(0);
}
 
set_id(arg) {
    return name == arg;
}
