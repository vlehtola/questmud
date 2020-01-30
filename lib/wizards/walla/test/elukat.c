inherit "room/room";
#include "../path.h"

init() {
 ::init();
 add_action("poimi","pick");
 }

 status i;
 int the_squirrel_cometh = 0;

 

 
reset(arg) {
 if(arg) return;
 
 set_light(1);

 short_desc = "On a path between the vines";
 long_desc =

  "The vines are growing on both sides of a small path, leading up to the house\n"+
  "up ahead. The soil is sandy and contains some bits of gravel. The southerly\n"+
  "hillside on which the vineyard is based is considered the best for growing the\n"+
  "Vitis Wallatis grape. This grape, that can come in several colors, is an\n"+
  "extremely delicate and rare sort of grape that needs constant care to produce\n"+
  "the best possible wine. You can notice that the vines are extremely well\n"+
  "maintained. A low stone wall can be seen on your left.\n";

 dest_dir = ({
  AREA_PATH"21", "north",
  AREA_PATH"entrance", "south",
  });

 items = ({
  "vine",    "You see a very well tended vine. The leaves of the vine are a lucious\n"
             "green, and the grapes hanging from the branches look very appealing",
  "grapes",  "A nice bunch of grapes hangs from the well pruned vine",
  "grape",   "You closely look at the fine red grape on the vine",
  "stones",  "The stones on the wall besides you seem to be firmly attached",
  "wall",    "A low wall of stones has been built to border out the vineyard",

  });
  
  call_out("the_squirrel_cometh", 10+(random(30));
 }
int poimi(string str)
 {
 if(!i && str == "grape")
  {
  write("You pick a grape from the vine.\n");

  say(this_player()->query_name()+ " fiddles around with "+this_player()->query_possessive()+" hands in the vines.\n");
  move_object(clone_object("/wizards/kaarle/areas/vineyard/obj/grapet/grape1"),
  this_player());
  i = 1;
    items = ({
     "vine",    "You see a very well tended vine. The leaves of the vine are a lucious\n"
                "green, and the grapes hanging from the branches look very appealing",
     "grapes",  "The grapes seem to have run out on this vine",
     "grape",   "There does not seem to be any more grapes on this vine",
     "stones",  "The stones on the wall besides you seem to be firmly attached",
     "wall",    "A low wall of stones has been built to border out the vineyard",

  });
  return 1;
  }

 write("There doesn't seem to be anymore grapes on this vine.\n");
 say(this_player()->query_name()+ " fiddles around with "+this_player()->query_possessive()+" hands in the vines.\n");
 return 1;
 }
 

 
 int the_squirrel_cometh()
{
tell_room(environment(this_player()),"uuulala, a squirrel.\n");
if(!present("squirrel",this_object())) { 
move_object(clone_object("/wizards/kaarle/areas/vineyard/obj/pullo.c"),this_object()); 
}
}

