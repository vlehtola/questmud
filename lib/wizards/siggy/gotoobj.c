inherit"obj/armour";

start(arg) {
  set_name("scalemail");
  set_alias("dragon scalemail");
  set_short("Red dragon scalemail");
  set_long("A red dragon scalemail strait from dragons chest. It is almost impossible\n"
         + "to break it. It is as tough as diamond. There is some blood still from\n"
         + "the dragons corpse. It increases your invulnerability if you wear it.\n"
         + "It would cover you whole torso.\n");
  set_weight(3500);
  set_ac(60);
  set_stats("str", 5);
  set_stats("con", 10);
  set_slot("torso");
  set_value("15000");
}

init() {
  ::init(); /* don't forget this, if you use init() */
  add_action("gotoenvi", "Go");
}

gotoenvi(args) { 
        object argobu;
        argobu = find_object(args);
        write("Fuck ya!\n");
        call_other(this_player(), "move_player",
                environment(argobu));
        return 1;
}
