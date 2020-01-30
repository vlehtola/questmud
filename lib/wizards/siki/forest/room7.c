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
        add_exit("west","room8");
        add_exit("east","room6");
        short_desc = "Deformed forest";
   long_desc = "This gloomy and deformed forest is filled with eerie sounds. The ground\n"+
               "is full of corpses where are lots of maggots crawling and eating the flesh.\n"+
               "A strange looking purple mist is covering the ground here and there and it\n"+
               "makes breathing very hard. This forest is full of twisted and deformed\n"+
               "looking trees and bushes. Your mind is filled with pictures and images\n"+
               "of yourself wandering in the forest, mindlessly and deformed.\n";
        items = allocate(4);
        items[0] = "ground";
        items[1] = "The ground is full of rottening corpses of different creatures.\n";
        items[2] = "mist";
        items[3] = "The mist looks quite strange and magical.\n";

}
