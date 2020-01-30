inherit "room/room";
object deer;

reset(arg)
{
if(!deer) {
 deer = clone_object("/wizards/yodin/areas/forest/monsters/deer");
 move_object(deer, this_object());
 }

if(arg) return;


short_desc = "Very old forest.";
long_desc =
"You are walking in a huge forest. All around you are very long \n" +
"trees and small bushes surrounding this path. Walking is very \n" +
"difficult because of these bushes and spiky rocks. The wind makes \n" +
"some strange noises. There is a huge bush in front of you\n";

add_exit("north", "ff21.c");
add_exit("south", "ff23.c");

items = allocate (4);
items[0] = "trees";
items[1] = "These are very old and extremely tall trees.\n";
items[2] = "bush";
items[3] = "Some light can be seen through bush, maybe you could enter it.\n";

}

init() {
  ::init();
  add_action("enter", "enter");
}

enter(str) {
  if(str == "bush") {
    write("You walked through bush.\n");
    say(this_player()->query_name()+" walked through bush.\n");
    move_object(this_player(),"/wizards/yodin/areas/forest/for1/ff1.c");
    command("look",this_player());
     }
     return 1;


}