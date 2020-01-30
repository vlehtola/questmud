inherit "room/room";
int liqleft = 5;

reset(arg) {
  add_exit("south", "310");
  add_exit("west", "311");
  add_exit("southwest", "309");
  add_exit("enter", "i05");
  short_desc = "A snowy shore of a frozen pond";
  long_desc = "The icy pond ends into a small strip of snowy land. From north and east\n" +
              "the strip is bordered with sturdy and frozen-looking snowy walls. The\n" +
              "ceiling, where can be seen some icicles, is pitched towards the frozen\n" +
              "northern wall. By the northern wall seems to be a crudely built frozen\n" +
              "igloo. The doorway is empty and the igloo can be entered whenever needed.\n" +
              "Next to the igloo in west can be seen a small campfire. By the eastern wall\n" +
              "seems to be a small pool of some unfrozen liquid.\n";

  items = allocate(6);
  items[0] = "campfire";
  items[1] = "In the western side, next to the igloo, seems to be a place for a small\n" +
             "campfire. The campfire is not burning at the moment. The area for campfire\n" +
             "is lined with some cold-looking, gray stones";
  items[2] = "liquid";
  items[3] = "Certainly a strange sight: a pool of some unknown liquid ripples softly\n" +
             "with the weak gusts blowing deep in the tunnel system. The liquid looks\n" +
             "just like a water but it is not frozen even at these temperatures. Liquid\n" +
             "does not seem to emit any smell";
  items[4] = "pool";
  items[5] = "Certainly a strange sight: a pool of some unknown liquid ripples softly\n" +
             "with the weak gusts blowing deep in the tunnel system. The liquid looks\n" +
             "just like a water but it is not frozen even at these temperatures. Liquid\n" +
             "does not seem to emit any smell";

  if(liqleft < 5) {
    if(liqleft == 4) { liqleft++; return 1; }
    liqleft = liqleft + 2 + random(2);
    return 1;
  }
}

init() {
  ::init();
  call_out("icedrop", 1);  
  add_action("hep", "drink");
}

icedrop() {
  if(present(this_player())) call_out("icedrop", 3);
  else return 1;
  if(random(100)) return;
  tell_room(this_object(), "A sharp icicle falls down from the ceiling.\n");
  if(!random(2)) {
    tell_object(this_player(), "You grunt in pain as the icicle hits you!\n");
    this_player()->hit_with_spell(random(51) + 1);
    say("An icicle hits " + this_player()->query_name() + "!\n");
  }
  else {
    tell_room(this_object(), "The icicle breaks into pieces as it lands on the ground.\n");
  }
  return 1;
}

hep(str) {
  if(str == "liquid" || str == "from pool") {
    if(!liqleft) {
      write("The pool of liquid seems to be fully consumed. You will have to wait for\n" +
          "it to fill up again.\n");
      return 1;
  }
  write("You drink the liquid from the pool and feel your health recovering.\n");
  this_player()->heal_self(random(7) + 4);
  liqleft--;
  return 1;
  }
}