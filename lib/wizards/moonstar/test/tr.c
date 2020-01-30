inherit "room/room";

int i;

reset(arg) {
    if(arg) return;

    i = 0;

    short_desc = "In the darkness";
    long_desc = "You can hardly see in here. Everything is black and shapeless.\n"+
"You feel like somebody is watching.\n"+
"Despite the darkness, something makes a long ray of light.\n";
    set_light(1);
        items = allocate(6);

items[0] = "ray";
items[1] = "Ray of light is coming out from square shaped button.";
items[2] = "light";
items[3] = "Ray of light is coming out from square shaped button.";
items[4] = "button";
items[5] = "Small square shaped button is attached to the wall.";
add_exit("north", "/wizards/moonstar/areas/wasteland/room46.c");

}
init() {
    ::init();
   add_action("push", "move");
   add_action("push", "push");
}

push (str) {
   if(str == "button") {
      object thief;
                thief = clone_object("/wizards/moonstar/areas/wasteland/monsut/thief");
                move_object(thief, this_object());
i = 1;
  say(this_player()->query_name()+"pushes the button and small *click* can be heard.\n");  
tell_room(this_object(), "A thief jumps in.\n");
write("You push the button and secret passage opens to the south.\n");
  add_exit("south", "/wizards/moonstar/areas/wasteland/fortress/yard3.c");
  return 1;
   }
  return 0;

}
