inherit "room/room";
int broken;

reset(arg) {
  if(!present("adult")) move_object(clone_object("/wizards/ahma/ice/mob/ayeti"), this_object());
  present("adult")->specname();
  if(arg) return;
  add_exit("north", "210");
  short_desc = "An end of a snowy tunnel";
  long_desc = "The snowy tunnel ends into a bald, icy wall. The ceiling is about eight\n" +
              "and a third feet high. The ground is covered in thin layer of soft snow,\n" +
              "but all of the walls are bald. The ice, which covers the walls, seems\n" +
              "to emit or reflect some light into this part of the tunnel. Behind the\n" +
              "icy eastern wall seems to be something suspicious. The snowy tunnel\n" +
              "leads north.\n";
  items = allocate(2);
  items[0] = "wall";
  items[1] = "Behind the eastern wall there seems to be something strange. It almost\n" +
             "seems like there would be another room behind it, but it might be some\n" +
             "strange reflection, as well. The one thing is sure: you do not have an\n" +
             "idea why this wall would be frozen solid if there would be another room\n" +
             "behind it";
}

init() {
  ::init();
  add_action("hep", "dig");
  add_action("hep", "break");
  add_action("hep", "hack");
  add_action("hep", "hit");
}

hep(str) {
  if(str == "wall") {
    if(!present("shovel", this_player())) {
      write("You try to dig the wall with your bare hands, but it seems that the wall has\n" +
            "already frozen. You will need some equipment to dig with to get through the wall.\n");
      say(this_player()->query_name() + " tries to dig through the wall with " + this_player()->query_possessive() + " bare hands, but does not\n" +
          "manage to penetrate the hard surface.\n");
      return 1; }
    if(broken) return;
    write("You dig the wall open with your shovel. Behind the broken wall seems to be\n" +
          "another room.\n");
    say(this_player()->query_name() + " digs the wall open with " + this_player()->query_possessive() + " shovel. Behind the broken wall is revealed\n" +
        "another room.\n");
    add_exit("east", "212");
    broken = 1;
    long_desc = "The snowy tunnel ends into a bald, icy wall. The ceiling is about eight\n" +
                "and a third feet high. The ground is covered in thin layer of soft snow,\n" +
                "but all of the walls are bald. The ice, which covers the walls, seems\n" +
                "to emit or reflect some light into this part of the tunnel. The eastern\n" +
                "wall has been hacked open, giving an exit to the east. The snowy tunnel\n" +
                "leads north.\n";
    items[1] = "Where the icy wall used to be is now an entrance further into the snowy tunnels";
    return 1;
  }
  else return;
}
