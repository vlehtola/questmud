inherit "room/room";
int moved;

reset(arg) {
  if(!present("golem 2")) move_object(clone_object("/wizards/ahma/ice/mob/igolem"), this_object());
  if(!present("golem 2")) move_object(clone_object("/wizards/ahma/ice/mob/igolem"), this_object());
  if(arg) return;
  
  add_exit("down", "secret02");
  short_desc = "Deeper in the polar bears' nest";
  long_desc = "This tunnel is very dimly lit, the only light entering the room is\n" +
              "shimmering in from the hole in the upper part of the tunnel. The walls\n" +
              "in this tunnel look very suspicious, they seem to be soaked with blood.\n" +
              "Some bowels can also be spotted hanging here and there from the walls.\n" +
              "In addon to the walls' outlook, a horrible stench of rare, torn flesh\n" +
              "can be felt rising up from somewhere below this room. The tunnel leads\n" +
              "further down. A blocked hole can be seen leading up from here.\n";

  items = allocate(4);
  items[0] = "hole";
  items[1] = "A hole seems to be leading out from the tunnel in the upper part of it.\n" +
             "The hole cannot be trespassed due to a corpse which is blocking it.\n" +
             "Regardless of the corpse, some light is shimmering into this tunnel\n" +
             "throught the hole";
  items[2] = "walls";
  items[3] = "The steep tunnel walls shine in deep red. The red colouring is definitely\n" +
             "made with blood, in this case, lots of blood. Different entrails can also\n" +
             "be seen hanging from the walls among with the blood. You wonder if this\n" +
             "is a conscious work of art or subconscious manifestation of primal rage";
             
  set_blocker("golem", "down");
}

init() {
  ::init();
  add_action("hep", "move");
}

hep(str) {
  if(str != "corpse") return;
  if(present("corpse", this_object())) {
    write("You don't know which corpse to move. Get rid of the other first.\n");
    return 1;
  }
  if(!moved) {
    write("You push the corpse away from the entrance, opening it.\n");
    "/wizards/ahma/ice/rooms/nest01"->corpsemoved();
    add_exit("out", "nest01");
    moved = 1;
    return 1;
  }
  else {
    write("The corpse has already been removed from the exit.\n");
    return 1;
  }
}

corpsemoved() {
  add_exit("out", "nest01");
  moved = 1;
  long_desc = "This tunnel is very dimly lit, the only light entering the room is\n" +
              "shimmering in from the hole in the upper part of the tunnel. The walls\n" +
              "in this tunnel look very suspicious, they seem to be soaked with blood.\n" +
              "Some bowels can also be spotted hanging from the walls here and there.\n" +
              "In addon to the walls' outlook, a horrible stench of rare, torn flesh\n" +
              "can be felt rising up from somewhere below this room. The tunnel leads\n" +
              "further down. An open hole can be seen leading out from this tunnel.\n";
  items[1] = "You see nothing special";
  return 1;
}

corpsenotmoved() {
  remove_exit("out");
  moved = 0;
  long_desc = "This tunnel is very dimly lit, the only light entering the room is\n" +
              "shimmering in from the hole in the upper part of the tunnel. The walls\n" +
              "in this tunnel look very suspicious, they seem to be soaked with blood.\n" +
              "Some bowels can also be spotted hanging from the walls here and there.\n" +
              "In addon to the walls' outlook, a horrible stench of rare, torn flesh\n" +
              "can be felt rising up from somewhere below this room. The tunnel leads\n" +
              "further down. A blocked hole can be seen leading up from here.\n";
  items[1] = "A hole seems to be leading out from the tunnel in the upper part of it.\n" +
             "The hole cannot be trespassed due to a corpse which is blocking it.\n" +
             "Regardless of the corpse, some light is shimmering into this tunnel\n" +
             "throught the hole";
  return 1;
}  
