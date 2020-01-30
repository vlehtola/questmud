inherit "obj/weapon";
 
start() {
    set_class(5);
    set_sub_type("great axe");
    set_short("The great axe named Executioner");
    set_long("The axe you hold in your hand, is remarkable. The handle is made of some\n"+
             "very strong material, yet it seems to fit into your hand with perfect ease.\n"+
             "Your hands mold into the handle like they were meant there. The blade is made\n"+
             "sparkling mithril, and is perfectly flawless.\n"+
             "'type <sword>'\n");
}
 
int swmuoto;
 
init() {
  ::init();
  add_action("sword", "sword");
  add_action("axe", "axe");
}
 
sword() {
  if(swmuoto) {
  write("The Executioner is already in sword mode.\n");
  return 1;
} else {
  set_class(5);
  set_sub_type("broad sword");
  set_short("The broad sword named Executioner");
  set_long("The sword you hold in your hand, is remarkable. The handle is made of some\n"+
           "very strong material, yet it seems to fit into your hand with perfect ease.\n"+
           "Your hands mold into the handle like they were meant there. The blade is made\n"+
           "sparkling mithril, and is perfectly flawless.\n"+
           "'type <axe>'\n");
  write("As you press a small button at the hilt, the blades retract into a single great blade.\n");
  say(this_player()->query_name()+" presses a button on his axe, making the axe shake and shift.\n");
  swmuoto = 1;
  return 1;
    }
}
 
axe() {
  if(swmuoto) {
  set_class(5);
  set_sub_type("great axe");
  set_short("The great axe named Executioner");
  set_long("The axe you hold in your hand, is remarkable. The handle is made of some\n"+
           "very strong material, yet it seems to fit into your hand with perfect ease.\n"+
           "Your hands mold into the handle like they were meant there. The blade is made\n"+
           "sparkling mithril, and is perfectly flawless.\n"+
           "'type <sword>'\n");
  write("You press the small button on the hilt, and the two blades quickly part from each other.\n");
  say(this_player()->query_name()+" presses a button on his sword, making it shake and shift.\n");
  swmuoto = 0;
  return 1;
} else {
 write("The executioner is already in axe mode.\n");
  return 1;
  }
}
