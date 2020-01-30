inherit "room/room";
object baker;
int tehty;
int i = 1;

reset(arg) {
if(arg) return;

  if(!baker) {
    baker = clone_object("/wizards/kaappi/dcity/mobs/leipuri.c");
    move_object(baker, this_object());
}
  add_exit("north", "katu40.c");

  short_desc = "The bakery of Amaranthgard";
  long_desc = "You have arrived to the bakery of the city of Amaranthgard.\n"+
              "A delicious odour of recently baked bread fills you nose.\n"+
              "A very happy looking baker stands behind the counter.\n"+
              "A small sign is placed on the counter.\n";

items = allocate(2);
  items[0] = "sign";
  items[1] = "I'm searhing one brave adventurer to help me. If you're interested,\n"+
             "just type accept quest and I'll give you more information about the task.\n"+
             "-Gimim\n";
}
init() {
  ::init();
  add_action("accept", "accept");
}

accept(str) {
  if(str != "quest") return;
  if(!tehty) {
  move_object(clone_object("/wizards/kaappi/dcity/items/key.c"), this_player());
  write("Baker says: 'Ah, finally one brave one has arrived to our city. Here,\n"+
        "            take this key and go to the warehouse. There are some giant\n"+
        "            rats ruining my food ingredients. Please bring the head of the\n"+
        "            most bigger one to me and I will reward you.\n");

  call_out("valmis", (0), 1);
  tehty = 1;

return 1; }
}
valmis(i) {
items[1] = "The text on the sign is overlined.\n";
return 1;
}
