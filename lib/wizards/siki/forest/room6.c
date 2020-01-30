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
        add_exit("north","room5");
        add_exit("south","room11");
        add_exit("west","room7");
        add_exit("east","room19");
        short_desc = "Deeper in the corrupted forest";

     long_desc = "Deeper in the corrupted forest. The air is even more heavier and the mist\n"+
                 "looms high in the first branches of the trees. Shadowy creatures are looming\n"+
                 "behing the twisted and black trees, and low gurgling sound can be heard from\n"+
                 "time to time. The unnatural voices are howling from every direction so eerily\n"+
                 "it freezes every living things inside this forest.\n";
}
