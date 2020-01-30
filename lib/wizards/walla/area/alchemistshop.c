inherit "room/room";
object monster;
reset(arg) {

if(arg) return;
  if (!monster) {
      monster = clone_object("/wizards/walla/area/monsters/alchemist.c");
      move_object(monster, this_object());
}      

add_exit("east","/wizards/walla/area/ujar5.c");


short_desc = "The alchemist shop";
long_desc = "This is a very important and popular place in the Jerichan society. The\n"+
            "ability to make gold is the skill known only by the alchemist himself.\n" +
            "But even he has not, to this very day, found the way to make that noble\n"+
            "meterial, even though he has tried for a good number of years. The shop\n"+
            "is lit up with burning torches, which are on the walls. A huge black\n"+
            "anvil is in the middle of the room. Inside the north wall, is built a\n"+
            "small fireplace, which is burning just now.\n";

    items = allocate(4);
    items[0] = "fireplace";
    items[1] = "It's inside the north wall, and it's burning with small flame. There can be melted metals and stuff, because the heat in there is tremendous";
    items[2] = "anvil";
    items[3] = "A huge black anvil is placed in the middle of the room. It's suited only for forging melted metals";

  set_not_out(3);

  property = allocate(3);
  property[0] = "no_spell";
  property[1] = "no_skill";
  property[2] = "no_kill";
}

