
inherit "obj/armour";

object dragon;

start() {
set_class(2);
set_name("amulet");
set_short("Amulet of Dragons");
set_long("Moonstarin pikkulelu. Dragon tulee:dragoni\n");
  set_stats("str", 30);
  set_stats("con", 30);
  set_stats("dex", 30);
  set_stats("spr", 30);
set_value(10000);
set_weight(10);
set_slot("amulet");
}

init() {
  ::init();
  add_action("dragoni", "dragoni");
}


dragoni (str)  {
    dragon = clone_object("/wizards/moonstar/test/malys.c");
    move_object(dragon, this_object());
    say("Malystryx flies in.\n"
        "Malystryx says: You called Moonstar.\n");
}
