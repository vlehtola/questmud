inherit "obj/monster";

reset(arg) {
  ::reset(arg);
    set_animal(1);
    set_name("beetle");
    set_alias("");
    set_short("a beetle");
    set_long("With it's oily black carapace the beetle blends easilly into the natural shades given\n" +
             "by trees, boulders and other crevices that it creeps into. It scurries along the ground\n" +
             "in search for the nearest piece of green leaf.\n");
}
