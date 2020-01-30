inherit "obj/weapon";

start() {
    set_class(7);
    set_sub_type("broad sword");
    set_short("Black blade of the shadows");
    set_alias("blade");
    set_long(
"This sword was once wielded by the dark powers in the\n"+
"damned forest of Mor-aloth. It is a blade created by the\n"+
"powers of the shadow and darkness for the purpose of\n"+
"unknown evil. The steel its forged from glows dark light.\n"+
"Carvings on the blade describe somekind of horrid rituals\n"+
"in which this blade was used. The cutting edge is still as\n"+
"as sharp as new.\n");
    set_stats("con", -3);
    set_stats("dex", -3);
    set_stats("str", 8);
    value = 3000;
}

hit() {
  call_other(wielded_by, "reduce_sp", 2);
  write("The sword seems to drain your power!\n");
}
