inherit "room/room";
object monster;
int numPortalsClosed, numSpiritCalls;

reset(arg) {

  if ( arg ) return;

  /* setting exits */
  add_exit("southwest","outmap: 147 164");
  add_exit("flames","/wizards/gynter/element/fire/1");
  add_exit("pillar","/wizards/gynter/element/air/1");
  add_exit("hole","/wizards/gynter/element/earth/1");
  add_exit("swim","/wizards/gynter/element/water/1");

  /* setting desc */
  short_desc = "Connection point for all of the elements of nature.";
  long_desc = "This is a large room made out of all the elements in nature.\n"+
  "In this room the four gateways are located. In the middle of\n"+
  "the room there is a small fire, a pillar, a hole and a pool.\n"+
  "There are also signs on the wall.\n";

  items = allocate(10);
  items[0] = "fire";
  items[1] = "The flames burns for the fire plane.";
  items[2] = "pillar";
  items[3] = "This pillar is made of solid air.";
  items[4] = "hole";
  items[5] = "This is the gateway to the earthplane.";
  items[6] = "pool";
  items[7] = "This is the gateway to the water world.";
  items[8] = "signs";
  items[9] = "There is a fifth element, spirit. To evoke it one must wander to the\n four elements and get the keys from the elemental lords.\n Only by placing those keys in the same room as the portals\n is it possible to open the door to the fifth realm\nSome say you have to speak the spirits name to open the gateway.";

  numPortalsClosed = 0;
  numSpiritCalls = 0;
}

init() {
  ::init();
  add_action("place", "place");
  add_action("say", "say");
}

place(str) {
  if(!str) return 0;
  //Check added by Rag -- 25.9.04
  if ( !present(str,this_player()) ) {
    write("But you don't have a "+str+".\n");
    return 1;
  }
  if ( present(str,this_player())->query_no_save() ) {
    write("Your "+str+" seems to be a fake.\n");
    return 1;
  }
  if(str == "ruby") {
    write("As you place the ruby into the flames they start to move\n");
    write("more and more slowly until they stop.\n");
        write("After what seems like an eternity they suddenly dissapear\n");
          say("The flames dies out.\n");
    /* remove the exit to the fire planes */
    remove_exit("flames");
    this_player()->set_quest("Destroy the entrance to the fire plane");
    numPortalsClosed++;
    destruct(present("ruby",this_player()));
          return 1;
  }

  if (str == "sapphire") {
    write("As you place the sapphire on the pillar, the pillar starts to crumble\n");
    write("and after some time it is only a pile of dust on the floor.\n");
    say("The wind starts to blow stronger and the pile of dust vanishes into the air.\n");
    /* removing exit to the air planes */
    remove_exit("pillar");
    this_player()->set_quest("Destroy the pillar to the air realm");
    numPortalsClosed++;
    destruct(present("sapphire",this_player()));
    return 1;
  }

  if(str == "diamond") {
    write("As you place the diamond into the hole the ground starts to shake\n");
    write("and the walls of the hole starts to deteriate and suddenly\n");
    write("the hole is filled with dirt.\n");
    say("The ground shakes and when it stops there isn't a singel mark where the hole was.\n");
    /* removing exit to the earth planes */
    remove_exit("hole");
   this_player()->set_quest("Destroy the gateway to the earth plane");
                numPortalsClosed++;
destruct(present("diamond",this_player()));
    return 1;
  }

  if(str == "emerald") {
    write("As you place the emerald on the surface of the water the surface starts\n");
    write("to ripple and soon there are high waves in the small pool.\n");
          write("And as fast as the waves started they stops and the water sinks away.\n");
    say("The water starts vanishing and suddenly all that is left in the pool is some dust.\n");
    /* removing exit to the water planes */
    remove_exit("swim");
    this_player()->set_quest("Destroy the entrance to the water plane");
    numPortalsClosed++;
    destruct(present("emerald",this_player()));
    return 1;
  }
}

say(str) {
  if(str == "tirpis" && !monster) {
    if(numPortalsClosed < 4) return;
    if((this_player()->query_quests("Destroy the entrance to the water plane")) &&
       (this_player()->query_quests("Destroy the gateway to the earth plane")) &&
       (this_player()->query_quests("Destroy the pillar to the air realm")) &&
       (this_player()->query_quests("Destroy the entrance to the fire plane"))) {
      if(numSpiritCalls >= 1) {
        write("The spirit has already been vanquished.\n");
        return;
      }
      write("As you growl the name of the fifth element the whole room\n");
      write("starts vibrating and the precense you felt before almost crushes your\n");
      write("mind when it appears and screams out it's name : Tirpis.\n");
      numSpiritCalls++;
      this_player()->set_quest("Release the great spirit element");
          /* getting the mob */
      monster = clone_object("/wizards/gynter/element/mobs/spirit");
      move_object(monster, this_object());
    } else {
      write("The presence of another gateway stops the fifth element.\n");
    }
  }
}
