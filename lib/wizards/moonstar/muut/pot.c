inherit "obj/armour";
        int time;
start()
{
   set_class(1);
   set_alias("potion");
   set_short("A beautiful red potion");
   set_long("Test potion.\n");
}
init() {
  add_action("drink", "drink");
}
drink(str) {
  if(str == "potion") {
        if(this_player()->query_wis_boost()) {
                write("The potion doesn't affect you.\n");
                return 1;
}
        time = random(20)+600;
        write("You drink the potion.\n");
        clone_object("/wizards/moonstar/muut/wisboost")->start(this_player(),time);
return 1;
}
return 1;
}

