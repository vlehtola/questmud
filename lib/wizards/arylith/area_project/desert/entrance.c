inherit "room/room";
object merchant;

reset(arg) {
if(!merchant) {
merchant = clone_object("/wizards/arylith/area_project/monsters/merchant3");
move_object(merchant, this_object());
if(arg) { return; } 
}
add_exit("portal", "/wizards/arylith/area_project/portal");
add_exit("hut", "/wizards/arylith/area_project/desert/hut");
add_exit("tent", "/wizards/arylith/area_project/desert/tent");
add_exit("north", "/wizards/arylith/area_project/desert/d1");
short_desc = "Entrance to the desert.\n";
long_desc = "This is the camping site at the desert.\n"+ 
"Only thing you can see is sand everywhere and some\n"+
"monsters crawling around.\n"+
"There's a sign.\n";

property = allocate(4);
property[0] = "no_kill";
property[1] = "no_skill";
property[2] = "no_spell";
property[3] = "no_summon"; 

items = allocate(2);
items[0] = "sign";
items[1] = "Maybe you should read it?";

}
init() {
::init();
add_action("read", "read");
}
read(str) {
if(str == "sign") {
write("The sign says that if you give a worm scale to the merchant\n");
write("He gives you money in return.\n");
return 1;
}
write("You can't read that.\n");
return 1;
}
