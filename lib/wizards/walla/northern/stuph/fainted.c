inherit "obj/base_object";
 
reset(arg) {
::reset(arg);
if (arg) { return; }
set_name("soldier");
set_alias("conscript");
set_alias("dwarf");
set_short("A fainted dwarven conscript");
set_long("You see a fainted dwarf, lying on the floor, still wearing his armour. He\n"+
         "seems to have fainted from the foul smell here");
set_weight(100000);
set_value(1);
set_no_get(0);
}
 
set_id(arg) {
    return name == arg;
}
