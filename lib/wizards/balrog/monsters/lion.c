inherit "obj/monster";

reset(arg) {
  ::reset(arg);
    set_animal(1);
    set_name("lion");
    set_alias("");
    set_short("a lion");
    set_long("The creature lying on the ground ahead of you is none other than the lion.\n" +
             "It has a magnificent fur and thick mane. A tawny body and a tufted tail to\n" +
             "go along with it.\n");
}
