inherit "obj/monster";

reset(arg) {
  ::reset(arg);
    set_animal(1);
    set_name("bumblebee");
    set_alias("");
    set_short("a bumblebee");
    set_long("The bigger one in the 'family'. It's large body and lack of respect for gravity makes it an\n" +
             "interesting creature. It's wings and disproportional body has been the subject of many\n" +
             "philosophers throughout the times.\n");
}
