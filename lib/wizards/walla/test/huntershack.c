#define AREAPATH "wizards/nalle/plateau/"

inherit "room/room";

object monster;
int searched;

reset(arg) {
  if(arg) return;
  add_exit("out",AREAPATH+"19_-1");
  short_desc = "A hunter's shack";
  long_desc =
"This shack must belong to some great hunter, as there are hides\n"+
"of all sorts of wild beasts on the walls, and weapons on display.\n"+
"The interior of the shack is somewhat spartan but cosy. You notice\n"+
"some interesting bottles on the shelves. A thick oaken door leads out.\n";

  items = allocate(4);
  items[0] = "shelves";
  items[1] = "Wow, there are some bottles of liquor on the shelves.\n";
  items[2] = "bottles";
  items[3] = "Wow, there are some bottles of liquor on the shelves.\n";

if(!monster)    {
 monster = clone_object(AREAPATH+"monsters/jaegermeister");
 move_object(monster, this_object());
                }
}


search_finished(str) {
 object ob;
	if(!searched )
         if((str == "shelves" || str == "bottles") && present("rutger", this_object() ) ) 
	   {
            write("You take a bottle of liquor from the shelves, but drop it from fright as Rutger gets mad!\n");
            say(this_player()->query_name()+ " takes a bottle from the shelves, and Rutger is not happy!\n");
            ob = clone_object("/wizards/nalle/plateau/eq/jekkupullo");
            move_object(ob,this_object());
            this_player()->attack_object(present("rutger", this_object()));
            searched = 1;
            return 1;
           }
        write("You find nothing special, all the bottles on the shelves are empty.\n");
        say(this_player()->query_name()+ " finds nothing.\n");
        return 1;
}

