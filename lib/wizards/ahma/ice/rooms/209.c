inherit "room/room";

reset(arg) {
  add_exit("west", "210");
  add_exit("east", "205");
  short_desc = "A pitching snowy tunnel";
  long_desc = "The tunnel floor is pitching downwards when moving to west. Tunnel's\n" +
              "ceiling is about eight and a third feet high, and it seems to be pitching\n" +
              "along with the ground. The ground is covered in thin layer of soft\n" +
              "snow, but the walls are bald. The ice, which covers the walls, seems\n" +
              "to emit or reflect the light into the tunnel. In east can be seen a\n" +
              "spacious opening. Some icicles hang from the ceiling.\n";
  if(!present("wolverine")) move_object(clone_object("/wizards/ahma/ice/mob/wolverine"), this_object());
  if(!present("baby")) move_object(clone_object("/wizards/ahma/ice/mob/byeti"), this_object());
}

icedrop() {
  if(present(this_player())) call_out("icedrop", 3);
  else return 1;
  if(random(180)) return;
  tell_room(this_object(), "A sharp icicle falls down from the ceiling.\n");
  if(!random(2)) {
    tell_object(this_player(), "You grunt in pain as the icicle hits you!\n");
    say("An icicle hits " + this_player()->query_name() + "!\n");
    if(this_player()->query_name() == "Baby yeti") return;
    if(this_player()->query_name() == "Wolverine") return;
    this_player()->hit_with_spell(random(38) + 1);
  }
  else {
    tell_room(this_object(), "The icicle breaks into pieces as it lands on the ground.\n");
  }
  return 1;
}