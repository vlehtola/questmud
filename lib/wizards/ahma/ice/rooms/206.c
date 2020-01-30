inherit "room/room";

reset(arg) {
  add_exit("north", "205");
  add_exit("south", "207");
  add_exit("east", "203");
  add_exit("northeast", "202");
  add_exit("hole", "nest04");
  short_desc = "A large opening full of icicles";
  long_desc = "You are standing in a huge opening. The ceiling is at least in the height\n" +
              "of thirteen feet. The ground is almost fully frozen, though some piles of\n" +
              "soft snow can be seen here and there. The opening continues to east- and\n" +
              "northwards. A spacious-looking tunnel is located in south and a small hole\n" +
              "in the ground by the western wall. Some faint drops of blood can be seen\n" +
              "on the ground. The ceiling of the cavern is full of sharp icicles.\n";
  items = allocate(4);
  items[0] = "blood";
  items[1] = "Faint drops of blood arrive somewhere in east and lead into a hole located\n" +
             "by the western wall. Maybe some predator has moved its prey into its nest\n" +
             "before eating it";
  items[2] = "hole";
  items[3] = "A small hole is located in the ground by the western wall. It might be an\n" +
             "entrance to some animal's nest";
  if(!present("wolverine")) move_object(clone_object("/wizards/ahma/ice/mob/wolverine"), this_object());
}

icedrop() {
  if(present(this_player())) call_out("icedrop", 3);
  else return 1;
  if(random(180)) return;
  tell_room(this_object(), "A sharp icicle falls down from the ceiling.\n");
  if(!random(2)) {
    tell_object(this_player(), "You grunt in pain as the icicle hits you!\n");
    say("An icicle hits " + this_player()->query_name() + "!\n");
    if(this_player()->query_name() == "Wolverine") return;
    this_player()->hit_with_spell(random(38) + 1);
    
  }
  else {
    tell_room(this_object(), "The icicle breaks into pieces as it lands on the ground.\n");
  }
  return 1;
}