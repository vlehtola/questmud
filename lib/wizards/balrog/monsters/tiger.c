inherit "obj/monster";

reset(arg) {
  ::reset(arg);
    set_animal(1);
    set_name("tiger");
    set_alias("");
    set_short("a tiger");
    set_long("This black and orange striped creature is unmistakingly a tiger. It's one of\n" +
             "the many fears for the people in these lands. It spots you and glares with it's\n" +
             "keen eyes at you. A hungry glare it is..\n");
}
