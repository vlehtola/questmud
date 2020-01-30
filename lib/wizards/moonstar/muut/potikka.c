#include "/guilds/witch/effects.c"
inherit "obj/armour";
start()
{
   set_class(1);
   set_name("potion");
   set_short("A beautiful red potion");
   set_long("Test potion.\n");
}
init() {
  add_action("drink", "drink");
}
drink(str) {
  if(str == "potion") {
  int time;
  time = random(20)+60;
  if(this_player()->query_wis_effect()) {
          write("Nothing happens.\n");
          destruct(this_object());
          return 1;
  }
  shadow(this_player(), 1);
  update_stats();
  call_out("end_wis_effect", time);
  write("You feel your wisdom is rising.\n");
        this_player()->update_stats();
        this_player()->set_wis(this_player()->query_wis()+(100));
}
end_wis_effect() {
        write("You feel your wisdom lowering.\n");
        this_player()->update_stats();
        destruct(this_object());
return 1;
}
write("drink what?\n");
return 1;
}
