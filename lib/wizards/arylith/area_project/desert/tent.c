inherit "room/room";
object merchant;

reset(arg) {
if(!merchant) {
merchant = clone_object("/wizards/arylith/area_project/monsters/merchant2");
move_object(merchant, this_object());
if(arg) { return; } 
}
add_exit("out", "/wizards/arylith/area_project/desert/entrance");
short_desc = "The hut.\n";
long_desc = "You are at the tent of the desert.\n"+ 
"You can see a merchant forging something at the forge.\n"+
"You can see a sign.\n";

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
write("The sign says that if you give a ruby to the merchant\n");
write("she can forge you a very powerful fighter ring.\n");
return 1;
}
write("You can't read that.\n");
return 1;
}
