inherit "obj/monster";

reset(arg) {
  ::reset(arg);
    set_animal(1);
    set_name("bear");
    set_alias("");
    set_short("a bear");
    set_long("A big brown bear is tumbling across the country. Even through the thick fur\n" +
             "it's muscles are visible. Creating ripples thru the fur it makes the resident\n" +
             "light cast a dreamy shimmer across it..\n");
}
