inherit "room/room";
object monster;
int giggle;
reset(arg) {
    if (!monster) {
     if (giggle != 21) {      
     monster = clone_object("/wizards/nalle/jerusalem/monsters/derman");
     move_object(monster, this_object()); 
     giggle = 21;
     }
    }
    property = allocate(1);
    property[0] = "no_summon";
  if(arg) return;
  add_exit("east","wizards/nalle/jerusalem/golb3");
  add_exit("north","wizards/nalle/jerusalem/gola2");
  add_exit("south","wizards/nalle/jerusalem/golpath");
  short_desc = "A meandering path to Golgatha";
  long_desc =
"You are on a cobblestoned path that meanders south, to what\n" +
"you suspect to be Golgatha, The Hill of Skulls. You now\n" +
"understand why the people are so interested in what is happening,\n" +
"they are throwing rocks at a man who is to be crucified, and en\n"+
"route to Golgatha.\n";
}

init() {
    ::init();
   add_action("map", "map");
   add_action("south", "south");
}

south() {
  say(this_player()->query_name()+" tries to go south, but cannot get through all the people standing in your way.\n");
  write("Dozens of people are standing in your way, and you cannot get through.\n");
  return 1;
}

map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/gmap");
   return 1;
}
