//written by C

#define GUARD_ROOM      "/wizards/irmeli/castle/wall2.c"
int hits;

short() { return "An old catapult"; }

long(str) {
    write("An old catapult was used in the conquer attempt. Its wheels are broken and therefore\n");
    write("you can't move it. It's directed towards the castle. A layer of rust is covering it.\n");
    return;
}

id(str) { return str == "catapult"; }

get(str) {
    if (str == "catapult") {
        write("You can't take the catapult.\n");
        return 0;
    }
    return 0;

}


// return hit_perc
int get_chance(string size) {
  switch(size) {
  case "small": return 90;
  case "medium": return 60;
  case "big": return 30;
  }
  return 0;
}

// call with add_action
status shoot(string arg) {
  string size;
  int chance;
  object guard, rock;
  if(!arg || sscanf(arg, "%s rock", size) != 1) {
    write("Usage: shoot [small|medium|big] rock\n");
    return 1;
  }

  if ( size != "small" && size != "medium" && size != "big" ) {
    write("Usage: shoot [small|medium|big] rock\n");
    return 1;
  }


// Check if we have the right rock

// Is the player carrying one
  rock = present(size,this_player());

  if ( !rock ) {
    // In the room with the catapult
    rock = present(size,environment(this_object()));
  }
  if ( !rock ) {
    write("There aren't any "+size+" rocks here.\n");
    return 1;
  }

// The rock is here so we destroy it when it's shot

  destruct(rock);

  this_player()->fix_weight();

  chance = get_chance(size);
  if(chance < random(101)) {
     write("The rock misses the guard.\n");
     return 1;
  }

// we have a hit

  GUARD_ROOM->wake_up_call();
  guard = present("guard", find_object(GUARD_ROOM));
  if(!guard) {
    write("Someone has already killed the guard.\n");
    return 1;
  }
  write("You hit the guard in the face.\n");

  hits += 100-chance;
  if(hits > 100) {
    write("The guard dies as the rock hits his head.\n");
    write("The drawbridge lowers and you walk across the bridge to the other side.\n");
    write("The drawbridge closes behind you.\n");
    guard->death();
    move_object(this_player(),"/wizards/irmeli/castle/r1.c");
    this_player()->look();
    this_player()->set_quest("Get inside the castle of Asgroth");
    hits = 0;
  }
  return 1;
}

init() {
  add_action("shoot", "shoot");
}

