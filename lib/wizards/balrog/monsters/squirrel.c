inherit "obj/monster";

reset(arg) {
  ::reset(arg);
    set_animal(1);
    set_name("squirrel");
    set_alias("");
    set_short("a squirrel");
    set_long("A squirrel jumps around, making great archs in the air with it's slender\n" +
             "body and tail. Searching for it's favourite food. An acorn, a cone or\n" +
             "something else equally nutritious.\n");
}
