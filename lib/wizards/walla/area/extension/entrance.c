inherit "room/room"

 
object monster;

reset(arg) {
if(!monster) {monster = clone_object("/wizards/walla/area/monsters/worker");;move_object(monster, this_object());}
if(arg) return;
add_exit("east","wizards/walla/workroom");
add_exit("west","wizards/walla/area/extension/13");
"The spiderfell continues deeper into the ground, and the air gets\n" +
"warmer and more insupportable. Further and further, you notice\n" +
"start noticing creatures that you have never thought existed. The\n" +           
"versatile fauna in here surprises you, and you wonder who has led\n" +
"all these animals in here.\n";
}
