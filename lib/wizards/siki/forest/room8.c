inherit "room/room";
static searched;
string bush_desc;
string ldesc;
object sob;

reset(arg) {
        if(arg) return;
        if(!searched) {
		bush_desc = "The bushes are deformed and twisted with somekind of dark magic.\nOne of bushes is moving and demonic roar can be heard from there";
        ldesc ="This gloomy and deformed forest is filled with eerie sounds. The ground\n"+
               "is full of corpses where are lots of maggots crawling and eating the flesh.\n"+
               "A strange looking purple mist is covering the ground here and there and it\n"+
               "makes breathing very hard. This forest is full of twisted and deformed\n"+
               "looking trees and bushes. A mad cackling sound is coming from on of the\n"+
               "bushes.\n";
	}
        add_exit("south","room9");
        add_exit("east","room7");
        short_desc = "Deformed forest";
        long_desc = ldesc;
        items = allocate(6);
        items[0] = "ground";
        items[1] = "The ground is full of rottening corpses of different creatures";
        items[2] = "mist";
        items[3] = "The mist looks quite strange and magical";
        items[4] = "bushes";
        items[5] = bush_desc;
	}

search_finished(string str) {
	if(str == "bushes" && !searched) {
	bush_desc = "The bushes are quite normal looking but still twisted and deformed!";
	ldesc ="This gloomy and deformed forest is filled with eerie sounds. The ground\n"+
               "is full of corpses where are lots of maggots crawling and eating the flesh.\n"+
               "A strange looking purple mist is covering the ground here and there and it\n"+
               "makes breathing very hard. This forest is full of twisted and deformed\n"+
               "looking trees and bushes.\n";
	write("You move one of the bushes and look behind it.\n");
	write("Suddenly somebody with eyes full of rage jumps out of the bush and attacks you!\n");
	sob = clone_object("/wizards/siki/forest/monsters/thuf");
	move_object(sob, environment(this_player()));
	this_player()->attack_object(sob);
	searched = 1;
	this_object()->reset();
	return 1;
}
write("You search around but find nothing special.\n");
return 1;
}

