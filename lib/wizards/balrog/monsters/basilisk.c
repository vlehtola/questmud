inherit "obj/monster";

reset(arg) {
  ::reset(arg);
    set_animal(1);
    set_name("basilisk");
    set_alias("");
    set_short("a basilisk");
    set_long("With it's grey and green hue, and fearsome appearance. The basilisk, though very\n" +
             "small, has often been considered to be babies to the ever so terrible fire-breathing\n" +
             "dragon. Could this be a baby-dragon?\n");
}
