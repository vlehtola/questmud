inherit "room/room";

reset(arg) {
  add_exit("north", "107");
  add_exit("enter", "i01");
  short_desc = "A dead end";
  long_desc = "The uncomfortably narrow tunnel ends into a small opening. In the center\n" +
              "of the opening seems to be an igloo made of frozen snow. A place for a\n" +
              "campfire is located east, next to the igloo. The ceiling above the campfire\n" +
              "seems to be thoroughly molten, showing the pale, stony wall under the layer\n" +
              "of frozen snow and ice. Otherwise, the tunnel is covered with snow, and in\n" +
              "the ceiling seems to be hanging some icicles.\n";
  items = allocate(4);
  items[0] = "campfire";
  items[1] = "Just about only warm thing in these freezing caverns. The campfire can be\n" +
             "burn without fearing a collapse, because a strong stony ceiling is located\n" +
             "above the layer of frozen snow. The snow has molten away from the ceiling\n" +
             "above the campfire";
  items[2] = "igloo";
  items[3] = "The igloo has been made by attaching numerous right-angle-shaped pieces of\n" +
             "frozen snow to each other. In whole, the igloo is shaped like the bottom-\n" +
             "part of an egg and turned upside down. In the doorway there does not seem\n" +
             "to be anything to block the way, so the igloo can be entered anytime";
  if(!present("baby")) move_object(clone_object("/wizards/ahma/ice/mob/byeti"), this_object());
}

init() {
  ::init();
  call_out("icedrop", 1);
}

icedrop() {
  if(present(this_player())) call_out("icedrop", 3);
  else return 1;
  if(random(200)) return;
  tell_room(this_object(), "A sharp icicle falls down from the ceiling.\n");
  if(!random(2)) {
    tell_object(this_player(), "You grunt in pain as the icicle hits you!\n");
    say("An icicle hits " + this_player()->query_name() + "!\n");
    if(this_player()->query_name() == "Baby yeti") return;
    this_player()->hit_with_spell(random(31) + 1);
  }
  else {
    tell_room(this_object(), "The icicle breaks into pieces as it lands on the ground.\n");
  }
  return 1;
}