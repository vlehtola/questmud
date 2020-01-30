inherit "room/room";

reset(arg)
{
if(arg) return;

        
short_desc = "Very old forest.";
long_desc = 
"You are walking in huge forest. All around you are very long \n" +
"trees and small bushes surrounding this path. Walking is very \n" + 
"difficult because all those bushes and spiky rocks. Wind makes \n" + 
"some strange noises. In front of you is very large bush.\n";

add_exit("south", "ff11.c");
add_exit("north", "ff13.c");

items = allocate (4);
items[0] = "trees";
items[1] = "These are very old and extremely tall trees.\n";
items[2] = "bush";
items[3] = "This bush looks extremely large, maybe you could enter it.\n";
move_object(clone_object("/wizards/yodin/forest/monsters/deer.c"), this_object());           
move_object(clone_object("/wizards/yodin/forest/monsters/deer.c"), this_object());
move_object(clone_object("/wizards/yodin/forest/monsters/deer.c"), this_object());

}

init() {
  ::init(); 
  add_action("enter", "enter"); 
}

enter(str) {
  if(str == "bush") {
    write("You walked through bush.\n"); 
    say(this_player()->query_name()+" walked through bush.\n");
    move_object(this_player(),"/wizards/yodin/forest/for2/ff1.c");
    command("look",this_player());
     }
     return 1;

}


