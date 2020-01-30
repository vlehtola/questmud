inherit "room/room";
object monster;

reset(arg) 
{

 if(!monster) 
 {
  monster = clone_object("/wizards/moonstar/areas/wasteland/monsut/bonedragon");
  move_object(monster, this_object());
 }

 if(arg) return;

 add_exit("east" , "/wizards/moonstar/areas/wasteland/cave6.c");

 short_desc = "Dead end";

 long_desc = "You have come to dead end. The room is very spacious.\n"+
 	"Water runs down from the wall forming a little pond in the\n"+
	"middle of room. It is really cold in here.\n"+
	"Skeleton lies in the corner.\n";

  set_light(5);

  	items = allocate(6);
        items[0] = "skeleton";
        items[1] = "Skeleton is staring at the pond.\n";
	items[2] = "pond";
  	items[3] = "The water in the pond is really dark making it impossible to see the bottom.";
  	items[4] = "wall";
  	items[5] = "Water flows from the little holes.\n";
}

init () 
{
 ::init();
 add_action("dive","dive");
}

dive (str) 
{
 if(str == "pond") 
   {
    write("You dive in the cold water and found a small cave!\n");
    move_object(this_player(), "/guilds/fighter/bladedancers");
    return 1;
   }
 write("Dive where?\n");
 return 1;
}

