inherit "obj/monster";

reset(arg) {
  ::reset(arg);
    set_animal(1);
    set_name("dragon");
    set_alias("");
    set_short("a dragon");
    set_long("A larger cousin to the common basilisk, it's stern and fearsome appearance gives it\n" +
             "every right to bear the title of 'dragon'. It's huge body gives it's moves a stiff\n" +
             "feeling. But don't underestimate it's speed or power. It has been known to kill adults..\n");
}
