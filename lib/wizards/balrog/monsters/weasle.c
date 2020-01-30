inherit "obj/monster";

reset(arg) {
  ::reset(arg);
    set_animal(1);
    set_name("weasle");
    set_alias("");
    set_short("a weasle");
    set_long("Something moves with a near-lightning speed from one point to another.\n" +
             "You catch a glimpse of the creature and notice that it's a black weasle\n" +
             "with a shimmering fur and white paws, playing some game by itself.\n");
}
