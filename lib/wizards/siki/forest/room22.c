inherit "room/room";
object mob;
string *mobsters;
static int com;
reset(arg) {
	mobsters = ({ "/wizards/siki/forest/monsters/bear","/wizards/siki/forest/monsters/deer","/wizards/siki/forest/monsters/rabbit","/wizards/siki/forest/monsters/wolf",});
        if(!mob) {
        mob = clone_object(mobsters[random(4)]);
        move_object(mob, this_object());
        }
        if(arg) return;
        add_exit("west","room21");
        short_desc = "A crossing in the path";
  long_desc = "End of the path. A quiet whining sound can be heard somewhere, it seems\n"+
              "like somebody is asking for help. The ground is full of fighting marks\n"+
              "from animals and couple of child's clothes can also be seen. The tree in\n"+
              "eastern end of the path sways a little. Maybe it's just the wind.\n";

items = allocate(4);
items[0] = "spruce";
items[1] = "Someone is sitting on one of the braches of this tree.\n";
items[2] = "tree";
items[3] = "Someone is sitting on one of the branches of this tree.\n";

}

init() {
	::init();
	add_action("climb", "climb");
}

climb(str) {
	object rope;
	if(!str) { write("Climb where?\n"); return 1; }
	rope = present("rope", this_player());
	if(!rope) { write("You try to reach the first branch of the tree and climb but failed.\nMaybe you need something to help you climbing!\n"); return 1; }
	if(str == "tree" && !com) {
	write("You climb to the tree and sit on the branch\n");
	write("You ask from that child what has happened and the child start telling a story.\n");
	write("Child says: 'I am child of the Dexlom. Then he continues his story about strange beast that attacked him.\n");
	write("Child says: 'Then the beast captured my father and took him inside that oak. I followed them all the way to some place that wansn't on earth!\n");
	write("Child says: 'I can show you how to open that portal if you like..'\n");
	write("You say to the child 'Yes' and follow him to the oak.\n");
    write("Then Child commands the portal to open: 'Behold iam the mighty overlord and i command you to open'\n");
    write("Child says: 'You need to use that and the portal opens!'\n");
    write("The portal shimmers little and the magical field is gone!\n");
    write("Then you and the child return back.\n");
    write("Child says: 'I kept my promise and showed how to open that portal.\n");
    write("Child says: 'Now it is your turn to do a favour for me and escort me to safety.\n");
    write("You escort the Child to safety and return back.\n");
    com = 1;
  if(!this_player()->query_quest("Escort child to safety")) {
	this_player()->set_quest("Escort child to safety");
}
return 1;
} else if(str == "tree" && com) { write("You climb to the tree but find nothing special from there!\n"); return 1; }

write("Climb where?\n");
return 1;
}