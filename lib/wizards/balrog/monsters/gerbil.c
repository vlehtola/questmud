inherit "obj/monster";

reset(arg) {
  ::reset(arg);
    set_animal(1);
    set_name("gerbil");
    set_alias("");
    set_short("a gerbil");
    set_long("A grey gerbil scutters from one stone to another, scavaging for food.\n" +
             "Peeking up from behind one of the rocks it notices you and makes a\n" +
             "serious effort in keeping itself hidden from you.\n");
}
