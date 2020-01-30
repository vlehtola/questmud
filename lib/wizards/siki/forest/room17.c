inherit "room/room";
object mob;
string *mobsters;
reset(arg) {
	mobsters = ({ "/wizards/siki/forest/monsters/bear","/wizards/siki/forest/monsters/deer","/wizards/siki/forest/monsters/rabbit","/wizards/siki/forest/monsters/wolf",});
        if(!mob) {
        mob = clone_object(mobsters[random(4)]);
        move_object(mob, this_object());
        }
        if(arg) return;
        add_exit("north","room18");
        add_exit("east","room16");
        short_desc = "A deformed bushes are southwest from here";
  long_desc = "The twisted looking path is going different ways from here. A lots of that \n"+
              "purple mist is floating above the ground and it makes tje breathing almost\n"+
              "an impossible thing to do here. There are couple of bushes in southwest from\n"+
              "here. They seem to be quite fresh. Even too fresh considering everything else\n"+
              "in this forest.\n";
              
}

init() {
	::init();
	add_action("southwest", "sw");
	add_action("southwest", "southwest");
}

southwest() {
	write("You take little speed and try to run southwest from here.\n");
	if(this_player()->query_alignment() < 0) {
	write("You almost manage to run throught those bushes but some strange angelical force pushes you back.\n");
	return 1;
}
write("You manage to run throught those bushes and came to the other side.\n");
write("An angelic looking white druid whispers in your ear: 'Don't be afraid my child, because your worst nightmare won't come true!'\n");
write("Then the druid leaves somewhere saying that only the true innocent one can open the portal safely by yelling the magical words!\n");
return 1;
}
