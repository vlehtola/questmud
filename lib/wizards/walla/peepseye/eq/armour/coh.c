inherit "obj/armour"; 
 
reset(arg) {
    ::reset(arg);
    set_name("cloak");
    set_alias("cloak");
    set_short("Cloak of hell");
    set_long("This is the Cloak of hell. It is made of completely black velvet and is very comfortable.\n" +
                   "It seems to be of the protective sort, at least considering it's weight. No matter what, it\n" +
                   "seems to be of a kind that doesn't get very hot during the summer.\n");
    set_ac(10);
    set_value(6900);
    set_weight(300);
    set_slot("cloak");
 
}
