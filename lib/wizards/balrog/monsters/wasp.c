inherit "obj/monster";

reset(arg) {
  ::reset(arg);
    set_animal(1);
    set_name("wasp");
    set_alias("");
    set_short("a wasp");
    set_long("The more aggressive species compared to it's fellow cousins. The wasp has a mean look to it.\n" +
             "It's thin body and angled shapes makes it look like a flying pin-needle. A pin-needle that is\n" +
             "out to get _you_!!\n");
}
